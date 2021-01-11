#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "AsyncEventSource.h"
#include "ArduinoJson.h"

#include "config.h"

#include "bindings/hal_common.h"

#define GREEN_LED 4
#define BLUE_LED 32

bool deadline_elapsed(uint32_t deadline_ms);
bool find_uid_by_did(TF_HalContext *hal, uint16_t device_id, char uid[7]);


bool send_event_allowed(AsyncEventSource *events);

String update_config(Config &cfg, String config_name, JsonVariant &json);
