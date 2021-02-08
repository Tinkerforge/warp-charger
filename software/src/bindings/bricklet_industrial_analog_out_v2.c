/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_industrial_analog_out_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


static bool tf_industrial_analog_out_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    (void)dev;
    (void)fid;
    (void)payload;
    return false;
}
int tf_industrial_analog_out_v2_create(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, const char *uid, TF_HalContext *hal) {
    memset(industrial_analog_out_v2, 0, sizeof(TF_IndustrialAnalogOutV2));

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

    //rc = tf_tfp_init(industrial_analog_out_v2->tfp, numeric_uid, TF_INDUSTRIAL_ANALOG_OUT_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_industrial_analog_out_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    industrial_analog_out_v2->tfp->device = industrial_analog_out_v2;
    industrial_analog_out_v2->tfp->uid = numeric_uid;
    industrial_analog_out_v2->tfp->cb_handler = tf_industrial_analog_out_v2_callback_handler;
    industrial_analog_out_v2->response_expected[0] = 0x00;
    industrial_analog_out_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_industrial_analog_out_v2_destroy(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2) {
    int result = tf_tfp_destroy(industrial_analog_out_v2->tfp);
    industrial_analog_out_v2->tfp = NULL;
    return result;
}

int tf_industrial_analog_out_v2_get_response_expected(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_ENABLED:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_analog_out_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_VOLTAGE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_analog_out_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_CURRENT:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_analog_out_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_analog_out_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_OUT_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_analog_out_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_OUT_LED_STATUS_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_analog_out_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_analog_out_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_analog_out_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_analog_out_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_analog_out_v2->response_expected[1] & (1 << 1)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_industrial_analog_out_v2_set_response_expected(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_ENABLED:
            if (response_expected) {
                industrial_analog_out_v2->response_expected[0] |= (1 << 0);
            } else {
                industrial_analog_out_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_VOLTAGE:
            if (response_expected) {
                industrial_analog_out_v2->response_expected[0] |= (1 << 1);
            } else {
                industrial_analog_out_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_CURRENT:
            if (response_expected) {
                industrial_analog_out_v2->response_expected[0] |= (1 << 2);
            } else {
                industrial_analog_out_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_CONFIGURATION:
            if (response_expected) {
                industrial_analog_out_v2->response_expected[0] |= (1 << 3);
            } else {
                industrial_analog_out_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_OUT_LED_CONFIG:
            if (response_expected) {
                industrial_analog_out_v2->response_expected[0] |= (1 << 4);
            } else {
                industrial_analog_out_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_OUT_LED_STATUS_CONFIG:
            if (response_expected) {
                industrial_analog_out_v2->response_expected[0] |= (1 << 5);
            } else {
                industrial_analog_out_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                industrial_analog_out_v2->response_expected[0] |= (1 << 6);
            } else {
                industrial_analog_out_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                industrial_analog_out_v2->response_expected[0] |= (1 << 7);
            } else {
                industrial_analog_out_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_RESET:
            if (response_expected) {
                industrial_analog_out_v2->response_expected[1] |= (1 << 0);
            } else {
                industrial_analog_out_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                industrial_analog_out_v2->response_expected[1] |= (1 << 1);
            } else {
                industrial_analog_out_v2->response_expected[1] &= ~(1 << 1);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_industrial_analog_out_v2_set_response_expected_all(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, bool response_expected) {
    memset(industrial_analog_out_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_industrial_analog_out_v2_set_enabled(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, bool enabled) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_analog_out_v2_get_response_expected(industrial_analog_out_v2, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_ENABLED, &response_expected);
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_ENABLED, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_analog_out_v2->tfp);

    buf[0] = enabled ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_get_enabled(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, bool *ret_enabled) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_GET_ENABLED, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { *ret_enabled = tf_packetbuffer_read_bool(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_set_voltage(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint16_t voltage) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_analog_out_v2_get_response_expected(industrial_analog_out_v2, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_VOLTAGE, &response_expected);
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_VOLTAGE, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_analog_out_v2->tfp);

    voltage = tf_leconvert_uint16_to(voltage); memcpy(buf + 0, &voltage, 2);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_get_voltage(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint16_t *ret_voltage) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_GET_VOLTAGE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_voltage != NULL) { *ret_voltage = tf_packetbuffer_read_uint16_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_set_current(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint16_t current) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_analog_out_v2_get_response_expected(industrial_analog_out_v2, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_CURRENT, &response_expected);
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_CURRENT, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_analog_out_v2->tfp);

    current = tf_leconvert_uint16_to(current); memcpy(buf + 0, &current, 2);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_get_current(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint16_t *ret_current) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_GET_CURRENT, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_current != NULL) { *ret_current = tf_packetbuffer_read_uint16_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_set_configuration(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint8_t voltage_range, uint8_t current_range) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_analog_out_v2_get_response_expected(industrial_analog_out_v2, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_CONFIGURATION, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_analog_out_v2->tfp);

    buf[0] = (uint8_t)voltage_range;
    buf[1] = (uint8_t)current_range;

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_get_configuration(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint8_t *ret_voltage_range, uint8_t *ret_current_range) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_GET_CONFIGURATION, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_voltage_range != NULL) { *ret_voltage_range = tf_packetbuffer_read_uint8_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_current_range != NULL) { *ret_current_range = tf_packetbuffer_read_uint8_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_set_out_led_config(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint8_t config) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_analog_out_v2_get_response_expected(industrial_analog_out_v2, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_OUT_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_OUT_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_analog_out_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_get_out_led_config(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_GET_OUT_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_set_out_led_status_config(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint16_t min, uint16_t max, uint8_t config) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_analog_out_v2_get_response_expected(industrial_analog_out_v2, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_OUT_LED_STATUS_CONFIG, &response_expected);
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_OUT_LED_STATUS_CONFIG, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_analog_out_v2->tfp);

    min = tf_leconvert_uint16_to(min); memcpy(buf + 0, &min, 2);
    max = tf_leconvert_uint16_to(max); memcpy(buf + 2, &max, 2);
    buf[4] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_get_out_led_status_config(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint16_t *ret_min, uint16_t *ret_max, uint8_t *ret_config) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_GET_OUT_LED_STATUS_CONFIG, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_min != NULL) { *ret_min = tf_packetbuffer_read_uint16_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_max != NULL) { *ret_max = tf_packetbuffer_read_uint16_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_get_spitfp_error_count(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_set_bootloader_mode(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_analog_out_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_get_bootloader_mode(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_set_write_firmware_pointer(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint32_t pointer) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_analog_out_v2_get_response_expected(industrial_analog_out_v2, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_analog_out_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_write_firmware(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_analog_out_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_set_status_led_config(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint8_t config) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_analog_out_v2_get_response_expected(industrial_analog_out_v2, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_analog_out_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_get_status_led_config(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_get_chip_temperature(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_reset(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_analog_out_v2_get_response_expected(industrial_analog_out_v2, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_write_uid(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint32_t uid) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_analog_out_v2_get_response_expected(industrial_analog_out_v2, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_analog_out_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_read_uid(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_analog_out_v2_get_identity(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_analog_out_v2->tfp, TF_INDUSTRIAL_ANALOG_OUT_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + tf_hal_get_common(industrial_analog_out_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_analog_out_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&industrial_analog_out_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&industrial_analog_out_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&industrial_analog_out_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_analog_out_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(industrial_analog_out_v2->tfp->hal, industrial_analog_out_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(industrial_analog_out_v2->tfp);
    }

    result = tf_tfp_finish_send(industrial_analog_out_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}


int tf_industrial_analog_out_v2_callback_tick(TF_IndustrialAnalogOutV2 *industrial_analog_out_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(industrial_analog_out_v2->tfp, tf_hal_current_time_us(industrial_analog_out_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
