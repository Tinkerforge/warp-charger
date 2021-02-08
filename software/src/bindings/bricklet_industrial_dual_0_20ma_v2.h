/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_INDUSTRIAL_DUAL_0_20MA_V2_H
#define TF_BRICKLET_INDUSTRIAL_DUAL_0_20MA_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletIndustrialDual020mAV2 Industrial Dual 0-20mA Bricklet 2.0
 */

struct TF_IndustrialDual020mAV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_IndustrialDual020mAV2CurrentHandler)(struct TF_IndustrialDual020mAV2 *device, uint8_t channel, int32_t current, void *user_data);

#endif
/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Measures two DC currents between 0mA and 20mA (IEC 60381-1)
 */
typedef struct TF_IndustrialDual020mAV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_IndustrialDual020mAV2CurrentHandler current_handler;
    void *current_user_data;

#endif
    uint8_t response_expected[2];
} TF_IndustrialDual020mAV2;

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_GET_CURRENT 1

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_SET_CURRENT_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_GET_CURRENT_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_SET_SAMPLE_RATE 5

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_GET_SAMPLE_RATE 6

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_SET_GAIN 7

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_GET_GAIN 8

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_SET_CHANNEL_LED_CONFIG 9

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_GET_CHANNEL_LED_CONFIG 10

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_SET_CHANNEL_LED_STATUS_CONFIG 11

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_GET_CHANNEL_LED_STATUS_CONFIG 12

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_CALLBACK_CURRENT 4

#endif

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_THRESHOLD_OPTION_OFF 'x'

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_THRESHOLD_OPTION_OUTSIDE 'o'

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_THRESHOLD_OPTION_INSIDE 'i'

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_THRESHOLD_OPTION_SMALLER '<'

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_THRESHOLD_OPTION_GREATER '>'

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_SAMPLE_RATE_240_SPS 0

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_SAMPLE_RATE_60_SPS 1

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_SAMPLE_RATE_15_SPS 2

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_SAMPLE_RATE_4_SPS 3

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_GAIN_1X 0

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_GAIN_2X 1

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_GAIN_4X 2

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_GAIN_8X 3

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_CHANNEL_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_CHANNEL_LED_CONFIG_ON 1

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_CHANNEL_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_CHANNEL_LED_CONFIG_SHOW_CHANNEL_STATUS 3

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_CHANNEL_LED_STATUS_CONFIG_THRESHOLD 0

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_CHANNEL_LED_STATUS_CONFIG_INTENSITY 1

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletIndustrialDual020mAV2
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * This constant is used to identify a Industrial Dual 0-20mA Bricklet 2.0.
 *
 * The {@link industrial_dual_0_20ma_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_DEVICE_IDENTIFIER 2120

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * This constant represents the display name of a Industrial Dual 0-20mA Bricklet 2.0.
 */
#define TF_INDUSTRIAL_DUAL_0_20MA_V2_DEVICE_DISPLAY_NAME "Industrial Dual 0-20mA Bricklet 2.0"

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Creates the device object \c industrial_dual_0_20ma_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_industrial_dual_0_20ma_v2_create(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Removes the device object \c industrial_dual_0_20ma_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_industrial_dual_0_20ma_v2_destroy(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the industrial_dual_0_20ma_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_get_response_expected(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletIndustrialDual020mAV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_industrial_dual_0_20ma_v2_set_response_expected(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_industrial_dual_0_20ma_v2_set_response_expected_all(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Registers the given \c handler to the Current callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t channel, int32_t current, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_industrial_dual_0_20ma_v2_set_current_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_industrial_dual_0_20ma_v2_get_current}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_industrial_dual_0_20ma_v2_register_current_callback(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, TF_IndustrialDual020mAV2CurrentHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_industrial_dual_0_20ma_v2_callback_tick(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Returns the current of the specified channel.
 * 
 * It is possible to detect if an IEC 60381-1 compatible sensor is connected
 * and if it works probably.
 * 
 * If the returned current is below 4mA, there is likely no sensor connected
 * or the connected sensor is defective. If the returned current is over 20mA,
 * there might be a short circuit or the sensor is defective.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_industrial_dual_0_20ma_v2_register_current_callback} callback. You can set the callback configuration
 * with {@link tf_industrial_dual_0_20ma_v2_set_current_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_get_current(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t channel, int32_t *ret_current);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * The period is the period with which the {@link tf_industrial_dual_0_20ma_v2_register_current_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_industrial_dual_0_20ma_v2_register_current_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_set_current_callback_configuration(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t channel, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Returns the callback configuration as set by {@link tf_industrial_dual_0_20ma_v2_set_current_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_get_current_callback_configuration(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t channel, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Sets the sample rate to either 240, 60, 15 or 4 samples per second.
 * The resolution for the rates is 12, 14, 16 and 18 bit respectively.
 * 
 * \verbatim
 *  "Value", "Description"
 * 
 *  "0",    "240 samples per second, 12 bit resolution"
 *  "1",    "60 samples per second, 14 bit resolution"
 *  "2",    "15 samples per second, 16 bit resolution"
 *  "3",    "4 samples per second, 18 bit resolution"
 * \endverbatim
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_set_sample_rate(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t rate);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Returns the sample rate as set by {@link tf_industrial_dual_0_20ma_v2_set_sample_rate}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_get_sample_rate(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t *ret_rate);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Sets a gain between 1x and 8x. If you want to measure a very small current,
 * you can increase the gain to get some more resolution.
 * 
 * Example: If you measure 0.5mA with a gain of 8x the return value will be
 * 4mA.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_set_gain(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t gain);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Returns the gain as set by {@link tf_industrial_dual_0_20ma_v2_set_gain}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_get_gain(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t *ret_gain);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Each channel has a corresponding LED. You can turn the LED off, on or show a
 * heartbeat. You can also set the LED to "Channel Status". In this mode the
 * LED can either be turned on with a pre-defined threshold or the intensity
 * of the LED can change with the measured value.
 * 
 * You can configure the channel status behavior with {@link tf_industrial_dual_0_20ma_v2_set_channel_led_status_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_set_channel_led_config(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t channel, uint8_t config);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Returns the channel LED configuration as set by {@link tf_industrial_dual_0_20ma_v2_set_channel_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_get_channel_led_config(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t channel, uint8_t *ret_config);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Sets the channel LED status config. This config is used if the channel LED is
 * configured as "Channel Status", see {@link tf_industrial_dual_0_20ma_v2_set_channel_led_config}.
 * 
 * For each channel you can choose between threshold and intensity mode.
 * 
 * In threshold mode you can define a positive or a negative threshold.
 * For a positive threshold set the "min" parameter to the threshold value in nA
 * above which the LED should turn on and set the "max" parameter to 0. Example:
 * If you set a positive threshold of 10mA, the LED will turn on as soon as the
 * current exceeds 10mA and turn off again if it goes below 10mA.
 * For a negative threshold set the "max" parameter to the threshold value in nA
 * below which the LED should turn on and set the "min" parameter to 0. Example:
 * If you set a negative threshold of 10mA, the LED will turn on as soon as the
 * current goes below 10mA and the LED will turn off when the current exceeds 10mA.
 * 
 * In intensity mode you can define a range in nA that is used to scale the brightness
 * of the LED. Example with min=4mA and max=20mA: The LED is off at 4mA and below,
 * on at 20mA and above and the brightness is linearly scaled between the values
 * 4mA and 20mA. If the min value is greater than the max value, the LED brightness
 * is scaled the other way around.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_set_channel_led_status_config(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t channel, int32_t min, int32_t max, uint8_t config);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Returns the channel LED status configuration as set by
 * {@link tf_industrial_dual_0_20ma_v2_set_channel_led_status_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_get_channel_led_status_config(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t channel, int32_t *ret_min, int32_t *ret_max, uint8_t *ret_config);

/**
 * \ingroup BrickletIndustrialDual020mAV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_get_spitfp_error_count(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletIndustrialDual020mAV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_set_bootloader_mode(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Returns the current bootloader mode, see {@link tf_industrial_dual_0_20ma_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_get_bootloader_mode(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Sets the firmware pointer for {@link tf_industrial_dual_0_20ma_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_set_write_firmware_pointer(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint32_t pointer);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_industrial_dual_0_20ma_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_write_firmware(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_set_status_led_config(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t config);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Returns the configuration as set by {@link tf_industrial_dual_0_20ma_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_get_status_led_config(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_get_chip_temperature(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_reset(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_write_uid(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint32_t uid);

/**
 * \ingroup BrickletIndustrialDual020mAV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_read_uid(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletIndustrialDual020mAV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_dual_0_20ma_v2_get_identity(TF_IndustrialDual020mAV2 *industrial_dual_0_20ma_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
