/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_gps_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_gps_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_GPSV2 *gps_v2 = (TF_GPSV2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_GPS_V2_CALLBACK_PULSE_PER_SECOND: {
            TF_GPSV2PulsePerSecondHandler fn = gps_v2->pulse_per_second_handler;
            void *user_data = gps_v2->pulse_per_second_user_data;
            if (fn == NULL)
                return false;


            TF_HalCommon *common = tf_hal_get_common(gps_v2->tfp->hal);
            common->locked = true;
            fn(gps_v2, user_data);
            common->locked = false;
            break;
        }

        case TF_GPS_V2_CALLBACK_COORDINATES: {
            TF_GPSV2CoordinatesHandler fn = gps_v2->coordinates_handler;
            void *user_data = gps_v2->coordinates_user_data;
            if (fn == NULL)
                return false;

            uint32_t latitude = tf_packetbuffer_read_uint32_t(payload);
            char ns = tf_packetbuffer_read_char(payload);
            uint32_t longitude = tf_packetbuffer_read_uint32_t(payload);
            char ew = tf_packetbuffer_read_char(payload);
            TF_HalCommon *common = tf_hal_get_common(gps_v2->tfp->hal);
            common->locked = true;
            fn(gps_v2, latitude, ns, longitude, ew, user_data);
            common->locked = false;
            break;
        }

        case TF_GPS_V2_CALLBACK_STATUS: {
            TF_GPSV2StatusHandler fn = gps_v2->status_handler;
            void *user_data = gps_v2->status_user_data;
            if (fn == NULL)
                return false;

            bool has_fix = tf_packetbuffer_read_bool(payload);
            uint8_t satellites_view = tf_packetbuffer_read_uint8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(gps_v2->tfp->hal);
            common->locked = true;
            fn(gps_v2, has_fix, satellites_view, user_data);
            common->locked = false;
            break;
        }

        case TF_GPS_V2_CALLBACK_ALTITUDE: {
            TF_GPSV2AltitudeHandler fn = gps_v2->altitude_handler;
            void *user_data = gps_v2->altitude_user_data;
            if (fn == NULL)
                return false;

            int32_t altitude = tf_packetbuffer_read_int32_t(payload);
            int32_t geoidal_separation = tf_packetbuffer_read_int32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(gps_v2->tfp->hal);
            common->locked = true;
            fn(gps_v2, altitude, geoidal_separation, user_data);
            common->locked = false;
            break;
        }

        case TF_GPS_V2_CALLBACK_MOTION: {
            TF_GPSV2MotionHandler fn = gps_v2->motion_handler;
            void *user_data = gps_v2->motion_user_data;
            if (fn == NULL)
                return false;

            uint32_t course = tf_packetbuffer_read_uint32_t(payload);
            uint32_t speed = tf_packetbuffer_read_uint32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(gps_v2->tfp->hal);
            common->locked = true;
            fn(gps_v2, course, speed, user_data);
            common->locked = false;
            break;
        }

        case TF_GPS_V2_CALLBACK_DATE_TIME: {
            TF_GPSV2DateTimeHandler fn = gps_v2->date_time_handler;
            void *user_data = gps_v2->date_time_user_data;
            if (fn == NULL)
                return false;

            uint32_t date = tf_packetbuffer_read_uint32_t(payload);
            uint32_t time = tf_packetbuffer_read_uint32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(gps_v2->tfp->hal);
            common->locked = true;
            fn(gps_v2, date, time, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_gps_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_gps_v2_create(TF_GPSV2 *gps_v2, const char *uid, TF_HalContext *hal) {
    memset(gps_v2, 0, sizeof(TF_GPSV2));

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

    //rc = tf_tfp_init(gps_v2->tfp, numeric_uid, TF_GPS_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_gps_v2_callback_handler);
    rc = tf_hal_get_tfp(hal, &gps_v2->tfp, TF_GPS_V2_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    gps_v2->tfp->device = gps_v2;
    gps_v2->tfp->uid = numeric_uid;
    gps_v2->tfp->cb_handler = tf_gps_v2_callback_handler;
    gps_v2->response_expected[0] = 0x7C;
    gps_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_gps_v2_destroy(TF_GPSV2 *gps_v2) {
    int result = tf_tfp_destroy(gps_v2->tfp);
    gps_v2->tfp = NULL;
    return result;
}

int tf_gps_v2_get_response_expected(TF_GPSV2 *gps_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_GPS_V2_FUNCTION_RESTART:
            if(ret_response_expected != NULL)
                *ret_response_expected = (gps_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_GPS_V2_FUNCTION_SET_FIX_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (gps_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_GPS_V2_FUNCTION_SET_COORDINATES_CALLBACK_PERIOD:
            if(ret_response_expected != NULL)
                *ret_response_expected = (gps_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_GPS_V2_FUNCTION_SET_STATUS_CALLBACK_PERIOD:
            if(ret_response_expected != NULL)
                *ret_response_expected = (gps_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_GPS_V2_FUNCTION_SET_ALTITUDE_CALLBACK_PERIOD:
            if(ret_response_expected != NULL)
                *ret_response_expected = (gps_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_GPS_V2_FUNCTION_SET_MOTION_CALLBACK_PERIOD:
            if(ret_response_expected != NULL)
                *ret_response_expected = (gps_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_GPS_V2_FUNCTION_SET_DATE_TIME_CALLBACK_PERIOD:
            if(ret_response_expected != NULL)
                *ret_response_expected = (gps_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_GPS_V2_FUNCTION_SET_SBAS_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (gps_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_GPS_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (gps_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_GPS_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (gps_v2->response_expected[1] & (1 << 1)) != 0;
            break;
        case TF_GPS_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (gps_v2->response_expected[1] & (1 << 2)) != 0;
            break;
        case TF_GPS_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (gps_v2->response_expected[1] & (1 << 3)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_gps_v2_set_response_expected(TF_GPSV2 *gps_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_GPS_V2_FUNCTION_RESTART:
            if (response_expected) {
                gps_v2->response_expected[0] |= (1 << 0);
            } else {
                gps_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_GPS_V2_FUNCTION_SET_FIX_LED_CONFIG:
            if (response_expected) {
                gps_v2->response_expected[0] |= (1 << 1);
            } else {
                gps_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_GPS_V2_FUNCTION_SET_COORDINATES_CALLBACK_PERIOD:
            if (response_expected) {
                gps_v2->response_expected[0] |= (1 << 2);
            } else {
                gps_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_GPS_V2_FUNCTION_SET_STATUS_CALLBACK_PERIOD:
            if (response_expected) {
                gps_v2->response_expected[0] |= (1 << 3);
            } else {
                gps_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_GPS_V2_FUNCTION_SET_ALTITUDE_CALLBACK_PERIOD:
            if (response_expected) {
                gps_v2->response_expected[0] |= (1 << 4);
            } else {
                gps_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_GPS_V2_FUNCTION_SET_MOTION_CALLBACK_PERIOD:
            if (response_expected) {
                gps_v2->response_expected[0] |= (1 << 5);
            } else {
                gps_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_GPS_V2_FUNCTION_SET_DATE_TIME_CALLBACK_PERIOD:
            if (response_expected) {
                gps_v2->response_expected[0] |= (1 << 6);
            } else {
                gps_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_GPS_V2_FUNCTION_SET_SBAS_CONFIG:
            if (response_expected) {
                gps_v2->response_expected[0] |= (1 << 7);
            } else {
                gps_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_GPS_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                gps_v2->response_expected[1] |= (1 << 0);
            } else {
                gps_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_GPS_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                gps_v2->response_expected[1] |= (1 << 1);
            } else {
                gps_v2->response_expected[1] &= ~(1 << 1);
            }
            break;
        case TF_GPS_V2_FUNCTION_RESET:
            if (response_expected) {
                gps_v2->response_expected[1] |= (1 << 2);
            } else {
                gps_v2->response_expected[1] &= ~(1 << 2);
            }
            break;
        case TF_GPS_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                gps_v2->response_expected[1] |= (1 << 3);
            } else {
                gps_v2->response_expected[1] &= ~(1 << 3);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_gps_v2_set_response_expected_all(TF_GPSV2 *gps_v2, bool response_expected) {
    memset(gps_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_gps_v2_get_coordinates(TF_GPSV2 *gps_v2, uint32_t *ret_latitude, char *ret_ns, uint32_t *ret_longitude, char *ret_ew) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_COORDINATES, 0, 10, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_latitude != NULL) { *ret_latitude = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_ns != NULL) { *ret_ns = tf_packetbuffer_read_char(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_longitude != NULL) { *ret_longitude = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_ew != NULL) { *ret_ew = tf_packetbuffer_read_char(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_status(TF_GPSV2 *gps_v2, bool *ret_has_fix, uint8_t *ret_satellites_view) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_STATUS, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_has_fix != NULL) { *ret_has_fix = tf_packetbuffer_read_bool(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_satellites_view != NULL) { *ret_satellites_view = tf_packetbuffer_read_uint8_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_altitude(TF_GPSV2 *gps_v2, int32_t *ret_altitude, int32_t *ret_geoidal_separation) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_ALTITUDE, 0, 8, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_altitude != NULL) { *ret_altitude = tf_packetbuffer_read_int32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_geoidal_separation != NULL) { *ret_geoidal_separation = tf_packetbuffer_read_int32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_motion(TF_GPSV2 *gps_v2, uint32_t *ret_course, uint32_t *ret_speed) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_MOTION, 0, 8, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_course != NULL) { *ret_course = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_speed != NULL) { *ret_speed = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_date_time(TF_GPSV2 *gps_v2, uint32_t *ret_date, uint32_t *ret_time) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_DATE_TIME, 0, 8, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_date != NULL) { *ret_date = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_time != NULL) { *ret_time = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_restart(TF_GPSV2 *gps_v2, uint8_t restart_type) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_gps_v2_get_response_expected(gps_v2, TF_GPS_V2_FUNCTION_RESTART, &response_expected);
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_RESTART, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    buf[0] = (uint8_t)restart_type;

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_satellite_system_status_low_level(TF_GPSV2 *gps_v2, uint8_t satellite_system, uint8_t *ret_satellite_numbers_length, uint8_t ret_satellite_numbers_data[12], uint8_t *ret_fix, uint16_t *ret_pdop, uint16_t *ret_hdop, uint16_t *ret_vdop) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_SATELLITE_SYSTEM_STATUS_LOW_LEVEL, 1, 20, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    buf[0] = (uint8_t)satellite_system;

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_satellite_numbers_length != NULL) { *ret_satellite_numbers_length = tf_packetbuffer_read_uint8_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_satellite_numbers_data != NULL) { for (i = 0; i < 12; ++i) ret_satellite_numbers_data[i] = tf_packetbuffer_read_uint8_t(&gps_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 12); }
        if (ret_fix != NULL) { *ret_fix = tf_packetbuffer_read_uint8_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_pdop != NULL) { *ret_pdop = tf_packetbuffer_read_uint16_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_hdop != NULL) { *ret_hdop = tf_packetbuffer_read_uint16_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_vdop != NULL) { *ret_vdop = tf_packetbuffer_read_uint16_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_satellite_status(TF_GPSV2 *gps_v2, uint8_t satellite_system, uint8_t satellite_number, int16_t *ret_elevation, int16_t *ret_azimuth, int16_t *ret_snr) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_SATELLITE_STATUS, 2, 6, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    buf[0] = (uint8_t)satellite_system;
    buf[1] = (uint8_t)satellite_number;

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_elevation != NULL) { *ret_elevation = tf_packetbuffer_read_int16_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_azimuth != NULL) { *ret_azimuth = tf_packetbuffer_read_int16_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 2); }
        if (ret_snr != NULL) { *ret_snr = tf_packetbuffer_read_int16_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_set_fix_led_config(TF_GPSV2 *gps_v2, uint8_t config) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_gps_v2_get_response_expected(gps_v2, TF_GPS_V2_FUNCTION_SET_FIX_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_SET_FIX_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_fix_led_config(TF_GPSV2 *gps_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_FIX_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_set_coordinates_callback_period(TF_GPSV2 *gps_v2, uint32_t period) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_gps_v2_get_response_expected(gps_v2, TF_GPS_V2_FUNCTION_SET_COORDINATES_CALLBACK_PERIOD, &response_expected);
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_SET_COORDINATES_CALLBACK_PERIOD, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_coordinates_callback_period(TF_GPSV2 *gps_v2, uint32_t *ret_period) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_COORDINATES_CALLBACK_PERIOD, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_set_status_callback_period(TF_GPSV2 *gps_v2, uint32_t period) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_gps_v2_get_response_expected(gps_v2, TF_GPS_V2_FUNCTION_SET_STATUS_CALLBACK_PERIOD, &response_expected);
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_SET_STATUS_CALLBACK_PERIOD, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_status_callback_period(TF_GPSV2 *gps_v2, uint32_t *ret_period) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_STATUS_CALLBACK_PERIOD, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_set_altitude_callback_period(TF_GPSV2 *gps_v2, uint32_t period) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_gps_v2_get_response_expected(gps_v2, TF_GPS_V2_FUNCTION_SET_ALTITUDE_CALLBACK_PERIOD, &response_expected);
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_SET_ALTITUDE_CALLBACK_PERIOD, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_altitude_callback_period(TF_GPSV2 *gps_v2, uint32_t *ret_period) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_ALTITUDE_CALLBACK_PERIOD, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_set_motion_callback_period(TF_GPSV2 *gps_v2, uint32_t period) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_gps_v2_get_response_expected(gps_v2, TF_GPS_V2_FUNCTION_SET_MOTION_CALLBACK_PERIOD, &response_expected);
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_SET_MOTION_CALLBACK_PERIOD, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_motion_callback_period(TF_GPSV2 *gps_v2, uint32_t *ret_period) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_MOTION_CALLBACK_PERIOD, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_set_date_time_callback_period(TF_GPSV2 *gps_v2, uint32_t period) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_gps_v2_get_response_expected(gps_v2, TF_GPS_V2_FUNCTION_SET_DATE_TIME_CALLBACK_PERIOD, &response_expected);
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_SET_DATE_TIME_CALLBACK_PERIOD, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_date_time_callback_period(TF_GPSV2 *gps_v2, uint32_t *ret_period) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_DATE_TIME_CALLBACK_PERIOD, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_set_sbas_config(TF_GPSV2 *gps_v2, uint8_t sbas_config) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_gps_v2_get_response_expected(gps_v2, TF_GPS_V2_FUNCTION_SET_SBAS_CONFIG, &response_expected);
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_SET_SBAS_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    buf[0] = (uint8_t)sbas_config;

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_sbas_config(TF_GPSV2 *gps_v2, uint8_t *ret_sbas_config) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_SBAS_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_sbas_config != NULL) { *ret_sbas_config = tf_packetbuffer_read_uint8_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_spitfp_error_count(TF_GPSV2 *gps_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_set_bootloader_mode(TF_GPSV2 *gps_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_bootloader_mode(TF_GPSV2 *gps_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_set_write_firmware_pointer(TF_GPSV2 *gps_v2, uint32_t pointer) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_gps_v2_get_response_expected(gps_v2, TF_GPS_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_write_firmware(TF_GPSV2 *gps_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_set_status_led_config(TF_GPSV2 *gps_v2, uint8_t config) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_gps_v2_get_response_expected(gps_v2, TF_GPS_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_status_led_config(TF_GPSV2 *gps_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_chip_temperature(TF_GPSV2 *gps_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_reset(TF_GPSV2 *gps_v2) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_gps_v2_get_response_expected(gps_v2, TF_GPS_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_write_uid(TF_GPSV2 *gps_v2, uint32_t uid) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_gps_v2_get_response_expected(gps_v2, TF_GPS_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(gps_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_read_uid(TF_GPSV2 *gps_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_identity(TF_GPSV2 *gps_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(gps_v2->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(gps_v2->tfp, TF_GPS_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(gps_v2->tfp->hal) + tf_hal_get_common(gps_v2->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(gps_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&gps_v2->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&gps_v2->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&gps_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&gps_v2->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&gps_v2->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&gps_v2->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(gps_v2->tfp->hal, gps_v2->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(gps_v2->tfp);
    }

    result = tf_tfp_finish_send(gps_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_gps_v2_get_satellite_system_status(TF_GPSV2 *gps_v2, uint8_t satellite_system, uint8_t *ret_satellite_numbers, uint8_t *ret_satellite_numbers_length, uint8_t *ret_fix, uint16_t *ret_pdop, uint16_t *ret_hdop, uint16_t *ret_vdop) {
    int ret = TF_E_OK;
    uint8_t satellite_numbers_length = 0;
    uint8_t satellite_numbers_data[12];

    *ret_satellite_numbers_length = 0;

    ret = tf_gps_v2_get_satellite_system_status_low_level(gps_v2, satellite_system, &satellite_numbers_length, satellite_numbers_data, ret_fix, ret_pdop, ret_hdop, ret_vdop);

    if (ret != TF_E_OK) {
        return ret;
    }

    memcpy(ret_satellite_numbers, satellite_numbers_data, sizeof(uint8_t) * satellite_numbers_length);
    memset(&satellite_numbers_data[satellite_numbers_length], 0, sizeof(uint8_t) * (12 - satellite_numbers_length));

    *ret_satellite_numbers_length = satellite_numbers_length;

    return ret;
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_gps_v2_register_pulse_per_second_callback(TF_GPSV2 *gps_v2, TF_GPSV2PulsePerSecondHandler handler, void *user_data) {
    if (handler == NULL) {
        gps_v2->tfp->needs_callback_tick = false;
        gps_v2->tfp->needs_callback_tick |= gps_v2->coordinates_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->status_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->altitude_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->motion_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->date_time_handler != NULL;
    } else {
        gps_v2->tfp->needs_callback_tick = true;
    }
    gps_v2->pulse_per_second_handler = handler;
    gps_v2->pulse_per_second_user_data = user_data;
}


void tf_gps_v2_register_coordinates_callback(TF_GPSV2 *gps_v2, TF_GPSV2CoordinatesHandler handler, void *user_data) {
    if (handler == NULL) {
        gps_v2->tfp->needs_callback_tick = false;
        gps_v2->tfp->needs_callback_tick |= gps_v2->pulse_per_second_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->status_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->altitude_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->motion_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->date_time_handler != NULL;
    } else {
        gps_v2->tfp->needs_callback_tick = true;
    }
    gps_v2->coordinates_handler = handler;
    gps_v2->coordinates_user_data = user_data;
}


void tf_gps_v2_register_status_callback(TF_GPSV2 *gps_v2, TF_GPSV2StatusHandler handler, void *user_data) {
    if (handler == NULL) {
        gps_v2->tfp->needs_callback_tick = false;
        gps_v2->tfp->needs_callback_tick |= gps_v2->pulse_per_second_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->coordinates_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->altitude_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->motion_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->date_time_handler != NULL;
    } else {
        gps_v2->tfp->needs_callback_tick = true;
    }
    gps_v2->status_handler = handler;
    gps_v2->status_user_data = user_data;
}


void tf_gps_v2_register_altitude_callback(TF_GPSV2 *gps_v2, TF_GPSV2AltitudeHandler handler, void *user_data) {
    if (handler == NULL) {
        gps_v2->tfp->needs_callback_tick = false;
        gps_v2->tfp->needs_callback_tick |= gps_v2->pulse_per_second_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->coordinates_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->status_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->motion_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->date_time_handler != NULL;
    } else {
        gps_v2->tfp->needs_callback_tick = true;
    }
    gps_v2->altitude_handler = handler;
    gps_v2->altitude_user_data = user_data;
}


void tf_gps_v2_register_motion_callback(TF_GPSV2 *gps_v2, TF_GPSV2MotionHandler handler, void *user_data) {
    if (handler == NULL) {
        gps_v2->tfp->needs_callback_tick = false;
        gps_v2->tfp->needs_callback_tick |= gps_v2->pulse_per_second_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->coordinates_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->status_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->altitude_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->date_time_handler != NULL;
    } else {
        gps_v2->tfp->needs_callback_tick = true;
    }
    gps_v2->motion_handler = handler;
    gps_v2->motion_user_data = user_data;
}


void tf_gps_v2_register_date_time_callback(TF_GPSV2 *gps_v2, TF_GPSV2DateTimeHandler handler, void *user_data) {
    if (handler == NULL) {
        gps_v2->tfp->needs_callback_tick = false;
        gps_v2->tfp->needs_callback_tick |= gps_v2->pulse_per_second_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->coordinates_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->status_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->altitude_handler != NULL;
        gps_v2->tfp->needs_callback_tick |= gps_v2->motion_handler != NULL;
    } else {
        gps_v2->tfp->needs_callback_tick = true;
    }
    gps_v2->date_time_handler = handler;
    gps_v2->date_time_user_data = user_data;
}
#endif
int tf_gps_v2_callback_tick(TF_GPSV2 *gps_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(gps_v2->tfp, tf_hal_current_time_us(gps_v2->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
