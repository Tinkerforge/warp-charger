/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_servo_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_servo_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_ServoV2 *servo_v2 = (TF_ServoV2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_SERVO_V2_CALLBACK_POSITION_REACHED: {
            TF_ServoV2PositionReachedHandler fn = servo_v2->position_reached_handler;
            void *user_data = servo_v2->position_reached_user_data;
            if (fn == NULL)
                return false;

            uint16_t servo_channel = tf_packetbuffer_read_uint16_t(payload);
            int16_t position = tf_packetbuffer_read_int16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(servo_v2->tfp->hal);
            common->locked = true;
            fn(servo_v2, servo_channel, position, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_servo_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_servo_v2_create(TF_ServoV2 *servo_v2, const char *uid, TF_HalContext *hal) {
    memset(servo_v2, 0, sizeof(TF_ServoV2));

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

    //rc = tf_tfp_init(servo_v2->tfp, numeric_uid, TF_SERVO_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_servo_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &servo_v2->tfp, TF_SERVO_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    servo_v2->tfp->device = servo_v2;
    servo_v2->tfp->uid = numeric_uid;
    servo_v2->tfp->cb_handler = tf_servo_v2_callback_handler;
    servo_v2->response_expected[0] = 0x00;
    servo_v2->response_expected[1] = 0x02;
    return TF_E_OK;
}

int tf_servo_v2_destroy(TF_ServoV2 *servo_v2) {
    int result = tf_tfp_destroy(servo_v2->tfp);
    servo_v2->tfp = NULL;
    return result;
}

int tf_servo_v2_get_response_expected(TF_ServoV2 *servo_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_SERVO_V2_FUNCTION_SET_ENABLE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_SET_POSITION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_SET_MOTION_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_SET_PULSE_WIDTH:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_SET_DEGREE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_SET_PERIOD:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_SET_SERVO_CURRENT_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_SET_INPUT_VOLTAGE_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_SET_CURRENT_CALIBRATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_SET_POSITION_REACHED_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[1] & (1 << 1)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[1] & (1 << 2)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[1] & (1 << 3)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[1] & (1 << 4)) != 0;
            break;
        case TF_SERVO_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (servo_v2->response_expected[1] & (1 << 5)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_servo_v2_set_response_expected(TF_ServoV2 *servo_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_SERVO_V2_FUNCTION_SET_ENABLE:
            if (response_expected) {
                servo_v2->response_expected[0] |= (1 << 0);
            } else {
                servo_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_SERVO_V2_FUNCTION_SET_POSITION:
            if (response_expected) {
                servo_v2->response_expected[0] |= (1 << 1);
            } else {
                servo_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_SERVO_V2_FUNCTION_SET_MOTION_CONFIGURATION:
            if (response_expected) {
                servo_v2->response_expected[0] |= (1 << 2);
            } else {
                servo_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_SERVO_V2_FUNCTION_SET_PULSE_WIDTH:
            if (response_expected) {
                servo_v2->response_expected[0] |= (1 << 3);
            } else {
                servo_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_SERVO_V2_FUNCTION_SET_DEGREE:
            if (response_expected) {
                servo_v2->response_expected[0] |= (1 << 4);
            } else {
                servo_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_SERVO_V2_FUNCTION_SET_PERIOD:
            if (response_expected) {
                servo_v2->response_expected[0] |= (1 << 5);
            } else {
                servo_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_SERVO_V2_FUNCTION_SET_SERVO_CURRENT_CONFIGURATION:
            if (response_expected) {
                servo_v2->response_expected[0] |= (1 << 6);
            } else {
                servo_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_SERVO_V2_FUNCTION_SET_INPUT_VOLTAGE_CONFIGURATION:
            if (response_expected) {
                servo_v2->response_expected[0] |= (1 << 7);
            } else {
                servo_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_SERVO_V2_FUNCTION_SET_CURRENT_CALIBRATION:
            if (response_expected) {
                servo_v2->response_expected[1] |= (1 << 0);
            } else {
                servo_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_SERVO_V2_FUNCTION_SET_POSITION_REACHED_CALLBACK_CONFIGURATION:
            if (response_expected) {
                servo_v2->response_expected[1] |= (1 << 1);
            } else {
                servo_v2->response_expected[1] &= ~(1 << 1);
            }
            break;
        case TF_SERVO_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                servo_v2->response_expected[1] |= (1 << 2);
            } else {
                servo_v2->response_expected[1] &= ~(1 << 2);
            }
            break;
        case TF_SERVO_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                servo_v2->response_expected[1] |= (1 << 3);
            } else {
                servo_v2->response_expected[1] &= ~(1 << 3);
            }
            break;
        case TF_SERVO_V2_FUNCTION_RESET:
            if (response_expected) {
                servo_v2->response_expected[1] |= (1 << 4);
            } else {
                servo_v2->response_expected[1] &= ~(1 << 4);
            }
            break;
        case TF_SERVO_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                servo_v2->response_expected[1] |= (1 << 5);
            } else {
                servo_v2->response_expected[1] &= ~(1 << 5);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_servo_v2_set_response_expected_all(TF_ServoV2 *servo_v2, bool response_expected) {
    memset(servo_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_servo_v2_get_status(TF_ServoV2 *servo_v2, bool ret_enabled[10], int16_t ret_current_position[10], int16_t ret_current_velocity[10], uint16_t ret_current[10], uint16_t *ret_input_voltage) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_STATUS, 0, 64, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { tf_packetbuffer_read_bool_array(&servo_v2->tfp->spitfp->recv_buf, ret_enabled, 10);} else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_current_position != NULL) { for (i = 0; i < 10; ++i) ret_current_position[i] = tf_packetbuffer_read_int16_t(&servo_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 20); }
        if (ret_current_velocity != NULL) { for (i = 0; i < 10; ++i) ret_current_velocity[i] = tf_packetbuffer_read_int16_t(&servo_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 20); }
        if (ret_current != NULL) { for (i = 0; i < 10; ++i) ret_current[i] = tf_packetbuffer_read_uint16_t(&servo_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 20); }
        if (ret_input_voltage != NULL) { *ret_input_voltage = tf_packetbuffer_read_uint16_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_enable(TF_ServoV2 *servo_v2, uint16_t servo_channel, bool enable) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_SET_ENABLE, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_ENABLE, 3, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);
    buf[2] = enable ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_enabled(TF_ServoV2 *servo_v2, uint16_t servo_channel, bool *ret_enable) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_ENABLED, 2, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enable != NULL) { *ret_enable = tf_packetbuffer_read_bool(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_position(TF_ServoV2 *servo_v2, uint16_t servo_channel, int16_t position) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_SET_POSITION, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_POSITION, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);
    position = tf_leconvert_int16_to(position); memcpy(buf + 2, &position, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_position(TF_ServoV2 *servo_v2, uint16_t servo_channel, int16_t *ret_position) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_POSITION, 2, 2, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_int16_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_current_position(TF_ServoV2 *servo_v2, uint16_t servo_channel, int16_t *ret_position) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_CURRENT_POSITION, 2, 2, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_int16_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_current_velocity(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint16_t *ret_velocity) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_CURRENT_VELOCITY, 2, 2, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_velocity != NULL) { *ret_velocity = tf_packetbuffer_read_uint16_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_motion_configuration(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint32_t velocity, uint32_t acceleration, uint32_t deceleration) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_SET_MOTION_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_MOTION_CONFIGURATION, 14, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);
    velocity = tf_leconvert_uint32_to(velocity); memcpy(buf + 2, &velocity, 4);
    acceleration = tf_leconvert_uint32_to(acceleration); memcpy(buf + 6, &acceleration, 4);
    deceleration = tf_leconvert_uint32_to(deceleration); memcpy(buf + 10, &deceleration, 4);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_motion_configuration(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint32_t *ret_velocity, uint32_t *ret_acceleration, uint32_t *ret_deceleration) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_MOTION_CONFIGURATION, 2, 12, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_velocity != NULL) { *ret_velocity = tf_packetbuffer_read_uint32_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_acceleration != NULL) { *ret_acceleration = tf_packetbuffer_read_uint32_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_deceleration != NULL) { *ret_deceleration = tf_packetbuffer_read_uint32_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_pulse_width(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint32_t min, uint32_t max) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_SET_PULSE_WIDTH, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_PULSE_WIDTH, 10, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);
    min = tf_leconvert_uint32_to(min); memcpy(buf + 2, &min, 4);
    max = tf_leconvert_uint32_to(max); memcpy(buf + 6, &max, 4);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_pulse_width(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint32_t *ret_min, uint32_t *ret_max) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_PULSE_WIDTH, 2, 8, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_min != NULL) { *ret_min = tf_packetbuffer_read_uint32_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_max != NULL) { *ret_max = tf_packetbuffer_read_uint32_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_degree(TF_ServoV2 *servo_v2, uint16_t servo_channel, int16_t min, int16_t max) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_SET_DEGREE, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_DEGREE, 6, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);
    min = tf_leconvert_int16_to(min); memcpy(buf + 2, &min, 2);
    max = tf_leconvert_int16_to(max); memcpy(buf + 4, &max, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_degree(TF_ServoV2 *servo_v2, uint16_t servo_channel, int16_t *ret_min, int16_t *ret_max) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_DEGREE, 2, 4, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_min != NULL) { *ret_min = tf_packetbuffer_read_int16_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_max != NULL) { *ret_max = tf_packetbuffer_read_int16_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_period(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint32_t period) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_SET_PERIOD, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_PERIOD, 6, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);
    period = tf_leconvert_uint32_to(period); memcpy(buf + 2, &period, 4);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_period(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint32_t *ret_period) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_PERIOD, 2, 4, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_servo_current(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint16_t *ret_current) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_SERVO_CURRENT, 2, 2, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_current != NULL) { *ret_current = tf_packetbuffer_read_uint16_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_servo_current_configuration(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint8_t averaging_duration) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_SET_SERVO_CURRENT_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_SERVO_CURRENT_CONFIGURATION, 3, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);
    buf[2] = (uint8_t)averaging_duration;

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_servo_current_configuration(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint8_t *ret_averaging_duration) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_SERVO_CURRENT_CONFIGURATION, 2, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_averaging_duration != NULL) { *ret_averaging_duration = tf_packetbuffer_read_uint8_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_input_voltage_configuration(TF_ServoV2 *servo_v2, uint8_t averaging_duration) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_SET_INPUT_VOLTAGE_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_INPUT_VOLTAGE_CONFIGURATION, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    buf[0] = (uint8_t)averaging_duration;

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_input_voltage_configuration(TF_ServoV2 *servo_v2, uint8_t *ret_averaging_duration) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_INPUT_VOLTAGE_CONFIGURATION, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_averaging_duration != NULL) { *ret_averaging_duration = tf_packetbuffer_read_uint8_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_overall_current(TF_ServoV2 *servo_v2, uint16_t *ret_current) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_OVERALL_CURRENT, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_current != NULL) { *ret_current = tf_packetbuffer_read_uint16_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_input_voltage(TF_ServoV2 *servo_v2, uint16_t *ret_voltage) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_INPUT_VOLTAGE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_voltage != NULL) { *ret_voltage = tf_packetbuffer_read_uint16_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_current_calibration(TF_ServoV2 *servo_v2, int16_t offset[10]) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_SET_CURRENT_CALIBRATION, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_CURRENT_CALIBRATION, 20, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    for (i = 0; i < 10; i++) { int16_t tmp_offset = tf_leconvert_int16_to(offset[i]); memcpy(buf + 0 + (i * sizeof(int16_t)), &tmp_offset, sizeof(int16_t)); }

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_current_calibration(TF_ServoV2 *servo_v2, int16_t ret_offset[10]) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_CURRENT_CALIBRATION, 0, 20, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_offset != NULL) { for (i = 0; i < 10; ++i) ret_offset[i] = tf_packetbuffer_read_int16_t(&servo_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 20); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_position_reached_callback_configuration(TF_ServoV2 *servo_v2, uint16_t servo_channel, bool enabled) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_SET_POSITION_REACHED_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_POSITION_REACHED_CALLBACK_CONFIGURATION, 3, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);
    buf[2] = enabled ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_position_reached_callback_configuration(TF_ServoV2 *servo_v2, uint16_t servo_channel, bool *ret_enabled) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_POSITION_REACHED_CALLBACK_CONFIGURATION, 2, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    servo_channel = tf_leconvert_uint16_to(servo_channel); memcpy(buf + 0, &servo_channel, 2);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { *ret_enabled = tf_packetbuffer_read_bool(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_spitfp_error_count(TF_ServoV2 *servo_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_bootloader_mode(TF_ServoV2 *servo_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_bootloader_mode(TF_ServoV2 *servo_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_write_firmware_pointer(TF_ServoV2 *servo_v2, uint32_t pointer) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_write_firmware(TF_ServoV2 *servo_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_set_status_led_config(TF_ServoV2 *servo_v2, uint8_t config) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_status_led_config(TF_ServoV2 *servo_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_chip_temperature(TF_ServoV2 *servo_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_reset(TF_ServoV2 *servo_v2) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_write_uid(TF_ServoV2 *servo_v2, uint32_t uid) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_servo_v2_get_response_expected(servo_v2, TF_SERVO_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(servo_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_read_uid(TF_ServoV2 *servo_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_servo_v2_get_identity(TF_ServoV2 *servo_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(servo_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(servo_v2->tfp, TF_SERVO_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(servo_v2->tfp->hal) + tf_hal_get_common(servo_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(servo_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&servo_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&servo_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&servo_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&servo_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&servo_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&servo_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(servo_v2->tfp->hal, servo_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(servo_v2->tfp);
    }

    result = tf_tfp_finish_send(servo_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_servo_v2_register_position_reached_callback(TF_ServoV2 *servo_v2, TF_ServoV2PositionReachedHandler handler, void *user_data) {
    if (handler == NULL) {
        servo_v2->tfp->needs_callback_tick = false;
        
    } else {
        servo_v2->tfp->needs_callback_tick = true;
    }
    servo_v2->position_reached_handler = handler;
    servo_v2->position_reached_user_data = user_data;
}
#endif
int tf_servo_v2_callback_tick(TF_ServoV2 *servo_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(servo_v2->tfp, tf_hal_current_time_us(servo_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
