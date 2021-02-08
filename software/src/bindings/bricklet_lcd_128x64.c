/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_lcd_128x64.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_lcd_128x64_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_LCD128x64 *lcd_128x64 = (TF_LCD128x64 *) dev;
    (void)payload;

    switch(fid) {

        case TF_LCD_128X64_CALLBACK_TOUCH_POSITION: {
            TF_LCD128x64TouchPositionHandler fn = lcd_128x64->touch_position_handler;
            void *user_data = lcd_128x64->touch_position_user_data;
            if (fn == NULL)
                return false;

            uint16_t pressure = tf_packetbuffer_read_uint16_t(payload);
            uint16_t x = tf_packetbuffer_read_uint16_t(payload);
            uint16_t y = tf_packetbuffer_read_uint16_t(payload);
            uint32_t age = tf_packetbuffer_read_uint32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(lcd_128x64->tfp->hal);
            common->locked = true;
            fn(lcd_128x64, pressure, x, y, age, user_data);
            common->locked = false;
            break;
        }

        case TF_LCD_128X64_CALLBACK_TOUCH_GESTURE: {
            TF_LCD128x64TouchGestureHandler fn = lcd_128x64->touch_gesture_handler;
            void *user_data = lcd_128x64->touch_gesture_user_data;
            if (fn == NULL)
                return false;

            uint8_t gesture = tf_packetbuffer_read_uint8_t(payload);
            uint32_t duration = tf_packetbuffer_read_uint32_t(payload);
            uint16_t pressure_max = tf_packetbuffer_read_uint16_t(payload);
            uint16_t x_start = tf_packetbuffer_read_uint16_t(payload);
            uint16_t y_start = tf_packetbuffer_read_uint16_t(payload);
            uint16_t x_end = tf_packetbuffer_read_uint16_t(payload);
            uint16_t y_end = tf_packetbuffer_read_uint16_t(payload);
            uint32_t age = tf_packetbuffer_read_uint32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(lcd_128x64->tfp->hal);
            common->locked = true;
            fn(lcd_128x64, gesture, duration, pressure_max, x_start, y_start, x_end, y_end, age, user_data);
            common->locked = false;
            break;
        }

        case TF_LCD_128X64_CALLBACK_GUI_BUTTON_PRESSED: {
            TF_LCD128x64GUIButtonPressedHandler fn = lcd_128x64->gui_button_pressed_handler;
            void *user_data = lcd_128x64->gui_button_pressed_user_data;
            if (fn == NULL)
                return false;

            uint8_t index = tf_packetbuffer_read_uint8_t(payload);
            bool pressed = tf_packetbuffer_read_bool(payload);
            TF_HalCommon *common = tf_hal_get_common(lcd_128x64->tfp->hal);
            common->locked = true;
            fn(lcd_128x64, index, pressed, user_data);
            common->locked = false;
            break;
        }

        case TF_LCD_128X64_CALLBACK_GUI_SLIDER_VALUE: {
            TF_LCD128x64GUISliderValueHandler fn = lcd_128x64->gui_slider_value_handler;
            void *user_data = lcd_128x64->gui_slider_value_user_data;
            if (fn == NULL)
                return false;

            uint8_t index = tf_packetbuffer_read_uint8_t(payload);
            uint8_t value = tf_packetbuffer_read_uint8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(lcd_128x64->tfp->hal);
            common->locked = true;
            fn(lcd_128x64, index, value, user_data);
            common->locked = false;
            break;
        }

        case TF_LCD_128X64_CALLBACK_GUI_TAB_SELECTED: {
            TF_LCD128x64GUITabSelectedHandler fn = lcd_128x64->gui_tab_selected_handler;
            void *user_data = lcd_128x64->gui_tab_selected_user_data;
            if (fn == NULL)
                return false;

            int8_t index = tf_packetbuffer_read_int8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(lcd_128x64->tfp->hal);
            common->locked = true;
            fn(lcd_128x64, index, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_lcd_128x64_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_lcd_128x64_create(TF_LCD128x64 *lcd_128x64, const char *uid, TF_HalContext *hal) {
    memset(lcd_128x64, 0, sizeof(TF_LCD128x64));

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

    //rc = tf_tfp_init(lcd_128x64->tfp, numeric_uid, TF_LCD_128X64_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_lcd_128x64_callback_handler);
    rc = tf_hal_get_tfp(hal, &lcd_128x64->tfp, TF_LCD_128X64_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    lcd_128x64->tfp->device = lcd_128x64;
    lcd_128x64->tfp->uid = numeric_uid;
    lcd_128x64->tfp->cb_handler = tf_lcd_128x64_callback_handler;
    lcd_128x64->response_expected[0] = 0x61;
    lcd_128x64->response_expected[1] = 0x90;
    lcd_128x64->response_expected[2] = 0xA0;
    lcd_128x64->response_expected[3] = 0x00;
    return TF_E_OK;
}

int tf_lcd_128x64_destroy(TF_LCD128x64 *lcd_128x64) {
    int result = tf_tfp_destroy(lcd_128x64->tfp);
    lcd_128x64->tfp = NULL;
    return result;
}

int tf_lcd_128x64_get_response_expected(TF_LCD128x64 *lcd_128x64, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_LCD_128X64_FUNCTION_WRITE_PIXELS_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_CLEAR_DISPLAY:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_DISPLAY_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_WRITE_LINE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_DRAW_BUFFERED_FRAME:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_TOUCH_POSITION_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_TOUCH_GESTURE_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_DRAW_LINE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_DRAW_BOX:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_DRAW_TEXT:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[1] & (1 << 1)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_BUTTON:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[1] & (1 << 2)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_REMOVE_GUI_BUTTON:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[1] & (1 << 3)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_BUTTON_PRESSED_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[1] & (1 << 4)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_SLIDER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[1] & (1 << 5)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_REMOVE_GUI_SLIDER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[1] & (1 << 6)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_SLIDER_VALUE_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[1] & (1 << 7)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_TAB_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[2] & (1 << 0)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_TAB_TEXT:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[2] & (1 << 1)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_TAB_ICON:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[2] & (1 << 2)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_REMOVE_GUI_TAB:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[2] & (1 << 3)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_TAB_SELECTED:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[2] & (1 << 4)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_TAB_SELECTED_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[2] & (1 << 5)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_GRAPH_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[2] & (1 << 6)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_GRAPH_DATA_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[2] & (1 << 7)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_REMOVE_GUI_GRAPH:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[3] & (1 << 0)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_REMOVE_ALL_GUI:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[3] & (1 << 1)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_TOUCH_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[3] & (1 << 2)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[3] & (1 << 3)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[3] & (1 << 4)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[3] & (1 << 5)) != 0;
            break;
        case TF_LCD_128X64_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (lcd_128x64->response_expected[3] & (1 << 6)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_lcd_128x64_set_response_expected(TF_LCD128x64 *lcd_128x64, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_LCD_128X64_FUNCTION_WRITE_PIXELS_LOW_LEVEL:
            if (response_expected) {
                lcd_128x64->response_expected[0] |= (1 << 0);
            } else {
                lcd_128x64->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_LCD_128X64_FUNCTION_CLEAR_DISPLAY:
            if (response_expected) {
                lcd_128x64->response_expected[0] |= (1 << 1);
            } else {
                lcd_128x64->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_DISPLAY_CONFIGURATION:
            if (response_expected) {
                lcd_128x64->response_expected[0] |= (1 << 2);
            } else {
                lcd_128x64->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_LCD_128X64_FUNCTION_WRITE_LINE:
            if (response_expected) {
                lcd_128x64->response_expected[0] |= (1 << 3);
            } else {
                lcd_128x64->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_LCD_128X64_FUNCTION_DRAW_BUFFERED_FRAME:
            if (response_expected) {
                lcd_128x64->response_expected[0] |= (1 << 4);
            } else {
                lcd_128x64->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_TOUCH_POSITION_CALLBACK_CONFIGURATION:
            if (response_expected) {
                lcd_128x64->response_expected[0] |= (1 << 5);
            } else {
                lcd_128x64->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_TOUCH_GESTURE_CALLBACK_CONFIGURATION:
            if (response_expected) {
                lcd_128x64->response_expected[0] |= (1 << 6);
            } else {
                lcd_128x64->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_LCD_128X64_FUNCTION_DRAW_LINE:
            if (response_expected) {
                lcd_128x64->response_expected[0] |= (1 << 7);
            } else {
                lcd_128x64->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_LCD_128X64_FUNCTION_DRAW_BOX:
            if (response_expected) {
                lcd_128x64->response_expected[1] |= (1 << 0);
            } else {
                lcd_128x64->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_LCD_128X64_FUNCTION_DRAW_TEXT:
            if (response_expected) {
                lcd_128x64->response_expected[1] |= (1 << 1);
            } else {
                lcd_128x64->response_expected[1] &= ~(1 << 1);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_BUTTON:
            if (response_expected) {
                lcd_128x64->response_expected[1] |= (1 << 2);
            } else {
                lcd_128x64->response_expected[1] &= ~(1 << 2);
            }
            break;
        case TF_LCD_128X64_FUNCTION_REMOVE_GUI_BUTTON:
            if (response_expected) {
                lcd_128x64->response_expected[1] |= (1 << 3);
            } else {
                lcd_128x64->response_expected[1] &= ~(1 << 3);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_BUTTON_PRESSED_CALLBACK_CONFIGURATION:
            if (response_expected) {
                lcd_128x64->response_expected[1] |= (1 << 4);
            } else {
                lcd_128x64->response_expected[1] &= ~(1 << 4);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_SLIDER:
            if (response_expected) {
                lcd_128x64->response_expected[1] |= (1 << 5);
            } else {
                lcd_128x64->response_expected[1] &= ~(1 << 5);
            }
            break;
        case TF_LCD_128X64_FUNCTION_REMOVE_GUI_SLIDER:
            if (response_expected) {
                lcd_128x64->response_expected[1] |= (1 << 6);
            } else {
                lcd_128x64->response_expected[1] &= ~(1 << 6);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_SLIDER_VALUE_CALLBACK_CONFIGURATION:
            if (response_expected) {
                lcd_128x64->response_expected[1] |= (1 << 7);
            } else {
                lcd_128x64->response_expected[1] &= ~(1 << 7);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_TAB_CONFIGURATION:
            if (response_expected) {
                lcd_128x64->response_expected[2] |= (1 << 0);
            } else {
                lcd_128x64->response_expected[2] &= ~(1 << 0);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_TAB_TEXT:
            if (response_expected) {
                lcd_128x64->response_expected[2] |= (1 << 1);
            } else {
                lcd_128x64->response_expected[2] &= ~(1 << 1);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_TAB_ICON:
            if (response_expected) {
                lcd_128x64->response_expected[2] |= (1 << 2);
            } else {
                lcd_128x64->response_expected[2] &= ~(1 << 2);
            }
            break;
        case TF_LCD_128X64_FUNCTION_REMOVE_GUI_TAB:
            if (response_expected) {
                lcd_128x64->response_expected[2] |= (1 << 3);
            } else {
                lcd_128x64->response_expected[2] &= ~(1 << 3);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_TAB_SELECTED:
            if (response_expected) {
                lcd_128x64->response_expected[2] |= (1 << 4);
            } else {
                lcd_128x64->response_expected[2] &= ~(1 << 4);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_TAB_SELECTED_CALLBACK_CONFIGURATION:
            if (response_expected) {
                lcd_128x64->response_expected[2] |= (1 << 5);
            } else {
                lcd_128x64->response_expected[2] &= ~(1 << 5);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_GRAPH_CONFIGURATION:
            if (response_expected) {
                lcd_128x64->response_expected[2] |= (1 << 6);
            } else {
                lcd_128x64->response_expected[2] &= ~(1 << 6);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_GUI_GRAPH_DATA_LOW_LEVEL:
            if (response_expected) {
                lcd_128x64->response_expected[2] |= (1 << 7);
            } else {
                lcd_128x64->response_expected[2] &= ~(1 << 7);
            }
            break;
        case TF_LCD_128X64_FUNCTION_REMOVE_GUI_GRAPH:
            if (response_expected) {
                lcd_128x64->response_expected[3] |= (1 << 0);
            } else {
                lcd_128x64->response_expected[3] &= ~(1 << 0);
            }
            break;
        case TF_LCD_128X64_FUNCTION_REMOVE_ALL_GUI:
            if (response_expected) {
                lcd_128x64->response_expected[3] |= (1 << 1);
            } else {
                lcd_128x64->response_expected[3] &= ~(1 << 1);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_TOUCH_LED_CONFIG:
            if (response_expected) {
                lcd_128x64->response_expected[3] |= (1 << 2);
            } else {
                lcd_128x64->response_expected[3] &= ~(1 << 2);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                lcd_128x64->response_expected[3] |= (1 << 3);
            } else {
                lcd_128x64->response_expected[3] &= ~(1 << 3);
            }
            break;
        case TF_LCD_128X64_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                lcd_128x64->response_expected[3] |= (1 << 4);
            } else {
                lcd_128x64->response_expected[3] &= ~(1 << 4);
            }
            break;
        case TF_LCD_128X64_FUNCTION_RESET:
            if (response_expected) {
                lcd_128x64->response_expected[3] |= (1 << 5);
            } else {
                lcd_128x64->response_expected[3] &= ~(1 << 5);
            }
            break;
        case TF_LCD_128X64_FUNCTION_WRITE_UID:
            if (response_expected) {
                lcd_128x64->response_expected[3] |= (1 << 6);
            } else {
                lcd_128x64->response_expected[3] &= ~(1 << 6);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_lcd_128x64_set_response_expected_all(TF_LCD128x64 *lcd_128x64, bool response_expected) {
    memset(lcd_128x64->response_expected, response_expected ? 0xFF : 0, 4);
}

int tf_lcd_128x64_write_pixels_low_level(TF_LCD128x64 *lcd_128x64, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, uint16_t pixels_length, uint16_t pixels_chunk_offset, bool pixels_chunk_data[448]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_WRITE_PIXELS_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_WRITE_PIXELS_LOW_LEVEL, 64, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)x_start;
    buf[1] = (uint8_t)y_start;
    buf[2] = (uint8_t)x_end;
    buf[3] = (uint8_t)y_end;
    pixels_length = tf_leconvert_uint16_to(pixels_length); memcpy(buf + 4, &pixels_length, 2);
    pixels_chunk_offset = tf_leconvert_uint16_to(pixels_chunk_offset); memcpy(buf + 6, &pixels_chunk_offset, 2);
    memset(buf + 8, 0, 56); for (i = 0; i < 448; ++i) buf[8 + (i / 8)] |= (pixels_chunk_data[i] ? 1 : 0) << (i % 8);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_read_pixels_low_level(TF_LCD128x64 *lcd_128x64, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, uint16_t *ret_pixels_length, uint16_t *ret_pixels_chunk_offset, bool ret_pixels_chunk_data[480]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_READ_PIXELS_LOW_LEVEL, 4, 64, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)x_start;
    buf[1] = (uint8_t)y_start;
    buf[2] = (uint8_t)x_end;
    buf[3] = (uint8_t)y_end;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_pixels_length != NULL) { *ret_pixels_length = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (ret_pixels_chunk_offset != NULL) { *ret_pixels_chunk_offset = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (ret_pixels_chunk_data != NULL) { tf_packetbuffer_read_bool_array(&lcd_128x64->tfp->spitfp->recv_buf, ret_pixels_chunk_data, 480);} else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 60); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_clear_display(TF_LCD128x64 *lcd_128x64) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_CLEAR_DISPLAY, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_CLEAR_DISPLAY, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_display_configuration(TF_LCD128x64 *lcd_128x64, uint8_t contrast, uint8_t backlight, bool invert, bool automatic_draw) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_DISPLAY_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_DISPLAY_CONFIGURATION, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)contrast;
    buf[1] = (uint8_t)backlight;
    buf[2] = invert ? 1 : 0;
    buf[3] = automatic_draw ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_display_configuration(TF_LCD128x64 *lcd_128x64, uint8_t *ret_contrast, uint8_t *ret_backlight, bool *ret_invert, bool *ret_automatic_draw) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_DISPLAY_CONFIGURATION, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_contrast != NULL) { *ret_contrast = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_backlight != NULL) { *ret_backlight = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_invert != NULL) { *ret_invert = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_automatic_draw != NULL) { *ret_automatic_draw = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_write_line(TF_LCD128x64 *lcd_128x64, uint8_t line, uint8_t position, const char text[22]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_WRITE_LINE, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_WRITE_LINE, 24, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)line;
    buf[1] = (uint8_t)position;
    memcpy(buf + 2, text, 22);


    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_draw_buffered_frame(TF_LCD128x64 *lcd_128x64, bool force_complete_redraw) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_DRAW_BUFFERED_FRAME, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_DRAW_BUFFERED_FRAME, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = force_complete_redraw ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_touch_position(TF_LCD128x64 *lcd_128x64, uint16_t *ret_pressure, uint16_t *ret_x, uint16_t *ret_y, uint32_t *ret_age) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_TOUCH_POSITION, 0, 10, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_pressure != NULL) { *ret_pressure = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (ret_x != NULL) { *ret_x = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (ret_y != NULL) { *ret_y = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (ret_age != NULL) { *ret_age = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_touch_position_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_TOUCH_POSITION_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_TOUCH_POSITION_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_touch_position_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_TOUCH_POSITION_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_touch_gesture(TF_LCD128x64 *lcd_128x64, uint8_t *ret_gesture, uint32_t *ret_duration, uint16_t *ret_pressure_max, uint16_t *ret_x_start, uint16_t *ret_y_start, uint16_t *ret_x_end, uint16_t *ret_y_end, uint32_t *ret_age) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_TOUCH_GESTURE, 0, 19, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_gesture != NULL) { *ret_gesture = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_duration != NULL) { *ret_duration = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        if (ret_pressure_max != NULL) { *ret_pressure_max = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (ret_x_start != NULL) { *ret_x_start = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (ret_y_start != NULL) { *ret_y_start = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (ret_x_end != NULL) { *ret_x_end = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (ret_y_end != NULL) { *ret_y_end = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (ret_age != NULL) { *ret_age = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_touch_gesture_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_TOUCH_GESTURE_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_TOUCH_GESTURE_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_touch_gesture_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_TOUCH_GESTURE_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_draw_line(TF_LCD128x64 *lcd_128x64, uint8_t position_x_start, uint8_t position_y_start, uint8_t position_x_end, uint8_t position_y_end, bool color) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_DRAW_LINE, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_DRAW_LINE, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)position_x_start;
    buf[1] = (uint8_t)position_y_start;
    buf[2] = (uint8_t)position_x_end;
    buf[3] = (uint8_t)position_y_end;
    buf[4] = color ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_draw_box(TF_LCD128x64 *lcd_128x64, uint8_t position_x_start, uint8_t position_y_start, uint8_t position_x_end, uint8_t position_y_end, bool fill, bool color) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_DRAW_BOX, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_DRAW_BOX, 6, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)position_x_start;
    buf[1] = (uint8_t)position_y_start;
    buf[2] = (uint8_t)position_x_end;
    buf[3] = (uint8_t)position_y_end;
    buf[4] = fill ? 1 : 0;
    buf[5] = color ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_draw_text(TF_LCD128x64 *lcd_128x64, uint8_t position_x, uint8_t position_y, uint8_t font, bool color, const char text[22]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_DRAW_TEXT, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_DRAW_TEXT, 26, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)position_x;
    buf[1] = (uint8_t)position_y;
    buf[2] = (uint8_t)font;
    buf[3] = color ? 1 : 0;
    memcpy(buf + 4, text, 22);


    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_gui_button(TF_LCD128x64 *lcd_128x64, uint8_t index, uint8_t position_x, uint8_t position_y, uint8_t width, uint8_t height, const char text[16]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_GUI_BUTTON, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_GUI_BUTTON, 21, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;
    buf[1] = (uint8_t)position_x;
    buf[2] = (uint8_t)position_y;
    buf[3] = (uint8_t)width;
    buf[4] = (uint8_t)height;
    memcpy(buf + 5, text, 16);


    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_button(TF_LCD128x64 *lcd_128x64, uint8_t index, bool *ret_active, uint8_t *ret_position_x, uint8_t *ret_position_y, uint8_t *ret_width, uint8_t *ret_height, char ret_text[16]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_BUTTON, 1, 21, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_active != NULL) { *ret_active = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_position_x != NULL) { *ret_position_x = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_position_y != NULL) { *ret_position_y = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_width != NULL) { *ret_width = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_height != NULL) { *ret_height = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_text != NULL) { tf_packetbuffer_pop_n(&lcd_128x64->tfp->spitfp->recv_buf, (uint8_t*)ret_text, 16);} else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 16); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_remove_gui_button(TF_LCD128x64 *lcd_128x64, uint8_t index) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_REMOVE_GUI_BUTTON, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_REMOVE_GUI_BUTTON, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_gui_button_pressed_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_GUI_BUTTON_PRESSED_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_GUI_BUTTON_PRESSED_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_button_pressed_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_BUTTON_PRESSED_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_button_pressed(TF_LCD128x64 *lcd_128x64, uint8_t index, bool *ret_pressed) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_BUTTON_PRESSED, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_pressed != NULL) { *ret_pressed = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_gui_slider(TF_LCD128x64 *lcd_128x64, uint8_t index, uint8_t position_x, uint8_t position_y, uint8_t length, uint8_t direction, uint8_t value) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_GUI_SLIDER, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_GUI_SLIDER, 6, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;
    buf[1] = (uint8_t)position_x;
    buf[2] = (uint8_t)position_y;
    buf[3] = (uint8_t)length;
    buf[4] = (uint8_t)direction;
    buf[5] = (uint8_t)value;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_slider(TF_LCD128x64 *lcd_128x64, uint8_t index, bool *ret_active, uint8_t *ret_position_x, uint8_t *ret_position_y, uint8_t *ret_length, uint8_t *ret_direction, uint8_t *ret_value) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_SLIDER, 1, 6, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_active != NULL) { *ret_active = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_position_x != NULL) { *ret_position_x = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_position_y != NULL) { *ret_position_y = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_length != NULL) { *ret_length = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_direction != NULL) { *ret_direction = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_value != NULL) { *ret_value = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_remove_gui_slider(TF_LCD128x64 *lcd_128x64, uint8_t index) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_REMOVE_GUI_SLIDER, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_REMOVE_GUI_SLIDER, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_gui_slider_value_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_GUI_SLIDER_VALUE_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_GUI_SLIDER_VALUE_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_slider_value_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_SLIDER_VALUE_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_slider_value(TF_LCD128x64 *lcd_128x64, uint8_t index, uint8_t *ret_value) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_SLIDER_VALUE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_value != NULL) { *ret_value = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_gui_tab_configuration(TF_LCD128x64 *lcd_128x64, uint8_t change_tab_config, bool clear_gui) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_GUI_TAB_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_GUI_TAB_CONFIGURATION, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)change_tab_config;
    buf[1] = clear_gui ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_tab_configuration(TF_LCD128x64 *lcd_128x64, uint8_t *ret_change_tab_config, bool *ret_clear_gui) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_TAB_CONFIGURATION, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_change_tab_config != NULL) { *ret_change_tab_config = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_clear_gui != NULL) { *ret_clear_gui = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_gui_tab_text(TF_LCD128x64 *lcd_128x64, uint8_t index, const char text[5]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_GUI_TAB_TEXT, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_GUI_TAB_TEXT, 6, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;
    memcpy(buf + 1, text, 5);


    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_tab_text(TF_LCD128x64 *lcd_128x64, uint8_t index, bool *ret_active, char ret_text[5]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_TAB_TEXT, 1, 6, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_active != NULL) { *ret_active = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_text != NULL) { tf_packetbuffer_pop_n(&lcd_128x64->tfp->spitfp->recv_buf, (uint8_t*)ret_text, 5);} else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 5); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_gui_tab_icon(TF_LCD128x64 *lcd_128x64, uint8_t index, bool icon[168]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_GUI_TAB_ICON, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_GUI_TAB_ICON, 22, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;
    memset(buf + 1, 0, 21); for (i = 0; i < 168; ++i) buf[1 + (i / 8)] |= (icon[i] ? 1 : 0) << (i % 8);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_tab_icon(TF_LCD128x64 *lcd_128x64, uint8_t index, bool *ret_active, bool ret_icon[168]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_TAB_ICON, 1, 22, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_active != NULL) { *ret_active = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_icon != NULL) { tf_packetbuffer_read_bool_array(&lcd_128x64->tfp->spitfp->recv_buf, ret_icon, 168);} else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 21); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_remove_gui_tab(TF_LCD128x64 *lcd_128x64, uint8_t index) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_REMOVE_GUI_TAB, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_REMOVE_GUI_TAB, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_gui_tab_selected(TF_LCD128x64 *lcd_128x64, uint8_t index) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_GUI_TAB_SELECTED, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_GUI_TAB_SELECTED, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_gui_tab_selected_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_GUI_TAB_SELECTED_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_GUI_TAB_SELECTED_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_tab_selected_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_TAB_SELECTED_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_tab_selected(TF_LCD128x64 *lcd_128x64, int8_t *ret_index) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_TAB_SELECTED, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_index != NULL) { *ret_index = tf_packetbuffer_read_int8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_gui_graph_configuration(TF_LCD128x64 *lcd_128x64, uint8_t index, uint8_t graph_type, uint8_t position_x, uint8_t position_y, uint8_t width, uint8_t height, const char text_x[4], const char text_y[4]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_GUI_GRAPH_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_GUI_GRAPH_CONFIGURATION, 14, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;
    buf[1] = (uint8_t)graph_type;
    buf[2] = (uint8_t)position_x;
    buf[3] = (uint8_t)position_y;
    buf[4] = (uint8_t)width;
    buf[5] = (uint8_t)height;
    memcpy(buf + 6, text_x, 4);

    memcpy(buf + 10, text_y, 4);


    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_graph_configuration(TF_LCD128x64 *lcd_128x64, uint8_t index, bool *ret_active, uint8_t *ret_graph_type, uint8_t *ret_position_x, uint8_t *ret_position_y, uint8_t *ret_width, uint8_t *ret_height, char ret_text_x[4], char ret_text_y[4]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_GRAPH_CONFIGURATION, 1, 14, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_active != NULL) { *ret_active = tf_packetbuffer_read_bool(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_graph_type != NULL) { *ret_graph_type = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_position_x != NULL) { *ret_position_x = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_position_y != NULL) { *ret_position_y = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_width != NULL) { *ret_width = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_height != NULL) { *ret_height = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_text_x != NULL) { tf_packetbuffer_pop_n(&lcd_128x64->tfp->spitfp->recv_buf, (uint8_t*)ret_text_x, 4);} else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        if (ret_text_y != NULL) { tf_packetbuffer_pop_n(&lcd_128x64->tfp->spitfp->recv_buf, (uint8_t*)ret_text_y, 4);} else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_gui_graph_data_low_level(TF_LCD128x64 *lcd_128x64, uint8_t index, uint16_t data_length, uint16_t data_chunk_offset, uint8_t data_chunk_data[59]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_GUI_GRAPH_DATA_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_GUI_GRAPH_DATA_LOW_LEVEL, 64, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;
    data_length = tf_leconvert_uint16_to(data_length); memcpy(buf + 1, &data_length, 2);
    data_chunk_offset = tf_leconvert_uint16_to(data_chunk_offset); memcpy(buf + 3, &data_chunk_offset, 2);
    memcpy(buf + 5, data_chunk_data, 59);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_gui_graph_data_low_level(TF_LCD128x64 *lcd_128x64, uint8_t index, uint16_t *ret_data_length, uint16_t *ret_data_chunk_offset, uint8_t ret_data_chunk_data[59]) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_GUI_GRAPH_DATA_LOW_LEVEL, 1, 63, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_data_length != NULL) { *ret_data_length = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (ret_data_chunk_offset != NULL) { *ret_data_chunk_offset = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (ret_data_chunk_data != NULL) { for (i = 0; i < 59; ++i) ret_data_chunk_data[i] = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 59); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_remove_gui_graph(TF_LCD128x64 *lcd_128x64, uint8_t index) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_REMOVE_GUI_GRAPH, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_REMOVE_GUI_GRAPH, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)index;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_remove_all_gui(TF_LCD128x64 *lcd_128x64) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_REMOVE_ALL_GUI, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_REMOVE_ALL_GUI, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_touch_led_config(TF_LCD128x64 *lcd_128x64, uint8_t config) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_TOUCH_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_TOUCH_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_touch_led_config(TF_LCD128x64 *lcd_128x64, uint8_t *ret_config) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_TOUCH_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_spitfp_error_count(TF_LCD128x64 *lcd_128x64, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_bootloader_mode(TF_LCD128x64 *lcd_128x64, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_bootloader_mode(TF_LCD128x64 *lcd_128x64, uint8_t *ret_mode) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_write_firmware_pointer(TF_LCD128x64 *lcd_128x64, uint32_t pointer) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_write_firmware(TF_LCD128x64 *lcd_128x64, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_set_status_led_config(TF_LCD128x64 *lcd_128x64, uint8_t config) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_status_led_config(TF_LCD128x64 *lcd_128x64, uint8_t *ret_config) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_chip_temperature(TF_LCD128x64 *lcd_128x64, int16_t *ret_temperature) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_reset(TF_LCD128x64 *lcd_128x64) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_write_uid(TF_LCD128x64 *lcd_128x64, uint32_t uid) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_lcd_128x64_get_response_expected(lcd_128x64, TF_LCD_128X64_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(lcd_128x64->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_read_uid(TF_LCD128x64 *lcd_128x64, uint32_t *ret_uid) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_get_identity(TF_LCD128x64 *lcd_128x64, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(lcd_128x64->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(lcd_128x64->tfp, TF_LCD_128X64_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(lcd_128x64->tfp->hal) + tf_hal_get_common(lcd_128x64->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(lcd_128x64->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&lcd_128x64->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&lcd_128x64->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&lcd_128x64->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&lcd_128x64->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&lcd_128x64->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(lcd_128x64->tfp->hal, lcd_128x64->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(lcd_128x64->tfp);
    }

    result = tf_tfp_finish_send(lcd_128x64->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_lcd_128x64_write_pixels(TF_LCD128x64 *lcd_128x64, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, bool *pixels, uint16_t pixels_length) {
    int ret = TF_E_OK;
    uint16_t pixels_chunk_offset = 0;
    bool pixels_chunk_data[448];
    uint16_t pixels_chunk_length = 0;

    if (pixels_length == 0) {
        memset(&pixels_chunk_data, 0, sizeof(bool) * 448);

        ret = tf_lcd_128x64_write_pixels_low_level(lcd_128x64, x_start, y_start, x_end, y_end, pixels_length, pixels_chunk_offset, pixels_chunk_data);
    } else {

        while (pixels_chunk_offset < pixels_length) {
            pixels_chunk_length = pixels_length - pixels_chunk_offset;

            if (pixels_chunk_length > 448) {
                pixels_chunk_length = 448;
            }

            memcpy(pixels_chunk_data, &pixels[pixels_chunk_offset], sizeof(bool) * pixels_chunk_length);
            memset(&pixels_chunk_data[pixels_chunk_length], 0, sizeof(bool) * (448 - pixels_chunk_length));

            ret = tf_lcd_128x64_write_pixels_low_level(lcd_128x64, x_start, y_start, x_end, y_end, pixels_length, pixels_chunk_offset, pixels_chunk_data);

            if (ret != TF_E_OK) {
                break;
            }

            pixels_chunk_offset += 448;
        }

    }

    return ret;
}

int tf_lcd_128x64_read_pixels(TF_LCD128x64 *lcd_128x64, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, bool *ret_pixels, uint16_t *ret_pixels_length) {
    int ret = TF_E_OK;
    uint16_t pixels_length = 0;
    uint16_t pixels_chunk_offset = 0;
    bool pixels_chunk_data[480];
    bool pixels_out_of_sync;
    uint16_t pixels_chunk_length = 0;

    *ret_pixels_length = 0;

    ret = tf_lcd_128x64_read_pixels_low_level(lcd_128x64, x_start, y_start, x_end, y_end, &pixels_length, &pixels_chunk_offset, pixels_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    pixels_out_of_sync = pixels_chunk_offset != 0;

    if (!pixels_out_of_sync) {
        pixels_chunk_length = pixels_length - pixels_chunk_offset;

        if (pixels_chunk_length > 480) {
            pixels_chunk_length = 480;
        }

        memcpy(ret_pixels, pixels_chunk_data, sizeof(bool) * pixels_chunk_length);
        *ret_pixels_length = pixels_chunk_length;

        while (*ret_pixels_length < pixels_length) {
            ret = tf_lcd_128x64_read_pixels_low_level(lcd_128x64, x_start, y_start, x_end, y_end, &pixels_length, &pixels_chunk_offset, pixels_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            pixels_out_of_sync = pixels_chunk_offset != *ret_pixels_length;

            if (pixels_out_of_sync) {
                break;
            }

            pixels_chunk_length = pixels_length - pixels_chunk_offset;

            if (pixels_chunk_length > 480) {
                pixels_chunk_length = 480;
            }

            memcpy(&ret_pixels[*ret_pixels_length], pixels_chunk_data, sizeof(bool) * pixels_chunk_length);
            *ret_pixels_length += pixels_chunk_length;
        }
    }

    if (pixels_out_of_sync) {
        *ret_pixels_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (pixels_chunk_offset + 480 < pixels_length) {
            ret = tf_lcd_128x64_read_pixels_low_level(lcd_128x64, x_start, y_start, x_end, y_end, &pixels_length, &pixels_chunk_offset, pixels_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}

int tf_lcd_128x64_set_gui_graph_data(TF_LCD128x64 *lcd_128x64, uint8_t index, uint8_t *data, uint16_t data_length) {
    int ret = TF_E_OK;
    uint16_t data_chunk_offset = 0;
    uint8_t data_chunk_data[59];
    uint16_t data_chunk_length = 0;

    if (data_length == 0) {
        memset(&data_chunk_data, 0, sizeof(uint8_t) * 59);

        ret = tf_lcd_128x64_set_gui_graph_data_low_level(lcd_128x64, index, data_length, data_chunk_offset, data_chunk_data);
    } else {

        while (data_chunk_offset < data_length) {
            data_chunk_length = data_length - data_chunk_offset;

            if (data_chunk_length > 59) {
                data_chunk_length = 59;
            }

            memcpy(data_chunk_data, &data[data_chunk_offset], sizeof(uint8_t) * data_chunk_length);
            memset(&data_chunk_data[data_chunk_length], 0, sizeof(uint8_t) * (59 - data_chunk_length));

            ret = tf_lcd_128x64_set_gui_graph_data_low_level(lcd_128x64, index, data_length, data_chunk_offset, data_chunk_data);

            if (ret != TF_E_OK) {
                break;
            }

            data_chunk_offset += 59;
        }

    }

    return ret;
}

int tf_lcd_128x64_get_gui_graph_data(TF_LCD128x64 *lcd_128x64, uint8_t index, uint8_t *ret_data, uint16_t *ret_data_length) {
    int ret = TF_E_OK;
    uint16_t data_length = 0;
    uint16_t data_chunk_offset = 0;
    uint8_t data_chunk_data[59];
    bool data_out_of_sync;
    uint16_t data_chunk_length = 0;

    *ret_data_length = 0;

    ret = tf_lcd_128x64_get_gui_graph_data_low_level(lcd_128x64, index, &data_length, &data_chunk_offset, data_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    data_out_of_sync = data_chunk_offset != 0;

    if (!data_out_of_sync) {
        data_chunk_length = data_length - data_chunk_offset;

        if (data_chunk_length > 59) {
            data_chunk_length = 59;
        }

        memcpy(ret_data, data_chunk_data, sizeof(uint8_t) * data_chunk_length);
        *ret_data_length = data_chunk_length;

        while (*ret_data_length < data_length) {
            ret = tf_lcd_128x64_get_gui_graph_data_low_level(lcd_128x64, index, &data_length, &data_chunk_offset, data_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            data_out_of_sync = data_chunk_offset != *ret_data_length;

            if (data_out_of_sync) {
                break;
            }

            data_chunk_length = data_length - data_chunk_offset;

            if (data_chunk_length > 59) {
                data_chunk_length = 59;
            }

            memcpy(&ret_data[*ret_data_length], data_chunk_data, sizeof(uint8_t) * data_chunk_length);
            *ret_data_length += data_chunk_length;
        }
    }

    if (data_out_of_sync) {
        *ret_data_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (data_chunk_offset + 59 < data_length) {
            ret = tf_lcd_128x64_get_gui_graph_data_low_level(lcd_128x64, index, &data_length, &data_chunk_offset, data_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_lcd_128x64_register_touch_position_callback(TF_LCD128x64 *lcd_128x64, TF_LCD128x64TouchPositionHandler handler, void *user_data) {
    if (handler == NULL) {
        lcd_128x64->tfp->needs_callback_tick = false;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->touch_gesture_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->gui_button_pressed_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->gui_slider_value_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->gui_tab_selected_handler != NULL;
    } else {
        lcd_128x64->tfp->needs_callback_tick = true;
    }
    lcd_128x64->touch_position_handler = handler;
    lcd_128x64->touch_position_user_data = user_data;
}


void tf_lcd_128x64_register_touch_gesture_callback(TF_LCD128x64 *lcd_128x64, TF_LCD128x64TouchGestureHandler handler, void *user_data) {
    if (handler == NULL) {
        lcd_128x64->tfp->needs_callback_tick = false;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->touch_position_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->gui_button_pressed_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->gui_slider_value_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->gui_tab_selected_handler != NULL;
    } else {
        lcd_128x64->tfp->needs_callback_tick = true;
    }
    lcd_128x64->touch_gesture_handler = handler;
    lcd_128x64->touch_gesture_user_data = user_data;
}


void tf_lcd_128x64_register_gui_button_pressed_callback(TF_LCD128x64 *lcd_128x64, TF_LCD128x64GUIButtonPressedHandler handler, void *user_data) {
    if (handler == NULL) {
        lcd_128x64->tfp->needs_callback_tick = false;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->touch_position_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->touch_gesture_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->gui_slider_value_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->gui_tab_selected_handler != NULL;
    } else {
        lcd_128x64->tfp->needs_callback_tick = true;
    }
    lcd_128x64->gui_button_pressed_handler = handler;
    lcd_128x64->gui_button_pressed_user_data = user_data;
}


void tf_lcd_128x64_register_gui_slider_value_callback(TF_LCD128x64 *lcd_128x64, TF_LCD128x64GUISliderValueHandler handler, void *user_data) {
    if (handler == NULL) {
        lcd_128x64->tfp->needs_callback_tick = false;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->touch_position_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->touch_gesture_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->gui_button_pressed_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->gui_tab_selected_handler != NULL;
    } else {
        lcd_128x64->tfp->needs_callback_tick = true;
    }
    lcd_128x64->gui_slider_value_handler = handler;
    lcd_128x64->gui_slider_value_user_data = user_data;
}


void tf_lcd_128x64_register_gui_tab_selected_callback(TF_LCD128x64 *lcd_128x64, TF_LCD128x64GUITabSelectedHandler handler, void *user_data) {
    if (handler == NULL) {
        lcd_128x64->tfp->needs_callback_tick = false;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->touch_position_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->touch_gesture_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->gui_button_pressed_handler != NULL;
        lcd_128x64->tfp->needs_callback_tick |= lcd_128x64->gui_slider_value_handler != NULL;
    } else {
        lcd_128x64->tfp->needs_callback_tick = true;
    }
    lcd_128x64->gui_tab_selected_handler = handler;
    lcd_128x64->gui_tab_selected_user_data = user_data;
}
#endif
int tf_lcd_128x64_callback_tick(TF_LCD128x64 *lcd_128x64, uint32_t timeout_us) {
    return tf_tfp_callback_tick(lcd_128x64->tfp, tf_hal_current_time_us(lcd_128x64->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
