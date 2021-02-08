/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_MOTORIZED_LINEAR_POTI_H
#define TF_BRICKLET_MOTORIZED_LINEAR_POTI_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletMotorizedLinearPoti Motorized Linear Poti Bricklet
 */

struct TF_MotorizedLinearPoti;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_MotorizedLinearPotiPositionHandler)(struct TF_MotorizedLinearPoti *device, uint16_t position, void *user_data);
typedef void (*TF_MotorizedLinearPotiPositionReachedHandler)(struct TF_MotorizedLinearPoti *device, uint16_t position, void *user_data);

#endif
/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Motorized Linear Potentiometer
 */
typedef struct TF_MotorizedLinearPoti {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_MotorizedLinearPotiPositionHandler position_handler;
    void *position_user_data;

    TF_MotorizedLinearPotiPositionReachedHandler position_reached_handler;
    void *position_reached_user_data;

#endif
    uint8_t response_expected[1];
} TF_MotorizedLinearPoti;

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_GET_POSITION 1

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_SET_POSITION_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_GET_POSITION_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_SET_MOTOR_POSITION 5

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_GET_MOTOR_POSITION 6

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_CALIBRATE 7

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_SET_POSITION_REACHED_CALLBACK_CONFIGURATION 8

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_GET_POSITION_REACHED_CALLBACK_CONFIGURATION 9

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_RESET 243

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_CALLBACK_POSITION 4

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_CALLBACK_POSITION_REACHED 10

#endif

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_THRESHOLD_OPTION_OFF 'x'

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_THRESHOLD_OPTION_OUTSIDE 'o'

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_THRESHOLD_OPTION_INSIDE 'i'

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_THRESHOLD_OPTION_SMALLER '<'

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_THRESHOLD_OPTION_GREATER '>'

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_DRIVE_MODE_FAST 0

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_DRIVE_MODE_SMOOTH 1

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletMotorizedLinearPoti
 */
#define TF_MOTORIZED_LINEAR_POTI_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * This constant is used to identify a Motorized Linear Poti Bricklet.
 *
 * The {@link motorized_linear_poti_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_MOTORIZED_LINEAR_POTI_DEVICE_IDENTIFIER 267

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * This constant represents the display name of a Motorized Linear Poti Bricklet.
 */
#define TF_MOTORIZED_LINEAR_POTI_DEVICE_DISPLAY_NAME "Motorized Linear Poti Bricklet"

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Creates the device object \c motorized_linear_poti with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_motorized_linear_poti_create(TF_MotorizedLinearPoti *motorized_linear_poti, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Removes the device object \c motorized_linear_poti from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_motorized_linear_poti_destroy(TF_MotorizedLinearPoti *motorized_linear_poti);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the motorized_linear_poti_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_get_response_expected(TF_MotorizedLinearPoti *motorized_linear_poti, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletMotorizedLinearPoti
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
TF_ATTRIBUTE_NONNULL_ALL int tf_motorized_linear_poti_set_response_expected(TF_MotorizedLinearPoti *motorized_linear_poti, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_motorized_linear_poti_set_response_expected_all(TF_MotorizedLinearPoti *motorized_linear_poti, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Registers the given \c handler to the Position callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t position, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_motorized_linear_poti_set_position_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_motorized_linear_poti_get_position}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_motorized_linear_poti_register_position_callback(TF_MotorizedLinearPoti *motorized_linear_poti, TF_MotorizedLinearPotiPositionHandler handler, void *user_data);


/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Registers the given \c handler to the Position Reached callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t position, void *user_data) \endcode
 * 
 * This callback is triggered if a new position as set by
 * {@link tf_motorized_linear_poti_set_motor_position} is reached.
 * 
 * The parameter is the current position.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_motorized_linear_poti_register_position_reached_callback(TF_MotorizedLinearPoti *motorized_linear_poti, TF_MotorizedLinearPotiPositionReachedHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_motorized_linear_poti_callback_tick(TF_MotorizedLinearPoti *motorized_linear_poti, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Returns the position of the linear potentiometer. The value is
 * between 0 (slider down) and 100 (slider up).
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_motorized_linear_poti_register_position_callback} callback. You can set the callback configuration
 * with {@link tf_motorized_linear_poti_set_position_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_get_position(TF_MotorizedLinearPoti *motorized_linear_poti, uint16_t *ret_position);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * The period is the period with which the {@link tf_motorized_linear_poti_register_position_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_motorized_linear_poti_register_position_callback} callback.
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
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_set_position_callback_configuration(TF_MotorizedLinearPoti *motorized_linear_poti, uint32_t period, bool value_has_to_change, char option, uint16_t min, uint16_t max);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Returns the callback configuration as set by {@link tf_motorized_linear_poti_set_position_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_get_position_callback_configuration(TF_MotorizedLinearPoti *motorized_linear_poti, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Sets the position of the potentiometer. The motorized potentiometer will
 * immediately start to approach the position. Depending on the chosen drive mode,
 * the position will either be reached as fast as possible or in a slow but smooth
 * motion.
 * 
 * The position has to be between 0 (slider down) and 100 (slider up).
 * 
 * If you set the hold position parameter to true, the position will automatically
 * be retained. If a user changes the position of the potentiometer, it will
 * automatically drive back to the original set point.
 * 
 * If the hold position parameter is set to false, the potentiometer can be changed
 * again by the user as soon as the set point was reached once.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_set_motor_position(TF_MotorizedLinearPoti *motorized_linear_poti, uint16_t position, uint8_t drive_mode, bool hold_position);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Returns the last motor position as set by {@link tf_motorized_linear_poti_set_motor_position}. This is not
 * the current position (use {@link tf_motorized_linear_poti_get_position} to get the current position). This
 * is the last used set point and configuration.
 * 
 * The position reached parameter is true if the position has been reached at one point.
 * The position may have been changed again in the meantime by the user.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_get_motor_position(TF_MotorizedLinearPoti *motorized_linear_poti, uint16_t *ret_position, uint8_t *ret_drive_mode, bool *ret_hold_position, bool *ret_position_reached);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Starts a calibration procedure. The potentiometer will be driven to the extreme
 * points to calibrate the potentiometer.
 * 
 * The calibration is saved in flash, it does not have to be called on every start up.
 * 
 * The Motorized Linear Poti Bricklet is already factory-calibrated during
 * testing at Tinkerforge.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_calibrate(TF_MotorizedLinearPoti *motorized_linear_poti);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Enables/Disables {@link tf_motorized_linear_poti_register_position_reached_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_set_position_reached_callback_configuration(TF_MotorizedLinearPoti *motorized_linear_poti, bool enabled);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Returns the {@link tf_motorized_linear_poti_register_position_reached_callback} callback configuration
 * as set by {@link tf_motorized_linear_poti_set_position_reached_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_get_position_reached_callback_configuration(TF_MotorizedLinearPoti *motorized_linear_poti, bool *ret_enabled);

/**
 * \ingroup BrickletMotorizedLinearPoti
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
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_get_spitfp_error_count(TF_MotorizedLinearPoti *motorized_linear_poti, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletMotorizedLinearPoti
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
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_set_bootloader_mode(TF_MotorizedLinearPoti *motorized_linear_poti, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Returns the current bootloader mode, see {@link tf_motorized_linear_poti_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_get_bootloader_mode(TF_MotorizedLinearPoti *motorized_linear_poti, uint8_t *ret_mode);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Sets the firmware pointer for {@link tf_motorized_linear_poti_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_set_write_firmware_pointer(TF_MotorizedLinearPoti *motorized_linear_poti, uint32_t pointer);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_motorized_linear_poti_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_write_firmware(TF_MotorizedLinearPoti *motorized_linear_poti, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_set_status_led_config(TF_MotorizedLinearPoti *motorized_linear_poti, uint8_t config);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Returns the configuration as set by {@link tf_motorized_linear_poti_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_get_status_led_config(TF_MotorizedLinearPoti *motorized_linear_poti, uint8_t *ret_config);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_get_chip_temperature(TF_MotorizedLinearPoti *motorized_linear_poti, int16_t *ret_temperature);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_reset(TF_MotorizedLinearPoti *motorized_linear_poti);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_write_uid(TF_MotorizedLinearPoti *motorized_linear_poti, uint32_t uid);

/**
 * \ingroup BrickletMotorizedLinearPoti
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_read_uid(TF_MotorizedLinearPoti *motorized_linear_poti, uint32_t *ret_uid);

/**
 * \ingroup BrickletMotorizedLinearPoti
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
TF_ATTRIBUTE_NONNULL(1) int tf_motorized_linear_poti_get_identity(TF_MotorizedLinearPoti *motorized_linear_poti, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
