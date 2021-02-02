#pragma once

#include <stdarg.h>

#include <Arduino.h>

#include "ESPAsyncWebServer.h"

#include "ringbuffer.h"

#include "bindings/macros.h"

extern AsyncWebServer server;

class EventLog {
public:
    TF_Ringbuffer<char, 10000> event_buf;

    void printfln(const char *fmt, ...) __attribute__((__format__(__printf__, 2, 3)));

    void drop(size_t count);

    void register_urls();

    bool sending_response = false;
};
