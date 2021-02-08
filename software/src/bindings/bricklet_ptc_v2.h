/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_PTC_V2_H
#define TF_BRICKLET_PTC_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletPTCV2 PTC Bricklet 2.0
 */

struct TF_PTCV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_PTCV2TemperatureHandler)(struct TF_PTCV2 *device, int32_t temperature, void *user_data);
typedef void (*TF_PTCV2ResistanceHandler)(struct TF_PTCV2 *device, int32_t resistance, void *user_data);
typedef void (*TF_PTCV2SensorConnectedHandler)(struct TF_PTCV2 *device, bool connected, void *user_data);

#endif
/**
 * \ingroup BrickletPTCV2
 *
 * Reads temperatures from Pt100 und Pt1000 sensors
 */
typedef struct TF_PTCV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_PTCV2TemperatureHandler temperature_handler;
    void *temperature_user_data;

    TF_PTCV2ResistanceHandler resistance_handler;
    void *resistance_user_data;

    TF_PTCV2SensorConnectedHandler sensor_connected_handler;
    void *sensor_connected_user_data;

#endif
    uint8_t response_expected[2];
} TF_PTCV2;

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_TEMPERATURE 1

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_TEMPERATURE_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_RESISTANCE 5

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_SET_RESISTANCE_CALLBACK_CONFIGURATION 6

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_RESISTANCE_CALLBACK_CONFIGURATION 7

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_SET_NOISE_REJECTION_FILTER 9

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_NOISE_REJECTION_FILTER 10

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_IS_SENSOR_CONNECTED 11

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_SET_WIRE_MODE 12

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_WIRE_MODE 13

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_SET_MOVING_AVERAGE_CONFIGURATION 14

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_MOVING_AVERAGE_CONFIGURATION 15

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_SET_SENSOR_CONNECTED_CALLBACK_CONFIGURATION 16

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_SENSOR_CONNECTED_CALLBACK_CONFIGURATION 17

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_CALLBACK_TEMPERATURE 4

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_CALLBACK_RESISTANCE 8

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_CALLBACK_SENSOR_CONNECTED 18

#endif

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_THRESHOLD_OPTION_OFF 'x'

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_THRESHOLD_OPTION_OUTSIDE 'o'

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_THRESHOLD_OPTION_INSIDE 'i'

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_THRESHOLD_OPTION_SMALLER '<'

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_THRESHOLD_OPTION_GREATER '>'

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FILTER_OPTION_50HZ 0

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_FILTER_OPTION_60HZ 1

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_WIRE_MODE_2 2

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_WIRE_MODE_3 3

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_WIRE_MODE_4 4

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletPTCV2
 */
#define TF_PTC_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletPTCV2
 *
 * This constant is used to identify a PTC Bricklet 2.0.
 *
 * The {@link ptc_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_PTC_V2_DEVICE_IDENTIFIER 2101

/**
 * \ingroup BrickletPTCV2
 *
 * This constant represents the display name of a PTC Bricklet 2.0.
 */
#define TF_PTC_V2_DEVICE_DISPLAY_NAME "PTC Bricklet 2.0"

/**
 * \ingroup BrickletPTCV2
 *
 * Creates the device object \c ptc_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_ptc_v2_create(TF_PTCV2 *ptc_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletPTCV2
 *
 * Removes the device object \c ptc_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_ptc_v2_destroy(TF_PTCV2 *ptc_v2);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the ptc_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_response_expected(TF_PTCV2 *ptc_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletPTCV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_ptc_v2_set_response_expected(TF_PTCV2 *ptc_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletPTCV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_ptc_v2_set_response_expected_all(TF_PTCV2 *ptc_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletPTCV2
 *
 * Registers the given \c handler to the Temperature callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int32_t temperature, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_ptc_v2_set_temperature_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_ptc_v2_get_temperature}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_ptc_v2_register_temperature_callback(TF_PTCV2 *ptc_v2, TF_PTCV2TemperatureHandler handler, void *user_data);


/**
 * \ingroup BrickletPTCV2
 *
 * Registers the given \c handler to the Resistance callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int32_t resistance, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_ptc_v2_set_resistance_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_ptc_v2_get_resistance}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_ptc_v2_register_resistance_callback(TF_PTCV2 *ptc_v2, TF_PTCV2ResistanceHandler handler, void *user_data);


/**
 * \ingroup BrickletPTCV2
 *
 * Registers the given \c handler to the Sensor Connected callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(bool connected, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_ptc_v2_set_sensor_connected_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_ptc_v2_is_sensor_connected}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_ptc_v2_register_sensor_connected_callback(TF_PTCV2 *ptc_v2, TF_PTCV2SensorConnectedHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletPTCV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_ptc_v2_callback_tick(TF_PTCV2 *ptc_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the temperature of the connected sensor.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_ptc_v2_register_temperature_callback} callback. You can set the callback configuration
 * with {@link tf_ptc_v2_set_temperature_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_temperature(TF_PTCV2 *ptc_v2, int32_t *ret_temperature);

/**
 * \ingroup BrickletPTCV2
 *
 * The period is the period with which the {@link tf_ptc_v2_register_temperature_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_ptc_v2_register_temperature_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_set_temperature_callback_configuration(TF_PTCV2 *ptc_v2, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the callback configuration as set by {@link tf_ptc_v2_set_temperature_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_temperature_callback_configuration(TF_PTCV2 *ptc_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the value as measured by the MAX31865 precision delta-sigma ADC.
 * 
 * The value can be converted with the following formulas:
 * 
 * * Pt100:  resistance = (value * 390) / 32768
 * * Pt1000: resistance = (value * 3900) / 32768
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_ptc_v2_register_resistance_callback} callback. You can set the callback configuration
 * with {@link tf_ptc_v2_set_resistance_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_resistance(TF_PTCV2 *ptc_v2, int32_t *ret_resistance);

/**
 * \ingroup BrickletPTCV2
 *
 * The period is the period with which the {@link tf_ptc_v2_register_resistance_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_ptc_v2_register_resistance_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_set_resistance_callback_configuration(TF_PTCV2 *ptc_v2, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the callback configuration as set by {@link tf_ptc_v2_set_resistance_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_resistance_callback_configuration(TF_PTCV2 *ptc_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max);

/**
 * \ingroup BrickletPTCV2
 *
 * Sets the noise rejection filter to either 50Hz (0) or 60Hz (1).
 * Noise from 50Hz or 60Hz power sources (including
 * harmonics of the AC power's fundamental frequency) is
 * attenuated by 82dB.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_set_noise_rejection_filter(TF_PTCV2 *ptc_v2, uint8_t filter);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the noise rejection filter option as set by
 * {@link tf_ptc_v2_set_noise_rejection_filter}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_noise_rejection_filter(TF_PTCV2 *ptc_v2, uint8_t *ret_filter);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns *true* if the sensor is connected correctly.
 * 
 * If this function
 * returns *false*, there is either no Pt100 or Pt1000 sensor connected,
 * the sensor is connected incorrectly or the sensor itself is faulty.
 * 
 * If you want to get the status automatically, it is recommended to use the
 * {@link tf_ptc_v2_register_sensor_connected_callback} callback. You can set the callback configuration
 * with {@link tf_ptc_v2_set_sensor_connected_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_is_sensor_connected(TF_PTCV2 *ptc_v2, bool *ret_connected);

/**
 * \ingroup BrickletPTCV2
 *
 * Sets the wire mode of the sensor. Possible values are 2, 3 and 4 which
 * correspond to 2-, 3- and 4-wire sensors. The value has to match the jumper
 * configuration on the Bricklet.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_set_wire_mode(TF_PTCV2 *ptc_v2, uint8_t mode);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the wire mode as set by {@link tf_ptc_v2_set_wire_mode}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_wire_mode(TF_PTCV2 *ptc_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletPTCV2
 *
 * Sets the length of a `moving averaging <https://en.wikipedia.org/wiki/Moving_average>`__
 * for the resistance and temperature.
 * 
 * Setting the length to 1 will turn the averaging off. With less
 * averaging, there is more noise on the data.
 * 
 * New data is gathered every 20ms. With a moving average of length 1000 the resulting
 * averaging window has a length of 20s. If you want to do long term measurements the longest
 * moving average will give the cleanest results.
 * 
 * The default values match the non-changeable averaging settings of the old PTC Bricklet 1.0
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_set_moving_average_configuration(TF_PTCV2 *ptc_v2, uint16_t moving_average_length_resistance, uint16_t moving_average_length_temperature);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the moving average configuration as set by {@link tf_ptc_v2_set_moving_average_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_moving_average_configuration(TF_PTCV2 *ptc_v2, uint16_t *ret_moving_average_length_resistance, uint16_t *ret_moving_average_length_temperature);

/**
 * \ingroup BrickletPTCV2
 *
 * If you enable this callback, the {@link tf_ptc_v2_register_sensor_connected_callback} callback is triggered
 * every time a Pt sensor is connected/disconnected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_set_sensor_connected_callback_configuration(TF_PTCV2 *ptc_v2, bool enabled);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the configuration as set by {@link tf_ptc_v2_set_sensor_connected_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_sensor_connected_callback_configuration(TF_PTCV2 *ptc_v2, bool *ret_enabled);

/**
 * \ingroup BrickletPTCV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_spitfp_error_count(TF_PTCV2 *ptc_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletPTCV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_set_bootloader_mode(TF_PTCV2 *ptc_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the current bootloader mode, see {@link tf_ptc_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_bootloader_mode(TF_PTCV2 *ptc_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletPTCV2
 *
 * Sets the firmware pointer for {@link tf_ptc_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_set_write_firmware_pointer(TF_PTCV2 *ptc_v2, uint32_t pointer);

/**
 * \ingroup BrickletPTCV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_ptc_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_write_firmware(TF_PTCV2 *ptc_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletPTCV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_set_status_led_config(TF_PTCV2 *ptc_v2, uint8_t config);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the configuration as set by {@link tf_ptc_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_status_led_config(TF_PTCV2 *ptc_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_chip_temperature(TF_PTCV2 *ptc_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletPTCV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_reset(TF_PTCV2 *ptc_v2);

/**
 * \ingroup BrickletPTCV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_write_uid(TF_PTCV2 *ptc_v2, uint32_t uid);

/**
 * \ingroup BrickletPTCV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_read_uid(TF_PTCV2 *ptc_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletPTCV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_ptc_v2_get_identity(TF_PTCV2 *ptc_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
