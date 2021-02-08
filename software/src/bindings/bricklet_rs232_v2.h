/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_RS232_V2_H
#define TF_BRICKLET_RS232_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletRS232V2 RS232 Bricklet 2.0
 */

struct TF_RS232V2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_RS232V2ReadLowLevelHandler)(struct TF_RS232V2 *device, uint16_t message_length, uint16_t message_chunk_offset, char message_chunk_data[60], void *user_data);
typedef void (*TF_RS232V2ErrorCountHandler)(struct TF_RS232V2 *device, uint32_t error_count_overrun, uint32_t error_count_parity, void *user_data);
typedef void (*TF_RS232V2FrameReadableHandler)(struct TF_RS232V2 *device, uint16_t frame_count, void *user_data);

#endif
/**
 * \ingroup BrickletRS232V2
 *
 * Communicates with RS232 devices
 */
typedef struct TF_RS232V2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_RS232V2ReadLowLevelHandler read_low_level_handler;
    void *read_low_level_user_data;

    TF_RS232V2ErrorCountHandler error_count_handler;
    void *error_count_user_data;

    TF_RS232V2FrameReadableHandler frame_readable_handler;
    void *frame_readable_user_data;

#endif
    uint8_t response_expected[2];
} TF_RS232V2;

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_WRITE_LOW_LEVEL 1

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_READ_LOW_LEVEL 2

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_ENABLE_READ_CALLBACK 3

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_DISABLE_READ_CALLBACK 4

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_IS_READ_CALLBACK_ENABLED 5

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_SET_CONFIGURATION 6

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_GET_CONFIGURATION 7

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_SET_BUFFER_CONFIG 8

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_GET_BUFFER_CONFIG 9

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_GET_BUFFER_STATUS 10

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_GET_ERROR_COUNT 11

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION 14

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_GET_FRAME_READABLE_CALLBACK_CONFIGURATION 15

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_CALLBACK_READ_LOW_LEVEL 12

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_CALLBACK_ERROR_COUNT 13

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_CALLBACK_FRAME_READABLE 16

#endif

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_PARITY_NONE 0

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_PARITY_ODD 1

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_PARITY_EVEN 2

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_STOPBITS_1 1

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_STOPBITS_2 2

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_WORDLENGTH_5 5

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_WORDLENGTH_6 6

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_WORDLENGTH_7 7

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_WORDLENGTH_8 8

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FLOWCONTROL_OFF 0

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FLOWCONTROL_SOFTWARE 1

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_FLOWCONTROL_HARDWARE 2

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletRS232V2
 */
#define TF_RS232_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletRS232V2
 *
 * This constant is used to identify a RS232 Bricklet 2.0.
 *
 * The {@link rs232_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_RS232_V2_DEVICE_IDENTIFIER 2108

/**
 * \ingroup BrickletRS232V2
 *
 * This constant represents the display name of a RS232 Bricklet 2.0.
 */
#define TF_RS232_V2_DEVICE_DISPLAY_NAME "RS232 Bricklet 2.0"

/**
 * \ingroup BrickletRS232V2
 *
 * Creates the device object \c rs232_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_rs232_v2_create(TF_RS232V2 *rs232_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletRS232V2
 *
 * Removes the device object \c rs232_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_rs232_v2_destroy(TF_RS232V2 *rs232_v2);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the rs232_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_get_response_expected(TF_RS232V2 *rs232_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletRS232V2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_rs232_v2_set_response_expected(TF_RS232V2 *rs232_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletRS232V2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_rs232_v2_set_response_expected_all(TF_RS232V2 *rs232_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletRS232V2
 *
 * Registers the given \c handler to the Read Low Level callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t message_length, uint16_t message_chunk_offset, char message_chunk_data[60], void *user_data) \endcode
 * 
 * This callback is called if new data is available.
 * 
 * To enable this callback, use {@link tf_rs232_v2_enable_read_callback}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs232_v2_register_read_low_level_callback(TF_RS232V2 *rs232_v2, TF_RS232V2ReadLowLevelHandler handler, void *user_data);


/**
 * \ingroup BrickletRS232V2
 *
 * Registers the given \c handler to the Error Count callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint32_t error_count_overrun, uint32_t error_count_parity, void *user_data) \endcode
 * 
 * This callback is called if a new error occurs. It returns
 * the current overrun and parity error count.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs232_v2_register_error_count_callback(TF_RS232V2 *rs232_v2, TF_RS232V2ErrorCountHandler handler, void *user_data);


/**
 * \ingroup BrickletRS232V2
 *
 * Registers the given \c handler to the Frame Readable callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t frame_count, void *user_data) \endcode
 * 
 * This callback is called if at least one frame of data is readable. The frame size is configured with {@link tf_rs232_v2_set_frame_readable_callback_configuration}.
 * The frame count parameter is the number of frames that can be read.
 * This callback is triggered only once until {@link tf_rs232_v2_read} is called. This means, that if you have configured a frame size of X bytes,
 * you can read exactly X bytes using the {@link tf_rs232_v2_read} function, every time the callback triggers without checking the frame count parameter.
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs232_v2_register_frame_readable_callback(TF_RS232V2 *rs232_v2, TF_RS232V2FrameReadableHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletRS232V2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_rs232_v2_callback_tick(TF_RS232V2 *rs232_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletRS232V2
 *
 * Writes characters to the RS232 interface. The characters can be binary data,
 * ASCII or similar is not necessary.
 * 
 * The return value is the number of characters that were written.
 * 
 * See {@link tf_rs232_v2_set_configuration} for configuration possibilities
 * regarding baud rate, parity and so on.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_write_low_level(TF_RS232V2 *rs232_v2, uint16_t message_length, uint16_t message_chunk_offset, char message_chunk_data[60], uint8_t *ret_message_chunk_written);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns up to *length* characters from receive buffer.
 * 
 * Instead of polling with this function, you can also use
 * callbacks. But note that this function will return available
 * data only when the read callback is disabled.
 * See {@link tf_rs232_v2_enable_read_callback} and {@link tf_rs232_v2_register_read_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_read_low_level(TF_RS232V2 *rs232_v2, uint16_t length, uint16_t *ret_message_length, uint16_t *ret_message_chunk_offset, char ret_message_chunk_data[60]);

/**
 * \ingroup BrickletRS232V2
 *
 * Enables the {@link tf_rs232_v2_register_read_callback} callback. This will disable the {@link tf_rs232_v2_register_frame_readable_callback} callback.
 * 
 * By default the callback is disabled.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_enable_read_callback(TF_RS232V2 *rs232_v2);

/**
 * \ingroup BrickletRS232V2
 *
 * Disables the {@link tf_rs232_v2_register_read_callback} callback.
 * 
 * By default the callback is disabled.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_disable_read_callback(TF_RS232V2 *rs232_v2);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns *true* if the {@link tf_rs232_v2_register_read_callback} callback is enabled,
 * *false* otherwise.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_is_read_callback_enabled(TF_RS232V2 *rs232_v2, bool *ret_enabled);

/**
 * \ingroup BrickletRS232V2
 *
 * Sets the configuration for the RS232 communication.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_set_configuration(TF_RS232V2 *rs232_v2, uint32_t baudrate, uint8_t parity, uint8_t stopbits, uint8_t wordlength, uint8_t flowcontrol);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns the configuration as set by {@link tf_rs232_v2_set_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_get_configuration(TF_RS232V2 *rs232_v2, uint32_t *ret_baudrate, uint8_t *ret_parity, uint8_t *ret_stopbits, uint8_t *ret_wordlength, uint8_t *ret_flowcontrol);

/**
 * \ingroup BrickletRS232V2
 *
 * Sets the send and receive buffer size in byte. In total the buffers have to be
 * 10240 byte (10KiB) in size, the minimum buffer size is 1024 byte (1KiB) for each.
 * 
 * The current buffer content is lost if this function is called.
 * 
 * The send buffer holds data that is given by {@link tf_rs232_v2_write} and
 * can not be written yet. The receive buffer holds data that is
 * received through RS232 but could not yet be send to the
 * user, either by {@link tf_rs232_v2_read} or through {@link tf_rs232_v2_register_read_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_set_buffer_config(TF_RS232V2 *rs232_v2, uint16_t send_buffer_size, uint16_t receive_buffer_size);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns the buffer configuration as set by {@link tf_rs232_v2_set_buffer_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_get_buffer_config(TF_RS232V2 *rs232_v2, uint16_t *ret_send_buffer_size, uint16_t *ret_receive_buffer_size);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns the currently used bytes for the send and received buffer.
 * 
 * See {@link tf_rs232_v2_set_buffer_config} for buffer size configuration.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_get_buffer_status(TF_RS232V2 *rs232_v2, uint16_t *ret_send_buffer_used, uint16_t *ret_receive_buffer_used);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns the current number of overrun and parity errors.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_get_error_count(TF_RS232V2 *rs232_v2, uint32_t *ret_error_count_overrun, uint32_t *ret_error_count_parity);

/**
 * \ingroup BrickletRS232V2
 *
 * Configures the {@link tf_rs232_v2_register_frame_readable_callback} callback. The frame size is the number of bytes, that have to be readable to trigger the callback.
 * A frame size of 0 disables the callback. A frame size greater than 0 enables the callback and disables the {@link tf_rs232_v2_register_read_callback} callback.
 * 
 * By default the callback is disabled.
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_set_frame_readable_callback_configuration(TF_RS232V2 *rs232_v2, uint16_t frame_size);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns the callback configuration as set by {@link tf_rs232_v2_set_frame_readable_callback_configuration}.
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_get_frame_readable_callback_configuration(TF_RS232V2 *rs232_v2, uint16_t *ret_frame_size);

/**
 * \ingroup BrickletRS232V2
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
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_get_spitfp_error_count(TF_RS232V2 *rs232_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletRS232V2
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
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_set_bootloader_mode(TF_RS232V2 *rs232_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns the current bootloader mode, see {@link tf_rs232_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_get_bootloader_mode(TF_RS232V2 *rs232_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletRS232V2
 *
 * Sets the firmware pointer for {@link tf_rs232_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_set_write_firmware_pointer(TF_RS232V2 *rs232_v2, uint32_t pointer);

/**
 * \ingroup BrickletRS232V2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_rs232_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_write_firmware(TF_RS232V2 *rs232_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletRS232V2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_set_status_led_config(TF_RS232V2 *rs232_v2, uint8_t config);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns the configuration as set by {@link tf_rs232_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_get_status_led_config(TF_RS232V2 *rs232_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_get_chip_temperature(TF_RS232V2 *rs232_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletRS232V2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_reset(TF_RS232V2 *rs232_v2);

/**
 * \ingroup BrickletRS232V2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_write_uid(TF_RS232V2 *rs232_v2, uint32_t uid);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_read_uid(TF_RS232V2 *rs232_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletRS232V2
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
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_get_identity(TF_RS232V2 *rs232_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

/**
 * \ingroup BrickletRS232V2
 *
 * Writes characters to the RS232 interface. The characters can be binary data,
 * ASCII or similar is not necessary.
 * 
 * The return value is the number of characters that were written.
 * 
 * See {@link tf_rs232_v2_set_configuration} for configuration possibilities
 * regarding baud rate, parity and so on.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_write(TF_RS232V2 *rs232_v2, const char *message, uint16_t message_length, uint16_t *ret_message_written);

/**
 * \ingroup BrickletRS232V2
 *
 * Returns up to *length* characters from receive buffer.
 * 
 * Instead of polling with this function, you can also use
 * callbacks. But note that this function will return available
 * data only when the read callback is disabled.
 * See {@link tf_rs232_v2_enable_read_callback} and {@link tf_rs232_v2_register_read_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs232_v2_read(TF_RS232V2 *rs232_v2, uint16_t length, char *ret_message, uint16_t *ret_message_length);

#ifdef __cplusplus
}
#endif

#endif
