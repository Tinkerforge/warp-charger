/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_industrial_counter.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_industrial_counter_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_IndustrialCounter *industrial_counter = (TF_IndustrialCounter *) dev;
    (void)payload;

    switch(fid) {

        case TF_INDUSTRIAL_COUNTER_CALLBACK_ALL_COUNTER: {
            TF_IndustrialCounterAllCounterHandler fn = industrial_counter->all_counter_handler;
            void *user_data = industrial_counter->all_counter_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            int64_t counter[4]; for (i = 0; i < 4; ++i) counter[i] = tf_packetbuffer_read_int64_t(payload);
            TF_HalCommon *common = tf_hal_get_common(industrial_counter->tfp->hal);
            common->locked = true;
            fn(industrial_counter, counter, user_data);
            common->locked = false;
            break;
        }

        case TF_INDUSTRIAL_COUNTER_CALLBACK_ALL_SIGNAL_DATA: {
            TF_IndustrialCounterAllSignalDataHandler fn = industrial_counter->all_signal_data_handler;
            void *user_data = industrial_counter->all_signal_data_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            uint16_t duty_cycle[4]; for (i = 0; i < 4; ++i) duty_cycle[i] = tf_packetbuffer_read_uint16_t(payload);
            uint64_t period[4]; for (i = 0; i < 4; ++i) period[i] = tf_packetbuffer_read_uint64_t(payload);
            uint32_t frequency[4]; for (i = 0; i < 4; ++i) frequency[i] = tf_packetbuffer_read_uint32_t(payload);
            bool value[4]; tf_packetbuffer_read_bool_array(payload, value, 4);
            TF_HalCommon *common = tf_hal_get_common(industrial_counter->tfp->hal);
            common->locked = true;
            fn(industrial_counter, duty_cycle, period, frequency, value, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_industrial_counter_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_industrial_counter_create(TF_IndustrialCounter *industrial_counter, const char *uid, TF_HalContext *hal) {
    memset(industrial_counter, 0, sizeof(TF_IndustrialCounter));

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

    //rc = tf_tfp_init(industrial_counter->tfp, numeric_uid, TF_INDUSTRIAL_COUNTER_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_industrial_counter_callback_handler);
    rc = tf_hal_get_tfp(hal, &industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    industrial_counter->tfp->device = industrial_counter;
    industrial_counter->tfp->uid = numeric_uid;
    industrial_counter->tfp->cb_handler = tf_industrial_counter_callback_handler;
    industrial_counter->response_expected[0] = 0x60;
    industrial_counter->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_industrial_counter_destroy(TF_IndustrialCounter *industrial_counter) {
    int result = tf_tfp_destroy(industrial_counter->tfp);
    industrial_counter->tfp = NULL;
    return result;
}

int tf_industrial_counter_get_response_expected(TF_IndustrialCounter *industrial_counter, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_COUNTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_counter->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_COUNTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_counter->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_COUNTER_ACTIVE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_counter->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_COUNTER_ACTIVE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_counter->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_COUNTER_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_counter->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_COUNTER_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_counter->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_SIGNAL_DATA_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_counter->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_CHANNEL_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_counter->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_counter->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_counter->response_expected[1] & (1 << 1)) != 0;
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_counter->response_expected[1] & (1 << 2)) != 0;
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_counter->response_expected[1] & (1 << 3)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_industrial_counter_set_response_expected(TF_IndustrialCounter *industrial_counter, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_COUNTER:
            if (response_expected) {
                industrial_counter->response_expected[0] |= (1 << 0);
            } else {
                industrial_counter->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_COUNTER:
            if (response_expected) {
                industrial_counter->response_expected[0] |= (1 << 1);
            } else {
                industrial_counter->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_COUNTER_ACTIVE:
            if (response_expected) {
                industrial_counter->response_expected[0] |= (1 << 2);
            } else {
                industrial_counter->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_COUNTER_ACTIVE:
            if (response_expected) {
                industrial_counter->response_expected[0] |= (1 << 3);
            } else {
                industrial_counter->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_COUNTER_CONFIGURATION:
            if (response_expected) {
                industrial_counter->response_expected[0] |= (1 << 4);
            } else {
                industrial_counter->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_COUNTER_CALLBACK_CONFIGURATION:
            if (response_expected) {
                industrial_counter->response_expected[0] |= (1 << 5);
            } else {
                industrial_counter->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_SIGNAL_DATA_CALLBACK_CONFIGURATION:
            if (response_expected) {
                industrial_counter->response_expected[0] |= (1 << 6);
            } else {
                industrial_counter->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_CHANNEL_LED_CONFIG:
            if (response_expected) {
                industrial_counter->response_expected[0] |= (1 << 7);
            } else {
                industrial_counter->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                industrial_counter->response_expected[1] |= (1 << 0);
            } else {
                industrial_counter->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                industrial_counter->response_expected[1] |= (1 << 1);
            } else {
                industrial_counter->response_expected[1] &= ~(1 << 1);
            }
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_RESET:
            if (response_expected) {
                industrial_counter->response_expected[1] |= (1 << 2);
            } else {
                industrial_counter->response_expected[1] &= ~(1 << 2);
            }
            break;
        case TF_INDUSTRIAL_COUNTER_FUNCTION_WRITE_UID:
            if (response_expected) {
                industrial_counter->response_expected[1] |= (1 << 3);
            } else {
                industrial_counter->response_expected[1] &= ~(1 << 3);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_industrial_counter_set_response_expected_all(TF_IndustrialCounter *industrial_counter, bool response_expected) {
    memset(industrial_counter->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_industrial_counter_get_counter(TF_IndustrialCounter *industrial_counter, uint8_t channel, int64_t *ret_counter) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_COUNTER, 1, 8, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_counter != NULL) { *ret_counter = tf_packetbuffer_read_int64_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 8); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_all_counter(TF_IndustrialCounter *industrial_counter, int64_t ret_counter[4]) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_ALL_COUNTER, 0, 32, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_counter != NULL) { for (i = 0; i < 4; ++i) ret_counter[i] = tf_packetbuffer_read_int64_t(&industrial_counter->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 32); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_set_counter(TF_IndustrialCounter *industrial_counter, uint8_t channel, int64_t counter) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_counter_get_response_expected(industrial_counter, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_COUNTER, &response_expected);
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_COUNTER, 9, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    buf[0] = (uint8_t)channel;
    counter = tf_leconvert_int64_to(counter); memcpy(buf + 1, &counter, 8);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_set_all_counter(TF_IndustrialCounter *industrial_counter, int64_t counter[4]) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_counter_get_response_expected(industrial_counter, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_COUNTER, &response_expected);
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_COUNTER, 32, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    for (i = 0; i < 4; i++) { int64_t tmp_counter = tf_leconvert_int64_to(counter[i]); memcpy(buf + 0 + (i * sizeof(int64_t)), &tmp_counter, sizeof(int64_t)); }

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_signal_data(TF_IndustrialCounter *industrial_counter, uint8_t channel, uint16_t *ret_duty_cycle, uint64_t *ret_period, uint32_t *ret_frequency, bool *ret_value) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_SIGNAL_DATA, 1, 15, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_duty_cycle != NULL) { *ret_duty_cycle = tf_packetbuffer_read_uint16_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 2); }
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint64_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 8); }
        if (ret_frequency != NULL) { *ret_frequency = tf_packetbuffer_read_uint32_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 4); }
        if (ret_value != NULL) { *ret_value = tf_packetbuffer_read_bool(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_all_signal_data(TF_IndustrialCounter *industrial_counter, uint16_t ret_duty_cycle[4], uint64_t ret_period[4], uint32_t ret_frequency[4], bool ret_value[4]) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_ALL_SIGNAL_DATA, 0, 57, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_duty_cycle != NULL) { for (i = 0; i < 4; ++i) ret_duty_cycle[i] = tf_packetbuffer_read_uint16_t(&industrial_counter->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 8); }
        if (ret_period != NULL) { for (i = 0; i < 4; ++i) ret_period[i] = tf_packetbuffer_read_uint64_t(&industrial_counter->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 32); }
        if (ret_frequency != NULL) { for (i = 0; i < 4; ++i) ret_frequency[i] = tf_packetbuffer_read_uint32_t(&industrial_counter->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 16); }
        if (ret_value != NULL) { tf_packetbuffer_read_bool_array(&industrial_counter->tfp->spitfp->recv_buf, ret_value, 4);} else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_set_counter_active(TF_IndustrialCounter *industrial_counter, uint8_t channel, bool active) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_counter_get_response_expected(industrial_counter, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_COUNTER_ACTIVE, &response_expected);
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_COUNTER_ACTIVE, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = active ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_set_all_counter_active(TF_IndustrialCounter *industrial_counter, bool active[4]) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_counter_get_response_expected(industrial_counter, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_COUNTER_ACTIVE, &response_expected);
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_COUNTER_ACTIVE, 1, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    memset(buf + 0, 0, 1); for (i = 0; i < 4; ++i) buf[0 + (i / 8)] |= (active[i] ? 1 : 0) << (i % 8);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_counter_active(TF_IndustrialCounter *industrial_counter, uint8_t channel, bool *ret_active) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_COUNTER_ACTIVE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_active != NULL) { *ret_active = tf_packetbuffer_read_bool(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_all_counter_active(TF_IndustrialCounter *industrial_counter, bool ret_active[4]) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_ALL_COUNTER_ACTIVE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_active != NULL) { tf_packetbuffer_read_bool_array(&industrial_counter->tfp->spitfp->recv_buf, ret_active, 4);} else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_set_counter_configuration(TF_IndustrialCounter *industrial_counter, uint8_t channel, uint8_t count_edge, uint8_t count_direction, uint8_t duty_cycle_prescaler, uint8_t frequency_integration_time) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_counter_get_response_expected(industrial_counter, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_COUNTER_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_COUNTER_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = (uint8_t)count_edge;
    buf[2] = (uint8_t)count_direction;
    buf[3] = (uint8_t)duty_cycle_prescaler;
    buf[4] = (uint8_t)frequency_integration_time;

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_counter_configuration(TF_IndustrialCounter *industrial_counter, uint8_t channel, uint8_t *ret_count_edge, uint8_t *ret_count_direction, uint8_t *ret_duty_cycle_prescaler, uint8_t *ret_frequency_integration_time) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_COUNTER_CONFIGURATION, 1, 4, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_count_edge != NULL) { *ret_count_edge = tf_packetbuffer_read_uint8_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        if (ret_count_direction != NULL) { *ret_count_direction = tf_packetbuffer_read_uint8_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        if (ret_duty_cycle_prescaler != NULL) { *ret_duty_cycle_prescaler = tf_packetbuffer_read_uint8_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        if (ret_frequency_integration_time != NULL) { *ret_frequency_integration_time = tf_packetbuffer_read_uint8_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_set_all_counter_callback_configuration(TF_IndustrialCounter *industrial_counter, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_counter_get_response_expected(industrial_counter, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_COUNTER_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_COUNTER_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_all_counter_callback_configuration(TF_IndustrialCounter *industrial_counter, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_ALL_COUNTER_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_set_all_signal_data_callback_configuration(TF_IndustrialCounter *industrial_counter, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_counter_get_response_expected(industrial_counter, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_SIGNAL_DATA_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_ALL_SIGNAL_DATA_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_all_signal_data_callback_configuration(TF_IndustrialCounter *industrial_counter, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_ALL_SIGNAL_DATA_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_set_channel_led_config(TF_IndustrialCounter *industrial_counter, uint8_t channel, uint8_t config) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_counter_get_response_expected(industrial_counter, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_CHANNEL_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_CHANNEL_LED_CONFIG, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_channel_led_config(TF_IndustrialCounter *industrial_counter, uint8_t channel, uint8_t *ret_config) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_CHANNEL_LED_CONFIG, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_spitfp_error_count(TF_IndustrialCounter *industrial_counter, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_set_bootloader_mode(TF_IndustrialCounter *industrial_counter, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_bootloader_mode(TF_IndustrialCounter *industrial_counter, uint8_t *ret_mode) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_set_write_firmware_pointer(TF_IndustrialCounter *industrial_counter, uint32_t pointer) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_counter_get_response_expected(industrial_counter, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_write_firmware(TF_IndustrialCounter *industrial_counter, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_set_status_led_config(TF_IndustrialCounter *industrial_counter, uint8_t config) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_counter_get_response_expected(industrial_counter, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_status_led_config(TF_IndustrialCounter *industrial_counter, uint8_t *ret_config) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_chip_temperature(TF_IndustrialCounter *industrial_counter, int16_t *ret_temperature) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_reset(TF_IndustrialCounter *industrial_counter) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_counter_get_response_expected(industrial_counter, TF_INDUSTRIAL_COUNTER_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_write_uid(TF_IndustrialCounter *industrial_counter, uint32_t uid) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_counter_get_response_expected(industrial_counter, TF_INDUSTRIAL_COUNTER_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(industrial_counter->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_read_uid(TF_IndustrialCounter *industrial_counter, uint32_t *ret_uid) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_counter_get_identity(TF_IndustrialCounter *industrial_counter, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(industrial_counter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(industrial_counter->tfp, TF_INDUSTRIAL_COUNTER_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(industrial_counter->tfp->hal) + tf_hal_get_common(industrial_counter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(industrial_counter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&industrial_counter->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&industrial_counter->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&industrial_counter->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&industrial_counter->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&industrial_counter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&industrial_counter->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(industrial_counter->tfp->hal, industrial_counter->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(industrial_counter->tfp);
    }

    result = tf_tfp_finish_send(industrial_counter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_industrial_counter_register_all_counter_callback(TF_IndustrialCounter *industrial_counter, TF_IndustrialCounterAllCounterHandler handler, void *user_data) {
    if (handler == NULL) {
        industrial_counter->tfp->needs_callback_tick = false;
        industrial_counter->tfp->needs_callback_tick |= industrial_counter->all_signal_data_handler != NULL;
    } else {
        industrial_counter->tfp->needs_callback_tick = true;
    }
    industrial_counter->all_counter_handler = handler;
    industrial_counter->all_counter_user_data = user_data;
}


void tf_industrial_counter_register_all_signal_data_callback(TF_IndustrialCounter *industrial_counter, TF_IndustrialCounterAllSignalDataHandler handler, void *user_data) {
    if (handler == NULL) {
        industrial_counter->tfp->needs_callback_tick = false;
        industrial_counter->tfp->needs_callback_tick |= industrial_counter->all_counter_handler != NULL;
    } else {
        industrial_counter->tfp->needs_callback_tick = true;
    }
    industrial_counter->all_signal_data_handler = handler;
    industrial_counter->all_signal_data_user_data = user_data;
}
#endif
int tf_industrial_counter_callback_tick(TF_IndustrialCounter *industrial_counter, uint32_t timeout_us) {
    return tf_tfp_callback_tick(industrial_counter->tfp, tf_hal_current_time_us(industrial_counter->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
