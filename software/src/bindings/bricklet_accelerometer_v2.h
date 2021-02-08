/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_ACCELEROMETER_V2_H
#define TF_BRICKLET_ACCELEROMETER_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletAccelerometerV2 Accelerometer Bricklet 2.0
 */

struct TF_AccelerometerV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_AccelerometerV2AccelerationHandler)(struct TF_AccelerometerV2 *device, int32_t x, int32_t y, int32_t z, void *user_data);
typedef void (*TF_AccelerometerV2ContinuousAcceleration16BitHandler)(struct TF_AccelerometerV2 *device, int16_t acceleration[30], void *user_data);
typedef void (*TF_AccelerometerV2ContinuousAcceleration8BitHandler)(struct TF_AccelerometerV2 *device, int8_t acceleration[60], void *user_data);

#endif
/**
 * \ingroup BrickletAccelerometerV2
 *
 * Measures acceleration in three axis
 */
typedef struct TF_AccelerometerV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_AccelerometerV2AccelerationHandler acceleration_handler;
    void *acceleration_user_data;

    TF_AccelerometerV2ContinuousAcceleration16BitHandler continuous_acceleration_16_bit_handler;
    void *continuous_acceleration_16_bit_user_data;

    TF_AccelerometerV2ContinuousAcceleration8BitHandler continuous_acceleration_8_bit_handler;
    void *continuous_acceleration_8_bit_user_data;

#endif
    uint8_t response_expected[2];
} TF_AccelerometerV2;

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_GET_ACCELERATION 1

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_SET_CONFIGURATION 2

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_GET_CONFIGURATION 3

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_SET_ACCELERATION_CALLBACK_CONFIGURATION 4

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_GET_ACCELERATION_CALLBACK_CONFIGURATION 5

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_SET_INFO_LED_CONFIG 6

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_GET_INFO_LED_CONFIG 7

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_SET_CONTINUOUS_ACCELERATION_CONFIGURATION 9

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_GET_CONTINUOUS_ACCELERATION_CONFIGURATION 10

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_SET_FILTER_CONFIGURATION 13

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_GET_FILTER_CONFIGURATION 14

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_CALLBACK_ACCELERATION 8

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_CALLBACK_CONTINUOUS_ACCELERATION_16_BIT 11

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_CALLBACK_CONTINUOUS_ACCELERATION_8_BIT 12

#endif

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_0_781HZ 0

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_1_563HZ 1

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_3_125HZ 2

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_6_2512HZ 3

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_12_5HZ 4

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_25HZ 5

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_50HZ 6

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_100HZ 7

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_200HZ 8

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_400HZ 9

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_800HZ 10

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_1600HZ 11

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_3200HZ 12

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_6400HZ 13

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_12800HZ 14

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_DATA_RATE_25600HZ 15

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FULL_SCALE_2G 0

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FULL_SCALE_4G 1

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_FULL_SCALE_8G 2

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_INFO_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_INFO_LED_CONFIG_ON 1

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_INFO_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_RESOLUTION_8BIT 0

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_RESOLUTION_16BIT 1

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_IIR_BYPASS_APPLIED 0

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_IIR_BYPASS_BYPASSED 1

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_LOW_PASS_FILTER_NINTH 0

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_LOW_PASS_FILTER_HALF 1

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletAccelerometerV2
 */
#define TF_ACCELEROMETER_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletAccelerometerV2
 *
 * This constant is used to identify a Accelerometer Bricklet 2.0.
 *
 * The {@link accelerometer_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_ACCELEROMETER_V2_DEVICE_IDENTIFIER 2130

/**
 * \ingroup BrickletAccelerometerV2
 *
 * This constant represents the display name of a Accelerometer Bricklet 2.0.
 */
#define TF_ACCELEROMETER_V2_DEVICE_DISPLAY_NAME "Accelerometer Bricklet 2.0"

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Creates the device object \c accelerometer_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_accelerometer_v2_create(TF_AccelerometerV2 *accelerometer_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Removes the device object \c accelerometer_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_accelerometer_v2_destroy(TF_AccelerometerV2 *accelerometer_v2);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the accelerometer_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_get_response_expected(TF_AccelerometerV2 *accelerometer_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletAccelerometerV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_accelerometer_v2_set_response_expected(TF_AccelerometerV2 *accelerometer_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_accelerometer_v2_set_response_expected_all(TF_AccelerometerV2 *accelerometer_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletAccelerometerV2
 *
 * Registers the given \c handler to the Acceleration callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int32_t x, int32_t y, int32_t z, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_accelerometer_v2_set_acceleration_callback_configuration}.
 * 
 * The parameters are the same as {@link tf_accelerometer_v2_get_acceleration}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_accelerometer_v2_register_acceleration_callback(TF_AccelerometerV2 *accelerometer_v2, TF_AccelerometerV2AccelerationHandler handler, void *user_data);


/**
 * \ingroup BrickletAccelerometerV2
 *
 * Registers the given \c handler to the Continuous Acceleration 16 Bit callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int16_t acceleration[30], void *user_data) \endcode
 * 
 * Returns 30 acceleration values with 16 bit resolution. The data rate can
 * be configured with {@link tf_accelerometer_v2_set_configuration} and this callback can be
 * enabled with {@link tf_accelerometer_v2_set_continuous_acceleration_configuration}.
 * 
 * The returned values are raw ADC data. If you want to put this data into
 * a FFT to determine the occurrences of specific frequencies we recommend
 * that you use the data as is. It has all of the ADC noise in it. This noise
 * looks like pure noise at first glance, but it might still have some frequnecy
 * information in it that can be utilized by the FFT.
 * 
 * Otherwise you have to use the following formulas that depend on the
 * full scale range (see {@link tf_accelerometer_v2_set_configuration}) to calculate
 * the data in gₙ/10000 (same unit that is returned by {@link tf_accelerometer_v2_get_acceleration}):
 * 
 * * Full scale 2g: acceleration = value * 625 / 1024
 * * Full scale 4g: acceleration = value * 1250 / 1024
 * * Full scale 8g: acceleration = value * 2500 / 1024
 * 
 * The data is formated in the sequence "x, y, z, x, y, z, ..." depending on
 * the enabled axis. Examples:
 * 
 * * x, y, z enabled: "x, y, z, ..." 10x repeated
 * * x, z enabled: "x, z, ..." 15x repeated
 * * y enabled: "y, ..." 30x repeated
 */
TF_ATTRIBUTE_NONNULL(1) void tf_accelerometer_v2_register_continuous_acceleration_16_bit_callback(TF_AccelerometerV2 *accelerometer_v2, TF_AccelerometerV2ContinuousAcceleration16BitHandler handler, void *user_data);


/**
 * \ingroup BrickletAccelerometerV2
 *
 * Registers the given \c handler to the Continuous Acceleration 8 Bit callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int8_t acceleration[60], void *user_data) \endcode
 * 
 * Returns 60 acceleration values with 8 bit resolution. The data rate can
 * be configured with {@link tf_accelerometer_v2_set_configuration} and this callback can be
 * enabled with {@link tf_accelerometer_v2_set_continuous_acceleration_configuration}.
 * 
 * The returned values are raw ADC data. If you want to put this data into
 * a FFT to determine the occurrences of specific frequencies we recommend
 * that you use the data as is. It has all of the ADC noise in it. This noise
 * looks like pure noise at first glance, but it might still have some frequnecy
 * information in it that can be utilized by the FFT.
 * 
 * Otherwise you have to use the following formulas that depend on the
 * full scale range (see {@link tf_accelerometer_v2_set_configuration}) to calculate
 * the data in gₙ/10000 (same unit that is returned by {@link tf_accelerometer_v2_get_acceleration}):
 * 
 * * Full scale 2g: acceleration = value * 256 * 625 / 1024
 * * Full scale 4g: acceleration = value * 256 * 1250 / 1024
 * * Full scale 8g: acceleration = value * 256 * 2500 / 1024
 * 
 * The data is formated in the sequence "x, y, z, x, y, z, ..." depending on
 * the enabled axis. Examples:
 * 
 * * x, y, z enabled: "x, y, z, ..." 20x repeated
 * * x, z enabled: "x, z, ..." 30x repeated
 * * y enabled: "y, ..." 60x repeated
 */
TF_ATTRIBUTE_NONNULL(1) void tf_accelerometer_v2_register_continuous_acceleration_8_bit_callback(TF_AccelerometerV2 *accelerometer_v2, TF_AccelerometerV2ContinuousAcceleration8BitHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletAccelerometerV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_accelerometer_v2_callback_tick(TF_AccelerometerV2 *accelerometer_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Returns the acceleration in x, y and z direction. The values
 * are given in gₙ/10000 (1gₙ = 9.80665m/s²). The range is
 * configured with {@link tf_accelerometer_v2_set_configuration}.
 * 
 * If you want to get the acceleration periodically, it is recommended
 * to use the {@link tf_accelerometer_v2_register_acceleration_callback} callback and set the period with
 * {@link tf_accelerometer_v2_set_acceleration_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_get_acceleration(TF_AccelerometerV2 *accelerometer_v2, int32_t *ret_x, int32_t *ret_y, int32_t *ret_z);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Configures the data rate and full scale range.
 * Possible values are:
 * 
 * * Data rate of 0.781Hz to 25600Hz.
 * * Full scale range of ±2g up to ±8g.
 * 
 * Decreasing data rate or full scale range will also decrease the noise on
 * the data.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_set_configuration(TF_AccelerometerV2 *accelerometer_v2, uint8_t data_rate, uint8_t full_scale);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Returns the configuration as set by {@link tf_accelerometer_v2_set_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_get_configuration(TF_AccelerometerV2 *accelerometer_v2, uint8_t *ret_data_rate, uint8_t *ret_full_scale);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * The period is the period with which the {@link tf_accelerometer_v2_register_acceleration_callback}
 * callback is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 * 
 * If this callback is enabled, the {@link tf_accelerometer_v2_register_continuous_acceleration_16_bit_callback} callback
 * and {@link tf_accelerometer_v2_register_continuous_acceleration_8_bit_callback} callback will automatically be disabled.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_set_acceleration_callback_configuration(TF_AccelerometerV2 *accelerometer_v2, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Returns the callback configuration as set by
 * {@link tf_accelerometer_v2_set_acceleration_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_get_acceleration_callback_configuration(TF_AccelerometerV2 *accelerometer_v2, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Configures the info LED (marked as "Force" on the Bricklet) to be either turned off,
 * turned on, or blink in heartbeat mode.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_set_info_led_config(TF_AccelerometerV2 *accelerometer_v2, uint8_t config);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Returns the LED configuration as set by {@link tf_accelerometer_v2_set_info_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_get_info_led_config(TF_AccelerometerV2 *accelerometer_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * For high throughput of acceleration data (> 1000Hz) you have to use the
 * {@link tf_accelerometer_v2_register_continuous_acceleration_16_bit_callback} or {@link tf_accelerometer_v2_register_continuous_acceleration_8_bit_callback}
 * callbacks.
 * 
 * You can enable the callback for each axis (x, y, z) individually and choose a
 * resolution of 8 bit or 16 bit.
 * 
 * If at least one of the axis is enabled and the resolution is set to 8 bit,
 * the {@link tf_accelerometer_v2_register_continuous_acceleration_8_bit_callback} callback is activated. If at least
 * one of the axis is enabled and the resolution is set to 16 bit,
 * the {@link tf_accelerometer_v2_register_continuous_acceleration_16_bit_callback} callback is activated.
 * 
 * The returned values are raw ADC data. If you want to put this data into
 * a FFT to determine the occurrences of specific frequencies we recommend
 * that you use the data as is. It has all of the ADC noise in it. This noise
 * looks like pure noise at first glance, but it might still have some frequnecy
 * information in it that can be utilized by the FFT.
 * 
 * Otherwise you have to use the following formulas that depend on the configured
 * resolution (8/16 bit) and the full scale range (see {@link tf_accelerometer_v2_set_configuration}) to calculate
 * the data in gₙ/10000 (same unit that is returned by {@link tf_accelerometer_v2_get_acceleration}):
 * 
 * * 16 bit, full scale 2g: acceleration = value * 625 / 1024
 * * 16 bit, full scale 4g: acceleration = value * 1250 / 1024
 * * 16 bit, full scale 8g: acceleration = value * 2500 / 1024
 * 
 * If a resolution of 8 bit is used, only the 8 most significant bits will be
 * transferred, so you can use the following formulas:
 * 
 * * 8 bit, full scale 2g: acceleration = value * 256 * 625 / 1024
 * * 8 bit, full scale 4g: acceleration = value * 256 * 1250 / 1024
 * * 8 bit, full scale 8g: acceleration = value * 256 * 2500 / 1024
 * 
 * If no axis is enabled, both callbacks are disabled. If one of the continuous
 * callbacks is enabled, the {@link tf_accelerometer_v2_register_acceleration_callback} callback is disabled.
 * 
 * The maximum throughput depends on the exact configuration:
 * 
 * \verbatim
 *  "Number of axis enabled", "Throughput 8 bit", "Throughout 16 bit"
 * 
 *  "1", "25600Hz", "25600Hz"
 *  "2", "25600Hz", "15000Hz"
 *  "3", "20000Hz", "10000Hz"
 * \endverbatim
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_set_continuous_acceleration_configuration(TF_AccelerometerV2 *accelerometer_v2, bool enable_x, bool enable_y, bool enable_z, uint8_t resolution);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Returns the continuous acceleration configuration as set by
 * {@link tf_accelerometer_v2_set_continuous_acceleration_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_get_continuous_acceleration_configuration(TF_AccelerometerV2 *accelerometer_v2, bool *ret_enable_x, bool *ret_enable_y, bool *ret_enable_z, uint8_t *ret_resolution);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Configures IIR Bypass filter mode and low pass filter roll off corner frequency.
 * 
 * The filter can be applied or bypassed and the corner frequency can be
 * half or a ninth of the output data rate.
 * 
 * .. image:: /Images/Bricklets/bricklet_accelerometer_v2_filter.png
 *    :scale: 100 %
 *    :alt: Accelerometer filter
 *    :align: center
 *    :target: ../../_images/Bricklets/bricklet_accelerometer_v2_filter.png
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_set_filter_configuration(TF_AccelerometerV2 *accelerometer_v2, uint8_t iir_bypass, uint8_t low_pass_filter);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Returns the configuration as set by {@link tf_accelerometer_v2_set_filter_configuration}.
 * 
 * .. versionadded:: 2.0.2$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_get_filter_configuration(TF_AccelerometerV2 *accelerometer_v2, uint8_t *ret_iir_bypass, uint8_t *ret_low_pass_filter);

/**
 * \ingroup BrickletAccelerometerV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_get_spitfp_error_count(TF_AccelerometerV2 *accelerometer_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletAccelerometerV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_set_bootloader_mode(TF_AccelerometerV2 *accelerometer_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Returns the current bootloader mode, see {@link tf_accelerometer_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_get_bootloader_mode(TF_AccelerometerV2 *accelerometer_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Sets the firmware pointer for {@link tf_accelerometer_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_set_write_firmware_pointer(TF_AccelerometerV2 *accelerometer_v2, uint32_t pointer);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_accelerometer_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_write_firmware(TF_AccelerometerV2 *accelerometer_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_set_status_led_config(TF_AccelerometerV2 *accelerometer_v2, uint8_t config);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Returns the configuration as set by {@link tf_accelerometer_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_get_status_led_config(TF_AccelerometerV2 *accelerometer_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_get_chip_temperature(TF_AccelerometerV2 *accelerometer_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_reset(TF_AccelerometerV2 *accelerometer_v2);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_write_uid(TF_AccelerometerV2 *accelerometer_v2, uint32_t uid);

/**
 * \ingroup BrickletAccelerometerV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_read_uid(TF_AccelerometerV2 *accelerometer_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletAccelerometerV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_accelerometer_v2_get_identity(TF_AccelerometerV2 *accelerometer_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
