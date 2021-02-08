/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_xmc1400_breakout.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_xmc1400_breakout_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_XMC1400Breakout *xmc1400_breakout = (TF_XMC1400Breakout *) dev;
    (void)payload;

    switch(fid) {

        case TF_XMC1400_BREAKOUT_CALLBACK_ADC_VALUES: {
            TF_XMC1400BreakoutADCValuesHandler fn = xmc1400_breakout->adc_values_handler;
            void *user_data = xmc1400_breakout->adc_values_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            uint16_t values[8]; for (i = 0; i < 8; ++i) values[i] = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(xmc1400_breakout->tfp->hal);
            common->locked = true;
            fn(xmc1400_breakout, values, user_data);
            common->locked = false;
            break;
        }

        case TF_XMC1400_BREAKOUT_CALLBACK_COUNT: {
            TF_XMC1400BreakoutCountHandler fn = xmc1400_breakout->count_handler;
            void *user_data = xmc1400_breakout->count_user_data;
            if (fn == NULL)
                return false;

            uint32_t count = tf_packetbuffer_read_uint32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(xmc1400_breakout->tfp->hal);
            common->locked = true;
            fn(xmc1400_breakout, count, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_xmc1400_breakout_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_xmc1400_breakout_create(TF_XMC1400Breakout *xmc1400_breakout, const char *uid, TF_HalContext *hal) {
    memset(xmc1400_breakout, 0, sizeof(TF_XMC1400Breakout));

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

    //rc = tf_tfp_init(xmc1400_breakout->tfp, numeric_uid, TF_XMC1400_BREAKOUT_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_xmc1400_breakout_callback_handler);
    rc = tf_hal_get_tfp(hal, &xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    xmc1400_breakout->tfp->device = xmc1400_breakout;
    xmc1400_breakout->tfp->uid = numeric_uid;
    xmc1400_breakout->tfp->cb_handler = tf_xmc1400_breakout_callback_handler;
    xmc1400_breakout->response_expected[0] = 0x0C;
    return TF_E_OK;
}

int tf_xmc1400_breakout_destroy(TF_XMC1400Breakout *xmc1400_breakout) {
    int result = tf_tfp_destroy(xmc1400_breakout->tfp);
    xmc1400_breakout->tfp = NULL;
    return result;
}

int tf_xmc1400_breakout_get_response_expected(TF_XMC1400Breakout *xmc1400_breakout, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_XMC1400_BREAKOUT_FUNCTION_SET_GPIO_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (xmc1400_breakout->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_SET_ADC_CHANNEL_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (xmc1400_breakout->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_SET_ADC_VALUES_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (xmc1400_breakout->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_SET_COUNT_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (xmc1400_breakout->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (xmc1400_breakout->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (xmc1400_breakout->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (xmc1400_breakout->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (xmc1400_breakout->response_expected[0] & (1 << 7)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_xmc1400_breakout_set_response_expected(TF_XMC1400Breakout *xmc1400_breakout, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_XMC1400_BREAKOUT_FUNCTION_SET_GPIO_CONFIG:
            if (response_expected) {
                xmc1400_breakout->response_expected[0] |= (1 << 0);
            } else {
                xmc1400_breakout->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_SET_ADC_CHANNEL_CONFIG:
            if (response_expected) {
                xmc1400_breakout->response_expected[0] |= (1 << 1);
            } else {
                xmc1400_breakout->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_SET_ADC_VALUES_CALLBACK_CONFIGURATION:
            if (response_expected) {
                xmc1400_breakout->response_expected[0] |= (1 << 2);
            } else {
                xmc1400_breakout->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_SET_COUNT_CALLBACK_CONFIGURATION:
            if (response_expected) {
                xmc1400_breakout->response_expected[0] |= (1 << 3);
            } else {
                xmc1400_breakout->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                xmc1400_breakout->response_expected[0] |= (1 << 4);
            } else {
                xmc1400_breakout->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                xmc1400_breakout->response_expected[0] |= (1 << 5);
            } else {
                xmc1400_breakout->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_RESET:
            if (response_expected) {
                xmc1400_breakout->response_expected[0] |= (1 << 6);
            } else {
                xmc1400_breakout->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_XMC1400_BREAKOUT_FUNCTION_WRITE_UID:
            if (response_expected) {
                xmc1400_breakout->response_expected[0] |= (1 << 7);
            } else {
                xmc1400_breakout->response_expected[0] &= ~(1 << 7);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_xmc1400_breakout_set_response_expected_all(TF_XMC1400Breakout *xmc1400_breakout, bool response_expected) {
    memset(xmc1400_breakout->response_expected, response_expected ? 0xFF : 0, 1);
}

int tf_xmc1400_breakout_set_gpio_config(TF_XMC1400Breakout *xmc1400_breakout, uint8_t port, uint8_t pin, uint8_t mode, uint8_t input_hysteresis, bool output_level) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_xmc1400_breakout_get_response_expected(xmc1400_breakout, TF_XMC1400_BREAKOUT_FUNCTION_SET_GPIO_CONFIG, &response_expected);
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_SET_GPIO_CONFIG, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(xmc1400_breakout->tfp);

    buf[0] = (uint8_t)port;
    buf[1] = (uint8_t)pin;
    buf[2] = (uint8_t)mode;
    buf[3] = (uint8_t)input_hysteresis;
    buf[4] = output_level ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_get_gpio_input(TF_XMC1400Breakout *xmc1400_breakout, uint8_t port, uint8_t pin, bool *ret_value) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_GET_GPIO_INPUT, 2, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(xmc1400_breakout->tfp);

    buf[0] = (uint8_t)port;
    buf[1] = (uint8_t)pin;

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_value != NULL) { *ret_value = tf_packetbuffer_read_bool(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_set_adc_channel_config(TF_XMC1400Breakout *xmc1400_breakout, uint8_t channel, bool enable) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_xmc1400_breakout_get_response_expected(xmc1400_breakout, TF_XMC1400_BREAKOUT_FUNCTION_SET_ADC_CHANNEL_CONFIG, &response_expected);
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_SET_ADC_CHANNEL_CONFIG, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(xmc1400_breakout->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = enable ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_get_adc_channel_config(TF_XMC1400Breakout *xmc1400_breakout, uint8_t channel, bool *ret_enable) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_GET_ADC_CHANNEL_CONFIG, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(xmc1400_breakout->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enable != NULL) { *ret_enable = tf_packetbuffer_read_bool(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_get_adc_channel_value(TF_XMC1400Breakout *xmc1400_breakout, uint8_t channel, uint16_t *ret_value) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_GET_ADC_CHANNEL_VALUE, 1, 2, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(xmc1400_breakout->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_value != NULL) { *ret_value = tf_packetbuffer_read_uint16_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_get_adc_values(TF_XMC1400Breakout *xmc1400_breakout, uint16_t ret_values[8]) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_GET_ADC_VALUES, 0, 16, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_values != NULL) { for (i = 0; i < 8; ++i) ret_values[i] = tf_packetbuffer_read_uint16_t(&xmc1400_breakout->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 16); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_set_adc_values_callback_configuration(TF_XMC1400Breakout *xmc1400_breakout, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_xmc1400_breakout_get_response_expected(xmc1400_breakout, TF_XMC1400_BREAKOUT_FUNCTION_SET_ADC_VALUES_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_SET_ADC_VALUES_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(xmc1400_breakout->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_get_adc_values_callback_configuration(TF_XMC1400Breakout *xmc1400_breakout, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_GET_ADC_VALUES_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_get_count(TF_XMC1400Breakout *xmc1400_breakout, uint32_t *ret_count) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_GET_COUNT, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_count != NULL) { *ret_count = tf_packetbuffer_read_uint32_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_set_count_callback_configuration(TF_XMC1400Breakout *xmc1400_breakout, uint32_t period, bool value_has_to_change, char option, uint32_t min, uint32_t max) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_xmc1400_breakout_get_response_expected(xmc1400_breakout, TF_XMC1400_BREAKOUT_FUNCTION_SET_COUNT_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_SET_COUNT_CALLBACK_CONFIGURATION, 14, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(xmc1400_breakout->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;
    buf[5] = (uint8_t)option;
    min = tf_leconvert_uint32_to(min); memcpy(buf + 6, &min, 4);
    max = tf_leconvert_uint32_to(max); memcpy(buf + 10, &max, 4);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_get_count_callback_configuration(TF_XMC1400Breakout *xmc1400_breakout, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, uint32_t *ret_min, uint32_t *ret_max) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_GET_COUNT_CALLBACK_CONFIGURATION, 0, 14, response_expected);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 1); }
        if (ret_option != NULL) { *ret_option = tf_packetbuffer_read_char(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 1); }
        if (ret_min != NULL) { *ret_min = tf_packetbuffer_read_uint32_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 4); }
        if (ret_max != NULL) { *ret_max = tf_packetbuffer_read_uint32_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_get_spitfp_error_count(TF_XMC1400Breakout *xmc1400_breakout, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_set_bootloader_mode(TF_XMC1400Breakout *xmc1400_breakout, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(xmc1400_breakout->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_get_bootloader_mode(TF_XMC1400Breakout *xmc1400_breakout, uint8_t *ret_mode) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_set_write_firmware_pointer(TF_XMC1400Breakout *xmc1400_breakout, uint32_t pointer) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_xmc1400_breakout_get_response_expected(xmc1400_breakout, TF_XMC1400_BREAKOUT_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(xmc1400_breakout->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_write_firmware(TF_XMC1400Breakout *xmc1400_breakout, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(xmc1400_breakout->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_set_status_led_config(TF_XMC1400Breakout *xmc1400_breakout, uint8_t config) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_xmc1400_breakout_get_response_expected(xmc1400_breakout, TF_XMC1400_BREAKOUT_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(xmc1400_breakout->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_get_status_led_config(TF_XMC1400Breakout *xmc1400_breakout, uint8_t *ret_config) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_get_chip_temperature(TF_XMC1400Breakout *xmc1400_breakout, int16_t *ret_temperature) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_reset(TF_XMC1400Breakout *xmc1400_breakout) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_xmc1400_breakout_get_response_expected(xmc1400_breakout, TF_XMC1400_BREAKOUT_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_write_uid(TF_XMC1400Breakout *xmc1400_breakout, uint32_t uid) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_xmc1400_breakout_get_response_expected(xmc1400_breakout, TF_XMC1400_BREAKOUT_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(xmc1400_breakout->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_read_uid(TF_XMC1400Breakout *xmc1400_breakout, uint32_t *ret_uid) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_xmc1400_breakout_get_identity(TF_XMC1400Breakout *xmc1400_breakout, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(xmc1400_breakout->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(xmc1400_breakout->tfp, TF_XMC1400_BREAKOUT_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + tf_hal_get_common(xmc1400_breakout->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(xmc1400_breakout->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&xmc1400_breakout->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&xmc1400_breakout->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&xmc1400_breakout->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&xmc1400_breakout->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&xmc1400_breakout->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&xmc1400_breakout->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(xmc1400_breakout->tfp->hal, xmc1400_breakout->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(xmc1400_breakout->tfp);
    }

    result = tf_tfp_finish_send(xmc1400_breakout->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_xmc1400_breakout_register_adc_values_callback(TF_XMC1400Breakout *xmc1400_breakout, TF_XMC1400BreakoutADCValuesHandler handler, void *user_data) {
    if (handler == NULL) {
        xmc1400_breakout->tfp->needs_callback_tick = false;
        xmc1400_breakout->tfp->needs_callback_tick |= xmc1400_breakout->count_handler != NULL;
    } else {
        xmc1400_breakout->tfp->needs_callback_tick = true;
    }
    xmc1400_breakout->adc_values_handler = handler;
    xmc1400_breakout->adc_values_user_data = user_data;
}


void tf_xmc1400_breakout_register_count_callback(TF_XMC1400Breakout *xmc1400_breakout, TF_XMC1400BreakoutCountHandler handler, void *user_data) {
    if (handler == NULL) {
        xmc1400_breakout->tfp->needs_callback_tick = false;
        xmc1400_breakout->tfp->needs_callback_tick |= xmc1400_breakout->adc_values_handler != NULL;
    } else {
        xmc1400_breakout->tfp->needs_callback_tick = true;
    }
    xmc1400_breakout->count_handler = handler;
    xmc1400_breakout->count_user_data = user_data;
}
#endif
int tf_xmc1400_breakout_callback_tick(TF_XMC1400Breakout *xmc1400_breakout, uint32_t timeout_us) {
    return tf_tfp_callback_tick(xmc1400_breakout->tfp, tf_hal_current_time_us(xmc1400_breakout->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
