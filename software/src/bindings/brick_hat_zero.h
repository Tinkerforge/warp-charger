/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICK_HAT_ZERO_H
#define TF_BRICK_HAT_ZERO_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickHATZero HAT Zero Brick
 */

struct TF_HATZero;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_HATZeroUSBVoltageHandler)(struct TF_HATZero *device, uint16_t voltage, void *user_data);

#endif
/**
 * \ingroup BrickHATZero
 *
 * HAT for Raspberry Pi Zero with 4 Bricklets ports
 */
typedef struct TF_HATZero {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_HATZeroUSBVoltageHandler usb_voltage_handler;
    void *usb_voltage_user_data;

#endif
    uint8_t response_expected[1];
} TF_HATZero;

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_GET_USB_VOLTAGE 1

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_SET_USB_VOLTAGE_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_GET_USB_VOLTAGE_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_RESET 243

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_READ_UID 249

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_CALLBACK_USB_VOLTAGE 4

#endif

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_THRESHOLD_OPTION_OFF 'x'

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_THRESHOLD_OPTION_OUTSIDE 'o'

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_THRESHOLD_OPTION_INSIDE 'i'

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_THRESHOLD_OPTION_SMALLER '<'

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_THRESHOLD_OPTION_GREATER '>'

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickHATZero
 */
#define TF_HAT_ZERO_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickHATZero
 *
 * This constant is used to identify a HAT Zero Brick.
 *
 * The {@link hat_zero_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_HAT_ZERO_DEVICE_IDENTIFIER 112

/**
 * \ingroup BrickHATZero
 *
 * This constant represents the display name of a HAT Zero Brick.
 */
#define TF_HAT_ZERO_DEVICE_DISPLAY_NAME "HAT Zero Brick"

/**
 * \ingroup BrickHATZero
 *
 * Creates the device object \c hat_zero with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_hat_zero_create(TF_HATZero *hat_zero, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickHATZero
 *
 * Removes the device object \c hat_zero from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_hat_zero_destroy(TF_HATZero *hat_zero);

/**
 * \ingroup BrickHATZero
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the hat_zero_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_get_response_expected(TF_HATZero *hat_zero, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickHATZero
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
TF_ATTRIBUTE_NONNULL_ALL int tf_hat_zero_set_response_expected(TF_HATZero *hat_zero, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickHATZero
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_hat_zero_set_response_expected_all(TF_HATZero *hat_zero, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickHATZero
 *
 * Registers the given \c handler to the USB Voltage callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t voltage, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_hat_zero_set_usb_voltage_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_hat_zero_get_usb_voltage}.
 * 
 * .. versionadded:: 2.0.1$nbsp;(Firmware)
 */
TF_ATTRIBUTE_NONNULL(1) void tf_hat_zero_register_usb_voltage_callback(TF_HATZero *hat_zero, TF_HATZeroUSBVoltageHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickHATZero
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_hat_zero_callback_tick(TF_HATZero *hat_zero, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickHATZero
 *
 * Returns the USB supply voltage of the Raspberry Pi.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_hat_zero_register_usb_voltage_callback} callback. You can set the callback configuration
 * with {@link tf_hat_zero_set_usb_voltage_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_get_usb_voltage(TF_HATZero *hat_zero, uint16_t *ret_voltage);

/**
 * \ingroup BrickHATZero
 *
 * The period is the period with which the {@link tf_hat_zero_register_usb_voltage_callback} callback is triggered
 * periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change
 * within the period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 * 
 * It is furthermore possible to constrain the callback with thresholds.
 * 
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_hat_zero_register_usb_voltage_callback} callback.
 * 
 * The following options are possible:
 * 
 * \verbatim
 *  "Option", "Description"
 * 
 *  "'x'",    "Threshold is turned off"
 *  "'o'",    "Threshold is triggered when the value is *outside* the min and max values"
 *  "'i'",    "Threshold is triggered when the value is *inside* or equal to the min and max values"
 *  "'<'",    "Threshold is triggered when the value is smaller than the min value (max is ignored)"
 *  "'>'",    "Threshold is triggered when the value is greater than the min value (max is ignored)"
 * \endverbatim
 * 
 * If the option is set to 'x' (threshold turned off) the callback is triggered with the fixed period.
 * 
 * .. versionadded:: 2.0.1$nbsp;(Firmware)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_set_usb_voltage_callback_configuration(TF_HATZero *hat_zero, uint32_t period, bool value_has_to_change, char option, uint16_t min, uint16_t max);

/**
 * \ingroup BrickHATZero
 *
 * Returns the callback configuration as set by {@link tf_hat_zero_set_usb_voltage_callback_configuration}.
 * 
 * .. versionadded:: 2.0.1$nbsp;(Firmware)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_get_usb_voltage_callback_configuration(TF_HATZero *hat_zero, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);

/**
 * \ingroup BrickHATZero
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
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_get_spitfp_error_count(TF_HATZero *hat_zero, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickHATZero
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
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_set_bootloader_mode(TF_HATZero *hat_zero, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickHATZero
 *
 * Returns the current bootloader mode, see {@link tf_hat_zero_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_get_bootloader_mode(TF_HATZero *hat_zero, uint8_t *ret_mode);

/**
 * \ingroup BrickHATZero
 *
 * Sets the firmware pointer for {@link tf_hat_zero_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_set_write_firmware_pointer(TF_HATZero *hat_zero, uint32_t pointer);

/**
 * \ingroup BrickHATZero
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_hat_zero_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_write_firmware(TF_HATZero *hat_zero, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickHATZero
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_set_status_led_config(TF_HATZero *hat_zero, uint8_t config);

/**
 * \ingroup BrickHATZero
 *
 * Returns the configuration as set by {@link tf_hat_zero_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_get_status_led_config(TF_HATZero *hat_zero, uint8_t *ret_config);

/**
 * \ingroup BrickHATZero
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_get_chip_temperature(TF_HATZero *hat_zero, int16_t *ret_temperature);

/**
 * \ingroup BrickHATZero
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_reset(TF_HATZero *hat_zero);

/**
 * \ingroup BrickHATZero
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_write_uid(TF_HATZero *hat_zero, uint32_t uid);

/**
 * \ingroup BrickHATZero
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_read_uid(TF_HATZero *hat_zero, uint32_t *ret_uid);

/**
 * \ingroup BrickHATZero
 *
 * Returns the UID, the UID where the HAT is connected to
 * (typically '0' as the HAT is the root device in the topology),
 * the position, the hardware and firmware version as well as the
 * device identifier.
 * 
 * The HAT (Zero) Brick is always at position 'i'.
 * 
 * The device identifier numbers can be found :ref:`here <device_identifier>`.
 * |device_identifier_constant|
 */
TF_ATTRIBUTE_NONNULL(1) int tf_hat_zero_get_identity(TF_HATZero *hat_zero, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
