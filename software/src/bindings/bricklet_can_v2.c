/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_can_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_can_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_CANV2 *can_v2 = (TF_CANV2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_CAN_V2_CALLBACK_FRAME_READ_LOW_LEVEL: {
            TF_CANV2FrameReadLowLevelHandler fn = can_v2->frame_read_low_level_handler;
            void *user_data = can_v2->frame_read_low_level_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            uint8_t frame_type = tf_packetbuffer_read_uint8_t(payload);
            uint32_t identifier = tf_packetbuffer_read_uint32_t(payload);
            uint8_t data_length = tf_packetbuffer_read_uint8_t(payload);
            uint8_t data_data[15]; for (i = 0; i < 15; ++i) data_data[i] = tf_packetbuffer_read_uint8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(can_v2->tfp->hal);
            common->locked = true;
            fn(can_v2, frame_type, identifier, data_length, data_data, user_data);
            common->locked = false;
            break;
        }

        case TF_CAN_V2_CALLBACK_FRAME_READABLE: {
            TF_CANV2FrameReadableHandler fn = can_v2->frame_readable_handler;
            void *user_data = can_v2->frame_readable_user_data;
            if (fn == NULL)
                return false;


            TF_HalCommon *common = tf_hal_get_common(can_v2->tfp->hal);
            common->locked = true;
            fn(can_v2, user_data);
            common->locked = false;
            break;
        }

        case TF_CAN_V2_CALLBACK_ERROR_OCCURRED: {
            TF_CANV2ErrorOccurredHandler fn = can_v2->error_occurred_handler;
            void *user_data = can_v2->error_occurred_user_data;
            if (fn == NULL)
                return false;


            TF_HalCommon *common = tf_hal_get_common(can_v2->tfp->hal);
            common->locked = true;
            fn(can_v2, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_can_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_can_v2_create(TF_CANV2 *can_v2, const char *uid, TF_HalContext *hal) {
    memset(can_v2, 0, sizeof(TF_CANV2));

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

    //rc = tf_tfp_init(can_v2->tfp, numeric_uid, TF_CAN_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_can_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &can_v2->tfp, TF_CAN_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    can_v2->tfp->device = can_v2;
    can_v2->tfp->uid = numeric_uid;
    can_v2->tfp->cb_handler = tf_can_v2_callback_handler;
    can_v2->response_expected[0] = 0xC5;
    can_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_can_v2_destroy(TF_CANV2 *can_v2) {
    int result = tf_tfp_destroy(can_v2->tfp);
    can_v2->tfp = NULL;
    return result;
}

int tf_can_v2_get_response_expected(TF_CANV2 *can_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_CAN_V2_FUNCTION_SET_FRAME_READ_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (can_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_CAN_V2_FUNCTION_SET_TRANSCEIVER_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (can_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_CAN_V2_FUNCTION_SET_QUEUE_CONFIGURATION_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (can_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_CAN_V2_FUNCTION_SET_READ_FILTER_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (can_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_CAN_V2_FUNCTION_SET_COMMUNICATION_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (can_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_CAN_V2_FUNCTION_SET_ERROR_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (can_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_CAN_V2_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (can_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_CAN_V2_FUNCTION_SET_ERROR_OCCURRED_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (can_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_CAN_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (can_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_CAN_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (can_v2->response_expected[1] & (1 << 1)) != 0;
            break;
        case TF_CAN_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (can_v2->response_expected[1] & (1 << 2)) != 0;
            break;
        case TF_CAN_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (can_v2->response_expected[1] & (1 << 3)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_can_v2_set_response_expected(TF_CANV2 *can_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_CAN_V2_FUNCTION_SET_FRAME_READ_CALLBACK_CONFIGURATION:
            if (response_expected) {
                can_v2->response_expected[0] |= (1 << 0);
            } else {
                can_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_CAN_V2_FUNCTION_SET_TRANSCEIVER_CONFIGURATION:
            if (response_expected) {
                can_v2->response_expected[0] |= (1 << 1);
            } else {
                can_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_CAN_V2_FUNCTION_SET_QUEUE_CONFIGURATION_LOW_LEVEL:
            if (response_expected) {
                can_v2->response_expected[0] |= (1 << 2);
            } else {
                can_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_CAN_V2_FUNCTION_SET_READ_FILTER_CONFIGURATION:
            if (response_expected) {
                can_v2->response_expected[0] |= (1 << 3);
            } else {
                can_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_CAN_V2_FUNCTION_SET_COMMUNICATION_LED_CONFIG:
            if (response_expected) {
                can_v2->response_expected[0] |= (1 << 4);
            } else {
                can_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_CAN_V2_FUNCTION_SET_ERROR_LED_CONFIG:
            if (response_expected) {
                can_v2->response_expected[0] |= (1 << 5);
            } else {
                can_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_CAN_V2_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION:
            if (response_expected) {
                can_v2->response_expected[0] |= (1 << 6);
            } else {
                can_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_CAN_V2_FUNCTION_SET_ERROR_OCCURRED_CALLBACK_CONFIGURATION:
            if (response_expected) {
                can_v2->response_expected[0] |= (1 << 7);
            } else {
                can_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_CAN_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                can_v2->response_expected[1] |= (1 << 0);
            } else {
                can_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_CAN_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                can_v2->response_expected[1] |= (1 << 1);
            } else {
                can_v2->response_expected[1] &= ~(1 << 1);
            }
            break;
        case TF_CAN_V2_FUNCTION_RESET:
            if (response_expected) {
                can_v2->response_expected[1] |= (1 << 2);
            } else {
                can_v2->response_expected[1] &= ~(1 << 2);
            }
            break;
        case TF_CAN_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                can_v2->response_expected[1] |= (1 << 3);
            } else {
                can_v2->response_expected[1] &= ~(1 << 3);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_can_v2_set_response_expected_all(TF_CANV2 *can_v2, bool response_expected) {
    memset(can_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_can_v2_write_frame_low_level(TF_CANV2 *can_v2, uint8_t frame_type, uint32_t identifier, uint8_t data_length, uint8_t data_data[15], bool *ret_success) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_WRITE_FRAME_LOW_LEVEL, 21, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    buf[0] = (uint8_t)frame_type;
    identifier = tf_leconvert_uint32_to(identifier); memcpy(buf + 1, &identifier, 4);
    buf[5] = (uint8_t)data_length;
    memcpy(buf + 6, data_data, 15);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_success != NULL) { *ret_success = tf_packetbuffer_read_bool(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_read_frame_low_level(TF_CANV2 *can_v2, bool *ret_success, uint8_t *ret_frame_type, uint32_t *ret_identifier, uint8_t *ret_data_length, uint8_t ret_data_data[15]) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_READ_FRAME_LOW_LEVEL, 0, 22, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_success != NULL) { *ret_success = tf_packetbuffer_read_bool(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_frame_type != NULL) { *ret_frame_type = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_identifier != NULL) { *ret_identifier = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_data_length != NULL) { *ret_data_length = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_data_data != NULL) { for (i = 0; i < 15; ++i) ret_data_data[i] = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 15); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_set_frame_read_callback_configuration(TF_CANV2 *can_v2, bool enabled) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_can_v2_get_response_expected(can_v2, TF_CAN_V2_FUNCTION_SET_FRAME_READ_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_SET_FRAME_READ_CALLBACK_CONFIGURATION, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    buf[0] = enabled ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_frame_read_callback_configuration(TF_CANV2 *can_v2, bool *ret_enabled) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_FRAME_READ_CALLBACK_CONFIGURATION, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { *ret_enabled = tf_packetbuffer_read_bool(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_set_transceiver_configuration(TF_CANV2 *can_v2, uint32_t baud_rate, uint16_t sample_point, uint8_t transceiver_mode) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_can_v2_get_response_expected(can_v2, TF_CAN_V2_FUNCTION_SET_TRANSCEIVER_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_SET_TRANSCEIVER_CONFIGURATION, 7, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    baud_rate = tf_leconvert_uint32_to(baud_rate); memcpy(buf + 0, &baud_rate, 4);
    sample_point = tf_leconvert_uint16_to(sample_point); memcpy(buf + 4, &sample_point, 2);
    buf[6] = (uint8_t)transceiver_mode;

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_transceiver_configuration(TF_CANV2 *can_v2, uint32_t *ret_baud_rate, uint16_t *ret_sample_point, uint8_t *ret_transceiver_mode) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_TRANSCEIVER_CONFIGURATION, 0, 7, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_baud_rate != NULL) { *ret_baud_rate = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_sample_point != NULL) { *ret_sample_point = tf_packetbuffer_read_uint16_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_transceiver_mode != NULL) { *ret_transceiver_mode = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_set_queue_configuration_low_level(TF_CANV2 *can_v2, uint8_t write_buffer_size, int32_t write_buffer_timeout, uint16_t write_backlog_size, uint8_t read_buffer_sizes_length, int8_t read_buffer_sizes_data[32], uint16_t read_backlog_size) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_can_v2_get_response_expected(can_v2, TF_CAN_V2_FUNCTION_SET_QUEUE_CONFIGURATION_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_SET_QUEUE_CONFIGURATION_LOW_LEVEL, 42, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    buf[0] = (uint8_t)write_buffer_size;
    write_buffer_timeout = tf_leconvert_int32_to(write_buffer_timeout); memcpy(buf + 1, &write_buffer_timeout, 4);
    write_backlog_size = tf_leconvert_uint16_to(write_backlog_size); memcpy(buf + 5, &write_backlog_size, 2);
    buf[7] = (uint8_t)read_buffer_sizes_length;
    memcpy(buf + 8, read_buffer_sizes_data, 32);
    read_backlog_size = tf_leconvert_uint16_to(read_backlog_size); memcpy(buf + 40, &read_backlog_size, 2);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_queue_configuration_low_level(TF_CANV2 *can_v2, uint8_t *ret_write_buffer_size, int32_t *ret_write_buffer_timeout, uint16_t *ret_write_backlog_size, uint8_t *ret_read_buffer_sizes_length, int8_t ret_read_buffer_sizes_data[32], uint16_t *ret_read_backlog_size) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_QUEUE_CONFIGURATION_LOW_LEVEL, 0, 42, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_write_buffer_size != NULL) { *ret_write_buffer_size = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_write_buffer_timeout != NULL) { *ret_write_buffer_timeout = tf_packetbuffer_read_int32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_write_backlog_size != NULL) { *ret_write_backlog_size = tf_packetbuffer_read_uint16_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_read_buffer_sizes_length != NULL) { *ret_read_buffer_sizes_length = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_read_buffer_sizes_data != NULL) { for (i = 0; i < 32; ++i) ret_read_buffer_sizes_data[i] = tf_packetbuffer_read_int8_t(&can_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 32); }
        if (ret_read_backlog_size != NULL) { *ret_read_backlog_size = tf_packetbuffer_read_uint16_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_set_read_filter_configuration(TF_CANV2 *can_v2, uint8_t buffer_index, uint8_t filter_mode, uint32_t filter_mask, uint32_t filter_identifier) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_can_v2_get_response_expected(can_v2, TF_CAN_V2_FUNCTION_SET_READ_FILTER_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_SET_READ_FILTER_CONFIGURATION, 10, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    buf[0] = (uint8_t)buffer_index;
    buf[1] = (uint8_t)filter_mode;
    filter_mask = tf_leconvert_uint32_to(filter_mask); memcpy(buf + 2, &filter_mask, 4);
    filter_identifier = tf_leconvert_uint32_to(filter_identifier); memcpy(buf + 6, &filter_identifier, 4);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_read_filter_configuration(TF_CANV2 *can_v2, uint8_t buffer_index, uint8_t *ret_filter_mode, uint32_t *ret_filter_mask, uint32_t *ret_filter_identifier) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_READ_FILTER_CONFIGURATION, 1, 9, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    buf[0] = (uint8_t)buffer_index;

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_filter_mode != NULL) { *ret_filter_mode = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_filter_mask != NULL) { *ret_filter_mask = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_filter_identifier != NULL) { *ret_filter_identifier = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_error_log_low_level(TF_CANV2 *can_v2, uint8_t *ret_transceiver_state, uint8_t *ret_transceiver_write_error_level, uint8_t *ret_transceiver_read_error_level, uint32_t *ret_transceiver_stuffing_error_count, uint32_t *ret_transceiver_format_error_count, uint32_t *ret_transceiver_ack_error_count, uint32_t *ret_transceiver_bit1_error_count, uint32_t *ret_transceiver_bit0_error_count, uint32_t *ret_transceiver_crc_error_count, uint32_t *ret_write_buffer_timeout_error_count, uint32_t *ret_read_buffer_overflow_error_count, uint8_t *ret_read_buffer_overflow_error_occurred_length, bool ret_read_buffer_overflow_error_occurred_data[32], uint32_t *ret_read_backlog_overflow_error_count) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_ERROR_LOG_LOW_LEVEL, 0, 44, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_transceiver_state != NULL) { *ret_transceiver_state = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_transceiver_write_error_level != NULL) { *ret_transceiver_write_error_level = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_transceiver_read_error_level != NULL) { *ret_transceiver_read_error_level = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_transceiver_stuffing_error_count != NULL) { *ret_transceiver_stuffing_error_count = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_transceiver_format_error_count != NULL) { *ret_transceiver_format_error_count = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_transceiver_ack_error_count != NULL) { *ret_transceiver_ack_error_count = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_transceiver_bit1_error_count != NULL) { *ret_transceiver_bit1_error_count = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_transceiver_bit0_error_count != NULL) { *ret_transceiver_bit0_error_count = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_transceiver_crc_error_count != NULL) { *ret_transceiver_crc_error_count = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_write_buffer_timeout_error_count != NULL) { *ret_write_buffer_timeout_error_count = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_read_buffer_overflow_error_count != NULL) { *ret_read_buffer_overflow_error_count = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_read_buffer_overflow_error_occurred_length != NULL) { *ret_read_buffer_overflow_error_occurred_length = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_read_buffer_overflow_error_occurred_data != NULL) { tf_packetbuffer_read_bool_array(&can_v2->tfp->spitfp->recv_buf, ret_read_buffer_overflow_error_occurred_data, 32);} else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_read_backlog_overflow_error_count != NULL) { *ret_read_backlog_overflow_error_count = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_set_communication_led_config(TF_CANV2 *can_v2, uint8_t config) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_can_v2_get_response_expected(can_v2, TF_CAN_V2_FUNCTION_SET_COMMUNICATION_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_SET_COMMUNICATION_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_communication_led_config(TF_CANV2 *can_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_COMMUNICATION_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_set_error_led_config(TF_CANV2 *can_v2, uint8_t config) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_can_v2_get_response_expected(can_v2, TF_CAN_V2_FUNCTION_SET_ERROR_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_SET_ERROR_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_error_led_config(TF_CANV2 *can_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_ERROR_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_set_frame_readable_callback_configuration(TF_CANV2 *can_v2, bool enabled) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_can_v2_get_response_expected(can_v2, TF_CAN_V2_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    buf[0] = enabled ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_frame_readable_callback_configuration(TF_CANV2 *can_v2, bool *ret_enabled) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_FRAME_READABLE_CALLBACK_CONFIGURATION, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { *ret_enabled = tf_packetbuffer_read_bool(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_set_error_occurred_callback_configuration(TF_CANV2 *can_v2, bool enabled) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_can_v2_get_response_expected(can_v2, TF_CAN_V2_FUNCTION_SET_ERROR_OCCURRED_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_SET_ERROR_OCCURRED_CALLBACK_CONFIGURATION, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    buf[0] = enabled ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_error_occurred_callback_configuration(TF_CANV2 *can_v2, bool *ret_enabled) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_ERROR_OCCURRED_CALLBACK_CONFIGURATION, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { *ret_enabled = tf_packetbuffer_read_bool(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_spitfp_error_count(TF_CANV2 *can_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_set_bootloader_mode(TF_CANV2 *can_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_bootloader_mode(TF_CANV2 *can_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_set_write_firmware_pointer(TF_CANV2 *can_v2, uint32_t pointer) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_can_v2_get_response_expected(can_v2, TF_CAN_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_write_firmware(TF_CANV2 *can_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_set_status_led_config(TF_CANV2 *can_v2, uint8_t config) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_can_v2_get_response_expected(can_v2, TF_CAN_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_status_led_config(TF_CANV2 *can_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_chip_temperature(TF_CANV2 *can_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_reset(TF_CANV2 *can_v2) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_can_v2_get_response_expected(can_v2, TF_CAN_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_write_uid(TF_CANV2 *can_v2, uint32_t uid) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_can_v2_get_response_expected(can_v2, TF_CAN_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(can_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_read_uid(TF_CANV2 *can_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_get_identity(TF_CANV2 *can_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(can_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(can_v2->tfp, TF_CAN_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(can_v2->tfp->hal) + tf_hal_get_common(can_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(can_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&can_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&can_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&can_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&can_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&can_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(can_v2->tfp->hal, can_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(can_v2->tfp);
    }

    result = tf_tfp_finish_send(can_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_can_v2_write_frame(TF_CANV2 *can_v2, uint8_t frame_type, uint32_t identifier, uint8_t *data, uint8_t data_length, bool *ret_success) {
    uint8_t data_data[15];

    if (data_length > 15) {
        return TF_E_INVALID_PARAMETER;
    }

    memcpy(data_data, data, sizeof(uint8_t) * data_length);
    memset(&data_data[data_length], 0, sizeof(uint8_t) * (15 - data_length));

    return tf_can_v2_write_frame_low_level(can_v2, frame_type, identifier, data_length, data_data, ret_success);
}

int tf_can_v2_read_frame(TF_CANV2 *can_v2, bool *ret_success, uint8_t *ret_frame_type, uint32_t *ret_identifier, uint8_t *ret_data, uint8_t *ret_data_length) {
    int ret = TF_E_OK;
    uint8_t data_length = 0;
    uint8_t data_data[15];

    *ret_data_length = 0;

    ret = tf_can_v2_read_frame_low_level(can_v2, ret_success, ret_frame_type, ret_identifier, &data_length, data_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    memcpy(ret_data, data_data, sizeof(uint8_t) * data_length);
    memset(&data_data[data_length], 0, sizeof(uint8_t) * (15 - data_length));

    *ret_data_length = data_length;

    return ret;
}

int tf_can_v2_set_queue_configuration(TF_CANV2 *can_v2, uint8_t write_buffer_size, int32_t write_buffer_timeout, uint16_t write_backlog_size, int8_t *read_buffer_sizes, uint8_t read_buffer_sizes_length, uint16_t read_backlog_size) {
    int8_t read_buffer_sizes_data[32];

    if (read_buffer_sizes_length > 32) {
        return TF_E_INVALID_PARAMETER;
    }

    memcpy(read_buffer_sizes_data, read_buffer_sizes, sizeof(int8_t) * read_buffer_sizes_length);
    memset(&read_buffer_sizes_data[read_buffer_sizes_length], 0, sizeof(int8_t) * (32 - read_buffer_sizes_length));

    return tf_can_v2_set_queue_configuration_low_level(can_v2, write_buffer_size, write_buffer_timeout, write_backlog_size, read_buffer_sizes_length, read_buffer_sizes_data, read_backlog_size);
}

int tf_can_v2_get_queue_configuration(TF_CANV2 *can_v2, uint8_t *ret_write_buffer_size, int32_t *ret_write_buffer_timeout, uint16_t *ret_write_backlog_size, int8_t *ret_read_buffer_sizes, uint8_t *ret_read_buffer_sizes_length, uint16_t *ret_read_backlog_size) {
    int ret = TF_E_OK;
    uint8_t read_buffer_sizes_length = 0;
    int8_t read_buffer_sizes_data[32];

    *ret_read_buffer_sizes_length = 0;

    ret = tf_can_v2_get_queue_configuration_low_level(can_v2, ret_write_buffer_size, ret_write_buffer_timeout, ret_write_backlog_size, &read_buffer_sizes_length, read_buffer_sizes_data, ret_read_backlog_size);

    if (ret != TF_E_OK) {
        return ret;
    }

    memcpy(ret_read_buffer_sizes, read_buffer_sizes_data, sizeof(int8_t) * read_buffer_sizes_length);
    memset(&read_buffer_sizes_data[read_buffer_sizes_length], 0, sizeof(int8_t) * (32 - read_buffer_sizes_length));

    *ret_read_buffer_sizes_length = read_buffer_sizes_length;

    return ret;
}

int tf_can_v2_get_error_log(TF_CANV2 *can_v2, uint8_t *ret_transceiver_state, uint8_t *ret_transceiver_write_error_level, uint8_t *ret_transceiver_read_error_level, uint32_t *ret_transceiver_stuffing_error_count, uint32_t *ret_transceiver_format_error_count, uint32_t *ret_transceiver_ack_error_count, uint32_t *ret_transceiver_bit1_error_count, uint32_t *ret_transceiver_bit0_error_count, uint32_t *ret_transceiver_crc_error_count, uint32_t *ret_write_buffer_timeout_error_count, uint32_t *ret_read_buffer_overflow_error_count, bool *ret_read_buffer_overflow_error_occurred, uint8_t *ret_read_buffer_overflow_error_occurred_length, uint32_t *ret_read_backlog_overflow_error_count) {
    int ret = TF_E_OK;
    uint8_t read_buffer_overflow_error_occurred_length = 0;
    bool read_buffer_overflow_error_occurred_data[32];

    *ret_read_buffer_overflow_error_occurred_length = 0;

    ret = tf_can_v2_get_error_log_low_level(can_v2, ret_transceiver_state, ret_transceiver_write_error_level, ret_transceiver_read_error_level, ret_transceiver_stuffing_error_count, ret_transceiver_format_error_count, ret_transceiver_ack_error_count, ret_transceiver_bit1_error_count, ret_transceiver_bit0_error_count, ret_transceiver_crc_error_count, ret_write_buffer_timeout_error_count, ret_read_buffer_overflow_error_count, &read_buffer_overflow_error_occurred_length, read_buffer_overflow_error_occurred_data, ret_read_backlog_overflow_error_count);

    if (ret != TF_E_OK) {
        return ret;
    }

    memcpy(ret_read_buffer_overflow_error_occurred, read_buffer_overflow_error_occurred_data, sizeof(bool) * read_buffer_overflow_error_occurred_length);
    memset(&read_buffer_overflow_error_occurred_data[read_buffer_overflow_error_occurred_length], 0, sizeof(bool) * (32 - read_buffer_overflow_error_occurred_length));

    *ret_read_buffer_overflow_error_occurred_length = read_buffer_overflow_error_occurred_length;

    return ret;
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_can_v2_register_frame_read_low_level_callback(TF_CANV2 *can_v2, TF_CANV2FrameReadLowLevelHandler handler, void *user_data) {
    if (handler == NULL) {
        can_v2->tfp->needs_callback_tick = false;
        can_v2->tfp->needs_callback_tick |= can_v2->frame_readable_handler != NULL;
        can_v2->tfp->needs_callback_tick |= can_v2->error_occurred_handler != NULL;
    } else {
        can_v2->tfp->needs_callback_tick = true;
    }
    can_v2->frame_read_low_level_handler = handler;
    can_v2->frame_read_low_level_user_data = user_data;
}


void tf_can_v2_register_frame_readable_callback(TF_CANV2 *can_v2, TF_CANV2FrameReadableHandler handler, void *user_data) {
    if (handler == NULL) {
        can_v2->tfp->needs_callback_tick = false;
        can_v2->tfp->needs_callback_tick |= can_v2->frame_read_low_level_handler != NULL;
        can_v2->tfp->needs_callback_tick |= can_v2->error_occurred_handler != NULL;
    } else {
        can_v2->tfp->needs_callback_tick = true;
    }
    can_v2->frame_readable_handler = handler;
    can_v2->frame_readable_user_data = user_data;
}


void tf_can_v2_register_error_occurred_callback(TF_CANV2 *can_v2, TF_CANV2ErrorOccurredHandler handler, void *user_data) {
    if (handler == NULL) {
        can_v2->tfp->needs_callback_tick = false;
        can_v2->tfp->needs_callback_tick |= can_v2->frame_read_low_level_handler != NULL;
        can_v2->tfp->needs_callback_tick |= can_v2->frame_readable_handler != NULL;
    } else {
        can_v2->tfp->needs_callback_tick = true;
    }
    can_v2->error_occurred_handler = handler;
    can_v2->error_occurred_user_data = user_data;
}
#endif
int tf_can_v2_callback_tick(TF_CANV2 *can_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(can_v2->tfp, tf_hal_current_time_us(can_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
