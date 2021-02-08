/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_INDUSTRIAL_DUAL_ANALOG_IN_V2_H
#define TF_BRICKLET_INDUSTRIAL_DUAL_ANALOG_IN_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletIndustrialDualAnalogInV2 Industrial Dual Analog In Bricklet 2.0
 */

struct TF_IndustrialDualAnalogInV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_IndustrialDualAnalogInV2VoltageHandler)(struct TF_IndustrialDualAnalogInV2 *device, uint8_t channel, int32_t voltage, void *user_data);
typedef void (*TF_IndustrialDualAnalogInV2AllVoltagesHandler)(struct TF_IndustrialDualAnalogInV2 *device, int32_t voltages[2], void *user_data);

#endif
/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Measures two DC voltages between -35V and +35V with 24bit resolution each
 */
typedef struct TF_IndustrialDualAnalogInV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_IndustrialDualAnalogInV2VoltageHandler voltage_handler;
    void *voltage_user_data;

    TF_IndustrialDualAnalogInV2AllVoltagesHandler all_voltages_handler;
    void *all_voltages_user_data;

#endif
    uint8_t response_expected[2];
} TF_IndustrialDualAnalogInV2;

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_VOLTAGE 1

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_VOLTAGE_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_VOLTAGE_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_SAMPLE_RATE 5

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_SAMPLE_RATE 6

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CALIBRATION 7

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_CALIBRATION 8

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_ADC_VALUES 9

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CHANNEL_LED_CONFIG 10

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_CHANNEL_LED_CONFIG 11

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CHANNEL_LED_STATUS_CONFIG 12

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_CHANNEL_LED_STATUS_CONFIG 13

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_ALL_VOLTAGES 14

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_ALL_VOLTAGES_CALLBACK_CONFIGURATION 15

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_ALL_VOLTAGES_CALLBACK_CONFIGURATION 16

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_CALLBACK_VOLTAGE 4

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_CALLBACK_ALL_VOLTAGES 17

#endif

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_THRESHOLD_OPTION_OFF 'x'

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_THRESHOLD_OPTION_OUTSIDE 'o'

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_THRESHOLD_OPTION_INSIDE 'i'

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_THRESHOLD_OPTION_SMALLER '<'

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_THRESHOLD_OPTION_GREATER '>'

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_976_SPS 0

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_488_SPS 1

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_244_SPS 2

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_122_SPS 3

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_61_SPS 4

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_4_SPS 5

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_2_SPS 6

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_1_SPS 7

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_ON 1

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_SHOW_CHANNEL_STATUS 3

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_STATUS_CONFIG_THRESHOLD 0

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_STATUS_CONFIG_INTENSITY 1

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * This constant is used to identify a Industrial Dual Analog In Bricklet 2.0.
 *
 * The {@link industrial_dual_analog_in_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_DEVICE_IDENTIFIER 2121

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * This constant represents the display name of a Industrial Dual Analog In Bricklet 2.0.
 */
#define TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_DEVICE_DISPLAY_NAME "Industrial Dual Analog In Bricklet 2.0"

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Creates the device object \c industrial_dual_analog_in_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_industrial_dual_analog_in_v2_create(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Removes the device object \c industrial_dual_analog_in_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_industrial_dual_analog_in_v2_destroy(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the industrial_dual_analog_in_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_response_expected(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_industrial_dual_analog_in_v2_set_response_expected(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_industrial_dual_analog_in_v2_set_response_expected_all(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Registers the given \c handler to the Voltage callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t channel, int32_t voltage, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_industrial_dual_analog_in_v2_set_voltage_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_industrial_dual_analog_in_v2_get_voltage}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_industrial_dual_analog_in_v2_register_voltage_callback(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, TF_IndustrialDualAnalogInV2VoltageHandler handler, void *user_data);


/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Registers the given \c handler to the All Voltages callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int32_t voltages[2], void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_industrial_dual_analog_in_v2_set_all_voltages_callback_configuration}.
 * 
 * The parameters are the same as {@link tf_industrial_dual_analog_in_v2_get_all_voltages}.
 * 
 * .. versionadded:: 2.0.6$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) void tf_industrial_dual_analog_in_v2_register_all_voltages_callback(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, TF_IndustrialDualAnalogInV2AllVoltagesHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_industrial_dual_analog_in_v2_callback_tick(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the voltage for the given channel.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_industrial_dual_analog_in_v2_register_voltage_callback} callback. You can set the callback configuration
 * with {@link tf_industrial_dual_analog_in_v2_set_voltage_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_voltage(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, int32_t *ret_voltage);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * The period is the period with which the {@link tf_industrial_dual_analog_in_v2_register_voltage_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_industrial_dual_analog_in_v2_register_voltage_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_set_voltage_callback_configuration(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the callback configuration as set by {@link tf_industrial_dual_analog_in_v2_set_voltage_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_voltage_callback_configuration(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Sets the sample rate. The sample rate can be between 1 sample per second
 * and 976 samples per second. Decreasing the sample rate will also decrease the
 * noise on the data.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_set_sample_rate(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t rate);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the sample rate as set by {@link tf_industrial_dual_analog_in_v2_set_sample_rate}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_sample_rate(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t *ret_rate);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Sets offset and gain of MCP3911 internal calibration registers.
 * 
 * See MCP3911 datasheet 7.7 and 7.8. The Industrial Dual Analog In Bricklet 2.0
 * is already factory calibrated by Tinkerforge. It should not be necessary
 * for you to use this function
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_set_calibration(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, int32_t offset[2], int32_t gain[2]);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the calibration as set by {@link tf_industrial_dual_analog_in_v2_set_calibration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_calibration(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, int32_t ret_offset[2], int32_t ret_gain[2]);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the ADC values as given by the MCP3911 IC. This function
 * is needed for proper calibration, see {@link tf_industrial_dual_analog_in_v2_set_calibration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_adc_values(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, int32_t ret_value[2]);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Each channel has a corresponding LED. You can turn the LED off, on or show a
 * heartbeat. You can also set the LED to "Channel Status". In this mode the
 * LED can either be turned on with a pre-defined threshold or the intensity
 * of the LED can change with the measured value.
 * 
 * You can configure the channel status behavior with {@link tf_industrial_dual_analog_in_v2_set_channel_led_status_config}.
 * 
 * By default all channel LEDs are configured as "Channel Status".
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_set_channel_led_config(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, uint8_t config);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the channel LED configuration as set by {@link tf_industrial_dual_analog_in_v2_set_channel_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_channel_led_config(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, uint8_t *ret_config);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Sets the channel LED status config. This config is used if the channel LED is
 * configured as "Channel Status", see {@link tf_industrial_dual_analog_in_v2_set_channel_led_config}.
 * 
 * For each channel you can choose between threshold and intensity mode.
 * 
 * In threshold mode you can define a positive or a negative threshold.
 * For a positive threshold set the "min" parameter to the threshold value in mV
 * above which the LED should turn on and set the "max" parameter to 0. Example:
 * If you set a positive threshold of 10V, the LED will turn on as soon as the
 * voltage exceeds 10V and turn off again if it goes below 10V.
 * For a negative threshold set the "max" parameter to the threshold value in mV
 * below which the LED should turn on and set the "min" parameter to 0. Example:
 * If you set a negative threshold of 10V, the LED will turn on as soon as the
 * voltage goes below 10V and the LED will turn off when the voltage exceeds 10V.
 * 
 * In intensity mode you can define a range in mV that is used to scale the brightness
 * of the LED. Example with min=4V, max=20V: The LED is off at 4V, on at 20V
 * and the brightness is linearly scaled between the values 4V and 20V. If the
 * min value is greater than the max value, the LED brightness is scaled the other
 * way around.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_set_channel_led_status_config(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, int32_t min, int32_t max, uint8_t config);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the channel LED status configuration as set by
 * {@link tf_industrial_dual_analog_in_v2_set_channel_led_status_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_channel_led_status_config(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, int32_t *ret_min, int32_t *ret_max, uint8_t *ret_config);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the voltages for all channels.
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_industrial_dual_analog_in_v2_register_all_voltages_callback} callback. You can set the callback configuration
 * with {@link tf_industrial_dual_analog_in_v2_set_all_voltages_callback_configuration}.
 * 
 * .. versionadded:: 2.0.6$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_all_voltages(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, int32_t ret_voltages[2]);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * The period is the period with which the {@link tf_industrial_dual_analog_in_v2_register_all_voltages_callback}
 * callback is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after at least one of the values has changed. If the values didn't
 * change within the period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 * 
 * .. versionadded:: 2.0.6$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_set_all_voltages_callback_configuration(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the callback configuration as set by
 * {@link tf_industrial_dual_analog_in_v2_set_all_voltages_callback_configuration}.
 * 
 * .. versionadded:: 2.0.6$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_all_voltages_callback_configuration(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_spitfp_error_count(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_set_bootloader_mode(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the current bootloader mode, see {@link tf_industrial_dual_analog_in_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_bootloader_mode(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Sets the firmware pointer for {@link tf_industrial_dual_analog_in_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_set_write_firmware_pointer(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t pointer);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_industrial_dual_analog_in_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_write_firmware(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_set_status_led_config(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t config);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the configuration as set by {@link tf_industrial_dual_analog_in_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_status_led_config(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_chip_temperature(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_reset(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_write_uid(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t uid);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_read_uid(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletIndustrialDualAnalogInV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_analog_in_v2_get_identity(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
