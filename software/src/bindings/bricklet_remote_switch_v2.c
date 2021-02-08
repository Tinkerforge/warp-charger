/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_remote_switch_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_remote_switch_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_RemoteSwitchV2 *remote_switch_v2 = (TF_RemoteSwitchV2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_REMOTE_SWITCH_V2_CALLBACK_SWITCHING_DONE: {
            TF_RemoteSwitchV2SwitchingDoneHandler fn = remote_switch_v2->switching_done_handler;
            void *user_data = remote_switch_v2->switching_done_user_data;
            if (fn == NULL)
                return false;


            TF_HalCommon *common = tf_hal_get_common(remote_switch_v2->tfp->hal);
            common->locked = true;
            fn(remote_switch_v2, user_data);
            common->locked = false;
            break;
        }

        case TF_REMOTE_SWITCH_V2_CALLBACK_REMOTE_STATUS_A: {
            TF_RemoteSwitchV2RemoteStatusAHandler fn = remote_switch_v2->remote_status_a_handler;
            void *user_data = remote_switch_v2->remote_status_a_user_data;
            if (fn == NULL)
                return false;

            uint8_t house_code = tf_packetbuffer_read_uint8_t(payload);
            uint8_t receiver_code = tf_packetbuffer_read_uint8_t(payload);
            uint8_t switch_to = tf_packetbuffer_read_uint8_t(payload);
            uint16_t repeats = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(remote_switch_v2->tfp->hal);
            common->locked = true;
            fn(remote_switch_v2, house_code, receiver_code, switch_to, repeats, user_data);
            common->locked = false;
            break;
        }

        case TF_REMOTE_SWITCH_V2_CALLBACK_REMOTE_STATUS_B: {
            TF_RemoteSwitchV2RemoteStatusBHandler fn = remote_switch_v2->remote_status_b_handler;
            void *user_data = remote_switch_v2->remote_status_b_user_data;
            if (fn == NULL)
                return false;

            uint32_t address = tf_packetbuffer_read_uint32_t(payload);
            uint8_t unit = tf_packetbuffer_read_uint8_t(payload);
            uint8_t switch_to = tf_packetbuffer_read_uint8_t(payload);
            uint8_t dim_value = tf_packetbuffer_read_uint8_t(payload);
            uint16_t repeats = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(remote_switch_v2->tfp->hal);
            common->locked = true;
            fn(remote_switch_v2, address, unit, switch_to, dim_value, repeats, user_data);
            common->locked = false;
            break;
        }

        case TF_REMOTE_SWITCH_V2_CALLBACK_REMOTE_STATUS_C: {
            TF_RemoteSwitchV2RemoteStatusCHandler fn = remote_switch_v2->remote_status_c_handler;
            void *user_data = remote_switch_v2->remote_status_c_user_data;
            if (fn == NULL)
                return false;

            char system_code = tf_packetbuffer_read_char(payload);
            uint8_t device_code = tf_packetbuffer_read_uint8_t(payload);
            uint8_t switch_to = tf_packetbuffer_read_uint8_t(payload);
            uint16_t repeats = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(remote_switch_v2->tfp->hal);
            common->locked = true;
            fn(remote_switch_v2, system_code, device_code, switch_to, repeats, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_remote_switch_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_remote_switch_v2_create(TF_RemoteSwitchV2 *remote_switch_v2, const char *uid, TF_HalContext *hal) {
    memset(remote_switch_v2, 0, sizeof(TF_RemoteSwitchV2));

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

    //rc = tf_tfp_init(remote_switch_v2->tfp, numeric_uid, TF_REMOTE_SWITCH_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_remote_switch_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    remote_switch_v2->tfp->device = remote_switch_v2;
    remote_switch_v2->tfp->uid = numeric_uid;
    remote_switch_v2->tfp->cb_handler = tf_remote_switch_v2_callback_handler;
    remote_switch_v2->response_expected[0] = 0x00;
    remote_switch_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_remote_switch_v2_destroy(TF_RemoteSwitchV2 *remote_switch_v2) {
    int result = tf_tfp_destroy(remote_switch_v2->tfp);
    remote_switch_v2->tfp = NULL;
    return result;
}

int tf_remote_switch_v2_get_response_expected(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_REMOTE_SWITCH_V2_FUNCTION_SET_REPEATS:
            if(ret_response_expected != NULL)
                *ret_response_expected = (remote_switch_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_SWITCH_SOCKET_A:
            if(ret_response_expected != NULL)
                *ret_response_expected = (remote_switch_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_SWITCH_SOCKET_B:
            if(ret_response_expected != NULL)
                *ret_response_expected = (remote_switch_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_DIM_SOCKET_B:
            if(ret_response_expected != NULL)
                *ret_response_expected = (remote_switch_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_SWITCH_SOCKET_C:
            if(ret_response_expected != NULL)
                *ret_response_expected = (remote_switch_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_SET_REMOTE_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (remote_switch_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (remote_switch_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (remote_switch_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (remote_switch_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (remote_switch_v2->response_expected[1] & (1 << 1)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_remote_switch_v2_set_response_expected(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_REMOTE_SWITCH_V2_FUNCTION_SET_REPEATS:
            if (response_expected) {
                remote_switch_v2->response_expected[0] |= (1 << 0);
            } else {
                remote_switch_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_SWITCH_SOCKET_A:
            if (response_expected) {
                remote_switch_v2->response_expected[0] |= (1 << 1);
            } else {
                remote_switch_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_SWITCH_SOCKET_B:
            if (response_expected) {
                remote_switch_v2->response_expected[0] |= (1 << 2);
            } else {
                remote_switch_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_DIM_SOCKET_B:
            if (response_expected) {
                remote_switch_v2->response_expected[0] |= (1 << 3);
            } else {
                remote_switch_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_SWITCH_SOCKET_C:
            if (response_expected) {
                remote_switch_v2->response_expected[0] |= (1 << 4);
            } else {
                remote_switch_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_SET_REMOTE_CONFIGURATION:
            if (response_expected) {
                remote_switch_v2->response_expected[0] |= (1 << 5);
            } else {
                remote_switch_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                remote_switch_v2->response_expected[0] |= (1 << 6);
            } else {
                remote_switch_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                remote_switch_v2->response_expected[0] |= (1 << 7);
            } else {
                remote_switch_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_RESET:
            if (response_expected) {
                remote_switch_v2->response_expected[1] |= (1 << 0);
            } else {
                remote_switch_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_REMOTE_SWITCH_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                remote_switch_v2->response_expected[1] |= (1 << 1);
            } else {
                remote_switch_v2->response_expected[1] &= ~(1 << 1);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_remote_switch_v2_set_response_expected_all(TF_RemoteSwitchV2 *remote_switch_v2, bool response_expected) {
    memset(remote_switch_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_remote_switch_v2_get_switching_state(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t *ret_state) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_GET_SWITCHING_STATE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_state != NULL) { *ret_state = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_set_repeats(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t repeats) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_remote_switch_v2_get_response_expected(remote_switch_v2, TF_REMOTE_SWITCH_V2_FUNCTION_SET_REPEATS, &response_expected);
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_SET_REPEATS, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(remote_switch_v2->tfp);

    buf[0] = (uint8_t)repeats;

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_get_repeats(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t *ret_repeats) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_GET_REPEATS, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_repeats != NULL) { *ret_repeats = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_switch_socket_a(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t house_code, uint8_t receiver_code, uint8_t switch_to) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_remote_switch_v2_get_response_expected(remote_switch_v2, TF_REMOTE_SWITCH_V2_FUNCTION_SWITCH_SOCKET_A, &response_expected);
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_SWITCH_SOCKET_A, 3, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(remote_switch_v2->tfp);

    buf[0] = (uint8_t)house_code;
    buf[1] = (uint8_t)receiver_code;
    buf[2] = (uint8_t)switch_to;

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_switch_socket_b(TF_RemoteSwitchV2 *remote_switch_v2, uint32_t address, uint8_t unit, uint8_t switch_to) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_remote_switch_v2_get_response_expected(remote_switch_v2, TF_REMOTE_SWITCH_V2_FUNCTION_SWITCH_SOCKET_B, &response_expected);
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_SWITCH_SOCKET_B, 6, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(remote_switch_v2->tfp);

    address = tf_leconvert_uint32_to(address); memcpy(buf + 0, &address, 4);
    buf[4] = (uint8_t)unit;
    buf[5] = (uint8_t)switch_to;

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_dim_socket_b(TF_RemoteSwitchV2 *remote_switch_v2, uint32_t address, uint8_t unit, uint8_t dim_value) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_remote_switch_v2_get_response_expected(remote_switch_v2, TF_REMOTE_SWITCH_V2_FUNCTION_DIM_SOCKET_B, &response_expected);
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_DIM_SOCKET_B, 6, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(remote_switch_v2->tfp);

    address = tf_leconvert_uint32_to(address); memcpy(buf + 0, &address, 4);
    buf[4] = (uint8_t)unit;
    buf[5] = (uint8_t)dim_value;

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_switch_socket_c(TF_RemoteSwitchV2 *remote_switch_v2, char system_code, uint8_t device_code, uint8_t switch_to) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_remote_switch_v2_get_response_expected(remote_switch_v2, TF_REMOTE_SWITCH_V2_FUNCTION_SWITCH_SOCKET_C, &response_expected);
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_SWITCH_SOCKET_C, 3, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(remote_switch_v2->tfp);

    buf[0] = (uint8_t)system_code;
    buf[1] = (uint8_t)device_code;
    buf[2] = (uint8_t)switch_to;

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_set_remote_configuration(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t remote_type, uint16_t minimum_repeats, bool callback_enabled) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_remote_switch_v2_get_response_expected(remote_switch_v2, TF_REMOTE_SWITCH_V2_FUNCTION_SET_REMOTE_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_SET_REMOTE_CONFIGURATION, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(remote_switch_v2->tfp);

    buf[0] = (uint8_t)remote_type;
    minimum_repeats = tf_leconvert_uint16_to(minimum_repeats); memcpy(buf + 1, &minimum_repeats, 2);
    buf[3] = callback_enabled ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_get_remote_configuration(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t *ret_remote_type, uint16_t *ret_minimum_repeats, bool *ret_callback_enabled) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_GET_REMOTE_CONFIGURATION, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_remote_type != NULL) { *ret_remote_type = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_minimum_repeats != NULL) { *ret_minimum_repeats = tf_packetbuffer_read_uint16_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_callback_enabled != NULL) { *ret_callback_enabled = tf_packetbuffer_read_bool(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_get_remote_status_a(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t *ret_house_code, uint8_t *ret_receiver_code, uint8_t *ret_switch_to, uint16_t *ret_repeats) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_GET_REMOTE_STATUS_A, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_house_code != NULL) { *ret_house_code = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_receiver_code != NULL) { *ret_receiver_code = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_switch_to != NULL) { *ret_switch_to = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_repeats != NULL) { *ret_repeats = tf_packetbuffer_read_uint16_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_get_remote_status_b(TF_RemoteSwitchV2 *remote_switch_v2, uint32_t *ret_address, uint8_t *ret_unit, uint8_t *ret_switch_to, uint8_t *ret_dim_value, uint16_t *ret_repeats) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_GET_REMOTE_STATUS_B, 0, 9, response_expected);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_address != NULL) { *ret_address = tf_packetbuffer_read_uint32_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_unit != NULL) { *ret_unit = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_switch_to != NULL) { *ret_switch_to = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_dim_value != NULL) { *ret_dim_value = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_repeats != NULL) { *ret_repeats = tf_packetbuffer_read_uint16_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_get_remote_status_c(TF_RemoteSwitchV2 *remote_switch_v2, char *ret_system_code, uint8_t *ret_device_code, uint8_t *ret_switch_to, uint16_t *ret_repeats) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_GET_REMOTE_STATUS_C, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_system_code != NULL) { *ret_system_code = tf_packetbuffer_read_char(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_device_code != NULL) { *ret_device_code = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_switch_to != NULL) { *ret_switch_to = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_repeats != NULL) { *ret_repeats = tf_packetbuffer_read_uint16_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_get_spitfp_error_count(TF_RemoteSwitchV2 *remote_switch_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_set_bootloader_mode(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(remote_switch_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_get_bootloader_mode(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_set_write_firmware_pointer(TF_RemoteSwitchV2 *remote_switch_v2, uint32_t pointer) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_remote_switch_v2_get_response_expected(remote_switch_v2, TF_REMOTE_SWITCH_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(remote_switch_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_write_firmware(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(remote_switch_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_set_status_led_config(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t config) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_remote_switch_v2_get_response_expected(remote_switch_v2, TF_REMOTE_SWITCH_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(remote_switch_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_get_status_led_config(TF_RemoteSwitchV2 *remote_switch_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_get_chip_temperature(TF_RemoteSwitchV2 *remote_switch_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_reset(TF_RemoteSwitchV2 *remote_switch_v2) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_remote_switch_v2_get_response_expected(remote_switch_v2, TF_REMOTE_SWITCH_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_write_uid(TF_RemoteSwitchV2 *remote_switch_v2, uint32_t uid) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_remote_switch_v2_get_response_expected(remote_switch_v2, TF_REMOTE_SWITCH_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(remote_switch_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_read_uid(TF_RemoteSwitchV2 *remote_switch_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_remote_switch_v2_get_identity(TF_RemoteSwitchV2 *remote_switch_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(remote_switch_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(remote_switch_v2->tfp, TF_REMOTE_SWITCH_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(remote_switch_v2->tfp->hal) + tf_hal_get_common(remote_switch_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(remote_switch_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&remote_switch_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&remote_switch_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&remote_switch_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&remote_switch_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&remote_switch_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(remote_switch_v2->tfp->hal, remote_switch_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(remote_switch_v2->tfp);
    }

    result = tf_tfp_finish_send(remote_switch_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_remote_switch_v2_register_switching_done_callback(TF_RemoteSwitchV2 *remote_switch_v2, TF_RemoteSwitchV2SwitchingDoneHandler handler, void *user_data) {
    if (handler == NULL) {
        remote_switch_v2->tfp->needs_callback_tick = false;
        remote_switch_v2->tfp->needs_callback_tick |= remote_switch_v2->remote_status_a_handler != NULL;
        remote_switch_v2->tfp->needs_callback_tick |= remote_switch_v2->remote_status_b_handler != NULL;
        remote_switch_v2->tfp->needs_callback_tick |= remote_switch_v2->remote_status_c_handler != NULL;
    } else {
        remote_switch_v2->tfp->needs_callback_tick = true;
    }
    remote_switch_v2->switching_done_handler = handler;
    remote_switch_v2->switching_done_user_data = user_data;
}


void tf_remote_switch_v2_register_remote_status_a_callback(TF_RemoteSwitchV2 *remote_switch_v2, TF_RemoteSwitchV2RemoteStatusAHandler handler, void *user_data) {
    if (handler == NULL) {
        remote_switch_v2->tfp->needs_callback_tick = false;
        remote_switch_v2->tfp->needs_callback_tick |= remote_switch_v2->switching_done_handler != NULL;
        remote_switch_v2->tfp->needs_callback_tick |= remote_switch_v2->remote_status_b_handler != NULL;
        remote_switch_v2->tfp->needs_callback_tick |= remote_switch_v2->remote_status_c_handler != NULL;
    } else {
        remote_switch_v2->tfp->needs_callback_tick = true;
    }
    remote_switch_v2->remote_status_a_handler = handler;
    remote_switch_v2->remote_status_a_user_data = user_data;
}


void tf_remote_switch_v2_register_remote_status_b_callback(TF_RemoteSwitchV2 *remote_switch_v2, TF_RemoteSwitchV2RemoteStatusBHandler handler, void *user_data) {
    if (handler == NULL) {
        remote_switch_v2->tfp->needs_callback_tick = false;
        remote_switch_v2->tfp->needs_callback_tick |= remote_switch_v2->switching_done_handler != NULL;
        remote_switch_v2->tfp->needs_callback_tick |= remote_switch_v2->remote_status_a_handler != NULL;
        remote_switch_v2->tfp->needs_callback_tick |= remote_switch_v2->remote_status_c_handler != NULL;
    } else {
        remote_switch_v2->tfp->needs_callback_tick = true;
    }
    remote_switch_v2->remote_status_b_handler = handler;
    remote_switch_v2->remote_status_b_user_data = user_data;
}


void tf_remote_switch_v2_register_remote_status_c_callback(TF_RemoteSwitchV2 *remote_switch_v2, TF_RemoteSwitchV2RemoteStatusCHandler handler, void *user_data) {
    if (handler == NULL) {
        remote_switch_v2->tfp->needs_callback_tick = false;
        remote_switch_v2->tfp->needs_callback_tick |= remote_switch_v2->switching_done_handler != NULL;
        remote_switch_v2->tfp->needs_callback_tick |= remote_switch_v2->remote_status_a_handler != NULL;
        remote_switch_v2->tfp->needs_callback_tick |= remote_switch_v2->remote_status_b_handler != NULL;
    } else {
        remote_switch_v2->tfp->needs_callback_tick = true;
    }
    remote_switch_v2->remote_status_c_handler = handler;
    remote_switch_v2->remote_status_c_user_data = user_data;
}
#endif
int tf_remote_switch_v2_callback_tick(TF_RemoteSwitchV2 *remote_switch_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(remote_switch_v2->tfp, tf_hal_current_time_us(remote_switch_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
