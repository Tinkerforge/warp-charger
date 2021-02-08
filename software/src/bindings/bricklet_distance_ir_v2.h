/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_DISTANCE_IR_V2_H
#define TF_BRICKLET_DISTANCE_IR_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletDistanceIRV2 Distance IR Bricklet 2.0
 */

struct TF_DistanceIRV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_DistanceIRV2DistanceHandler)(struct TF_DistanceIRV2 *device, uint16_t distance, void *user_data);
typedef void (*TF_DistanceIRV2AnalogValueHandler)(struct TF_DistanceIRV2 *device, uint32_t analog_value, void *user_data);

#endif
/**
 * \ingroup BrickletDistanceIRV2
 *
 * Measures distance up to 150cm with infrared light
 */
typedef struct TF_DistanceIRV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_DistanceIRV2DistanceHandler distance_handler;
    void *distance_user_data;

    TF_DistanceIRV2AnalogValueHandler analog_value_handler;
    void *analog_value_user_data;

#endif
    uint8_t response_expected[2];
} TF_DistanceIRV2;

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_GET_DISTANCE 1

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_SET_DISTANCE_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_GET_DISTANCE_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_GET_ANALOG_VALUE 5

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_SET_ANALOG_VALUE_CALLBACK_CONFIGURATION 6

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_GET_ANALOG_VALUE_CALLBACK_CONFIGURATION 7

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_SET_MOVING_AVERAGE_CONFIGURATION 9

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_GET_MOVING_AVERAGE_CONFIGURATION 10

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_SET_DISTANCE_LED_CONFIG 11

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_GET_DISTANCE_LED_CONFIG 12

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_SET_SENSOR_TYPE 13

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_GET_SENSOR_TYPE 14

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_CALLBACK_DISTANCE 4

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_CALLBACK_ANALOG_VALUE 8

#endif

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_THRESHOLD_OPTION_OFF 'x'

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_THRESHOLD_OPTION_OUTSIDE 'o'

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_THRESHOLD_OPTION_INSIDE 'i'

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_THRESHOLD_OPTION_SMALLER '<'

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_THRESHOLD_OPTION_GREATER '>'

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_DISTANCE_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_DISTANCE_LED_CONFIG_ON 1

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_DISTANCE_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_DISTANCE_LED_CONFIG_SHOW_DISTANCE 3

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_SENSOR_TYPE_2Y0A41 0

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_SENSOR_TYPE_2Y0A21 1

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_SENSOR_TYPE_2Y0A02 2

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletDistanceIRV2
 */
#define TF_DISTANCE_IR_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletDistanceIRV2
 *
 * This constant is used to identify a Distance IR Bricklet 2.0.
 *
 * The {@link distance_ir_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_DISTANCE_IR_V2_DEVICE_IDENTIFIER 2125

/**
 * \ingroup BrickletDistanceIRV2
 *
 * This constant represents the display name of a Distance IR Bricklet 2.0.
 */
#define TF_DISTANCE_IR_V2_DEVICE_DISPLAY_NAME "Distance IR Bricklet 2.0"

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Creates the device object \c distance_ir_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_distance_ir_v2_create(TF_DistanceIRV2 *distance_ir_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Removes the device object \c distance_ir_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_distance_ir_v2_destroy(TF_DistanceIRV2 *distance_ir_v2);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the distance_ir_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_response_expected(TF_DistanceIRV2 *distance_ir_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletDistanceIRV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_distance_ir_v2_set_response_expected(TF_DistanceIRV2 *distance_ir_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_distance_ir_v2_set_response_expected_all(TF_DistanceIRV2 *distance_ir_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletDistanceIRV2
 *
 * Registers the given \c handler to the Distance callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t distance, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_distance_ir_v2_set_distance_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_distance_ir_v2_get_distance}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_distance_ir_v2_register_distance_callback(TF_DistanceIRV2 *distance_ir_v2, TF_DistanceIRV2DistanceHandler handler, void *user_data);


/**
 * \ingroup BrickletDistanceIRV2
 *
 * Registers the given \c handler to the Analog Value callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint32_t analog_value, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_distance_ir_v2_set_analog_value_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_distance_ir_v2_get_analog_value}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_distance_ir_v2_register_analog_value_callback(TF_DistanceIRV2 *distance_ir_v2, TF_DistanceIRV2AnalogValueHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletDistanceIRV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_distance_ir_v2_callback_tick(TF_DistanceIRV2 *distance_ir_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Returns the distance measured by the sensor. Possible
 * distance ranges are 40 to 300, 100 to 800 and 200 to 1500, depending on the
 * selected IR sensor.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_distance_ir_v2_register_distance_callback} callback. You can set the callback configuration
 * with {@link tf_distance_ir_v2_set_distance_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_distance(TF_DistanceIRV2 *distance_ir_v2, uint16_t *ret_distance);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * The period is the period with which the {@link tf_distance_ir_v2_register_distance_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_distance_ir_v2_register_distance_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_set_distance_callback_configuration(TF_DistanceIRV2 *distance_ir_v2, uint32_t period, bool value_has_to_change, char option, uint16_t min, uint16_t max);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Returns the callback configuration as set by {@link tf_distance_ir_v2_set_distance_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_distance_callback_configuration(TF_DistanceIRV2 *distance_ir_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Returns the analog value as read by a analog-to-digital converter.
 * 
 * This is unfiltered raw data. We made sure that the integration time
 * of the ADC is shorter then the measurement interval of the sensor
 * (10ms vs 16.5ms). So there is no information lost.
 * 
 * If you want to do your own calibration or create your own lookup table
 * you can use this value.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_distance_ir_v2_register_analog_value_callback} callback. You can set the callback configuration
 * with {@link tf_distance_ir_v2_set_analog_value_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_analog_value(TF_DistanceIRV2 *distance_ir_v2, uint32_t *ret_analog_value);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * The period is the period with which the {@link tf_distance_ir_v2_register_analog_value_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_distance_ir_v2_register_analog_value_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_set_analog_value_callback_configuration(TF_DistanceIRV2 *distance_ir_v2, uint32_t period, bool value_has_to_change, char option, uint32_t min, uint32_t max);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Returns the callback configuration as set by {@link tf_distance_ir_v2_set_analog_value_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_analog_value_callback_configuration(TF_DistanceIRV2 *distance_ir_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, uint32_t *ret_min, uint32_t *ret_max);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Sets the length of a `moving averaging <https://en.wikipedia.org/wiki/Moving_average>`__
 * for the distance.
 * 
 * Setting the length to 1 will turn the averaging off. With less averaging, there
 * is more noise on the data.
 * 
 * New data is gathered every ~10ms. With a moving average of length 1000 the
 * resulting averaging window has a length of approximately 10s. If you want to do
 * long term measurements the longest moving average will give the cleanest results.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_set_moving_average_configuration(TF_DistanceIRV2 *distance_ir_v2, uint16_t moving_average_length);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Returns the moving average configuration as set by {@link tf_distance_ir_v2_set_moving_average_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_moving_average_configuration(TF_DistanceIRV2 *distance_ir_v2, uint16_t *ret_moving_average_length);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Configures the distance LED to be either turned off, turned on, blink in
 * heartbeat mode or show the distance (brighter = object is nearer).
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_set_distance_led_config(TF_DistanceIRV2 *distance_ir_v2, uint8_t config);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Returns the LED configuration as set by {@link tf_distance_ir_v2_set_distance_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_distance_led_config(TF_DistanceIRV2 *distance_ir_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Sets the sensor type.
 * 
 * The Bricklet comes configured with the correct sensor type
 * and the type is saved in flash (i.e. the Bricklet retains the information if
 * power is lost).
 * 
 * If you want to change the sensor you can set the type in Brick Viewer,
 * you will likely never need to call this function from your program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_set_sensor_type(TF_DistanceIRV2 *distance_ir_v2, uint8_t sensor);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Returns the sensor type as set by {@link tf_distance_ir_v2_set_sensor_type}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_sensor_type(TF_DistanceIRV2 *distance_ir_v2, uint8_t *ret_sensor);

/**
 * \ingroup BrickletDistanceIRV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_spitfp_error_count(TF_DistanceIRV2 *distance_ir_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletDistanceIRV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_set_bootloader_mode(TF_DistanceIRV2 *distance_ir_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Returns the current bootloader mode, see {@link tf_distance_ir_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_bootloader_mode(TF_DistanceIRV2 *distance_ir_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Sets the firmware pointer for {@link tf_distance_ir_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_set_write_firmware_pointer(TF_DistanceIRV2 *distance_ir_v2, uint32_t pointer);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_distance_ir_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_write_firmware(TF_DistanceIRV2 *distance_ir_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_set_status_led_config(TF_DistanceIRV2 *distance_ir_v2, uint8_t config);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Returns the configuration as set by {@link tf_distance_ir_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_status_led_config(TF_DistanceIRV2 *distance_ir_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_chip_temperature(TF_DistanceIRV2 *distance_ir_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_reset(TF_DistanceIRV2 *distance_ir_v2);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_write_uid(TF_DistanceIRV2 *distance_ir_v2, uint32_t uid);

/**
 * \ingroup BrickletDistanceIRV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_read_uid(TF_DistanceIRV2 *distance_ir_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletDistanceIRV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_distance_ir_v2_get_identity(TF_DistanceIRV2 *distance_ir_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
