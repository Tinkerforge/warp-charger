/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_accelerometer_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_accelerometer_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_AccelerometerV2 *accelerometer_v2 = (TF_AccelerometerV2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_ACCELEROMETER_V2_CALLBACK_ACCELERATION: {
            TF_AccelerometerV2AccelerationHandler fn = accelerometer_v2->acceleration_handler;
            void *user_data = accelerometer_v2->acceleration_user_data;
            if (fn == NULL)
                return false;

            int32_t x = tf_packetbuffer_read_int32_t(payload);
            int32_t y = tf_packetbuffer_read_int32_t(payload);
            int32_t z = tf_packetbuffer_read_int32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(accelerometer_v2->tfp->hal);
            common->locked = true;
            fn(accelerometer_v2, x, y, z, user_data);
            common->locked = false;
            break;
        }

        case TF_ACCELEROMETER_V2_CALLBACK_CONTINUOUS_ACCELERATION_16_BIT: {
            TF_AccelerometerV2ContinuousAcceleration16BitHandler fn = accelerometer_v2->continuous_acceleration_16_bit_handler;
            void *user_data = accelerometer_v2->continuous_acceleration_16_bit_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            int16_t acceleration[30]; for (i = 0; i < 30; ++i) acceleration[i] = tf_packetbuffer_read_int16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(accelerometer_v2->tfp->hal);
            common->locked = true;
            fn(accelerometer_v2, acceleration, user_data);
            common->locked = false;
            break;
        }

        case TF_ACCELEROMETER_V2_CALLBACK_CONTINUOUS_ACCELERATION_8_BIT: {
            TF_AccelerometerV2ContinuousAcceleration8BitHandler fn = accelerometer_v2->continuous_acceleration_8_bit_handler;
            void *user_data = accelerometer_v2->continuous_acceleration_8_bit_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            int8_t acceleration[60]; for (i = 0; i < 60; ++i) acceleration[i] = tf_packetbuffer_read_int8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(accelerometer_v2->tfp->hal);
            common->locked = true;
            fn(accelerometer_v2, acceleration, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_accelerometer_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_accelerometer_v2_create(TF_AccelerometerV2 *accelerometer_v2, const char *uid, TF_HalContext *hal) {
    memset(accelerometer_v2, 0, sizeof(TF_AccelerometerV2));

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

    //rc = tf_tfp_init(accelerometer_v2->tfp, numeric_uid, TF_ACCELEROMETER_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_accelerometer_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &accelerometer_v2->tfp, TF_ACCELEROMETER_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    accelerometer_v2->tfp->device = accelerometer_v2;
    accelerometer_v2->tfp->uid = numeric_uid;
    accelerometer_v2->tfp->cb_handler = tf_accelerometer_v2_callback_handler;
    accelerometer_v2->response_expected[0] = 0x0A;
    accelerometer_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_accelerometer_v2_destroy(TF_AccelerometerV2 *accelerometer_v2) {
    int result = tf_tfp_destroy(accelerometer_v2->tfp);
    accelerometer_v2->tfp = NULL;
    return result;
}

int tf_accelerometer_v2_get_response_expected(TF_AccelerometerV2 *accelerometer_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_ACCELEROMETER_V2_FUNCTION_SET_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (accelerometer_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_SET_ACCELERATION_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (accelerometer_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_SET_INFO_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (accelerometer_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_SET_CONTINUOUS_ACCELERATION_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (accelerometer_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_SET_FILTER_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (accelerometer_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (accelerometer_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (accelerometer_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (accelerometer_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (accelerometer_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_accelerometer_v2_set_response_expected(TF_AccelerometerV2 *accelerometer_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_ACCELEROMETER_V2_FUNCTION_SET_CONFIGURATION:
            if (response_expected) {
                accelerometer_v2->response_expected[0] |= (1 << 0);
            } else {
                accelerometer_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_SET_ACCELERATION_CALLBACK_CONFIGURATION:
            if (response_expected) {
                accelerometer_v2->response_expected[0] |= (1 << 1);
            } else {
                accelerometer_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_SET_INFO_LED_CONFIG:
            if (response_expected) {
                accelerometer_v2->response_expected[0] |= (1 << 2);
            } else {
                accelerometer_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_SET_CONTINUOUS_ACCELERATION_CONFIGURATION:
            if (response_expected) {
                accelerometer_v2->response_expected[0] |= (1 << 3);
            } else {
                accelerometer_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_SET_FILTER_CONFIGURATION:
            if (response_expected) {
                accelerometer_v2->response_expected[0] |= (1 << 4);
            } else {
                accelerometer_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                accelerometer_v2->response_expected[0] |= (1 << 5);
            } else {
                accelerometer_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                accelerometer_v2->response_expected[0] |= (1 << 6);
            } else {
                accelerometer_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_RESET:
            if (response_expected) {
                accelerometer_v2->response_expected[0] |= (1 << 7);
            } else {
                accelerometer_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_ACCELEROMETER_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                accelerometer_v2->response_expected[1] |= (1 << 0);
            } else {
                accelerometer_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_accelerometer_v2_set_response_expected_all(TF_AccelerometerV2 *accelerometer_v2, bool response_expected) {
    memset(accelerometer_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_accelerometer_v2_get_acceleration(TF_AccelerometerV2 *accelerometer_v2, int32_t *ret_x, int32_t *ret_y, int32_t *ret_z) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_GET_ACCELERATION, 0, 12, response_expected);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_x != NULL) { *ret_x = tf_packetbuffer_read_int32_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_y != NULL) { *ret_y = tf_packetbuffer_read_int32_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_z != NULL) { *ret_z = tf_packetbuffer_read_int32_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_set_configuration(TF_AccelerometerV2 *accelerometer_v2, uint8_t data_rate, uint8_t full_scale) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_accelerometer_v2_get_response_expected(accelerometer_v2, TF_ACCELEROMETER_V2_FUNCTION_SET_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_SET_CONFIGURATION, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(accelerometer_v2->tfp);

    buf[0] = (uint8_t)data_rate;
    buf[1] = (uint8_t)full_scale;

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_get_configuration(TF_AccelerometerV2 *accelerometer_v2, uint8_t *ret_data_rate, uint8_t *ret_full_scale) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_GET_CONFIGURATION, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_data_rate != NULL) { *ret_data_rate = tf_packetbuffer_read_uint8_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_full_scale != NULL) { *ret_full_scale = tf_packetbuffer_read_uint8_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_set_acceleration_callback_configuration(TF_AccelerometerV2 *accelerometer_v2, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_accelerometer_v2_get_response_expected(accelerometer_v2, TF_ACCELEROMETER_V2_FUNCTION_SET_ACCELERATION_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_SET_ACCELERATION_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(accelerometer_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_get_acceleration_callback_configuration(TF_AccelerometerV2 *accelerometer_v2, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_GET_ACCELERATION_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_set_info_led_config(TF_AccelerometerV2 *accelerometer_v2, uint8_t config) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_accelerometer_v2_get_response_expected(accelerometer_v2, TF_ACCELEROMETER_V2_FUNCTION_SET_INFO_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_SET_INFO_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(accelerometer_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_get_info_led_config(TF_AccelerometerV2 *accelerometer_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_GET_INFO_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_set_continuous_acceleration_configuration(TF_AccelerometerV2 *accelerometer_v2, bool enable_x, bool enable_y, bool enable_z, uint8_t resolution) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_accelerometer_v2_get_response_expected(accelerometer_v2, TF_ACCELEROMETER_V2_FUNCTION_SET_CONTINUOUS_ACCELERATION_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_SET_CONTINUOUS_ACCELERATION_CONFIGURATION, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(accelerometer_v2->tfp);

    buf[0] = enable_x ? 1 : 0;
    buf[1] = enable_y ? 1 : 0;
    buf[2] = enable_z ? 1 : 0;
    buf[3] = (uint8_t)resolution;

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_get_continuous_acceleration_configuration(TF_AccelerometerV2 *accelerometer_v2, bool *ret_enable_x, bool *ret_enable_y, bool *ret_enable_z, uint8_t *ret_resolution) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_GET_CONTINUOUS_ACCELERATION_CONFIGURATION, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enable_x != NULL) { *ret_enable_x = tf_packetbuffer_read_bool(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_enable_y != NULL) { *ret_enable_y = tf_packetbuffer_read_bool(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_enable_z != NULL) { *ret_enable_z = tf_packetbuffer_read_bool(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_resolution != NULL) { *ret_resolution = tf_packetbuffer_read_uint8_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_set_filter_configuration(TF_AccelerometerV2 *accelerometer_v2, uint8_t iir_bypass, uint8_t low_pass_filter) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_accelerometer_v2_get_response_expected(accelerometer_v2, TF_ACCELEROMETER_V2_FUNCTION_SET_FILTER_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_SET_FILTER_CONFIGURATION, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(accelerometer_v2->tfp);

    buf[0] = (uint8_t)iir_bypass;
    buf[1] = (uint8_t)low_pass_filter;

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_get_filter_configuration(TF_AccelerometerV2 *accelerometer_v2, uint8_t *ret_iir_bypass, uint8_t *ret_low_pass_filter) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_GET_FILTER_CONFIGURATION, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_iir_bypass != NULL) { *ret_iir_bypass = tf_packetbuffer_read_uint8_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_low_pass_filter != NULL) { *ret_low_pass_filter = tf_packetbuffer_read_uint8_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_get_spitfp_error_count(TF_AccelerometerV2 *accelerometer_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_set_bootloader_mode(TF_AccelerometerV2 *accelerometer_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(accelerometer_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_get_bootloader_mode(TF_AccelerometerV2 *accelerometer_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_set_write_firmware_pointer(TF_AccelerometerV2 *accelerometer_v2, uint32_t pointer) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_accelerometer_v2_get_response_expected(accelerometer_v2, TF_ACCELEROMETER_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(accelerometer_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_write_firmware(TF_AccelerometerV2 *accelerometer_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(accelerometer_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_set_status_led_config(TF_AccelerometerV2 *accelerometer_v2, uint8_t config) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_accelerometer_v2_get_response_expected(accelerometer_v2, TF_ACCELEROMETER_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(accelerometer_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_get_status_led_config(TF_AccelerometerV2 *accelerometer_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_get_chip_temperature(TF_AccelerometerV2 *accelerometer_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_reset(TF_AccelerometerV2 *accelerometer_v2) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_accelerometer_v2_get_response_expected(accelerometer_v2, TF_ACCELEROMETER_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_write_uid(TF_AccelerometerV2 *accelerometer_v2, uint32_t uid) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_accelerometer_v2_get_response_expected(accelerometer_v2, TF_ACCELEROMETER_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(accelerometer_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_read_uid(TF_AccelerometerV2 *accelerometer_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_accelerometer_v2_get_identity(TF_AccelerometerV2 *accelerometer_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(accelerometer_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(accelerometer_v2->tfp, TF_ACCELEROMETER_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(accelerometer_v2->tfp->hal) + tf_hal_get_common(accelerometer_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(accelerometer_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&accelerometer_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&accelerometer_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&accelerometer_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&accelerometer_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&accelerometer_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&accelerometer_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(accelerometer_v2->tfp->hal, accelerometer_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(accelerometer_v2->tfp);
    }

    result = tf_tfp_finish_send(accelerometer_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_accelerometer_v2_register_acceleration_callback(TF_AccelerometerV2 *accelerometer_v2, TF_AccelerometerV2AccelerationHandler handler, void *user_data) {
    if (handler == NULL) {
        accelerometer_v2->tfp->needs_callback_tick = false;
        accelerometer_v2->tfp->needs_callback_tick |= accelerometer_v2->continuous_acceleration_16_bit_handler != NULL;
        accelerometer_v2->tfp->needs_callback_tick |= accelerometer_v2->continuous_acceleration_8_bit_handler != NULL;
    } else {
        accelerometer_v2->tfp->needs_callback_tick = true;
    }
    accelerometer_v2->acceleration_handler = handler;
    accelerometer_v2->acceleration_user_data = user_data;
}


void tf_accelerometer_v2_register_continuous_acceleration_16_bit_callback(TF_AccelerometerV2 *accelerometer_v2, TF_AccelerometerV2ContinuousAcceleration16BitHandler handler, void *user_data) {
    if (handler == NULL) {
        accelerometer_v2->tfp->needs_callback_tick = false;
        accelerometer_v2->tfp->needs_callback_tick |= accelerometer_v2->acceleration_handler != NULL;
        accelerometer_v2->tfp->needs_callback_tick |= accelerometer_v2->continuous_acceleration_8_bit_handler != NULL;
    } else {
        accelerometer_v2->tfp->needs_callback_tick = true;
    }
    accelerometer_v2->continuous_acceleration_16_bit_handler = handler;
    accelerometer_v2->continuous_acceleration_16_bit_user_data = user_data;
}


void tf_accelerometer_v2_register_continuous_acceleration_8_bit_callback(TF_AccelerometerV2 *accelerometer_v2, TF_AccelerometerV2ContinuousAcceleration8BitHandler handler, void *user_data) {
    if (handler == NULL) {
        accelerometer_v2->tfp->needs_callback_tick = false;
        accelerometer_v2->tfp->needs_callback_tick |= accelerometer_v2->acceleration_handler != NULL;
        accelerometer_v2->tfp->needs_callback_tick |= accelerometer_v2->continuous_acceleration_16_bit_handler != NULL;
    } else {
        accelerometer_v2->tfp->needs_callback_tick = true;
    }
    accelerometer_v2->continuous_acceleration_8_bit_handler = handler;
    accelerometer_v2->continuous_acceleration_8_bit_user_data = user_data;
}
#endif
int tf_accelerometer_v2_callback_tick(TF_AccelerometerV2 *accelerometer_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(accelerometer_v2->tfp, tf_hal_current_time_us(accelerometer_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
