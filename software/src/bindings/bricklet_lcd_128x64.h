/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_LCD_128X64_H
#define TF_BRICKLET_LCD_128X64_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletLCD128x64 LCD 128x64 Bricklet
 */

struct TF_LCD128x64;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_LCD128x64TouchPositionHandler)(struct TF_LCD128x64 *device, uint16_t pressure, uint16_t x, uint16_t y, uint32_t age, void *user_data);
typedef void (*TF_LCD128x64TouchGestureHandler)(struct TF_LCD128x64 *device, uint8_t gesture, uint32_t duration, uint16_t pressure_max, uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint32_t age, void *user_data);
typedef void (*TF_LCD128x64GUIButtonPressedHandler)(struct TF_LCD128x64 *device, uint8_t index, bool pressed, void *user_data);
typedef void (*TF_LCD128x64GUISliderValueHandler)(struct TF_LCD128x64 *device, uint8_t index, uint8_t value, void *user_data);
typedef void (*TF_LCD128x64GUITabSelectedHandler)(struct TF_LCD128x64 *device, int8_t index, void *user_data);

#endif
/**
 * \ingroup BrickletLCD128x64
 *
 * 7.1cm (2.8") display with 128x64 pixel and touch screen
 */
typedef struct TF_LCD128x64 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_LCD128x64TouchPositionHandler touch_position_handler;
    void *touch_position_user_data;

    TF_LCD128x64TouchGestureHandler touch_gesture_handler;
    void *touch_gesture_user_data;

    TF_LCD128x64GUIButtonPressedHandler gui_button_pressed_handler;
    void *gui_button_pressed_user_data;

    TF_LCD128x64GUISliderValueHandler gui_slider_value_handler;
    void *gui_slider_value_user_data;

    TF_LCD128x64GUITabSelectedHandler gui_tab_selected_handler;
    void *gui_tab_selected_user_data;

#endif
    uint8_t response_expected[4];
} TF_LCD128x64;

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_WRITE_PIXELS_LOW_LEVEL 1

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_READ_PIXELS_LOW_LEVEL 2

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_CLEAR_DISPLAY 3

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_DISPLAY_CONFIGURATION 4

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_DISPLAY_CONFIGURATION 5

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_WRITE_LINE 6

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_DRAW_BUFFERED_FRAME 7

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_TOUCH_POSITION 8

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_TOUCH_POSITION_CALLBACK_CONFIGURATION 9

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_TOUCH_POSITION_CALLBACK_CONFIGURATION 10

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_TOUCH_GESTURE 12

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_TOUCH_GESTURE_CALLBACK_CONFIGURATION 13

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_TOUCH_GESTURE_CALLBACK_CONFIGURATION 14

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_DRAW_LINE 16

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_DRAW_BOX 17

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_DRAW_TEXT 18

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_GUI_BUTTON 19

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_BUTTON 20

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_REMOVE_GUI_BUTTON 21

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_GUI_BUTTON_PRESSED_CALLBACK_CONFIGURATION 22

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_BUTTON_PRESSED_CALLBACK_CONFIGURATION 23

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_BUTTON_PRESSED 24

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_GUI_SLIDER 26

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_SLIDER 27

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_REMOVE_GUI_SLIDER 28

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_GUI_SLIDER_VALUE_CALLBACK_CONFIGURATION 29

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_SLIDER_VALUE_CALLBACK_CONFIGURATION 30

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_SLIDER_VALUE 31

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_GUI_TAB_CONFIGURATION 33

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_TAB_CONFIGURATION 34

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_GUI_TAB_TEXT 35

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_TAB_TEXT 36

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_GUI_TAB_ICON 37

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_TAB_ICON 38

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_REMOVE_GUI_TAB 39

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_GUI_TAB_SELECTED 40

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_GUI_TAB_SELECTED_CALLBACK_CONFIGURATION 41

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_TAB_SELECTED_CALLBACK_CONFIGURATION 42

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_TAB_SELECTED 43

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_GUI_GRAPH_CONFIGURATION 45

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_GRAPH_CONFIGURATION 46

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_GUI_GRAPH_DATA_LOW_LEVEL 47

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_GUI_GRAPH_DATA_LOW_LEVEL 48

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_REMOVE_GUI_GRAPH 49

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_REMOVE_ALL_GUI 50

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_TOUCH_LED_CONFIG 51

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_TOUCH_LED_CONFIG 52

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_RESET 243

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_CALLBACK_TOUCH_POSITION 11

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_CALLBACK_TOUCH_GESTURE 15

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_CALLBACK_GUI_BUTTON_PRESSED 25

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_CALLBACK_GUI_SLIDER_VALUE 32

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_CALLBACK_GUI_TAB_SELECTED 44

#endif

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_GESTURE_LEFT_TO_RIGHT 0

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_GESTURE_RIGHT_TO_LEFT 1

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_GESTURE_TOP_TO_BOTTOM 2

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_GESTURE_BOTTOM_TO_TOP 3

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_COLOR_WHITE false

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_COLOR_BLACK true

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FONT_6X8 0

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FONT_6X16 1

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FONT_6X24 2

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FONT_6X32 3

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FONT_12X16 4

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FONT_12X24 5

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FONT_12X32 6

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FONT_18X24 7

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FONT_18X32 8

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_FONT_24X32 9

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_DIRECTION_HORIZONTAL 0

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_DIRECTION_VERTICAL 1

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_CHANGE_TAB_ON_CLICK 1

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_CHANGE_TAB_ON_SWIPE 2

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_CHANGE_TAB_ON_CLICK_AND_SWIPE 3

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_GRAPH_TYPE_DOT 0

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_GRAPH_TYPE_LINE 1

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_GRAPH_TYPE_BAR 2

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_TOUCH_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_TOUCH_LED_CONFIG_ON 1

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_TOUCH_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_TOUCH_LED_CONFIG_SHOW_TOUCH 3

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletLCD128x64
 */
#define TF_LCD_128X64_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletLCD128x64
 *
 * This constant is used to identify a LCD 128x64 Bricklet.
 *
 * The {@link lcd_128x64_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_LCD_128X64_DEVICE_IDENTIFIER 298

/**
 * \ingroup BrickletLCD128x64
 *
 * This constant represents the display name of a LCD 128x64 Bricklet.
 */
#define TF_LCD_128X64_DEVICE_DISPLAY_NAME "LCD 128x64 Bricklet"

/**
 * \ingroup BrickletLCD128x64
 *
 * Creates the device object \c lcd_128x64 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_lcd_128x64_create(TF_LCD128x64 *lcd_128x64, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletLCD128x64
 *
 * Removes the device object \c lcd_128x64 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_lcd_128x64_destroy(TF_LCD128x64 *lcd_128x64);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the lcd_128x64_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_response_expected(TF_LCD128x64 *lcd_128x64, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletLCD128x64
 *
 * Changes the response expected flag of the function specified by the
 * \c function_id parameter. This flag can only be changed for setter
 * (default value: *false*) and callback configuration functions
 * (default value: *true*). For getter functions it is always enabled.
 *
 * Enabling the response expected flag for a setter function allows to detect
 * timeouts and other error conditions calls of this setter as well. The device
 * will then send a response for this purpose. If this flag is disabled for a
 * setter function then no response is sent and errors are silently ignored,
 * because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_lcd_128x64_set_response_expected(TF_LCD128x64 *lcd_128x64, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletLCD128x64
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_lcd_128x64_set_response_expected_all(TF_LCD128x64 *lcd_128x64, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletLCD128x64
 *
 * Registers the given \c handler to the Touch Position callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t pressure, uint16_t x, uint16_t y, uint32_t age, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_lcd_128x64_set_touch_position_callback_configuration}. The parameters are the
 * same as for {@link tf_lcd_128x64_get_touch_position}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_lcd_128x64_register_touch_position_callback(TF_LCD128x64 *lcd_128x64, TF_LCD128x64TouchPositionHandler handler, void *user_data);


/**
 * \ingroup BrickletLCD128x64
 *
 * Registers the given \c handler to the Touch Gesture callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t gesture, uint32_t duration, uint16_t pressure_max, uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint32_t age, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_lcd_128x64_set_touch_gesture_callback_configuration}. The parameters are the
 * same as for {@link tf_lcd_128x64_get_touch_gesture}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_lcd_128x64_register_touch_gesture_callback(TF_LCD128x64 *lcd_128x64, TF_LCD128x64TouchGestureHandler handler, void *user_data);


/**
 * \ingroup BrickletLCD128x64
 *
 * Registers the given \c handler to the GUI Button Pressed callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t index, bool pressed, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_lcd_128x64_set_gui_button_pressed_callback_configuration}. The parameters are the
 * same as for {@link tf_lcd_128x64_get_gui_button_pressed}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) void tf_lcd_128x64_register_gui_button_pressed_callback(TF_LCD128x64 *lcd_128x64, TF_LCD128x64GUIButtonPressedHandler handler, void *user_data);


/**
 * \ingroup BrickletLCD128x64
 *
 * Registers the given \c handler to the GUI Slider Value callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t index, uint8_t value, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_lcd_128x64_set_gui_slider_value_callback_configuration}. The parameters are the
 * same as for {@link tf_lcd_128x64_get_gui_slider_value}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) void tf_lcd_128x64_register_gui_slider_value_callback(TF_LCD128x64 *lcd_128x64, TF_LCD128x64GUISliderValueHandler handler, void *user_data);


/**
 * \ingroup BrickletLCD128x64
 *
 * Registers the given \c handler to the GUI Tab Selected callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int8_t index, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_lcd_128x64_set_gui_tab_selected_callback_configuration}. The parameters are the
 * same as for {@link tf_lcd_128x64_get_gui_tab_selected}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) void tf_lcd_128x64_register_gui_tab_selected_callback(TF_LCD128x64 *lcd_128x64, TF_LCD128x64GUITabSelectedHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletLCD128x64
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_lcd_128x64_callback_tick(TF_LCD128x64 *lcd_128x64, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletLCD128x64
 *
 * Writes pixels to the specified window.
 * 
 * The pixels are written into the window line by line top to bottom
 * and each line is written from left to right.
 * 
 * If automatic draw is enabled (default) the pixels are directly written to
 * the screen. Only pixels that have actually changed are updated on the screen,
 * the rest stays the same.
 * 
 * If automatic draw is disabled the pixels are written to an internal buffer and
 * the buffer is transferred to the display only after {@link tf_lcd_128x64_draw_buffered_frame}
 * is called. This can be used to avoid flicker when drawing a complex frame in
 * multiple steps.
 * 
 * Automatic draw can be configured with the {@link tf_lcd_128x64_set_display_configuration}
 * function.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_write_pixels_low_level(TF_LCD128x64 *lcd_128x64, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, uint16_t pixels_length, uint16_t pixels_chunk_offset, bool pixels_chunk_data[448]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Reads pixels from the specified window.
 * 
 * The pixels are read from the window line by line top to bottom
 * and each line is read from left to right.
 * 
 * If automatic draw is enabled (default) the pixels that are read are always the
 * same that are shown on the display.
 * 
 * If automatic draw is disabled the pixels are read from the internal buffer
 * (see {@link tf_lcd_128x64_draw_buffered_frame}).
 * 
 * Automatic draw can be configured with the {@link tf_lcd_128x64_set_display_configuration}
 * function.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_read_pixels_low_level(TF_LCD128x64 *lcd_128x64, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, uint16_t *ret_pixels_length, uint16_t *ret_pixels_chunk_offset, bool ret_pixels_chunk_data[480]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Clears the complete content of the display.
 * 
 * If automatic draw is enabled (default) the pixels are directly cleared.
 * 
 * If automatic draw is disabled the the internal buffer is cleared and
 * the buffer is transferred to the display only after {@link tf_lcd_128x64_draw_buffered_frame}
 * is called. This can be used to avoid flicker when drawing a complex frame in
 * multiple steps.
 * 
 * Automatic draw can be configured with the {@link tf_lcd_128x64_set_display_configuration}
 * function.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_clear_display(TF_LCD128x64 *lcd_128x64);

/**
 * \ingroup BrickletLCD128x64
 *
 * Sets the configuration of the display.
 * 
 * If automatic draw is set to *true*, the display is automatically updated with every
 * call of {@link tf_lcd_128x64_write_pixels} and {@link tf_lcd_128x64_write_line}. If it is set to false, the
 * changes are written into an internal buffer and only shown on the display after
 * a call of {@link tf_lcd_128x64_draw_buffered_frame}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_display_configuration(TF_LCD128x64 *lcd_128x64, uint8_t contrast, uint8_t backlight, bool invert, bool automatic_draw);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the configuration as set by {@link tf_lcd_128x64_set_display_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_display_configuration(TF_LCD128x64 *lcd_128x64, uint8_t *ret_contrast, uint8_t *ret_backlight, bool *ret_invert, bool *ret_automatic_draw);

/**
 * \ingroup BrickletLCD128x64
 *
 * Writes text to a specific line with a specific position.
 * 
 * For example: (1, 10, "Hello") will write *Hello* in the middle of the
 * second line of the display.
 * 
 * The display uses a special 5x7 pixel charset. You can view the characters
 * of the charset in Brick Viewer.
 * 
 * If automatic draw is enabled (default) the text is directly written to
 * the screen. Only pixels that have actually changed are updated on the screen,
 * the rest stays the same.
 * 
 * If automatic draw is disabled the text is written to an internal buffer and
 * the buffer is transferred to the display only after {@link tf_lcd_128x64_draw_buffered_frame}
 * is called. This can be used to avoid flicker when drawing a complex frame in
 * multiple steps.
 * 
 * Automatic draw can be configured with the {@link tf_lcd_128x64_set_display_configuration}
 * function.
 * 
 * This function is a 1:1 replacement for the function with the same name
 * in the LCD 20x4 Bricklet. You can draw text at a specific pixel position
 * and with different font sizes with the {@link tf_lcd_128x64_draw_text} function.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_write_line(TF_LCD128x64 *lcd_128x64, uint8_t line, uint8_t position, const char text[22]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Draws the currently buffered frame. Normally each call of {@link tf_lcd_128x64_write_pixels} and
 * {@link tf_lcd_128x64_write_line} draws directly onto the display. If you turn automatic draw off
 * ({@link tf_lcd_128x64_set_display_configuration}), the data is written in an internal buffer and
 * only transferred to the display by calling this function. This can be used to
 * avoid flicker when drawing a complex frame in multiple steps.
 * 
 * Set the `force complete redraw` to *true* to redraw the whole display
 * instead of only the changed parts. Normally it should not be necessary to set this to
 * *true*. It may only become necessary in case of stuck pixels because of errors.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_draw_buffered_frame(TF_LCD128x64 *lcd_128x64, bool force_complete_redraw);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the last valid touch position:
 * 
 * * Pressure: Amount of pressure applied by the user
 * * X: Touch position on x-axis
 * * Y: Touch position on y-axis
 * * Age: Age of touch press (how long ago it was)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_touch_position(TF_LCD128x64 *lcd_128x64, uint16_t *ret_pressure, uint16_t *ret_x, uint16_t *ret_y, uint32_t *ret_age);

/**
 * \ingroup BrickletLCD128x64
 *
 * The period is the period with which the {@link tf_lcd_128x64_register_touch_position_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_touch_position_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the callback configuration as set by
 * {@link tf_lcd_128x64_set_touch_position_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_touch_position_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns one of four touch gestures that can be automatically detected by the Bricklet.
 * 
 * The gestures are swipes from left to right, right to left, top to bottom and bottom to top.
 * 
 * Additionally to the gestures a vector with a start and end position of the gesture is
 * provided. You can use this vector do determine a more exact location of the gesture (e.g.
 * the swipe from top to bottom was on the left or right part of the screen).
 * 
 * The age parameter corresponds to the age of gesture (how long ago it was).
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_touch_gesture(TF_LCD128x64 *lcd_128x64, uint8_t *ret_gesture, uint32_t *ret_duration, uint16_t *ret_pressure_max, uint16_t *ret_x_start, uint16_t *ret_y_start, uint16_t *ret_x_end, uint16_t *ret_y_end, uint32_t *ret_age);

/**
 * \ingroup BrickletLCD128x64
 *
 * The period is the period with which the {@link tf_lcd_128x64_register_touch_gesture_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_touch_gesture_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the callback configuration as set by
 * {@link tf_lcd_128x64_set_touch_gesture_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_touch_gesture_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletLCD128x64
 *
 * Draws a white or black line from (x, y)-start to (x, y)-end.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_draw_line(TF_LCD128x64 *lcd_128x64, uint8_t position_x_start, uint8_t position_y_start, uint8_t position_x_end, uint8_t position_y_end, bool color);

/**
 * \ingroup BrickletLCD128x64
 *
 * Draws a white or black box from (x, y)-start to (x, y)-end.
 * 
 * If you set fill to true, the box will be filled with the
 * color. Otherwise only the outline will be drawn.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_draw_box(TF_LCD128x64 *lcd_128x64, uint8_t position_x_start, uint8_t position_y_start, uint8_t position_x_end, uint8_t position_y_end, bool fill, bool color);

/**
 * \ingroup BrickletLCD128x64
 *
 * Draws a text at the pixel position (x, y).
 * 
 * You can use one of 9 different font sizes and draw the text in white or black.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_draw_text(TF_LCD128x64 *lcd_128x64, uint8_t position_x, uint8_t position_y, uint8_t font, bool color, const char text[22]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Draws a clickable button at position (x, y) with the given text.
 * 
 * You can use up to 12 buttons.
 * 
 * The x position + width has to be within the range of 1 to 128 and the y
 * position + height has to be within the range of 1 to 64.
 * 
 * The minimum useful width/height of a button is 3.
 * 
 * You can enable a callback for a button press with
 * {@link tf_lcd_128x64_set_gui_button_pressed_callback_configuration}. The callback will
 * be triggered for press and release-events.
 * 
 * The button is drawn in a separate GUI buffer and the button-frame will
 * always stay on top of the graphics drawn with {@link tf_lcd_128x64_write_pixels}. To
 * remove the button use {@link tf_lcd_128x64_remove_gui_button}.
 * 
 * If you want an icon instead of text, you can draw the icon inside of the
 * button with {@link tf_lcd_128x64_write_pixels}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_gui_button(TF_LCD128x64 *lcd_128x64, uint8_t index, uint8_t position_x, uint8_t position_y, uint8_t width, uint8_t height, const char text[16]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the button properties for a given `Index` as set by {@link tf_lcd_128x64_set_gui_button}.
 * 
 * Additionally the `Active` parameter shows if a button is currently active/visible
 * or not.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_button(TF_LCD128x64 *lcd_128x64, uint8_t index, bool *ret_active, uint8_t *ret_position_x, uint8_t *ret_position_y, uint8_t *ret_width, uint8_t *ret_height, char ret_text[16]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Removes the button with the given index.
 * 
 * You can use index 255 to remove all buttons.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_remove_gui_button(TF_LCD128x64 *lcd_128x64, uint8_t index);

/**
 * \ingroup BrickletLCD128x64
 *
 * The period is the period with which the {@link tf_lcd_128x64_register_gui_button_pressed_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_gui_button_pressed_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the callback configuration as set by
 * {@link tf_lcd_128x64_set_gui_button_pressed_callback_configuration}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_button_pressed_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the state of the button for the given index.
 * 
 * The state can either be pressed (true) or released (false).
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_button_pressed(TF_LCD128x64 *lcd_128x64, uint8_t index, bool *ret_pressed);

/**
 * \ingroup BrickletLCD128x64
 *
 * Draws a slider at position (x, y) with the given length.
 * 
 * You can use up to 6 sliders.
 * 
 * If you use the horizontal direction, the x position + length has to be
 * within the range of 1 to 128 and the y position has to be within
 * the range of 0 to 46.
 * 
 * If you use the vertical direction, the y position + length has to be
 * within the range of 1 to 64 and the x position has to be within
 * the range of 0 to 110.
 * 
 * The minimum length of a slider is 8.
 * 
 * The parameter value is the start-position of the slider, it can
 * be between 0 and length-8.
 * 
 * You can enable a callback for the slider value with
 * {@link tf_lcd_128x64_set_gui_slider_value_callback_configuration}.
 * 
 * The slider is drawn in a separate GUI buffer and it will
 * always stay on top of the graphics drawn with {@link tf_lcd_128x64_write_pixels}. To
 * remove the button use {@link tf_lcd_128x64_remove_gui_slider}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_gui_slider(TF_LCD128x64 *lcd_128x64, uint8_t index, uint8_t position_x, uint8_t position_y, uint8_t length, uint8_t direction, uint8_t value);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the slider properties for a given `Index` as set by {@link tf_lcd_128x64_set_gui_slider}.
 * 
 * Additionally the `Active` parameter shows if a button is currently active/visible
 * or not.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_slider(TF_LCD128x64 *lcd_128x64, uint8_t index, bool *ret_active, uint8_t *ret_position_x, uint8_t *ret_position_y, uint8_t *ret_length, uint8_t *ret_direction, uint8_t *ret_value);

/**
 * \ingroup BrickletLCD128x64
 *
 * Removes the slider with the given index.
 * 
 * You can use index 255 to remove all slider.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_remove_gui_slider(TF_LCD128x64 *lcd_128x64, uint8_t index);

/**
 * \ingroup BrickletLCD128x64
 *
 * The period is the period with which the {@link tf_lcd_128x64_register_gui_slider_value_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_gui_slider_value_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the callback configuration as set by
 * {@link tf_lcd_128x64_set_gui_slider_value_callback_configuration}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_slider_value_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the current slider value for the given index.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_slider_value(TF_LCD128x64 *lcd_128x64, uint8_t index, uint8_t *ret_value);

/**
 * \ingroup BrickletLCD128x64
 *
 * Sets the general configuration for tabs. You can configure the tabs to only
 * accept clicks or only swipes (gesture left/right and right/left) or both.
 * 
 * Additionally, if you set `Clear GUI` to true, all of the GUI elements (buttons,
 * slider, graphs) will automatically be removed on every tab change.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_gui_tab_configuration(TF_LCD128x64 *lcd_128x64, uint8_t change_tab_config, bool clear_gui);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the tab configuration as set by {@link tf_lcd_128x64_set_gui_tab_configuration}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_tab_configuration(TF_LCD128x64 *lcd_128x64, uint8_t *ret_change_tab_config, bool *ret_clear_gui);

/**
 * \ingroup BrickletLCD128x64
 *
 * Adds a text-tab with the given index.
 * 
 * You can use up to 10 tabs.
 * 
 * A text-tab with the same index as a icon-tab will overwrite the icon-tab.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_gui_tab_text(TF_LCD128x64 *lcd_128x64, uint8_t index, const char text[5]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the text for a given index as set by {@link tf_lcd_128x64_set_gui_tab_text}.
 * 
 * Additionally the `Active` parameter shows if the tab is currently active/visible
 * or not.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_tab_text(TF_LCD128x64 *lcd_128x64, uint8_t index, bool *ret_active, char ret_text[5]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Adds a icon-tab with the given index. The icon can have a width of 28 pixels
 * with a height of 6 pixels. It is drawn line-by-line from left to right.
 * 
 * You can use up to 10 tabs.
 * 
 * A icon-tab with the same index as a text-tab will overwrite the text-tab.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_gui_tab_icon(TF_LCD128x64 *lcd_128x64, uint8_t index, bool icon[168]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the icon for a given index as set by {@link tf_lcd_128x64_set_gui_tab_icon}.
 * 
 * Additionally the `Active` parameter shows if the tab is currently active/visible
 * or not.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_tab_icon(TF_LCD128x64 *lcd_128x64, uint8_t index, bool *ret_active, bool ret_icon[168]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Removes the tab with the given index.
 * 
 * You can use index 255 to remove all tabs.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_remove_gui_tab(TF_LCD128x64 *lcd_128x64, uint8_t index);

/**
 * \ingroup BrickletLCD128x64
 *
 * Sets the tab with the given index as selected (drawn as selected on the display).
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_gui_tab_selected(TF_LCD128x64 *lcd_128x64, uint8_t index);

/**
 * \ingroup BrickletLCD128x64
 *
 * The period is the period with which the {@link tf_lcd_128x64_register_gui_tab_selected_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_gui_tab_selected_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the callback configuration as set by
 * {@link tf_lcd_128x64_set_gui_tab_selected_callback_configuration}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_tab_selected_callback_configuration(TF_LCD128x64 *lcd_128x64, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the index of the currently selected tab.
 * If there are not tabs, the returned index is -1.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_tab_selected(TF_LCD128x64 *lcd_128x64, int8_t *ret_index);

/**
 * \ingroup BrickletLCD128x64
 *
 * Sets the configuration for up to four graphs.
 * 
 * The graph type can be dot-, line- or bar-graph.
 * 
 * The x and y position are pixel positions.
 * 
 * You can add a text for the x and y axis.
 * The text is drawn at the inside of the graph and it can overwrite some
 * of the graph data. If you need the text outside of the graph you can
 * leave this text here empty and use {@link tf_lcd_128x64_draw_text} to draw the caption
 * outside of the graph.
 * 
 * The data of the graph can be set and updated with {@link tf_lcd_128x64_set_gui_graph_data}.
 * 
 * The graph is drawn in a separate GUI buffer and the graph-frame and data will
 * always stay on top of the graphics drawn with {@link tf_lcd_128x64_write_pixels}. To
 * remove the graph use {@link tf_lcd_128x64_remove_gui_graph}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_gui_graph_configuration(TF_LCD128x64 *lcd_128x64, uint8_t index, uint8_t graph_type, uint8_t position_x, uint8_t position_y, uint8_t width, uint8_t height, const char text_x[4], const char text_y[4]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the graph properties for a given `Index` as set by {@link tf_lcd_128x64_set_gui_graph_configuration}.
 * 
 * Additionally the `Active` parameter shows if a graph is currently active/visible
 * or not.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_graph_configuration(TF_LCD128x64 *lcd_128x64, uint8_t index, bool *ret_active, uint8_t *ret_graph_type, uint8_t *ret_position_x, uint8_t *ret_position_y, uint8_t *ret_width, uint8_t *ret_height, char ret_text_x[4], char ret_text_y[4]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Sets the data for a graph with the given index. You have to configure the graph with
 * {@link tf_lcd_128x64_set_gui_graph_configuration} before you can set the first data.
 * 
 * The graph will show the first n values of the data that you set, where
 * n is the width set with {@link tf_lcd_128x64_set_gui_graph_configuration}. If you set
 * less then n values it will show the rest of the values as zero.
 * 
 * The maximum number of data-points you can set is 118 (which also corresponds to the
 * maximum width of the graph).
 * 
 * You have to scale your values to be between 0 and 255. 0 will be shown
 * at the bottom of the graph and 255 at the top.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_gui_graph_data_low_level(TF_LCD128x64 *lcd_128x64, uint8_t index, uint16_t data_length, uint16_t data_chunk_offset, uint8_t data_chunk_data[59]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the graph data for a given index as set by {@link tf_lcd_128x64_set_gui_graph_data}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_graph_data_low_level(TF_LCD128x64 *lcd_128x64, uint8_t index, uint16_t *ret_data_length, uint16_t *ret_data_chunk_offset, uint8_t ret_data_chunk_data[59]);

/**
 * \ingroup BrickletLCD128x64
 *
 * Removes the graph with the given index.
 * 
 * You can use index 255 to remove all graphs.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_remove_gui_graph(TF_LCD128x64 *lcd_128x64, uint8_t index);

/**
 * \ingroup BrickletLCD128x64
 *
 * Removes all GUI elements (buttons, slider, graphs, tabs).
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_remove_all_gui(TF_LCD128x64 *lcd_128x64);

/**
 * \ingroup BrickletLCD128x64
 *
 * Sets the touch LED configuration. By default the LED is on if the
 * LCD is touched.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is off.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_touch_led_config(TF_LCD128x64 *lcd_128x64, uint8_t config);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the configuration as set by {@link tf_lcd_128x64_set_touch_led_config}
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_touch_led_config(TF_LCD128x64 *lcd_128x64, uint8_t *ret_config);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the error count for the communication between Brick and Bricklet.
 * 
 * The errors are divided into
 * 
 * * ACK checksum errors,
 * * message checksum errors,
 * * framing errors and
 * * overflow errors.
 * 
 * The errors counts are for errors that occur on the Bricklet side. All
 * Bricks have a similar function that returns the errors on the Brick side.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_spitfp_error_count(TF_LCD128x64 *lcd_128x64, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletLCD128x64
 *
 * Sets the bootloader mode and returns the status after the requested
 * mode change was instigated.
 * 
 * You can change from bootloader mode to firmware mode and vice versa. A change
 * from bootloader mode to firmware mode will only take place if the entry function,
 * device identifier and CRC are present and correct.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_bootloader_mode(TF_LCD128x64 *lcd_128x64, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the current bootloader mode, see {@link tf_lcd_128x64_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_bootloader_mode(TF_LCD128x64 *lcd_128x64, uint8_t *ret_mode);

/**
 * \ingroup BrickletLCD128x64
 *
 * Sets the firmware pointer for {@link tf_lcd_128x64_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_write_firmware_pointer(TF_LCD128x64 *lcd_128x64, uint32_t pointer);

/**
 * \ingroup BrickletLCD128x64
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_lcd_128x64_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_write_firmware(TF_LCD128x64 *lcd_128x64, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletLCD128x64
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_status_led_config(TF_LCD128x64 *lcd_128x64, uint8_t config);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the configuration as set by {@link tf_lcd_128x64_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_status_led_config(TF_LCD128x64 *lcd_128x64, uint8_t *ret_config);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_chip_temperature(TF_LCD128x64 *lcd_128x64, int16_t *ret_temperature);

/**
 * \ingroup BrickletLCD128x64
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_reset(TF_LCD128x64 *lcd_128x64);

/**
 * \ingroup BrickletLCD128x64
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_write_uid(TF_LCD128x64 *lcd_128x64, uint32_t uid);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_read_uid(TF_LCD128x64 *lcd_128x64, uint32_t *ret_uid);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the UID, the UID where the Bricklet is connected to,
 * the position, the hardware and firmware version as well as the
 * device identifier.
 * 
 * The position can be 'a', 'b', 'c', 'd', 'e', 'f', 'g' or 'h' (Bricklet Port).
 * A Bricklet connected to an :ref:`Isolator Bricklet <isolator_bricklet>` is always at
 * position 'z'.
 * 
 * The device identifier numbers can be found :ref:`here <device_identifier>`.
 * |device_identifier_constant|
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_identity(TF_LCD128x64 *lcd_128x64, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

/**
 * \ingroup BrickletLCD128x64
 *
 * Writes pixels to the specified window.
 * 
 * The pixels are written into the window line by line top to bottom
 * and each line is written from left to right.
 * 
 * If automatic draw is enabled (default) the pixels are directly written to
 * the screen. Only pixels that have actually changed are updated on the screen,
 * the rest stays the same.
 * 
 * If automatic draw is disabled the pixels are written to an internal buffer and
 * the buffer is transferred to the display only after {@link tf_lcd_128x64_draw_buffered_frame}
 * is called. This can be used to avoid flicker when drawing a complex frame in
 * multiple steps.
 * 
 * Automatic draw can be configured with the {@link tf_lcd_128x64_set_display_configuration}
 * function.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_write_pixels(TF_LCD128x64 *lcd_128x64, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, bool *pixels, uint16_t pixels_length);

/**
 * \ingroup BrickletLCD128x64
 *
 * Reads pixels from the specified window.
 * 
 * The pixels are read from the window line by line top to bottom
 * and each line is read from left to right.
 * 
 * If automatic draw is enabled (default) the pixels that are read are always the
 * same that are shown on the display.
 * 
 * If automatic draw is disabled the pixels are read from the internal buffer
 * (see {@link tf_lcd_128x64_draw_buffered_frame}).
 * 
 * Automatic draw can be configured with the {@link tf_lcd_128x64_set_display_configuration}
 * function.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_read_pixels(TF_LCD128x64 *lcd_128x64, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, bool *ret_pixels, uint16_t *ret_pixels_length);

/**
 * \ingroup BrickletLCD128x64
 *
 * Sets the data for a graph with the given index. You have to configure the graph with
 * {@link tf_lcd_128x64_set_gui_graph_configuration} before you can set the first data.
 * 
 * The graph will show the first n values of the data that you set, where
 * n is the width set with {@link tf_lcd_128x64_set_gui_graph_configuration}. If you set
 * less then n values it will show the rest of the values as zero.
 * 
 * The maximum number of data-points you can set is 118 (which also corresponds to the
 * maximum width of the graph).
 * 
 * You have to scale your values to be between 0 and 255. 0 will be shown
 * at the bottom of the graph and 255 at the top.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_set_gui_graph_data(TF_LCD128x64 *lcd_128x64, uint8_t index, uint8_t *data, uint16_t data_length);

/**
 * \ingroup BrickletLCD128x64
 *
 * Returns the graph data for a given index as set by {@link tf_lcd_128x64_set_gui_graph_data}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_lcd_128x64_get_gui_graph_data(TF_LCD128x64 *lcd_128x64, uint8_t index, uint8_t *ret_data, uint16_t *ret_data_length);

#ifdef __cplusplus
}
#endif

#endif
