/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_AMBIENT_LIGHT_V3_H
#define TF_BRICKLET_AMBIENT_LIGHT_V3_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletAmbientLightV3 Ambient Light Bricklet 3.0
 */

struct TF_AmbientLightV3;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_AmbientLightV3IlluminanceHandler)(struct TF_AmbientLightV3 *device, uint32_t illuminance, void *user_data);

#endif
/**
 * \ingroup BrickletAmbientLightV3
 *
 * Measures ambient light up to 64000lux
 */
typedef struct TF_AmbientLightV3 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_AmbientLightV3IlluminanceHandler illuminance_handler;
    void *illuminance_user_data;

#endif
    uint8_t response_expected[1];
} TF_AmbientLightV3;

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_GET_ILLUMINANCE 1

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_SET_ILLUMINANCE_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_GET_ILLUMINANCE_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_SET_CONFIGURATION 5

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_GET_CONFIGURATION 6

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_RESET 243

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_CALLBACK_ILLUMINANCE 4

#endif

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_THRESHOLD_OPTION_OFF 'x'

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_THRESHOLD_OPTION_OUTSIDE 'o'

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_THRESHOLD_OPTION_INSIDE 'i'

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_THRESHOLD_OPTION_SMALLER '<'

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_THRESHOLD_OPTION_GREATER '>'

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_ILLUMINANCE_RANGE_UNLIMITED 6

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_ILLUMINANCE_RANGE_64000LUX 0

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_ILLUMINANCE_RANGE_32000LUX 1

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_ILLUMINANCE_RANGE_16000LUX 2

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_ILLUMINANCE_RANGE_8000LUX 3

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_ILLUMINANCE_RANGE_1300LUX 4

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_ILLUMINANCE_RANGE_600LUX 5

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_INTEGRATION_TIME_50MS 0

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_INTEGRATION_TIME_100MS 1

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_INTEGRATION_TIME_150MS 2

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_INTEGRATION_TIME_200MS 3

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_INTEGRATION_TIME_250MS 4

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_INTEGRATION_TIME_300MS 5

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_INTEGRATION_TIME_350MS 6

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_INTEGRATION_TIME_400MS 7

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletAmbientLightV3
 */
#define TF_AMBIENT_LIGHT_V3_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletAmbientLightV3
 *
 * This constant is used to identify a Ambient Light Bricklet 3.0.
 *
 * The {@link ambient_light_v3_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_AMBIENT_LIGHT_V3_DEVICE_IDENTIFIER 2131

/**
 * \ingroup BrickletAmbientLightV3
 *
 * This constant represents the display name of a Ambient Light Bricklet 3.0.
 */
#define TF_AMBIENT_LIGHT_V3_DEVICE_DISPLAY_NAME "Ambient Light Bricklet 3.0"

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Creates the device object \c ambient_light_v3 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_ambient_light_v3_create(TF_AmbientLightV3 *ambient_light_v3, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Removes the device object \c ambient_light_v3 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_ambient_light_v3_destroy(TF_AmbientLightV3 *ambient_light_v3);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the ambient_light_v3_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_get_response_expected(TF_AmbientLightV3 *ambient_light_v3, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletAmbientLightV3
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
TF_ATTRIBUTE_NONNULL_ALL int tf_ambient_light_v3_set_response_expected(TF_AmbientLightV3 *ambient_light_v3, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_ambient_light_v3_set_response_expected_all(TF_AmbientLightV3 *ambient_light_v3, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletAmbientLightV3
 *
 * Registers the given \c handler to the Illuminance callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint32_t illuminance, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_ambient_light_v3_set_illuminance_callback_configuration}.
 * 
 * The parameter is the same as {@link tf_ambient_light_v3_get_illuminance}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_ambient_light_v3_register_illuminance_callback(TF_AmbientLightV3 *ambient_light_v3, TF_AmbientLightV3IlluminanceHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletAmbientLightV3
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_ambient_light_v3_callback_tick(TF_AmbientLightV3 *ambient_light_v3, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Returns the illuminance of the ambient light sensor. The measurement range goes
 * up to about 100000lux, but above 64000lux the precision starts to drop.
 * The illuminance is given in lux/100, i.e. a value of 450000 means that an
 * illuminance of 4500lux is measured.
 * 
 * An illuminance of 0lux indicates that the sensor is saturated and the
 * configuration should be modified, see {@link tf_ambient_light_v3_set_configuration}.
 * 
 * 
 * If you want to get the value periodically, it is recommended to use the
 * {@link tf_ambient_light_v3_register_illuminance_callback} callback. You can set the callback configuration
 * with {@link tf_ambient_light_v3_set_illuminance_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_get_illuminance(TF_AmbientLightV3 *ambient_light_v3, uint32_t *ret_illuminance);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * The period is the period with which the {@link tf_ambient_light_v3_register_illuminance_callback} callback is triggered
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
 * The `option`-parameter together with min/max sets a threshold for the {@link tf_ambient_light_v3_register_illuminance_callback} callback.
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
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_set_illuminance_callback_configuration(TF_AmbientLightV3 *ambient_light_v3, uint32_t period, bool value_has_to_change, char option, uint32_t min, uint32_t max);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Returns the callback configuration as set by {@link tf_ambient_light_v3_set_illuminance_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_get_illuminance_callback_configuration(TF_AmbientLightV3 *ambient_light_v3, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, uint32_t *ret_min, uint32_t *ret_max);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Sets the configuration. It is possible to configure an illuminance range
 * between 0-600lux and 0-64000lux and an integration time between 50ms and 400ms.
 * 
 * The unlimited illuminance range allows to measure up to about 100000lux, but
 * above 64000lux the precision starts to drop.
 * 
 * A smaller illuminance range increases the resolution of the data. A longer
 * integration time will result in less noise on the data.
 * 
 * If the actual measure illuminance is out-of-range then the current illuminance
 * range maximum +0.01lux is reported by {@link tf_ambient_light_v3_get_illuminance} and the
 * {@link tf_ambient_light_v3_register_illuminance_callback} callback. For example, 800001 for the 0-8000lux range.
 * 
 * With a long integration time the sensor might be saturated before the measured
 * value reaches the maximum of the selected illuminance range. In this case 0lux
 * is reported by {@link tf_ambient_light_v3_get_illuminance} and the {@link tf_ambient_light_v3_register_illuminance_callback} callback.
 * 
 * If the measurement is out-of-range or the sensor is saturated then you should
 * configure the next higher illuminance range. If the highest range is already
 * in use, then start to reduce the integration time.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_set_configuration(TF_AmbientLightV3 *ambient_light_v3, uint8_t illuminance_range, uint8_t integration_time);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Returns the configuration as set by {@link tf_ambient_light_v3_set_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_get_configuration(TF_AmbientLightV3 *ambient_light_v3, uint8_t *ret_illuminance_range, uint8_t *ret_integration_time);

/**
 * \ingroup BrickletAmbientLightV3
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
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_get_spitfp_error_count(TF_AmbientLightV3 *ambient_light_v3, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletAmbientLightV3
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
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_set_bootloader_mode(TF_AmbientLightV3 *ambient_light_v3, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Returns the current bootloader mode, see {@link tf_ambient_light_v3_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_get_bootloader_mode(TF_AmbientLightV3 *ambient_light_v3, uint8_t *ret_mode);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Sets the firmware pointer for {@link tf_ambient_light_v3_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_set_write_firmware_pointer(TF_AmbientLightV3 *ambient_light_v3, uint32_t pointer);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_ambient_light_v3_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_write_firmware(TF_AmbientLightV3 *ambient_light_v3, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_set_status_led_config(TF_AmbientLightV3 *ambient_light_v3, uint8_t config);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Returns the configuration as set by {@link tf_ambient_light_v3_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_get_status_led_config(TF_AmbientLightV3 *ambient_light_v3, uint8_t *ret_config);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_get_chip_temperature(TF_AmbientLightV3 *ambient_light_v3, int16_t *ret_temperature);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_reset(TF_AmbientLightV3 *ambient_light_v3);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_write_uid(TF_AmbientLightV3 *ambient_light_v3, uint32_t uid);

/**
 * \ingroup BrickletAmbientLightV3
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_read_uid(TF_AmbientLightV3 *ambient_light_v3, uint32_t *ret_uid);

/**
 * \ingroup BrickletAmbientLightV3
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
TF_ATTRIBUTE_NONNULL(1) int tf_ambient_light_v3_get_identity(TF_AmbientLightV3 *ambient_light_v3, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
