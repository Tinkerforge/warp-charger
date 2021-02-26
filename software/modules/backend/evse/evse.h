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

#include "ESPAsyncWebServer.h"
#include "ArduinoJson.h"

#include "bindings/bricklet_evse.h"

#include "config.h"

#define EVSE_CHARGING_STATE_NOT_CONNECTED 0
#define EVSE_CHARGING_STATE_CONNECTED 1
#define EVSE_CHARGING_STATE_CHARGING 2
#define EVSE_CHARGING_STATE_ERROR 3

class EVSE {
public:
    EVSE();
    void setup();
    void register_urls();
    void loop();

    bool evse_found = false;
    bool initialized = false;

private:
    void setup_evse();
    void update_evse_state();
    void update_evse_low_level_state();
    void update_evse_max_charging_current();
    void update_evse_auto_start_charging();
    bool is_in_bootloader(int rc);
    bool flash_firmware();
    bool flash_plugin(int regular_plugin_upto);
    bool wait_for_bootloader_mode(int mode);

    Config evse_state;
    Config evse_hardware_configuration;
    Config evse_low_level_state;
    Config evse_max_charging_current;
    Config evse_auto_start_charging;
    Config evse_auto_start_charging_update;
    Config evse_current_limit;
    Config evse_stop_charging;
    Config evse_start_charging;

    TF_EVSE evse;
};
