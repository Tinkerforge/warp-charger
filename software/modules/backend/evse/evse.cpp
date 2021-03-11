/* warp-charger
 * Copyright (C) 2020-2021 Erik Fleckstein <erik@tinkerforge.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "evse.h"
#include "evse_firmware.h"

#include "bindings/errors.h"

#include "api.h"
#include "event_log.h"
#include "task_scheduler.h"
#include "tools.h"

extern EventLog logger;

extern TaskScheduler task_scheduler;
extern TF_HalContext hal;
extern AsyncWebServer server;

extern API api;
extern bool firmware_update_allowed;

EVSE::EVSE()
{
    evse_state = Config::Object({
        {"iec61851_state", Config::Uint8(0)},
        {"vehicle_state", Config::Uint8(0)},
        {"contactor_state", Config::Uint8(0)},
        {"contactor_error", Config::Uint8(0)},
        {"charge_release", Config::Uint8(0)},
        {"allowed_charging_current", Config::Uint16(0)},
        {"error_state", Config::Uint8(0)},
        {"lock_state", Config::Uint8(0)},
        {"time_since_state_change", Config::Uint32(0)},
        {"uptime", Config::Uint32(0)}
    });

    evse_hardware_configuration = Config::Object({
        {"jumper_configuration", Config::Uint8(0)},
        {"has_lock_switch", Config::Bool(false)}
    });

    evse_low_level_state = Config::Object ({
        {"low_level_mode_enabled", Config::Bool(false)},
        {"led_state", Config::Uint8(0)},
        {"cp_pwm_duty_cycle", Config::Uint16(0)},
        {"adc_values", Config::Array({
                Config::Uint16(0),
                Config::Uint16(0),
            }, Config::Uint16(0), 2, 2, Config::type_id<Config::ConfUint>())
        },
        {"voltages", Config::Array({
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
            }, Config::Int16(0), 3, 3, Config::type_id<Config::ConfInt>())
        },
        {"resistances", Config::Array({
                Config::Uint32(0),
                Config::Uint32(0),
            }, Config::Uint32(0), 2, 2, Config::type_id<Config::ConfUint>())
        },
        {"gpio", Config::Array({Config::Bool(false),Config::Bool(false),Config::Bool(false),Config::Bool(false), Config::Bool(false)}, Config::Bool(false), 5, 5, Config::type_id<Config::ConfBool>())}
    });

    evse_max_charging_current = Config::Object ({
        {"max_current_configured", Config::Uint16(0)},
        {"max_current_incoming_cable", Config::Uint16(0)},
        {"max_current_outgoing_cable", Config::Uint16(0)},
    });

    evse_auto_start_charging = Config::Object({
        {"auto_start_charging", Config::Bool(true)}
    });

    evse_auto_start_charging_update = Config::Object({
        {"auto_start_charging", Config::Bool(true)}
    });


    evse_current_limit = Config::Object({
        {"current", Config::Uint(32000, 6000, 32000)}
    });

    evse_stop_charging = Config::Null();
    evse_start_charging = Config::Null();
}

void EVSE::setup()
{
    setup_evse();
    task_scheduler.scheduleWithFixedDelay("update_evse_state", [this](){
        update_evse_state();
    }, 0, 1000);

    task_scheduler.scheduleWithFixedDelay("update_evse_low_level_state", [this](){
        update_evse_low_level_state();
    }, 0, 1000);

    task_scheduler.scheduleWithFixedDelay("update_evse_max_charging_current", [this](){
        update_evse_max_charging_current();
    }, 0, 1000);

    task_scheduler.scheduleWithFixedDelay("update_evse_auto_start_charging", [this](){
        update_evse_auto_start_charging();
    }, 0, 1000);
}

void EVSE::register_urls()
{
    api.addState("evse/state", &evse_state, {}, 1000);
    api.addState("evse/hardware_configuration", &evse_hardware_configuration, {}, 1000);
    api.addState("evse/low_level_state", &evse_low_level_state, {}, 1000);
    api.addState("evse/max_charging_current", &evse_max_charging_current, {}, 1000);
    api.addState("evse/auto_start_charging", &evse_auto_start_charging, {}, 1000);

    api.addCommand("evse/auto_start_charging_update", &evse_auto_start_charging_update, {}, [this](){
        is_in_bootloader(tf_evse_set_charging_autostart(&evse, evse_auto_start_charging_update.get("auto_start_charging")->asBool()));
    });

    /*api.addTemporaryConfig("evse/auto_start_charging", &evse_auto_start_charging, {}, 1000, [this](){
        is_in_bootloader(tf_evse_set_charging_autostart(&evse, evse_auto_start_charging.get("auto_start_charging")->asBool()));
    });*/

    api.addCommand("evse/current_limit", &evse_current_limit, {}, [this](){
        is_in_bootloader(tf_evse_set_max_charging_current(&evse, evse_current_limit.get("current")->asUint()));
    });

    api.addCommand("evse/stop_charging", &evse_stop_charging, {}, [this](){tf_evse_stop_charging(&evse);});
    api.addCommand("evse/start_charging", &evse_start_charging, {}, [this](){tf_evse_start_charging(&evse);});
}

void EVSE::loop()
{
    static uint32_t last_check = 0;
    if(evse_found && !initialized && deadline_elapsed(last_check + 10000)) {
        last_check = millis();
        if(!is_in_bootloader(TF_E_TIMEOUT))
            setup_evse();
    }
}

void EVSE::setup_evse()
{
    char uid[7] = {0};
    if (!find_uid_by_did(&hal, TF_EVSE_DEVICE_IDENTIFIER, uid)) {
        logger.printfln("No EVSE bricklet found. Disabling EVSE support.");
        return;
    }
    evse_found = true;

    auto result = tf_evse_create(&evse, uid, &hal);
    if(result != TF_E_OK) {
        logger.printfln("EVSE init failed (rc %d). Disabling EVSE support.", result);
        return;
    }

    uint8_t firmware_version[3] = {0};

    result = tf_evse_get_identity(&evse, nullptr, nullptr, nullptr, nullptr, firmware_version, nullptr);
    if(result != TF_E_OK) {
        logger.printfln("EVSE get identity (rc %d). Disabling EVSE support.", result);
        return;
    }

    bool flash_required = false;
    for(int i = 0; i < 3; ++i) {
        // Intentionally use != here: we also want to downgrade the evse firmware if the esp firmware embeds an older one.
        // This makes sure, that the interfaces fit.
        flash_required |= firmware_version[i] != evse_firmware_version[i];
    }

    if (flash_required) {
        logger.printfln("EVSE firmware is %d.%d.%d not the expected %d.%d.%d. Flashing firmware...",
                      firmware_version[0], firmware_version[1], firmware_version[2],
                      evse_firmware_version[0], evse_firmware_version[1], evse_firmware_version[2]);
        if(!flash_firmware()) {
            logger.printfln("EVSE flashing failed. Disabling EVSE support.");
            return;
        }

        result = tf_evse_create(&evse, uid, &hal);
        if(result != TF_E_OK) {
            logger.printfln("EVSE init failed (rc %d). Disabling EVSE support.", result);
            return;
        }
    }

    uint8_t jumper_configuration;
    bool has_lock_switch;

    result = tf_evse_get_hardware_configuration(&evse, &jumper_configuration, &has_lock_switch);

    if (result != TF_E_OK) {
        if(!is_in_bootloader(result)) {
            logger.printfln("EVSE hardware config query failed (rc %d). Disabling EVSE support.", result);
        }
        return;
    } else {
        evse_hardware_configuration.get("jumper_configuration")->updateUint(jumper_configuration);
        evse_hardware_configuration.get("has_lock_switch")->updateBool(has_lock_switch);
    }

    initialized = true;
}

void EVSE::update_evse_low_level_state() {
    if(!initialized)
        return;

    bool low_level_mode_enabled;
    uint8_t led_state;
    uint16_t cp_pwm_duty_cycle;

    uint16_t adc_values[2];
    int16_t voltages[3];
    uint32_t resistances[2];
    bool gpio[5];

    int rc = tf_evse_get_low_level_state(&evse,
        &low_level_mode_enabled,
        &led_state,
        &cp_pwm_duty_cycle,
        adc_values,
        voltages,
        resistances,
        gpio);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_low_level_state.get("low_level_mode_enabled")->updateBool(low_level_mode_enabled);
    evse_low_level_state.get("led_state")->updateUint(led_state);
    evse_low_level_state.get("cp_pwm_duty_cycle")->updateUint(cp_pwm_duty_cycle);

    for(int i = 0; i < sizeof(adc_values)/sizeof(adc_values[0]); ++i)
        evse_low_level_state.get("adc_values")->get(i)->updateUint(adc_values[i]);

    for(int i = 0; i < sizeof(voltages)/sizeof(voltages[0]); ++i)
        evse_low_level_state.get("voltages")->get(i)->updateInt(voltages[i]);

    for(int i = 0; i < sizeof(resistances)/sizeof(resistances[0]); ++i)
        evse_low_level_state.get("resistances")->get(i)->updateUint(resistances[i]);

    for(int i = 0; i < sizeof(gpio)/sizeof(gpio[0]); ++i)
        evse_low_level_state.get("gpio")->get(i)->updateBool(gpio[i]);
}

void EVSE::update_evse_state() {
    if(!initialized)
        return;
    uint8_t iec61851_state, vehicle_state, contactor_state, contactor_error, charge_release, error_state, lock_state;
    uint16_t allowed_charging_current;
    uint32_t time_since_state_change, uptime;

    int rc = tf_evse_get_state(&evse,
        &iec61851_state,
        &vehicle_state,
        &contactor_state,
        &contactor_error,
        &charge_release,
        &allowed_charging_current,
        &error_state,
        &lock_state,
        &time_since_state_change,
        &uptime);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    firmware_update_allowed = vehicle_state == 0;

    evse_state.get("iec61851_state")->updateUint(iec61851_state);
    evse_state.get("vehicle_state")->updateUint(vehicle_state);
    evse_state.get("contactor_state")->updateUint(contactor_state);
    bool contactor_error_changed = evse_state.get("contactor_error")->updateUint(contactor_error);
    evse_state.get("charge_release")->updateUint(charge_release);
    evse_state.get("allowed_charging_current")->updateUint(allowed_charging_current);
    bool error_state_changed = evse_state.get("error_state")->updateUint(error_state);
    evse_state.get("lock_state")->updateUint(lock_state);
    evse_state.get("time_since_state_change")->updateUint(time_since_state_change);
    evse_state.get("uptime")->updateUint(uptime);

    if (contactor_error_changed) {
        if (contactor_error != 0) {
            logger.printfln("EVSE: Contactor error %d", contactor_error);
        } else {
            logger.printfln("EVSE: Contactor error cleared");
        }
    }

    if (error_state_changed) {
        if (error_state != 0) {
            logger.printfln("EVSE: Error state %d", error_state);
        } else {
            logger.printfln("EVSE: Error state cleared");
        }
    }
}

void EVSE::update_evse_max_charging_current() {
    if(!initialized)
        return;
    uint16_t configured, incoming, outgoing;

    int rc = tf_evse_get_max_charging_current(&evse,
        &configured,
        &incoming,
        &outgoing);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_max_charging_current.get("max_current_configured")->updateUint(configured);
    evse_max_charging_current.get("max_current_incoming_cable")->updateUint(incoming);
    evse_max_charging_current.get("max_current_outgoing_cable")->updateUint(outgoing);
}

void EVSE::update_evse_auto_start_charging() {
    if(!initialized)
        return;
    bool auto_start_charging;

    int rc = tf_evse_get_charging_autostart(&evse,
        &auto_start_charging);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_auto_start_charging.get("auto_start_charging")->updateBool(auto_start_charging);
}

bool EVSE::is_in_bootloader(int rc) {
    if(rc != TF_E_TIMEOUT && rc != TF_E_NOT_SUPPORTED)
        return false;

    uint8_t mode;
    int bootloader_rc = tf_evse_get_bootloader_mode(&evse, &mode);
    if(bootloader_rc != TF_E_OK) {
        return false;
    }

    if(mode != TF_EVSE_BOOTLOADER_MODE_FIRMWARE) {
        initialized = false;
    }

    return mode != TF_EVSE_BOOTLOADER_MODE_FIRMWARE;
}

bool EVSE::wait_for_bootloader_mode(int target_mode) {
    uint8_t mode = 255;
    for(int i = 0; i < 10; ++i) {
        if (tf_evse_get_bootloader_mode(&evse, &mode) != TF_E_OK) {
            continue;
        }
        if (mode == target_mode) {
            break;
        }
        delay(250);
    }

    return mode == target_mode;
}

bool EVSE::flash_firmware() {
    int regular_plugin_upto = -1;
    for(int i = evse_bricklet_firmware_bin_len - 13; i >= 4; --i) {
        if (evse_bricklet_firmware_bin[i] == 0x12
         && evse_bricklet_firmware_bin[i - 1] == 0x34
         && evse_bricklet_firmware_bin[i - 2] == 0x56
         && evse_bricklet_firmware_bin[i - 3] == 0x78) {
             regular_plugin_upto = i;
             break;
         }
    }

    if (regular_plugin_upto == -1) {
        logger.printfln("    Firmware end marker not found. Is this a valid firmware?");
        return false;
    }

    if(!flash_plugin(regular_plugin_upto)) {
        return false;
    }

    logger.printfln("    Setting bootloader mode to firmware.");
    uint8_t ret_status = 0;
    tf_evse_set_bootloader_mode(&evse, 1, &ret_status);
    if (ret_status != 0 && ret_status != 2) {
        logger.printfln("    Failed to set bootloader mode to firmware. status %d.", ret_status);
        if (ret_status != 5) {
            return false;
        }
        logger.printfln("    Status is 5, retrying.");
        if(!flash_plugin(regular_plugin_upto)) {
            return false;
        }

        ret_status = 0;
        logger.printfln("    Setting bootloader mode to firmware.");
        tf_evse_set_bootloader_mode(&evse, 1, &ret_status);
        if (ret_status != 0 && ret_status != 2) {
            logger.printfln("    (Second attempt) Failed to set bootloader mode to firmware. status %d.", ret_status);
            return false;
        }
    }
    logger.printfln("    Waiting for firmware...");
    if(!wait_for_bootloader_mode(1)) {
        logger.printfln("    Timed out, flashing failed");
        return false;
    }
    logger.printfln("    Firmware flashed successfully");
    return true;
}

bool EVSE::flash_plugin(int regular_plugin_upto) {
    logger.printfln("    Setting bootloader mode to bootloader.");
    tf_evse_set_bootloader_mode(&evse, 0, nullptr);
    logger.printfln("    Waiting for bootloader...");
    if(!wait_for_bootloader_mode(0)) {
        logger.printfln("    Timed out, flashing failed");
        return false;
    }
    logger.printfln("    Device is in bootloader, flashing...");

    int num_packets = evse_bricklet_firmware_bin_len / 64;

    int last_packet = 0;
    bool write_footer = false;
    if (regular_plugin_upto >= evse_bricklet_firmware_bin_len - 64 * 4) {
        last_packet = num_packets;
    } else {
        last_packet = ((regular_plugin_upto / 256) + 1) * 4;
        write_footer = true;
    }

    for(int position = 0; position < last_packet; ++position) {
        int start = position * 64;
        if(tf_evse_set_write_firmware_pointer(&evse, start) != TF_E_OK) {
            if(tf_evse_set_write_firmware_pointer(&evse, start) != TF_E_OK) {
                logger.printfln("    Failed to set firmware pointer to %d", start);
                return false;
            }
        }

        if(tf_evse_write_firmware(&evse, const_cast<uint8_t *>(evse_bricklet_firmware_bin + start), nullptr) != TF_E_OK) {
            if(tf_evse_write_firmware(&evse, const_cast<uint8_t *>(evse_bricklet_firmware_bin + start), nullptr) != TF_E_OK) {
                logger.printfln("    Failed to write firmware at %d", start);
                return false;
            }
        }
    }

    if (write_footer) {
        for(int position = num_packets - 4; position < num_packets; ++position) {
            int start = position * 64;
            if(tf_evse_set_write_firmware_pointer(&evse, start) != TF_E_OK) {
                if(tf_evse_set_write_firmware_pointer(&evse, start) != TF_E_OK) {
                    logger.printfln("    (Footer) Failed to set firmware pointer to %d", start);
                    return false;
                }
            }

            if(tf_evse_write_firmware(&evse, const_cast<uint8_t *>(evse_bricklet_firmware_bin + start), nullptr) != TF_E_OK) {
                if(tf_evse_write_firmware(&evse, const_cast<uint8_t *>(evse_bricklet_firmware_bin + start), nullptr) != TF_E_OK) {
                    logger.printfln("    (Footer) Failed to write firmware at %d", start);
                    return false;
                }
            }
        }
    }
    logger.printfln("    Device flashed successfully.");
    return true;
}
