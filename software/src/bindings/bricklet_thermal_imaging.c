/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_thermal_imaging.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_thermal_imaging_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_ThermalImaging *thermal_imaging = (TF_ThermalImaging *) dev;
    (void)payload;

    switch(fid) {

        case TF_THERMAL_IMAGING_CALLBACK_HIGH_CONTRAST_IMAGE_LOW_LEVEL: {
            TF_ThermalImagingHighContrastImageLowLevelHandler fn = thermal_imaging->high_contrast_image_low_level_handler;
            void *user_data = thermal_imaging->high_contrast_image_low_level_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            uint16_t image_chunk_offset = tf_packetbuffer_read_uint16_t(payload);
            uint8_t image_chunk_data[62]; for (i = 0; i < 62; ++i) image_chunk_data[i] = tf_packetbuffer_read_uint8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(thermal_imaging->tfp->hal);
            common->locked = true;
            fn(thermal_imaging, image_chunk_offset, image_chunk_data, user_data);
            common->locked = false;
            break;
        }

        case TF_THERMAL_IMAGING_CALLBACK_TEMPERATURE_IMAGE_LOW_LEVEL: {
            TF_ThermalImagingTemperatureImageLowLevelHandler fn = thermal_imaging->temperature_image_low_level_handler;
            void *user_data = thermal_imaging->temperature_image_low_level_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            uint16_t image_chunk_offset = tf_packetbuffer_read_uint16_t(payload);
            uint16_t image_chunk_data[31]; for (i = 0; i < 31; ++i) image_chunk_data[i] = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(thermal_imaging->tfp->hal);
            common->locked = true;
            fn(thermal_imaging, image_chunk_offset, image_chunk_data, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_thermal_imaging_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_thermal_imaging_create(TF_ThermalImaging *thermal_imaging, const char *uid, TF_HalContext *hal) {
    memset(thermal_imaging, 0, sizeof(TF_ThermalImaging));

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

    //rc = tf_tfp_init(thermal_imaging->tfp, numeric_uid, TF_THERMAL_IMAGING_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_thermal_imaging_callback_handler);
    rc = tf_hal_get_tfp(hal, &thermal_imaging->tfp, TF_THERMAL_IMAGING_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    thermal_imaging->tfp->device = thermal_imaging;
    thermal_imaging->tfp->uid = numeric_uid;
    thermal_imaging->tfp->cb_handler = tf_thermal_imaging_callback_handler;
    thermal_imaging->response_expected[0] = 0x08;
    thermal_imaging->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_thermal_imaging_destroy(TF_ThermalImaging *thermal_imaging) {
    int result = tf_tfp_destroy(thermal_imaging->tfp);
    thermal_imaging->tfp = NULL;
    return result;
}

int tf_thermal_imaging_get_response_expected(TF_ThermalImaging *thermal_imaging, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_THERMAL_IMAGING_FUNCTION_SET_RESOLUTION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (thermal_imaging->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_THERMAL_IMAGING_FUNCTION_SET_SPOTMETER_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (thermal_imaging->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_THERMAL_IMAGING_FUNCTION_SET_HIGH_CONTRAST_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (thermal_imaging->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_THERMAL_IMAGING_FUNCTION_SET_IMAGE_TRANSFER_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (thermal_imaging->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_THERMAL_IMAGING_FUNCTION_SET_FLUX_LINEAR_PARAMETERS:
            if(ret_response_expected != NULL)
                *ret_response_expected = (thermal_imaging->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_THERMAL_IMAGING_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (thermal_imaging->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_THERMAL_IMAGING_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (thermal_imaging->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_THERMAL_IMAGING_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (thermal_imaging->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_THERMAL_IMAGING_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (thermal_imaging->response_expected[1] & (1 << 0)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_thermal_imaging_set_response_expected(TF_ThermalImaging *thermal_imaging, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_THERMAL_IMAGING_FUNCTION_SET_RESOLUTION:
            if (response_expected) {
                thermal_imaging->response_expected[0] |= (1 << 0);
            } else {
                thermal_imaging->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_THERMAL_IMAGING_FUNCTION_SET_SPOTMETER_CONFIG:
            if (response_expected) {
                thermal_imaging->response_expected[0] |= (1 << 1);
            } else {
                thermal_imaging->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_THERMAL_IMAGING_FUNCTION_SET_HIGH_CONTRAST_CONFIG:
            if (response_expected) {
                thermal_imaging->response_expected[0] |= (1 << 2);
            } else {
                thermal_imaging->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_THERMAL_IMAGING_FUNCTION_SET_IMAGE_TRANSFER_CONFIG:
            if (response_expected) {
                thermal_imaging->response_expected[0] |= (1 << 3);
            } else {
                thermal_imaging->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_THERMAL_IMAGING_FUNCTION_SET_FLUX_LINEAR_PARAMETERS:
            if (response_expected) {
                thermal_imaging->response_expected[0] |= (1 << 4);
            } else {
                thermal_imaging->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_THERMAL_IMAGING_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                thermal_imaging->response_expected[0] |= (1 << 5);
            } else {
                thermal_imaging->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_THERMAL_IMAGING_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                thermal_imaging->response_expected[0] |= (1 << 6);
            } else {
                thermal_imaging->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_THERMAL_IMAGING_FUNCTION_RESET:
            if (response_expected) {
                thermal_imaging->response_expected[0] |= (1 << 7);
            } else {
                thermal_imaging->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_THERMAL_IMAGING_FUNCTION_WRITE_UID:
            if (response_expected) {
                thermal_imaging->response_expected[1] |= (1 << 0);
            } else {
                thermal_imaging->response_expected[1] &= ~(1 << 0);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_thermal_imaging_set_response_expected_all(TF_ThermalImaging *thermal_imaging, bool response_expected) {
    memset(thermal_imaging->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_thermal_imaging_get_high_contrast_image_low_level(TF_ThermalImaging *thermal_imaging, uint16_t *ret_image_chunk_offset, uint8_t ret_image_chunk_data[62]) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_HIGH_CONTRAST_IMAGE_LOW_LEVEL, 0, 64, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_image_chunk_offset != NULL) { *ret_image_chunk_offset = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        if (ret_image_chunk_data != NULL) { for (i = 0; i < 62; ++i) ret_image_chunk_data[i] = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 62); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_temperature_image_low_level(TF_ThermalImaging *thermal_imaging, uint16_t *ret_image_chunk_offset, uint16_t ret_image_chunk_data[31]) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_TEMPERATURE_IMAGE_LOW_LEVEL, 0, 64, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_image_chunk_offset != NULL) { *ret_image_chunk_offset = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        if (ret_image_chunk_data != NULL) { for (i = 0; i < 31; ++i) ret_image_chunk_data[i] = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 62); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_statistics(TF_ThermalImaging *thermal_imaging, uint16_t ret_spotmeter_statistics[4], uint16_t ret_temperatures[4], uint8_t *ret_resolution, uint8_t *ret_ffc_status, bool ret_temperature_warning[2]) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_STATISTICS, 0, 19, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_spotmeter_statistics != NULL) { for (i = 0; i < 4; ++i) ret_spotmeter_statistics[i] = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 8); }
        if (ret_temperatures != NULL) { for (i = 0; i < 4; ++i) ret_temperatures[i] = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 8); }
        if (ret_resolution != NULL) { *ret_resolution = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 1); }
        if (ret_ffc_status != NULL) { *ret_ffc_status = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 1); }
        if (ret_temperature_warning != NULL) { tf_packetbuffer_read_bool_array(&thermal_imaging->tfp->spitfp->recv_buf, ret_temperature_warning, 2);} else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_set_resolution(TF_ThermalImaging *thermal_imaging, uint8_t resolution) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_thermal_imaging_get_response_expected(thermal_imaging, TF_THERMAL_IMAGING_FUNCTION_SET_RESOLUTION, &response_expected);
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_SET_RESOLUTION, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(thermal_imaging->tfp);

    buf[0] = (uint8_t)resolution;

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_resolution(TF_ThermalImaging *thermal_imaging, uint8_t *ret_resolution) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_RESOLUTION, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_resolution != NULL) { *ret_resolution = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_set_spotmeter_config(TF_ThermalImaging *thermal_imaging, uint8_t region_of_interest[4]) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_thermal_imaging_get_response_expected(thermal_imaging, TF_THERMAL_IMAGING_FUNCTION_SET_SPOTMETER_CONFIG, &response_expected);
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_SET_SPOTMETER_CONFIG, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(thermal_imaging->tfp);

    memcpy(buf + 0, region_of_interest, 4);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_spotmeter_config(TF_ThermalImaging *thermal_imaging, uint8_t ret_region_of_interest[4]) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_SPOTMETER_CONFIG, 0, 4, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_region_of_interest != NULL) { for (i = 0; i < 4; ++i) ret_region_of_interest[i] = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_set_high_contrast_config(TF_ThermalImaging *thermal_imaging, uint8_t region_of_interest[4], uint16_t dampening_factor, uint16_t clip_limit[2], uint16_t empty_counts) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_thermal_imaging_get_response_expected(thermal_imaging, TF_THERMAL_IMAGING_FUNCTION_SET_HIGH_CONTRAST_CONFIG, &response_expected);
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_SET_HIGH_CONTRAST_CONFIG, 12, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(thermal_imaging->tfp);

    memcpy(buf + 0, region_of_interest, 4);
    dampening_factor = tf_leconvert_uint16_to(dampening_factor); memcpy(buf + 4, &dampening_factor, 2);
    for (i = 0; i < 2; i++) { uint16_t tmp_clip_limit = tf_leconvert_uint16_to(clip_limit[i]); memcpy(buf + 6 + (i * sizeof(uint16_t)), &tmp_clip_limit, sizeof(uint16_t)); }
    empty_counts = tf_leconvert_uint16_to(empty_counts); memcpy(buf + 10, &empty_counts, 2);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_high_contrast_config(TF_ThermalImaging *thermal_imaging, uint8_t ret_region_of_interest[4], uint16_t *ret_dampening_factor, uint16_t ret_clip_limit[2], uint16_t *ret_empty_counts) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_HIGH_CONTRAST_CONFIG, 0, 12, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_region_of_interest != NULL) { for (i = 0; i < 4; ++i) ret_region_of_interest[i] = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 4); }
        if (ret_dampening_factor != NULL) { *ret_dampening_factor = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        if (ret_clip_limit != NULL) { for (i = 0; i < 2; ++i) ret_clip_limit[i] = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 4); }
        if (ret_empty_counts != NULL) { *ret_empty_counts = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_set_image_transfer_config(TF_ThermalImaging *thermal_imaging, uint8_t config) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_thermal_imaging_get_response_expected(thermal_imaging, TF_THERMAL_IMAGING_FUNCTION_SET_IMAGE_TRANSFER_CONFIG, &response_expected);
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_SET_IMAGE_TRANSFER_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(thermal_imaging->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_image_transfer_config(TF_ThermalImaging *thermal_imaging, uint8_t *ret_config) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_IMAGE_TRANSFER_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_set_flux_linear_parameters(TF_ThermalImaging *thermal_imaging, uint16_t scene_emissivity, uint16_t temperature_background, uint16_t tau_window, uint16_t temperatur_window, uint16_t tau_atmosphere, uint16_t temperature_atmosphere, uint16_t reflection_window, uint16_t temperature_reflection) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_thermal_imaging_get_response_expected(thermal_imaging, TF_THERMAL_IMAGING_FUNCTION_SET_FLUX_LINEAR_PARAMETERS, &response_expected);
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_SET_FLUX_LINEAR_PARAMETERS, 16, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(thermal_imaging->tfp);

    scene_emissivity = tf_leconvert_uint16_to(scene_emissivity); memcpy(buf + 0, &scene_emissivity, 2);
    temperature_background = tf_leconvert_uint16_to(temperature_background); memcpy(buf + 2, &temperature_background, 2);
    tau_window = tf_leconvert_uint16_to(tau_window); memcpy(buf + 4, &tau_window, 2);
    temperatur_window = tf_leconvert_uint16_to(temperatur_window); memcpy(buf + 6, &temperatur_window, 2);
    tau_atmosphere = tf_leconvert_uint16_to(tau_atmosphere); memcpy(buf + 8, &tau_atmosphere, 2);
    temperature_atmosphere = tf_leconvert_uint16_to(temperature_atmosphere); memcpy(buf + 10, &temperature_atmosphere, 2);
    reflection_window = tf_leconvert_uint16_to(reflection_window); memcpy(buf + 12, &reflection_window, 2);
    temperature_reflection = tf_leconvert_uint16_to(temperature_reflection); memcpy(buf + 14, &temperature_reflection, 2);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_flux_linear_parameters(TF_ThermalImaging *thermal_imaging, uint16_t *ret_scene_emissivity, uint16_t *ret_temperature_background, uint16_t *ret_tau_window, uint16_t *ret_temperatur_window, uint16_t *ret_tau_atmosphere, uint16_t *ret_temperature_atmosphere, uint16_t *ret_reflection_window, uint16_t *ret_temperature_reflection) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_FLUX_LINEAR_PARAMETERS, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_scene_emissivity != NULL) { *ret_scene_emissivity = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        if (ret_temperature_background != NULL) { *ret_temperature_background = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        if (ret_tau_window != NULL) { *ret_tau_window = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        if (ret_temperatur_window != NULL) { *ret_temperatur_window = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        if (ret_tau_atmosphere != NULL) { *ret_tau_atmosphere = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        if (ret_temperature_atmosphere != NULL) { *ret_temperature_atmosphere = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        if (ret_reflection_window != NULL) { *ret_reflection_window = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        if (ret_temperature_reflection != NULL) { *ret_temperature_reflection = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_spitfp_error_count(TF_ThermalImaging *thermal_imaging, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_set_bootloader_mode(TF_ThermalImaging *thermal_imaging, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(thermal_imaging->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_bootloader_mode(TF_ThermalImaging *thermal_imaging, uint8_t *ret_mode) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_set_write_firmware_pointer(TF_ThermalImaging *thermal_imaging, uint32_t pointer) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_thermal_imaging_get_response_expected(thermal_imaging, TF_THERMAL_IMAGING_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(thermal_imaging->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_write_firmware(TF_ThermalImaging *thermal_imaging, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(thermal_imaging->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_set_status_led_config(TF_ThermalImaging *thermal_imaging, uint8_t config) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_thermal_imaging_get_response_expected(thermal_imaging, TF_THERMAL_IMAGING_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(thermal_imaging->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_status_led_config(TF_ThermalImaging *thermal_imaging, uint8_t *ret_config) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_chip_temperature(TF_ThermalImaging *thermal_imaging, int16_t *ret_temperature) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_reset(TF_ThermalImaging *thermal_imaging) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_thermal_imaging_get_response_expected(thermal_imaging, TF_THERMAL_IMAGING_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_write_uid(TF_ThermalImaging *thermal_imaging, uint32_t uid) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_thermal_imaging_get_response_expected(thermal_imaging, TF_THERMAL_IMAGING_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(thermal_imaging->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_read_uid(TF_ThermalImaging *thermal_imaging, uint32_t *ret_uid) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_identity(TF_ThermalImaging *thermal_imaging, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(thermal_imaging->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(thermal_imaging->tfp, TF_THERMAL_IMAGING_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(thermal_imaging->tfp->hal) + tf_hal_get_common(thermal_imaging->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(thermal_imaging->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&thermal_imaging->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&thermal_imaging->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&thermal_imaging->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&thermal_imaging->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&thermal_imaging->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(thermal_imaging->tfp->hal, thermal_imaging->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(thermal_imaging->tfp);
    }

    result = tf_tfp_finish_send(thermal_imaging->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_thermal_imaging_get_high_contrast_image(TF_ThermalImaging *thermal_imaging, uint8_t *ret_image, uint16_t *ret_image_length) {
    int ret = TF_E_OK;
    uint16_t image_length = 4800;
    uint16_t image_chunk_offset = 0;
    uint8_t image_chunk_data[62];
    bool image_out_of_sync;
    uint16_t image_chunk_length = 0;

    *ret_image_length = 0;

    ret = tf_thermal_imaging_get_high_contrast_image_low_level(thermal_imaging, &image_chunk_offset, image_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    if (image_chunk_offset == (1 << 16) - 1) { // maximum chunk offset -> stream has no data
        return ret;
    }

    image_out_of_sync = image_chunk_offset != 0;

    if (!image_out_of_sync) {
        image_chunk_length = image_length - image_chunk_offset;

        if (image_chunk_length > 62) {
            image_chunk_length = 62;
        }

        memcpy(ret_image, image_chunk_data, sizeof(uint8_t) * image_chunk_length);
        *ret_image_length = image_chunk_length;

        while (*ret_image_length < image_length) {
            ret = tf_thermal_imaging_get_high_contrast_image_low_level(thermal_imaging, &image_chunk_offset, image_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            image_out_of_sync = image_chunk_offset != *ret_image_length;

            if (image_out_of_sync) {
                break;
            }

            image_chunk_length = image_length - image_chunk_offset;

            if (image_chunk_length > 62) {
                image_chunk_length = 62;
            }

            memcpy(&ret_image[*ret_image_length], image_chunk_data, sizeof(uint8_t) * image_chunk_length);
            *ret_image_length += image_chunk_length;
        }
    }

    if (image_out_of_sync) {
        *ret_image_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (image_chunk_offset + 62 < image_length) {
            ret = tf_thermal_imaging_get_high_contrast_image_low_level(thermal_imaging, &image_chunk_offset, image_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}

int tf_thermal_imaging_get_temperature_image(TF_ThermalImaging *thermal_imaging, uint16_t *ret_image, uint16_t *ret_image_length) {
    int ret = TF_E_OK;
    uint16_t image_length = 4800;
    uint16_t image_chunk_offset = 0;
    uint16_t image_chunk_data[31];
    bool image_out_of_sync;
    uint16_t image_chunk_length = 0;

    *ret_image_length = 0;

    ret = tf_thermal_imaging_get_temperature_image_low_level(thermal_imaging, &image_chunk_offset, image_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    if (image_chunk_offset == (1 << 16) - 1) { // maximum chunk offset -> stream has no data
        return ret;
    }

    image_out_of_sync = image_chunk_offset != 0;

    if (!image_out_of_sync) {
        image_chunk_length = image_length - image_chunk_offset;

        if (image_chunk_length > 31) {
            image_chunk_length = 31;
        }

        memcpy(ret_image, image_chunk_data, sizeof(uint16_t) * image_chunk_length);
        *ret_image_length = image_chunk_length;

        while (*ret_image_length < image_length) {
            ret = tf_thermal_imaging_get_temperature_image_low_level(thermal_imaging, &image_chunk_offset, image_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            image_out_of_sync = image_chunk_offset != *ret_image_length;

            if (image_out_of_sync) {
                break;
            }

            image_chunk_length = image_length - image_chunk_offset;

            if (image_chunk_length > 31) {
                image_chunk_length = 31;
            }

            memcpy(&ret_image[*ret_image_length], image_chunk_data, sizeof(uint16_t) * image_chunk_length);
            *ret_image_length += image_chunk_length;
        }
    }

    if (image_out_of_sync) {
        *ret_image_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (image_chunk_offset + 31 < image_length) {
            ret = tf_thermal_imaging_get_temperature_image_low_level(thermal_imaging, &image_chunk_offset, image_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_thermal_imaging_register_high_contrast_image_low_level_callback(TF_ThermalImaging *thermal_imaging, TF_ThermalImagingHighContrastImageLowLevelHandler handler, void *user_data) {
    if (handler == NULL) {
        thermal_imaging->tfp->needs_callback_tick = false;
        thermal_imaging->tfp->needs_callback_tick |= thermal_imaging->temperature_image_low_level_handler != NULL;
    } else {
        thermal_imaging->tfp->needs_callback_tick = true;
    }
    thermal_imaging->high_contrast_image_low_level_handler = handler;
    thermal_imaging->high_contrast_image_low_level_user_data = user_data;
}


void tf_thermal_imaging_register_temperature_image_low_level_callback(TF_ThermalImaging *thermal_imaging, TF_ThermalImagingTemperatureImageLowLevelHandler handler, void *user_data) {
    if (handler == NULL) {
        thermal_imaging->tfp->needs_callback_tick = false;
        thermal_imaging->tfp->needs_callback_tick |= thermal_imaging->high_contrast_image_low_level_handler != NULL;
    } else {
        thermal_imaging->tfp->needs_callback_tick = true;
    }
    thermal_imaging->temperature_image_low_level_handler = handler;
    thermal_imaging->temperature_image_low_level_user_data = user_data;
}
#endif
int tf_thermal_imaging_callback_tick(TF_ThermalImaging *thermal_imaging, uint32_t timeout_us) {
    return tf_tfp_callback_tick(thermal_imaging->tfp, tf_hal_current_time_us(thermal_imaging->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
