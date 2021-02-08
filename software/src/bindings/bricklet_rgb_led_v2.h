/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_RGB_LED_V2_H
#define TF_BRICKLET_RGB_LED_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletRGBLEDV2 RGB LED Bricklet 2.0
 */

struct TF_RGBLEDV2;
#ifdef TF_IMPLEMENT_CALLBACKS


#endif
/**
 * \ingroup BrickletRGBLEDV2
 *
 * Controls one RGB LED
 */
typedef struct TF_RGBLEDV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS

#endif
    uint8_t response_expected[1];
} TF_RGBLEDV2;

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_SET_RGB_VALUE 1

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_GET_RGB_VALUE 2

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

#endif

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletRGBLEDV2
 */
#define TF_RGB_LED_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletRGBLEDV2
 *
 * This constant is used to identify a RGB LED Bricklet 2.0.
 *
 * The {@link rgb_led_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_RGB_LED_V2_DEVICE_IDENTIFIER 2127

/**
 * \ingroup BrickletRGBLEDV2
 *
 * This constant represents the display name of a RGB LED Bricklet 2.0.
 */
#define TF_RGB_LED_V2_DEVICE_DISPLAY_NAME "RGB LED Bricklet 2.0"

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Creates the device object \c rgb_led_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_rgb_led_v2_create(TF_RGBLEDV2 *rgb_led_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Removes the device object \c rgb_led_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_rgb_led_v2_destroy(TF_RGBLEDV2 *rgb_led_v2);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the rgb_led_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_get_response_expected(TF_RGBLEDV2 *rgb_led_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletRGBLEDV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_rgb_led_v2_set_response_expected(TF_RGBLEDV2 *rgb_led_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_rgb_led_v2_set_response_expected_all(TF_RGBLEDV2 *rgb_led_v2, bool response_expected);


#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletRGBLEDV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_rgb_led_v2_callback_tick(TF_RGBLEDV2 *rgb_led_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Sets the *r*, *g* and *b* values for the LED.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_set_rgb_value(TF_RGBLEDV2 *rgb_led_v2, uint8_t r, uint8_t g, uint8_t b);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Returns the *r*, *g* and *b* values of the LED as set by {@link tf_rgb_led_v2_set_rgb_value}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_get_rgb_value(TF_RGBLEDV2 *rgb_led_v2, uint8_t *ret_r, uint8_t *ret_g, uint8_t *ret_b);

/**
 * \ingroup BrickletRGBLEDV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_get_spitfp_error_count(TF_RGBLEDV2 *rgb_led_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletRGBLEDV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_set_bootloader_mode(TF_RGBLEDV2 *rgb_led_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Returns the current bootloader mode, see {@link tf_rgb_led_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_get_bootloader_mode(TF_RGBLEDV2 *rgb_led_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Sets the firmware pointer for {@link tf_rgb_led_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_set_write_firmware_pointer(TF_RGBLEDV2 *rgb_led_v2, uint32_t pointer);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_rgb_led_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_write_firmware(TF_RGBLEDV2 *rgb_led_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_set_status_led_config(TF_RGBLEDV2 *rgb_led_v2, uint8_t config);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Returns the configuration as set by {@link tf_rgb_led_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_get_status_led_config(TF_RGBLEDV2 *rgb_led_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_get_chip_temperature(TF_RGBLEDV2 *rgb_led_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_reset(TF_RGBLEDV2 *rgb_led_v2);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_write_uid(TF_RGBLEDV2 *rgb_led_v2, uint32_t uid);

/**
 * \ingroup BrickletRGBLEDV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_read_uid(TF_RGBLEDV2 *rgb_led_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletRGBLEDV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_rgb_led_v2_get_identity(TF_RGBLEDV2 *rgb_led_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
