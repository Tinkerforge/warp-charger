/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_OLED_128X64_V2_H
#define TF_BRICKLET_OLED_128X64_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletOLED128x64V2 OLED 128x64 Bricklet 2.0
 */

struct TF_OLED128x64V2;
#ifdef TF_IMPLEMENT_CALLBACKS


#endif
/**
 * \ingroup BrickletOLED128x64V2
 *
 * 3.3cm (1.3") OLED display with 128x64 pixels
 */
typedef struct TF_OLED128x64V2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS

#endif
    uint8_t response_expected[2];
} TF_OLED128x64V2;

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_WRITE_PIXELS_LOW_LEVEL 1

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_READ_PIXELS_LOW_LEVEL 2

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_CLEAR_DISPLAY 3

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_SET_DISPLAY_CONFIGURATION 4

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_GET_DISPLAY_CONFIGURATION 5

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_WRITE_LINE 6

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_DRAW_BUFFERED_FRAME 7

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

#endif

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletOLED128x64V2
 */
#define TF_OLED_128X64_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletOLED128x64V2
 *
 * This constant is used to identify a OLED 128x64 Bricklet 2.0.
 *
 * The {@link oled_128x64_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_OLED_128X64_V2_DEVICE_IDENTIFIER 2112

/**
 * \ingroup BrickletOLED128x64V2
 *
 * This constant represents the display name of a OLED 128x64 Bricklet 2.0.
 */
#define TF_OLED_128X64_V2_DEVICE_DISPLAY_NAME "OLED 128x64 Bricklet 2.0"

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Creates the device object \c oled_128x64_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_oled_128x64_v2_create(TF_OLED128x64V2 *oled_128x64_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Removes the device object \c oled_128x64_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_oled_128x64_v2_destroy(TF_OLED128x64V2 *oled_128x64_v2);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the oled_128x64_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_get_response_expected(TF_OLED128x64V2 *oled_128x64_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletOLED128x64V2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_oled_128x64_v2_set_response_expected(TF_OLED128x64V2 *oled_128x64_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_oled_128x64_v2_set_response_expected_all(TF_OLED128x64V2 *oled_128x64_v2, bool response_expected);


#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletOLED128x64V2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_oled_128x64_v2_callback_tick(TF_OLED128x64V2 *oled_128x64_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletOLED128x64V2
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
 * the buffer is transferred to the display only after {@link tf_oled_128x64_v2_draw_buffered_frame}
 * is called. This can be used to avoid flicker when drawing a complex frame in
 * multiple steps.
 * 
 * Automatic draw can be configured with the {@link tf_oled_128x64_v2_set_display_configuration}
 * function.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_write_pixels_low_level(TF_OLED128x64V2 *oled_128x64_v2, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, uint16_t pixels_length, uint16_t pixels_chunk_offset, bool pixels_chunk_data[448]);

/**
 * \ingroup BrickletOLED128x64V2
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
 * (see {@link tf_oled_128x64_v2_draw_buffered_frame}).
 * 
 * Automatic draw can be configured with the {@link tf_oled_128x64_v2_set_display_configuration}
 * function.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_read_pixels_low_level(TF_OLED128x64V2 *oled_128x64_v2, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, uint16_t *ret_pixels_length, uint16_t *ret_pixels_chunk_offset, bool ret_pixels_chunk_data[480]);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Clears the complete content of the display.
 * 
 * If automatic draw is enabled (default) the pixels are directly cleared.
 * 
 * If automatic draw is disabled the the internal buffer is cleared and
 * the buffer is transferred to the display only after {@link tf_oled_128x64_v2_draw_buffered_frame}
 * is called. This can be used to avoid flicker when drawing a complex frame in
 * multiple steps.
 * 
 * Automatic draw can be configured with the {@link tf_oled_128x64_v2_set_display_configuration}
 * function.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_clear_display(TF_OLED128x64V2 *oled_128x64_v2);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Sets the configuration of the display.
 * 
 * You can set a contrast value from 0 to 255 and you can invert the color
 * (white/black) of the display.
 * 
 * If automatic draw is set to *true*, the display is automatically updated with every
 * call of {@link tf_oled_128x64_v2_write_pixels} or {@link tf_oled_128x64_v2_write_line}. If it is set to false, the
 * changes are written into an internal buffer and only shown on the display after
 * a call of {@link tf_oled_128x64_v2_draw_buffered_frame}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_set_display_configuration(TF_OLED128x64V2 *oled_128x64_v2, uint8_t contrast, bool invert, bool automatic_draw);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Returns the configuration as set by {@link tf_oled_128x64_v2_set_display_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_get_display_configuration(TF_OLED128x64V2 *oled_128x64_v2, uint8_t *ret_contrast, bool *ret_invert, bool *ret_automatic_draw);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Writes text to a specific line with a specific position.
 * The text can have a maximum of 22 characters.
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
 * the buffer is transferred to the display only after {@link tf_oled_128x64_v2_draw_buffered_frame}
 * is called. This can be used to avoid flicker when drawing a complex frame in
 * multiple steps.
 * 
 * Automatic draw can be configured with the {@link tf_oled_128x64_v2_set_display_configuration}
 * function.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_write_line(TF_OLED128x64V2 *oled_128x64_v2, uint8_t line, uint8_t position, const char text[22]);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Draws the currently buffered frame. Normally each call of {@link tf_oled_128x64_v2_write_pixels} and
 * {@link tf_oled_128x64_v2_write_line} draws directly onto the display. If you turn automatic draw off
 * ({@link tf_oled_128x64_v2_set_display_configuration}), the data is written in an internal buffer and
 * only transferred to the display by calling this function. This can be used to
 * avoid flicker when drawing a complex frame in multiple steps.
 * 
 * Set the `force complete redraw` to *true* to redraw the whole display
 * instead of only the changed parts. Normally it should not be necessary to set this to
 * *true*. It may only become necessary in case of stuck pixels because of errors.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_draw_buffered_frame(TF_OLED128x64V2 *oled_128x64_v2, bool force_complete_redraw);

/**
 * \ingroup BrickletOLED128x64V2
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
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_get_spitfp_error_count(TF_OLED128x64V2 *oled_128x64_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletOLED128x64V2
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
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_set_bootloader_mode(TF_OLED128x64V2 *oled_128x64_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Returns the current bootloader mode, see {@link tf_oled_128x64_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_get_bootloader_mode(TF_OLED128x64V2 *oled_128x64_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Sets the firmware pointer for {@link tf_oled_128x64_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_set_write_firmware_pointer(TF_OLED128x64V2 *oled_128x64_v2, uint32_t pointer);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_oled_128x64_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_write_firmware(TF_OLED128x64V2 *oled_128x64_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_set_status_led_config(TF_OLED128x64V2 *oled_128x64_v2, uint8_t config);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Returns the configuration as set by {@link tf_oled_128x64_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_get_status_led_config(TF_OLED128x64V2 *oled_128x64_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_get_chip_temperature(TF_OLED128x64V2 *oled_128x64_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_reset(TF_OLED128x64V2 *oled_128x64_v2);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_write_uid(TF_OLED128x64V2 *oled_128x64_v2, uint32_t uid);

/**
 * \ingroup BrickletOLED128x64V2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_read_uid(TF_OLED128x64V2 *oled_128x64_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletOLED128x64V2
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
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_get_identity(TF_OLED128x64V2 *oled_128x64_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

/**
 * \ingroup BrickletOLED128x64V2
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
 * the buffer is transferred to the display only after {@link tf_oled_128x64_v2_draw_buffered_frame}
 * is called. This can be used to avoid flicker when drawing a complex frame in
 * multiple steps.
 * 
 * Automatic draw can be configured with the {@link tf_oled_128x64_v2_set_display_configuration}
 * function.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_write_pixels(TF_OLED128x64V2 *oled_128x64_v2, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, bool *pixels, uint16_t pixels_length);

/**
 * \ingroup BrickletOLED128x64V2
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
 * (see {@link tf_oled_128x64_v2_draw_buffered_frame}).
 * 
 * Automatic draw can be configured with the {@link tf_oled_128x64_v2_set_display_configuration}
 * function.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_oled_128x64_v2_read_pixels(TF_OLED128x64V2 *oled_128x64_v2, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end, bool *ret_pixels, uint16_t *ret_pixels_length);

#ifdef __cplusplus
}
#endif

#endif
