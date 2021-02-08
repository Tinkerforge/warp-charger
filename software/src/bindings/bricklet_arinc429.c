/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_arinc429.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_arinc429_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_ARINC429 *arinc429 = (TF_ARINC429 *) dev;
    (void)payload;

    switch(fid) {

        case TF_ARINC429_CALLBACK_HEARTBEAT: {
            TF_ARINC429HeartbeatHandler fn = arinc429->heartbeat_handler;
            void *user_data = arinc429->heartbeat_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            uint8_t seq_number = tf_packetbuffer_read_uint8_t(payload);
            uint16_t timestamp = tf_packetbuffer_read_uint16_t(payload);
            uint16_t frames_processed[3]; for (i = 0; i < 3; ++i) frames_processed[i] = tf_packetbuffer_read_uint16_t(payload);
            uint16_t frames_lost[3]; for (i = 0; i < 3; ++i) frames_lost[i] = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(arinc429->tfp->hal);
            common->locked = true;
            fn(arinc429, seq_number, timestamp, frames_processed, frames_lost, user_data);
            common->locked = false;
            break;
        }

        case TF_ARINC429_CALLBACK_FRAME_MESSAGE: {
            TF_ARINC429FrameMessageHandler fn = arinc429->frame_message_handler;
            void *user_data = arinc429->frame_message_user_data;
            if (fn == NULL)
                return false;

            uint8_t channel = tf_packetbuffer_read_uint8_t(payload);
            uint8_t seq_number = tf_packetbuffer_read_uint8_t(payload);
            uint16_t timestamp = tf_packetbuffer_read_uint16_t(payload);
            uint8_t frame_status = tf_packetbuffer_read_uint8_t(payload);
            uint32_t frame = tf_packetbuffer_read_uint32_t(payload);
            uint16_t age = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(arinc429->tfp->hal);
            common->locked = true;
            fn(arinc429, channel, seq_number, timestamp, frame_status, frame, age, user_data);
            common->locked = false;
            break;
        }

        case TF_ARINC429_CALLBACK_SCHEDULER_MESSAGE: {
            TF_ARINC429SchedulerMessageHandler fn = arinc429->scheduler_message_handler;
            void *user_data = arinc429->scheduler_message_user_data;
            if (fn == NULL)
                return false;

            uint8_t channel = tf_packetbuffer_read_uint8_t(payload);
            uint8_t seq_number = tf_packetbuffer_read_uint8_t(payload);
            uint16_t timestamp = tf_packetbuffer_read_uint16_t(payload);
            uint8_t token = tf_packetbuffer_read_uint8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(arinc429->tfp->hal);
            common->locked = true;
            fn(arinc429, channel, seq_number, timestamp, token, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_arinc429_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_arinc429_create(TF_ARINC429 *arinc429, const char *uid, TF_HalContext *hal) {
    memset(arinc429, 0, sizeof(TF_ARINC429));

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

    //rc = tf_tfp_init(arinc429->tfp, numeric_uid, TF_ARINC429_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_arinc429_callback_handler);
    rc = tf_hal_get_tfp(hal, &arinc429->tfp, TF_ARINC429_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    arinc429->tfp->device = arinc429;
    arinc429->tfp->uid = numeric_uid;
    arinc429->tfp->cb_handler = tf_arinc429_callback_handler;
    arinc429->response_expected[0] = 0x21;
    arinc429->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_arinc429_destroy(TF_ARINC429 *arinc429) {
    int result = tf_tfp_destroy(arinc429->tfp);
    arinc429->tfp = NULL;
    return result;
}

int tf_arinc429_get_response_expected(TF_ARINC429 *arinc429, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_ARINC429_FUNCTION_SET_HEARTBEAT_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_ARINC429_FUNCTION_SET_CHANNEL_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_ARINC429_FUNCTION_SET_CHANNEL_MODE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_ARINC429_FUNCTION_CLEAR_ALL_RX_FILTERS:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_ARINC429_FUNCTION_SET_RX_STANDARD_FILTERS:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_ARINC429_FUNCTION_SET_RX_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_ARINC429_FUNCTION_WRITE_FRAME_DIRECT:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_ARINC429_FUNCTION_WRITE_FRAME_SCHEDULED:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_ARINC429_FUNCTION_CLEAR_SCHEDULE_ENTRIES:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_ARINC429_FUNCTION_SET_SCHEDULE_ENTRY:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[1] & (1 << 1)) != 0;
            break;
        case TF_ARINC429_FUNCTION_RESTART:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[1] & (1 << 2)) != 0;
            break;
        case TF_ARINC429_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[1] & (1 << 3)) != 0;
            break;
        case TF_ARINC429_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[1] & (1 << 4)) != 0;
            break;
        case TF_ARINC429_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[1] & (1 << 5)) != 0;
            break;
        case TF_ARINC429_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (arinc429->response_expected[1] & (1 << 6)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_arinc429_set_response_expected(TF_ARINC429 *arinc429, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_ARINC429_FUNCTION_SET_HEARTBEAT_CALLBACK_CONFIGURATION:
            if (response_expected) {
                arinc429->response_expected[0] |= (1 << 0);
            } else {
                arinc429->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_ARINC429_FUNCTION_SET_CHANNEL_CONFIGURATION:
            if (response_expected) {
                arinc429->response_expected[0] |= (1 << 1);
            } else {
                arinc429->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_ARINC429_FUNCTION_SET_CHANNEL_MODE:
            if (response_expected) {
                arinc429->response_expected[0] |= (1 << 2);
            } else {
                arinc429->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_ARINC429_FUNCTION_CLEAR_ALL_RX_FILTERS:
            if (response_expected) {
                arinc429->response_expected[0] |= (1 << 3);
            } else {
                arinc429->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_ARINC429_FUNCTION_SET_RX_STANDARD_FILTERS:
            if (response_expected) {
                arinc429->response_expected[0] |= (1 << 4);
            } else {
                arinc429->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_ARINC429_FUNCTION_SET_RX_CALLBACK_CONFIGURATION:
            if (response_expected) {
                arinc429->response_expected[0] |= (1 << 5);
            } else {
                arinc429->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_ARINC429_FUNCTION_WRITE_FRAME_DIRECT:
            if (response_expected) {
                arinc429->response_expected[0] |= (1 << 6);
            } else {
                arinc429->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_ARINC429_FUNCTION_WRITE_FRAME_SCHEDULED:
            if (response_expected) {
                arinc429->response_expected[0] |= (1 << 7);
            } else {
                arinc429->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_ARINC429_FUNCTION_CLEAR_SCHEDULE_ENTRIES:
            if (response_expected) {
                arinc429->response_expected[1] |= (1 << 0);
            } else {
                arinc429->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_ARINC429_FUNCTION_SET_SCHEDULE_ENTRY:
            if (response_expected) {
                arinc429->response_expected[1] |= (1 << 1);
            } else {
                arinc429->response_expected[1] &= ~(1 << 1);
            }
            break;
        case TF_ARINC429_FUNCTION_RESTART:
            if (response_expected) {
                arinc429->response_expected[1] |= (1 << 2);
            } else {
                arinc429->response_expected[1] &= ~(1 << 2);
            }
            break;
        case TF_ARINC429_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                arinc429->response_expected[1] |= (1 << 3);
            } else {
                arinc429->response_expected[1] &= ~(1 << 3);
            }
            break;
        case TF_ARINC429_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                arinc429->response_expected[1] |= (1 << 4);
            } else {
                arinc429->response_expected[1] &= ~(1 << 4);
            }
            break;
        case TF_ARINC429_FUNCTION_RESET:
            if (response_expected) {
                arinc429->response_expected[1] |= (1 << 5);
            } else {
                arinc429->response_expected[1] &= ~(1 << 5);
            }
            break;
        case TF_ARINC429_FUNCTION_WRITE_UID:
            if (response_expected) {
                arinc429->response_expected[1] |= (1 << 6);
            } else {
                arinc429->response_expected[1] &= ~(1 << 6);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_arinc429_set_response_expected_all(TF_ARINC429 *arinc429, bool response_expected) {
    memset(arinc429->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_arinc429_get_capabilities(TF_ARINC429 *arinc429, uint16_t *ret_tx_total_scheduler_jobs, uint16_t *ret_tx_used_scheduler_jobs, uint16_t *ret_rx_total_frame_filters, uint16_t ret_rx_used_frame_filters[2]) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_GET_CAPABILITIES, 0, 10, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_tx_total_scheduler_jobs != NULL) { *ret_tx_total_scheduler_jobs = tf_packetbuffer_read_uint16_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 2); }
        if (ret_tx_used_scheduler_jobs != NULL) { *ret_tx_used_scheduler_jobs = tf_packetbuffer_read_uint16_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 2); }
        if (ret_rx_total_frame_filters != NULL) { *ret_rx_total_frame_filters = tf_packetbuffer_read_uint16_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 2); }
        if (ret_rx_used_frame_filters != NULL) { for (i = 0; i < 2; ++i) ret_rx_used_frame_filters[i] = tf_packetbuffer_read_uint16_t(&arinc429->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_set_heartbeat_callback_configuration(TF_ARINC429 *arinc429, uint8_t period, bool value_has_to_change) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_SET_HEARTBEAT_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_SET_HEARTBEAT_CALLBACK_CONFIGURATION, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)period;
    buf[1] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_get_heartbeat_callback_configuration(TF_ARINC429 *arinc429, uint8_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_GET_HEARTBEAT_CALLBACK_CONFIGURATION, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint8_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_set_channel_configuration(TF_ARINC429 *arinc429, uint8_t channel, uint8_t parity, uint8_t speed) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_SET_CHANNEL_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_SET_CHANNEL_CONFIGURATION, 3, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = (uint8_t)parity;
    buf[2] = (uint8_t)speed;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_get_channel_configuration(TF_ARINC429 *arinc429, uint8_t channel, uint8_t *ret_parity, uint8_t *ret_speed) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_GET_CHANNEL_CONFIGURATION, 1, 2, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_parity != NULL) { *ret_parity = tf_packetbuffer_read_uint8_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        if (ret_speed != NULL) { *ret_speed = tf_packetbuffer_read_uint8_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_set_channel_mode(TF_ARINC429 *arinc429, uint8_t channel, uint8_t mode) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_SET_CHANNEL_MODE, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_SET_CHANNEL_MODE, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_get_channel_mode(TF_ARINC429 *arinc429, uint8_t channel, uint8_t *ret_mode) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_GET_CHANNEL_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_clear_all_rx_filters(TF_ARINC429 *arinc429, uint8_t channel) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_CLEAR_ALL_RX_FILTERS, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_CLEAR_ALL_RX_FILTERS, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_clear_rx_filter(TF_ARINC429 *arinc429, uint8_t channel, uint8_t label, uint8_t sdi, bool *ret_success) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_CLEAR_RX_FILTER, 3, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = (uint8_t)label;
    buf[2] = (uint8_t)sdi;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_success != NULL) { *ret_success = tf_packetbuffer_read_bool(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_set_rx_standard_filters(TF_ARINC429 *arinc429, uint8_t channel) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_SET_RX_STANDARD_FILTERS, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_SET_RX_STANDARD_FILTERS, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_set_rx_filter(TF_ARINC429 *arinc429, uint8_t channel, uint8_t label, uint8_t sdi, bool *ret_success) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_SET_RX_FILTER, 3, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = (uint8_t)label;
    buf[2] = (uint8_t)sdi;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_success != NULL) { *ret_success = tf_packetbuffer_read_bool(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_get_rx_filter(TF_ARINC429 *arinc429, uint8_t channel, uint8_t label, uint8_t sdi, bool *ret_configured) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_GET_RX_FILTER, 3, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = (uint8_t)label;
    buf[2] = (uint8_t)sdi;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_configured != NULL) { *ret_configured = tf_packetbuffer_read_bool(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_read_frame(TF_ARINC429 *arinc429, uint8_t channel, uint8_t label, uint8_t sdi, bool *ret_status, uint32_t *ret_frame, uint16_t *ret_age) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_READ_FRAME, 3, 7, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = (uint8_t)label;
    buf[2] = (uint8_t)sdi;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_bool(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        if (ret_frame != NULL) { *ret_frame = tf_packetbuffer_read_uint32_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 4); }
        if (ret_age != NULL) { *ret_age = tf_packetbuffer_read_uint16_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_set_rx_callback_configuration(TF_ARINC429 *arinc429, uint8_t channel, bool enabled, bool value_has_to_change, uint16_t timeout) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_SET_RX_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_SET_RX_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = enabled ? 1 : 0;
    buf[2] = value_has_to_change ? 1 : 0;
    timeout = tf_leconvert_uint16_to(timeout); memcpy(buf + 3, &timeout, 2);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_get_rx_callback_configuration(TF_ARINC429 *arinc429, uint8_t channel, bool *ret_enabled, bool *ret_value_has_to_change, uint16_t *ret_timeout) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_GET_RX_CALLBACK_CONFIGURATION, 1, 4, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { *ret_enabled = tf_packetbuffer_read_bool(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        if (ret_timeout != NULL) { *ret_timeout = tf_packetbuffer_read_uint16_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_write_frame_direct(TF_ARINC429 *arinc429, uint8_t channel, uint32_t frame) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_WRITE_FRAME_DIRECT, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_WRITE_FRAME_DIRECT, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;
    frame = tf_leconvert_uint32_to(frame); memcpy(buf + 1, &frame, 4);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_write_frame_scheduled(TF_ARINC429 *arinc429, uint8_t channel, uint16_t frame_index, uint32_t frame) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_WRITE_FRAME_SCHEDULED, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_WRITE_FRAME_SCHEDULED, 7, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;
    frame_index = tf_leconvert_uint16_to(frame_index); memcpy(buf + 1, &frame_index, 2);
    frame = tf_leconvert_uint32_to(frame); memcpy(buf + 3, &frame, 4);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_clear_schedule_entries(TF_ARINC429 *arinc429, uint8_t channel, uint16_t job_index_first, uint16_t job_index_last) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_CLEAR_SCHEDULE_ENTRIES, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_CLEAR_SCHEDULE_ENTRIES, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;
    job_index_first = tf_leconvert_uint16_to(job_index_first); memcpy(buf + 1, &job_index_first, 2);
    job_index_last = tf_leconvert_uint16_to(job_index_last); memcpy(buf + 3, &job_index_last, 2);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_set_schedule_entry(TF_ARINC429 *arinc429, uint8_t channel, uint16_t job_index, uint8_t job, uint16_t frame_index, uint8_t dwell_time) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_SET_SCHEDULE_ENTRY, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_SET_SCHEDULE_ENTRY, 7, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;
    job_index = tf_leconvert_uint16_to(job_index); memcpy(buf + 1, &job_index, 2);
    buf[3] = (uint8_t)job;
    frame_index = tf_leconvert_uint16_to(frame_index); memcpy(buf + 4, &frame_index, 2);
    buf[6] = (uint8_t)dwell_time;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_get_schedule_entry(TF_ARINC429 *arinc429, uint8_t channel, uint16_t job_index, uint8_t *ret_job, uint16_t *ret_frame_index, uint32_t *ret_frame, uint8_t *ret_dwell_time) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_GET_SCHEDULE_ENTRY, 3, 8, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)channel;
    job_index = tf_leconvert_uint16_to(job_index); memcpy(buf + 1, &job_index, 2);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_job != NULL) { *ret_job = tf_packetbuffer_read_uint8_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        if (ret_frame_index != NULL) { *ret_frame_index = tf_packetbuffer_read_uint16_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 2); }
        if (ret_frame != NULL) { *ret_frame = tf_packetbuffer_read_uint32_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 4); }
        if (ret_dwell_time != NULL) { *ret_dwell_time = tf_packetbuffer_read_uint8_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_restart(TF_ARINC429 *arinc429) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_RESTART, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_RESTART, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_get_spitfp_error_count(TF_ARINC429 *arinc429, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_set_bootloader_mode(TF_ARINC429 *arinc429, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_get_bootloader_mode(TF_ARINC429 *arinc429, uint8_t *ret_mode) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_set_write_firmware_pointer(TF_ARINC429 *arinc429, uint32_t pointer) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_write_firmware(TF_ARINC429 *arinc429, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_set_status_led_config(TF_ARINC429 *arinc429, uint8_t config) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_get_status_led_config(TF_ARINC429 *arinc429, uint8_t *ret_config) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_get_chip_temperature(TF_ARINC429 *arinc429, int16_t *ret_temperature) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_reset(TF_ARINC429 *arinc429) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_write_uid(TF_ARINC429 *arinc429, uint32_t uid) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_arinc429_get_response_expected(arinc429, TF_ARINC429_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(arinc429->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_read_uid(TF_ARINC429 *arinc429, uint32_t *ret_uid) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_arinc429_get_identity(TF_ARINC429 *arinc429, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(arinc429->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(arinc429->tfp, TF_ARINC429_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(arinc429->tfp->hal) + tf_hal_get_common(arinc429->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(arinc429->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&arinc429->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&arinc429->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&arinc429->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&arinc429->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&arinc429->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&arinc429->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(arinc429->tfp->hal, arinc429->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(arinc429->tfp);
    }

    result = tf_tfp_finish_send(arinc429->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_arinc429_register_heartbeat_callback(TF_ARINC429 *arinc429, TF_ARINC429HeartbeatHandler handler, void *user_data) {
    if (handler == NULL) {
        arinc429->tfp->needs_callback_tick = false;
        arinc429->tfp->needs_callback_tick |= arinc429->frame_message_handler != NULL;
        arinc429->tfp->needs_callback_tick |= arinc429->scheduler_message_handler != NULL;
    } else {
        arinc429->tfp->needs_callback_tick = true;
    }
    arinc429->heartbeat_handler = handler;
    arinc429->heartbeat_user_data = user_data;
}


void tf_arinc429_register_frame_message_callback(TF_ARINC429 *arinc429, TF_ARINC429FrameMessageHandler handler, void *user_data) {
    if (handler == NULL) {
        arinc429->tfp->needs_callback_tick = false;
        arinc429->tfp->needs_callback_tick |= arinc429->heartbeat_handler != NULL;
        arinc429->tfp->needs_callback_tick |= arinc429->scheduler_message_handler != NULL;
    } else {
        arinc429->tfp->needs_callback_tick = true;
    }
    arinc429->frame_message_handler = handler;
    arinc429->frame_message_user_data = user_data;
}


void tf_arinc429_register_scheduler_message_callback(TF_ARINC429 *arinc429, TF_ARINC429SchedulerMessageHandler handler, void *user_data) {
    if (handler == NULL) {
        arinc429->tfp->needs_callback_tick = false;
        arinc429->tfp->needs_callback_tick |= arinc429->heartbeat_handler != NULL;
        arinc429->tfp->needs_callback_tick |= arinc429->frame_message_handler != NULL;
    } else {
        arinc429->tfp->needs_callback_tick = true;
    }
    arinc429->scheduler_message_handler = handler;
    arinc429->scheduler_message_user_data = user_data;
}
#endif
int tf_arinc429_callback_tick(TF_ARINC429 *arinc429, uint32_t timeout_us) {
    return tf_tfp_callback_tick(arinc429->tfp, tf_hal_current_time_us(arinc429->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
