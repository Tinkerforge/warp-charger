/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_nfc.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_nfc_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_NFC *nfc = (TF_NFC *) dev;
    (void)payload;

    switch(fid) {

        case TF_NFC_CALLBACK_READER_STATE_CHANGED: {
            TF_NFCReaderStateChangedHandler fn = nfc->reader_state_changed_handler;
            void *user_data = nfc->reader_state_changed_user_data;
            if (fn == NULL)
                return false;

            uint8_t state = tf_packetbuffer_read_uint8_t(payload);
            bool idle = tf_packetbuffer_read_bool(payload);
            TF_HalCommon *common = tf_hal_get_common(nfc->tfp->hal);
            common->locked = true;
            fn(nfc, state, idle, user_data);
            common->locked = false;
            break;
        }

        case TF_NFC_CALLBACK_CARDEMU_STATE_CHANGED: {
            TF_NFCCardemuStateChangedHandler fn = nfc->cardemu_state_changed_handler;
            void *user_data = nfc->cardemu_state_changed_user_data;
            if (fn == NULL)
                return false;

            uint8_t state = tf_packetbuffer_read_uint8_t(payload);
            bool idle = tf_packetbuffer_read_bool(payload);
            TF_HalCommon *common = tf_hal_get_common(nfc->tfp->hal);
            common->locked = true;
            fn(nfc, state, idle, user_data);
            common->locked = false;
            break;
        }

        case TF_NFC_CALLBACK_P2P_STATE_CHANGED: {
            TF_NFCP2PStateChangedHandler fn = nfc->p2p_state_changed_handler;
            void *user_data = nfc->p2p_state_changed_user_data;
            if (fn == NULL)
                return false;

            uint8_t state = tf_packetbuffer_read_uint8_t(payload);
            bool idle = tf_packetbuffer_read_bool(payload);
            TF_HalCommon *common = tf_hal_get_common(nfc->tfp->hal);
            common->locked = true;
            fn(nfc, state, idle, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_nfc_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_nfc_create(TF_NFC *nfc, const char *uid, TF_HalContext *hal) {
    memset(nfc, 0, sizeof(TF_NFC));

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

    //rc = tf_tfp_init(nfc->tfp, numeric_uid, TF_NFC_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_nfc_callback_handler);
    rc = tf_hal_get_tfp(hal, &nfc->tfp, TF_NFC_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    nfc->tfp->device = nfc;
    nfc->tfp->uid = numeric_uid;
    nfc->tfp->cb_handler = tf_nfc_callback_handler;
    nfc->response_expected[0] = 0x24;
    nfc->response_expected[1] = 0x09;
    nfc->response_expected[2] = 0x00;
    return TF_E_OK;
}

int tf_nfc_destroy(TF_NFC *nfc) {
    int result = tf_tfp_destroy(nfc->tfp);
    nfc->tfp = NULL;
    return result;
}

int tf_nfc_get_response_expected(TF_NFC *nfc, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_NFC_FUNCTION_SET_MODE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_NFC_FUNCTION_READER_REQUEST_TAG_ID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_NFC_FUNCTION_READER_WRITE_NDEF_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_NFC_FUNCTION_READER_REQUEST_NDEF:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_NFC_FUNCTION_READER_AUTHENTICATE_MIFARE_CLASSIC_PAGE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_NFC_FUNCTION_READER_WRITE_PAGE_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_NFC_FUNCTION_READER_REQUEST_PAGE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_NFC_FUNCTION_CARDEMU_START_DISCOVERY:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_NFC_FUNCTION_CARDEMU_WRITE_NDEF_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_NFC_FUNCTION_CARDEMU_START_TRANSFER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[1] & (1 << 1)) != 0;
            break;
        case TF_NFC_FUNCTION_P2P_START_DISCOVERY:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[1] & (1 << 2)) != 0;
            break;
        case TF_NFC_FUNCTION_P2P_WRITE_NDEF_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[1] & (1 << 3)) != 0;
            break;
        case TF_NFC_FUNCTION_P2P_START_TRANSFER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[1] & (1 << 4)) != 0;
            break;
        case TF_NFC_FUNCTION_SET_DETECTION_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[1] & (1 << 5)) != 0;
            break;
        case TF_NFC_FUNCTION_SET_MAXIMUM_TIMEOUT:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[1] & (1 << 6)) != 0;
            break;
        case TF_NFC_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[1] & (1 << 7)) != 0;
            break;
        case TF_NFC_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[2] & (1 << 0)) != 0;
            break;
        case TF_NFC_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[2] & (1 << 1)) != 0;
            break;
        case TF_NFC_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (nfc->response_expected[2] & (1 << 2)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_nfc_set_response_expected(TF_NFC *nfc, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_NFC_FUNCTION_SET_MODE:
            if (response_expected) {
                nfc->response_expected[0] |= (1 << 0);
            } else {
                nfc->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_NFC_FUNCTION_READER_REQUEST_TAG_ID:
            if (response_expected) {
                nfc->response_expected[0] |= (1 << 1);
            } else {
                nfc->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_NFC_FUNCTION_READER_WRITE_NDEF_LOW_LEVEL:
            if (response_expected) {
                nfc->response_expected[0] |= (1 << 2);
            } else {
                nfc->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_NFC_FUNCTION_READER_REQUEST_NDEF:
            if (response_expected) {
                nfc->response_expected[0] |= (1 << 3);
            } else {
                nfc->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_NFC_FUNCTION_READER_AUTHENTICATE_MIFARE_CLASSIC_PAGE:
            if (response_expected) {
                nfc->response_expected[0] |= (1 << 4);
            } else {
                nfc->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_NFC_FUNCTION_READER_WRITE_PAGE_LOW_LEVEL:
            if (response_expected) {
                nfc->response_expected[0] |= (1 << 5);
            } else {
                nfc->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_NFC_FUNCTION_READER_REQUEST_PAGE:
            if (response_expected) {
                nfc->response_expected[0] |= (1 << 6);
            } else {
                nfc->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_NFC_FUNCTION_CARDEMU_START_DISCOVERY:
            if (response_expected) {
                nfc->response_expected[0] |= (1 << 7);
            } else {
                nfc->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_NFC_FUNCTION_CARDEMU_WRITE_NDEF_LOW_LEVEL:
            if (response_expected) {
                nfc->response_expected[1] |= (1 << 0);
            } else {
                nfc->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_NFC_FUNCTION_CARDEMU_START_TRANSFER:
            if (response_expected) {
                nfc->response_expected[1] |= (1 << 1);
            } else {
                nfc->response_expected[1] &= ~(1 << 1);
            }
            break;
        case TF_NFC_FUNCTION_P2P_START_DISCOVERY:
            if (response_expected) {
                nfc->response_expected[1] |= (1 << 2);
            } else {
                nfc->response_expected[1] &= ~(1 << 2);
            }
            break;
        case TF_NFC_FUNCTION_P2P_WRITE_NDEF_LOW_LEVEL:
            if (response_expected) {
                nfc->response_expected[1] |= (1 << 3);
            } else {
                nfc->response_expected[1] &= ~(1 << 3);
            }
            break;
        case TF_NFC_FUNCTION_P2P_START_TRANSFER:
            if (response_expected) {
                nfc->response_expected[1] |= (1 << 4);
            } else {
                nfc->response_expected[1] &= ~(1 << 4);
            }
            break;
        case TF_NFC_FUNCTION_SET_DETECTION_LED_CONFIG:
            if (response_expected) {
                nfc->response_expected[1] |= (1 << 5);
            } else {
                nfc->response_expected[1] &= ~(1 << 5);
            }
            break;
        case TF_NFC_FUNCTION_SET_MAXIMUM_TIMEOUT:
            if (response_expected) {
                nfc->response_expected[1] |= (1 << 6);
            } else {
                nfc->response_expected[1] &= ~(1 << 6);
            }
            break;
        case TF_NFC_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                nfc->response_expected[1] |= (1 << 7);
            } else {
                nfc->response_expected[1] &= ~(1 << 7);
            }
            break;
        case TF_NFC_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                nfc->response_expected[2] |= (1 << 0);
            } else {
                nfc->response_expected[2] &= ~(1 << 0);
            }
            break;
        case TF_NFC_FUNCTION_RESET:
            if (response_expected) {
                nfc->response_expected[2] |= (1 << 1);
            } else {
                nfc->response_expected[2] &= ~(1 << 1);
            }
            break;
        case TF_NFC_FUNCTION_WRITE_UID:
            if (response_expected) {
                nfc->response_expected[2] |= (1 << 2);
            } else {
                nfc->response_expected[2] &= ~(1 << 2);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_nfc_set_response_expected_all(TF_NFC *nfc, bool response_expected) {
    memset(nfc->response_expected, response_expected ? 0xFF : 0, 3);
}

int tf_nfc_set_mode(TF_NFC *nfc, uint8_t mode) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_SET_MODE, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_SET_MODE, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_get_mode(TF_NFC *nfc, uint8_t *ret_mode) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_GET_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_reader_request_tag_id(TF_NFC *nfc) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_READER_REQUEST_TAG_ID, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_READER_REQUEST_TAG_ID, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_reader_get_tag_id_low_level(TF_NFC *nfc, uint8_t *ret_tag_type, uint8_t *ret_tag_id_length, uint8_t ret_tag_id_data[32]) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_READER_GET_TAG_ID_LOW_LEVEL, 0, 34, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_tag_type != NULL) { *ret_tag_type = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        if (ret_tag_id_length != NULL) { *ret_tag_id_length = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        if (ret_tag_id_data != NULL) { for (i = 0; i < 32; ++i) ret_tag_id_data[i] = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 32); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_reader_get_state(TF_NFC *nfc, uint8_t *ret_state, bool *ret_idle) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_READER_GET_STATE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_state != NULL) { *ret_state = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        if (ret_idle != NULL) { *ret_idle = tf_packetbuffer_read_bool(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_reader_write_ndef_low_level(TF_NFC *nfc, uint16_t ndef_length, uint16_t ndef_chunk_offset, uint8_t ndef_chunk_data[60]) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_READER_WRITE_NDEF_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_READER_WRITE_NDEF_LOW_LEVEL, 64, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    ndef_length = tf_leconvert_uint16_to(ndef_length); memcpy(buf + 0, &ndef_length, 2);
    ndef_chunk_offset = tf_leconvert_uint16_to(ndef_chunk_offset); memcpy(buf + 2, &ndef_chunk_offset, 2);
    memcpy(buf + 4, ndef_chunk_data, 60);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_reader_request_ndef(TF_NFC *nfc) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_READER_REQUEST_NDEF, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_READER_REQUEST_NDEF, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_reader_read_ndef_low_level(TF_NFC *nfc, uint16_t *ret_ndef_length, uint16_t *ret_ndef_chunk_offset, uint8_t ret_ndef_chunk_data[60]) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_READER_READ_NDEF_LOW_LEVEL, 0, 64, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_ndef_length != NULL) { *ret_ndef_length = tf_packetbuffer_read_uint16_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 2); }
        if (ret_ndef_chunk_offset != NULL) { *ret_ndef_chunk_offset = tf_packetbuffer_read_uint16_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 2); }
        if (ret_ndef_chunk_data != NULL) { for (i = 0; i < 60; ++i) ret_ndef_chunk_data[i] = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 60); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_reader_authenticate_mifare_classic_page(TF_NFC *nfc, uint16_t page, uint8_t key_number, uint8_t key[6]) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_READER_AUTHENTICATE_MIFARE_CLASSIC_PAGE, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_READER_AUTHENTICATE_MIFARE_CLASSIC_PAGE, 9, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    page = tf_leconvert_uint16_to(page); memcpy(buf + 0, &page, 2);
    buf[2] = (uint8_t)key_number;
    memcpy(buf + 3, key, 6);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_reader_write_page_low_level(TF_NFC *nfc, uint16_t page, uint16_t data_length, uint16_t data_chunk_offset, uint8_t data_chunk_data[58]) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_READER_WRITE_PAGE_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_READER_WRITE_PAGE_LOW_LEVEL, 64, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    page = tf_leconvert_uint16_to(page); memcpy(buf + 0, &page, 2);
    data_length = tf_leconvert_uint16_to(data_length); memcpy(buf + 2, &data_length, 2);
    data_chunk_offset = tf_leconvert_uint16_to(data_chunk_offset); memcpy(buf + 4, &data_chunk_offset, 2);
    memcpy(buf + 6, data_chunk_data, 58);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_reader_request_page(TF_NFC *nfc, uint16_t page, uint16_t length) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_READER_REQUEST_PAGE, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_READER_REQUEST_PAGE, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    page = tf_leconvert_uint16_to(page); memcpy(buf + 0, &page, 2);
    length = tf_leconvert_uint16_to(length); memcpy(buf + 2, &length, 2);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_reader_read_page_low_level(TF_NFC *nfc, uint16_t *ret_data_length, uint16_t *ret_data_chunk_offset, uint8_t ret_data_chunk_data[60]) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_READER_READ_PAGE_LOW_LEVEL, 0, 64, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_data_length != NULL) { *ret_data_length = tf_packetbuffer_read_uint16_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 2); }
        if (ret_data_chunk_offset != NULL) { *ret_data_chunk_offset = tf_packetbuffer_read_uint16_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 2); }
        if (ret_data_chunk_data != NULL) { for (i = 0; i < 60; ++i) ret_data_chunk_data[i] = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 60); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_cardemu_get_state(TF_NFC *nfc, uint8_t *ret_state, bool *ret_idle) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_CARDEMU_GET_STATE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_state != NULL) { *ret_state = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        if (ret_idle != NULL) { *ret_idle = tf_packetbuffer_read_bool(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_cardemu_start_discovery(TF_NFC *nfc) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_CARDEMU_START_DISCOVERY, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_CARDEMU_START_DISCOVERY, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_cardemu_write_ndef_low_level(TF_NFC *nfc, uint16_t ndef_length, uint16_t ndef_chunk_offset, uint8_t ndef_chunk_data[60]) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_CARDEMU_WRITE_NDEF_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_CARDEMU_WRITE_NDEF_LOW_LEVEL, 64, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    ndef_length = tf_leconvert_uint16_to(ndef_length); memcpy(buf + 0, &ndef_length, 2);
    ndef_chunk_offset = tf_leconvert_uint16_to(ndef_chunk_offset); memcpy(buf + 2, &ndef_chunk_offset, 2);
    memcpy(buf + 4, ndef_chunk_data, 60);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_cardemu_start_transfer(TF_NFC *nfc, uint8_t transfer) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_CARDEMU_START_TRANSFER, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_CARDEMU_START_TRANSFER, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    buf[0] = (uint8_t)transfer;

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_p2p_get_state(TF_NFC *nfc, uint8_t *ret_state, bool *ret_idle) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_P2P_GET_STATE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_state != NULL) { *ret_state = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        if (ret_idle != NULL) { *ret_idle = tf_packetbuffer_read_bool(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_p2p_start_discovery(TF_NFC *nfc) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_P2P_START_DISCOVERY, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_P2P_START_DISCOVERY, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_p2p_write_ndef_low_level(TF_NFC *nfc, uint16_t ndef_length, uint16_t ndef_chunk_offset, uint8_t ndef_chunk_data[60]) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_P2P_WRITE_NDEF_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_P2P_WRITE_NDEF_LOW_LEVEL, 64, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    ndef_length = tf_leconvert_uint16_to(ndef_length); memcpy(buf + 0, &ndef_length, 2);
    ndef_chunk_offset = tf_leconvert_uint16_to(ndef_chunk_offset); memcpy(buf + 2, &ndef_chunk_offset, 2);
    memcpy(buf + 4, ndef_chunk_data, 60);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_p2p_start_transfer(TF_NFC *nfc, uint8_t transfer) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_P2P_START_TRANSFER, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_P2P_START_TRANSFER, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    buf[0] = (uint8_t)transfer;

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_p2p_read_ndef_low_level(TF_NFC *nfc, uint16_t *ret_ndef_length, uint16_t *ret_ndef_chunk_offset, uint8_t ret_ndef_chunk_data[60]) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_P2P_READ_NDEF_LOW_LEVEL, 0, 64, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_ndef_length != NULL) { *ret_ndef_length = tf_packetbuffer_read_uint16_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 2); }
        if (ret_ndef_chunk_offset != NULL) { *ret_ndef_chunk_offset = tf_packetbuffer_read_uint16_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 2); }
        if (ret_ndef_chunk_data != NULL) { for (i = 0; i < 60; ++i) ret_ndef_chunk_data[i] = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 60); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_set_detection_led_config(TF_NFC *nfc, uint8_t config) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_SET_DETECTION_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_SET_DETECTION_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_get_detection_led_config(TF_NFC *nfc, uint8_t *ret_config) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_GET_DETECTION_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_set_maximum_timeout(TF_NFC *nfc, uint16_t timeout) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_SET_MAXIMUM_TIMEOUT, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_SET_MAXIMUM_TIMEOUT, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    timeout = tf_leconvert_uint16_to(timeout); memcpy(buf + 0, &timeout, 2);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_get_maximum_timeout(TF_NFC *nfc, uint16_t *ret_timeout) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_GET_MAXIMUM_TIMEOUT, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_timeout != NULL) { *ret_timeout = tf_packetbuffer_read_uint16_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_get_spitfp_error_count(TF_NFC *nfc, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_set_bootloader_mode(TF_NFC *nfc, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_get_bootloader_mode(TF_NFC *nfc, uint8_t *ret_mode) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_set_write_firmware_pointer(TF_NFC *nfc, uint32_t pointer) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_write_firmware(TF_NFC *nfc, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_set_status_led_config(TF_NFC *nfc, uint8_t config) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_get_status_led_config(TF_NFC *nfc, uint8_t *ret_config) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_get_chip_temperature(TF_NFC *nfc, int16_t *ret_temperature) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_reset(TF_NFC *nfc) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_write_uid(TF_NFC *nfc, uint32_t uid) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_nfc_get_response_expected(nfc, TF_NFC_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(nfc->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_read_uid(TF_NFC *nfc, uint32_t *ret_uid) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_get_identity(TF_NFC *nfc, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(nfc->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(nfc->tfp, TF_NFC_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(nfc->tfp->hal) + tf_hal_get_common(nfc->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(nfc->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&nfc->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&nfc->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&nfc->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&nfc->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&nfc->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(nfc->tfp->hal, nfc->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(nfc->tfp);
    }

    result = tf_tfp_finish_send(nfc->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_nfc_reader_get_tag_id(TF_NFC *nfc, uint8_t *ret_tag_type, uint8_t *ret_tag_id, uint8_t *ret_tag_id_length) {
    int ret = TF_E_OK;
    uint8_t tag_id_length = 0;
    uint8_t tag_id_data[32];

    *ret_tag_id_length = 0;

    ret = tf_nfc_reader_get_tag_id_low_level(nfc, ret_tag_type, &tag_id_length, tag_id_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    memcpy(ret_tag_id, tag_id_data, sizeof(uint8_t) * tag_id_length);
    memset(&tag_id_data[tag_id_length], 0, sizeof(uint8_t) * (32 - tag_id_length));

    *ret_tag_id_length = tag_id_length;

    return ret;
}

int tf_nfc_reader_write_ndef(TF_NFC *nfc, uint8_t *ndef, uint16_t ndef_length) {
    int ret = TF_E_OK;
    uint16_t ndef_chunk_offset = 0;
    uint8_t ndef_chunk_data[60];
    uint16_t ndef_chunk_length = 0;

    if (ndef_length == 0) {
        memset(&ndef_chunk_data, 0, sizeof(uint8_t) * 60);

        ret = tf_nfc_reader_write_ndef_low_level(nfc, ndef_length, ndef_chunk_offset, ndef_chunk_data);
    } else {

        while (ndef_chunk_offset < ndef_length) {
            ndef_chunk_length = ndef_length - ndef_chunk_offset;

            if (ndef_chunk_length > 60) {
                ndef_chunk_length = 60;
            }

            memcpy(ndef_chunk_data, &ndef[ndef_chunk_offset], sizeof(uint8_t) * ndef_chunk_length);
            memset(&ndef_chunk_data[ndef_chunk_length], 0, sizeof(uint8_t) * (60 - ndef_chunk_length));

            ret = tf_nfc_reader_write_ndef_low_level(nfc, ndef_length, ndef_chunk_offset, ndef_chunk_data);

            if (ret != TF_E_OK) {
                break;
            }

            ndef_chunk_offset += 60;
        }

    }

    return ret;
}

int tf_nfc_reader_read_ndef(TF_NFC *nfc, uint8_t *ret_ndef, uint16_t *ret_ndef_length) {
    int ret = TF_E_OK;
    uint16_t ndef_length = 0;
    uint16_t ndef_chunk_offset = 0;
    uint8_t ndef_chunk_data[60];
    bool ndef_out_of_sync;
    uint16_t ndef_chunk_length = 0;

    *ret_ndef_length = 0;

    ret = tf_nfc_reader_read_ndef_low_level(nfc, &ndef_length, &ndef_chunk_offset, ndef_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    ndef_out_of_sync = ndef_chunk_offset != 0;

    if (!ndef_out_of_sync) {
        ndef_chunk_length = ndef_length - ndef_chunk_offset;

        if (ndef_chunk_length > 60) {
            ndef_chunk_length = 60;
        }

        memcpy(ret_ndef, ndef_chunk_data, sizeof(uint8_t) * ndef_chunk_length);
        *ret_ndef_length = ndef_chunk_length;

        while (*ret_ndef_length < ndef_length) {
            ret = tf_nfc_reader_read_ndef_low_level(nfc, &ndef_length, &ndef_chunk_offset, ndef_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            ndef_out_of_sync = ndef_chunk_offset != *ret_ndef_length;

            if (ndef_out_of_sync) {
                break;
            }

            ndef_chunk_length = ndef_length - ndef_chunk_offset;

            if (ndef_chunk_length > 60) {
                ndef_chunk_length = 60;
            }

            memcpy(&ret_ndef[*ret_ndef_length], ndef_chunk_data, sizeof(uint8_t) * ndef_chunk_length);
            *ret_ndef_length += ndef_chunk_length;
        }
    }

    if (ndef_out_of_sync) {
        *ret_ndef_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (ndef_chunk_offset + 60 < ndef_length) {
            ret = tf_nfc_reader_read_ndef_low_level(nfc, &ndef_length, &ndef_chunk_offset, ndef_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}

int tf_nfc_reader_write_page(TF_NFC *nfc, uint16_t page, uint8_t *data, uint16_t data_length) {
    int ret = TF_E_OK;
    uint16_t data_chunk_offset = 0;
    uint8_t data_chunk_data[58];
    uint16_t data_chunk_length = 0;

    if (data_length == 0) {
        memset(&data_chunk_data, 0, sizeof(uint8_t) * 58);

        ret = tf_nfc_reader_write_page_low_level(nfc, page, data_length, data_chunk_offset, data_chunk_data);
    } else {

        while (data_chunk_offset < data_length) {
            data_chunk_length = data_length - data_chunk_offset;

            if (data_chunk_length > 58) {
                data_chunk_length = 58;
            }

            memcpy(data_chunk_data, &data[data_chunk_offset], sizeof(uint8_t) * data_chunk_length);
            memset(&data_chunk_data[data_chunk_length], 0, sizeof(uint8_t) * (58 - data_chunk_length));

            ret = tf_nfc_reader_write_page_low_level(nfc, page, data_length, data_chunk_offset, data_chunk_data);

            if (ret != TF_E_OK) {
                break;
            }

            data_chunk_offset += 58;
        }

    }

    return ret;
}

int tf_nfc_reader_read_page(TF_NFC *nfc, uint8_t *ret_data, uint16_t *ret_data_length) {
    int ret = TF_E_OK;
    uint16_t data_length = 0;
    uint16_t data_chunk_offset = 0;
    uint8_t data_chunk_data[60];
    bool data_out_of_sync;
    uint16_t data_chunk_length = 0;

    *ret_data_length = 0;

    ret = tf_nfc_reader_read_page_low_level(nfc, &data_length, &data_chunk_offset, data_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    data_out_of_sync = data_chunk_offset != 0;

    if (!data_out_of_sync) {
        data_chunk_length = data_length - data_chunk_offset;

        if (data_chunk_length > 60) {
            data_chunk_length = 60;
        }

        memcpy(ret_data, data_chunk_data, sizeof(uint8_t) * data_chunk_length);
        *ret_data_length = data_chunk_length;

        while (*ret_data_length < data_length) {
            ret = tf_nfc_reader_read_page_low_level(nfc, &data_length, &data_chunk_offset, data_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            data_out_of_sync = data_chunk_offset != *ret_data_length;

            if (data_out_of_sync) {
                break;
            }

            data_chunk_length = data_length - data_chunk_offset;

            if (data_chunk_length > 60) {
                data_chunk_length = 60;
            }

            memcpy(&ret_data[*ret_data_length], data_chunk_data, sizeof(uint8_t) * data_chunk_length);
            *ret_data_length += data_chunk_length;
        }
    }

    if (data_out_of_sync) {
        *ret_data_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (data_chunk_offset + 60 < data_length) {
            ret = tf_nfc_reader_read_page_low_level(nfc, &data_length, &data_chunk_offset, data_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}

int tf_nfc_cardemu_write_ndef(TF_NFC *nfc, uint8_t *ndef, uint16_t ndef_length) {
    int ret = TF_E_OK;
    uint16_t ndef_chunk_offset = 0;
    uint8_t ndef_chunk_data[60];
    uint16_t ndef_chunk_length = 0;

    if (ndef_length == 0) {
        memset(&ndef_chunk_data, 0, sizeof(uint8_t) * 60);

        ret = tf_nfc_cardemu_write_ndef_low_level(nfc, ndef_length, ndef_chunk_offset, ndef_chunk_data);
    } else {

        while (ndef_chunk_offset < ndef_length) {
            ndef_chunk_length = ndef_length - ndef_chunk_offset;

            if (ndef_chunk_length > 60) {
                ndef_chunk_length = 60;
            }

            memcpy(ndef_chunk_data, &ndef[ndef_chunk_offset], sizeof(uint8_t) * ndef_chunk_length);
            memset(&ndef_chunk_data[ndef_chunk_length], 0, sizeof(uint8_t) * (60 - ndef_chunk_length));

            ret = tf_nfc_cardemu_write_ndef_low_level(nfc, ndef_length, ndef_chunk_offset, ndef_chunk_data);

            if (ret != TF_E_OK) {
                break;
            }

            ndef_chunk_offset += 60;
        }

    }

    return ret;
}

int tf_nfc_p2p_write_ndef(TF_NFC *nfc, uint8_t *ndef, uint16_t ndef_length) {
    int ret = TF_E_OK;
    uint16_t ndef_chunk_offset = 0;
    uint8_t ndef_chunk_data[60];
    uint16_t ndef_chunk_length = 0;

    if (ndef_length == 0) {
        memset(&ndef_chunk_data, 0, sizeof(uint8_t) * 60);

        ret = tf_nfc_p2p_write_ndef_low_level(nfc, ndef_length, ndef_chunk_offset, ndef_chunk_data);
    } else {

        while (ndef_chunk_offset < ndef_length) {
            ndef_chunk_length = ndef_length - ndef_chunk_offset;

            if (ndef_chunk_length > 60) {
                ndef_chunk_length = 60;
            }

            memcpy(ndef_chunk_data, &ndef[ndef_chunk_offset], sizeof(uint8_t) * ndef_chunk_length);
            memset(&ndef_chunk_data[ndef_chunk_length], 0, sizeof(uint8_t) * (60 - ndef_chunk_length));

            ret = tf_nfc_p2p_write_ndef_low_level(nfc, ndef_length, ndef_chunk_offset, ndef_chunk_data);

            if (ret != TF_E_OK) {
                break;
            }

            ndef_chunk_offset += 60;
        }

    }

    return ret;
}

int tf_nfc_p2p_read_ndef(TF_NFC *nfc, uint8_t *ret_ndef, uint16_t *ret_ndef_length) {
    int ret = TF_E_OK;
    uint16_t ndef_length = 0;
    uint16_t ndef_chunk_offset = 0;
    uint8_t ndef_chunk_data[60];
    bool ndef_out_of_sync;
    uint16_t ndef_chunk_length = 0;

    *ret_ndef_length = 0;

    ret = tf_nfc_p2p_read_ndef_low_level(nfc, &ndef_length, &ndef_chunk_offset, ndef_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    ndef_out_of_sync = ndef_chunk_offset != 0;

    if (!ndef_out_of_sync) {
        ndef_chunk_length = ndef_length - ndef_chunk_offset;

        if (ndef_chunk_length > 60) {
            ndef_chunk_length = 60;
        }

        memcpy(ret_ndef, ndef_chunk_data, sizeof(uint8_t) * ndef_chunk_length);
        *ret_ndef_length = ndef_chunk_length;

        while (*ret_ndef_length < ndef_length) {
            ret = tf_nfc_p2p_read_ndef_low_level(nfc, &ndef_length, &ndef_chunk_offset, ndef_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            ndef_out_of_sync = ndef_chunk_offset != *ret_ndef_length;

            if (ndef_out_of_sync) {
                break;
            }

            ndef_chunk_length = ndef_length - ndef_chunk_offset;

            if (ndef_chunk_length > 60) {
                ndef_chunk_length = 60;
            }

            memcpy(&ret_ndef[*ret_ndef_length], ndef_chunk_data, sizeof(uint8_t) * ndef_chunk_length);
            *ret_ndef_length += ndef_chunk_length;
        }
    }

    if (ndef_out_of_sync) {
        *ret_ndef_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (ndef_chunk_offset + 60 < ndef_length) {
            ret = tf_nfc_p2p_read_ndef_low_level(nfc, &ndef_length, &ndef_chunk_offset, ndef_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_nfc_register_reader_state_changed_callback(TF_NFC *nfc, TF_NFCReaderStateChangedHandler handler, void *user_data) {
    if (handler == NULL) {
        nfc->tfp->needs_callback_tick = false;
        nfc->tfp->needs_callback_tick |= nfc->cardemu_state_changed_handler != NULL;
        nfc->tfp->needs_callback_tick |= nfc->p2p_state_changed_handler != NULL;
    } else {
        nfc->tfp->needs_callback_tick = true;
    }
    nfc->reader_state_changed_handler = handler;
    nfc->reader_state_changed_user_data = user_data;
}


void tf_nfc_register_cardemu_state_changed_callback(TF_NFC *nfc, TF_NFCCardemuStateChangedHandler handler, void *user_data) {
    if (handler == NULL) {
        nfc->tfp->needs_callback_tick = false;
        nfc->tfp->needs_callback_tick |= nfc->reader_state_changed_handler != NULL;
        nfc->tfp->needs_callback_tick |= nfc->p2p_state_changed_handler != NULL;
    } else {
        nfc->tfp->needs_callback_tick = true;
    }
    nfc->cardemu_state_changed_handler = handler;
    nfc->cardemu_state_changed_user_data = user_data;
}


void tf_nfc_register_p2p_state_changed_callback(TF_NFC *nfc, TF_NFCP2PStateChangedHandler handler, void *user_data) {
    if (handler == NULL) {
        nfc->tfp->needs_callback_tick = false;
        nfc->tfp->needs_callback_tick |= nfc->reader_state_changed_handler != NULL;
        nfc->tfp->needs_callback_tick |= nfc->cardemu_state_changed_handler != NULL;
    } else {
        nfc->tfp->needs_callback_tick = true;
    }
    nfc->p2p_state_changed_handler = handler;
    nfc->p2p_state_changed_user_data = user_data;
}
#endif
int tf_nfc_callback_tick(TF_NFC *nfc, uint32_t timeout_us) {
    return tf_tfp_callback_tick(nfc->tfp, tf_hal_current_time_us(nfc->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
