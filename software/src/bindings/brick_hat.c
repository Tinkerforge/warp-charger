/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "brick_hat.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_hat_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_HAT *hat = (TF_HAT *) dev;
    (void)payload;

    switch(fid) {

        case TF_HAT_CALLBACK_VOLTAGES: {
            TF_HATVoltagesHandler fn = hat->voltages_handler;
            void *user_data = hat->voltages_user_data;
            if (fn == NULL)
                return false;

            uint16_t voltage_usb = tf_packetbuffer_read_uint16_t(payload);
            uint16_t voltage_dc = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(hat->tfp->hal);
            common->locked = true;
            fn(hat, voltage_usb, voltage_dc, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_hat_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_hat_create(TF_HAT *hat, const char *uid, TF_HalContext *hal) {
    memset(hat, 0, sizeof(TF_HAT));

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

    //rc = tf_tfp_init(hat->tfp, numeric_uid, TF_HAT_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_hat_callback_handler);
    rc = tf_hal_get_tfp(hal, &hat->tfp, TF_HAT_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    hat->tfp->device = hat;
    hat->tfp->uid = numeric_uid;
    hat->tfp->cb_handler = tf_hat_callback_handler;
    hat->response_expected[0] = 0x04;
    return TF_E_OK;
}

int tf_hat_destroy(TF_HAT *hat) {
    int result = tf_tfp_destroy(hat->tfp);
    hat->tfp = NULL;
    return result;
}

int tf_hat_get_response_expected(TF_HAT *hat, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_HAT_FUNCTION_SET_SLEEP_MODE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (hat->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_HAT_FUNCTION_SET_BRICKLET_POWER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (hat->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_HAT_FUNCTION_SET_VOLTAGES_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (hat->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_HAT_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (hat->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_HAT_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (hat->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_HAT_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (hat->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_HAT_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (hat->response_expected[0] & (1 << 6)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_hat_set_response_expected(TF_HAT *hat, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_HAT_FUNCTION_SET_SLEEP_MODE:
            if (response_expected) {
                hat->response_expected[0] |= (1 << 0);
            } else {
                hat->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_HAT_FUNCTION_SET_BRICKLET_POWER:
            if (response_expected) {
                hat->response_expected[0] |= (1 << 1);
            } else {
                hat->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_HAT_FUNCTION_SET_VOLTAGES_CALLBACK_CONFIGURATION:
            if (response_expected) {
                hat->response_expected[0] |= (1 << 2);
            } else {
                hat->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_HAT_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                hat->response_expected[0] |= (1 << 3);
            } else {
                hat->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_HAT_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                hat->response_expected[0] |= (1 << 4);
            } else {
                hat->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_HAT_FUNCTION_RESET:
            if (response_expected) {
                hat->response_expected[0] |= (1 << 5);
            } else {
                hat->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_HAT_FUNCTION_WRITE_UID:
            if (response_expected) {
                hat->response_expected[0] |= (1 << 6);
            } else {
                hat->response_expected[0] &= ~(1 << 6);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_hat_set_response_expected_all(TF_HAT *hat, bool response_expected) {
    memset(hat->response_expected, response_expected ? 0xFF : 0, 1);
}

int tf_hat_set_sleep_mode(TF_HAT *hat, uint32_t power_off_delay, uint32_t power_off_duration, bool raspberry_pi_off, bool bricklets_off, bool enable_sleep_indicator) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_hat_get_response_expected(hat, TF_HAT_FUNCTION_SET_SLEEP_MODE, &response_expected);
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_SET_SLEEP_MODE, 11, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(hat->tfp);

    power_off_delay = tf_leconvert_uint32_to(power_off_delay); memcpy(buf + 0, &power_off_delay, 4);
    power_off_duration = tf_leconvert_uint32_to(power_off_duration); memcpy(buf + 4, &power_off_duration, 4);
    buf[8] = raspberry_pi_off ? 1 : 0;
    buf[9] = bricklets_off ? 1 : 0;
    buf[10] = enable_sleep_indicator ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_get_sleep_mode(TF_HAT *hat, uint32_t *ret_power_off_delay, uint32_t *ret_power_off_duration, bool *ret_raspberry_pi_off, bool *ret_bricklets_off, bool *ret_enable_sleep_indicator) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_GET_SLEEP_MODE, 0, 11, response_expected);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_power_off_delay != NULL) { *ret_power_off_delay = tf_packetbuffer_read_uint32_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 4); }
        if (ret_power_off_duration != NULL) { *ret_power_off_duration = tf_packetbuffer_read_uint32_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 4); }
        if (ret_raspberry_pi_off != NULL) { *ret_raspberry_pi_off = tf_packetbuffer_read_bool(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 1); }
        if (ret_bricklets_off != NULL) { *ret_bricklets_off = tf_packetbuffer_read_bool(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 1); }
        if (ret_enable_sleep_indicator != NULL) { *ret_enable_sleep_indicator = tf_packetbuffer_read_bool(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(hat->tfp);
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_set_bricklet_power(TF_HAT *hat, bool bricklet_power) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_hat_get_response_expected(hat, TF_HAT_FUNCTION_SET_BRICKLET_POWER, &response_expected);
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_SET_BRICKLET_POWER, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(hat->tfp);

    buf[0] = bricklet_power ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_get_bricklet_power(TF_HAT *hat, bool *ret_bricklet_power) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_GET_BRICKLET_POWER, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_bricklet_power != NULL) { *ret_bricklet_power = tf_packetbuffer_read_bool(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(hat->tfp);
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_get_voltages(TF_HAT *hat, uint16_t *ret_voltage_usb, uint16_t *ret_voltage_dc) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_GET_VOLTAGES, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_voltage_usb != NULL) { *ret_voltage_usb = tf_packetbuffer_read_uint16_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 2); }
        if (ret_voltage_dc != NULL) { *ret_voltage_dc = tf_packetbuffer_read_uint16_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(hat->tfp);
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_set_voltages_callback_configuration(TF_HAT *hat, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_hat_get_response_expected(hat, TF_HAT_FUNCTION_SET_VOLTAGES_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_SET_VOLTAGES_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(hat->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_get_voltages_callback_configuration(TF_HAT *hat, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_GET_VOLTAGES_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(hat->tfp);
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_get_spitfp_error_count(TF_HAT *hat, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(hat->tfp);
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_set_bootloader_mode(TF_HAT *hat, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(hat->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(hat->tfp);
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_get_bootloader_mode(TF_HAT *hat, uint8_t *ret_mode) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(hat->tfp);
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_set_write_firmware_pointer(TF_HAT *hat, uint32_t pointer) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_hat_get_response_expected(hat, TF_HAT_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(hat->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_write_firmware(TF_HAT *hat, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(hat->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(hat->tfp);
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_set_status_led_config(TF_HAT *hat, uint8_t config) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_hat_get_response_expected(hat, TF_HAT_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(hat->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_get_status_led_config(TF_HAT *hat, uint8_t *ret_config) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(hat->tfp);
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_get_chip_temperature(TF_HAT *hat, int16_t *ret_temperature) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(hat->tfp);
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_reset(TF_HAT *hat) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_hat_get_response_expected(hat, TF_HAT_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_write_uid(TF_HAT *hat, uint32_t uid) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_hat_get_response_expected(hat, TF_HAT_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(hat->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_read_uid(TF_HAT *hat, uint32_t *ret_uid) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(hat->tfp);
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_hat_get_identity(TF_HAT *hat, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(hat->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(hat->tfp, TF_HAT_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(hat->tfp->hal) + tf_hal_get_common(hat->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(hat->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&hat->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&hat->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&hat->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&hat->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&hat->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&hat->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(hat->tfp->hal, hat->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(hat->tfp);
    }

    result = tf_tfp_finish_send(hat->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_hat_register_voltages_callback(TF_HAT *hat, TF_HATVoltagesHandler handler, void *user_data) {
    if (handler == NULL) {
        hat->tfp->needs_callback_tick = false;
        
    } else {
        hat->tfp->needs_callback_tick = true;
    }
    hat->voltages_handler = handler;
    hat->voltages_user_data = user_data;
}
#endif
int tf_hat_callback_tick(TF_HAT *hat, uint32_t timeout_us) {
    return tf_tfp_callback_tick(hat->tfp, tf_hal_current_time_us(hat->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
