/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_performance_dc.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_performance_dc_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_PerformanceDC *performance_dc = (TF_PerformanceDC *) dev;
    (void)payload;

    switch(fid) {

        case TF_PERFORMANCE_DC_CALLBACK_EMERGENCY_SHUTDOWN: {
            TF_PerformanceDCEmergencyShutdownHandler fn = performance_dc->emergency_shutdown_handler;
            void *user_data = performance_dc->emergency_shutdown_user_data;
            if (fn == NULL)
                return false;


            TF_HalCommon *common = tf_hal_get_common(performance_dc->tfp->hal);
            common->locked = true;
            fn(performance_dc, user_data);
            common->locked = false;
            break;
        }

        case TF_PERFORMANCE_DC_CALLBACK_VELOCITY_REACHED: {
            TF_PerformanceDCVelocityReachedHandler fn = performance_dc->velocity_reached_handler;
            void *user_data = performance_dc->velocity_reached_user_data;
            if (fn == NULL)
                return false;

            int16_t velocity = tf_packetbuffer_read_int16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(performance_dc->tfp->hal);
            common->locked = true;
            fn(performance_dc, velocity, user_data);
            common->locked = false;
            break;
        }

        case TF_PERFORMANCE_DC_CALLBACK_CURRENT_VELOCITY: {
            TF_PerformanceDCCurrentVelocityHandler fn = performance_dc->current_velocity_handler;
            void *user_data = performance_dc->current_velocity_user_data;
            if (fn == NULL)
                return false;

            int16_t velocity = tf_packetbuffer_read_int16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(performance_dc->tfp->hal);
            common->locked = true;
            fn(performance_dc, velocity, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_performance_dc_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_performance_dc_create(TF_PerformanceDC *performance_dc, const char *uid, TF_HalContext *hal) {
    memset(performance_dc, 0, sizeof(TF_PerformanceDC));

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

    //rc = tf_tfp_init(performance_dc->tfp, numeric_uid, TF_PERFORMANCE_DC_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_performance_dc_callback_handler);
    rc = tf_hal_get_tfp(hal, &performance_dc->tfp, TF_PERFORMANCE_DC_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    performance_dc->tfp->device = performance_dc;
    performance_dc->tfp->uid = numeric_uid;
    performance_dc->tfp->cb_handler = tf_performance_dc_callback_handler;
    performance_dc->response_expected[0] = 0x00;
    performance_dc->response_expected[1] = 0xE0;
    performance_dc->response_expected[2] = 0x00;
    return TF_E_OK;
}

int tf_performance_dc_destroy(TF_PerformanceDC *performance_dc) {
    int result = tf_tfp_destroy(performance_dc->tfp);
    performance_dc->tfp = NULL;
    return result;
}

int tf_performance_dc_get_response_expected(TF_PerformanceDC *performance_dc, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_PERFORMANCE_DC_FUNCTION_SET_ENABLED:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_VELOCITY:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_MOTION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_FULL_BRAKE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_DRIVE_MODE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_PWM_FREQUENCY:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_THERMAL_SHUTDOWN:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_GPIO_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_GPIO_ACTION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_ERROR_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[1] & (1 << 1)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_CW_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[1] & (1 << 2)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_CCW_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[1] & (1 << 3)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_GPIO_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[1] & (1 << 4)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_EMERGENCY_SHUTDOWN_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[1] & (1 << 5)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_VELOCITY_REACHED_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[1] & (1 << 6)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_CURRENT_VELOCITY_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[1] & (1 << 7)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[2] & (1 << 0)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[2] & (1 << 1)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[2] & (1 << 2)) != 0;
            break;
        case TF_PERFORMANCE_DC_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (performance_dc->response_expected[2] & (1 << 3)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_performance_dc_set_response_expected(TF_PerformanceDC *performance_dc, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_PERFORMANCE_DC_FUNCTION_SET_ENABLED:
            if (response_expected) {
                performance_dc->response_expected[0] |= (1 << 0);
            } else {
                performance_dc->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_VELOCITY:
            if (response_expected) {
                performance_dc->response_expected[0] |= (1 << 1);
            } else {
                performance_dc->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_MOTION:
            if (response_expected) {
                performance_dc->response_expected[0] |= (1 << 2);
            } else {
                performance_dc->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_FULL_BRAKE:
            if (response_expected) {
                performance_dc->response_expected[0] |= (1 << 3);
            } else {
                performance_dc->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_DRIVE_MODE:
            if (response_expected) {
                performance_dc->response_expected[0] |= (1 << 4);
            } else {
                performance_dc->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_PWM_FREQUENCY:
            if (response_expected) {
                performance_dc->response_expected[0] |= (1 << 5);
            } else {
                performance_dc->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_THERMAL_SHUTDOWN:
            if (response_expected) {
                performance_dc->response_expected[0] |= (1 << 6);
            } else {
                performance_dc->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_GPIO_CONFIGURATION:
            if (response_expected) {
                performance_dc->response_expected[0] |= (1 << 7);
            } else {
                performance_dc->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_GPIO_ACTION:
            if (response_expected) {
                performance_dc->response_expected[1] |= (1 << 0);
            } else {
                performance_dc->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_ERROR_LED_CONFIG:
            if (response_expected) {
                performance_dc->response_expected[1] |= (1 << 1);
            } else {
                performance_dc->response_expected[1] &= ~(1 << 1);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_CW_LED_CONFIG:
            if (response_expected) {
                performance_dc->response_expected[1] |= (1 << 2);
            } else {
                performance_dc->response_expected[1] &= ~(1 << 2);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_CCW_LED_CONFIG:
            if (response_expected) {
                performance_dc->response_expected[1] |= (1 << 3);
            } else {
                performance_dc->response_expected[1] &= ~(1 << 3);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_GPIO_LED_CONFIG:
            if (response_expected) {
                performance_dc->response_expected[1] |= (1 << 4);
            } else {
                performance_dc->response_expected[1] &= ~(1 << 4);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_EMERGENCY_SHUTDOWN_CALLBACK_CONFIGURATION:
            if (response_expected) {
                performance_dc->response_expected[1] |= (1 << 5);
            } else {
                performance_dc->response_expected[1] &= ~(1 << 5);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_VELOCITY_REACHED_CALLBACK_CONFIGURATION:
            if (response_expected) {
                performance_dc->response_expected[1] |= (1 << 6);
            } else {
                performance_dc->response_expected[1] &= ~(1 << 6);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_CURRENT_VELOCITY_CALLBACK_CONFIGURATION:
            if (response_expected) {
                performance_dc->response_expected[1] |= (1 << 7);
            } else {
                performance_dc->response_expected[1] &= ~(1 << 7);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                performance_dc->response_expected[2] |= (1 << 0);
            } else {
                performance_dc->response_expected[2] &= ~(1 << 0);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                performance_dc->response_expected[2] |= (1 << 1);
            } else {
                performance_dc->response_expected[2] &= ~(1 << 1);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_RESET:
            if (response_expected) {
                performance_dc->response_expected[2] |= (1 << 2);
            } else {
                performance_dc->response_expected[2] &= ~(1 << 2);
            }
            break;
        case TF_PERFORMANCE_DC_FUNCTION_WRITE_UID:
            if (response_expected) {
                performance_dc->response_expected[2] |= (1 << 3);
            } else {
                performance_dc->response_expected[2] &= ~(1 << 3);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_performance_dc_set_response_expected_all(TF_PerformanceDC *performance_dc, bool response_expected) {
    memset(performance_dc->response_expected, response_expected ? 0xFF : 0, 3);
}

int tf_performance_dc_set_enabled(TF_PerformanceDC *performance_dc, bool enabled) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_ENABLED, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_ENABLED, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = enabled ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_enabled(TF_PerformanceDC *performance_dc, bool *ret_enabled) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_ENABLED, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { *ret_enabled = tf_packetbuffer_read_bool(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_velocity(TF_PerformanceDC *performance_dc, int16_t velocity) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_VELOCITY, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_VELOCITY, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    velocity = tf_leconvert_int16_to(velocity); memcpy(buf + 0, &velocity, 2);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_velocity(TF_PerformanceDC *performance_dc, int16_t *ret_velocity) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_VELOCITY, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_velocity != NULL) { *ret_velocity = tf_packetbuffer_read_int16_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_current_velocity(TF_PerformanceDC *performance_dc, int16_t *ret_velocity) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_CURRENT_VELOCITY, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_velocity != NULL) { *ret_velocity = tf_packetbuffer_read_int16_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_motion(TF_PerformanceDC *performance_dc, uint16_t acceleration, uint16_t deceleration) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_MOTION, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_MOTION, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    acceleration = tf_leconvert_uint16_to(acceleration); memcpy(buf + 0, &acceleration, 2);
    deceleration = tf_leconvert_uint16_to(deceleration); memcpy(buf + 2, &deceleration, 2);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_motion(TF_PerformanceDC *performance_dc, uint16_t *ret_acceleration, uint16_t *ret_deceleration) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_MOTION, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_acceleration != NULL) { *ret_acceleration = tf_packetbuffer_read_uint16_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 2); }
        if (ret_deceleration != NULL) { *ret_deceleration = tf_packetbuffer_read_uint16_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_full_brake(TF_PerformanceDC *performance_dc) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_FULL_BRAKE, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_FULL_BRAKE, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_drive_mode(TF_PerformanceDC *performance_dc, uint8_t mode) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_DRIVE_MODE, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_DRIVE_MODE, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_drive_mode(TF_PerformanceDC *performance_dc, uint8_t *ret_mode) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_DRIVE_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_pwm_frequency(TF_PerformanceDC *performance_dc, uint16_t frequency) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_PWM_FREQUENCY, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_PWM_FREQUENCY, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    frequency = tf_leconvert_uint16_to(frequency); memcpy(buf + 0, &frequency, 2);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_pwm_frequency(TF_PerformanceDC *performance_dc, uint16_t *ret_frequency) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_PWM_FREQUENCY, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_frequency != NULL) { *ret_frequency = tf_packetbuffer_read_uint16_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_power_statistics(TF_PerformanceDC *performance_dc, uint16_t *ret_voltage, uint16_t *ret_current, int16_t *ret_temperature) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_POWER_STATISTICS, 0, 6, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_voltage != NULL) { *ret_voltage = tf_packetbuffer_read_uint16_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 2); }
        if (ret_current != NULL) { *ret_current = tf_packetbuffer_read_uint16_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 2); }
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_thermal_shutdown(TF_PerformanceDC *performance_dc, uint8_t temperature) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_THERMAL_SHUTDOWN, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_THERMAL_SHUTDOWN, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)temperature;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_thermal_shutdown(TF_PerformanceDC *performance_dc, uint8_t *ret_temperature) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_THERMAL_SHUTDOWN, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_uint8_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_gpio_configuration(TF_PerformanceDC *performance_dc, uint8_t channel, uint16_t debounce, uint16_t stop_deceleration) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_GPIO_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_GPIO_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)channel;
    debounce = tf_leconvert_uint16_to(debounce); memcpy(buf + 1, &debounce, 2);
    stop_deceleration = tf_leconvert_uint16_to(stop_deceleration); memcpy(buf + 3, &stop_deceleration, 2);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_gpio_configuration(TF_PerformanceDC *performance_dc, uint8_t channel, uint16_t *ret_debounce, uint16_t *ret_stop_deceleration) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_GPIO_CONFIGURATION, 1, 4, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_debounce != NULL) { *ret_debounce = tf_packetbuffer_read_uint16_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 2); }
        if (ret_stop_deceleration != NULL) { *ret_stop_deceleration = tf_packetbuffer_read_uint16_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_gpio_action(TF_PerformanceDC *performance_dc, uint8_t channel, uint32_t action) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_GPIO_ACTION, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_GPIO_ACTION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)channel;
    action = tf_leconvert_uint32_to(action); memcpy(buf + 1, &action, 4);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_gpio_action(TF_PerformanceDC *performance_dc, uint8_t channel, uint32_t *ret_action) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_GPIO_ACTION, 1, 4, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_action != NULL) { *ret_action = tf_packetbuffer_read_uint32_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_gpio_state(TF_PerformanceDC *performance_dc, bool ret_gpio_state[2]) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_GPIO_STATE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_gpio_state != NULL) { tf_packetbuffer_read_bool_array(&performance_dc->tfp->spitfp->recv_buf, ret_gpio_state, 2);} else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_error_led_config(TF_PerformanceDC *performance_dc, uint8_t config) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_ERROR_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_ERROR_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_error_led_config(TF_PerformanceDC *performance_dc, uint8_t *ret_config) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_ERROR_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_cw_led_config(TF_PerformanceDC *performance_dc, uint8_t config) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_CW_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_CW_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_cw_led_config(TF_PerformanceDC *performance_dc, uint8_t *ret_config) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_CW_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_ccw_led_config(TF_PerformanceDC *performance_dc, uint8_t config) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_CCW_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_CCW_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_ccw_led_config(TF_PerformanceDC *performance_dc, uint8_t *ret_config) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_CCW_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_gpio_led_config(TF_PerformanceDC *performance_dc, uint8_t channel, uint8_t config) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_GPIO_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_GPIO_LED_CONFIG, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_gpio_led_config(TF_PerformanceDC *performance_dc, uint8_t channel, uint8_t *ret_config) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_GPIO_LED_CONFIG, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_emergency_shutdown_callback_configuration(TF_PerformanceDC *performance_dc, bool enabled) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_EMERGENCY_SHUTDOWN_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_EMERGENCY_SHUTDOWN_CALLBACK_CONFIGURATION, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = enabled ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_emergency_shutdown_callback_configuration(TF_PerformanceDC *performance_dc, bool *ret_enabled) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_EMERGENCY_SHUTDOWN_CALLBACK_CONFIGURATION, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { *ret_enabled = tf_packetbuffer_read_bool(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_velocity_reached_callback_configuration(TF_PerformanceDC *performance_dc, bool enabled) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_VELOCITY_REACHED_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_VELOCITY_REACHED_CALLBACK_CONFIGURATION, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = enabled ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_velocity_reached_callback_configuration(TF_PerformanceDC *performance_dc, bool *ret_enabled) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_VELOCITY_REACHED_CALLBACK_CONFIGURATION, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { *ret_enabled = tf_packetbuffer_read_bool(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_current_velocity_callback_configuration(TF_PerformanceDC *performance_dc, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_CURRENT_VELOCITY_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_CURRENT_VELOCITY_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_current_velocity_callback_configuration(TF_PerformanceDC *performance_dc, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_CURRENT_VELOCITY_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_spitfp_error_count(TF_PerformanceDC *performance_dc, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_bootloader_mode(TF_PerformanceDC *performance_dc, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_bootloader_mode(TF_PerformanceDC *performance_dc, uint8_t *ret_mode) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_write_firmware_pointer(TF_PerformanceDC *performance_dc, uint32_t pointer) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_write_firmware(TF_PerformanceDC *performance_dc, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_set_status_led_config(TF_PerformanceDC *performance_dc, uint8_t config) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_status_led_config(TF_PerformanceDC *performance_dc, uint8_t *ret_config) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_chip_temperature(TF_PerformanceDC *performance_dc, int16_t *ret_temperature) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_reset(TF_PerformanceDC *performance_dc) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_write_uid(TF_PerformanceDC *performance_dc, uint32_t uid) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_performance_dc_get_response_expected(performance_dc, TF_PERFORMANCE_DC_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(performance_dc->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_read_uid(TF_PerformanceDC *performance_dc, uint32_t *ret_uid) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_performance_dc_get_identity(TF_PerformanceDC *performance_dc, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(performance_dc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(performance_dc->tfp, TF_PERFORMANCE_DC_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(performance_dc->tfp->hal) + tf_hal_get_common(performance_dc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(performance_dc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&performance_dc->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&performance_dc->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&performance_dc->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&performance_dc->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&performance_dc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&performance_dc->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(performance_dc->tfp->hal, performance_dc->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(performance_dc->tfp);
    }

    result = tf_tfp_finish_send(performance_dc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_performance_dc_register_emergency_shutdown_callback(TF_PerformanceDC *performance_dc, TF_PerformanceDCEmergencyShutdownHandler handler, void *user_data) {
    if (handler == NULL) {
        performance_dc->tfp->needs_callback_tick = false;
        performance_dc->tfp->needs_callback_tick |= performance_dc->velocity_reached_handler != NULL;
        performance_dc->tfp->needs_callback_tick |= performance_dc->current_velocity_handler != NULL;
    } else {
        performance_dc->tfp->needs_callback_tick = true;
    }
    performance_dc->emergency_shutdown_handler = handler;
    performance_dc->emergency_shutdown_user_data = user_data;
}


void tf_performance_dc_register_velocity_reached_callback(TF_PerformanceDC *performance_dc, TF_PerformanceDCVelocityReachedHandler handler, void *user_data) {
    if (handler == NULL) {
        performance_dc->tfp->needs_callback_tick = false;
        performance_dc->tfp->needs_callback_tick |= performance_dc->emergency_shutdown_handler != NULL;
        performance_dc->tfp->needs_callback_tick |= performance_dc->current_velocity_handler != NULL;
    } else {
        performance_dc->tfp->needs_callback_tick = true;
    }
    performance_dc->velocity_reached_handler = handler;
    performance_dc->velocity_reached_user_data = user_data;
}


void tf_performance_dc_register_current_velocity_callback(TF_PerformanceDC *performance_dc, TF_PerformanceDCCurrentVelocityHandler handler, void *user_data) {
    if (handler == NULL) {
        performance_dc->tfp->needs_callback_tick = false;
        performance_dc->tfp->needs_callback_tick |= performance_dc->emergency_shutdown_handler != NULL;
        performance_dc->tfp->needs_callback_tick |= performance_dc->velocity_reached_handler != NULL;
    } else {
        performance_dc->tfp->needs_callback_tick = true;
    }
    performance_dc->current_velocity_handler = handler;
    performance_dc->current_velocity_user_data = user_data;
}
#endif
int tf_performance_dc_callback_tick(TF_PerformanceDC *performance_dc, uint32_t timeout_us) {
    return tf_tfp_callback_tick(performance_dc->tfp, tf_hal_current_time_us(performance_dc->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
