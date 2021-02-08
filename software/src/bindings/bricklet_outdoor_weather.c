/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_outdoor_weather.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_outdoor_weather_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_OutdoorWeather *outdoor_weather = (TF_OutdoorWeather *) dev;
    (void)payload;

    switch(fid) {

        case TF_OUTDOOR_WEATHER_CALLBACK_STATION_DATA: {
            TF_OutdoorWeatherStationDataHandler fn = outdoor_weather->station_data_handler;
            void *user_data = outdoor_weather->station_data_user_data;
            if (fn == NULL)
                return false;

            uint8_t identifier = tf_packetbuffer_read_uint8_t(payload);
            int16_t temperature = tf_packetbuffer_read_int16_t(payload);
            uint8_t humidity = tf_packetbuffer_read_uint8_t(payload);
            uint32_t wind_speed = tf_packetbuffer_read_uint32_t(payload);
            uint32_t gust_speed = tf_packetbuffer_read_uint32_t(payload);
            uint32_t rain = tf_packetbuffer_read_uint32_t(payload);
            uint8_t wind_direction = tf_packetbuffer_read_uint8_t(payload);
            bool battery_low = tf_packetbuffer_read_bool(payload);
            TF_HalCommon *common = tf_hal_get_common(outdoor_weather->tfp->hal);
            common->locked = true;
            fn(outdoor_weather, identifier, temperature, humidity, wind_speed, gust_speed, rain, wind_direction, battery_low, user_data);
            common->locked = false;
            break;
        }

        case TF_OUTDOOR_WEATHER_CALLBACK_SENSOR_DATA: {
            TF_OutdoorWeatherSensorDataHandler fn = outdoor_weather->sensor_data_handler;
            void *user_data = outdoor_weather->sensor_data_user_data;
            if (fn == NULL)
                return false;

            uint8_t identifier = tf_packetbuffer_read_uint8_t(payload);
            int16_t temperature = tf_packetbuffer_read_int16_t(payload);
            uint8_t humidity = tf_packetbuffer_read_uint8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(outdoor_weather->tfp->hal);
            common->locked = true;
            fn(outdoor_weather, identifier, temperature, humidity, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_outdoor_weather_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_outdoor_weather_create(TF_OutdoorWeather *outdoor_weather, const char *uid, TF_HalContext *hal) {
    memset(outdoor_weather, 0, sizeof(TF_OutdoorWeather));

    uint32_t numeric_uid;
    int rc = tf_base58_decode(uid, &numeric_uid);
    if (rc != TF_E_OK) {
        return rc;
    }

    uint8_t port_id;
    int inventory_index;
    rc = tf_hal_get_port_id(hal, numeric_uid, &port_id, &inventory_index);
    if (rc < 0) {
        return rc;
    }

    //rc = tf_tfp_init(outdoor_weather->tfp, numeric_uid, TF_OUTDOOR_WEATHER_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_outdoor_weather_callback_handler);
    rc = tf_hal_get_tfp(hal, &outdoor_weather->tfp, TF_OUTDOOR_WEATHER_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    outdoor_weather->tfp->device = outdoor_weather;
    outdoor_weather->tfp->uid = numeric_uid;
    outdoor_weather->tfp->cb_handler = tf_outdoor_weather_callback_handler;
    outdoor_weather->response_expected[0] = 0x03;
    return TF_E_OK;
}

int tf_outdoor_weather_destroy(TF_OutdoorWeather *outdoor_weather) {
    int result = tf_tfp_destroy(outdoor_weather->tfp);
    outdoor_weather->tfp = NULL;
    return result;
}

int tf_outdoor_weather_get_response_expected(TF_OutdoorWeather *outdoor_weather, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_OUTDOOR_WEATHER_FUNCTION_SET_STATION_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (outdoor_weather->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_OUTDOOR_WEATHER_FUNCTION_SET_SENSOR_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (outdoor_weather->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_OUTDOOR_WEATHER_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (outdoor_weather->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_OUTDOOR_WEATHER_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (outdoor_weather->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_OUTDOOR_WEATHER_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (outdoor_weather->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_OUTDOOR_WEATHER_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (outdoor_weather->response_expected[0] & (1 << 5)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_outdoor_weather_set_response_expected(TF_OutdoorWeather *outdoor_weather, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_OUTDOOR_WEATHER_FUNCTION_SET_STATION_CALLBACK_CONFIGURATION:
            if (response_expected) {
                outdoor_weather->response_expected[0] |= (1 << 0);
            } else {
                outdoor_weather->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_OUTDOOR_WEATHER_FUNCTION_SET_SENSOR_CALLBACK_CONFIGURATION:
            if (response_expected) {
                outdoor_weather->response_expected[0] |= (1 << 1);
            } else {
                outdoor_weather->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_OUTDOOR_WEATHER_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                outdoor_weather->response_expected[0] |= (1 << 2);
            } else {
                outdoor_weather->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_OUTDOOR_WEATHER_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                outdoor_weather->response_expected[0] |= (1 << 3);
            } else {
                outdoor_weather->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_OUTDOOR_WEATHER_FUNCTION_RESET:
            if (response_expected) {
                outdoor_weather->response_expected[0] |= (1 << 4);
            } else {
                outdoor_weather->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_OUTDOOR_WEATHER_FUNCTION_WRITE_UID:
            if (response_expected) {
                outdoor_weather->response_expected[0] |= (1 << 5);
            } else {
                outdoor_weather->response_expected[0] &= ~(1 << 5);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_outdoor_weather_set_response_expected_all(TF_OutdoorWeather *outdoor_weather, bool response_expected) {
    memset(outdoor_weather->response_expected, response_expected ? 0xFF : 0, 1);
}

int tf_outdoor_weather_get_station_identifiers_low_level(TF_OutdoorWeather *outdoor_weather, uint16_t *ret_identifiers_length, uint16_t *ret_identifiers_chunk_offset, uint8_t ret_identifiers_chunk_data[60]) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_GET_STATION_IDENTIFIERS_LOW_LEVEL, 0, 64, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_identifiers_length != NULL) { *ret_identifiers_length = tf_packetbuffer_read_uint16_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 2); }
        if (ret_identifiers_chunk_offset != NULL) { *ret_identifiers_chunk_offset = tf_packetbuffer_read_uint16_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 2); }
        if (ret_identifiers_chunk_data != NULL) { for (i = 0; i < 60; ++i) ret_identifiers_chunk_data[i] = tf_packetbuffer_read_uint8_t(&outdoor_weather->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 60); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_get_sensor_identifiers_low_level(TF_OutdoorWeather *outdoor_weather, uint16_t *ret_identifiers_length, uint16_t *ret_identifiers_chunk_offset, uint8_t ret_identifiers_chunk_data[60]) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_GET_SENSOR_IDENTIFIERS_LOW_LEVEL, 0, 64, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_identifiers_length != NULL) { *ret_identifiers_length = tf_packetbuffer_read_uint16_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 2); }
        if (ret_identifiers_chunk_offset != NULL) { *ret_identifiers_chunk_offset = tf_packetbuffer_read_uint16_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 2); }
        if (ret_identifiers_chunk_data != NULL) { for (i = 0; i < 60; ++i) ret_identifiers_chunk_data[i] = tf_packetbuffer_read_uint8_t(&outdoor_weather->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 60); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_get_station_data(TF_OutdoorWeather *outdoor_weather, uint8_t identifier, int16_t *ret_temperature, uint8_t *ret_humidity, uint32_t *ret_wind_speed, uint32_t *ret_gust_speed, uint32_t *ret_rain, uint8_t *ret_wind_direction, bool *ret_battery_low, uint16_t *ret_last_change) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_GET_STATION_DATA, 1, 19, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(outdoor_weather->tfp);

    buf[0] = (uint8_t)identifier;

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 2); }
        if (ret_humidity != NULL) { *ret_humidity = tf_packetbuffer_read_uint8_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 1); }
        if (ret_wind_speed != NULL) { *ret_wind_speed = tf_packetbuffer_read_uint32_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 4); }
        if (ret_gust_speed != NULL) { *ret_gust_speed = tf_packetbuffer_read_uint32_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 4); }
        if (ret_rain != NULL) { *ret_rain = tf_packetbuffer_read_uint32_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 4); }
        if (ret_wind_direction != NULL) { *ret_wind_direction = tf_packetbuffer_read_uint8_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 1); }
        if (ret_battery_low != NULL) { *ret_battery_low = tf_packetbuffer_read_bool(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 1); }
        if (ret_last_change != NULL) { *ret_last_change = tf_packetbuffer_read_uint16_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_get_sensor_data(TF_OutdoorWeather *outdoor_weather, uint8_t identifier, int16_t *ret_temperature, uint8_t *ret_humidity, uint16_t *ret_last_change) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_GET_SENSOR_DATA, 1, 5, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(outdoor_weather->tfp);

    buf[0] = (uint8_t)identifier;

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 2); }
        if (ret_humidity != NULL) { *ret_humidity = tf_packetbuffer_read_uint8_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 1); }
        if (ret_last_change != NULL) { *ret_last_change = tf_packetbuffer_read_uint16_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_set_station_callback_configuration(TF_OutdoorWeather *outdoor_weather, bool enable_callback) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_outdoor_weather_get_response_expected(outdoor_weather, TF_OUTDOOR_WEATHER_FUNCTION_SET_STATION_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_SET_STATION_CALLBACK_CONFIGURATION, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(outdoor_weather->tfp);

    buf[0] = enable_callback ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_get_station_callback_configuration(TF_OutdoorWeather *outdoor_weather, bool *ret_enable_callback) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_GET_STATION_CALLBACK_CONFIGURATION, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enable_callback != NULL) { *ret_enable_callback = tf_packetbuffer_read_bool(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_set_sensor_callback_configuration(TF_OutdoorWeather *outdoor_weather, bool enable_callback) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_outdoor_weather_get_response_expected(outdoor_weather, TF_OUTDOOR_WEATHER_FUNCTION_SET_SENSOR_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_SET_SENSOR_CALLBACK_CONFIGURATION, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(outdoor_weather->tfp);

    buf[0] = enable_callback ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_get_sensor_callback_configuration(TF_OutdoorWeather *outdoor_weather, bool *ret_enable_callback) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_GET_SENSOR_CALLBACK_CONFIGURATION, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enable_callback != NULL) { *ret_enable_callback = tf_packetbuffer_read_bool(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_get_spitfp_error_count(TF_OutdoorWeather *outdoor_weather, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_set_bootloader_mode(TF_OutdoorWeather *outdoor_weather, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(outdoor_weather->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_get_bootloader_mode(TF_OutdoorWeather *outdoor_weather, uint8_t *ret_mode) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_set_write_firmware_pointer(TF_OutdoorWeather *outdoor_weather, uint32_t pointer) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_outdoor_weather_get_response_expected(outdoor_weather, TF_OUTDOOR_WEATHER_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(outdoor_weather->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_write_firmware(TF_OutdoorWeather *outdoor_weather, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(outdoor_weather->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_set_status_led_config(TF_OutdoorWeather *outdoor_weather, uint8_t config) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_outdoor_weather_get_response_expected(outdoor_weather, TF_OUTDOOR_WEATHER_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(outdoor_weather->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_get_status_led_config(TF_OutdoorWeather *outdoor_weather, uint8_t *ret_config) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_get_chip_temperature(TF_OutdoorWeather *outdoor_weather, int16_t *ret_temperature) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_reset(TF_OutdoorWeather *outdoor_weather) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_outdoor_weather_get_response_expected(outdoor_weather, TF_OUTDOOR_WEATHER_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_write_uid(TF_OutdoorWeather *outdoor_weather, uint32_t uid) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_outdoor_weather_get_response_expected(outdoor_weather, TF_OUTDOOR_WEATHER_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(outdoor_weather->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_read_uid(TF_OutdoorWeather *outdoor_weather, uint32_t *ret_uid) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_get_identity(TF_OutdoorWeather *outdoor_weather, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(outdoor_weather->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(outdoor_weather->tfp, TF_OUTDOOR_WEATHER_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(outdoor_weather->tfp->hal) + tf_hal_get_common(outdoor_weather->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(outdoor_weather->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&outdoor_weather->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&outdoor_weather->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&outdoor_weather->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&outdoor_weather->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&outdoor_weather->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&outdoor_weather->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(outdoor_weather->tfp->hal, outdoor_weather->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(outdoor_weather->tfp);
    }

    result = tf_tfp_finish_send(outdoor_weather->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_outdoor_weather_get_station_identifiers(TF_OutdoorWeather *outdoor_weather, uint8_t *ret_identifiers, uint16_t *ret_identifiers_length) {
    int ret = TF_E_OK;
    uint16_t identifiers_length = 0;
    uint16_t identifiers_chunk_offset = 0;
    uint8_t identifiers_chunk_data[60];
    bool identifiers_out_of_sync;
    uint16_t identifiers_chunk_length = 0;

    *ret_identifiers_length = 0;

    ret = tf_outdoor_weather_get_station_identifiers_low_level(outdoor_weather, &identifiers_length, &identifiers_chunk_offset, identifiers_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    identifiers_out_of_sync = identifiers_chunk_offset != 0;

    if (!identifiers_out_of_sync) {
        identifiers_chunk_length = identifiers_length - identifiers_chunk_offset;

        if (identifiers_chunk_length > 60) {
            identifiers_chunk_length = 60;
        }

        memcpy(ret_identifiers, identifiers_chunk_data, sizeof(uint8_t) * identifiers_chunk_length);
        *ret_identifiers_length = identifiers_chunk_length;

        while (*ret_identifiers_length < identifiers_length) {
            ret = tf_outdoor_weather_get_station_identifiers_low_level(outdoor_weather, &identifiers_length, &identifiers_chunk_offset, identifiers_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            identifiers_out_of_sync = identifiers_chunk_offset != *ret_identifiers_length;

            if (identifiers_out_of_sync) {
                break;
            }

            identifiers_chunk_length = identifiers_length - identifiers_chunk_offset;

            if (identifiers_chunk_length > 60) {
                identifiers_chunk_length = 60;
            }

            memcpy(&ret_identifiers[*ret_identifiers_length], identifiers_chunk_data, sizeof(uint8_t) * identifiers_chunk_length);
            *ret_identifiers_length += identifiers_chunk_length;
        }
    }

    if (identifiers_out_of_sync) {
        *ret_identifiers_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (identifiers_chunk_offset + 60 < identifiers_length) {
            ret = tf_outdoor_weather_get_station_identifiers_low_level(outdoor_weather, &identifiers_length, &identifiers_chunk_offset, identifiers_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}

int tf_outdoor_weather_get_sensor_identifiers(TF_OutdoorWeather *outdoor_weather, uint8_t *ret_identifiers, uint16_t *ret_identifiers_length) {
    int ret = TF_E_OK;
    uint16_t identifiers_length = 0;
    uint16_t identifiers_chunk_offset = 0;
    uint8_t identifiers_chunk_data[60];
    bool identifiers_out_of_sync;
    uint16_t identifiers_chunk_length = 0;

    *ret_identifiers_length = 0;

    ret = tf_outdoor_weather_get_sensor_identifiers_low_level(outdoor_weather, &identifiers_length, &identifiers_chunk_offset, identifiers_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    identifiers_out_of_sync = identifiers_chunk_offset != 0;

    if (!identifiers_out_of_sync) {
        identifiers_chunk_length = identifiers_length - identifiers_chunk_offset;

        if (identifiers_chunk_length > 60) {
            identifiers_chunk_length = 60;
        }

        memcpy(ret_identifiers, identifiers_chunk_data, sizeof(uint8_t) * identifiers_chunk_length);
        *ret_identifiers_length = identifiers_chunk_length;

        while (*ret_identifiers_length < identifiers_length) {
            ret = tf_outdoor_weather_get_sensor_identifiers_low_level(outdoor_weather, &identifiers_length, &identifiers_chunk_offset, identifiers_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            identifiers_out_of_sync = identifiers_chunk_offset != *ret_identifiers_length;

            if (identifiers_out_of_sync) {
                break;
            }

            identifiers_chunk_length = identifiers_length - identifiers_chunk_offset;

            if (identifiers_chunk_length > 60) {
                identifiers_chunk_length = 60;
            }

            memcpy(&ret_identifiers[*ret_identifiers_length], identifiers_chunk_data, sizeof(uint8_t) * identifiers_chunk_length);
            *ret_identifiers_length += identifiers_chunk_length;
        }
    }

    if (identifiers_out_of_sync) {
        *ret_identifiers_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (identifiers_chunk_offset + 60 < identifiers_length) {
            ret = tf_outdoor_weather_get_sensor_identifiers_low_level(outdoor_weather, &identifiers_length, &identifiers_chunk_offset, identifiers_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_outdoor_weather_register_station_data_callback(TF_OutdoorWeather *outdoor_weather, TF_OutdoorWeatherStationDataHandler handler, void *user_data) {
    if (handler == NULL) {
        outdoor_weather->tfp->needs_callback_tick = false;
        outdoor_weather->tfp->needs_callback_tick |= outdoor_weather->sensor_data_handler != NULL;
    } else {
        outdoor_weather->tfp->needs_callback_tick = true;
    }
    outdoor_weather->station_data_handler = handler;
    outdoor_weather->station_data_user_data = user_data;
}


void tf_outdoor_weather_register_sensor_data_callback(TF_OutdoorWeather *outdoor_weather, TF_OutdoorWeatherSensorDataHandler handler, void *user_data) {
    if (handler == NULL) {
        outdoor_weather->tfp->needs_callback_tick = false;
        outdoor_weather->tfp->needs_callback_tick |= outdoor_weather->station_data_handler != NULL;
    } else {
        outdoor_weather->tfp->needs_callback_tick = true;
    }
    outdoor_weather->sensor_data_handler = handler;
    outdoor_weather->sensor_data_user_data = user_data;
}
#endif
int tf_outdoor_weather_callback_tick(TF_OutdoorWeather *outdoor_weather, uint32_t timeout_us) {
    return tf_tfp_callback_tick(outdoor_weather->tfp, tf_hal_current_time_us(outdoor_weather->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
