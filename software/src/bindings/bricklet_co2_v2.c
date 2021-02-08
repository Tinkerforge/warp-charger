/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_co2_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_co2_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_CO2V2 *co2_v2 = (TF_CO2V2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_CO2_V2_CALLBACK_ALL_VALUES: {
            TF_CO2V2AllValuesHandler fn = co2_v2->all_values_handler;
            void *user_data = co2_v2->all_values_user_data;
            if (fn == NULL)
                return false;

            uint16_t co2_concentration = tf_packetbuffer_read_uint16_t(payload);
            int16_t temperature = tf_packetbuffer_read_int16_t(payload);
            uint16_t humidity = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(co2_v2->tfp->hal);
            common->locked = true;
            fn(co2_v2, co2_concentration, temperature, humidity, user_data);
            common->locked = false;
            break;
        }

        case TF_CO2_V2_CALLBACK_CO2_CONCENTRATION: {
            TF_CO2V2CO2ConcentrationHandler fn = co2_v2->co2_concentration_handler;
            void *user_data = co2_v2->co2_concentration_user_data;
            if (fn == NULL)
                return false;

            uint16_t co2_concentration = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(co2_v2->tfp->hal);
            common->locked = true;
            fn(co2_v2, co2_concentration, user_data);
            common->locked = false;
            break;
        }

        case TF_CO2_V2_CALLBACK_TEMPERATURE: {
            TF_CO2V2TemperatureHandler fn = co2_v2->temperature_handler;
            void *user_data = co2_v2->temperature_user_data;
            if (fn == NULL)
                return false;

            int16_t temperature = tf_packetbuffer_read_int16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(co2_v2->tfp->hal);
            common->locked = true;
            fn(co2_v2, temperature, user_data);
            common->locked = false;
            break;
        }

        case TF_CO2_V2_CALLBACK_HUMIDITY: {
            TF_CO2V2HumidityHandler fn = co2_v2->humidity_handler;
            void *user_data = co2_v2->humidity_user_data;
            if (fn == NULL)
                return false;

            uint16_t humidity = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(co2_v2->tfp->hal);
            common->locked = true;
            fn(co2_v2, humidity, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_co2_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_co2_v2_create(TF_CO2V2 *co2_v2, const char *uid, TF_HalContext *hal) {
    memset(co2_v2, 0, sizeof(TF_CO2V2));

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

    //rc = tf_tfp_init(co2_v2->tfp, numeric_uid, TF_CO2_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_co2_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &co2_v2->tfp, TF_CO2_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    co2_v2->tfp->device = co2_v2;
    co2_v2->tfp->uid = numeric_uid;
    co2_v2->tfp->cb_handler = tf_co2_v2_callback_handler;
    co2_v2->response_expected[0] = 0x3C;
    co2_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_co2_v2_destroy(TF_CO2V2 *co2_v2) {
    int result = tf_tfp_destroy(co2_v2->tfp);
    co2_v2->tfp = NULL;
    return result;
}

int tf_co2_v2_get_response_expected(TF_CO2V2 *co2_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_CO2_V2_FUNCTION_SET_AIR_PRESSURE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (co2_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_CO2_V2_FUNCTION_SET_TEMPERATURE_OFFSET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (co2_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_CO2_V2_FUNCTION_SET_ALL_VALUES_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (co2_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_CO2_V2_FUNCTION_SET_CO2_CONCENTRATION_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (co2_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_CO2_V2_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (co2_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_CO2_V2_FUNCTION_SET_HUMIDITY_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (co2_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_CO2_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (co2_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_CO2_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (co2_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_CO2_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (co2_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_CO2_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (co2_v2->response_expected[1] & (1 << 1)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_co2_v2_set_response_expected(TF_CO2V2 *co2_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_CO2_V2_FUNCTION_SET_AIR_PRESSURE:
            if (response_expected) {
                co2_v2->response_expected[0] |= (1 << 0);
            } else {
                co2_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_CO2_V2_FUNCTION_SET_TEMPERATURE_OFFSET:
            if (response_expected) {
                co2_v2->response_expected[0] |= (1 << 1);
            } else {
                co2_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_CO2_V2_FUNCTION_SET_ALL_VALUES_CALLBACK_CONFIGURATION:
            if (response_expected) {
                co2_v2->response_expected[0] |= (1 << 2);
            } else {
                co2_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_CO2_V2_FUNCTION_SET_CO2_CONCENTRATION_CALLBACK_CONFIGURATION:
            if (response_expected) {
                co2_v2->response_expected[0] |= (1 << 3);
            } else {
                co2_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_CO2_V2_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION:
            if (response_expected) {
                co2_v2->response_expected[0] |= (1 << 4);
            } else {
                co2_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_CO2_V2_FUNCTION_SET_HUMIDITY_CALLBACK_CONFIGURATION:
            if (response_expected) {
                co2_v2->response_expected[0] |= (1 << 5);
            } else {
                co2_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_CO2_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                co2_v2->response_expected[0] |= (1 << 6);
            } else {
                co2_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_CO2_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                co2_v2->response_expected[0] |= (1 << 7);
            } else {
                co2_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_CO2_V2_FUNCTION_RESET:
            if (response_expected) {
                co2_v2->response_expected[1] |= (1 << 0);
            } else {
                co2_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_CO2_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                co2_v2->response_expected[1] |= (1 << 1);
            } else {
                co2_v2->response_expected[1] &= ~(1 << 1);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_co2_v2_set_response_expected_all(TF_CO2V2 *co2_v2, bool response_expected) {
    memset(co2_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_co2_v2_get_all_values(TF_CO2V2 *co2_v2, uint16_t *ret_co2_concentration, int16_t *ret_temperature, uint16_t *ret_humidity) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_ALL_VALUES, 0, 6, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_co2_concentration != NULL) { *ret_co2_concentration = tf_packetbuffer_read_uint16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_humidity != NULL) { *ret_humidity = tf_packetbuffer_read_uint16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_set_air_pressure(TF_CO2V2 *co2_v2, uint16_t air_pressure) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_co2_v2_get_response_expected(co2_v2, TF_CO2_V2_FUNCTION_SET_AIR_PRESSURE, &response_expected);
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_SET_AIR_PRESSURE, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(co2_v2->tfp);

    air_pressure = tf_leconvert_uint16_to(air_pressure); memcpy(buf + 0, &air_pressure, 2);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_air_pressure(TF_CO2V2 *co2_v2, uint16_t *ret_air_pressure) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_AIR_PRESSURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_air_pressure != NULL) { *ret_air_pressure = tf_packetbuffer_read_uint16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_set_temperature_offset(TF_CO2V2 *co2_v2, uint16_t offset) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_co2_v2_get_response_expected(co2_v2, TF_CO2_V2_FUNCTION_SET_TEMPERATURE_OFFSET, &response_expected);
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_SET_TEMPERATURE_OFFSET, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(co2_v2->tfp);

    offset = tf_leconvert_uint16_to(offset); memcpy(buf + 0, &offset, 2);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_temperature_offset(TF_CO2V2 *co2_v2, uint16_t *ret_offset) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_TEMPERATURE_OFFSET, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_offset != NULL) { *ret_offset = tf_packetbuffer_read_uint16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_set_all_values_callback_configuration(TF_CO2V2 *co2_v2, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_co2_v2_get_response_expected(co2_v2, TF_CO2_V2_FUNCTION_SET_ALL_VALUES_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_SET_ALL_VALUES_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(co2_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_all_values_callback_configuration(TF_CO2V2 *co2_v2, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_ALL_VALUES_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_co2_concentration(TF_CO2V2 *co2_v2, uint16_t *ret_co2_concentration) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_CO2_CONCENTRATION, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_co2_concentration != NULL) { *ret_co2_concentration = tf_packetbuffer_read_uint16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_set_co2_concentration_callback_configuration(TF_CO2V2 *co2_v2, uint32_t period, bool value_has_to_change, char option, uint16_t min, uint16_t max) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_co2_v2_get_response_expected(co2_v2, TF_CO2_V2_FUNCTION_SET_CO2_CONCENTRATION_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_SET_CO2_CONCENTRATION_CALLBACK_CONFIGURATION, 10, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(co2_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;
    buf[5] = (uint8_t)option;
    min = tf_leconvert_uint16_to(min); memcpy(buf + 6, &min, 2);
    max = tf_leconvert_uint16_to(max); memcpy(buf + 8, &max, 2);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_co2_concentration_callback_configuration(TF_CO2V2 *co2_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_CO2_CONCENTRATION_CALLBACK_CONFIGURATION, 0, 10, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_option != NULL) { *ret_option = tf_packetbuffer_read_char(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_min != NULL) { *ret_min = tf_packetbuffer_read_uint16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_max != NULL) { *ret_max = tf_packetbuffer_read_uint16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_temperature(TF_CO2V2 *co2_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_set_temperature_callback_configuration(TF_CO2V2 *co2_v2, uint32_t period, bool value_has_to_change, char option, int16_t min, int16_t max) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_co2_v2_get_response_expected(co2_v2, TF_CO2_V2_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION, 10, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(co2_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;
    buf[5] = (uint8_t)option;
    min = tf_leconvert_int16_to(min); memcpy(buf + 6, &min, 2);
    max = tf_leconvert_int16_to(max); memcpy(buf + 8, &max, 2);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_temperature_callback_configuration(TF_CO2V2 *co2_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_TEMPERATURE_CALLBACK_CONFIGURATION, 0, 10, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_option != NULL) { *ret_option = tf_packetbuffer_read_char(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_min != NULL) { *ret_min = tf_packetbuffer_read_int16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_max != NULL) { *ret_max = tf_packetbuffer_read_int16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_humidity(TF_CO2V2 *co2_v2, uint16_t *ret_humidity) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_HUMIDITY, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_humidity != NULL) { *ret_humidity = tf_packetbuffer_read_uint16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_set_humidity_callback_configuration(TF_CO2V2 *co2_v2, uint32_t period, bool value_has_to_change, char option, uint16_t min, uint16_t max) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_co2_v2_get_response_expected(co2_v2, TF_CO2_V2_FUNCTION_SET_HUMIDITY_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_SET_HUMIDITY_CALLBACK_CONFIGURATION, 10, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(co2_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;
    buf[5] = (uint8_t)option;
    min = tf_leconvert_uint16_to(min); memcpy(buf + 6, &min, 2);
    max = tf_leconvert_uint16_to(max); memcpy(buf + 8, &max, 2);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_humidity_callback_configuration(TF_CO2V2 *co2_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_HUMIDITY_CALLBACK_CONFIGURATION, 0, 10, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_option != NULL) { *ret_option = tf_packetbuffer_read_char(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_min != NULL) { *ret_min = tf_packetbuffer_read_uint16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_max != NULL) { *ret_max = tf_packetbuffer_read_uint16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_spitfp_error_count(TF_CO2V2 *co2_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_set_bootloader_mode(TF_CO2V2 *co2_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(co2_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_bootloader_mode(TF_CO2V2 *co2_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_set_write_firmware_pointer(TF_CO2V2 *co2_v2, uint32_t pointer) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_co2_v2_get_response_expected(co2_v2, TF_CO2_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(co2_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_write_firmware(TF_CO2V2 *co2_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(co2_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_set_status_led_config(TF_CO2V2 *co2_v2, uint8_t config) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_co2_v2_get_response_expected(co2_v2, TF_CO2_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(co2_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_status_led_config(TF_CO2V2 *co2_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_chip_temperature(TF_CO2V2 *co2_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_reset(TF_CO2V2 *co2_v2) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_co2_v2_get_response_expected(co2_v2, TF_CO2_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_write_uid(TF_CO2V2 *co2_v2, uint32_t uid) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_co2_v2_get_response_expected(co2_v2, TF_CO2_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(co2_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_read_uid(TF_CO2V2 *co2_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_co2_v2_get_identity(TF_CO2V2 *co2_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(co2_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(co2_v2->tfp, TF_CO2_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(co2_v2->tfp->hal) + tf_hal_get_common(co2_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(co2_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&co2_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&co2_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&co2_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&co2_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&co2_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&co2_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(co2_v2->tfp->hal, co2_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(co2_v2->tfp);
    }

    result = tf_tfp_finish_send(co2_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_co2_v2_register_all_values_callback(TF_CO2V2 *co2_v2, TF_CO2V2AllValuesHandler handler, void *user_data) {
    if (handler == NULL) {
        co2_v2->tfp->needs_callback_tick = false;
        co2_v2->tfp->needs_callback_tick |= co2_v2->co2_concentration_handler != NULL;
        co2_v2->tfp->needs_callback_tick |= co2_v2->temperature_handler != NULL;
        co2_v2->tfp->needs_callback_tick |= co2_v2->humidity_handler != NULL;
    } else {
        co2_v2->tfp->needs_callback_tick = true;
    }
    co2_v2->all_values_handler = handler;
    co2_v2->all_values_user_data = user_data;
}


void tf_co2_v2_register_co2_concentration_callback(TF_CO2V2 *co2_v2, TF_CO2V2CO2ConcentrationHandler handler, void *user_data) {
    if (handler == NULL) {
        co2_v2->tfp->needs_callback_tick = false;
        co2_v2->tfp->needs_callback_tick |= co2_v2->all_values_handler != NULL;
        co2_v2->tfp->needs_callback_tick |= co2_v2->temperature_handler != NULL;
        co2_v2->tfp->needs_callback_tick |= co2_v2->humidity_handler != NULL;
    } else {
        co2_v2->tfp->needs_callback_tick = true;
    }
    co2_v2->co2_concentration_handler = handler;
    co2_v2->co2_concentration_user_data = user_data;
}


void tf_co2_v2_register_temperature_callback(TF_CO2V2 *co2_v2, TF_CO2V2TemperatureHandler handler, void *user_data) {
    if (handler == NULL) {
        co2_v2->tfp->needs_callback_tick = false;
        co2_v2->tfp->needs_callback_tick |= co2_v2->all_values_handler != NULL;
        co2_v2->tfp->needs_callback_tick |= co2_v2->co2_concentration_handler != NULL;
        co2_v2->tfp->needs_callback_tick |= co2_v2->humidity_handler != NULL;
    } else {
        co2_v2->tfp->needs_callback_tick = true;
    }
    co2_v2->temperature_handler = handler;
    co2_v2->temperature_user_data = user_data;
}


void tf_co2_v2_register_humidity_callback(TF_CO2V2 *co2_v2, TF_CO2V2HumidityHandler handler, void *user_data) {
    if (handler == NULL) {
        co2_v2->tfp->needs_callback_tick = false;
        co2_v2->tfp->needs_callback_tick |= co2_v2->all_values_handler != NULL;
        co2_v2->tfp->needs_callback_tick |= co2_v2->co2_concentration_handler != NULL;
        co2_v2->tfp->needs_callback_tick |= co2_v2->temperature_handler != NULL;
    } else {
        co2_v2->tfp->needs_callback_tick = true;
    }
    co2_v2->humidity_handler = handler;
    co2_v2->humidity_user_data = user_data;
}
#endif
int tf_co2_v2_callback_tick(TF_CO2V2 *co2_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(co2_v2->tfp, tf_hal_current_time_us(co2_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
