#include "api.h"

#include "modules/mqtt/mqtt.h"
#include "modules/task_scheduler/task_scheduler.h"
#include "SPIFFS.h"
#include "bindings/hal_common.h"
#include "bindings/errors.h"

#include "event_log.h"

extern Mqtt mqtt;

extern TaskScheduler task_scheduler;
extern AsyncWebServer server;
extern AsyncEventSource events;

extern TF_HalContext hal;

extern EventLog logger;

void API::setup()
{

}

void API::addCommand(String path, Config *config, std::initializer_list<String> keys_to_censor_in_debug_report, std::function<void(void)> callback)
{
    if(use_mqtt) {
        mqtt.subscribe(path, config->json_size(), [config, path, callback](String payload){
            String error = config->update_from_string(payload);
            if(error == "")
                task_scheduler.scheduleOnce((String("notify command update for ") + path).c_str(), [callback](){callback();}, 0);
            else
                logger.printfln("%s", error.c_str());
        });
    }

    if(use_http) {
        AsyncCallbackJsonWebHandler *handler = new AsyncCallbackJsonWebHandler(String("/") + path, [config, path, callback](AsyncWebServerRequest *request, JsonVariant &json){
            String message = config->update_from_json(json);

            task_scheduler.scheduleOnce((String("notify command update for ") + path).c_str(), [callback](){callback();}, 0);

            if (message == "") {
                request->send(200, "text/html", "");
            } else {
                request->send(400, "text/html", message);
            }
        });
        server.addHandler(handler);
    }

    commands.push_back({path, config, callback, keys_to_censor_in_debug_report});
}

void API::addState(String path, Config *config, std::initializer_list<String> keys_to_censor, uint32_t interval_ms)
{
    // copy into vector, initializer list is temporary, but we want to capture the content
    std::vector<String> keys{keys_to_censor};

    task_scheduler.scheduleWithFixedDelay((String("state ") + path).c_str(), [this, path, config, keys]() {
        if(!config->was_updated())
            return;
        config->set_update_handled();

        String payload = config->to_string_except(keys);
        if(use_mqtt)
            mqtt.publish(path, payload);
        if(use_sse)
            events.send(payload.c_str(), path.c_str(), millis());
    }, interval_ms, interval_ms);

    if(use_http) {
        server.on((String("/") + path).c_str(), HTTP_GET, [config, keys](AsyncWebServerRequest *request) {
            auto *response = request->beginResponseStream("application/json; charset=utf-8");
            config->write_to_stream_except(*response, keys);
            request->send(response);
        });
    }

    states.push_back({path, config, keys});
}

void API::addPersistentConfig(String path, Config *config, std::initializer_list<String> keys_to_censor, uint32_t interval_ms)
{
    addState(path, config, keys_to_censor, interval_ms);
    addCommand(path + String("_update"), config, keys_to_censor, [path, config](){
        String path_copy = path;
        path_copy.replace('/', '_');
        String tmp_path = String("/") + path_copy + ".json.tmp";
        String cfg_path = String("/") + path_copy + ".json";

        if (SPIFFS.exists(tmp_path))
            SPIFFS.remove(tmp_path);

        File file = SPIFFS.open(tmp_path, "w");
        config->save_to_file(file);
        file.close();

        if (SPIFFS.exists(cfg_path))
            SPIFFS.remove(cfg_path);

        SPIFFS.rename(tmp_path, cfg_path);
    });
}
/*
void API::addTemporaryConfig(String path, Config *config, std::initializer_list<String> keys_to_censor, uint32_t interval_ms, std::function<void(void)> callback)
{
    addState(path, config, keys_to_censor, interval_ms);
    addCommand(path + String("_update"), config, callback);
}
*/
void API::onEventConnect(AsyncEventSourceClient *client)
{
    for(auto &reg : states) {
        client->send(reg.config->to_string_except(reg.keys_to_censor).c_str(), reg.path.c_str(), millis(), 1000);
    }
}

void API::onMqttConnect()
{
    // Do the publishing in the "main thread". Otherwise this would be a race condition with the publishing in addState.
    task_scheduler.scheduleOnce("onMqttConnect", [this](){
        for(auto &reg : commands) {
            mqtt.subscribe(reg.path, reg.config->json_size(), [reg](String payload){
                String error = reg.config->update_from_string(payload);
                if(error == "")
                    task_scheduler.scheduleOnce((String("notify command update for ") + reg.path).c_str(), [reg](){reg.callback();}, 0);
                else
                    logger.printfln("%s", error.c_str());
            });
        }
        for(auto &reg : states) {
            mqtt.publish(reg.path, reg.config->to_string_except(reg.keys_to_censor));
        }
    }, 0);
}

void API::registerDebugUrl() {
    server.on("/debug_report", HTTP_GET, [this](AsyncWebServerRequest *request) {

        String result = "{\"uptime\": ";
        result += String(millis());
        result += ",\n \"free_heap_bytes\":" ;
        result += ESP.getFreeHeap();
        result += ",\n \"largest_free_heap_block\":" ;
        result += ESP.getMaxAllocHeap();

        result += ",\n \"devices\": [";
        size_t i = 0;
        char uid[7] = {0};
        char pos = 0;
        uint16_t did = 0;
        while(tf_hal_get_device_info(&hal, i, uid, &pos, &did) == TF_E_OK) {
            char buf[100] = {0};
            snprintf(buf, sizeof(buf), "%c{\"UID\":\"%s\", \"DID\":%u, \"port\":\"%c\"}", i == 0 ? ' ': ',', uid, did, pos);
            result += buf;
            ++i;
        }
        result += "]";

        for(auto &reg : states) {
            result += ",\n \"";
            result += reg.path;
            result += "\": ";
            result += reg.config->to_string_except(reg.keys_to_censor);
        }

        for(auto &reg: commands) {
            result += ",\n \"";
            result += reg.path;
            result += "\": ";
            result += reg.config->to_string_except(reg.keys_to_censor_in_debug_report);
        }
        result += "}";
        request->send(200, "application/json; charset=utf-8", result);
    });
}
