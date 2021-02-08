/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_RGB_LED_BUTTON_H
#define TF_BRICKLET_RGB_LED_BUTTON_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletRGBLEDButton RGB LED Button Bricklet
 */

struct TF_RGBLEDButton;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_RGBLEDButtonButtonStateChangedHandler)(struct TF_RGBLEDButton *device, uint8_t state, void *user_data);

#endif
/**
 * \ingroup BrickletRGBLEDButton
 *
 * Push button with built-in RGB LED
 */
typedef struct TF_RGBLEDButton {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_RGBLEDButtonButtonStateChangedHandler button_state_changed_handler;
    void *button_state_changed_user_data;

#endif
    uint8_t response_expected[1];
} TF_RGBLEDButton;

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_SET_COLOR 1

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_GET_COLOR 2

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_GET_BUTTON_STATE 3

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_SET_COLOR_CALIBRATION 5

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_GET_COLOR_CALIBRATION 6

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_RESET 243

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_CALLBACK_BUTTON_STATE_CHANGED 4

#endif

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BUTTON_STATE_PRESSED 0

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BUTTON_STATE_RELEASED 1

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletRGBLEDButton
 */
#define TF_RGB_LED_BUTTON_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletRGBLEDButton
 *
 * This constant is used to identify a RGB LED Button Bricklet.
 *
 * The {@link rgb_led_button_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_RGB_LED_BUTTON_DEVICE_IDENTIFIER 282

/**
 * \ingroup BrickletRGBLEDButton
 *
 * This constant represents the display name of a RGB LED Button Bricklet.
 */
#define TF_RGB_LED_BUTTON_DEVICE_DISPLAY_NAME "RGB LED Button Bricklet"

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Creates the device object \c rgb_led_button with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_rgb_led_button_create(TF_RGBLEDButton *rgb_led_button, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Removes the device object \c rgb_led_button from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_rgb_led_button_destroy(TF_RGBLEDButton *rgb_led_button);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the rgb_led_button_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_get_response_expected(TF_RGBLEDButton *rgb_led_button, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletRGBLEDButton
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
TF_ATTRIBUTE_NONNULL_ALL int tf_rgb_led_button_set_response_expected(TF_RGBLEDButton *rgb_led_button, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_rgb_led_button_set_response_expected_all(TF_RGBLEDButton *rgb_led_button, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletRGBLEDButton
 *
 * Registers the given \c handler to the Button State Changed callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t state, void *user_data) \endcode
 * 
 * This callback is triggered every time the button state changes from pressed to
 * released or from released to pressed.
 * 
 * The parameter is the current state of the button.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rgb_led_button_register_button_state_changed_callback(TF_RGBLEDButton *rgb_led_button, TF_RGBLEDButtonButtonStateChangedHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletRGBLEDButton
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_rgb_led_button_callback_tick(TF_RGBLEDButton *rgb_led_button, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Sets the color of the LED.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_set_color(TF_RGBLEDButton *rgb_led_button, uint8_t red, uint8_t green, uint8_t blue);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Returns the LED color as set by {@link tf_rgb_led_button_set_color}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_get_color(TF_RGBLEDButton *rgb_led_button, uint8_t *ret_red, uint8_t *ret_green, uint8_t *ret_blue);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Returns the current state of the button (either pressed or released).
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_get_button_state(TF_RGBLEDButton *rgb_led_button, uint8_t *ret_state);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Sets a color calibration. Some colors appear brighter then others,
 * so a calibration may be necessary for uniform colors.
 * 
 * The calibration is saved in flash. You don't need to call this
 * function on every startup.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_set_color_calibration(TF_RGBLEDButton *rgb_led_button, uint8_t red, uint8_t green, uint8_t blue);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Returns the color calibration as set by {@link tf_rgb_led_button_set_color_calibration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_get_color_calibration(TF_RGBLEDButton *rgb_led_button, uint8_t *ret_red, uint8_t *ret_green, uint8_t *ret_blue);

/**
 * \ingroup BrickletRGBLEDButton
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
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_get_spitfp_error_count(TF_RGBLEDButton *rgb_led_button, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletRGBLEDButton
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
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_set_bootloader_mode(TF_RGBLEDButton *rgb_led_button, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Returns the current bootloader mode, see {@link tf_rgb_led_button_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_get_bootloader_mode(TF_RGBLEDButton *rgb_led_button, uint8_t *ret_mode);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Sets the firmware pointer for {@link tf_rgb_led_button_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_set_write_firmware_pointer(TF_RGBLEDButton *rgb_led_button, uint32_t pointer);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_rgb_led_button_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_write_firmware(TF_RGBLEDButton *rgb_led_button, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_set_status_led_config(TF_RGBLEDButton *rgb_led_button, uint8_t config);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Returns the configuration as set by {@link tf_rgb_led_button_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_get_status_led_config(TF_RGBLEDButton *rgb_led_button, uint8_t *ret_config);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_get_chip_temperature(TF_RGBLEDButton *rgb_led_button, int16_t *ret_temperature);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_reset(TF_RGBLEDButton *rgb_led_button);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_write_uid(TF_RGBLEDButton *rgb_led_button, uint32_t uid);

/**
 * \ingroup BrickletRGBLEDButton
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_read_uid(TF_RGBLEDButton *rgb_led_button, uint32_t *ret_uid);

/**
 * \ingroup BrickletRGBLEDButton
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
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_button_get_identity(TF_RGBLEDButton *rgb_led_button, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
