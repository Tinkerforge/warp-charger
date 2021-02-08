/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_PARTICULATE_MATTER_H
#define TF_BRICKLET_PARTICULATE_MATTER_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletParticulateMatter Particulate Matter Bricklet
 */

struct TF_ParticulateMatter;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_ParticulateMatterPMConcentrationHandler)(struct TF_ParticulateMatter *device, uint16_t pm10, uint16_t pm25, uint16_t pm100, void *user_data);
typedef void (*TF_ParticulateMatterPMCountHandler)(struct TF_ParticulateMatter *device, uint16_t greater03um, uint16_t greater05um, uint16_t greater10um, uint16_t greater25um, uint16_t greater50um, uint16_t greater100um, void *user_data);

#endif
/**
 * \ingroup BrickletParticulateMatter
 *
 * Measures Particulate Matter concentration (PM1.0, PM2.5 and PM10)
 */
typedef struct TF_ParticulateMatter {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_ParticulateMatterPMConcentrationHandler pm_concentration_handler;
    void *pm_concentration_user_data;

    TF_ParticulateMatterPMCountHandler pm_count_handler;
    void *pm_count_user_data;

#endif
    uint8_t response_expected[1];
} TF_ParticulateMatter;

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_GET_PM_CONCENTRATION 1

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_GET_PM_COUNT 2

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_SET_ENABLE 3

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_GET_ENABLE 4

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_GET_SENSOR_INFO 5

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_SET_PM_CONCENTRATION_CALLBACK_CONFIGURATION 6

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_GET_PM_CONCENTRATION_CALLBACK_CONFIGURATION 7

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_SET_PM_COUNT_CALLBACK_CONFIGURATION 8

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_GET_PM_COUNT_CALLBACK_CONFIGURATION 9

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_RESET 243

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_CALLBACK_PM_CONCENTRATION 10

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_CALLBACK_PM_COUNT 11

#endif

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletParticulateMatter
 */
#define TF_PARTICULATE_MATTER_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletParticulateMatter
 *
 * This constant is used to identify a Particulate Matter Bricklet.
 *
 * The {@link particulate_matter_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_PARTICULATE_MATTER_DEVICE_IDENTIFIER 2110

/**
 * \ingroup BrickletParticulateMatter
 *
 * This constant represents the display name of a Particulate Matter Bricklet.
 */
#define TF_PARTICULATE_MATTER_DEVICE_DISPLAY_NAME "Particulate Matter Bricklet"

/**
 * \ingroup BrickletParticulateMatter
 *
 * Creates the device object \c particulate_matter with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_particulate_matter_create(TF_ParticulateMatter *particulate_matter, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Removes the device object \c particulate_matter from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_particulate_matter_destroy(TF_ParticulateMatter *particulate_matter);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the particulate_matter_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_get_response_expected(TF_ParticulateMatter *particulate_matter, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletParticulateMatter
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
TF_ATTRIBUTE_NONNULL_ALL int tf_particulate_matter_set_response_expected(TF_ParticulateMatter *particulate_matter, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_particulate_matter_set_response_expected_all(TF_ParticulateMatter *particulate_matter, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletParticulateMatter
 *
 * Registers the given \c handler to the PM Concentration callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t pm10, uint16_t pm25, uint16_t pm100, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_particulate_matter_set_pm_concentration_callback_configuration}.
 * 
 * The parameters are the same as {@link tf_particulate_matter_get_pm_concentration}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_particulate_matter_register_pm_concentration_callback(TF_ParticulateMatter *particulate_matter, TF_ParticulateMatterPMConcentrationHandler handler, void *user_data);


/**
 * \ingroup BrickletParticulateMatter
 *
 * Registers the given \c handler to the PM Count callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t greater03um, uint16_t greater05um, uint16_t greater10um, uint16_t greater25um, uint16_t greater50um, uint16_t greater100um, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_particulate_matter_set_pm_count_callback_configuration}.
 * 
 * The parameters are the same as {@link tf_particulate_matter_get_pm_count}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_particulate_matter_register_pm_count_callback(TF_ParticulateMatter *particulate_matter, TF_ParticulateMatterPMCountHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletParticulateMatter
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_particulate_matter_callback_tick(TF_ParticulateMatter *particulate_matter, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletParticulateMatter
 *
 * Returns the particulate matter concentration, broken down as:
 * 
 * * PM\ :sub:`1.0`\ ,
 * * PM\ :sub:`2.5`\  and
 * * PM\ :sub:`10.0`\ .
 * 
 * If the sensor is disabled (see {@link tf_particulate_matter_set_enable}) then the last known good
 * values from the sensor are returned.
 * 
 * If you want to get the values periodically, it is recommended to use the
 * {@link tf_particulate_matter_register_pm_concentration_callback} callback. You can set the callback configuration
 * with {@link tf_particulate_matter_set_pm_concentration_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_get_pm_concentration(TF_ParticulateMatter *particulate_matter, uint16_t *ret_pm10, uint16_t *ret_pm25, uint16_t *ret_pm100);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Returns the number of particulates in 100 ml of air, broken down by their
 * diameter:
 * 
 * * greater 0.3µm,
 * * greater 0.5µm,
 * * greater 1.0µm,
 * * greater 2.5µm,
 * * greater 5.0µm and
 * * greater 10.0µm.
 * 
 * If the sensor is disabled (see {@link tf_particulate_matter_set_enable}) then the last known good
 * value from the sensor is returned.
 * 
 * If you want to get the values periodically, it is recommended to use the
 * {@link tf_particulate_matter_register_pm_count_callback} callback. You can set the callback configuration
 * with {@link tf_particulate_matter_set_pm_count_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_get_pm_count(TF_ParticulateMatter *particulate_matter, uint16_t *ret_greater03um, uint16_t *ret_greater05um, uint16_t *ret_greater10um, uint16_t *ret_greater25um, uint16_t *ret_greater50um, uint16_t *ret_greater100um);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Enables/Disables the fan and the laser diode of the sensors.
 * 
 * The sensor takes about 30 seconds after it is enabled to settle and produce stable
 * values.
 * 
 * The laser diode has a lifetime of about 8000 hours. If you want to measure in
 * an interval with a long idle time (e.g. hourly) you should turn the
 * laser diode off between the measurements.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_set_enable(TF_ParticulateMatter *particulate_matter, bool enable);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Returns the state of the sensor as set by {@link tf_particulate_matter_set_enable}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_get_enable(TF_ParticulateMatter *particulate_matter, bool *ret_enable);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Returns information about the sensor:
 * 
 * * the sensor version number,
 * * the last error code reported by the sensor (0 means no error) and
 * * the number of framing and checksum errors that occurred in the communication
 *   with the sensor.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_get_sensor_info(TF_ParticulateMatter *particulate_matter, uint8_t *ret_sensor_version, uint8_t *ret_last_error_code, uint8_t *ret_framing_error_count, uint8_t *ret_checksum_error_count);

/**
 * \ingroup BrickletParticulateMatter
 *
 * The period is the period with which the {@link tf_particulate_matter_register_pm_concentration_callback}
 * callback is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_set_pm_concentration_callback_configuration(TF_ParticulateMatter *particulate_matter, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Returns the callback configuration as set by
 * {@link tf_particulate_matter_set_pm_concentration_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_get_pm_concentration_callback_configuration(TF_ParticulateMatter *particulate_matter, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletParticulateMatter
 *
 * The period is the period with which the {@link tf_particulate_matter_register_pm_count_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_set_pm_count_callback_configuration(TF_ParticulateMatter *particulate_matter, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Returns the callback configuration as set by
 * {@link tf_particulate_matter_set_pm_count_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_get_pm_count_callback_configuration(TF_ParticulateMatter *particulate_matter, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletParticulateMatter
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
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_get_spitfp_error_count(TF_ParticulateMatter *particulate_matter, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletParticulateMatter
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
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_set_bootloader_mode(TF_ParticulateMatter *particulate_matter, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Returns the current bootloader mode, see {@link tf_particulate_matter_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_get_bootloader_mode(TF_ParticulateMatter *particulate_matter, uint8_t *ret_mode);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Sets the firmware pointer for {@link tf_particulate_matter_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_set_write_firmware_pointer(TF_ParticulateMatter *particulate_matter, uint32_t pointer);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_particulate_matter_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_write_firmware(TF_ParticulateMatter *particulate_matter, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_set_status_led_config(TF_ParticulateMatter *particulate_matter, uint8_t config);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Returns the configuration as set by {@link tf_particulate_matter_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_get_status_led_config(TF_ParticulateMatter *particulate_matter, uint8_t *ret_config);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_get_chip_temperature(TF_ParticulateMatter *particulate_matter, int16_t *ret_temperature);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_reset(TF_ParticulateMatter *particulate_matter);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_write_uid(TF_ParticulateMatter *particulate_matter, uint32_t uid);

/**
 * \ingroup BrickletParticulateMatter
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_read_uid(TF_ParticulateMatter *particulate_matter, uint32_t *ret_uid);

/**
 * \ingroup BrickletParticulateMatter
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
TF_ATTRIBUTE_NONNULL(1) int tf_particulate_matter_get_identity(TF_ParticulateMatter *particulate_matter, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
