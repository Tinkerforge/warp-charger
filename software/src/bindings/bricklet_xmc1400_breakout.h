/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_XMC1400_BREAKOUT_H
#define TF_BRICKLET_XMC1400_BREAKOUT_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletXMC1400Breakout XMC1400 Breakout Bricklet
 */

struct TF_XMC1400Breakout;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_XMC1400BreakoutADCValuesHandler)(struct TF_XMC1400Breakout *device, uint16_t values[8], void *user_data);
typedef void (*TF_XMC1400BreakoutCountHandler)(struct TF_XMC1400Breakout *device, uint32_t count, void *user_data);

#endif
/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Breakout for Infineon XMC1400 microcontroller
 */
typedef struct TF_XMC1400Breakout {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_XMC1400BreakoutADCValuesHandler adc_values_handler;
    void *adc_values_user_data;

    TF_XMC1400BreakoutCountHandler count_handler;
    void *count_user_data;

#endif
    uint8_t response_expected[1];
} TF_XMC1400Breakout;

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_SET_GPIO_CONFIG 1

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_GET_GPIO_INPUT 2

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_SET_ADC_CHANNEL_CONFIG 3

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_GET_ADC_CHANNEL_CONFIG 4

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_GET_ADC_CHANNEL_VALUE 5

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_GET_ADC_VALUES 6

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_SET_ADC_VALUES_CALLBACK_CONFIGURATION 7

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_GET_ADC_VALUES_CALLBACK_CONFIGURATION 8

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_GET_COUNT 10

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_SET_COUNT_CALLBACK_CONFIGURATION 11

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_GET_COUNT_CALLBACK_CONFIGURATION 12

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_RESET 243

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_CALLBACK_ADC_VALUES 9

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_CALLBACK_COUNT 13

#endif

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_THRESHOLD_OPTION_OFF 'x'

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_THRESHOLD_OPTION_OUTSIDE 'o'

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_THRESHOLD_OPTION_INSIDE 'i'

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_THRESHOLD_OPTION_SMALLER '<'

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_THRESHOLD_OPTION_GREATER '>'

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_GPIO_MODE_INPUT_TRISTATE 0

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_GPIO_MODE_INPUT_PULL_DOWN 1

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_GPIO_MODE_INPUT_PULL_UP 2

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_GPIO_MODE_INPUT_SAMPLING 3

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_GPIO_MODE_INPUT_INVERTED_TRISTATE 4

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_GPIO_MODE_INPUT_INVERTED_PULL_DOWN 5

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_GPIO_MODE_INPUT_INVERTED_PULL_UP 6

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_GPIO_MODE_INPUT_INVERTED_SAMPLING 7

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_GPIO_MODE_OUTPUT_PUSH_PULL 8

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_GPIO_MODE_OUTPUT_OPEN_DRAIN 9

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_GPIO_INPUT_HYSTERESIS_STANDARD 0

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_GPIO_INPUT_HYSTERESIS_LARGE 4

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletXMC1400Breakout
 */
#define TF_XMC1400_BREAKOUT_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * This constant is used to identify a XMC1400 Breakout Bricklet.
 *
 * The {@link xmc1400_breakout_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_XMC1400_BREAKOUT_DEVICE_IDENTIFIER 279

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * This constant represents the display name of a XMC1400 Breakout Bricklet.
 */
#define TF_XMC1400_BREAKOUT_DEVICE_DISPLAY_NAME "XMC1400 Breakout Bricklet"

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Creates the device object \c xmc1400_breakout with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_xmc1400_breakout_create(TF_XMC1400Breakout *xmc1400_breakout, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Removes the device object \c xmc1400_breakout from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_xmc1400_breakout_destroy(TF_XMC1400Breakout *xmc1400_breakout);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the xmc1400_breakout_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_response_expected(TF_XMC1400Breakout *xmc1400_breakout, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletXMC1400Breakout
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
TF_ATTRIBUTE_NONNULL_ALL int tf_xmc1400_breakout_set_response_expected(TF_XMC1400Breakout *xmc1400_breakout, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_xmc1400_breakout_set_response_expected_all(TF_XMC1400Breakout *xmc1400_breakout, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Registers the given \c handler to the ADC Values callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t values[8], void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_xmc1400_breakout_set_adc_values_callback_configuration}.
 * 
 * The parameters are the same as {@link tf_xmc1400_breakout_get_adc_values}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_xmc1400_breakout_register_adc_values_callback(TF_XMC1400Breakout *xmc1400_breakout, TF_XMC1400BreakoutADCValuesHandler handler, void *user_data);


/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Registers the given \c handler to the Count callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint32_t count, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_xmc1400_breakout_set_count_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_xmc1400_breakout_get_count}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_xmc1400_breakout_register_count_callback(TF_XMC1400Breakout *xmc1400_breakout, TF_XMC1400BreakoutCountHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_xmc1400_breakout_callback_tick(TF_XMC1400Breakout *xmc1400_breakout, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Example for a setter function. The values are the values that can be given to
 * the XMC_GPIO_Init function. See communication.c in the firmware.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_set_gpio_config(TF_XMC1400Breakout *xmc1400_breakout, uint8_t port, uint8_t pin, uint8_t mode, uint8_t input_hysteresis, bool output_level);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Example for a getter function. Returns the result of a
 * XMC_GPIO_GetInput call for the given port/pin.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_gpio_input(TF_XMC1400Breakout *xmc1400_breakout, uint8_t port, uint8_t pin, bool *ret_value);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Enables a ADC channel for the ADC driver example (adc.c/adc.h).
 * 
 * There are 8 ADC channels and they correspond to the following pins:
 * 
 * * Channel 0: P2_6
 * * Channel 1: P2_8
 * * Channel 2: P2_9
 * * Channel 3: P2_10
 * * Channel 4: P2_11
 * * Channel 5: P2_0
 * * Channel 6: P2_1
 * * Channel 7: P2_2
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_set_adc_channel_config(TF_XMC1400Breakout *xmc1400_breakout, uint8_t channel, bool enable);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Returns the config for the given channel as set by {@link tf_xmc1400_breakout_set_adc_channel_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_adc_channel_config(TF_XMC1400Breakout *xmc1400_breakout, uint8_t channel, bool *ret_enable);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Returns the 12-bit value of the given ADC channel of the ADC driver example.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_adc_channel_value(TF_XMC1400Breakout *xmc1400_breakout, uint8_t channel, uint16_t *ret_value);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Returns the values for all 8 ADC channels of the adc driver example.
 * 
 * This example function also has a corresponding callback.
 * 
 * See {@link tf_xmc1400_breakout_set_adc_values_callback_configuration} and {@link tf_xmc1400_breakout_register_adc_values_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_adc_values(TF_XMC1400Breakout *xmc1400_breakout, uint16_t ret_values[8]);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * The period is the period with which the {@link tf_xmc1400_breakout_register_adc_values_callback}
 * callback is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_set_adc_values_callback_configuration(TF_XMC1400Breakout *xmc1400_breakout, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Returns the callback configuration as set by
 * {@link tf_xmc1400_breakout_set_adc_values_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_adc_values_callback_configuration(TF_XMC1400Breakout *xmc1400_breakout, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Returns the value of the example count (see example.c).
 * 
 * This example function uses the "add_callback_value_function"-helper in the
 * generator. The getter as well as the callback and callback configuration
 * functions are auto-generated for the API as well as the firmware.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_xmc1400_breakout_register_count_callback} callback. You can set the callback configuration
 * with {@link tf_xmc1400_breakout_set_count_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_count(TF_XMC1400Breakout *xmc1400_breakout, uint32_t *ret_count);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * The period is the period with which the {@link tf_xmc1400_breakout_register_count_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_xmc1400_breakout_register_count_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_set_count_callback_configuration(TF_XMC1400Breakout *xmc1400_breakout, uint32_t period, bool value_has_to_change, char option, uint32_t min, uint32_t max);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Returns the callback configuration as set by {@link tf_xmc1400_breakout_set_count_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_count_callback_configuration(TF_XMC1400Breakout *xmc1400_breakout, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, uint32_t *ret_min, uint32_t *ret_max);

/**
 * \ingroup BrickletXMC1400Breakout
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
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_spitfp_error_count(TF_XMC1400Breakout *xmc1400_breakout, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletXMC1400Breakout
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
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_set_bootloader_mode(TF_XMC1400Breakout *xmc1400_breakout, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Returns the current bootloader mode, see {@link tf_xmc1400_breakout_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_bootloader_mode(TF_XMC1400Breakout *xmc1400_breakout, uint8_t *ret_mode);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Sets the firmware pointer for {@link tf_xmc1400_breakout_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_set_write_firmware_pointer(TF_XMC1400Breakout *xmc1400_breakout, uint32_t pointer);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_xmc1400_breakout_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_write_firmware(TF_XMC1400Breakout *xmc1400_breakout, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_set_status_led_config(TF_XMC1400Breakout *xmc1400_breakout, uint8_t config);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Returns the configuration as set by {@link tf_xmc1400_breakout_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_status_led_config(TF_XMC1400Breakout *xmc1400_breakout, uint8_t *ret_config);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_chip_temperature(TF_XMC1400Breakout *xmc1400_breakout, int16_t *ret_temperature);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_reset(TF_XMC1400Breakout *xmc1400_breakout);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_write_uid(TF_XMC1400Breakout *xmc1400_breakout, uint32_t uid);

/**
 * \ingroup BrickletXMC1400Breakout
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_read_uid(TF_XMC1400Breakout *xmc1400_breakout, uint32_t *ret_uid);

/**
 * \ingroup BrickletXMC1400Breakout
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
TF_ATTRIBUTE_NONNULL(1) int tf_xmc1400_breakout_get_identity(TF_XMC1400Breakout *xmc1400_breakout, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
