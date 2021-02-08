/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_INDUSTRIAL_QUAD_RELAY_V2_H
#define TF_BRICKLET_INDUSTRIAL_QUAD_RELAY_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletIndustrialQuadRelayV2 Industrial Quad Relay Bricklet 2.0
 */

struct TF_IndustrialQuadRelayV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_IndustrialQuadRelayV2MonoflopDoneHandler)(struct TF_IndustrialQuadRelayV2 *device, uint8_t channel, bool value, void *user_data);

#endif
/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * 4 galvanically isolated solid state relays
 */
typedef struct TF_IndustrialQuadRelayV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_IndustrialQuadRelayV2MonoflopDoneHandler monoflop_done_handler;
    void *monoflop_done_user_data;

#endif
    uint8_t response_expected[1];
} TF_IndustrialQuadRelayV2;

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_SET_VALUE 1

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_GET_VALUE 2

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_SET_MONOFLOP 3

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_GET_MONOFLOP 4

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_SET_SELECTED_VALUE 5

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_SET_CHANNEL_LED_CONFIG 6

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_GET_CHANNEL_LED_CONFIG 7

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_CALLBACK_MONOFLOP_DONE 8

#endif

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_CHANNEL_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_CHANNEL_LED_CONFIG_ON 1

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_CHANNEL_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_CHANNEL_LED_CONFIG_SHOW_CHANNEL_STATUS 3

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * This constant is used to identify a Industrial Quad Relay Bricklet 2.0.
 *
 * The {@link industrial_quad_relay_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_DEVICE_IDENTIFIER 2102

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * This constant represents the display name of a Industrial Quad Relay Bricklet 2.0.
 */
#define TF_INDUSTRIAL_QUAD_RELAY_V2_DEVICE_DISPLAY_NAME "Industrial Quad Relay Bricklet 2.0"

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Creates the device object \c industrial_quad_relay_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_industrial_quad_relay_v2_create(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Removes the device object \c industrial_quad_relay_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_industrial_quad_relay_v2_destroy(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the industrial_quad_relay_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_get_response_expected(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_industrial_quad_relay_v2_set_response_expected(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_industrial_quad_relay_v2_set_response_expected_all(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Registers the given \c handler to the Monoflop Done callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t channel, bool value, void *user_data) \endcode
 * 
 * This callback is triggered whenever a monoflop timer reaches 0. The
 * parameters contain the channel and the current value of the channel
 * (the value after the monoflop).
 */
TF_ATTRIBUTE_NONNULL(1) void tf_industrial_quad_relay_v2_register_monoflop_done_callback(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, TF_IndustrialQuadRelayV2MonoflopDoneHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_industrial_quad_relay_v2_callback_tick(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Sets the value of all four relays. A value of *true* closes the
 * relay and a value of *false* opens the relay.
 * 
 * Use {@link tf_industrial_quad_relay_v2_set_selected_value} to only change one relay.
 * 
 * All running monoflop timers will be aborted if this function is called.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_set_value(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, bool value[4]);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Returns the values as set by {@link tf_industrial_quad_relay_v2_set_value}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_get_value(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, bool ret_value[4]);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Configures a monoflop of the specified channel.
 * 
 * The second parameter is the desired value of the specified
 * channel. A *true* means relay closed and a *false* means relay open.
 * 
 * The third parameter indicates the time that the channels should hold
 * the value.
 * 
 * If this function is called with the parameters (0, 1, 1500) channel 0 will
 * close and in 1.5s channel 0 will open again
 * 
 * A monoflop can be used as a fail-safe mechanism. For example: Lets assume you
 * have a RS485 bus and a Industrial Quad Relay Bricklet 2.0 connected to one of
 * the slave stacks. You can now call this function every second, with a time
 * parameter of two seconds and channel 0 closed. Channel 0 will be closed all the
 * time. If now the RS485 connection is lost, then channel 0 will be opened in at
 * most two seconds.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_set_monoflop(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint8_t channel, bool value, uint32_t time);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Returns (for the given channel) the current value and the time as set by
 * {@link tf_industrial_quad_relay_v2_set_monoflop} as well as the remaining time until the value flips.
 * 
 * If the timer is not running currently, the remaining time will be returned
 * as 0.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_get_monoflop(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint8_t channel, bool *ret_value, uint32_t *ret_time, uint32_t *ret_time_remaining);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Sets the output value of the specified channel without affecting the other
 * channels.
 * 
 * A running monoflop timer for the specified channel will be aborted if this
 * function is called.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_set_selected_value(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint8_t channel, bool value);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Each channel has a corresponding LED. You can turn the LED off, on or show a
 * heartbeat. You can also set the LED to "Channel Status". In this mode the
 * LED is on if the channel is high and off otherwise.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_set_channel_led_config(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint8_t channel, uint8_t config);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Returns the channel LED configuration as set by {@link tf_industrial_quad_relay_v2_set_channel_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_get_channel_led_config(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint8_t channel, uint8_t *ret_config);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_get_spitfp_error_count(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_set_bootloader_mode(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Returns the current bootloader mode, see {@link tf_industrial_quad_relay_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_get_bootloader_mode(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Sets the firmware pointer for {@link tf_industrial_quad_relay_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_set_write_firmware_pointer(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint32_t pointer);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_industrial_quad_relay_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_write_firmware(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_set_status_led_config(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint8_t config);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Returns the configuration as set by {@link tf_industrial_quad_relay_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_get_status_led_config(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_get_chip_temperature(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_reset(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_write_uid(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint32_t uid);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_read_uid(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletIndustrialQuadRelayV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_industrial_quad_relay_v2_get_identity(TF_IndustrialQuadRelayV2 *industrial_quad_relay_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
