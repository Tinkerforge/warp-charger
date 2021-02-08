/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_isolator.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_isolator_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_Isolator *isolator = (TF_Isolator *) dev;
    (void)payload;

    switch(fid) {

        case TF_ISOLATOR_CALLBACK_STATISTICS: {
            TF_IsolatorStatisticsHandler fn = isolator->statistics_handler;
            void *user_data = isolator->statistics_user_data;
            if (fn == NULL)
                return false;

            uint32_t messages_from_brick = tf_packetbuffer_read_uint32_t(payload);
            uint32_t messages_from_bricklet = tf_packetbuffer_read_uint32_t(payload);
            uint16_t connected_bricklet_device_identifier = tf_packetbuffer_read_uint16_t(payload);
            char connected_bricklet_uid[8]; tf_packetbuffer_pop_n(payload, (uint8_t*)connected_bricklet_uid, 8);
            TF_HalCommon *common = tf_hal_get_common(isolator->tfp->hal);
            common->locked = true;
            fn(isolator, messages_from_brick, messages_from_bricklet, connected_bricklet_device_identifier, connected_bricklet_uid, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_isolator_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_isolator_create(TF_Isolator *isolator, const char *uid, TF_HalContext *hal) {
    memset(isolator, 0, sizeof(TF_Isolator));

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

    //rc = tf_tfp_init(isolator->tfp, numeric_uid, TF_ISOLATOR_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_isolator_callback_handler);
    rc = tf_hal_get_tfp(hal, &isolator->tfp, TF_ISOLATOR_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    isolator->tfp->device = isolator;
    isolator->tfp->uid = numeric_uid;
    isolator->tfp->cb_handler = tf_isolator_callback_handler;
    isolator->response_expected[0] = 0x04;
    return TF_E_OK;
}

int tf_isolator_destroy(TF_Isolator *isolator) {
    int result = tf_tfp_destroy(isolator->tfp);
    isolator->tfp = NULL;
    return result;
}

int tf_isolator_get_response_expected(TF_Isolator *isolator, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_ISOLATOR_FUNCTION_SET_SPITFP_BAUDRATE_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (isolator->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_ISOLATOR_FUNCTION_SET_SPITFP_BAUDRATE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (isolator->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_ISOLATOR_FUNCTION_SET_STATISTICS_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (isolator->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_ISOLATOR_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (isolator->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_ISOLATOR_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (isolator->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_ISOLATOR_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (isolator->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_ISOLATOR_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (isolator->response_expected[0] & (1 << 6)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_isolator_set_response_expected(TF_Isolator *isolator, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_ISOLATOR_FUNCTION_SET_SPITFP_BAUDRATE_CONFIG:
            if (response_expected) {
                isolator->response_expected[0] |= (1 << 0);
            } else {
                isolator->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_ISOLATOR_FUNCTION_SET_SPITFP_BAUDRATE:
            if (response_expected) {
                isolator->response_expected[0] |= (1 << 1);
            } else {
                isolator->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_ISOLATOR_FUNCTION_SET_STATISTICS_CALLBACK_CONFIGURATION:
            if (response_expected) {
                isolator->response_expected[0] |= (1 << 2);
            } else {
                isolator->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_ISOLATOR_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                isolator->response_expected[0] |= (1 << 3);
            } else {
                isolator->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_ISOLATOR_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                isolator->response_expected[0] |= (1 << 4);
            } else {
                isolator->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_ISOLATOR_FUNCTION_RESET:
            if (response_expected) {
                isolator->response_expected[0] |= (1 << 5);
            } else {
                isolator->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_ISOLATOR_FUNCTION_WRITE_UID:
            if (response_expected) {
                isolator->response_expected[0] |= (1 << 6);
            } else {
                isolator->response_expected[0] &= ~(1 << 6);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_isolator_set_response_expected_all(TF_Isolator *isolator, bool response_expected) {
    memset(isolator->response_expected, response_expected ? 0xFF : 0, 1);
}

int tf_isolator_get_statistics(TF_Isolator *isolator, uint32_t *ret_messages_from_brick, uint32_t *ret_messages_from_bricklet, uint16_t *ret_connected_bricklet_device_identifier, char ret_connected_bricklet_uid[8]) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_GET_STATISTICS, 0, 18, response_expected);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_messages_from_brick != NULL) { *ret_messages_from_brick = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        if (ret_messages_from_bricklet != NULL) { *ret_messages_from_bricklet = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        if (ret_connected_bricklet_device_identifier != NULL) { *ret_connected_bricklet_device_identifier = tf_packetbuffer_read_uint16_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 2); }
        if (ret_connected_bricklet_uid != NULL) { tf_packetbuffer_pop_n(&isolator->tfp->spitfp->recv_buf, (uint8_t*)ret_connected_bricklet_uid, 8);} else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 8); }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_set_spitfp_baudrate_config(TF_Isolator *isolator, bool enable_dynamic_baudrate, uint32_t minimum_dynamic_baudrate) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_isolator_get_response_expected(isolator, TF_ISOLATOR_FUNCTION_SET_SPITFP_BAUDRATE_CONFIG, &response_expected);
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_SET_SPITFP_BAUDRATE_CONFIG, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(isolator->tfp);

    buf[0] = enable_dynamic_baudrate ? 1 : 0;
    minimum_dynamic_baudrate = tf_leconvert_uint32_to(minimum_dynamic_baudrate); memcpy(buf + 1, &minimum_dynamic_baudrate, 4);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_get_spitfp_baudrate_config(TF_Isolator *isolator, bool *ret_enable_dynamic_baudrate, uint32_t *ret_minimum_dynamic_baudrate) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_GET_SPITFP_BAUDRATE_CONFIG, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enable_dynamic_baudrate != NULL) { *ret_enable_dynamic_baudrate = tf_packetbuffer_read_bool(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 1); }
        if (ret_minimum_dynamic_baudrate != NULL) { *ret_minimum_dynamic_baudrate = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_set_spitfp_baudrate(TF_Isolator *isolator, uint32_t baudrate) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_isolator_get_response_expected(isolator, TF_ISOLATOR_FUNCTION_SET_SPITFP_BAUDRATE, &response_expected);
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_SET_SPITFP_BAUDRATE, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(isolator->tfp);

    baudrate = tf_leconvert_uint32_to(baudrate); memcpy(buf + 0, &baudrate, 4);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_get_spitfp_baudrate(TF_Isolator *isolator, uint32_t *ret_baudrate) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_GET_SPITFP_BAUDRATE, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_baudrate != NULL) { *ret_baudrate = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_get_isolator_spitfp_error_count(TF_Isolator *isolator, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_GET_ISOLATOR_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_set_statistics_callback_configuration(TF_Isolator *isolator, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_isolator_get_response_expected(isolator, TF_ISOLATOR_FUNCTION_SET_STATISTICS_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_SET_STATISTICS_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(isolator->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_get_statistics_callback_configuration(TF_Isolator *isolator, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_GET_STATISTICS_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_get_spitfp_error_count(TF_Isolator *isolator, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_set_bootloader_mode(TF_Isolator *isolator, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(isolator->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_get_bootloader_mode(TF_Isolator *isolator, uint8_t *ret_mode) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_set_write_firmware_pointer(TF_Isolator *isolator, uint32_t pointer) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_isolator_get_response_expected(isolator, TF_ISOLATOR_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(isolator->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_write_firmware(TF_Isolator *isolator, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(isolator->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_set_status_led_config(TF_Isolator *isolator, uint8_t config) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_isolator_get_response_expected(isolator, TF_ISOLATOR_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(isolator->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_get_status_led_config(TF_Isolator *isolator, uint8_t *ret_config) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_get_chip_temperature(TF_Isolator *isolator, int16_t *ret_temperature) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_reset(TF_Isolator *isolator) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_isolator_get_response_expected(isolator, TF_ISOLATOR_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_write_uid(TF_Isolator *isolator, uint32_t uid) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_isolator_get_response_expected(isolator, TF_ISOLATOR_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(isolator->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_read_uid(TF_Isolator *isolator, uint32_t *ret_uid) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_isolator_get_identity(TF_Isolator *isolator, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(isolator->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(isolator->tfp, TF_ISOLATOR_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(isolator->tfp->hal) + tf_hal_get_common(isolator->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(isolator->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&isolator->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&isolator->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&isolator->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&isolator->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&isolator->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&isolator->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(isolator->tfp->hal, isolator->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(isolator->tfp);
    }

    result = tf_tfp_finish_send(isolator->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_isolator_register_statistics_callback(TF_Isolator *isolator, TF_IsolatorStatisticsHandler handler, void *user_data) {
    if (handler == NULL) {
        isolator->tfp->needs_callback_tick = false;
        
    } else {
        isolator->tfp->needs_callback_tick = true;
    }
    isolator->statistics_handler = handler;
    isolator->statistics_user_data = user_data;
}
#endif
int tf_isolator_callback_tick(TF_Isolator *isolator, uint32_t timeout_us) {
    return tf_tfp_callback_tick(isolator->tfp, tf_hal_current_time_us(isolator->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
