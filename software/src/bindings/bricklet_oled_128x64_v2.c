/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_oled_128x64_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


static bool tf_oled_128x64_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    (void)dev;
    (void)fid;
    (void)payload;
    return false;
}
int tf_oled_128x64_v2_create(TF_OLED128x64V2 *oled_128x64_v2, const char *uid, TF_HalContext *hal) {
    memset(oled_128x64_v2, 0, sizeof(TF_OLED128x64V2));

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

    //rc = tf_tfp_init(oled_128x64_v2->tfp, numeric_uid, TF_OLED_128X64_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_oled_128x64_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &oled_128x64_v2->tfp, TF_OLED_128X64_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    oled_128x64_v2->tfp->device = oled_128x64_v2;
    oled_128x64_v2->tfp->uid = numeric_uid;
    oled_128x64_v2->tfp->cb_handler = tf_oled_128x64_v2_callback_handler;
    oled_128x64_v2->response_expected[0] = 0x01;
    oled_128x64_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_oled_128x64_v2_destroy(TF_OLED128x64V2 *oled_128x64_v2) {
    int result = tf_tfp_destroy(oled_128x64_v2->tfp);
    oled_128x64_v2->tfp = NULL;
    return result;
}

int tf_oled_128x64_v2_get_response_expected(TF_OLED128x64V2 *oled_128x64_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_OLED_128X64_V2_FUNCTION_WRITE_PIXELS_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (oled_128x64_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_OLED_128X64_V2_FUNCTION_CLEAR_DISPLAY:
            if(ret_response_expected != NULL)
                *ret_response_expected = (oled_128x64_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_OLED_128X64_V2_FUNCTION_SET_DISPLAY_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (oled_128x64_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_OLED_128X64_V2_FUNCTION_WRITE_LINE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (oled_128x64_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_OLED_128X64_V2_FUNCTION_DRAW_BUFFERED_FRAME:
            if(ret_response_expected != NULL)
                *ret_response_expected = (oled_128x64_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_OLED_128X64_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (oled_128x64_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_OLED_128X64_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (oled_128x64_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_OLED_128X64_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (oled_128x64_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_OLED_128X64_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (oled_128x64_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_oled_128x64_v2_set_response_expected(TF_OLED128x64V2 *oled_128x64_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_OLED_128X64_V2_FUNCTION_WRITE_PIXELS_LOW_LEVEL:
            if (response_expected) {
                oled_128x64_v2->response_expected[0] |= (1 << 0);
            } else {
                oled_128x64_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_OLED_128X64_V2_FUNCTION_CLEAR_DISPLAY:
            if (response_expected) {
                oled_128x64_v2->response_expected[0] |= (1 << 1);
            } else {
                oled_128x64_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_OLED_128X64_V2_FUNCTION_SET_DISPLAY_CONFIGURATION:
            if (response_expected) {
                oled_128x64_v2->response_expected[0] |= (1 << 2);
            } else {
                oled_128x64_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_OLED_128X64_V2_FUNCTION_WRITE_LINE:
            if (response_expected) {
                oled_128x64_v2->response_expected[0] |= (1 << 3);
            } else {
                oled_128x64_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_OLED_128X64_V2_FUNCTION_DRAW_BUFFERED_FRAME:
            if (response_expected) {
                oled_128x64_v2->response_expected[0] |= (1 << 4);
            } else {
                oled_128x64_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_OLED_128X64_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                oled_128x64_v2->response_expected[0] |= (1 << 5);
            } else {
                oled_128x64_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_OLED_128X64_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                oled_128x64_v2->response_expected[0] |= (1 << 6);
            } else {
                oled_128x64_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_OLED_128X64_V2_FUNCTION_RESET:
            if (response_expected) {
                oled_128x64_v2->response_expected[0] |= (1 << 7);
            } else {
                oled_128x64_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_OLED_128X64_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                oled_128x64_v2->response_expected[1] |= (1 << 0);
            } else {
                oled_128x64_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_oled_128x64_v2_set_response_expected_all(TF_OLED128x64V2 *oled_128x64_v2, bool response_expected) {
    memset(oled_128x64_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_oled_128x64_v2_write_pixels_low_level(TF_OLED128x64V2 *oled_128x64_v2, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, uint16_t pixels_length, uint16_t pixels_chunk_offset, bool pixels_chunk_data[448]) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_oled_128x64_v2_get_response_expected(oled_128x64_v2, TF_OLED_128X64_V2_FUNCTION_WRITE_PIXELS_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_WRITE_PIXELS_LOW_LEVEL, 64, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(oled_128x64_v2->tfp);

    buf[0] = (uint8_t)x_start;
    buf[1] = (uint8_t)y_start;
    buf[2] = (uint8_t)x_end;
    buf[3] = (uint8_t)y_end;
    pixels_length = tf_leconvert_uint16_to(pixels_length); memcpy(buf + 4, &pixels_length, 2);
    pixels_chunk_offset = tf_leconvert_uint16_to(pixels_chunk_offset); memcpy(buf + 6, &pixels_chunk_offset, 2);
    memset(buf + 8, 0, 56); for (i = 0; i < 448; ++i) buf[8 + (i / 8)] |= (pixels_chunk_data[i] ? 1 : 0) << (i % 8);

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_read_pixels_low_level(TF_OLED128x64V2 *oled_128x64_v2, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, uint16_t *ret_pixels_length, uint16_t *ret_pixels_chunk_offset, bool ret_pixels_chunk_data[480]) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_READ_PIXELS_LOW_LEVEL, 4, 64, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(oled_128x64_v2->tfp);

    buf[0] = (uint8_t)x_start;
    buf[1] = (uint8_t)y_start;
    buf[2] = (uint8_t)x_end;
    buf[3] = (uint8_t)y_end;

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_pixels_length != NULL) { *ret_pixels_length = tf_packetbuffer_read_uint16_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_pixels_chunk_offset != NULL) { *ret_pixels_chunk_offset = tf_packetbuffer_read_uint16_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_pixels_chunk_data != NULL) { tf_packetbuffer_read_bool_array(&oled_128x64_v2->tfp->spitfp->recv_buf, ret_pixels_chunk_data, 480);} else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 60); }
        tf_tfp_packet_processed(oled_128x64_v2->tfp);
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_clear_display(TF_OLED128x64V2 *oled_128x64_v2) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_oled_128x64_v2_get_response_expected(oled_128x64_v2, TF_OLED_128X64_V2_FUNCTION_CLEAR_DISPLAY, &response_expected);
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_CLEAR_DISPLAY, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_set_display_configuration(TF_OLED128x64V2 *oled_128x64_v2, uint8_t contrast, bool invert, bool automatic_draw) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_oled_128x64_v2_get_response_expected(oled_128x64_v2, TF_OLED_128X64_V2_FUNCTION_SET_DISPLAY_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_SET_DISPLAY_CONFIGURATION, 3, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(oled_128x64_v2->tfp);

    buf[0] = (uint8_t)contrast;
    buf[1] = invert ? 1 : 0;
    buf[2] = automatic_draw ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_get_display_configuration(TF_OLED128x64V2 *oled_128x64_v2, uint8_t *ret_contrast, bool *ret_invert, bool *ret_automatic_draw) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_GET_DISPLAY_CONFIGURATION, 0, 3, response_expected);

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_contrast != NULL) { *ret_contrast = tf_packetbuffer_read_uint8_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_invert != NULL) { *ret_invert = tf_packetbuffer_read_bool(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_automatic_draw != NULL) { *ret_automatic_draw = tf_packetbuffer_read_bool(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(oled_128x64_v2->tfp);
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_write_line(TF_OLED128x64V2 *oled_128x64_v2, uint8_t line, uint8_t position, const char text[22]) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_oled_128x64_v2_get_response_expected(oled_128x64_v2, TF_OLED_128X64_V2_FUNCTION_WRITE_LINE, &response_expected);
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_WRITE_LINE, 24, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(oled_128x64_v2->tfp);

    buf[0] = (uint8_t)line;
    buf[1] = (uint8_t)position;
    memcpy(buf + 2, text, 22);


    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_draw_buffered_frame(TF_OLED128x64V2 *oled_128x64_v2, bool force_complete_redraw) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_oled_128x64_v2_get_response_expected(oled_128x64_v2, TF_OLED_128X64_V2_FUNCTION_DRAW_BUFFERED_FRAME, &response_expected);
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_DRAW_BUFFERED_FRAME, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(oled_128x64_v2->tfp);

    buf[0] = force_complete_redraw ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_get_spitfp_error_count(TF_OLED128x64V2 *oled_128x64_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(oled_128x64_v2->tfp);
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_set_bootloader_mode(TF_OLED128x64V2 *oled_128x64_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(oled_128x64_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(oled_128x64_v2->tfp);
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_get_bootloader_mode(TF_OLED128x64V2 *oled_128x64_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(oled_128x64_v2->tfp);
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_set_write_firmware_pointer(TF_OLED128x64V2 *oled_128x64_v2, uint32_t pointer) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_oled_128x64_v2_get_response_expected(oled_128x64_v2, TF_OLED_128X64_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(oled_128x64_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_write_firmware(TF_OLED128x64V2 *oled_128x64_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(oled_128x64_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(oled_128x64_v2->tfp);
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_set_status_led_config(TF_OLED128x64V2 *oled_128x64_v2, uint8_t config) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_oled_128x64_v2_get_response_expected(oled_128x64_v2, TF_OLED_128X64_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(oled_128x64_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_get_status_led_config(TF_OLED128x64V2 *oled_128x64_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(oled_128x64_v2->tfp);
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_get_chip_temperature(TF_OLED128x64V2 *oled_128x64_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(oled_128x64_v2->tfp);
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_reset(TF_OLED128x64V2 *oled_128x64_v2) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_oled_128x64_v2_get_response_expected(oled_128x64_v2, TF_OLED_128X64_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_write_uid(TF_OLED128x64V2 *oled_128x64_v2, uint32_t uid) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_oled_128x64_v2_get_response_expected(oled_128x64_v2, TF_OLED_128X64_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(oled_128x64_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_read_uid(TF_OLED128x64V2 *oled_128x64_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(oled_128x64_v2->tfp);
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_get_identity(TF_OLED128x64V2 *oled_128x64_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(oled_128x64_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(oled_128x64_v2->tfp, TF_OLED_128X64_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + tf_hal_get_common(oled_128x64_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(oled_128x64_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&oled_128x64_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&oled_128x64_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&oled_128x64_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&oled_128x64_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&oled_128x64_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&oled_128x64_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(oled_128x64_v2->tfp->hal, oled_128x64_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(oled_128x64_v2->tfp);
    }

    result = tf_tfp_finish_send(oled_128x64_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_oled_128x64_v2_write_pixels(TF_OLED128x64V2 *oled_128x64_v2, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, bool *pixels, uint16_t pixels_length) {
    int ret = TF_E_OK;
    uint16_t pixels_chunk_offset = 0;
    bool pixels_chunk_data[448];
    uint16_t pixels_chunk_length = 0;

    if (pixels_length == 0) {
        memset(&pixels_chunk_data, 0, sizeof(bool) * 448);

        ret = tf_oled_128x64_v2_write_pixels_low_level(oled_128x64_v2, x_start, y_start, x_end, y_end, pixels_length, pixels_chunk_offset, pixels_chunk_data);
    } else {

        while (pixels_chunk_offset < pixels_length) {
            pixels_chunk_length = pixels_length - pixels_chunk_offset;

            if (pixels_chunk_length > 448) {
                pixels_chunk_length = 448;
            }

            memcpy(pixels_chunk_data, &pixels[pixels_chunk_offset], sizeof(bool) * pixels_chunk_length);
            memset(&pixels_chunk_data[pixels_chunk_length], 0, sizeof(bool) * (448 - pixels_chunk_length));

            ret = tf_oled_128x64_v2_write_pixels_low_level(oled_128x64_v2, x_start, y_start, x_end, y_end, pixels_length, pixels_chunk_offset, pixels_chunk_data);

            if (ret != TF_E_OK) {
                break;
            }

            pixels_chunk_offset += 448;
        }

    }

    return ret;
}

int tf_oled_128x64_v2_read_pixels(TF_OLED128x64V2 *oled_128x64_v2, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, bool *ret_pixels, uint16_t *ret_pixels_length) {
    int ret = TF_E_OK;
    uint16_t pixels_length = 0;
    uint16_t pixels_chunk_offset = 0;
    bool pixels_chunk_data[480];
    bool pixels_out_of_sync;
    uint16_t pixels_chunk_length = 0;

    *ret_pixels_length = 0;

    ret = tf_oled_128x64_v2_read_pixels_low_level(oled_128x64_v2, x_start, y_start, x_end, y_end, &pixels_length, &pixels_chunk_offset, pixels_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    pixels_out_of_sync = pixels_chunk_offset != 0;

    if (!pixels_out_of_sync) {
        pixels_chunk_length = pixels_length - pixels_chunk_offset;

        if (pixels_chunk_length > 480) {
            pixels_chunk_length = 480;
        }

        memcpy(ret_pixels, pixels_chunk_data, sizeof(bool) * pixels_chunk_length);
        *ret_pixels_length = pixels_chunk_length;

        while (*ret_pixels_length < pixels_length) {
            ret = tf_oled_128x64_v2_read_pixels_low_level(oled_128x64_v2, x_start, y_start, x_end, y_end, &pixels_length, &pixels_chunk_offset, pixels_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            pixels_out_of_sync = pixels_chunk_offset != *ret_pixels_length;

            if (pixels_out_of_sync) {
                break;
            }

            pixels_chunk_length = pixels_length - pixels_chunk_offset;

            if (pixels_chunk_length > 480) {
                pixels_chunk_length = 480;
            }

            memcpy(&ret_pixels[*ret_pixels_length], pixels_chunk_data, sizeof(bool) * pixels_chunk_length);
            *ret_pixels_length += pixels_chunk_length;
        }
    }

    if (pixels_out_of_sync) {
        *ret_pixels_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (pixels_chunk_offset + 480 < pixels_length) {
            ret = tf_oled_128x64_v2_read_pixels_low_level(oled_128x64_v2, x_start, y_start, x_end, y_end, &pixels_length, &pixels_chunk_offset, pixels_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}


int tf_oled_128x64_v2_callback_tick(TF_OLED128x64V2 *oled_128x64_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(oled_128x64_v2->tfp, tf_hal_current_time_us(oled_128x64_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
