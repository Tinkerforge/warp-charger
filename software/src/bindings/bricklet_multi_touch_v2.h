/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_MULTI_TOUCH_V2_H
#define TF_BRICKLET_MULTI_TOUCH_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletMultiTouchV2 Multi Touch Bricklet 2.0
 */

struct TF_MultiTouchV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_MultiTouchV2TouchStateHandler)(struct TF_MultiTouchV2 *device, bool state[13], void *user_data);

#endif
/**
 * \ingroup BrickletMultiTouchV2
 *
 * Capacitive touch sensor for 12 electrodes
 */
typedef struct TF_MultiTouchV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_MultiTouchV2TouchStateHandler touch_state_handler;
    void *touch_state_user_data;

#endif
    uint8_t response_expected[2];
} TF_MultiTouchV2;

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_GET_TOUCH_STATE 1

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_SET_TOUCH_STATE_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_GET_TOUCH_STATE_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_RECALIBRATE 5

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_SET_ELECTRODE_CONFIG 6

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_GET_ELECTRODE_CONFIG 7

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_SET_ELECTRODE_SENSITIVITY 8

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_GET_ELECTRODE_SENSITIVITY 9

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_SET_TOUCH_LED_CONFIG 10

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_GET_TOUCH_LED_CONFIG 11

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_CALLBACK_TOUCH_STATE 4

#endif

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_TOUCH_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_TOUCH_LED_CONFIG_ON 1

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_TOUCH_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_TOUCH_LED_CONFIG_SHOW_TOUCH 3

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletMultiTouchV2
 */
#define TF_MULTI_TOUCH_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletMultiTouchV2
 *
 * This constant is used to identify a Multi Touch Bricklet 2.0.
 *
 * The {@link multi_touch_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_MULTI_TOUCH_V2_DEVICE_IDENTIFIER 2129

/**
 * \ingroup BrickletMultiTouchV2
 *
 * This constant represents the display name of a Multi Touch Bricklet 2.0.
 */
#define TF_MULTI_TOUCH_V2_DEVICE_DISPLAY_NAME "Multi Touch Bricklet 2.0"

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Creates the device object \c multi_touch_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_multi_touch_v2_create(TF_MultiTouchV2 *multi_touch_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Removes the device object \c multi_touch_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_multi_touch_v2_destroy(TF_MultiTouchV2 *multi_touch_v2);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the multi_touch_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_get_response_expected(TF_MultiTouchV2 *multi_touch_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletMultiTouchV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_multi_touch_v2_set_response_expected(TF_MultiTouchV2 *multi_touch_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_multi_touch_v2_set_response_expected_all(TF_MultiTouchV2 *multi_touch_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletMultiTouchV2
 *
 * Registers the given \c handler to the Touch State callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(bool state[13], void *user_data) \endcode
 * 
 * Returns the current touch state, see {@link tf_multi_touch_v2_get_touch_state} for
 * information about the state.
 * 
 * This callback is triggered every time the touch state changes with
 * a given period (see {@link tf_multi_touch_v2_set_touch_state_callback_configuration})
 */
TF_ATTRIBUTE_NONNULL(1) void tf_multi_touch_v2_register_touch_state_callback(TF_MultiTouchV2 *multi_touch_v2, TF_MultiTouchV2TouchStateHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletMultiTouchV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_multi_touch_v2_callback_tick(TF_MultiTouchV2 *multi_touch_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Returns the current touch state. The state is given as a array of
 * bools.
 * 
 * Element 0 to 11 represent the 12 electrodes and element 12 represents
 * the proximity.
 * 
 * If an electrode is touched, the corresponding element is *true*. If
 * a hand or similar is in proximity to the electrodes, element 12 is
 * *true*.
 * 
 * The proximity is activated with a distance of 1-2cm. An electrode
 * is already counted as touched if a finger is nearly touching the
 * electrode. This means that you can put a piece of paper or foil
 * or similar on top of a electrode to build a touch panel with
 * a professional look.
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_multi_touch_v2_register_touch_state_callback} callback. You can set the callback configuration
 * with {@link tf_multi_touch_v2_set_touch_state_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_get_touch_state(TF_MultiTouchV2 *multi_touch_v2, bool ret_state[13]);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * The period is the period with which the {@link tf_multi_touch_v2_register_touch_state_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_set_touch_state_callback_configuration(TF_MultiTouchV2 *multi_touch_v2, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Returns the callback configuration as set by
 * {@link tf_multi_touch_v2_set_touch_state_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_get_touch_state_callback_configuration(TF_MultiTouchV2 *multi_touch_v2, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Recalibrates the electrodes. Call this function whenever you changed
 * or moved you electrodes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_recalibrate(TF_MultiTouchV2 *multi_touch_v2);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Enables/disables electrodes with a bool array (see {@link tf_multi_touch_v2_get_touch_state}).
 * 
 * *True* enables the electrode, *false* disables the electrode. A
 * disabled electrode will always return *false* as its state. If you
 * don't need all electrodes you can disable the electrodes that are
 * not needed.
 * 
 * It is recommended that you disable the proximity electrode (element 12) if
 * the proximity feature is not needed. This will reduce the amount of
 * traffic that is produced by the {@link tf_multi_touch_v2_register_touch_state_callback} callback.
 * 
 * Disabling electrodes will also reduce power consumption.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_set_electrode_config(TF_MultiTouchV2 *multi_touch_v2, bool enabled_electrodes[13]);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Returns the electrode configuration, as set by {@link tf_multi_touch_v2_set_electrode_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_get_electrode_config(TF_MultiTouchV2 *multi_touch_v2, bool ret_enabled_electrodes[13]);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Sets the sensitivity of the electrodes. An electrode with a high sensitivity
 * will register a touch earlier then an electrode with a low sensitivity.
 * 
 * If you build a big electrode you might need to decrease the sensitivity, since
 * the area that can be charged will get bigger. If you want to be able to
 * activate an electrode from further away you need to increase the sensitivity.
 * 
 * After a new sensitivity is set, you likely want to call {@link tf_multi_touch_v2_recalibrate}
 * to calibrate the electrodes with the newly defined sensitivity.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_set_electrode_sensitivity(TF_MultiTouchV2 *multi_touch_v2, uint8_t sensitivity);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Returns the current sensitivity, as set by {@link tf_multi_touch_v2_set_electrode_sensitivity}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_get_electrode_sensitivity(TF_MultiTouchV2 *multi_touch_v2, uint8_t *ret_sensitivity);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Configures the touch LED to be either turned off, turned on, blink in
 * heartbeat mode or show the touch state (electrode touched = LED on).
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_set_touch_led_config(TF_MultiTouchV2 *multi_touch_v2, uint8_t config);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Returns the LED configuration as set by {@link tf_multi_touch_v2_set_touch_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_get_touch_led_config(TF_MultiTouchV2 *multi_touch_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletMultiTouchV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_get_spitfp_error_count(TF_MultiTouchV2 *multi_touch_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletMultiTouchV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_set_bootloader_mode(TF_MultiTouchV2 *multi_touch_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Returns the current bootloader mode, see {@link tf_multi_touch_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_get_bootloader_mode(TF_MultiTouchV2 *multi_touch_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Sets the firmware pointer for {@link tf_multi_touch_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_set_write_firmware_pointer(TF_MultiTouchV2 *multi_touch_v2, uint32_t pointer);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_multi_touch_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_write_firmware(TF_MultiTouchV2 *multi_touch_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_set_status_led_config(TF_MultiTouchV2 *multi_touch_v2, uint8_t config);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Returns the configuration as set by {@link tf_multi_touch_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_get_status_led_config(TF_MultiTouchV2 *multi_touch_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_get_chip_temperature(TF_MultiTouchV2 *multi_touch_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_reset(TF_MultiTouchV2 *multi_touch_v2);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_write_uid(TF_MultiTouchV2 *multi_touch_v2, uint32_t uid);

/**
 * \ingroup BrickletMultiTouchV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_read_uid(TF_MultiTouchV2 *multi_touch_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletMultiTouchV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_multi_touch_v2_get_identity(TF_MultiTouchV2 *multi_touch_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
