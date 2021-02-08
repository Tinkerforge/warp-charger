/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_barometer_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_barometer_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_BarometerV2 *barometer_v2 = (TF_BarometerV2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_BAROMETER_V2_CALLBACK_AIR_PRESSURE: {
            TF_BarometerV2AirPressureHandler fn = barometer_v2->air_pressure_handler;
            void *user_data = barometer_v2->air_pressure_user_data;
            if (fn == NULL)
                return false;

            int32_t air_pressure = tf_packetbuffer_read_int32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(barometer_v2->tfp->hal);
            common->locked = true;
            fn(barometer_v2, air_pressure, user_data);
            common->locked = false;
            break;
        }

        case TF_BAROMETER_V2_CALLBACK_ALTITUDE: {
            TF_BarometerV2AltitudeHandler fn = barometer_v2->altitude_handler;
            void *user_data = barometer_v2->altitude_user_data;
            if (fn == NULL)
                return false;

            int32_t altitude = tf_packetbuffer_read_int32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(barometer_v2->tfp->hal);
            common->locked = true;
            fn(barometer_v2, altitude, user_data);
            common->locked = false;
            break;
        }

        case TF_BAROMETER_V2_CALLBACK_TEMPERATURE: {
            TF_BarometerV2TemperatureHandler fn = barometer_v2->temperature_handler;
            void *user_data = barometer_v2->temperature_user_data;
            if (fn == NULL)
                return false;

            int32_t temperature = tf_packetbuffer_read_int32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(barometer_v2->tfp->hal);
            common->locked = true;
            fn(barometer_v2, temperature, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_barometer_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_barometer_v2_create(TF_BarometerV2 *barometer_v2, const char *uid, TF_HalContext *hal) {
    memset(barometer_v2, 0, sizeof(TF_BarometerV2));

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

    //rc = tf_tfp_init(barometer_v2->tfp, numeric_uid, TF_BAROMETER_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_barometer_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &barometer_v2->tfp, TF_BAROMETER_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    barometer_v2->tfp->device = barometer_v2;
    barometer_v2->tfp->uid = numeric_uid;
    barometer_v2->tfp->cb_handler = tf_barometer_v2_callback_handler;
    barometer_v2->response_expected[0] = 0x07;
    barometer_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_barometer_v2_destroy(TF_BarometerV2 *barometer_v2) {
    int result = tf_tfp_destroy(barometer_v2->tfp);
    barometer_v2->tfp = NULL;
    return result;
}

int tf_barometer_v2_get_response_expected(TF_BarometerV2 *barometer_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_BAROMETER_V2_FUNCTION_SET_AIR_PRESSURE_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (barometer_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_ALTITUDE_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (barometer_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (barometer_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_MOVING_AVERAGE_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (barometer_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_REFERENCE_AIR_PRESSURE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (barometer_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_CALIBRATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (barometer_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_SENSOR_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (barometer_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (barometer_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (barometer_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_BAROMETER_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (barometer_v2->response_expected[1] & (1 << 1)) != 0;
            break;
        case TF_BAROMETER_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (barometer_v2->response_expected[1] & (1 << 2)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_barometer_v2_set_response_expected(TF_BarometerV2 *barometer_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_BAROMETER_V2_FUNCTION_SET_AIR_PRESSURE_CALLBACK_CONFIGURATION:
            if (response_expected) {
                barometer_v2->response_expected[0] |= (1 << 0);
            } else {
                barometer_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_ALTITUDE_CALLBACK_CONFIGURATION:
            if (response_expected) {
                barometer_v2->response_expected[0] |= (1 << 1);
            } else {
                barometer_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION:
            if (response_expected) {
                barometer_v2->response_expected[0] |= (1 << 2);
            } else {
                barometer_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_MOVING_AVERAGE_CONFIGURATION:
            if (response_expected) {
                barometer_v2->response_expected[0] |= (1 << 3);
            } else {
                barometer_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_REFERENCE_AIR_PRESSURE:
            if (response_expected) {
                barometer_v2->response_expected[0] |= (1 << 4);
            } else {
                barometer_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_CALIBRATION:
            if (response_expected) {
                barometer_v2->response_expected[0] |= (1 << 5);
            } else {
                barometer_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_SENSOR_CONFIGURATION:
            if (response_expected) {
                barometer_v2->response_expected[0] |= (1 << 6);
            } else {
                barometer_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                barometer_v2->response_expected[0] |= (1 << 7);
            } else {
                barometer_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_BAROMETER_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                barometer_v2->response_expected[1] |= (1 << 0);
            } else {
                barometer_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_BAROMETER_V2_FUNCTION_RESET:
            if (response_expected) {
                barometer_v2->response_expected[1] |= (1 << 1);
            } else {
                barometer_v2->response_expected[1] &= ~(1 << 1);
            }
            break;
        case TF_BAROMETER_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                barometer_v2->response_expected[1] |= (1 << 2);
            } else {
                barometer_v2->response_expected[1] &= ~(1 << 2);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_barometer_v2_set_response_expected_all(TF_BarometerV2 *barometer_v2, bool response_expected) {
    memset(barometer_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_barometer_v2_get_air_pressure(TF_BarometerV2 *barometer_v2, int32_t *ret_air_pressure) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_AIR_PRESSURE, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_air_pressure != NULL) { *ret_air_pressure = tf_packetbuffer_read_int32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_set_air_pressure_callback_configuration(TF_BarometerV2 *barometer_v2, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_barometer_v2_get_response_expected(barometer_v2, TF_BAROMETER_V2_FUNCTION_SET_AIR_PRESSURE_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_SET_AIR_PRESSURE_CALLBACK_CONFIGURATION, 14, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(barometer_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;
    buf[5] = (uint8_t)option;
    min = tf_leconvert_int32_to(min); memcpy(buf + 6, &min, 4);
    max = tf_leconvert_int32_to(max); memcpy(buf + 10, &max, 4);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_air_pressure_callback_configuration(TF_BarometerV2 *barometer_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_AIR_PRESSURE_CALLBACK_CONFIGURATION, 0, 14, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_option != NULL) { *ret_option = tf_packetbuffer_read_char(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_min != NULL) { *ret_min = tf_packetbuffer_read_int32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_max != NULL) { *ret_max = tf_packetbuffer_read_int32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_altitude(TF_BarometerV2 *barometer_v2, int32_t *ret_altitude) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_ALTITUDE, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_altitude != NULL) { *ret_altitude = tf_packetbuffer_read_int32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_set_altitude_callback_configuration(TF_BarometerV2 *barometer_v2, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_barometer_v2_get_response_expected(barometer_v2, TF_BAROMETER_V2_FUNCTION_SET_ALTITUDE_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_SET_ALTITUDE_CALLBACK_CONFIGURATION, 14, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(barometer_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;
    buf[5] = (uint8_t)option;
    min = tf_leconvert_int32_to(min); memcpy(buf + 6, &min, 4);
    max = tf_leconvert_int32_to(max); memcpy(buf + 10, &max, 4);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_altitude_callback_configuration(TF_BarometerV2 *barometer_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_ALTITUDE_CALLBACK_CONFIGURATION, 0, 14, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_option != NULL) { *ret_option = tf_packetbuffer_read_char(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_min != NULL) { *ret_min = tf_packetbuffer_read_int32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_max != NULL) { *ret_max = tf_packetbuffer_read_int32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_temperature(TF_BarometerV2 *barometer_v2, int32_t *ret_temperature) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_TEMPERATURE, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_set_temperature_callback_configuration(TF_BarometerV2 *barometer_v2, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_barometer_v2_get_response_expected(barometer_v2, TF_BAROMETER_V2_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION, 14, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(barometer_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;
    buf[5] = (uint8_t)option;
    min = tf_leconvert_int32_to(min); memcpy(buf + 6, &min, 4);
    max = tf_leconvert_int32_to(max); memcpy(buf + 10, &max, 4);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_temperature_callback_configuration(TF_BarometerV2 *barometer_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_TEMPERATURE_CALLBACK_CONFIGURATION, 0, 14, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_option != NULL) { *ret_option = tf_packetbuffer_read_char(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_min != NULL) { *ret_min = tf_packetbuffer_read_int32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_max != NULL) { *ret_max = tf_packetbuffer_read_int32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_set_moving_average_configuration(TF_BarometerV2 *barometer_v2, uint16_t moving_average_length_air_pressure, uint16_t moving_average_length_temperature) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_barometer_v2_get_response_expected(barometer_v2, TF_BAROMETER_V2_FUNCTION_SET_MOVING_AVERAGE_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_SET_MOVING_AVERAGE_CONFIGURATION, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(barometer_v2->tfp);

    moving_average_length_air_pressure = tf_leconvert_uint16_to(moving_average_length_air_pressure); memcpy(buf + 0, &moving_average_length_air_pressure, 2);
    moving_average_length_temperature = tf_leconvert_uint16_to(moving_average_length_temperature); memcpy(buf + 2, &moving_average_length_temperature, 2);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_moving_average_configuration(TF_BarometerV2 *barometer_v2, uint16_t *ret_moving_average_length_air_pressure, uint16_t *ret_moving_average_length_temperature) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_MOVING_AVERAGE_CONFIGURATION, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_moving_average_length_air_pressure != NULL) { *ret_moving_average_length_air_pressure = tf_packetbuffer_read_uint16_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_moving_average_length_temperature != NULL) { *ret_moving_average_length_temperature = tf_packetbuffer_read_uint16_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_set_reference_air_pressure(TF_BarometerV2 *barometer_v2, int32_t air_pressure) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_barometer_v2_get_response_expected(barometer_v2, TF_BAROMETER_V2_FUNCTION_SET_REFERENCE_AIR_PRESSURE, &response_expected);
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_SET_REFERENCE_AIR_PRESSURE, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(barometer_v2->tfp);

    air_pressure = tf_leconvert_int32_to(air_pressure); memcpy(buf + 0, &air_pressure, 4);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_reference_air_pressure(TF_BarometerV2 *barometer_v2, int32_t *ret_air_pressure) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_REFERENCE_AIR_PRESSURE, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_air_pressure != NULL) { *ret_air_pressure = tf_packetbuffer_read_int32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_set_calibration(TF_BarometerV2 *barometer_v2, int32_t measured_air_pressure, int32_t actual_air_pressure) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_barometer_v2_get_response_expected(barometer_v2, TF_BAROMETER_V2_FUNCTION_SET_CALIBRATION, &response_expected);
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_SET_CALIBRATION, 8, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(barometer_v2->tfp);

    measured_air_pressure = tf_leconvert_int32_to(measured_air_pressure); memcpy(buf + 0, &measured_air_pressure, 4);
    actual_air_pressure = tf_leconvert_int32_to(actual_air_pressure); memcpy(buf + 4, &actual_air_pressure, 4);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_calibration(TF_BarometerV2 *barometer_v2, int32_t *ret_measured_air_pressure, int32_t *ret_actual_air_pressure) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_CALIBRATION, 0, 8, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_measured_air_pressure != NULL) { *ret_measured_air_pressure = tf_packetbuffer_read_int32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_actual_air_pressure != NULL) { *ret_actual_air_pressure = tf_packetbuffer_read_int32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_set_sensor_configuration(TF_BarometerV2 *barometer_v2, uint8_t data_rate, uint8_t air_pressure_low_pass_filter) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_barometer_v2_get_response_expected(barometer_v2, TF_BAROMETER_V2_FUNCTION_SET_SENSOR_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_SET_SENSOR_CONFIGURATION, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(barometer_v2->tfp);

    buf[0] = (uint8_t)data_rate;
    buf[1] = (uint8_t)air_pressure_low_pass_filter;

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_sensor_configuration(TF_BarometerV2 *barometer_v2, uint8_t *ret_data_rate, uint8_t *ret_air_pressure_low_pass_filter) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_SENSOR_CONFIGURATION, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_data_rate != NULL) { *ret_data_rate = tf_packetbuffer_read_uint8_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_air_pressure_low_pass_filter != NULL) { *ret_air_pressure_low_pass_filter = tf_packetbuffer_read_uint8_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_spitfp_error_count(TF_BarometerV2 *barometer_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_set_bootloader_mode(TF_BarometerV2 *barometer_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(barometer_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_bootloader_mode(TF_BarometerV2 *barometer_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_set_write_firmware_pointer(TF_BarometerV2 *barometer_v2, uint32_t pointer) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_barometer_v2_get_response_expected(barometer_v2, TF_BAROMETER_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(barometer_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_write_firmware(TF_BarometerV2 *barometer_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(barometer_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_set_status_led_config(TF_BarometerV2 *barometer_v2, uint8_t config) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_barometer_v2_get_response_expected(barometer_v2, TF_BAROMETER_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(barometer_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_status_led_config(TF_BarometerV2 *barometer_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_chip_temperature(TF_BarometerV2 *barometer_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_reset(TF_BarometerV2 *barometer_v2) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_barometer_v2_get_response_expected(barometer_v2, TF_BAROMETER_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_write_uid(TF_BarometerV2 *barometer_v2, uint32_t uid) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_barometer_v2_get_response_expected(barometer_v2, TF_BAROMETER_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(barometer_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_read_uid(TF_BarometerV2 *barometer_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_barometer_v2_get_identity(TF_BarometerV2 *barometer_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(barometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(barometer_v2->tfp, TF_BAROMETER_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(barometer_v2->tfp->hal) + tf_hal_get_common(barometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(barometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&barometer_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&barometer_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&barometer_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&barometer_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&barometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&barometer_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(barometer_v2->tfp->hal, barometer_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(barometer_v2->tfp);
    }

    result = tf_tfp_finish_send(barometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_barometer_v2_register_air_pressure_callback(TF_BarometerV2 *barometer_v2, TF_BarometerV2AirPressureHandler handler, void *user_data) {
    if (handler == NULL) {
        barometer_v2->tfp->needs_callback_tick = false;
        barometer_v2->tfp->needs_callback_tick |= barometer_v2->altitude_handler != NULL;
        barometer_v2->tfp->needs_callback_tick |= barometer_v2->temperature_handler != NULL;
    } else {
        barometer_v2->tfp->needs_callback_tick = true;
    }
    barometer_v2->air_pressure_handler = handler;
    barometer_v2->air_pressure_user_data = user_data;
}


void tf_barometer_v2_register_altitude_callback(TF_BarometerV2 *barometer_v2, TF_BarometerV2AltitudeHandler handler, void *user_data) {
    if (handler == NULL) {
        barometer_v2->tfp->needs_callback_tick = false;
        barometer_v2->tfp->needs_callback_tick |= barometer_v2->air_pressure_handler != NULL;
        barometer_v2->tfp->needs_callback_tick |= barometer_v2->temperature_handler != NULL;
    } else {
        barometer_v2->tfp->needs_callback_tick = true;
    }
    barometer_v2->altitude_handler = handler;
    barometer_v2->altitude_user_data = user_data;
}


void tf_barometer_v2_register_temperature_callback(TF_BarometerV2 *barometer_v2, TF_BarometerV2TemperatureHandler handler, void *user_data) {
    if (handler == NULL) {
        barometer_v2->tfp->needs_callback_tick = false;
        barometer_v2->tfp->needs_callback_tick |= barometer_v2->air_pressure_handler != NULL;
        barometer_v2->tfp->needs_callback_tick |= barometer_v2->altitude_handler != NULL;
    } else {
        barometer_v2->tfp->needs_callback_tick = true;
    }
    barometer_v2->temperature_handler = handler;
    barometer_v2->temperature_user_data = user_data;
}
#endif
int tf_barometer_v2_callback_tick(TF_BarometerV2 *barometer_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(barometer_v2->tfp, tf_hal_current_time_us(barometer_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
