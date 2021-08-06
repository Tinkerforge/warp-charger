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

#pragma once

#include "bindings/bricklet_evse_v2.h"

#include "config.h"

class EVSEV2 {
public:
    EVSEV2();
    void setup();
    void register_urls();
    void loop();

    bool evse_found = false;
    bool initialized = false;

    TF_EVSEV2 evse;

    Config evse_energy_meter_state;

private:
    void setup_evse();
    void update_evse_state();
    void update_evse_low_level_state();
    void update_evse_max_charging_current();
    void update_evse_auto_start_charging();
    void update_evse_managed();
    void update_evse_energy_meter_values();
    void update_evse_energy_meter_state();
    void update_evse_dc_fault_current_state();
    void update_evse_gpio_configuration();
    bool is_in_bootloader(int rc);
    bool flash_firmware();
    bool flash_plugin(int regular_plugin_upto);
    bool wait_for_bootloader_mode(int mode);
    String get_evse_debug_header();
    String get_evse_debug_line();
    void set_managed_current(uint16_t current);
    String get_evse_monitor_header();
    String get_evse_monitor_line();

    bool debug = false;

    Config evse_state;
    Config evse_hardware_configuration;
    Config evse_low_level_state;
    Config evse_max_charging_current;
    Config evse_auto_start_charging;
    Config evse_auto_start_charging_update;
    Config evse_current_limit;
    Config evse_stop_charging;
    Config evse_start_charging;
    Config evse_energy_meter_values;

    Config evse_dc_fault_current_state;
    Config evse_reset_dc_fault_current;
    Config evse_gpio_configuration;
    Config evse_managed;
    Config evse_managed_update;
    Config evse_managed_current;

    uint32_t last_current_update = 0;
    bool shutdown_logged = false;


};
