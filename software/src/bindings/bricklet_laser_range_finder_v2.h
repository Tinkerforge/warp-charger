/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_LASER_RANGE_FINDER_V2_H
#define TF_BRICKLET_LASER_RANGE_FINDER_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletLaserRangeFinderV2 Laser Range Finder Bricklet 2.0
 */

struct TF_LaserRangeFinderV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_LaserRangeFinderV2DistanceHandler)(struct TF_LaserRangeFinderV2 *device, int16_t distance, void *user_data);
typedef void (*TF_LaserRangeFinderV2VelocityHandler)(struct TF_LaserRangeFinderV2 *device, int16_t velocity, void *user_data);

#endif
/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Measures distance up to 40m with laser light
 */
typedef struct TF_LaserRangeFinderV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_LaserRangeFinderV2DistanceHandler distance_handler;
    void *distance_user_data;

    TF_LaserRangeFinderV2VelocityHandler velocity_handler;
    void *velocity_user_data;

#endif
    uint8_t response_expected[2];
} TF_LaserRangeFinderV2;

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_DISTANCE 1

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_SET_DISTANCE_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_DISTANCE_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_VELOCITY 5

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_SET_VELOCITY_CALLBACK_CONFIGURATION 6

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_VELOCITY_CALLBACK_CONFIGURATION 7

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_SET_ENABLE 9

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_ENABLE 10

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_SET_CONFIGURATION 11

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_CONFIGURATION 12

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_SET_MOVING_AVERAGE 13

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_MOVING_AVERAGE 14

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_SET_OFFSET_CALIBRATION 15

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_OFFSET_CALIBRATION 16

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_SET_DISTANCE_LED_CONFIG 17

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_DISTANCE_LED_CONFIG 18

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_CALLBACK_DISTANCE 4

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_CALLBACK_VELOCITY 8

#endif

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_THRESHOLD_OPTION_OFF 'x'

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_THRESHOLD_OPTION_OUTSIDE 'o'

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_THRESHOLD_OPTION_INSIDE 'i'

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_THRESHOLD_OPTION_SMALLER '<'

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_THRESHOLD_OPTION_GREATER '>'

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_DISTANCE_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_DISTANCE_LED_CONFIG_ON 1

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_DISTANCE_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_DISTANCE_LED_CONFIG_SHOW_DISTANCE 3

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletLaserRangeFinderV2
 */
#define TF_LASER_RANGE_FINDER_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * This constant is used to identify a Laser Range Finder Bricklet 2.0.
 *
 * The {@link laser_range_finder_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_LASER_RANGE_FINDER_V2_DEVICE_IDENTIFIER 2144

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * This constant represents the display name of a Laser Range Finder Bricklet 2.0.
 */
#define TF_LASER_RANGE_FINDER_V2_DEVICE_DISPLAY_NAME "Laser Range Finder Bricklet 2.0"

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Creates the device object \c laser_range_finder_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_laser_range_finder_v2_create(TF_LaserRangeFinderV2 *laser_range_finder_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Removes the device object \c laser_range_finder_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_laser_range_finder_v2_destroy(TF_LaserRangeFinderV2 *laser_range_finder_v2);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the laser_range_finder_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_response_expected(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletLaserRangeFinderV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_laser_range_finder_v2_set_response_expected(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_laser_range_finder_v2_set_response_expected_all(TF_LaserRangeFinderV2 *laser_range_finder_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Registers the given \c handler to the Distance callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int16_t distance, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_laser_range_finder_v2_set_distance_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_laser_range_finder_v2_get_distance}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_laser_range_finder_v2_register_distance_callback(TF_LaserRangeFinderV2 *laser_range_finder_v2, TF_LaserRangeFinderV2DistanceHandler handler, void *user_data);


/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Registers the given \c handler to the Velocity callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int16_t velocity, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_laser_range_finder_v2_set_velocity_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_laser_range_finder_v2_get_velocity}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_laser_range_finder_v2_register_velocity_callback(TF_LaserRangeFinderV2 *laser_range_finder_v2, TF_LaserRangeFinderV2VelocityHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_laser_range_finder_v2_callback_tick(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the measured distance.
 * 
 * The laser has to be enabled, see {@link tf_laser_range_finder_v2_set_enable}.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_laser_range_finder_v2_register_distance_callback} callback. You can set the callback configuration
 * with {@link tf_laser_range_finder_v2_set_distance_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_distance(TF_LaserRangeFinderV2 *laser_range_finder_v2, int16_t *ret_distance);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * The period is the period with which the {@link tf_laser_range_finder_v2_register_distance_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_laser_range_finder_v2_register_distance_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_set_distance_callback_configuration(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint32_t period, bool value_has_to_change, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the callback configuration as set by {@link tf_laser_range_finder_v2_set_distance_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_distance_callback_configuration(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the measured velocity. The value has a range of -12800 to 12700
 * and is given in 1/100 m/s.
 * 
 * The velocity measurement only produces stables results if a fixed
 * measurement rate (see {@link tf_laser_range_finder_v2_set_configuration}) is configured. Also the laser
 * has to be enabled, see {@link tf_laser_range_finder_v2_set_enable}.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_laser_range_finder_v2_register_velocity_callback} callback. You can set the callback configuration
 * with {@link tf_laser_range_finder_v2_set_velocity_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_velocity(TF_LaserRangeFinderV2 *laser_range_finder_v2, int16_t *ret_velocity);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * The period is the period with which the {@link tf_laser_range_finder_v2_register_velocity_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_laser_range_finder_v2_register_velocity_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_set_velocity_callback_configuration(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint32_t period, bool value_has_to_change, char option, int16_t min, int16_t max);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the callback configuration as set by {@link tf_laser_range_finder_v2_set_velocity_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_velocity_callback_configuration(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int16_t *ret_min, int16_t *ret_max);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Enables the laser of the LIDAR if set to *true*.
 * 
 * We recommend that you wait 250ms after enabling the laser before
 * the first call of {@link tf_laser_range_finder_v2_get_distance} to ensure stable measurements.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_set_enable(TF_LaserRangeFinderV2 *laser_range_finder_v2, bool enable);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the value as set by {@link tf_laser_range_finder_v2_set_enable}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_enable(TF_LaserRangeFinderV2 *laser_range_finder_v2, bool *ret_enable);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * The **Acquisition Count** defines the number of times the Laser Range Finder Bricklet
 * will integrate acquisitions to find a correlation record peak. With a higher count,
 * the Bricklet can measure longer distances. With a lower count, the rate increases. The
 * allowed values are 1-255.
 * 
 * If you set **Enable Quick Termination** to true, the distance measurement will be terminated
 * early if a high peak was already detected. This means that a higher measurement rate can be achieved
 * and long distances can be measured at the same time. However, the chance of false-positive
 * distance measurements increases.
 * 
 * Normally the distance is calculated with a detection algorithm that uses peak value,
 * signal strength and noise. You can however also define a fixed **Threshold Value**.
 * Set this to a low value if you want to measure the distance to something that has
 * very little reflection (e.g. glass) and set it to a high value if you want to measure
 * the distance to something with a very high reflection (e.g. mirror). Set this to 0 to
 * use the default algorithm. The other allowed values are 1-255.
 * 
 * Set the **Measurement Frequency** to force a fixed measurement rate. If set to 0,
 * the Laser Range Finder Bricklet will use the optimal frequency according to the other
 * configurations and the actual measured distance. Since the rate is not fixed in this case,
 * the velocity measurement is not stable. For a stable velocity measurement you should
 * set a fixed measurement frequency. The lower the frequency, the higher is the resolution
 * of the calculated velocity. The allowed values are 10Hz-500Hz (and 0 to turn the fixed
 * frequency off).
 * 
 * The default values for Acquisition Count, Enable Quick Termination, Threshold Value and
 * Measurement Frequency are 128, false, 0 and 0.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_set_configuration(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t acquisition_count, bool enable_quick_termination, uint8_t threshold_value, uint16_t measurement_frequency);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the configuration as set by {@link tf_laser_range_finder_v2_set_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_configuration(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t *ret_acquisition_count, bool *ret_enable_quick_termination, uint8_t *ret_threshold_value, uint16_t *ret_measurement_frequency);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Sets the length of a `moving averaging <https://en.wikipedia.org/wiki/Moving_average>`__
 * for the distance and velocity.
 * 
 * Setting the length to 0 will turn the averaging completely off. With less
 * averaging, there is more noise on the data.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_set_moving_average(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t distance_average_length, uint8_t velocity_average_length);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the length moving average as set by {@link tf_laser_range_finder_v2_set_moving_average}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_moving_average(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t *ret_distance_average_length, uint8_t *ret_velocity_average_length);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * The offset is added to the measured distance.
 * It is saved in non-volatile memory, you only have to set it once.
 * 
 * The Bricklet comes with a per-sensor factory-calibrated offset value,
 * you should not have to call this function.
 * 
 * If you want to re-calibrate the offset you first have to set it to 0.
 * Calculate the offset by measuring the distance to a known distance
 * and set it again.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_set_offset_calibration(TF_LaserRangeFinderV2 *laser_range_finder_v2, int16_t offset);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the offset value as set by {@link tf_laser_range_finder_v2_set_offset_calibration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_offset_calibration(TF_LaserRangeFinderV2 *laser_range_finder_v2, int16_t *ret_offset);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Configures the distance LED to be either turned off, turned on, blink in
 * heartbeat mode or show the distance (brighter = object is nearer).
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_set_distance_led_config(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t config);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the LED configuration as set by {@link tf_laser_range_finder_v2_set_distance_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_distance_led_config(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletLaserRangeFinderV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_spitfp_error_count(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletLaserRangeFinderV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_set_bootloader_mode(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the current bootloader mode, see {@link tf_laser_range_finder_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_bootloader_mode(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Sets the firmware pointer for {@link tf_laser_range_finder_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_set_write_firmware_pointer(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint32_t pointer);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_laser_range_finder_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_write_firmware(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_set_status_led_config(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t config);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the configuration as set by {@link tf_laser_range_finder_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_status_led_config(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_chip_temperature(TF_LaserRangeFinderV2 *laser_range_finder_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_reset(TF_LaserRangeFinderV2 *laser_range_finder_v2);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_write_uid(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint32_t uid);

/**
 * \ingroup BrickletLaserRangeFinderV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_read_uid(TF_LaserRangeFinderV2 *laser_range_finder_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletLaserRangeFinderV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_laser_range_finder_v2_get_identity(TF_LaserRangeFinderV2 *laser_range_finder_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
