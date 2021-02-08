/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_rgb_led_matrix.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_rgb_led_matrix_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_RGBLEDMatrix *rgb_led_matrix = (TF_RGBLEDMatrix *) dev;
    (void)payload;

    switch(fid) {

        case TF_RGB_LED_MATRIX_CALLBACK_FRAME_STARTED: {
            TF_RGBLEDMatrixFrameStartedHandler fn = rgb_led_matrix->frame_started_handler;
            void *user_data = rgb_led_matrix->frame_started_user_data;
            if (fn == NULL)
                return false;

            uint32_t frame_number = tf_packetbuffer_read_uint32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rgb_led_matrix->tfp->hal);
            common->locked = true;
            fn(rgb_led_matrix, frame_number, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_rgb_led_matrix_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_rgb_led_matrix_create(TF_RGBLEDMatrix *rgb_led_matrix, const char *uid, TF_HalContext *hal) {
    memset(rgb_led_matrix, 0, sizeof(TF_RGBLEDMatrix));

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

    //rc = tf_tfp_init(rgb_led_matrix->tfp, numeric_uid, TF_RGB_LED_MATRIX_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_rgb_led_matrix_callback_handler);
    rc = tf_hal_get_tfp(hal, &rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    rgb_led_matrix->tfp->device = rgb_led_matrix;
    rgb_led_matrix->tfp->uid = numeric_uid;
    rgb_led_matrix->tfp->cb_handler = tf_rgb_led_matrix_callback_handler;
    rgb_led_matrix->response_expected[0] = 0x00;
    rgb_led_matrix->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_rgb_led_matrix_destroy(TF_RGBLEDMatrix *rgb_led_matrix) {
    int result = tf_tfp_destroy(rgb_led_matrix->tfp);
    rgb_led_matrix->tfp = NULL;
    return result;
}

int tf_rgb_led_matrix_get_response_expected(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_RGB_LED_MATRIX_FUNCTION_SET_RED:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_matrix->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_SET_GREEN:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_matrix->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_SET_BLUE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_matrix->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_SET_FRAME_DURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_matrix->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_DRAW_FRAME:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_matrix->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_matrix->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_matrix->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_matrix->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_matrix->response_expected[1] & (1 << 0)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_rgb_led_matrix_set_response_expected(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_RGB_LED_MATRIX_FUNCTION_SET_RED:
            if (response_expected) {
                rgb_led_matrix->response_expected[0] |= (1 << 0);
            } else {
                rgb_led_matrix->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_SET_GREEN:
            if (response_expected) {
                rgb_led_matrix->response_expected[0] |= (1 << 1);
            } else {
                rgb_led_matrix->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_SET_BLUE:
            if (response_expected) {
                rgb_led_matrix->response_expected[0] |= (1 << 2);
            } else {
                rgb_led_matrix->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_SET_FRAME_DURATION:
            if (response_expected) {
                rgb_led_matrix->response_expected[0] |= (1 << 3);
            } else {
                rgb_led_matrix->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_DRAW_FRAME:
            if (response_expected) {
                rgb_led_matrix->response_expected[0] |= (1 << 4);
            } else {
                rgb_led_matrix->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                rgb_led_matrix->response_expected[0] |= (1 << 5);
            } else {
                rgb_led_matrix->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                rgb_led_matrix->response_expected[0] |= (1 << 6);
            } else {
                rgb_led_matrix->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_RESET:
            if (response_expected) {
                rgb_led_matrix->response_expected[0] |= (1 << 7);
            } else {
                rgb_led_matrix->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_RGB_LED_MATRIX_FUNCTION_WRITE_UID:
            if (response_expected) {
                rgb_led_matrix->response_expected[1] |= (1 << 0);
            } else {
                rgb_led_matrix->response_expected[1] &= ~(1 << 0);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_rgb_led_matrix_set_response_expected_all(TF_RGBLEDMatrix *rgb_led_matrix, bool response_expected) {
    memset(rgb_led_matrix->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_rgb_led_matrix_set_red(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t red[64]) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_matrix_get_response_expected(rgb_led_matrix, TF_RGB_LED_MATRIX_FUNCTION_SET_RED, &response_expected);
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_SET_RED, 64, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_matrix->tfp);

    memcpy(buf + 0, red, 64);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_get_red(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t ret_red[64]) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_GET_RED, 0, 64, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_red != NULL) { for (i = 0; i < 64; ++i) ret_red[i] = tf_packetbuffer_read_uint8_t(&rgb_led_matrix->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 64); }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_set_green(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t green[64]) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_matrix_get_response_expected(rgb_led_matrix, TF_RGB_LED_MATRIX_FUNCTION_SET_GREEN, &response_expected);
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_SET_GREEN, 64, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_matrix->tfp);

    memcpy(buf + 0, green, 64);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_get_green(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t ret_green[64]) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_GET_GREEN, 0, 64, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_green != NULL) { for (i = 0; i < 64; ++i) ret_green[i] = tf_packetbuffer_read_uint8_t(&rgb_led_matrix->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 64); }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_set_blue(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t blue[64]) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_matrix_get_response_expected(rgb_led_matrix, TF_RGB_LED_MATRIX_FUNCTION_SET_BLUE, &response_expected);
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_SET_BLUE, 64, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_matrix->tfp);

    memcpy(buf + 0, blue, 64);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_get_blue(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t ret_blue[64]) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_GET_BLUE, 0, 64, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_blue != NULL) { for (i = 0; i < 64; ++i) ret_blue[i] = tf_packetbuffer_read_uint8_t(&rgb_led_matrix->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 64); }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_set_frame_duration(TF_RGBLEDMatrix *rgb_led_matrix, uint16_t frame_duration) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_matrix_get_response_expected(rgb_led_matrix, TF_RGB_LED_MATRIX_FUNCTION_SET_FRAME_DURATION, &response_expected);
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_SET_FRAME_DURATION, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_matrix->tfp);

    frame_duration = tf_leconvert_uint16_to(frame_duration); memcpy(buf + 0, &frame_duration, 2);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_get_frame_duration(TF_RGBLEDMatrix *rgb_led_matrix, uint16_t *ret_frame_duration) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_GET_FRAME_DURATION, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_frame_duration != NULL) { *ret_frame_duration = tf_packetbuffer_read_uint16_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_draw_frame(TF_RGBLEDMatrix *rgb_led_matrix) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_matrix_get_response_expected(rgb_led_matrix, TF_RGB_LED_MATRIX_FUNCTION_DRAW_FRAME, &response_expected);
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_DRAW_FRAME, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_get_supply_voltage(TF_RGBLEDMatrix *rgb_led_matrix, uint16_t *ret_voltage) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_GET_SUPPLY_VOLTAGE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_voltage != NULL) { *ret_voltage = tf_packetbuffer_read_uint16_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_get_spitfp_error_count(TF_RGBLEDMatrix *rgb_led_matrix, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_set_bootloader_mode(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_matrix->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_get_bootloader_mode(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t *ret_mode) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_set_write_firmware_pointer(TF_RGBLEDMatrix *rgb_led_matrix, uint32_t pointer) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_matrix_get_response_expected(rgb_led_matrix, TF_RGB_LED_MATRIX_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_matrix->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_write_firmware(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_matrix->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_set_status_led_config(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t config) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_matrix_get_response_expected(rgb_led_matrix, TF_RGB_LED_MATRIX_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_matrix->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_get_status_led_config(TF_RGBLEDMatrix *rgb_led_matrix, uint8_t *ret_config) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_get_chip_temperature(TF_RGBLEDMatrix *rgb_led_matrix, int16_t *ret_temperature) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_reset(TF_RGBLEDMatrix *rgb_led_matrix) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_matrix_get_response_expected(rgb_led_matrix, TF_RGB_LED_MATRIX_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_write_uid(TF_RGBLEDMatrix *rgb_led_matrix, uint32_t uid) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_matrix_get_response_expected(rgb_led_matrix, TF_RGB_LED_MATRIX_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rgb_led_matrix->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_read_uid(TF_RGBLEDMatrix *rgb_led_matrix, uint32_t *ret_uid) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_matrix_get_identity(TF_RGBLEDMatrix *rgb_led_matrix, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(rgb_led_matrix->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rgb_led_matrix->tfp, TF_RGB_LED_MATRIX_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + tf_hal_get_common(rgb_led_matrix->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rgb_led_matrix->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&rgb_led_matrix->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&rgb_led_matrix->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&rgb_led_matrix->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&rgb_led_matrix->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&rgb_led_matrix->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rgb_led_matrix->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(rgb_led_matrix->tfp->hal, rgb_led_matrix->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(rgb_led_matrix->tfp);
    }

    result = tf_tfp_finish_send(rgb_led_matrix->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_rgb_led_matrix_register_frame_started_callback(TF_RGBLEDMatrix *rgb_led_matrix, TF_RGBLEDMatrixFrameStartedHandler handler, void *user_data) {
    if (handler == NULL) {
        rgb_led_matrix->tfp->needs_callback_tick = false;
        
    } else {
        rgb_led_matrix->tfp->needs_callback_tick = true;
    }
    rgb_led_matrix->frame_started_handler = handler;
    rgb_led_matrix->frame_started_user_data = user_data;
}
#endif
int tf_rgb_led_matrix_callback_tick(TF_RGBLEDMatrix *rgb_led_matrix, uint32_t timeout_us) {
    return tf_tfp_callback_tick(rgb_led_matrix->tfp, tf_hal_current_time_us(rgb_led_matrix->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
