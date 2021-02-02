#pragma once

#include "ArduinoJson.h"
#include "FS.h"

#include "event_log.h"

#define STRICT_VARIANT_ASSUME_MOVE_NOTHROW true
#include "strict_variant/variant.hpp"
#include "strict_variant/mpl/find_with.hpp"

extern EventLog logger;

struct Config {
    struct ConfString {
        String value;
        size_t maxChars;
        String(*validator)(const ConfString &);
    };

    struct ConfFloat {
        double value;
        double min;
        double max;
        String(*validator)(const ConfFloat &);
    };

    struct ConfInt {
        int64_t value;
        int64_t min;
        int64_t max;
        String(*validator)(const ConfInt &);
    };

    struct ConfUint {
        uint64_t value;
        uint64_t min;
        uint64_t max;
        String(*validator)(const ConfUint &);
    };

    struct ConfBool {
        bool value;
        String(*validator)(const ConfBool &);
    };

    struct ConfArray {
        std::vector<Config> value;
        std::vector<Config> prototype;
        size_t minElements;
        size_t maxElements;
        int variantType;
        String(*validator)(const ConfArray &);
    };

    struct ConfObject {
        std::vector<std::pair<String, Config>> value;
        String(*validator)(const ConfObject &);
    };

    typedef strict_variant::variant<
        ConfString,
        ConfFloat,
        ConfInt,
        ConfUint,
        ConfBool,
        ConfArray,
        ConfObject,
        std::nullptr_t
    > ConfVariant;

    ConfVariant value;
    bool updated;

    bool was_updated();
    void set_update_handled();

    template<typename T>
    static int type_id()
    {
        constexpr std::size_t index = decltype(value)::find_which<T>::value;
        return index;
    }

    template<typename T>
    bool is() const
    {
        return value.which() == decltype(value)::find_which<T>::value;
    }

    static Config Str(String s,
                      size_t maxChars = 0,
                      String(*validator)(const ConfString &) = [](const ConfString &s){
                          if(s.maxChars == 0 || s.value.length() <= s.maxChars)
                            return String("");

                          return String(String("String of maximum length ") + s.maxChars + " was expected, but got " + s.value.length());
                    });

    static Config Float(double d,
                        double min = std::numeric_limits<double>::lowest(),
                        double max = std::numeric_limits<double>::max(),
                        String(*validator)(const ConfFloat &) = [](const ConfFloat &f) {
                            if(f.value < f.min)
                                return String(String("Float value ") + f.value + " was less than the allowed minimum of " + f.min);
                            if(f.value > f.max)
                                return String(String("Float value ") + f.value + " was more than the allowed maximum of " + f.max);
                            return String("");
                        });

    static Config Int(int64_t i,
                      int64_t min = std::numeric_limits<int64_t>::lowest(),
                      int64_t max = std::numeric_limits<int64_t>::max(),
                      String(*validator)(const ConfInt &) = [](const ConfInt &f) {
                        if(f.value < f.min)
                            //return String(String("Integer value ") + f.value + " was less than the allowed minimum of " + f.min);
                            return String("Integer value was less than the allowed minimum");
                        if(f.value > f.max)
                            //return String(String("Integer value ") + f.value + " was more than the allowed maximum of " + f.max);
                            return String("Integer value was more than the allowed maximum");
                        return String("");
                      });

    static Config Uint(uint64_t u,
                       uint64_t min = std::numeric_limits<uint64_t>::lowest(),
                       uint64_t max = std::numeric_limits<uint64_t>::max(),
                       String(*validator)(const ConfUint &) = [](const ConfUint &f) {
                            if(f.value < f.min)
                                //return String(String("Unsigned integer value ") + f.value + " was less than the allowed minimum of " + f.min);
                                return String("Unsigned integer value was less than the allowed minimum");
                            if(f.value > f.max)
                                //return String(String("Unsigned integer value ") + f.value + " was more than the allowed maximum of " + f.max);
                                return String("Unsigned integer value was more than the allowed maximum");
                            return String("");
                        });

    static Config Bool(bool b,
                       String(*validator)(const ConfBool &) = [](const ConfBool &){return String("");});

    static Config Array(std::initializer_list<Config> arr,
                        Config prototype,
                        size_t minElements = 0,
                        size_t maxElements = 0,
                        int variantType = -1,
                        String(*validator)(const ConfArray &) = [](const ConfArray &arr){
                            if(arr.maxElements > 0 && arr.value.size() > arr.maxElements)
                                return String(String("Array had ") + arr.value.size() + " entries, but only " + arr.maxElements + " are allowed.");
                            if(arr.minElements > 0 && arr.value.size() < arr.minElements)
                                return String(String("Array had ") + arr.value.size() + " entries, but at least " + arr.maxElements + " are required.");

                            if(arr.variantType < 0)
                                return String("");
                            for(int i = 0; i < arr.value.size(); ++i)
                                if(arr.value[i].value.which() != arr.variantType)
                                    return String(String("[") + i + "] has wrong type");
                            return String("");
                        });
    static Config Object(std::initializer_list<std::pair<String, Config>> obj,
                         String(*validator)(const ConfObject &) = [](const ConfObject &){return String("");});
    static Config Null();

    static Config Uint8(uint8_t u);

    static Config Uint16(uint16_t u);

    static Config Uint32(uint32_t u);

    static Config Uint64(uint64_t u);

    static Config Int8(int8_t i);

    static Config Int16(int16_t i);

    static Config Int32(int32_t i);

    static Config Int64(int64_t i);

    Config *get(String s);

    Config *get(size_t i);

    bool isValid();

    template<typename T, typename ConfigT>
    bool set(String s, T val) {
        Config *toChange = get(s);
        if(!toChange->is<ConfigT>()) {
            logger.printfln("Config key %s not found! Can't set to [see serial console]", s.c_str());
            Serial.println(val);
            delay(100);
            return false;
        }
        *toChange->as<T, ConfigT>() = val;
        return isValid();
    }

    template<typename T, typename ConfigT>
    bool set(size_t idx, T val) {
        Config *toChange = get(idx);
        if(!toChange->is<ConfigT>()) {
            logger.printfln("Config idx %u not found! Can't set to [see serial console]", idx);
            Serial.println(val);
            delay(100);
            return false;
        }
        *toChange->as<T, ConfigT>() = val;
        return isValid();
    }

    bool add() {
        if (!this->is<Config::ConfArray>()){
            logger.printfln("Tried to add to a node that is not an array!");
            delay(100);
            return false;
        }
        std::vector<Config> &children = strict_variant::get<Config::ConfArray>(&value)->value;
        children.push_back(strict_variant::get<Config::ConfArray>(&value)->prototype[0]);
        return true;
    }

    ssize_t count() {
        if (!this->is<Config::ConfArray>()){
            logger.printfln("Tried to add to a node that is not an array!");
            delay(100);
            return -1;
        }
        std::vector<Config> &children = strict_variant::get<Config::ConfArray>(&value)->value;
        return children.size();
    }

    template<typename T, typename ConfigT>
    T *as() {
        if (!this->is<ConfigT>()) {
            logger.printfln("Config has wrong type.");
            delay(100);
            return nullptr;
        }
        return &strict_variant::get<ConfigT>(&value)->value;
    }

    const String &asString();

    const char *asCStr();

    const double &asFloat();

    const uint64_t &asUint();

    const int64_t &asInt();

    const bool &asBool();

    std::vector<Config> &asArray();

    template<typename T, typename ConfigT>
    bool update_value(T value) {
        if (!this->is<ConfigT>()) {
            logger.printfln("Config has wrong type.");
            delay(100);
            return false;
        }
        T *target = as<T, ConfigT>();
        T old_value = *target;
        *target = value;

        if(old_value != value)
            this->updated = true;

        return old_value != value;
    }

    bool updateString(String value) {
        return update_value<String, ConfString>(value);
    }

    bool updateInt(int64_t value) {
        return update_value<int64_t, ConfInt>(value);
    }

    bool updateUint(uint64_t value) {
        return update_value<uint64_t, ConfUint>(value);
    }

    bool updateFloat(double value) {
        return update_value<double, ConfFloat>(value);
    }

    bool updateBool(bool value) {
        return update_value<bool, ConfBool>(value);
    }

    template<typename T, typename ConfigT>
    size_t fillArray(T *arr, size_t elements) {
        if (!this->is<ConfArray>()) {
            logger.printfln("Can't fill array, Config is not an array");
            delay(100);
            return 0;
        }

        ConfArray *confArr = strict_variant::get<ConfArray>(&value);
        size_t toWrite = std::min(confArr->value.size(), elements);

        for(size_t i = 0; i < toWrite; ++i) {
            Config &entry = confArr->value[i];
            if (!entry.is<ConfigT>()) {
                logger.printfln("Config entry has wrong type.");
                delay(100);
                return 0;
            }
            arr[i] = strict_variant::get<ConfigT>(&entry.value)->value;
        }

        return toWrite;
    }

    size_t fillFloatArray(double *arr, size_t elements);

    size_t fillUint8Array(uint8_t *arr, size_t elements);
    size_t fillUint16Array(uint16_t *arr, size_t elements);
    size_t fillUint32Array(uint32_t *arr, size_t elements);
    size_t fillUint64Array(uint64_t *arr, size_t elements);

    size_t fillInt8Array(int8_t *arr, size_t elements);
    size_t fillInt16Array(int16_t *arr, size_t elements);
    size_t fillInt32Array(int32_t *arr, size_t elements);
    size_t fillInt64Array(int64_t *arr, size_t elements);
/*
    template<typename T, typename ConfigT>
    void fromArray(T *arr, size_t elements) {
        if (!this->is<ConfArray>()) {
            Serial.println("Can't from array, config is not an array");
            delay(100);
            return;
        }

        ConfArray *confArr = strict_variant::get<ConfArray>(&this->value);

        confArr->value.clear();
        for(size_t i = 0; i < elements; ++i) {
            confArr->value.push_back(confArr->prototype[0]);
            *confArr->value[i].as<T, ConfigT>() = arr[i];
            ConfigT *inner = strict_variant::get<ConfigT>(confArr->value[i]);
            String inner_error = inner->validator(*inner);
            if(inner_error != "") {
                //return String("[") + i + "]" + inner_error;
                Serial.println( String("[") + i + "]" + inner_error);
                delay(100);
                return;
            }
        }

        String error = confArr->validator(*confArr);
        if(error != "") {
            Serial.println(error);
            delay(100);
        }
    }
*/
    size_t json_size();

    String update_from_file(File file);

    String update_from_string(String s);

    String update_from_json(JsonVariant root);

    void save_to_file(File file);

    void write_to_stream(Print &output);
    void write_to_stream_except(Print &output, std::initializer_list<String> keys_to_censor);
    void write_to_stream_except(Print &output, const std::vector<String> &keys_to_censor);

    String to_string();
    String to_string_except(std::initializer_list<String> keys_to_censor);
    String to_string_except(const std::vector<String> &keys_to_censor);
};

/*void test() {
    Config value = Config::Object({
        {"ssid", Config::Str("", 32)},
        {"bssid", Config::Array({
                Config::Uint8(0),
                Config::Uint8(1),
                Config::Uint8(2),
                Config::Uint8(3),
                Config::Uint8(4),
                Config::Uint8(5)
                },
                Config::Uint8(0),
                6,
                6,
                Config::type_id<Config::ConfUint>()
            )
        },
        {"bssid_lock", Config::Bool(false)},
        {"passphrase", Config::Str("", 64, [](const Config::ConfString &s) {
                return s.value.length() == 0 ||
                    (s.value.length() >= 8 && s.value.length() <= 63) || //FIXME: check if there are only ASCII characters here.
                    (s.value.length() == 64) ? String("") : String("passphrase must be of length zero, or 8 to 63, or 64 if PSK."); //FIXME: check if there are only hex digits here.
            })
        },
        {"ip", Config::Uint32(0)},
        {"gateway", Config::Uint32(0)},
        {"subnet", Config::Uint32(0)},
        {"dns", Config::Uint32(0)},
        {"dns2", Config::Uint32(0)},
    });
    bool result = strict_variant::apply_visitor(recursive_validator{}, value.value);
    Serial.println(result);

    const char* json = "{\"ssid\":\"01234567890123456789012345678901\",\"bssid\":[0,1,2,3,4,5],\"bssid_lock\":true,\"passphrase\":\"01234567\",\"ip\":0,\"gateway\":0,\"subnet\":0,\"dns\":0,\"dns2\":0}";
    const size_t capacity = JSON_ARRAY_SIZE(6) + JSON_OBJECT_SIZE(9) + 120;
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, json);

    String error = strict_variant::apply_visitor(Config::from_json{doc.as<JsonVariant>()}, value.value);

    Serial.println(error);
    Serial.println(value.value.get<Config::ConfObject>()->value[0].second.value.get<Config::ConfString>()->value);


    Serial.printf("Capacity is %d, visited capacity is %d\n", capacity, value.json_size());

    DynamicJsonDocument doc2(value.json_size());

    JsonVariant var;
    if(value.is<Config::ConfObject>()) {
        var = doc2.to<JsonObject>();
    } else if(value.is<Config::ConfArray>()) {
        var = doc2.to<JsonArray>();
    } else {
        var = doc2.as<JsonVariant>();
    }
    strict_variant::apply_visitor(to_json{var}, value.value);

    //empty doc
    //root is obj? doc.to<JsonObject>()
    //root is arr? doc.to<JsonArray>()

    uint32_t bssidSecondByte = *value.get("bssid")->get(1)->asUint();

    serializeJson(doc2, Serial);
    Serial.println("");
    Serial.println(doc2.capacity());
    Serial.println(doc2.memoryUsage());
}
*/
