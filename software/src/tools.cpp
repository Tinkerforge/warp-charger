#include "tools.h"

#include "bindings/errors.h"

#include <Arduino.h>
#include "SPIFFS.h"

bool deadline_elapsed(uint32_t deadline_ms) {
    uint32_t now = millis();

    if(now < deadline_ms) {
        uint32_t diff = deadline_ms - now;
        if (diff < UINT32_MAX / 2)
            return false;
        return true;
    }
    else {
        uint32_t diff = now - deadline_ms;
        if(diff > UINT32_MAX / 2)
            return false;
        return true;
    }
}

bool find_uid_by_did(TF_HalContext *hal, uint16_t device_id, char uid[7]) {
    char pos;
    uint16_t did;
    for (size_t i = 0; tf_hal_get_device_info(hal, i, uid, &pos, &did) == TF_E_OK; ++i) {
        if (did == device_id) {
            return true;
        }
    }
    return false;
}

bool send_event_allowed(AsyncEventSource *events) {
    // TODO: patch the library to get how many packets are waiting in the fullest client queue
    return events->count() > 0 && events->avgPacketsWaiting() < 8;
}

String update_config(Config &cfg, String config_name, JsonVariant &json) {
    String error = cfg.update_from_json(json);

    String tmp_path = String("/") + config_name + ".json.tmp";
    String path = String("/") + config_name + ".json";

    if (error == "") {
        if (SPIFFS.exists(tmp_path))
            SPIFFS.remove(tmp_path);

        File file = SPIFFS.open(tmp_path, "w");
        cfg.save_to_file(file);
        file.close();

        if (SPIFFS.exists(path))
            SPIFFS.remove(path);

        SPIFFS.rename(tmp_path, path);
    } else {
        logger.printfln("Failed to update %s: %s", path.c_str(), error.c_str());
    }
    return error;
}
