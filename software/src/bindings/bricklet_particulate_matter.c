/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_particulate_matter.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_particulate_matter_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_ParticulateMatter *particulate_matter = (TF_ParticulateMatter *) dev;
    (void)payload;

    switch(fid) {

        case TF_PARTICULATE_MATTER_CALLBACK_PM_CONCENTRATION: {
            TF_ParticulateMatterPMConcentrationHandler fn = particulate_matter->pm_concentration_handler;
            void *user_data = particulate_matter->pm_concentration_user_data;
            if (fn == NULL)
                return false;

            uint16_t pm10 = tf_packetbuffer_read_uint16_t(payload);
            uint16_t pm25 = tf_packetbuffer_read_uint16_t(payload);
            uint16_t pm100 = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(particulate_matter->tfp->hal);
            common->locked = true;
            fn(particulate_matter, pm10, pm25, pm100, user_data);
            common->locked = false;
            break;
        }

        case TF_PARTICULATE_MATTER_CALLBACK_PM_COUNT: {
            TF_ParticulateMatterPMCountHandler fn = particulate_matter->pm_count_handler;
            void *user_data = particulate_matter->pm_count_user_data;
            if (fn == NULL)
                return false;

            uint16_t greater03um = tf_packetbuffer_read_uint16_t(payload);
            uint16_t greater05um = tf_packetbuffer_read_uint16_t(payload);
            uint16_t greater10um = tf_packetbuffer_read_uint16_t(payload);
            uint16_t greater25um = tf_packetbuffer_read_uint16_t(payload);
            uint16_t greater50um = tf_packetbuffer_read_uint16_t(payload);
            uint16_t greater100um = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(particulate_matter->tfp->hal);
            common->locked = true;
            fn(particulate_matter, greater03um, greater05um, greater10um, greater25um, greater50um, greater100um, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_particulate_matter_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_particulate_matter_create(TF_ParticulateMatter *particulate_matter, const char *uid, TF_HalContext *hal) {
    memset(particulate_matter, 0, sizeof(TF_ParticulateMatter));

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

    //rc = tf_tfp_init(particulate_matter->tfp, numeric_uid, TF_PARTICULATE_MATTER_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_particulate_matter_callback_handler);
    rc = tf_hal_get_tfp(hal, &particulate_matter->tfp, TF_PARTICULATE_MATTER_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    particulate_matter->tfp->device = particulate_matter;
    particulate_matter->tfp->uid = numeric_uid;
    particulate_matter->tfp->cb_handler = tf_particulate_matter_callback_handler;
    particulate_matter->response_expected[0] = 0x06;
    return TF_E_OK;
}

int tf_particulate_matter_destroy(TF_ParticulateMatter *particulate_matter) {
    int result = tf_tfp_destroy(particulate_matter->tfp);
    particulate_matter->tfp = NULL;
    return result;
}

int tf_particulate_matter_get_response_expected(TF_ParticulateMatter *particulate_matter, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_PARTICULATE_MATTER_FUNCTION_SET_ENABLE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (particulate_matter->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_PARTICULATE_MATTER_FUNCTION_SET_PM_CONCENTRATION_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (particulate_matter->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_PARTICULATE_MATTER_FUNCTION_SET_PM_COUNT_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (particulate_matter->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_PARTICULATE_MATTER_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (particulate_matter->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_PARTICULATE_MATTER_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (particulate_matter->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_PARTICULATE_MATTER_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (particulate_matter->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_PARTICULATE_MATTER_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (particulate_matter->response_expected[0] & (1 << 6)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_particulate_matter_set_response_expected(TF_ParticulateMatter *particulate_matter, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_PARTICULATE_MATTER_FUNCTION_SET_ENABLE:
            if (response_expected) {
                particulate_matter->response_expected[0] |= (1 << 0);
            } else {
                particulate_matter->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_PARTICULATE_MATTER_FUNCTION_SET_PM_CONCENTRATION_CALLBACK_CONFIGURATION:
            if (response_expected) {
                particulate_matter->response_expected[0] |= (1 << 1);
            } else {
                particulate_matter->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_PARTICULATE_MATTER_FUNCTION_SET_PM_COUNT_CALLBACK_CONFIGURATION:
            if (response_expected) {
                particulate_matter->response_expected[0] |= (1 << 2);
            } else {
                particulate_matter->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_PARTICULATE_MATTER_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                particulate_matter->response_expected[0] |= (1 << 3);
            } else {
                particulate_matter->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_PARTICULATE_MATTER_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                particulate_matter->response_expected[0] |= (1 << 4);
            } else {
                particulate_matter->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_PARTICULATE_MATTER_FUNCTION_RESET:
            if (response_expected) {
                particulate_matter->response_expected[0] |= (1 << 5);
            } else {
                particulate_matter->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_PARTICULATE_MATTER_FUNCTION_WRITE_UID:
            if (response_expected) {
                particulate_matter->response_expected[0] |= (1 << 6);
            } else {
                particulate_matter->response_expected[0] &= ~(1 << 6);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_particulate_matter_set_response_expected_all(TF_ParticulateMatter *particulate_matter, bool response_expected) {
    memset(particulate_matter->response_expected, response_expected ? 0xFF : 0, 1);
}

int tf_particulate_matter_get_pm_concentration(TF_ParticulateMatter *particulate_matter, uint16_t *ret_pm10, uint16_t *ret_pm25, uint16_t *ret_pm100) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_GET_PM_CONCENTRATION, 0, 6, response_expected);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_pm10 != NULL) { *ret_pm10 = tf_packetbuffer_read_uint16_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 2); }
        if (ret_pm25 != NULL) { *ret_pm25 = tf_packetbuffer_read_uint16_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 2); }
        if (ret_pm100 != NULL) { *ret_pm100 = tf_packetbuffer_read_uint16_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_get_pm_count(TF_ParticulateMatter *particulate_matter, uint16_t *ret_greater03um, uint16_t *ret_greater05um, uint16_t *ret_greater10um, uint16_t *ret_greater25um, uint16_t *ret_greater50um, uint16_t *ret_greater100um) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_GET_PM_COUNT, 0, 12, response_expected);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_greater03um != NULL) { *ret_greater03um = tf_packetbuffer_read_uint16_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 2); }
        if (ret_greater05um != NULL) { *ret_greater05um = tf_packetbuffer_read_uint16_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 2); }
        if (ret_greater10um != NULL) { *ret_greater10um = tf_packetbuffer_read_uint16_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 2); }
        if (ret_greater25um != NULL) { *ret_greater25um = tf_packetbuffer_read_uint16_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 2); }
        if (ret_greater50um != NULL) { *ret_greater50um = tf_packetbuffer_read_uint16_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 2); }
        if (ret_greater100um != NULL) { *ret_greater100um = tf_packetbuffer_read_uint16_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_set_enable(TF_ParticulateMatter *particulate_matter, bool enable) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_particulate_matter_get_response_expected(particulate_matter, TF_PARTICULATE_MATTER_FUNCTION_SET_ENABLE, &response_expected);
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_SET_ENABLE, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(particulate_matter->tfp);

    buf[0] = enable ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_get_enable(TF_ParticulateMatter *particulate_matter, bool *ret_enable) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_GET_ENABLE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enable != NULL) { *ret_enable = tf_packetbuffer_read_bool(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_get_sensor_info(TF_ParticulateMatter *particulate_matter, uint8_t *ret_sensor_version, uint8_t *ret_last_error_code, uint8_t *ret_framing_error_count, uint8_t *ret_checksum_error_count) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_GET_SENSOR_INFO, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_sensor_version != NULL) { *ret_sensor_version = tf_packetbuffer_read_uint8_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 1); }
        if (ret_last_error_code != NULL) { *ret_last_error_code = tf_packetbuffer_read_uint8_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 1); }
        if (ret_framing_error_count != NULL) { *ret_framing_error_count = tf_packetbuffer_read_uint8_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 1); }
        if (ret_checksum_error_count != NULL) { *ret_checksum_error_count = tf_packetbuffer_read_uint8_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_set_pm_concentration_callback_configuration(TF_ParticulateMatter *particulate_matter, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_particulate_matter_get_response_expected(particulate_matter, TF_PARTICULATE_MATTER_FUNCTION_SET_PM_CONCENTRATION_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_SET_PM_CONCENTRATION_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(particulate_matter->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_get_pm_concentration_callback_configuration(TF_ParticulateMatter *particulate_matter, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_GET_PM_CONCENTRATION_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_set_pm_count_callback_configuration(TF_ParticulateMatter *particulate_matter, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_particulate_matter_get_response_expected(particulate_matter, TF_PARTICULATE_MATTER_FUNCTION_SET_PM_COUNT_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_SET_PM_COUNT_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(particulate_matter->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_get_pm_count_callback_configuration(TF_ParticulateMatter *particulate_matter, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_GET_PM_COUNT_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_get_spitfp_error_count(TF_ParticulateMatter *particulate_matter, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_set_bootloader_mode(TF_ParticulateMatter *particulate_matter, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(particulate_matter->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_get_bootloader_mode(TF_ParticulateMatter *particulate_matter, uint8_t *ret_mode) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_set_write_firmware_pointer(TF_ParticulateMatter *particulate_matter, uint32_t pointer) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_particulate_matter_get_response_expected(particulate_matter, TF_PARTICULATE_MATTER_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(particulate_matter->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_write_firmware(TF_ParticulateMatter *particulate_matter, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(particulate_matter->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_set_status_led_config(TF_ParticulateMatter *particulate_matter, uint8_t config) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_particulate_matter_get_response_expected(particulate_matter, TF_PARTICULATE_MATTER_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(particulate_matter->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_get_status_led_config(TF_ParticulateMatter *particulate_matter, uint8_t *ret_config) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_get_chip_temperature(TF_ParticulateMatter *particulate_matter, int16_t *ret_temperature) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_reset(TF_ParticulateMatter *particulate_matter) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_particulate_matter_get_response_expected(particulate_matter, TF_PARTICULATE_MATTER_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_write_uid(TF_ParticulateMatter *particulate_matter, uint32_t uid) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_particulate_matter_get_response_expected(particulate_matter, TF_PARTICULATE_MATTER_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(particulate_matter->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_read_uid(TF_ParticulateMatter *particulate_matter, uint32_t *ret_uid) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_particulate_matter_get_identity(TF_ParticulateMatter *particulate_matter, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(particulate_matter->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(particulate_matter->tfp, TF_PARTICULATE_MATTER_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(particulate_matter->tfp->hal) + tf_hal_get_common(particulate_matter->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(particulate_matter->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&particulate_matter->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&particulate_matter->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&particulate_matter->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&particulate_matter->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&particulate_matter->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&particulate_matter->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(particulate_matter->tfp->hal, particulate_matter->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(particulate_matter->tfp);
    }

    result = tf_tfp_finish_send(particulate_matter->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_particulate_matter_register_pm_concentration_callback(TF_ParticulateMatter *particulate_matter, TF_ParticulateMatterPMConcentrationHandler handler, void *user_data) {
    if (handler == NULL) {
        particulate_matter->tfp->needs_callback_tick = false;
        particulate_matter->tfp->needs_callback_tick |= particulate_matter->pm_count_handler != NULL;
    } else {
        particulate_matter->tfp->needs_callback_tick = true;
    }
    particulate_matter->pm_concentration_handler = handler;
    particulate_matter->pm_concentration_user_data = user_data;
}


void tf_particulate_matter_register_pm_count_callback(TF_ParticulateMatter *particulate_matter, TF_ParticulateMatterPMCountHandler handler, void *user_data) {
    if (handler == NULL) {
        particulate_matter->tfp->needs_callback_tick = false;
        particulate_matter->tfp->needs_callback_tick |= particulate_matter->pm_concentration_handler != NULL;
    } else {
        particulate_matter->tfp->needs_callback_tick = true;
    }
    particulate_matter->pm_count_handler = handler;
    particulate_matter->pm_count_user_data = user_data;
}
#endif
int tf_particulate_matter_callback_tick(TF_ParticulateMatter *particulate_matter, uint32_t timeout_us) {
    return tf_tfp_callback_tick(particulate_matter->tfp, tf_hal_current_time_us(particulate_matter->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
