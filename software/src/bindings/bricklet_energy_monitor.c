/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_energy_monitor.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_energy_monitor_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_EnergyMonitor *energy_monitor = (TF_EnergyMonitor *) dev;
    (void)payload;

    switch(fid) {

        case TF_ENERGY_MONITOR_CALLBACK_ENERGY_DATA: {
            TF_EnergyMonitorEnergyDataHandler fn = energy_monitor->energy_data_handler;
            void *user_data = energy_monitor->energy_data_user_data;
            if (fn == NULL)
                return false;

            int32_t voltage = tf_packetbuffer_read_int32_t(payload);
            int32_t current = tf_packetbuffer_read_int32_t(payload);
            int32_t energy = tf_packetbuffer_read_int32_t(payload);
            int32_t real_power = tf_packetbuffer_read_int32_t(payload);
            int32_t apparent_power = tf_packetbuffer_read_int32_t(payload);
            int32_t reactive_power = tf_packetbuffer_read_int32_t(payload);
            uint16_t power_factor = tf_packetbuffer_read_uint16_t(payload);
            uint16_t frequency = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(energy_monitor->tfp->hal);
            common->locked = true;
            fn(energy_monitor, voltage, current, energy, real_power, apparent_power, reactive_power, power_factor, frequency, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_energy_monitor_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_energy_monitor_create(TF_EnergyMonitor *energy_monitor, const char *uid, TF_HalContext *hal) {
    memset(energy_monitor, 0, sizeof(TF_EnergyMonitor));

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

    //rc = tf_tfp_init(energy_monitor->tfp, numeric_uid, TF_ENERGY_MONITOR_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_energy_monitor_callback_handler);
    rc = tf_hal_get_tfp(hal, &energy_monitor->tfp, TF_ENERGY_MONITOR_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    energy_monitor->tfp->device = energy_monitor;
    energy_monitor->tfp->uid = numeric_uid;
    energy_monitor->tfp->cb_handler = tf_energy_monitor_callback_handler;
    energy_monitor->response_expected[0] = 0x08;
    return TF_E_OK;
}

int tf_energy_monitor_destroy(TF_EnergyMonitor *energy_monitor) {
    int result = tf_tfp_destroy(energy_monitor->tfp);
    energy_monitor->tfp = NULL;
    return result;
}

int tf_energy_monitor_get_response_expected(TF_EnergyMonitor *energy_monitor, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_ENERGY_MONITOR_FUNCTION_RESET_ENERGY:
            if(ret_response_expected != NULL)
                *ret_response_expected = (energy_monitor->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_ENERGY_MONITOR_FUNCTION_SET_TRANSFORMER_CALIBRATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (energy_monitor->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_ENERGY_MONITOR_FUNCTION_CALIBRATE_OFFSET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (energy_monitor->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_ENERGY_MONITOR_FUNCTION_SET_ENERGY_DATA_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (energy_monitor->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_ENERGY_MONITOR_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (energy_monitor->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_ENERGY_MONITOR_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (energy_monitor->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_ENERGY_MONITOR_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (energy_monitor->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_ENERGY_MONITOR_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (energy_monitor->response_expected[0] & (1 << 7)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_energy_monitor_set_response_expected(TF_EnergyMonitor *energy_monitor, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_ENERGY_MONITOR_FUNCTION_RESET_ENERGY:
            if (response_expected) {
                energy_monitor->response_expected[0] |= (1 << 0);
            } else {
                energy_monitor->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_ENERGY_MONITOR_FUNCTION_SET_TRANSFORMER_CALIBRATION:
            if (response_expected) {
                energy_monitor->response_expected[0] |= (1 << 1);
            } else {
                energy_monitor->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_ENERGY_MONITOR_FUNCTION_CALIBRATE_OFFSET:
            if (response_expected) {
                energy_monitor->response_expected[0] |= (1 << 2);
            } else {
                energy_monitor->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_ENERGY_MONITOR_FUNCTION_SET_ENERGY_DATA_CALLBACK_CONFIGURATION:
            if (response_expected) {
                energy_monitor->response_expected[0] |= (1 << 3);
            } else {
                energy_monitor->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_ENERGY_MONITOR_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                energy_monitor->response_expected[0] |= (1 << 4);
            } else {
                energy_monitor->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_ENERGY_MONITOR_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                energy_monitor->response_expected[0] |= (1 << 5);
            } else {
                energy_monitor->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_ENERGY_MONITOR_FUNCTION_RESET:
            if (response_expected) {
                energy_monitor->response_expected[0] |= (1 << 6);
            } else {
                energy_monitor->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_ENERGY_MONITOR_FUNCTION_WRITE_UID:
            if (response_expected) {
                energy_monitor->response_expected[0] |= (1 << 7);
            } else {
                energy_monitor->response_expected[0] &= ~(1 << 7);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_energy_monitor_set_response_expected_all(TF_EnergyMonitor *energy_monitor, bool response_expected) {
    memset(energy_monitor->response_expected, response_expected ? 0xFF : 0, 1);
}

int tf_energy_monitor_get_energy_data(TF_EnergyMonitor *energy_monitor, int32_t *ret_voltage, int32_t *ret_current, int32_t *ret_energy, int32_t *ret_real_power, int32_t *ret_apparent_power, int32_t *ret_reactive_power, uint16_t *ret_power_factor, uint16_t *ret_frequency) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_GET_ENERGY_DATA, 0, 28, response_expected);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_voltage != NULL) { *ret_voltage = tf_packetbuffer_read_int32_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 4); }
        if (ret_current != NULL) { *ret_current = tf_packetbuffer_read_int32_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 4); }
        if (ret_energy != NULL) { *ret_energy = tf_packetbuffer_read_int32_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 4); }
        if (ret_real_power != NULL) { *ret_real_power = tf_packetbuffer_read_int32_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 4); }
        if (ret_apparent_power != NULL) { *ret_apparent_power = tf_packetbuffer_read_int32_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 4); }
        if (ret_reactive_power != NULL) { *ret_reactive_power = tf_packetbuffer_read_int32_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 4); }
        if (ret_power_factor != NULL) { *ret_power_factor = tf_packetbuffer_read_uint16_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 2); }
        if (ret_frequency != NULL) { *ret_frequency = tf_packetbuffer_read_uint16_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_reset_energy(TF_EnergyMonitor *energy_monitor) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_energy_monitor_get_response_expected(energy_monitor, TF_ENERGY_MONITOR_FUNCTION_RESET_ENERGY, &response_expected);
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_RESET_ENERGY, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_get_waveform_low_level(TF_EnergyMonitor *energy_monitor, uint16_t *ret_waveform_chunk_offset, int16_t ret_waveform_chunk_data[30]) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_GET_WAVEFORM_LOW_LEVEL, 0, 62, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_waveform_chunk_offset != NULL) { *ret_waveform_chunk_offset = tf_packetbuffer_read_uint16_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 2); }
        if (ret_waveform_chunk_data != NULL) { for (i = 0; i < 30; ++i) ret_waveform_chunk_data[i] = tf_packetbuffer_read_int16_t(&energy_monitor->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 60); }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_get_transformer_status(TF_EnergyMonitor *energy_monitor, bool *ret_voltage_transformer_connected, bool *ret_current_transformer_connected) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_GET_TRANSFORMER_STATUS, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_voltage_transformer_connected != NULL) { *ret_voltage_transformer_connected = tf_packetbuffer_read_bool(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 1); }
        if (ret_current_transformer_connected != NULL) { *ret_current_transformer_connected = tf_packetbuffer_read_bool(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_set_transformer_calibration(TF_EnergyMonitor *energy_monitor, uint16_t voltage_ratio, uint16_t current_ratio, int16_t phase_shift) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_energy_monitor_get_response_expected(energy_monitor, TF_ENERGY_MONITOR_FUNCTION_SET_TRANSFORMER_CALIBRATION, &response_expected);
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_SET_TRANSFORMER_CALIBRATION, 6, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(energy_monitor->tfp);

    voltage_ratio = tf_leconvert_uint16_to(voltage_ratio); memcpy(buf + 0, &voltage_ratio, 2);
    current_ratio = tf_leconvert_uint16_to(current_ratio); memcpy(buf + 2, &current_ratio, 2);
    phase_shift = tf_leconvert_int16_to(phase_shift); memcpy(buf + 4, &phase_shift, 2);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_get_transformer_calibration(TF_EnergyMonitor *energy_monitor, uint16_t *ret_voltage_ratio, uint16_t *ret_current_ratio, int16_t *ret_phase_shift) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_GET_TRANSFORMER_CALIBRATION, 0, 6, response_expected);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_voltage_ratio != NULL) { *ret_voltage_ratio = tf_packetbuffer_read_uint16_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 2); }
        if (ret_current_ratio != NULL) { *ret_current_ratio = tf_packetbuffer_read_uint16_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 2); }
        if (ret_phase_shift != NULL) { *ret_phase_shift = tf_packetbuffer_read_int16_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_calibrate_offset(TF_EnergyMonitor *energy_monitor) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_energy_monitor_get_response_expected(energy_monitor, TF_ENERGY_MONITOR_FUNCTION_CALIBRATE_OFFSET, &response_expected);
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_CALIBRATE_OFFSET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_set_energy_data_callback_configuration(TF_EnergyMonitor *energy_monitor, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_energy_monitor_get_response_expected(energy_monitor, TF_ENERGY_MONITOR_FUNCTION_SET_ENERGY_DATA_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_SET_ENERGY_DATA_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(energy_monitor->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_get_energy_data_callback_configuration(TF_EnergyMonitor *energy_monitor, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_GET_ENERGY_DATA_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_get_spitfp_error_count(TF_EnergyMonitor *energy_monitor, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_set_bootloader_mode(TF_EnergyMonitor *energy_monitor, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(energy_monitor->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_get_bootloader_mode(TF_EnergyMonitor *energy_monitor, uint8_t *ret_mode) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_set_write_firmware_pointer(TF_EnergyMonitor *energy_monitor, uint32_t pointer) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_energy_monitor_get_response_expected(energy_monitor, TF_ENERGY_MONITOR_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(energy_monitor->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_write_firmware(TF_EnergyMonitor *energy_monitor, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(energy_monitor->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_set_status_led_config(TF_EnergyMonitor *energy_monitor, uint8_t config) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_energy_monitor_get_response_expected(energy_monitor, TF_ENERGY_MONITOR_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(energy_monitor->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_get_status_led_config(TF_EnergyMonitor *energy_monitor, uint8_t *ret_config) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_get_chip_temperature(TF_EnergyMonitor *energy_monitor, int16_t *ret_temperature) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_reset(TF_EnergyMonitor *energy_monitor) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_energy_monitor_get_response_expected(energy_monitor, TF_ENERGY_MONITOR_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_write_uid(TF_EnergyMonitor *energy_monitor, uint32_t uid) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_energy_monitor_get_response_expected(energy_monitor, TF_ENERGY_MONITOR_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(energy_monitor->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_read_uid(TF_EnergyMonitor *energy_monitor, uint32_t *ret_uid) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_get_identity(TF_EnergyMonitor *energy_monitor, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(energy_monitor->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(energy_monitor->tfp, TF_ENERGY_MONITOR_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(energy_monitor->tfp->hal) + tf_hal_get_common(energy_monitor->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(energy_monitor->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&energy_monitor->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&energy_monitor->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&energy_monitor->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&energy_monitor->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&energy_monitor->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&energy_monitor->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(energy_monitor->tfp->hal, energy_monitor->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(energy_monitor->tfp);
    }

    result = tf_tfp_finish_send(energy_monitor->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_energy_monitor_get_waveform(TF_EnergyMonitor *energy_monitor, int16_t *ret_waveform, uint16_t *ret_waveform_length) {
    int ret = TF_E_OK;
    uint16_t waveform_length = 1536;
    uint16_t waveform_chunk_offset = 0;
    int16_t waveform_chunk_data[30];
    bool waveform_out_of_sync;
    uint16_t waveform_chunk_length = 0;

    *ret_waveform_length = 0;

    ret = tf_energy_monitor_get_waveform_low_level(energy_monitor, &waveform_chunk_offset, waveform_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    if (waveform_chunk_offset == (1 << 16) - 1) { // maximum chunk offset -> stream has no data
        return ret;
    }

    waveform_out_of_sync = waveform_chunk_offset != 0;

    if (!waveform_out_of_sync) {
        waveform_chunk_length = waveform_length - waveform_chunk_offset;

        if (waveform_chunk_length > 30) {
            waveform_chunk_length = 30;
        }

        memcpy(ret_waveform, waveform_chunk_data, sizeof(int16_t) * waveform_chunk_length);
        *ret_waveform_length = waveform_chunk_length;

        while (*ret_waveform_length < waveform_length) {
            ret = tf_energy_monitor_get_waveform_low_level(energy_monitor, &waveform_chunk_offset, waveform_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            waveform_out_of_sync = waveform_chunk_offset != *ret_waveform_length;

            if (waveform_out_of_sync) {
                break;
            }

            waveform_chunk_length = waveform_length - waveform_chunk_offset;

            if (waveform_chunk_length > 30) {
                waveform_chunk_length = 30;
            }

            memcpy(&ret_waveform[*ret_waveform_length], waveform_chunk_data, sizeof(int16_t) * waveform_chunk_length);
            *ret_waveform_length += waveform_chunk_length;
        }
    }

    if (waveform_out_of_sync) {
        *ret_waveform_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (waveform_chunk_offset + 30 < waveform_length) {
            ret = tf_energy_monitor_get_waveform_low_level(energy_monitor, &waveform_chunk_offset, waveform_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_energy_monitor_register_energy_data_callback(TF_EnergyMonitor *energy_monitor, TF_EnergyMonitorEnergyDataHandler handler, void *user_data) {
    if (handler == NULL) {
        energy_monitor->tfp->needs_callback_tick = false;
        
    } else {
        energy_monitor->tfp->needs_callback_tick = true;
    }
    energy_monitor->energy_data_handler = handler;
    energy_monitor->energy_data_user_data = user_data;
}
#endif
int tf_energy_monitor_callback_tick(TF_EnergyMonitor *energy_monitor, uint32_t timeout_us) {
    return tf_tfp_callback_tick(energy_monitor->tfp, tf_hal_current_time_us(energy_monitor->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
