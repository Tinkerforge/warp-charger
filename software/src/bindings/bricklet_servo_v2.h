/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_SERVO_V2_H
#define TF_BRICKLET_SERVO_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletServoV2 Servo Bricklet 2.0
 */

struct TF_ServoV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_ServoV2PositionReachedHandler)(struct TF_ServoV2 *device, uint16_t servo_channel, int16_t position, void *user_data);

#endif
/**
 * \ingroup BrickletServoV2
 *
 * Drives up to 10 RC Servos
 */
typedef struct TF_ServoV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_ServoV2PositionReachedHandler position_reached_handler;
    void *position_reached_user_data;

#endif
    uint8_t response_expected[2];
} TF_ServoV2;

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_STATUS 1

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_ENABLE 2

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_ENABLED 3

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_POSITION 4

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_POSITION 5

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_CURRENT_POSITION 6

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_CURRENT_VELOCITY 7

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_MOTION_CONFIGURATION 8

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_MOTION_CONFIGURATION 9

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_PULSE_WIDTH 10

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_PULSE_WIDTH 11

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_DEGREE 12

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_DEGREE 13

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_PERIOD 14

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_PERIOD 15

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_SERVO_CURRENT 16

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_SERVO_CURRENT_CONFIGURATION 17

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_SERVO_CURRENT_CONFIGURATION 18

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_INPUT_VOLTAGE_CONFIGURATION 19

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_INPUT_VOLTAGE_CONFIGURATION 20

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_OVERALL_CURRENT 21

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_INPUT_VOLTAGE 22

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_CURRENT_CALIBRATION 23

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_CURRENT_CALIBRATION 24

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_POSITION_REACHED_CALLBACK_CONFIGURATION 25

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_POSITION_REACHED_CALLBACK_CONFIGURATION 26

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_CALLBACK_POSITION_REACHED 27

#endif

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletServoV2
 */
#define TF_SERVO_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletServoV2
 *
 * This constant is used to identify a Servo Bricklet 2.0.
 *
 * The {@link servo_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_SERVO_V2_DEVICE_IDENTIFIER 2157

/**
 * \ingroup BrickletServoV2
 *
 * This constant represents the display name of a Servo Bricklet 2.0.
 */
#define TF_SERVO_V2_DEVICE_DISPLAY_NAME "Servo Bricklet 2.0"

/**
 * \ingroup BrickletServoV2
 *
 * Creates the device object \c servo_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_servo_v2_create(TF_ServoV2 *servo_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletServoV2
 *
 * Removes the device object \c servo_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_servo_v2_destroy(TF_ServoV2 *servo_v2);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the servo_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_response_expected(TF_ServoV2 *servo_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletServoV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_servo_v2_set_response_expected(TF_ServoV2 *servo_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletServoV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_servo_v2_set_response_expected_all(TF_ServoV2 *servo_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletServoV2
 *
 * Registers the given \c handler to the Position Reached callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t servo_channel, int16_t position, void *user_data) \endcode
 * 
 * This callback is triggered when a position set by {@link tf_servo_v2_set_position}
 * is reached. If the new position matches the current position then the
 * callback is not triggered, because the servo didn't move.
 * The parameters are the servo and the position that is reached.
 * 
 * You can enable this callback with {@link tf_servo_v2_set_position_reached_callback_configuration}.
 * 
 * \note
 *  Since we can't get any feedback from the servo, this only works if the
 *  velocity (see {@link tf_servo_v2_set_motion_configuration}) is set smaller or equal to the
 *  maximum velocity of the servo. Otherwise the servo will lag behind the
 *  control value and the callback will be triggered too early.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_servo_v2_register_position_reached_callback(TF_ServoV2 *servo_v2, TF_ServoV2PositionReachedHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletServoV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_servo_v2_callback_tick(TF_ServoV2 *servo_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletServoV2
 *
 * Returns the status information of the Servo Bricklet 2.0.
 * 
 * The status includes
 * 
 * * for each channel if it is enabled or disabled,
 * * for each channel the current position,
 * * for each channel the current velocity,
 * * for each channel the current usage and
 * * the input voltage.
 * 
 * Please note that the position and the velocity is a snapshot of the
 * current position and velocity of the servo in motion.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_status(TF_ServoV2 *servo_v2, bool ret_enabled[10], int16_t ret_current_position[10], int16_t ret_current_velocity[10], uint16_t ret_current[10], uint16_t *ret_input_voltage);

/**
 * \ingroup BrickletServoV2
 *
 * Enables a servo channel (0 to 9). If a servo is enabled, the configured position,
 * velocity, acceleration, etc. are applied immediately.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_enable(TF_ServoV2 *servo_v2, uint16_t servo_channel, bool enable);

/**
 * \ingroup BrickletServoV2
 *
 * Returns *true* if the specified servo channel is enabled, *false* otherwise.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_enabled(TF_ServoV2 *servo_v2, uint16_t servo_channel, bool *ret_enable);

/**
 * \ingroup BrickletServoV2
 *
 * Sets the position in °/100 for the specified servo channel.
 * 
 * The default range of the position is -9000 to 9000, but it can be specified
 * according to your servo with {@link tf_servo_v2_set_degree}.
 * 
 * If you want to control a linear servo or RC brushless motor controller or
 * similar with the Servo Brick, you can also define lengths or speeds with
 * {@link tf_servo_v2_set_degree}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_position(TF_ServoV2 *servo_v2, uint16_t servo_channel, int16_t position);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the position of the specified servo channel as set by {@link tf_servo_v2_set_position}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_position(TF_ServoV2 *servo_v2, uint16_t servo_channel, int16_t *ret_position);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the *current* position of the specified servo channel. This may not be the
 * value of {@link tf_servo_v2_set_position} if the servo is currently approaching a
 * position goal.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_current_position(TF_ServoV2 *servo_v2, uint16_t servo_channel, int16_t *ret_position);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the *current* velocity of the specified servo channel. This may not be the
 * velocity specified by {@link tf_servo_v2_set_motion_configuration}. if the servo is
 * currently approaching a velocity goal.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_current_velocity(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint16_t *ret_velocity);

/**
 * \ingroup BrickletServoV2
 *
 * Sets the maximum velocity of the specified servo channel in °/100s as well as
 * the acceleration and deceleration in °/100s²
 * 
 * With a velocity of 0 °/100s the position will be set immediately (no velocity).
 * 
 * With an acc-/deceleration of 0 °/100s² the velocity will be set immediately
 * (no acc-/deceleration).
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_motion_configuration(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint32_t velocity, uint32_t acceleration, uint32_t deceleration);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the motion configuration as set by {@link tf_servo_v2_set_motion_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_motion_configuration(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint32_t *ret_velocity, uint32_t *ret_acceleration, uint32_t *ret_deceleration);

/**
 * \ingroup BrickletServoV2
 *
 * Sets the minimum and maximum pulse width of the specified servo channel in µs.
 * 
 * Usually, servos are controlled with a
 * `PWM <https://en.wikipedia.org/wiki/Pulse-width_modulation>`__, whereby the
 * length of the pulse controls the position of the servo. Every servo has
 * different minimum and maximum pulse widths, these can be specified with
 * this function.
 * 
 * If you have a datasheet for your servo that specifies the minimum and
 * maximum pulse width, you should set the values accordingly. If your servo
 * comes without any datasheet you have to find the values via trial and error.
 * 
 * Both values have a range from 1 to 65535 (unsigned 16-bit integer). The
 * minimum must be smaller than the maximum.
 * 
 * The default values are 1000µs (1ms) and 2000µs (2ms) for minimum and
 * maximum pulse width.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_pulse_width(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint32_t min, uint32_t max);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the minimum and maximum pulse width for the specified servo channel as set by
 * {@link tf_servo_v2_set_pulse_width}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_pulse_width(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint32_t *ret_min, uint32_t *ret_max);

/**
 * \ingroup BrickletServoV2
 *
 * Sets the minimum and maximum degree for the specified servo channel (by default
 * given as °/100).
 * 
 * This only specifies the abstract values between which the minimum and maximum
 * pulse width is scaled. For example: If you specify a pulse width of 1000µs
 * to 2000µs and a degree range of -90° to 90°, a call of {@link tf_servo_v2_set_position}
 * with 0 will result in a pulse width of 1500µs
 * (-90° = 1000µs, 90° = 2000µs, etc.).
 * 
 * Possible usage:
 * 
 * * The datasheet of your servo specifies a range of 200° with the middle position
 *   at 110°. In this case you can set the minimum to -9000 and the maximum to 11000.
 * * You measure a range of 220° on your servo and you don't have or need a middle
 *   position. In this case you can set the minimum to 0 and the maximum to 22000.
 * * You have a linear servo with a drive length of 20cm, In this case you could
 *   set the minimum to 0 and the maximum to 20000. Now you can set the Position
 *   with {@link tf_servo_v2_set_position} with a resolution of cm/100. Also the velocity will
 *   have a resolution of cm/100s and the acceleration will have a resolution of
 *   cm/100s².
 * * You don't care about units and just want the highest possible resolution. In
 *   this case you should set the minimum to -32767 and the maximum to 32767.
 * * You have a brushless motor with a maximum speed of 10000 rpm and want to
 *   control it with a RC brushless motor controller. In this case you can set the
 *   minimum to 0 and the maximum to 10000. {@link tf_servo_v2_set_position} now controls the rpm.
 * 
 * Both values have a possible range from -32767 to 32767
 * (signed 16-bit integer). The minimum must be smaller than the maximum.
 * 
 * The default values are -9000 and 9000 for the minimum and maximum degree.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_degree(TF_ServoV2 *servo_v2, uint16_t servo_channel, int16_t min, int16_t max);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the minimum and maximum degree for the specified servo channel as set by
 * {@link tf_servo_v2_set_degree}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_degree(TF_ServoV2 *servo_v2, uint16_t servo_channel, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletServoV2
 *
 * Sets the period of the specified servo channel in µs.
 * 
 * Usually, servos are controlled with a
 * `PWM <https://en.wikipedia.org/wiki/Pulse-width_modulation>`__. Different
 * servos expect PWMs with different periods. Most servos run well with a
 * period of about 20ms.
 * 
 * If your servo comes with a datasheet that specifies a period, you should
 * set it accordingly. If you don't have a datasheet and you have no idea
 * what the correct period is, the default value (19.5ms) will most likely
 * work fine.
 * 
 * The minimum possible period is 1µs and the maximum is 1000000µs.
 * 
 * The default value is 19.5ms (19500µs).
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_period(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint32_t period);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the period for the specified servo channel as set by {@link tf_servo_v2_set_period}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_period(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint32_t *ret_period);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the current consumption of the specified servo channel in mA.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_servo_current(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint16_t *ret_current);

/**
 * \ingroup BrickletServoV2
 *
 * Sets the averaging duration of the current measurement for the specified servo channel in ms.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_servo_current_configuration(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint8_t averaging_duration);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the servo current configuration for the specified servo channel as set
 * by {@link tf_servo_v2_set_servo_current_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_servo_current_configuration(TF_ServoV2 *servo_v2, uint16_t servo_channel, uint8_t *ret_averaging_duration);

/**
 * \ingroup BrickletServoV2
 *
 * Sets the averaging duration of the input voltage measurement for the specified servo channel in ms.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_input_voltage_configuration(TF_ServoV2 *servo_v2, uint8_t averaging_duration);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the input voltage configuration as set by {@link tf_servo_v2_set_input_voltage_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_input_voltage_configuration(TF_ServoV2 *servo_v2, uint8_t *ret_averaging_duration);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the current consumption of all servos together in mA.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_overall_current(TF_ServoV2 *servo_v2, uint16_t *ret_current);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the input voltage in mV. The input voltage is
 * given via the black power input connector on the Servo Brick.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_input_voltage(TF_ServoV2 *servo_v2, uint16_t *ret_voltage);

/**
 * \ingroup BrickletServoV2
 *
 * Sets an offset value (in mA) for each channel.
 * 
 * Note: On delivery the Servo Bricklet 2.0 is already calibrated.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_current_calibration(TF_ServoV2 *servo_v2, int16_t offset[10]);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the current calibration as set by {@link tf_servo_v2_set_current_calibration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_current_calibration(TF_ServoV2 *servo_v2, int16_t ret_offset[10]);

/**
 * \ingroup BrickletServoV2
 *
 * Enable/Disable {@link tf_servo_v2_register_position_reached_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_position_reached_callback_configuration(TF_ServoV2 *servo_v2, uint16_t servo_channel, bool enabled);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the callback configuration as set by
 * {@link tf_servo_v2_set_position_reached_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_position_reached_callback_configuration(TF_ServoV2 *servo_v2, uint16_t servo_channel, bool *ret_enabled);

/**
 * \ingroup BrickletServoV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_spitfp_error_count(TF_ServoV2 *servo_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletServoV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_bootloader_mode(TF_ServoV2 *servo_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the current bootloader mode, see {@link tf_servo_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_bootloader_mode(TF_ServoV2 *servo_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletServoV2
 *
 * Sets the firmware pointer for {@link tf_servo_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_write_firmware_pointer(TF_ServoV2 *servo_v2, uint32_t pointer);

/**
 * \ingroup BrickletServoV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_servo_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_write_firmware(TF_ServoV2 *servo_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletServoV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_set_status_led_config(TF_ServoV2 *servo_v2, uint8_t config);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the configuration as set by {@link tf_servo_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_status_led_config(TF_ServoV2 *servo_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_chip_temperature(TF_ServoV2 *servo_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletServoV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_reset(TF_ServoV2 *servo_v2);

/**
 * \ingroup BrickletServoV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_write_uid(TF_ServoV2 *servo_v2, uint32_t uid);

/**
 * \ingroup BrickletServoV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_read_uid(TF_ServoV2 *servo_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletServoV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_servo_v2_get_identity(TF_ServoV2 *servo_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
