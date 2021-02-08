/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_unknown.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_unknown_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_Unknown *unknown = (TF_Unknown *) dev;
    (void)payload;

    switch(fid) {

        case TF_UNKNOWN_CALLBACK_ENUMERATE: {
            TF_UnknownEnumerateHandler fn = unknown->enumerate_handler;
            void *user_data = unknown->enumerate_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            char uid[8]; tf_packetbuffer_pop_n(payload, (uint8_t*)uid, 8);
            char connected_uid[8]; tf_packetbuffer_pop_n(payload, (uint8_t*)connected_uid, 8);
            char position = tf_packetbuffer_read_char(payload);
            uint8_t hardware_version[3]; for (i = 0; i < 3; ++i) hardware_version[i] = tf_packetbuffer_read_uint8_t(payload);
            uint8_t firmware_version[3]; for (i = 0; i < 3; ++i) firmware_version[i] = tf_packetbuffer_read_uint8_t(payload);
            uint16_t device_identifier = tf_packetbuffer_read_uint16_t(payload);
            uint8_t enumeration_type = tf_packetbuffer_read_uint8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(unknown->tfp->hal);
            common->locked = true;
            fn(unknown, uid, connected_uid, position, hardware_version, firmware_version, device_identifier, enumeration_type, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_unknown_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_unknown_create(TF_Unknown *unknown, const char *uid, TF_HalContext *hal, uint8_t port_id, int inventory_index) {
    memset(unknown, 0, sizeof(TF_Unknown));

    uint32_t numeric_uid;
    int rc = tf_base58_decode(uid, &numeric_uid);
    if (rc != TF_E_OK) {
        return rc;
    }

    //rc = tf_tfp_init(&unknown->tfp, numeric_uid, 0, hal, port_id, inventory_index, tf_unknown_callback_handler);
    rc = tf_hal_get_tfp(hal, &unknown->tfp, 0, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    unknown->tfp->device = unknown;
    unknown->tfp->cb_handler = tf_unknown_callback_handler;
    TF_PortCommon *port_common = tf_hal_get_port_common(hal, port_id);
    rc = tf_spitfp_init(&port_common->spitfp, hal, port_id);
    if (rc != TF_E_OK) {
        return rc;
    }
    unknown->tfp->spitfp = &port_common->spitfp;
    unknown->response_expected[0] = 0x00;
    return TF_E_OK;
}

int tf_unknown_destroy(TF_Unknown *unknown) {
    int result = tf_tfp_destroy(unknown->tfp);
    unknown->tfp = NULL;
    return result;
}

int tf_unknown_get_response_expected(TF_Unknown *unknown, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_UNKNOWN_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (unknown->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_UNKNOWN_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (unknown->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_UNKNOWN_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (unknown->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_UNKNOWN_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (unknown->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_UNKNOWN_FUNCTION_COMCU_ENUMERATE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (unknown->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_UNKNOWN_FUNCTION_ENUMERATE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (unknown->response_expected[0] & (1 << 5)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_unknown_set_response_expected(TF_Unknown *unknown, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_UNKNOWN_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                unknown->response_expected[0] |= (1 << 0);
            } else {
                unknown->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_UNKNOWN_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                unknown->response_expected[0] |= (1 << 1);
            } else {
                unknown->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_UNKNOWN_FUNCTION_RESET:
            if (response_expected) {
                unknown->response_expected[0] |= (1 << 2);
            } else {
                unknown->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_UNKNOWN_FUNCTION_WRITE_UID:
            if (response_expected) {
                unknown->response_expected[0] |= (1 << 3);
            } else {
                unknown->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_UNKNOWN_FUNCTION_COMCU_ENUMERATE:
            if (response_expected) {
                unknown->response_expected[0] |= (1 << 4);
            } else {
                unknown->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_UNKNOWN_FUNCTION_ENUMERATE:
            if (response_expected) {
                unknown->response_expected[0] |= (1 << 5);
            } else {
                unknown->response_expected[0] &= ~(1 << 5);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_unknown_set_response_expected_all(TF_Unknown *unknown, bool response_expected) {
    memset(unknown->response_expected, response_expected ? 0xFF : 0, 1);
}

int tf_unknown_get_spitfp_error_count(TF_Unknown *unknown, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&unknown->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&unknown->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&unknown->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&unknown->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(unknown->tfp);
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_set_bootloader_mode(TF_Unknown *unknown, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(unknown->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&unknown->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(unknown->tfp);
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_get_bootloader_mode(TF_Unknown *unknown, uint8_t *ret_mode) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&unknown->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(unknown->tfp);
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_set_write_firmware_pointer(TF_Unknown *unknown, uint32_t pointer) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_unknown_get_response_expected(unknown, TF_UNKNOWN_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(unknown->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_write_firmware(TF_Unknown *unknown, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(unknown->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&unknown->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(unknown->tfp);
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_set_status_led_config(TF_Unknown *unknown, uint8_t config) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_unknown_get_response_expected(unknown, TF_UNKNOWN_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(unknown->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_get_status_led_config(TF_Unknown *unknown, uint8_t *ret_config) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&unknown->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(unknown->tfp);
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_get_chip_temperature(TF_Unknown *unknown, int16_t *ret_temperature) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&unknown->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(unknown->tfp);
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_reset(TF_Unknown *unknown) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_unknown_get_response_expected(unknown, TF_UNKNOWN_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_write_uid(TF_Unknown *unknown, uint32_t uid) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_unknown_get_response_expected(unknown, TF_UNKNOWN_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(unknown->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_read_uid(TF_Unknown *unknown, uint32_t *ret_uid) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&unknown->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(unknown->tfp);
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_comcu_enumerate(TF_Unknown *unknown) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_unknown_get_response_expected(unknown, TF_UNKNOWN_FUNCTION_COMCU_ENUMERATE, &response_expected);
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_COMCU_ENUMERATE, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_enumerate(TF_Unknown *unknown) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_unknown_get_response_expected(unknown, TF_UNKNOWN_FUNCTION_ENUMERATE, &response_expected);
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_ENUMERATE, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_unknown_get_identity(TF_Unknown *unknown, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(unknown->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(unknown->tfp, TF_UNKNOWN_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(unknown->tfp->hal) + tf_hal_get_common(unknown->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(unknown->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&unknown->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&unknown->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&unknown->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&unknown->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&unknown->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&unknown->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&unknown->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(unknown->tfp->hal, unknown->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(unknown->tfp);
    }

    result = tf_tfp_finish_send(unknown->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_unknown_register_enumerate_callback(TF_Unknown *unknown, TF_UnknownEnumerateHandler handler, void *user_data) {
    if (handler == NULL) {
        unknown->tfp->needs_callback_tick = false;
        
    } else {
        unknown->tfp->needs_callback_tick = true;
    }
    unknown->enumerate_handler = handler;
    unknown->enumerate_user_data = user_data;
}
#endif
int tf_unknown_callback_tick(TF_Unknown *unknown, uint32_t timeout_us) {
    return tf_tfp_callback_tick(unknown->tfp, tf_hal_current_time_us(unknown->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
