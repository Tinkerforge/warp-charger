/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_OUTDOOR_WEATHER_H
#define TF_BRICKLET_OUTDOOR_WEATHER_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletOutdoorWeather Outdoor Weather Bricklet
 */

struct TF_OutdoorWeather;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_OutdoorWeatherStationDataHandler)(struct TF_OutdoorWeather *device, uint8_t identifier, int16_t temperature, uint8_t humidity, uint32_t wind_speed, uint32_t gust_speed, uint32_t rain, uint8_t wind_direction, bool battery_low, void *user_data);
typedef void (*TF_OutdoorWeatherSensorDataHandler)(struct TF_OutdoorWeather *device, uint8_t identifier, int16_t temperature, uint8_t humidity, void *user_data);

#endif
/**
 * \ingroup BrickletOutdoorWeather
 *
 * 433MHz receiver for outdoor weather station
 */
typedef struct TF_OutdoorWeather {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_OutdoorWeatherStationDataHandler station_data_handler;
    void *station_data_user_data;

    TF_OutdoorWeatherSensorDataHandler sensor_data_handler;
    void *sensor_data_user_data;

#endif
    uint8_t response_expected[1];
} TF_OutdoorWeather;

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_GET_STATION_IDENTIFIERS_LOW_LEVEL 1

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_GET_SENSOR_IDENTIFIERS_LOW_LEVEL 2

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_GET_STATION_DATA 3

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_GET_SENSOR_DATA 4

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_SET_STATION_CALLBACK_CONFIGURATION 5

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_GET_STATION_CALLBACK_CONFIGURATION 6

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_SET_SENSOR_CALLBACK_CONFIGURATION 7

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_GET_SENSOR_CALLBACK_CONFIGURATION 8

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_RESET 243

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_CALLBACK_STATION_DATA 9

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_CALLBACK_SENSOR_DATA 10

#endif

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_N 0

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_NNE 1

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_NE 2

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_ENE 3

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_E 4

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_ESE 5

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_SE 6

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_SSE 7

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_S 8

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_SSW 9

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_SW 10

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_WSW 11

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_W 12

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_WNW 13

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_NW 14

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_NNW 15

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_WIND_DIRECTION_ERROR 255

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletOutdoorWeather
 */
#define TF_OUTDOOR_WEATHER_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletOutdoorWeather
 *
 * This constant is used to identify a Outdoor Weather Bricklet.
 *
 * The {@link outdoor_weather_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_OUTDOOR_WEATHER_DEVICE_IDENTIFIER 288

/**
 * \ingroup BrickletOutdoorWeather
 *
 * This constant represents the display name of a Outdoor Weather Bricklet.
 */
#define TF_OUTDOOR_WEATHER_DEVICE_DISPLAY_NAME "Outdoor Weather Bricklet"

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Creates the device object \c outdoor_weather with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_outdoor_weather_create(TF_OutdoorWeather *outdoor_weather, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Removes the device object \c outdoor_weather from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_outdoor_weather_destroy(TF_OutdoorWeather *outdoor_weather);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the outdoor_weather_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_response_expected(TF_OutdoorWeather *outdoor_weather, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletOutdoorWeather
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
TF_ATTRIBUTE_NONNULL_ALL int tf_outdoor_weather_set_response_expected(TF_OutdoorWeather *outdoor_weather, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_outdoor_weather_set_response_expected_all(TF_OutdoorWeather *outdoor_weather, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletOutdoorWeather
 *
 * Registers the given \c handler to the Station Data callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t identifier, int16_t temperature, uint8_t humidity, uint32_t wind_speed, uint32_t gust_speed, uint32_t rain, uint8_t wind_direction, bool battery_low, void *user_data) \endcode
 * 
 * Reports the station data every time a new data packet is received.
 * See {@link tf_outdoor_weather_get_station_data} for information about the data.
 * 
 * For each station the callback will be triggered about every 45 seconds.
 * 
 * Turn the callback on/off with {@link tf_outdoor_weather_set_station_callback_configuration}
 * (by default it is turned off).
 */
TF_ATTRIBUTE_NONNULL(1) void tf_outdoor_weather_register_station_data_callback(TF_OutdoorWeather *outdoor_weather, TF_OutdoorWeatherStationDataHandler handler, void *user_data);


/**
 * \ingroup BrickletOutdoorWeather
 *
 * Registers the given \c handler to the Sensor Data callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t identifier, int16_t temperature, uint8_t humidity, void *user_data) \endcode
 * 
 * Reports the sensor data every time a new data packet is received.
 * See {@link tf_outdoor_weather_get_sensor_data} for information about the data.
 * 
 * For each sensor the callback will be called about every 45 seconds.
 * 
 * Turn the callback on/off with {@link tf_outdoor_weather_set_sensor_callback_configuration}
 * (by default it is turned off).
 */
TF_ATTRIBUTE_NONNULL(1) void tf_outdoor_weather_register_sensor_data_callback(TF_OutdoorWeather *outdoor_weather, TF_OutdoorWeatherSensorDataHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletOutdoorWeather
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_outdoor_weather_callback_tick(TF_OutdoorWeather *outdoor_weather, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the identifiers (number between 0 and 255) of all `stations
 * <https://www.tinkerforge.com/en/shop/accessories/sensors/outdoor-weather-station-ws-6147.html>`__
 * that have been seen since the startup of the Bricklet.
 * 
 * Each station gives itself a random identifier on first startup.
 * 
 * Since firmware version 2.0.2 a station is removed from the list if no data was received for
 * 12 hours.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_station_identifiers_low_level(TF_OutdoorWeather *outdoor_weather, uint16_t *ret_identifiers_length, uint16_t *ret_identifiers_chunk_offset, uint8_t ret_identifiers_chunk_data[60]);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the identifiers (number between 0 and 255) of all `sensors
 * <https://www.tinkerforge.com/en/shop/accessories/sensors/temperature-humidity-sensor-th-6148.html>`__
 * that have been seen since the startup of the Bricklet.
 * 
 * Each sensor gives itself a random identifier on first startup.
 * 
 * Since firmware version 2.0.2 a sensor is removed from the list if no data was received for
 * 12 hours.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_sensor_identifiers_low_level(TF_OutdoorWeather *outdoor_weather, uint16_t *ret_identifiers_length, uint16_t *ret_identifiers_chunk_offset, uint8_t ret_identifiers_chunk_data[60]);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the last received data for a station with the given identifier.
 * Call {@link tf_outdoor_weather_get_station_identifiers} for a list of all available identifiers.
 * 
 * The return values are:
 * 
 * * Temperature,
 * * Humidity,
 * * Wind Speed,
 * * Gust Speed,
 * * Rain Fall (accumulated since station power-up),
 * * Wind Direction,
 * * Battery Low (true if battery is low) and
 * * Last Change (seconds since the reception of this data).
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_station_data(TF_OutdoorWeather *outdoor_weather, uint8_t identifier, int16_t *ret_temperature, uint8_t *ret_humidity, uint32_t *ret_wind_speed, uint32_t *ret_gust_speed, uint32_t *ret_rain, uint8_t *ret_wind_direction, bool *ret_battery_low, uint16_t *ret_last_change);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the last measured data for a sensor with the given identifier.
 * Call {@link tf_outdoor_weather_get_sensor_identifiers} for a list of all available identifiers.
 * 
 * The return values are:
 * 
 * * Temperature,
 * * Humidity and
 * * Last Change (seconds since the last reception of data).
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_sensor_data(TF_OutdoorWeather *outdoor_weather, uint8_t identifier, int16_t *ret_temperature, uint8_t *ret_humidity, uint16_t *ret_last_change);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Turns callback for station data on or off.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_set_station_callback_configuration(TF_OutdoorWeather *outdoor_weather, bool enable_callback);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the configuration as set by {@link tf_outdoor_weather_set_station_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_station_callback_configuration(TF_OutdoorWeather *outdoor_weather, bool *ret_enable_callback);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Turns callback for sensor data on or off.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_set_sensor_callback_configuration(TF_OutdoorWeather *outdoor_weather, bool enable_callback);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the configuration as set by {@link tf_outdoor_weather_set_sensor_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_sensor_callback_configuration(TF_OutdoorWeather *outdoor_weather, bool *ret_enable_callback);

/**
 * \ingroup BrickletOutdoorWeather
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
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_spitfp_error_count(TF_OutdoorWeather *outdoor_weather, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletOutdoorWeather
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
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_set_bootloader_mode(TF_OutdoorWeather *outdoor_weather, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the current bootloader mode, see {@link tf_outdoor_weather_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_bootloader_mode(TF_OutdoorWeather *outdoor_weather, uint8_t *ret_mode);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Sets the firmware pointer for {@link tf_outdoor_weather_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_set_write_firmware_pointer(TF_OutdoorWeather *outdoor_weather, uint32_t pointer);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_outdoor_weather_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_write_firmware(TF_OutdoorWeather *outdoor_weather, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_set_status_led_config(TF_OutdoorWeather *outdoor_weather, uint8_t config);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the configuration as set by {@link tf_outdoor_weather_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_status_led_config(TF_OutdoorWeather *outdoor_weather, uint8_t *ret_config);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_chip_temperature(TF_OutdoorWeather *outdoor_weather, int16_t *ret_temperature);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_reset(TF_OutdoorWeather *outdoor_weather);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_write_uid(TF_OutdoorWeather *outdoor_weather, uint32_t uid);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_read_uid(TF_OutdoorWeather *outdoor_weather, uint32_t *ret_uid);

/**
 * \ingroup BrickletOutdoorWeather
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
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_identity(TF_OutdoorWeather *outdoor_weather, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the identifiers (number between 0 and 255) of all `stations
 * <https://www.tinkerforge.com/en/shop/accessories/sensors/outdoor-weather-station-ws-6147.html>`__
 * that have been seen since the startup of the Bricklet.
 * 
 * Each station gives itself a random identifier on first startup.
 * 
 * Since firmware version 2.0.2 a station is removed from the list if no data was received for
 * 12 hours.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_station_identifiers(TF_OutdoorWeather *outdoor_weather, uint8_t *ret_identifiers, uint16_t *ret_identifiers_length);

/**
 * \ingroup BrickletOutdoorWeather
 *
 * Returns the identifiers (number between 0 and 255) of all `sensors
 * <https://www.tinkerforge.com/en/shop/accessories/sensors/temperature-humidity-sensor-th-6148.html>`__
 * that have been seen since the startup of the Bricklet.
 * 
 * Each sensor gives itself a random identifier on first startup.
 * 
 * Since firmware version 2.0.2 a sensor is removed from the list if no data was received for
 * 12 hours.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_outdoor_weather_get_sensor_identifiers(TF_OutdoorWeather *outdoor_weather, uint8_t *ret_identifiers, uint16_t *ret_identifiers_length);

#ifdef __cplusplus
}
#endif

#endif
