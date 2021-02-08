/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_VOLTAGE_CURRENT_V2_H
#define TF_BRICKLET_VOLTAGE_CURRENT_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletVoltageCurrentV2 Voltage/Current Bricklet 2.0
 */

struct TF_VoltageCurrentV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_VoltageCurrentV2CurrentHandler)(struct TF_VoltageCurrentV2 *device, int32_t current, void *user_data);
typedef void (*TF_VoltageCurrentV2VoltageHandler)(struct TF_VoltageCurrentV2 *device, int32_t voltage, void *user_data);
typedef void (*TF_VoltageCurrentV2PowerHandler)(struct TF_VoltageCurrentV2 *device, int32_t power, void *user_data);

#endif
/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Measures power, DC voltage and DC current up to 720W/36V/20A
 */
typedef struct TF_VoltageCurrentV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_VoltageCurrentV2CurrentHandler current_handler;
    void *current_user_data;

    TF_VoltageCurrentV2VoltageHandler voltage_handler;
    void *voltage_user_data;

    TF_VoltageCurrentV2PowerHandler power_handler;
    void *power_user_data;

#endif
    uint8_t response_expected[2];
} TF_VoltageCurrentV2;

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_CURRENT 1

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_SET_CURRENT_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_CURRENT_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_VOLTAGE 5

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_SET_VOLTAGE_CALLBACK_CONFIGURATION 6

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_VOLTAGE_CALLBACK_CONFIGURATION 7

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_POWER 9

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_SET_POWER_CALLBACK_CONFIGURATION 10

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_POWER_CALLBACK_CONFIGURATION 11

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_SET_CONFIGURATION 13

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_CONFIGURATION 14

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_SET_CALIBRATION 15

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_CALIBRATION 16

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_CALLBACK_CURRENT 4

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_CALLBACK_VOLTAGE 8

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_CALLBACK_POWER 12

#endif

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_THRESHOLD_OPTION_OFF 'x'

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_THRESHOLD_OPTION_OUTSIDE 'o'

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_THRESHOLD_OPTION_INSIDE 'i'

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_THRESHOLD_OPTION_SMALLER '<'

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_THRESHOLD_OPTION_GREATER '>'

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_AVERAGING_1 0

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_AVERAGING_4 1

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_AVERAGING_16 2

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_AVERAGING_64 3

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_AVERAGING_128 4

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_AVERAGING_256 5

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_AVERAGING_512 6

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_AVERAGING_1024 7

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_CONVERSION_TIME_140US 0

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_CONVERSION_TIME_204US 1

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_CONVERSION_TIME_332US 2

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_CONVERSION_TIME_588US 3

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_CONVERSION_TIME_1_1MS 4

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_CONVERSION_TIME_2_116MS 5

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_CONVERSION_TIME_4_156MS 6

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_CONVERSION_TIME_8_244MS 7

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletVoltageCurrentV2
 */
#define TF_VOLTAGE_CURRENT_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * This constant is used to identify a Voltage/Current Bricklet 2.0.
 *
 * The {@link voltage_current_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_VOLTAGE_CURRENT_V2_DEVICE_IDENTIFIER 2105

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * This constant represents the display name of a Voltage/Current Bricklet 2.0.
 */
#define TF_VOLTAGE_CURRENT_V2_DEVICE_DISPLAY_NAME "Voltage/Current Bricklet 2.0"

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Creates the device object \c voltage_current_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_voltage_current_v2_create(TF_VoltageCurrentV2 *voltage_current_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Removes the device object \c voltage_current_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_voltage_current_v2_destroy(TF_VoltageCurrentV2 *voltage_current_v2);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the voltage_current_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_response_expected(TF_VoltageCurrentV2 *voltage_current_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletVoltageCurrentV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_voltage_current_v2_set_response_expected(TF_VoltageCurrentV2 *voltage_current_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_voltage_current_v2_set_response_expected_all(TF_VoltageCurrentV2 *voltage_current_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Registers the given \c handler to the Current callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int32_t current, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_voltage_current_v2_set_current_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_voltage_current_v2_get_current}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_voltage_current_v2_register_current_callback(TF_VoltageCurrentV2 *voltage_current_v2, TF_VoltageCurrentV2CurrentHandler handler, void *user_data);


/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Registers the given \c handler to the Voltage callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int32_t voltage, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_voltage_current_v2_set_voltage_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_voltage_current_v2_get_voltage}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_voltage_current_v2_register_voltage_callback(TF_VoltageCurrentV2 *voltage_current_v2, TF_VoltageCurrentV2VoltageHandler handler, void *user_data);


/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Registers the given \c handler to the Power callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int32_t power, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_voltage_current_v2_set_power_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_voltage_current_v2_get_power}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_voltage_current_v2_register_power_callback(TF_VoltageCurrentV2 *voltage_current_v2, TF_VoltageCurrentV2PowerHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_voltage_current_v2_callback_tick(TF_VoltageCurrentV2 *voltage_current_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the current.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_voltage_current_v2_register_current_callback} callback. You can set the callback configuration
 * with {@link tf_voltage_current_v2_set_current_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_current(TF_VoltageCurrentV2 *voltage_current_v2, int32_t *ret_current);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * The period is the period with which the {@link tf_voltage_current_v2_register_current_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_voltage_current_v2_register_current_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_set_current_callback_configuration(TF_VoltageCurrentV2 *voltage_current_v2, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the callback configuration as set by {@link tf_voltage_current_v2_set_current_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_current_callback_configuration(TF_VoltageCurrentV2 *voltage_current_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the voltage.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_voltage_current_v2_register_voltage_callback} callback. You can set the callback configuration
 * with {@link tf_voltage_current_v2_set_voltage_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_voltage(TF_VoltageCurrentV2 *voltage_current_v2, int32_t *ret_voltage);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * The period is the period with which the {@link tf_voltage_current_v2_register_voltage_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_voltage_current_v2_register_voltage_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_set_voltage_callback_configuration(TF_VoltageCurrentV2 *voltage_current_v2, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the callback configuration as set by {@link tf_voltage_current_v2_set_voltage_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_voltage_callback_configuration(TF_VoltageCurrentV2 *voltage_current_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the power.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_voltage_current_v2_register_power_callback} callback. You can set the callback configuration
 * with {@link tf_voltage_current_v2_set_power_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_power(TF_VoltageCurrentV2 *voltage_current_v2, int32_t *ret_power);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * The period is the period with which the {@link tf_voltage_current_v2_register_power_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_voltage_current_v2_register_power_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_set_power_callback_configuration(TF_VoltageCurrentV2 *voltage_current_v2, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the callback configuration as set by {@link tf_voltage_current_v2_set_power_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_power_callback_configuration(TF_VoltageCurrentV2 *voltage_current_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Sets the configuration of the Voltage/Current Bricklet 2.0. It is
 * possible to configure number of averages as well as
 * voltage and current conversion time.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_set_configuration(TF_VoltageCurrentV2 *voltage_current_v2, uint8_t averaging, uint8_t voltage_conversion_time, uint8_t current_conversion_time);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the configuration as set by {@link tf_voltage_current_v2_set_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_configuration(TF_VoltageCurrentV2 *voltage_current_v2, uint8_t *ret_averaging, uint8_t *ret_voltage_conversion_time, uint8_t *ret_current_conversion_time);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Since the ADC and the shunt resistor used for the measurements
 * are not perfect they need to be calibrated by a multiplier and
 * a divisor if a very precise reading is needed.
 * 
 * For example, if you are expecting a current of 1000mA and you
 * are measuring 1023mA, you can calibrate the Voltage/Current Bricklet
 * by setting the current multiplier to 1000 and the divisor to 1023.
 * The same applies for the voltage.
 * 
 * The calibration will be saved on the EEPROM of the Voltage/Current
 * Bricklet and only needs to be done once.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_set_calibration(TF_VoltageCurrentV2 *voltage_current_v2, uint16_t voltage_multiplier, uint16_t voltage_divisor, uint16_t current_multiplier, uint16_t current_divisor);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the calibration as set by {@link tf_voltage_current_v2_set_calibration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_calibration(TF_VoltageCurrentV2 *voltage_current_v2, uint16_t *ret_voltage_multiplier, uint16_t *ret_voltage_divisor, uint16_t *ret_current_multiplier, uint16_t *ret_current_divisor);

/**
 * \ingroup BrickletVoltageCurrentV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_spitfp_error_count(TF_VoltageCurrentV2 *voltage_current_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletVoltageCurrentV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_set_bootloader_mode(TF_VoltageCurrentV2 *voltage_current_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the current bootloader mode, see {@link tf_voltage_current_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_bootloader_mode(TF_VoltageCurrentV2 *voltage_current_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Sets the firmware pointer for {@link tf_voltage_current_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_set_write_firmware_pointer(TF_VoltageCurrentV2 *voltage_current_v2, uint32_t pointer);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_voltage_current_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_write_firmware(TF_VoltageCurrentV2 *voltage_current_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_set_status_led_config(TF_VoltageCurrentV2 *voltage_current_v2, uint8_t config);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the configuration as set by {@link tf_voltage_current_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_status_led_config(TF_VoltageCurrentV2 *voltage_current_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_chip_temperature(TF_VoltageCurrentV2 *voltage_current_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_reset(TF_VoltageCurrentV2 *voltage_current_v2);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_write_uid(TF_VoltageCurrentV2 *voltage_current_v2, uint32_t uid);

/**
 * \ingroup BrickletVoltageCurrentV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_read_uid(TF_VoltageCurrentV2 *voltage_current_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletVoltageCurrentV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_voltage_current_v2_get_identity(TF_VoltageCurrentV2 *voltage_current_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
