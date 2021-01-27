#pragma once

#include "Arduino.h"

#include <functional>
#include <initializer_list>
#include <vector>

#include "ESPAsyncWebServer.h"

#include "config.h"

struct StateRegistration {
    String path;
    Config *config;
    std::vector<String> keys_to_censor;
};

struct CommandRegistration {
    String path;
    Config *config;
    std::function<void(void)> callback;
    std::vector<String> keys_to_censor_in_debug_report;
};


class API {
public:
    API(bool use_mqtt, bool use_sse, bool use_http) : use_mqtt(use_mqtt), use_sse(use_sse), use_http(use_http) {}

    void setup();

    void addCommand(String path, Config *config, std::initializer_list<String> keys_to_censor_in_debug_report, std::function<void(void)> callback);
    void addState(String path, Config *config, std::initializer_list<String> keys_to_censor, uint32_t interval_ms);
    void addPersistentConfig(String path, Config *config, std::initializer_list<String> keys_to_censor, uint32_t interval_ms);
    //void addTemporaryConfig(String path, Config *config, std::initializer_list<String> keys_to_censor, uint32_t interval_ms, std::function<void(void)> callback);

    void onEventConnect(AsyncEventSourceClient *client);
    void onMqttConnect();

    void registerDebugUrl();

private:
    bool use_mqtt;
    bool use_sse;
    bool use_http;

    std::vector<StateRegistration> states;
    std::vector<CommandRegistration> commands;
};
