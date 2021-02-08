/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_rs232_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_rs232_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_RS232V2 *rs232_v2 = (TF_RS232V2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_RS232_V2_CALLBACK_READ_LOW_LEVEL: {
            TF_RS232V2ReadLowLevelHandler fn = rs232_v2->read_low_level_handler;
            void *user_data = rs232_v2->read_low_level_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            uint16_t message_length = tf_packetbuffer_read_uint16_t(payload);
            uint16_t message_chunk_offset = tf_packetbuffer_read_uint16_t(payload);
            char message_chunk_data[60]; for (i = 0; i < 60; ++i) message_chunk_data[i] = tf_packetbuffer_read_char(payload);
            TF_HalCommon *common = tf_hal_get_common(rs232_v2->tfp->hal);
            common->locked = true;
            fn(rs232_v2, message_length, message_chunk_offset, message_chunk_data, user_data);
            common->locked = false;
            break;
        }

        case TF_RS232_V2_CALLBACK_ERROR_COUNT: {
            TF_RS232V2ErrorCountHandler fn = rs232_v2->error_count_handler;
            void *user_data = rs232_v2->error_count_user_data;
            if (fn == NULL)
                return false;

            uint32_t error_count_overrun = tf_packetbuffer_read_uint32_t(payload);
            uint32_t error_count_parity = tf_packetbuffer_read_uint32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs232_v2->tfp->hal);
            common->locked = true;
            fn(rs232_v2, error_count_overrun, error_count_parity, user_data);
            common->locked = false;
            break;
        }

        case TF_RS232_V2_CALLBACK_FRAME_READABLE: {
            TF_RS232V2FrameReadableHandler fn = rs232_v2->frame_readable_handler;
            void *user_data = rs232_v2->frame_readable_user_data;
            if (fn == NULL)
                return false;

            uint16_t frame_count = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs232_v2->tfp->hal);
            common->locked = true;
            fn(rs232_v2, frame_count, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_rs232_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_rs232_v2_create(TF_RS232V2 *rs232_v2, const char *uid, TF_HalContext *hal) {
    memset(rs232_v2, 0, sizeof(TF_RS232V2));

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

    //rc = tf_tfp_init(rs232_v2->tfp, numeric_uid, TF_RS232_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_rs232_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &rs232_v2->tfp, TF_RS232_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    rs232_v2->tfp->device = rs232_v2;
    rs232_v2->tfp->uid = numeric_uid;
    rs232_v2->tfp->cb_handler = tf_rs232_v2_callback_handler;
    rs232_v2->response_expected[0] = 0x13;
    rs232_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_rs232_v2_destroy(TF_RS232V2 *rs232_v2) {
    int result = tf_tfp_destroy(rs232_v2->tfp);
    rs232_v2->tfp = NULL;
    return result;
}

int tf_rs232_v2_get_response_expected(TF_RS232V2 *rs232_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_RS232_V2_FUNCTION_ENABLE_READ_CALLBACK:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs232_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_RS232_V2_FUNCTION_DISABLE_READ_CALLBACK:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs232_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_RS232_V2_FUNCTION_SET_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs232_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_RS232_V2_FUNCTION_SET_BUFFER_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs232_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_RS232_V2_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs232_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_RS232_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs232_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_RS232_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs232_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_RS232_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs232_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_RS232_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs232_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_rs232_v2_set_response_expected(TF_RS232V2 *rs232_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_RS232_V2_FUNCTION_ENABLE_READ_CALLBACK:
            if (response_expected) {
                rs232_v2->response_expected[0] |= (1 << 0);
            } else {
                rs232_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_RS232_V2_FUNCTION_DISABLE_READ_CALLBACK:
            if (response_expected) {
                rs232_v2->response_expected[0] |= (1 << 1);
            } else {
                rs232_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_RS232_V2_FUNCTION_SET_CONFIGURATION:
            if (response_expected) {
                rs232_v2->response_expected[0] |= (1 << 2);
            } else {
                rs232_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_RS232_V2_FUNCTION_SET_BUFFER_CONFIG:
            if (response_expected) {
                rs232_v2->response_expected[0] |= (1 << 3);
            } else {
                rs232_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_RS232_V2_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION:
            if (response_expected) {
                rs232_v2->response_expected[0] |= (1 << 4);
            } else {
                rs232_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_RS232_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                rs232_v2->response_expected[0] |= (1 << 5);
            } else {
                rs232_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_RS232_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                rs232_v2->response_expected[0] |= (1 << 6);
            } else {
                rs232_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_RS232_V2_FUNCTION_RESET:
            if (response_expected) {
                rs232_v2->response_expected[0] |= (1 << 7);
            } else {
                rs232_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_RS232_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                rs232_v2->response_expected[1] |= (1 << 0);
            } else {
                rs232_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_rs232_v2_set_response_expected_all(TF_RS232V2 *rs232_v2, bool response_expected) {
    memset(rs232_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_rs232_v2_write_low_level(TF_RS232V2 *rs232_v2, uint16_t message_length, uint16_t message_chunk_offset, char message_chunk_data[60], uint8_t *ret_message_chunk_written) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_WRITE_LOW_LEVEL, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs232_v2->tfp);

    message_length = tf_leconvert_uint16_to(message_length); memcpy(buf + 0, &message_length, 2);
    message_chunk_offset = tf_leconvert_uint16_to(message_chunk_offset); memcpy(buf + 2, &message_chunk_offset, 2);
    memcpy(buf + 4, message_chunk_data, 60);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_message_chunk_written != NULL) { *ret_message_chunk_written = tf_packetbuffer_read_uint8_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_read_low_level(TF_RS232V2 *rs232_v2, uint16_t length, uint16_t *ret_message_length, uint16_t *ret_message_chunk_offset, char ret_message_chunk_data[60]) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_READ_LOW_LEVEL, 2, 64, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(rs232_v2->tfp);

    length = tf_leconvert_uint16_to(length); memcpy(buf + 0, &length, 2);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_message_length != NULL) { *ret_message_length = tf_packetbuffer_read_uint16_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_message_chunk_offset != NULL) { *ret_message_chunk_offset = tf_packetbuffer_read_uint16_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_message_chunk_data != NULL) { for (i = 0; i < 60; ++i) ret_message_chunk_data[i] = tf_packetbuffer_read_char(&rs232_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 60); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_enable_read_callback(TF_RS232V2 *rs232_v2) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs232_v2_get_response_expected(rs232_v2, TF_RS232_V2_FUNCTION_ENABLE_READ_CALLBACK, &response_expected);
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_ENABLE_READ_CALLBACK, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_disable_read_callback(TF_RS232V2 *rs232_v2) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs232_v2_get_response_expected(rs232_v2, TF_RS232_V2_FUNCTION_DISABLE_READ_CALLBACK, &response_expected);
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_DISABLE_READ_CALLBACK, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_is_read_callback_enabled(TF_RS232V2 *rs232_v2, bool *ret_enabled) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_IS_READ_CALLBACK_ENABLED, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { *ret_enabled = tf_packetbuffer_read_bool(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_set_configuration(TF_RS232V2 *rs232_v2, uint32_t baudrate, uint8_t parity, uint8_t stopbits, uint8_t wordlength, uint8_t flowcontrol) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs232_v2_get_response_expected(rs232_v2, TF_RS232_V2_FUNCTION_SET_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_SET_CONFIGURATION, 8, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs232_v2->tfp);

    baudrate = tf_leconvert_uint32_to(baudrate); memcpy(buf + 0, &baudrate, 4);
    buf[4] = (uint8_t)parity;
    buf[5] = (uint8_t)stopbits;
    buf[6] = (uint8_t)wordlength;
    buf[7] = (uint8_t)flowcontrol;

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_get_configuration(TF_RS232V2 *rs232_v2, uint32_t *ret_baudrate, uint8_t *ret_parity, uint8_t *ret_stopbits, uint8_t *ret_wordlength, uint8_t *ret_flowcontrol) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_GET_CONFIGURATION, 0, 8, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_baudrate != NULL) { *ret_baudrate = tf_packetbuffer_read_uint32_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_parity != NULL) { *ret_parity = tf_packetbuffer_read_uint8_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_stopbits != NULL) { *ret_stopbits = tf_packetbuffer_read_uint8_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_wordlength != NULL) { *ret_wordlength = tf_packetbuffer_read_uint8_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_flowcontrol != NULL) { *ret_flowcontrol = tf_packetbuffer_read_uint8_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_set_buffer_config(TF_RS232V2 *rs232_v2, uint16_t send_buffer_size, uint16_t receive_buffer_size) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs232_v2_get_response_expected(rs232_v2, TF_RS232_V2_FUNCTION_SET_BUFFER_CONFIG, &response_expected);
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_SET_BUFFER_CONFIG, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs232_v2->tfp);

    send_buffer_size = tf_leconvert_uint16_to(send_buffer_size); memcpy(buf + 0, &send_buffer_size, 2);
    receive_buffer_size = tf_leconvert_uint16_to(receive_buffer_size); memcpy(buf + 2, &receive_buffer_size, 2);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_get_buffer_config(TF_RS232V2 *rs232_v2, uint16_t *ret_send_buffer_size, uint16_t *ret_receive_buffer_size) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_GET_BUFFER_CONFIG, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_send_buffer_size != NULL) { *ret_send_buffer_size = tf_packetbuffer_read_uint16_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_receive_buffer_size != NULL) { *ret_receive_buffer_size = tf_packetbuffer_read_uint16_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_get_buffer_status(TF_RS232V2 *rs232_v2, uint16_t *ret_send_buffer_used, uint16_t *ret_receive_buffer_used) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_GET_BUFFER_STATUS, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_send_buffer_used != NULL) { *ret_send_buffer_used = tf_packetbuffer_read_uint16_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_receive_buffer_used != NULL) { *ret_receive_buffer_used = tf_packetbuffer_read_uint16_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_get_error_count(TF_RS232V2 *rs232_v2, uint32_t *ret_error_count_overrun, uint32_t *ret_error_count_parity) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_GET_ERROR_COUNT, 0, 8, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_overrun != NULL) { *ret_error_count_overrun = tf_packetbuffer_read_uint32_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_parity != NULL) { *ret_error_count_parity = tf_packetbuffer_read_uint32_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_set_frame_readable_callback_configuration(TF_RS232V2 *rs232_v2, uint16_t frame_size) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs232_v2_get_response_expected(rs232_v2, TF_RS232_V2_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs232_v2->tfp);

    frame_size = tf_leconvert_uint16_to(frame_size); memcpy(buf + 0, &frame_size, 2);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_get_frame_readable_callback_configuration(TF_RS232V2 *rs232_v2, uint16_t *ret_frame_size) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_GET_FRAME_READABLE_CALLBACK_CONFIGURATION, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_frame_size != NULL) { *ret_frame_size = tf_packetbuffer_read_uint16_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_get_spitfp_error_count(TF_RS232V2 *rs232_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_set_bootloader_mode(TF_RS232V2 *rs232_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs232_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_get_bootloader_mode(TF_RS232V2 *rs232_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_set_write_firmware_pointer(TF_RS232V2 *rs232_v2, uint32_t pointer) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs232_v2_get_response_expected(rs232_v2, TF_RS232_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs232_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_write_firmware(TF_RS232V2 *rs232_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs232_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_set_status_led_config(TF_RS232V2 *rs232_v2, uint8_t config) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs232_v2_get_response_expected(rs232_v2, TF_RS232_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs232_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_get_status_led_config(TF_RS232V2 *rs232_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_get_chip_temperature(TF_RS232V2 *rs232_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_reset(TF_RS232V2 *rs232_v2) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs232_v2_get_response_expected(rs232_v2, TF_RS232_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_write_uid(TF_RS232V2 *rs232_v2, uint32_t uid) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs232_v2_get_response_expected(rs232_v2, TF_RS232_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs232_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_read_uid(TF_RS232V2 *rs232_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_get_identity(TF_RS232V2 *rs232_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(rs232_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs232_v2->tfp, TF_RS232_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(rs232_v2->tfp->hal) + tf_hal_get_common(rs232_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs232_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&rs232_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&rs232_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&rs232_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&rs232_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&rs232_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs232_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(rs232_v2->tfp->hal, rs232_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(rs232_v2->tfp);
    }

    result = tf_tfp_finish_send(rs232_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs232_v2_write(TF_RS232V2 *rs232_v2, const char *message, uint16_t message_length, uint16_t *ret_message_written) {
    int ret = TF_E_OK;
    uint16_t message_chunk_offset = 0;
    char message_chunk_data[60];
    uint16_t message_chunk_length = 0;
    uint8_t message_chunk_written = 0;

    *ret_message_written = 0;

    if (message_length == 0) {
        memset(&message_chunk_data, 0, sizeof(char) * 60);

        ret = tf_rs232_v2_write_low_level(rs232_v2, message_length, message_chunk_offset, message_chunk_data, &message_chunk_written);

        if (ret != TF_E_OK) {
            return ret;
        }

        *ret_message_written = message_chunk_written;
    } else {

        while (message_chunk_offset < message_length) {
            message_chunk_length = message_length - message_chunk_offset;

            if (message_chunk_length > 60) {
                message_chunk_length = 60;
            }

            memcpy(message_chunk_data, &message[message_chunk_offset], sizeof(char) * message_chunk_length);
            memset(&message_chunk_data[message_chunk_length], 0, sizeof(char) * (60 - message_chunk_length));

            ret = tf_rs232_v2_write_low_level(rs232_v2, message_length, message_chunk_offset, message_chunk_data, &message_chunk_written);

            if (ret != TF_E_OK) {
                *ret_message_written = 0;

                break;
            }

            *ret_message_written += message_chunk_written;

            if (message_chunk_written < 60) {
                break; // either last chunk or short write
            }

            message_chunk_offset += 60;
        }

    }

    return ret;
}

int tf_rs232_v2_read(TF_RS232V2 *rs232_v2, uint16_t length, char *ret_message, uint16_t *ret_message_length) {
    int ret = TF_E_OK;
    uint16_t message_length = 0;
    uint16_t message_chunk_offset = 0;
    char message_chunk_data[60];
    bool message_out_of_sync;
    uint16_t message_chunk_length = 0;

    *ret_message_length = 0;

    ret = tf_rs232_v2_read_low_level(rs232_v2, length, &message_length, &message_chunk_offset, message_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    message_out_of_sync = message_chunk_offset != 0;

    if (!message_out_of_sync) {
        message_chunk_length = message_length - message_chunk_offset;

        if (message_chunk_length > 60) {
            message_chunk_length = 60;
        }

        memcpy(ret_message, message_chunk_data, sizeof(char) * message_chunk_length);
        *ret_message_length = message_chunk_length;

        while (*ret_message_length < message_length) {
            ret = tf_rs232_v2_read_low_level(rs232_v2, length, &message_length, &message_chunk_offset, message_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            message_out_of_sync = message_chunk_offset != *ret_message_length;

            if (message_out_of_sync) {
                break;
            }

            message_chunk_length = message_length - message_chunk_offset;

            if (message_chunk_length > 60) {
                message_chunk_length = 60;
            }

            memcpy(&ret_message[*ret_message_length], message_chunk_data, sizeof(char) * message_chunk_length);
            *ret_message_length += message_chunk_length;
        }
    }

    if (message_out_of_sync) {
        *ret_message_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (message_chunk_offset + 60 < message_length) {
            ret = tf_rs232_v2_read_low_level(rs232_v2, length, &message_length, &message_chunk_offset, message_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_rs232_v2_register_read_low_level_callback(TF_RS232V2 *rs232_v2, TF_RS232V2ReadLowLevelHandler handler, void *user_data) {
    if (handler == NULL) {
        rs232_v2->tfp->needs_callback_tick = false;
        rs232_v2->tfp->needs_callback_tick |= rs232_v2->error_count_handler != NULL;
        rs232_v2->tfp->needs_callback_tick |= rs232_v2->frame_readable_handler != NULL;
    } else {
        rs232_v2->tfp->needs_callback_tick = true;
    }
    rs232_v2->read_low_level_handler = handler;
    rs232_v2->read_low_level_user_data = user_data;
}


void tf_rs232_v2_register_error_count_callback(TF_RS232V2 *rs232_v2, TF_RS232V2ErrorCountHandler handler, void *user_data) {
    if (handler == NULL) {
        rs232_v2->tfp->needs_callback_tick = false;
        rs232_v2->tfp->needs_callback_tick |= rs232_v2->read_low_level_handler != NULL;
        rs232_v2->tfp->needs_callback_tick |= rs232_v2->frame_readable_handler != NULL;
    } else {
        rs232_v2->tfp->needs_callback_tick = true;
    }
    rs232_v2->error_count_handler = handler;
    rs232_v2->error_count_user_data = user_data;
}


void tf_rs232_v2_register_frame_readable_callback(TF_RS232V2 *rs232_v2, TF_RS232V2FrameReadableHandler handler, void *user_data) {
    if (handler == NULL) {
        rs232_v2->tfp->needs_callback_tick = false;
        rs232_v2->tfp->needs_callback_tick |= rs232_v2->read_low_level_handler != NULL;
        rs232_v2->tfp->needs_callback_tick |= rs232_v2->error_count_handler != NULL;
    } else {
        rs232_v2->tfp->needs_callback_tick = true;
    }
    rs232_v2->frame_readable_handler = handler;
    rs232_v2->frame_readable_user_data = user_data;
}
#endif
int tf_rs232_v2_callback_tick(TF_RS232V2 *rs232_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(rs232_v2->tfp, tf_hal_current_time_us(rs232_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
