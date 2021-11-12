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

#include "bindings/bricklet_nfc.h"

#include "config.h"
#include "device_module.h"
#include "nfc_firmware.h"

class NFC : public DeviceModule<TF_NFC,
                                nfc_bricklet_firmware_bin,
                                nfc_bricklet_firmware_bin_len,
                                tf_nfc_create,
                                tf_nfc_get_bootloader_mode,
                                tf_nfc_reset> {
public:
    NFC();
    void setup();
    void register_urls();
    void loop();

private:
    struct tag_info_t {
        uint8_t tag_type;
        uint8_t tag_id_len;
        uint8_t tag_id[10];
        uint32_t last_seen;
    };

    void update_seen_tags();
    void handle_event(tag_info_t *tag, bool lost_or_found);
    void handle_evse();
    void setup_nfc();
    void check_nfc_state();
    bool is_tag_authorized(uint8_t tag_type, uint8_t *tag_id, uint8_t tag_id_len, uint32_t last_seen, uint8_t *tag_idx);
    bool is_tag_equal(uint8_t tag_type, uint8_t *tag_id, uint8_t tag_id_len, uint32_t last_seen, Config *other_tag);

    Config config;
    Config config_in_use;
    Config seen_tags;
    Config state;

    uint32_t last_action_ms = 0;

    char uid[7] = {0};

    tag_info_t old_tag_buffer[8] = {};
    tag_info_t new_tag_buffer[8] = {};
    tag_info_t *old_tags = old_tag_buffer;
    tag_info_t *new_tags = new_tag_buffer;

    int auth_token = -1;
    uint32_t auth_token_seen = 0;
    int16_t blink_state = -1;
};
