/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_led_strip_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_led_strip_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_LEDStripV2 *led_strip_v2 = (TF_LEDStripV2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_LED_STRIP_V2_CALLBACK_FRAME_STARTED: {
            TF_LEDStripV2FrameStartedHandler fn = led_strip_v2->frame_started_handler;
            void *user_data = led_strip_v2->frame_started_user_data;
            if (fn == NULL)
                return false;

            uint16_t length = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(led_strip_v2->tfp->hal);
            common->locked = true;
            fn(led_strip_v2, length, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_led_strip_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_led_strip_v2_create(TF_LEDStripV2 *led_strip_v2, const char *uid, TF_HalContext *hal) {
    memset(led_strip_v2, 0, sizeof(TF_LEDStripV2));

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

    //rc = tf_tfp_init(led_strip_v2->tfp, numeric_uid, TF_LED_STRIP_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_led_strip_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &led_strip_v2->tfp, TF_LED_STRIP_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    led_strip_v2->tfp->device = led_strip_v2;
    led_strip_v2->tfp->uid = numeric_uid;
    led_strip_v2->tfp->cb_handler = tf_led_strip_v2_callback_handler;
    led_strip_v2->response_expected[0] = 0x21;
    led_strip_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_led_strip_v2_destroy(TF_LEDStripV2 *led_strip_v2) {
    int result = tf_tfp_destroy(led_strip_v2->tfp);
    led_strip_v2->tfp = NULL;
    return result;
}

int tf_led_strip_v2_get_response_expected(TF_LEDStripV2 *led_strip_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_LED_STRIP_V2_FUNCTION_SET_LED_VALUES_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (led_strip_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_FRAME_DURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (led_strip_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_CLOCK_FREQUENCY:
            if(ret_response_expected != NULL)
                *ret_response_expected = (led_strip_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_CHIP_TYPE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (led_strip_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_CHANNEL_MAPPING:
            if(ret_response_expected != NULL)
                *ret_response_expected = (led_strip_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_FRAME_STARTED_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (led_strip_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (led_strip_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (led_strip_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_LED_STRIP_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (led_strip_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_LED_STRIP_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (led_strip_v2->response_expected[1] & (1 << 1)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_led_strip_v2_set_response_expected(TF_LEDStripV2 *led_strip_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_LED_STRIP_V2_FUNCTION_SET_LED_VALUES_LOW_LEVEL:
            if (response_expected) {
                led_strip_v2->response_expected[0] |= (1 << 0);
            } else {
                led_strip_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_FRAME_DURATION:
            if (response_expected) {
                led_strip_v2->response_expected[0] |= (1 << 1);
            } else {
                led_strip_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_CLOCK_FREQUENCY:
            if (response_expected) {
                led_strip_v2->response_expected[0] |= (1 << 2);
            } else {
                led_strip_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_CHIP_TYPE:
            if (response_expected) {
                led_strip_v2->response_expected[0] |= (1 << 3);
            } else {
                led_strip_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_CHANNEL_MAPPING:
            if (response_expected) {
                led_strip_v2->response_expected[0] |= (1 << 4);
            } else {
                led_strip_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_FRAME_STARTED_CALLBACK_CONFIGURATION:
            if (response_expected) {
                led_strip_v2->response_expected[0] |= (1 << 5);
            } else {
                led_strip_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                led_strip_v2->response_expected[0] |= (1 << 6);
            } else {
                led_strip_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_LED_STRIP_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                led_strip_v2->response_expected[0] |= (1 << 7);
            } else {
                led_strip_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_LED_STRIP_V2_FUNCTION_RESET:
            if (response_expected) {
                led_strip_v2->response_expected[1] |= (1 << 0);
            } else {
                led_strip_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_LED_STRIP_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                led_strip_v2->response_expected[1] |= (1 << 1);
            } else {
                led_strip_v2->response_expected[1] &= ~(1 << 1);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_led_strip_v2_set_response_expected_all(TF_LEDStripV2 *led_strip_v2, bool response_expected) {
    memset(led_strip_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_led_strip_v2_set_led_values_low_level(TF_LEDStripV2 *led_strip_v2, uint16_t index, uint16_t value_length, uint16_t value_chunk_offset, uint8_t value_chunk_data[58]) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_led_strip_v2_get_response_expected(led_strip_v2, TF_LED_STRIP_V2_FUNCTION_SET_LED_VALUES_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_SET_LED_VALUES_LOW_LEVEL, 64, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(led_strip_v2->tfp);

    index = tf_leconvert_uint16_to(index); memcpy(buf + 0, &index, 2);
    value_length = tf_leconvert_uint16_to(value_length); memcpy(buf + 2, &value_length, 2);
    value_chunk_offset = tf_leconvert_uint16_to(value_chunk_offset); memcpy(buf + 4, &value_chunk_offset, 2);
    memcpy(buf + 6, value_chunk_data, 58);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_get_led_values_low_level(TF_LEDStripV2 *led_strip_v2, uint16_t index, uint16_t length, uint16_t *ret_value_length, uint16_t *ret_value_chunk_offset, uint8_t ret_value_chunk_data[60]) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_GET_LED_VALUES_LOW_LEVEL, 4, 64, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(led_strip_v2->tfp);

    index = tf_leconvert_uint16_to(index); memcpy(buf + 0, &index, 2);
    length = tf_leconvert_uint16_to(length); memcpy(buf + 2, &length, 2);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_value_length != NULL) { *ret_value_length = tf_packetbuffer_read_uint16_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_value_chunk_offset != NULL) { *ret_value_chunk_offset = tf_packetbuffer_read_uint16_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_value_chunk_data != NULL) { for (i = 0; i < 60; ++i) ret_value_chunk_data[i] = tf_packetbuffer_read_uint8_t(&led_strip_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 60); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_set_frame_duration(TF_LEDStripV2 *led_strip_v2, uint16_t duration) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_led_strip_v2_get_response_expected(led_strip_v2, TF_LED_STRIP_V2_FUNCTION_SET_FRAME_DURATION, &response_expected);
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_SET_FRAME_DURATION, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(led_strip_v2->tfp);

    duration = tf_leconvert_uint16_to(duration); memcpy(buf + 0, &duration, 2);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_get_frame_duration(TF_LEDStripV2 *led_strip_v2, uint16_t *ret_duration) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_GET_FRAME_DURATION, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_duration != NULL) { *ret_duration = tf_packetbuffer_read_uint16_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_get_supply_voltage(TF_LEDStripV2 *led_strip_v2, uint16_t *ret_voltage) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_GET_SUPPLY_VOLTAGE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_voltage != NULL) { *ret_voltage = tf_packetbuffer_read_uint16_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_set_clock_frequency(TF_LEDStripV2 *led_strip_v2, uint32_t frequency) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_led_strip_v2_get_response_expected(led_strip_v2, TF_LED_STRIP_V2_FUNCTION_SET_CLOCK_FREQUENCY, &response_expected);
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_SET_CLOCK_FREQUENCY, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(led_strip_v2->tfp);

    frequency = tf_leconvert_uint32_to(frequency); memcpy(buf + 0, &frequency, 4);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_get_clock_frequency(TF_LEDStripV2 *led_strip_v2, uint32_t *ret_frequency) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_GET_CLOCK_FREQUENCY, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_frequency != NULL) { *ret_frequency = tf_packetbuffer_read_uint32_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_set_chip_type(TF_LEDStripV2 *led_strip_v2, uint16_t chip) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_led_strip_v2_get_response_expected(led_strip_v2, TF_LED_STRIP_V2_FUNCTION_SET_CHIP_TYPE, &response_expected);
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_SET_CHIP_TYPE, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(led_strip_v2->tfp);

    chip = tf_leconvert_uint16_to(chip); memcpy(buf + 0, &chip, 2);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_get_chip_type(TF_LEDStripV2 *led_strip_v2, uint16_t *ret_chip) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_GET_CHIP_TYPE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_chip != NULL) { *ret_chip = tf_packetbuffer_read_uint16_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_set_channel_mapping(TF_LEDStripV2 *led_strip_v2, uint8_t mapping) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_led_strip_v2_get_response_expected(led_strip_v2, TF_LED_STRIP_V2_FUNCTION_SET_CHANNEL_MAPPING, &response_expected);
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_SET_CHANNEL_MAPPING, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(led_strip_v2->tfp);

    buf[0] = (uint8_t)mapping;

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_get_channel_mapping(TF_LEDStripV2 *led_strip_v2, uint8_t *ret_mapping) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_GET_CHANNEL_MAPPING, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mapping != NULL) { *ret_mapping = tf_packetbuffer_read_uint8_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_set_frame_started_callback_configuration(TF_LEDStripV2 *led_strip_v2, bool enable) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_led_strip_v2_get_response_expected(led_strip_v2, TF_LED_STRIP_V2_FUNCTION_SET_FRAME_STARTED_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_SET_FRAME_STARTED_CALLBACK_CONFIGURATION, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(led_strip_v2->tfp);

    buf[0] = enable ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_get_frame_started_callback_configuration(TF_LEDStripV2 *led_strip_v2, bool *ret_enable) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_GET_FRAME_STARTED_CALLBACK_CONFIGURATION, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enable != NULL) { *ret_enable = tf_packetbuffer_read_bool(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_get_spitfp_error_count(TF_LEDStripV2 *led_strip_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_set_bootloader_mode(TF_LEDStripV2 *led_strip_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(led_strip_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_get_bootloader_mode(TF_LEDStripV2 *led_strip_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_set_write_firmware_pointer(TF_LEDStripV2 *led_strip_v2, uint32_t pointer) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_led_strip_v2_get_response_expected(led_strip_v2, TF_LED_STRIP_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(led_strip_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_write_firmware(TF_LEDStripV2 *led_strip_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(led_strip_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_set_status_led_config(TF_LEDStripV2 *led_strip_v2, uint8_t config) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_led_strip_v2_get_response_expected(led_strip_v2, TF_LED_STRIP_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(led_strip_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_get_status_led_config(TF_LEDStripV2 *led_strip_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_get_chip_temperature(TF_LEDStripV2 *led_strip_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_reset(TF_LEDStripV2 *led_strip_v2) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_led_strip_v2_get_response_expected(led_strip_v2, TF_LED_STRIP_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_write_uid(TF_LEDStripV2 *led_strip_v2, uint32_t uid) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_led_strip_v2_get_response_expected(led_strip_v2, TF_LED_STRIP_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(led_strip_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_read_uid(TF_LEDStripV2 *led_strip_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_get_identity(TF_LEDStripV2 *led_strip_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(led_strip_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(led_strip_v2->tfp, TF_LED_STRIP_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(led_strip_v2->tfp->hal) + tf_hal_get_common(led_strip_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(led_strip_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&led_strip_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&led_strip_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&led_strip_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&led_strip_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&led_strip_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&led_strip_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(led_strip_v2->tfp->hal, led_strip_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(led_strip_v2->tfp);
    }

    result = tf_tfp_finish_send(led_strip_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_led_strip_v2_set_led_values(TF_LEDStripV2 *led_strip_v2, uint16_t index, uint8_t *value, uint16_t value_length) {
    int ret = TF_E_OK;
    uint16_t value_chunk_offset = 0;
    uint8_t value_chunk_data[58];
    uint16_t value_chunk_length = 0;

    if (value_length == 0) {
        memset(&value_chunk_data, 0, sizeof(uint8_t) * 58);

        ret = tf_led_strip_v2_set_led_values_low_level(led_strip_v2, index, value_length, value_chunk_offset, value_chunk_data);
    } else {

        while (value_chunk_offset < value_length) {
            value_chunk_length = value_length - value_chunk_offset;

            if (value_chunk_length > 58) {
                value_chunk_length = 58;
            }

            memcpy(value_chunk_data, &value[value_chunk_offset], sizeof(uint8_t) * value_chunk_length);
            memset(&value_chunk_data[value_chunk_length], 0, sizeof(uint8_t) * (58 - value_chunk_length));

            ret = tf_led_strip_v2_set_led_values_low_level(led_strip_v2, index, value_length, value_chunk_offset, value_chunk_data);

            if (ret != TF_E_OK) {
                break;
            }

            value_chunk_offset += 58;
        }

    }

    return ret;
}

int tf_led_strip_v2_get_led_values(TF_LEDStripV2 *led_strip_v2, uint16_t index, uint16_t length, uint8_t *ret_value, uint16_t *ret_value_length) {
    int ret = TF_E_OK;
    uint16_t value_length = 0;
    uint16_t value_chunk_offset = 0;
    uint8_t value_chunk_data[60];
    bool value_out_of_sync;
    uint16_t value_chunk_length = 0;

    *ret_value_length = 0;

    ret = tf_led_strip_v2_get_led_values_low_level(led_strip_v2, index, length, &value_length, &value_chunk_offset, value_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    value_out_of_sync = value_chunk_offset != 0;

    if (!value_out_of_sync) {
        value_chunk_length = value_length - value_chunk_offset;

        if (value_chunk_length > 60) {
            value_chunk_length = 60;
        }

        memcpy(ret_value, value_chunk_data, sizeof(uint8_t) * value_chunk_length);
        *ret_value_length = value_chunk_length;

        while (*ret_value_length < value_length) {
            ret = tf_led_strip_v2_get_led_values_low_level(led_strip_v2, index, length, &value_length, &value_chunk_offset, value_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            value_out_of_sync = value_chunk_offset != *ret_value_length;

            if (value_out_of_sync) {
                break;
            }

            value_chunk_length = value_length - value_chunk_offset;

            if (value_chunk_length > 60) {
                value_chunk_length = 60;
            }

            memcpy(&ret_value[*ret_value_length], value_chunk_data, sizeof(uint8_t) * value_chunk_length);
            *ret_value_length += value_chunk_length;
        }
    }

    if (value_out_of_sync) {
        *ret_value_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (value_chunk_offset + 60 < value_length) {
            ret = tf_led_strip_v2_get_led_values_low_level(led_strip_v2, index, length, &value_length, &value_chunk_offset, value_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_led_strip_v2_register_frame_started_callback(TF_LEDStripV2 *led_strip_v2, TF_LEDStripV2FrameStartedHandler handler, void *user_data) {
    if (handler == NULL) {
        led_strip_v2->tfp->needs_callback_tick = false;
        
    } else {
        led_strip_v2->tfp->needs_callback_tick = true;
    }
    led_strip_v2->frame_started_handler = handler;
    led_strip_v2->frame_started_user_data = user_data;
}
#endif
int tf_led_strip_v2_callback_tick(TF_LEDStripV2 *led_strip_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(led_strip_v2->tfp, tf_hal_current_time_us(led_strip_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
