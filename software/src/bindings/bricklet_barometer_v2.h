/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_BAROMETER_V2_H
#define TF_BRICKLET_BAROMETER_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletBarometerV2 Barometer Bricklet 2.0
 */

struct TF_BarometerV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_BarometerV2AirPressureHandler)(struct TF_BarometerV2 *device, int32_t air_pressure, void *user_data);
typedef void (*TF_BarometerV2AltitudeHandler)(struct TF_BarometerV2 *device, int32_t altitude, void *user_data);
typedef void (*TF_BarometerV2TemperatureHandler)(struct TF_BarometerV2 *device, int32_t temperature, void *user_data);

#endif
/**
 * \ingroup BrickletBarometerV2
 *
 * Measures air pressure and altitude changes
 */
typedef struct TF_BarometerV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_BarometerV2AirPressureHandler air_pressure_handler;
    void *air_pressure_user_data;

    TF_BarometerV2AltitudeHandler altitude_handler;
    void *altitude_user_data;

    TF_BarometerV2TemperatureHandler temperature_handler;
    void *temperature_user_data;

#endif
    uint8_t response_expected[2];
} TF_BarometerV2;

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_AIR_PRESSURE 1

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_SET_AIR_PRESSURE_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_AIR_PRESSURE_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_ALTITUDE 5

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_SET_ALTITUDE_CALLBACK_CONFIGURATION 6

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_ALTITUDE_CALLBACK_CONFIGURATION 7

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_TEMPERATURE 9

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION 10

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_TEMPERATURE_CALLBACK_CONFIGURATION 11

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_SET_MOVING_AVERAGE_CONFIGURATION 13

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_MOVING_AVERAGE_CONFIGURATION 14

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_SET_REFERENCE_AIR_PRESSURE 15

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_REFERENCE_AIR_PRESSURE 16

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_SET_CALIBRATION 17

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_CALIBRATION 18

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_SET_SENSOR_CONFIGURATION 19

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_SENSOR_CONFIGURATION 20

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_CALLBACK_AIR_PRESSURE 4

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_CALLBACK_ALTITUDE 8

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_CALLBACK_TEMPERATURE 12

#endif

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_THRESHOLD_OPTION_OFF 'x'

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_THRESHOLD_OPTION_OUTSIDE 'o'

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_THRESHOLD_OPTION_INSIDE 'i'

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_THRESHOLD_OPTION_SMALLER '<'

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_THRESHOLD_OPTION_GREATER '>'

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_DATA_RATE_OFF 0

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_DATA_RATE_1HZ 1

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_DATA_RATE_10HZ 2

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_DATA_RATE_25HZ 3

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_DATA_RATE_50HZ 4

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_DATA_RATE_75HZ 5

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_LOW_PASS_FILTER_OFF 0

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_LOW_PASS_FILTER_1_9TH 1

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_LOW_PASS_FILTER_1_20TH 2

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletBarometerV2
 */
#define TF_BAROMETER_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletBarometerV2
 *
 * This constant is used to identify a Barometer Bricklet 2.0.
 *
 * The {@link barometer_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_BAROMETER_V2_DEVICE_IDENTIFIER 2117

/**
 * \ingroup BrickletBarometerV2
 *
 * This constant represents the display name of a Barometer Bricklet 2.0.
 */
#define TF_BAROMETER_V2_DEVICE_DISPLAY_NAME "Barometer Bricklet 2.0"

/**
 * \ingroup BrickletBarometerV2
 *
 * Creates the device object \c barometer_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_barometer_v2_create(TF_BarometerV2 *barometer_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletBarometerV2
 *
 * Removes the device object \c barometer_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_barometer_v2_destroy(TF_BarometerV2 *barometer_v2);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the barometer_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_response_expected(TF_BarometerV2 *barometer_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletBarometerV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_barometer_v2_set_response_expected(TF_BarometerV2 *barometer_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletBarometerV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_barometer_v2_set_response_expected_all(TF_BarometerV2 *barometer_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletBarometerV2
 *
 * Registers the given \c handler to the Air Pressure callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int32_t air_pressure, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_barometer_v2_set_air_pressure_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_barometer_v2_get_air_pressure}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_barometer_v2_register_air_pressure_callback(TF_BarometerV2 *barometer_v2, TF_BarometerV2AirPressureHandler handler, void *user_data);


/**
 * \ingroup BrickletBarometerV2
 *
 * Registers the given \c handler to the Altitude callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int32_t altitude, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_barometer_v2_set_altitude_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_barometer_v2_get_altitude}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_barometer_v2_register_altitude_callback(TF_BarometerV2 *barometer_v2, TF_BarometerV2AltitudeHandler handler, void *user_data);


/**
 * \ingroup BrickletBarometerV2
 *
 * Registers the given \c handler to the Temperature callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int32_t temperature, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_barometer_v2_set_temperature_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_barometer_v2_get_temperature}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_barometer_v2_register_temperature_callback(TF_BarometerV2 *barometer_v2, TF_BarometerV2TemperatureHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletBarometerV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_barometer_v2_callback_tick(TF_BarometerV2 *barometer_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the measured air pressure.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_barometer_v2_register_air_pressure_callback} callback. You can set the callback configuration
 * with {@link tf_barometer_v2_set_air_pressure_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_air_pressure(TF_BarometerV2 *barometer_v2, int32_t *ret_air_pressure);

/**
 * \ingroup BrickletBarometerV2
 *
 * The period is the period with which the {@link tf_barometer_v2_register_air_pressure_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_barometer_v2_register_air_pressure_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_set_air_pressure_callback_configuration(TF_BarometerV2 *barometer_v2, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the callback configuration as set by {@link tf_barometer_v2_set_air_pressure_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_air_pressure_callback_configuration(TF_BarometerV2 *barometer_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the relative altitude of the air pressure sensor. The value
 * is calculated based on the difference between the
 * current air pressure and the reference air pressure that can be set
 * with {@link tf_barometer_v2_set_reference_air_pressure}.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_barometer_v2_register_altitude_callback} callback. You can set the callback configuration
 * with {@link tf_barometer_v2_set_altitude_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_altitude(TF_BarometerV2 *barometer_v2, int32_t *ret_altitude);

/**
 * \ingroup BrickletBarometerV2
 *
 * The period is the period with which the {@link tf_barometer_v2_register_altitude_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_barometer_v2_register_altitude_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_set_altitude_callback_configuration(TF_BarometerV2 *barometer_v2, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the callback configuration as set by {@link tf_barometer_v2_set_altitude_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_altitude_callback_configuration(TF_BarometerV2 *barometer_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the temperature of the air pressure sensor.
 * 
 * This temperature is used internally for temperature compensation
 * of the air pressure measurement. It is not as accurate as the
 * temperature measured by the :ref:`temperature_v2_bricklet` or the
 * :ref:`temperature_ir_v2_bricklet`.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_barometer_v2_register_temperature_callback} callback. You can set the callback configuration
 * with {@link tf_barometer_v2_set_temperature_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_temperature(TF_BarometerV2 *barometer_v2, int32_t *ret_temperature);

/**
 * \ingroup BrickletBarometerV2
 *
 * The period is the period with which the {@link tf_barometer_v2_register_temperature_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_barometer_v2_register_temperature_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_set_temperature_callback_configuration(TF_BarometerV2 *barometer_v2, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the callback configuration as set by {@link tf_barometer_v2_set_temperature_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_temperature_callback_configuration(TF_BarometerV2 *barometer_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max);

/**
 * \ingroup BrickletBarometerV2
 *
 * Sets the length of a `moving averaging <https://en.wikipedia.org/wiki/Moving_average>`__
 * for the air pressure and temperature measurements.
 * 
 * Setting the length to 1 will turn the averaging off. With less
 * averaging, there is more noise on the data.
 * 
 * If you want to do long term measurements the longest moving average will give
 * the cleanest results.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_set_moving_average_configuration(TF_BarometerV2 *barometer_v2, uint16_t moving_average_length_air_pressure, uint16_t moving_average_length_temperature);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the moving average configuration as set by
 * {@link tf_barometer_v2_set_moving_average_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_moving_average_configuration(TF_BarometerV2 *barometer_v2, uint16_t *ret_moving_average_length_air_pressure, uint16_t *ret_moving_average_length_temperature);

/**
 * \ingroup BrickletBarometerV2
 *
 * Sets the reference air pressure for the altitude calculation.
 * Setting the reference to the
 * current air pressure results in a calculated altitude of 0mm. Passing 0 is
 * a shortcut for passing the current air pressure as reference.
 * 
 * Well known reference values are the Q codes
 * `QNH <https://en.wikipedia.org/wiki/QNH>`__ and
 * `QFE <https://en.wikipedia.org/wiki/Mean_sea_level_pressure#Mean_sea_level_pressure>`__
 * used in aviation.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_set_reference_air_pressure(TF_BarometerV2 *barometer_v2, int32_t air_pressure);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the reference air pressure as set by {@link tf_barometer_v2_set_reference_air_pressure}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_reference_air_pressure(TF_BarometerV2 *barometer_v2, int32_t *ret_air_pressure);

/**
 * \ingroup BrickletBarometerV2
 *
 * Sets the one point calibration (OPC) values for the air pressure measurement.
 * 
 * Before the Bricklet can be calibrated any previous calibration has to be removed
 * by setting ``measured air pressure`` and ``actual air pressure`` to 0.
 * 
 * Then the current air pressure has to be measured using the Bricklet
 * (``measured air pressure``) and with an accurate reference barometer
 * (``actual air pressure``) at the same time and passed to this function.
 * 
 * After proper calibration the air pressure measurement can achieve an accuracy
 * up to 0.2 hPa.
 * 
 * The calibration is saved in the EEPROM of the Bricklet and only needs to be
 * configured once.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_set_calibration(TF_BarometerV2 *barometer_v2, int32_t measured_air_pressure, int32_t actual_air_pressure);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the air pressure one point calibration values as set by
 * {@link tf_barometer_v2_set_calibration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_calibration(TF_BarometerV2 *barometer_v2, int32_t *ret_measured_air_pressure, int32_t *ret_actual_air_pressure);

/**
 * \ingroup BrickletBarometerV2
 *
 * Configures the data rate and air pressure low pass filter. The low pass filter
 * cut-off frequency (if enabled) can be set to 1/9th or 1/20th of the configure
 * data rate to decrease the noise on the air pressure data.
 * 
 * The low pass filter configuration only applies to the air pressure measurement.
 * There is no low pass filter for the temperature measurement.
 * 
 * A higher data rate will result in a less precise temperature because of
 * self-heating of the sensor. If the accuracy of the temperature reading is
 * important to you, we would recommend the 1Hz data rate.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_set_sensor_configuration(TF_BarometerV2 *barometer_v2, uint8_t data_rate, uint8_t air_pressure_low_pass_filter);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the sensor configuration as set by {@link tf_barometer_v2_set_sensor_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_sensor_configuration(TF_BarometerV2 *barometer_v2, uint8_t *ret_data_rate, uint8_t *ret_air_pressure_low_pass_filter);

/**
 * \ingroup BrickletBarometerV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_spitfp_error_count(TF_BarometerV2 *barometer_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletBarometerV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_set_bootloader_mode(TF_BarometerV2 *barometer_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the current bootloader mode, see {@link tf_barometer_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_bootloader_mode(TF_BarometerV2 *barometer_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletBarometerV2
 *
 * Sets the firmware pointer for {@link tf_barometer_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_set_write_firmware_pointer(TF_BarometerV2 *barometer_v2, uint32_t pointer);

/**
 * \ingroup BrickletBarometerV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_barometer_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_write_firmware(TF_BarometerV2 *barometer_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletBarometerV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_set_status_led_config(TF_BarometerV2 *barometer_v2, uint8_t config);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the configuration as set by {@link tf_barometer_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_status_led_config(TF_BarometerV2 *barometer_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_chip_temperature(TF_BarometerV2 *barometer_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletBarometerV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_reset(TF_BarometerV2 *barometer_v2);

/**
 * \ingroup BrickletBarometerV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_write_uid(TF_BarometerV2 *barometer_v2, uint32_t uid);

/**
 * \ingroup BrickletBarometerV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_read_uid(TF_BarometerV2 *barometer_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletBarometerV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_barometer_v2_get_identity(TF_BarometerV2 *barometer_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
