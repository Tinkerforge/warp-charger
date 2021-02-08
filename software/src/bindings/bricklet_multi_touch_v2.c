/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_multi_touch_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_multi_touch_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_MultiTouchV2 *multi_touch_v2 = (TF_MultiTouchV2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_MULTI_TOUCH_V2_CALLBACK_TOUCH_STATE: {
            TF_MultiTouchV2TouchStateHandler fn = multi_touch_v2->touch_state_handler;
            void *user_data = multi_touch_v2->touch_state_user_data;
            if (fn == NULL)
                return false;

            bool state[13]; tf_packetbuffer_read_bool_array(payload, state, 13);
            TF_HalCommon *common = tf_hal_get_common(multi_touch_v2->tfp->hal);
            common->locked = true;
            fn(multi_touch_v2, state, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_multi_touch_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_multi_touch_v2_create(TF_MultiTouchV2 *multi_touch_v2, const char *uid, TF_HalContext *hal) {
    memset(multi_touch_v2, 0, sizeof(TF_MultiTouchV2));

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

    //rc = tf_tfp_init(multi_touch_v2->tfp, numeric_uid, TF_MULTI_TOUCH_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_multi_touch_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    multi_touch_v2->tfp->device = multi_touch_v2;
    multi_touch_v2->tfp->uid = numeric_uid;
    multi_touch_v2->tfp->cb_handler = tf_multi_touch_v2_callback_handler;
    multi_touch_v2->response_expected[0] = 0x01;
    multi_touch_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_multi_touch_v2_destroy(TF_MultiTouchV2 *multi_touch_v2) {
    int result = tf_tfp_destroy(multi_touch_v2->tfp);
    multi_touch_v2->tfp = NULL;
    return result;
}

int tf_multi_touch_v2_get_response_expected(TF_MultiTouchV2 *multi_touch_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_MULTI_TOUCH_V2_FUNCTION_SET_TOUCH_STATE_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (multi_touch_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_RECALIBRATE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (multi_touch_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_SET_ELECTRODE_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (multi_touch_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_SET_ELECTRODE_SENSITIVITY:
            if(ret_response_expected != NULL)
                *ret_response_expected = (multi_touch_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_SET_TOUCH_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (multi_touch_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (multi_touch_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (multi_touch_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (multi_touch_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (multi_touch_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_multi_touch_v2_set_response_expected(TF_MultiTouchV2 *multi_touch_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_MULTI_TOUCH_V2_FUNCTION_SET_TOUCH_STATE_CALLBACK_CONFIGURATION:
            if (response_expected) {
                multi_touch_v2->response_expected[0] |= (1 << 0);
            } else {
                multi_touch_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_RECALIBRATE:
            if (response_expected) {
                multi_touch_v2->response_expected[0] |= (1 << 1);
            } else {
                multi_touch_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_SET_ELECTRODE_CONFIG:
            if (response_expected) {
                multi_touch_v2->response_expected[0] |= (1 << 2);
            } else {
                multi_touch_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_SET_ELECTRODE_SENSITIVITY:
            if (response_expected) {
                multi_touch_v2->response_expected[0] |= (1 << 3);
            } else {
                multi_touch_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_SET_TOUCH_LED_CONFIG:
            if (response_expected) {
                multi_touch_v2->response_expected[0] |= (1 << 4);
            } else {
                multi_touch_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                multi_touch_v2->response_expected[0] |= (1 << 5);
            } else {
                multi_touch_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                multi_touch_v2->response_expected[0] |= (1 << 6);
            } else {
                multi_touch_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_RESET:
            if (response_expected) {
                multi_touch_v2->response_expected[0] |= (1 << 7);
            } else {
                multi_touch_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_MULTI_TOUCH_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                multi_touch_v2->response_expected[1] |= (1 << 0);
            } else {
                multi_touch_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_multi_touch_v2_set_response_expected_all(TF_MultiTouchV2 *multi_touch_v2, bool response_expected) {
    memset(multi_touch_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_multi_touch_v2_get_touch_state(TF_MultiTouchV2 *multi_touch_v2, bool ret_state[13]) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_GET_TOUCH_STATE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_state != NULL) { tf_packetbuffer_read_bool_array(&multi_touch_v2->tfp->spitfp->recv_buf, ret_state, 13);} else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_set_touch_state_callback_configuration(TF_MultiTouchV2 *multi_touch_v2, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_multi_touch_v2_get_response_expected(multi_touch_v2, TF_MULTI_TOUCH_V2_FUNCTION_SET_TOUCH_STATE_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_SET_TOUCH_STATE_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(multi_touch_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_get_touch_state_callback_configuration(TF_MultiTouchV2 *multi_touch_v2, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_GET_TOUCH_STATE_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_recalibrate(TF_MultiTouchV2 *multi_touch_v2) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_multi_touch_v2_get_response_expected(multi_touch_v2, TF_MULTI_TOUCH_V2_FUNCTION_RECALIBRATE, &response_expected);
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_RECALIBRATE, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_set_electrode_config(TF_MultiTouchV2 *multi_touch_v2, bool enabled_electrodes[13]) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_multi_touch_v2_get_response_expected(multi_touch_v2, TF_MULTI_TOUCH_V2_FUNCTION_SET_ELECTRODE_CONFIG, &response_expected);
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_SET_ELECTRODE_CONFIG, 2, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(multi_touch_v2->tfp);

    memset(buf + 0, 0, 2); for (i = 0; i < 13; ++i) buf[0 + (i / 8)] |= (enabled_electrodes[i] ? 1 : 0) << (i % 8);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_get_electrode_config(TF_MultiTouchV2 *multi_touch_v2, bool ret_enabled_electrodes[13]) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_GET_ELECTRODE_CONFIG, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled_electrodes != NULL) { tf_packetbuffer_read_bool_array(&multi_touch_v2->tfp->spitfp->recv_buf, ret_enabled_electrodes, 13);} else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_set_electrode_sensitivity(TF_MultiTouchV2 *multi_touch_v2, uint8_t sensitivity) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_multi_touch_v2_get_response_expected(multi_touch_v2, TF_MULTI_TOUCH_V2_FUNCTION_SET_ELECTRODE_SENSITIVITY, &response_expected);
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_SET_ELECTRODE_SENSITIVITY, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(multi_touch_v2->tfp);

    buf[0] = (uint8_t)sensitivity;

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_get_electrode_sensitivity(TF_MultiTouchV2 *multi_touch_v2, uint8_t *ret_sensitivity) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_GET_ELECTRODE_SENSITIVITY, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_sensitivity != NULL) { *ret_sensitivity = tf_packetbuffer_read_uint8_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_set_touch_led_config(TF_MultiTouchV2 *multi_touch_v2, uint8_t config) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_multi_touch_v2_get_response_expected(multi_touch_v2, TF_MULTI_TOUCH_V2_FUNCTION_SET_TOUCH_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_SET_TOUCH_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(multi_touch_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_get_touch_led_config(TF_MultiTouchV2 *multi_touch_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_GET_TOUCH_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_get_spitfp_error_count(TF_MultiTouchV2 *multi_touch_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_set_bootloader_mode(TF_MultiTouchV2 *multi_touch_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(multi_touch_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_get_bootloader_mode(TF_MultiTouchV2 *multi_touch_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_set_write_firmware_pointer(TF_MultiTouchV2 *multi_touch_v2, uint32_t pointer) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_multi_touch_v2_get_response_expected(multi_touch_v2, TF_MULTI_TOUCH_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(multi_touch_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_write_firmware(TF_MultiTouchV2 *multi_touch_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(multi_touch_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_set_status_led_config(TF_MultiTouchV2 *multi_touch_v2, uint8_t config) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_multi_touch_v2_get_response_expected(multi_touch_v2, TF_MULTI_TOUCH_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(multi_touch_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_get_status_led_config(TF_MultiTouchV2 *multi_touch_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_get_chip_temperature(TF_MultiTouchV2 *multi_touch_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_reset(TF_MultiTouchV2 *multi_touch_v2) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_multi_touch_v2_get_response_expected(multi_touch_v2, TF_MULTI_TOUCH_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_write_uid(TF_MultiTouchV2 *multi_touch_v2, uint32_t uid) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_multi_touch_v2_get_response_expected(multi_touch_v2, TF_MULTI_TOUCH_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(multi_touch_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_read_uid(TF_MultiTouchV2 *multi_touch_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_multi_touch_v2_get_identity(TF_MultiTouchV2 *multi_touch_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(multi_touch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(multi_touch_v2->tfp, TF_MULTI_TOUCH_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(multi_touch_v2->tfp->hal) + tf_hal_get_common(multi_touch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(multi_touch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&multi_touch_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&multi_touch_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&multi_touch_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&multi_touch_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&multi_touch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&multi_touch_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(multi_touch_v2->tfp->hal, multi_touch_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(multi_touch_v2->tfp);
    }

    result = tf_tfp_finish_send(multi_touch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_multi_touch_v2_register_touch_state_callback(TF_MultiTouchV2 *multi_touch_v2, TF_MultiTouchV2TouchStateHandler handler, void *user_data) {
    if (handler == NULL) {
        multi_touch_v2->tfp->needs_callback_tick = false;
        
    } else {
        multi_touch_v2->tfp->needs_callback_tick = true;
    }
    multi_touch_v2->touch_state_handler = handler;
    multi_touch_v2->touch_state_user_data = user_data;
}
#endif
int tf_multi_touch_v2_callback_tick(TF_MultiTouchV2 *multi_touch_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(multi_touch_v2->tfp, tf_hal_current_time_us(multi_touch_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
