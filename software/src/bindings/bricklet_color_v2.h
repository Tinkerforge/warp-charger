/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_COLOR_V2_H
#define TF_BRICKLET_COLOR_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletColorV2 Color Bricklet 2.0
 */

struct TF_ColorV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_ColorV2ColorHandler)(struct TF_ColorV2 *device, uint16_t r, uint16_t g, uint16_t b, uint16_t c, void *user_data);
typedef void (*TF_ColorV2IlluminanceHandler)(struct TF_ColorV2 *device, uint32_t illuminance, void *user_data);
typedef void (*TF_ColorV2ColorTemperatureHandler)(struct TF_ColorV2 *device, uint16_t color_temperature, void *user_data);

#endif
/**
 * \ingroup BrickletColorV2
 *
 * Measures color (RGB value), illuminance and color temperature
 */
typedef struct TF_ColorV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_ColorV2ColorHandler color_handler;
    void *color_user_data;

    TF_ColorV2IlluminanceHandler illuminance_handler;
    void *illuminance_user_data;

    TF_ColorV2ColorTemperatureHandler color_temperature_handler;
    void *color_temperature_user_data;

#endif
    uint8_t response_expected[2];
} TF_ColorV2;

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_COLOR 1

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_SET_COLOR_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_COLOR_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_ILLUMINANCE 5

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_SET_ILLUMINANCE_CALLBACK_CONFIGURATION 6

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_ILLUMINANCE_CALLBACK_CONFIGURATION 7

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_COLOR_TEMPERATURE 9

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_SET_COLOR_TEMPERATURE_CALLBACK_CONFIGURATION 10

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_COLOR_TEMPERATURE_CALLBACK_CONFIGURATION 11

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_SET_LIGHT 13

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_LIGHT 14

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_SET_CONFIGURATION 15

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_CONFIGURATION 16

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_CALLBACK_COLOR 4

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_CALLBACK_ILLUMINANCE 8

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_CALLBACK_COLOR_TEMPERATURE 12

#endif

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_THRESHOLD_OPTION_OFF 'x'

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_THRESHOLD_OPTION_OUTSIDE 'o'

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_THRESHOLD_OPTION_INSIDE 'i'

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_THRESHOLD_OPTION_SMALLER '<'

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_THRESHOLD_OPTION_GREATER '>'

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_GAIN_1X 0

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_GAIN_4X 1

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_GAIN_16X 2

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_GAIN_60X 3

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_INTEGRATION_TIME_2MS 0

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_INTEGRATION_TIME_24MS 1

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_INTEGRATION_TIME_101MS 2

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_INTEGRATION_TIME_154MS 3

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_INTEGRATION_TIME_700MS 4

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletColorV2
 */
#define TF_COLOR_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletColorV2
 *
 * This constant is used to identify a Color Bricklet 2.0.
 *
 * The {@link color_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_COLOR_V2_DEVICE_IDENTIFIER 2128

/**
 * \ingroup BrickletColorV2
 *
 * This constant represents the display name of a Color Bricklet 2.0.
 */
#define TF_COLOR_V2_DEVICE_DISPLAY_NAME "Color Bricklet 2.0"

/**
 * \ingroup BrickletColorV2
 *
 * Creates the device object \c color_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_color_v2_create(TF_ColorV2 *color_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletColorV2
 *
 * Removes the device object \c color_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_color_v2_destroy(TF_ColorV2 *color_v2);

/**
 * \ingroup BrickletColorV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the color_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_response_expected(TF_ColorV2 *color_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletColorV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_color_v2_set_response_expected(TF_ColorV2 *color_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletColorV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_color_v2_set_response_expected_all(TF_ColorV2 *color_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletColorV2
 *
 * Registers the given \c handler to the Color callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t r, uint16_t g, uint16_t b, uint16_t c, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_color_v2_set_color_callback_configuration}. The parameter is the color
 * of the sensor as RGBC.
 * 
 * The {@link tf_color_v2_register_color_callback} callback is only triggered if the color has changed since the
 * last triggering.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_color_v2_register_color_callback(TF_ColorV2 *color_v2, TF_ColorV2ColorHandler handler, void *user_data);


/**
 * \ingroup BrickletColorV2
 *
 * Registers the given \c handler to the Illuminance callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint32_t illuminance, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_color_v2_set_illuminance_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_color_v2_get_illuminance}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_color_v2_register_illuminance_callback(TF_ColorV2 *color_v2, TF_ColorV2IlluminanceHandler handler, void *user_data);


/**
 * \ingroup BrickletColorV2
 *
 * Registers the given \c handler to the Color Temperature callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t color_temperature, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_color_v2_set_color_temperature_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_color_v2_get_color_temperature}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_color_v2_register_color_temperature_callback(TF_ColorV2 *color_v2, TF_ColorV2ColorTemperatureHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletColorV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_color_v2_callback_tick(TF_ColorV2 *color_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletColorV2
 *
 * Returns the measured color of the sensor.
 * 
 * The red (r), green (g), blue (b) and clear (c) colors are measured
 * with four different photodiodes that are responsive at different
 * wavelengths:
 * 
 * .. image:: /Images/Bricklets/bricklet_color_wavelength_chart_600.jpg
 *    :scale: 100 %
 *    :alt: Chart Responsivity / Wavelength
 *    :align: center
 *    :target: ../../_images/Bricklets/bricklet_color_wavelength_chart_600.jpg
 * 
 * If you want to get the color periodically, it is recommended
 * to use the {@link tf_color_v2_register_color_callback} callback and set the period with
 * {@link tf_color_v2_set_color_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_color(TF_ColorV2 *color_v2, uint16_t *ret_r, uint16_t *ret_g, uint16_t *ret_b, uint16_t *ret_c);

/**
 * \ingroup BrickletColorV2
 *
 * The period is the period with which the {@link tf_color_v2_register_color_callback}
 * callback is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_set_color_callback_configuration(TF_ColorV2 *color_v2, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletColorV2
 *
 * Returns the callback configuration as set by
 * {@link tf_color_v2_set_color_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_color_callback_configuration(TF_ColorV2 *color_v2, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletColorV2
 *
 * Returns the illuminance affected by the gain and integration time as
 * set by {@link tf_color_v2_set_configuration}. To get the illuminance in Lux apply this formula::
 * 
 *  lux = illuminance * 700 / gain / integration_time
 * 
 * To get a correct illuminance measurement make sure that the color
 * values themselves are not saturated. The color value (R, G or B)
 * is saturated if it is equal to the maximum value of 65535.
 * In that case you have to reduce the gain, see {@link tf_color_v2_set_configuration}.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_color_v2_register_illuminance_callback} callback. You can set the callback configuration
 * with {@link tf_color_v2_set_illuminance_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_illuminance(TF_ColorV2 *color_v2, uint32_t *ret_illuminance);

/**
 * \ingroup BrickletColorV2
 *
 * The period is the period with which the {@link tf_color_v2_register_illuminance_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_color_v2_register_illuminance_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_set_illuminance_callback_configuration(TF_ColorV2 *color_v2, uint32_t period, bool value_has_to_change, char option, uint32_t min, uint32_t max);

/**
 * \ingroup BrickletColorV2
 *
 * Returns the callback configuration as set by {@link tf_color_v2_set_illuminance_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_illuminance_callback_configuration(TF_ColorV2 *color_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, uint32_t *ret_min, uint32_t *ret_max);

/**
 * \ingroup BrickletColorV2
 *
 * Returns the color temperature.
 * 
 * To get a correct color temperature measurement make sure that the color
 * values themselves are not saturated. The color value (R, G or B)
 * is saturated if it is equal to the maximum value of 65535.
 * In that case you have to reduce the gain, see {@link tf_color_v2_set_configuration}.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_color_v2_register_color_temperature_callback} callback. You can set the callback configuration
 * with {@link tf_color_v2_set_color_temperature_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_color_temperature(TF_ColorV2 *color_v2, uint16_t *ret_color_temperature);

/**
 * \ingroup BrickletColorV2
 *
 * The period is the period with which the {@link tf_color_v2_register_color_temperature_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_color_v2_register_color_temperature_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_set_color_temperature_callback_configuration(TF_ColorV2 *color_v2, uint32_t period, bool value_has_to_change, char option, uint16_t min, uint16_t max);

/**
 * \ingroup BrickletColorV2
 *
 * Returns the callback configuration as set by {@link tf_color_v2_set_color_temperature_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_color_temperature_callback_configuration(TF_ColorV2 *color_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);

/**
 * \ingroup BrickletColorV2
 *
 * Turns the white LED on the Bricklet on/off.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_set_light(TF_ColorV2 *color_v2, bool enable);

/**
 * \ingroup BrickletColorV2
 *
 * Returns the value as set by {@link tf_color_v2_set_light}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_light(TF_ColorV2 *color_v2, bool *ret_enable);

/**
 * \ingroup BrickletColorV2
 *
 * Sets the configuration of the sensor. Gain and integration time
 * can be configured this way.
 * 
 * For configuring the gain:
 * 
 * * 0: 1x Gain
 * * 1: 4x Gain
 * * 2: 16x Gain
 * * 3: 60x Gain
 * 
 * For configuring the integration time:
 * 
 * * 0: 2.4ms
 * * 1: 24ms
 * * 2: 101ms
 * * 3: 154ms
 * * 4: 700ms
 * 
 * Increasing the gain enables the sensor to detect a
 * color from a higher distance.
 * 
 * The integration time provides a trade-off between conversion time
 * and accuracy. With a longer integration time the values read will
 * be more accurate but it will take longer to get the conversion
 * results.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_set_configuration(TF_ColorV2 *color_v2, uint8_t gain, uint8_t integration_time);

/**
 * \ingroup BrickletColorV2
 *
 * Returns the configuration as set by {@link tf_color_v2_set_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_configuration(TF_ColorV2 *color_v2, uint8_t *ret_gain, uint8_t *ret_integration_time);

/**
 * \ingroup BrickletColorV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_spitfp_error_count(TF_ColorV2 *color_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletColorV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_set_bootloader_mode(TF_ColorV2 *color_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletColorV2
 *
 * Returns the current bootloader mode, see {@link tf_color_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_bootloader_mode(TF_ColorV2 *color_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletColorV2
 *
 * Sets the firmware pointer for {@link tf_color_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_set_write_firmware_pointer(TF_ColorV2 *color_v2, uint32_t pointer);

/**
 * \ingroup BrickletColorV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_color_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_write_firmware(TF_ColorV2 *color_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletColorV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_set_status_led_config(TF_ColorV2 *color_v2, uint8_t config);

/**
 * \ingroup BrickletColorV2
 *
 * Returns the configuration as set by {@link tf_color_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_status_led_config(TF_ColorV2 *color_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletColorV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_chip_temperature(TF_ColorV2 *color_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletColorV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_reset(TF_ColorV2 *color_v2);

/**
 * \ingroup BrickletColorV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_write_uid(TF_ColorV2 *color_v2, uint32_t uid);

/**
 * \ingroup BrickletColorV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_read_uid(TF_ColorV2 *color_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletColorV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_color_v2_get_identity(TF_ColorV2 *color_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
