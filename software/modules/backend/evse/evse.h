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

#include "bindings/bricklet_evse.h"

#include "config.h"
#include "device_module.h"
#include "evse_firmware.h"

class EVSE : public DeviceModule<TF_EVSE,
                                 evse_bricklet_firmware_bin,
                                 evse_bricklet_firmware_bin_len,
                                 tf_evse_create,
                                 tf_evse_get_bootloader_mode,
                                 tf_evse_reset> {
public:
    EVSE();
    void setup();
    void register_urls();
    void loop();
private:
    void setup_evse();
    void update_all_data();
    String get_evse_debug_header();
    String get_evse_debug_line();
    void set_managed_current(uint16_t current);

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
    Config evse_managed;
    Config evse_managed_update;
    Config evse_managed_current;
    Config evse_user_calibration;
    Config evse_button_state;
    Config evse_reflash;
    Config evse_reset;

    uint32_t last_current_update = 0;
    bool shutdown_logged = false;
};
