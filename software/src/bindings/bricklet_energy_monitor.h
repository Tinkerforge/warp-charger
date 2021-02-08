/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_ENERGY_MONITOR_H
#define TF_BRICKLET_ENERGY_MONITOR_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletEnergyMonitor Energy Monitor Bricklet
 */

struct TF_EnergyMonitor;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_EnergyMonitorEnergyDataHandler)(struct TF_EnergyMonitor *device, int32_t voltage, int32_t current, int32_t energy, int32_t real_power, int32_t apparent_power, int32_t reactive_power, uint16_t power_factor, uint16_t frequency, void *user_data);

#endif
/**
 * \ingroup BrickletEnergyMonitor
 *
 * Measures Voltage, Current, Energy, Real/Apparent/Reactive Power, Power Factor and Frequency
 */
typedef struct TF_EnergyMonitor {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_EnergyMonitorEnergyDataHandler energy_data_handler;
    void *energy_data_user_data;

#endif
    uint8_t response_expected[1];
} TF_EnergyMonitor;

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_GET_ENERGY_DATA 1

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_RESET_ENERGY 2

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_GET_WAVEFORM_LOW_LEVEL 3

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_GET_TRANSFORMER_STATUS 4

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_SET_TRANSFORMER_CALIBRATION 5

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_GET_TRANSFORMER_CALIBRATION 6

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_CALIBRATE_OFFSET 7

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_SET_ENERGY_DATA_CALLBACK_CONFIGURATION 8

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_GET_ENERGY_DATA_CALLBACK_CONFIGURATION 9

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_RESET 243

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_CALLBACK_ENERGY_DATA 10

#endif

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletEnergyMonitor
 */
#define TF_ENERGY_MONITOR_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletEnergyMonitor
 *
 * This constant is used to identify a Energy Monitor Bricklet.
 *
 * The {@link energy_monitor_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_ENERGY_MONITOR_DEVICE_IDENTIFIER 2152

/**
 * \ingroup BrickletEnergyMonitor
 *
 * This constant represents the display name of a Energy Monitor Bricklet.
 */
#define TF_ENERGY_MONITOR_DEVICE_DISPLAY_NAME "Energy Monitor Bricklet"

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Creates the device object \c energy_monitor with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_energy_monitor_create(TF_EnergyMonitor *energy_monitor, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Removes the device object \c energy_monitor from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_energy_monitor_destroy(TF_EnergyMonitor *energy_monitor);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the energy_monitor_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_get_response_expected(TF_EnergyMonitor *energy_monitor, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletEnergyMonitor
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
TF_ATTRIBUTE_NONNULL_ALL int tf_energy_monitor_set_response_expected(TF_EnergyMonitor *energy_monitor, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_energy_monitor_set_response_expected_all(TF_EnergyMonitor *energy_monitor, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletEnergyMonitor
 *
 * Registers the given \c handler to the Energy Data callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int32_t voltage, int32_t current, int32_t energy, int32_t real_power, int32_t apparent_power, int32_t reactive_power, uint16_t power_factor, uint16_t frequency, void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_energy_monitor_set_energy_data_callback_configuration}.
 * 
 * The parameters are the same as {@link tf_energy_monitor_get_energy_data}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_energy_monitor_register_energy_data_callback(TF_EnergyMonitor *energy_monitor, TF_EnergyMonitorEnergyDataHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletEnergyMonitor
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_energy_monitor_callback_tick(TF_EnergyMonitor *energy_monitor, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Returns all of the measurements that are done by the Energy Monitor Bricklet.
 * 
 * * Voltage RMS
 * * Current RMS
 * * Energy (integrated over time)
 * * Real Power
 * * Apparent Power
 * * Reactive Power
 * * Power Factor
 * * Frequency (AC Frequency of the mains voltage)
 * 
 * The frequency is recalculated every 6 seconds.
 * 
 * All other values are integrated over 10 zero-crossings of the voltage sine wave.
 * With a standard AC mains voltage frequency of 50Hz this results in a 5 measurements
 * per second (or an integration time of 200ms per measurement).
 * 
 * If no voltage transformer is connected, the Bricklet will use the current waveform
 * to calculate the frequency and it will use an integration time of
 * 10 zero-crossings of the current waveform.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_get_energy_data(TF_EnergyMonitor *energy_monitor, int32_t *ret_voltage, int32_t *ret_current, int32_t *ret_energy, int32_t *ret_real_power, int32_t *ret_apparent_power, int32_t *ret_reactive_power, uint16_t *ret_power_factor, uint16_t *ret_frequency);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Sets the energy value (see {@link tf_energy_monitor_get_energy_data}) back to 0Wh.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_reset_energy(TF_EnergyMonitor *energy_monitor);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Returns a snapshot of the voltage and current waveform. The values
 * in the returned array alternate between voltage and current. The data from
 * one getter call contains 768 data points for voltage and current, which
 * correspond to about 3 full sine waves.
 * 
 * The voltage is given with a resolution of 100mV and the current is given
 * with a resolution of 10mA.
 * 
 * This data is meant to be used for a non-realtime graphical representation of
 * the voltage and current waveforms.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_get_waveform_low_level(TF_EnergyMonitor *energy_monitor, uint16_t *ret_waveform_chunk_offset, int16_t ret_waveform_chunk_data[30]);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Returns *true* if a voltage/current transformer is connected to the Bricklet.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_get_transformer_status(TF_EnergyMonitor *energy_monitor, bool *ret_voltage_transformer_connected, bool *ret_current_transformer_connected);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Sets the transformer ratio for the voltage and current transformer in 1/100 form.
 * 
 * Example: If your mains voltage is 230V, you use 9V voltage transformer and a
 * 1V:30A current clamp your voltage ratio is 230/9 = 25.56 and your current ratio
 * is 30/1 = 30.
 * 
 * In this case you have to set the values 2556 and 3000 for voltage ratio and current
 * ratio.
 * 
 * The calibration is saved in non-volatile memory, you only have to set it once.
 * 
 * Set the phase shift to 0. It is for future use and currently not supported by the Bricklet.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_set_transformer_calibration(TF_EnergyMonitor *energy_monitor, uint16_t voltage_ratio, uint16_t current_ratio, int16_t phase_shift);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Returns the transformer calibration as set by {@link tf_energy_monitor_set_transformer_calibration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_get_transformer_calibration(TF_EnergyMonitor *energy_monitor, uint16_t *ret_voltage_ratio, uint16_t *ret_current_ratio, int16_t *ret_phase_shift);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Calling this function will start an offset calibration. The offset calibration will
 * integrate the voltage and current waveform over a longer time period to find the 0
 * transition point in the sine wave.
 * 
 * The Bricklet comes with a factory-calibrated offset value, you should not have to
 * call this function.
 * 
 * If you want to re-calibrate the offset we recommend that you connect a load that
 * has a smooth sinusoidal voltage and current waveform. Alternatively you can also
 * short both inputs.
 * 
 * The calibration is saved in non-volatile memory, you only have to set it once.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_calibrate_offset(TF_EnergyMonitor *energy_monitor);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * The period is the period with which the {@link tf_energy_monitor_register_energy_data_callback}
 * callback is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_set_energy_data_callback_configuration(TF_EnergyMonitor *energy_monitor, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Returns the callback configuration as set by
 * {@link tf_energy_monitor_set_energy_data_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_get_energy_data_callback_configuration(TF_EnergyMonitor *energy_monitor, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletEnergyMonitor
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
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_get_spitfp_error_count(TF_EnergyMonitor *energy_monitor, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletEnergyMonitor
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
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_set_bootloader_mode(TF_EnergyMonitor *energy_monitor, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Returns the current bootloader mode, see {@link tf_energy_monitor_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_get_bootloader_mode(TF_EnergyMonitor *energy_monitor, uint8_t *ret_mode);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Sets the firmware pointer for {@link tf_energy_monitor_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_set_write_firmware_pointer(TF_EnergyMonitor *energy_monitor, uint32_t pointer);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_energy_monitor_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_write_firmware(TF_EnergyMonitor *energy_monitor, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_set_status_led_config(TF_EnergyMonitor *energy_monitor, uint8_t config);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Returns the configuration as set by {@link tf_energy_monitor_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_get_status_led_config(TF_EnergyMonitor *energy_monitor, uint8_t *ret_config);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_get_chip_temperature(TF_EnergyMonitor *energy_monitor, int16_t *ret_temperature);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_reset(TF_EnergyMonitor *energy_monitor);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_write_uid(TF_EnergyMonitor *energy_monitor, uint32_t uid);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_read_uid(TF_EnergyMonitor *energy_monitor, uint32_t *ret_uid);

/**
 * \ingroup BrickletEnergyMonitor
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
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_get_identity(TF_EnergyMonitor *energy_monitor, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

/**
 * \ingroup BrickletEnergyMonitor
 *
 * Returns a snapshot of the voltage and current waveform. The values
 * in the returned array alternate between voltage and current. The data from
 * one getter call contains 768 data points for voltage and current, which
 * correspond to about 3 full sine waves.
 * 
 * The voltage is given with a resolution of 100mV and the current is given
 * with a resolution of 10mA.
 * 
 * This data is meant to be used for a non-realtime graphical representation of
 * the voltage and current waveforms.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_energy_monitor_get_waveform(TF_EnergyMonitor *energy_monitor, int16_t *ret_waveform, uint16_t *ret_waveform_length);

#ifdef __cplusplus
}
#endif

#endif
