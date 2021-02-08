/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_rgb_led_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


static bool tf_rgb_led_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    (void)dev;
    (void)fid;
    (void)payload;
    return false;
}
int tf_rgb_led_v2_create(TF_RGBLEDV2 *rgb_led_v2, const char *uid, TF_HalContext *hal) {
    memset(rgb_led_v2, 0, sizeof(TF_RGBLEDV2));

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

    //rc = tf_tfp_init(rgb_led_v2->tfp, numeric_uid, TF_RGB_LED_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_rgb_led_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &rgb_led_v2->tfp, TF_RGB_LED_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    rgb_led_v2->tfp->device = rgb_led_v2;
    rgb_led_v2->tfp->uid = numeric_uid;
    rgb_led_v2->tfp->cb_handler = tf_rgb_led_v2_callback_handler;
    rgb_led_v2->response_expected[0] = 0x00;
    return TF_E_OK;
}

int tf_rgb_led_v2_destroy(TF_RGBLEDV2 *rgb_led_v2) {
    int result = tf_tfp_destroy(rgb_led_v2->tfp);
    rgb_led_v2->tfp = NULL;
    return result;
}

int tf_rgb_led_v2_get_response_expected(TF_RGBLEDV2 *rgb_led_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_RGB_LED_V2_FUNCTION_SET_RGB_VALUE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_RGB_LED_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_RGB_LED_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_RGB_LED_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_RGB_LED_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_rgb_led_v2_set_response_expected(TF_RGBLEDV2 *rgb_led_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_RGB_LED_V2_FUNCTION_SET_RGB_VALUE:
            if (response_expected) {
                rgb_led_v2->response_expected[0] |= (1 << 0);
            } else {
                rgb_led_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_RGB_LED_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                rgb_led_v2->response_expected[0] |= (1 << 1);
            } else {
                rgb_led_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_RGB_LED_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                rgb_led_v2->response_expected[0] |= (1 << 2);
            } else {
                rgb_led_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_RGB_LED_V2_FUNCTION_RESET:
            if (response_expected) {
                rgb_led_v2->response_expected[0] |= (1 << 3);
            } else {
                rgb_led_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_RGB_LED_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                rgb_led_v2->response_expected[0] |= (1 << 4);
            } else {
                rgb_led_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_rgb_led_v2_set_response_expected_all(TF_RGBLEDV2 *rgb_led_v2, bool response_expected) {
    memset(rgb_led_v2->response_expected, response_expected ? 0xFF : 0, 1);
}

int tf_rgb_led_v2_set_rgb_value(TF_RGBLEDV2 *rgb_led_v2, uint8_t r, uint8_t g, uint8_t b) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_v2_get_response_expected(rgb_led_v2, TF_RGB_LED_V2_FUNCTION_SET_RGB_VALUE, &response_expected);
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_SET_RGB_VALUE, 3, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_v2->tfp);

    buf[0] = (uint8_t)r;
    buf[1] = (uint8_t)g;
    buf[2] = (uint8_t)b;

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_get_rgb_value(TF_RGBLEDV2 *rgb_led_v2, uint8_t *ret_r, uint8_t *ret_g, uint8_t *ret_b) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_GET_RGB_VALUE, 0, 3, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_r != NULL) { *ret_r = tf_packetbuffer_read_uint8_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_g != NULL) { *ret_g = tf_packetbuffer_read_uint8_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_b != NULL) { *ret_b = tf_packetbuffer_read_uint8_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rgb_led_v2->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_get_spitfp_error_count(TF_RGBLEDV2 *rgb_led_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(rgb_led_v2->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_set_bootloader_mode(TF_RGBLEDV2 *rgb_led_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rgb_led_v2->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_get_bootloader_mode(TF_RGBLEDV2 *rgb_led_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rgb_led_v2->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_set_write_firmware_pointer(TF_RGBLEDV2 *rgb_led_v2, uint32_t pointer) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_v2_get_response_expected(rgb_led_v2, TF_RGB_LED_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_write_firmware(TF_RGBLEDV2 *rgb_led_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rgb_led_v2->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_set_status_led_config(TF_RGBLEDV2 *rgb_led_v2, uint8_t config) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_v2_get_response_expected(rgb_led_v2, TF_RGB_LED_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_get_status_led_config(TF_RGBLEDV2 *rgb_led_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rgb_led_v2->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_get_chip_temperature(TF_RGBLEDV2 *rgb_led_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(rgb_led_v2->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_reset(TF_RGBLEDV2 *rgb_led_v2) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_v2_get_response_expected(rgb_led_v2, TF_RGB_LED_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_write_uid(TF_RGBLEDV2 *rgb_led_v2, uint32_t uid) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_v2_get_response_expected(rgb_led_v2, TF_RGB_LED_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_read_uid(TF_RGBLEDV2 *rgb_led_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(rgb_led_v2->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_v2_get_identity(TF_RGBLEDV2 *rgb_led_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(rgb_led_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_v2->tfp, TF_RGB_LED_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(rgb_led_v2->tfp->hal) + tf_hal_get_common(rgb_led_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&rgb_led_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&rgb_led_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&rgb_led_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&rgb_led_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&rgb_led_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(rgb_led_v2->tfp->hal, rgb_led_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(rgb_led_v2->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}


int tf_rgb_led_v2_callback_tick(TF_RGBLEDV2 *rgb_led_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(rgb_led_v2->tfp, tf_hal_current_time_us(rgb_led_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
