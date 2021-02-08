/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_UNKNOWN_H
#define TF_BRICKLET_UNKNOWN_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletUnknown Unknown Bricklet
 */

struct TF_Unknown;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_UnknownEnumerateHandler)(struct TF_Unknown *device, char uid[8], char connected_uid[8], char position, uint8_t hardware_version[3], uint8_t firmware_version[3], uint16_t device_identifier, uint8_t enumeration_type, void *user_data);

#endif
/**
 * \ingroup BrickletUnknown
 *
 * 
 */
typedef struct TF_Unknown {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_UnknownEnumerateHandler enumerate_handler;
    void *enumerate_user_data;

#endif
    uint8_t response_expected[1];
} TF_Unknown;

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_RESET 243

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_COMCU_ENUMERATE 252

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_ENUMERATE 254

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_CALLBACK_ENUMERATE 253

#endif

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_ENUMERATION_TYPE_AVAILABLE 0

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_ENUMERATION_TYPE_CONNECTED 1

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_ENUMERATION_TYPE_DISCONNECTED 2

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletUnknown
 */
#define TF_UNKNOWN_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletUnknown
 *
 * This constant is used to identify a Unknown Bricklet.
 *
 * The {@link unknown_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_UNKNOWN_DEVICE_IDENTIFIER -21

/**
 * \ingroup BrickletUnknown
 *
 * This constant represents the display name of a Unknown Bricklet.
 */
#define TF_UNKNOWN_DEVICE_DISPLAY_NAME "Unknown Bricklet"

/**
 * \ingroup BrickletUnknown
 *
 * Creates the device object \c unknown with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_unknown_create(TF_Unknown *unknown, const char *uid, TF_HalContext *hal, uint8_t port_id, int inventory_index);

/**
 * \ingroup BrickletUnknown
 *
 * Removes the device object \c unknown from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_unknown_destroy(TF_Unknown *unknown);

/**
 * \ingroup BrickletUnknown
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the unknown_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_get_response_expected(TF_Unknown *unknown, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletUnknown
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
TF_ATTRIBUTE_NONNULL_ALL int tf_unknown_set_response_expected(TF_Unknown *unknown, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletUnknown
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_unknown_set_response_expected_all(TF_Unknown *unknown, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletUnknown
 *
 * Registers the given \c handler to the Enumerate callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(char uid[8], char connected_uid[8], char position, uint8_t hardware_version[3], uint8_t firmware_version[3], uint16_t device_identifier, uint8_t enumeration_type, void *user_data) \endcode
 * 
 * The callback has seven parameters:
 * 
 *  * ``uid``: The UID of the device.
 *  * ``connected_uid``: UID where the device is connected to. For a Bricklet this
 *    is the UID of the Brick or Bricklet it is connected to. "0" if the Bricklet is
 *    directly connected to the calling hardware. With this information it is possible to
 *    reconstruct the complete network topology.
 *  * ``position``: 'a' - 'h' (position on Brick) or 'i' (position of the Raspberry Pi (Zero) HAT)
 *    or 'z' (Bricklet on :ref:`Isolator Bricklet <isolator_bricklet>`).
 *  * ``hardware_version``: Major, minor and release number for hardware version.
 *  * ``firmware_version``: Major, minor and release number for firmware version.
 *  * ``device_identifier``: A number that represents the device.
 *  * ``enumeration_type``: Type of enumeration.
 * 
 *  Possible enumeration types are:
 * 
 *  * Available: Device is available (enumeration
 *    triggered by user). This enumeration type can
 *    occur multiple times for the same device.
 *  * Connected: Device is newly connected
 *    (automatically send by Brick after establishing a communication connection).
 *    This indicates that the device has potentially lost its previous
 *    configuration and needs to be reconfigured.
 *  * Disconnected: Device is disconnected (only
 *    possible for USB connection). In this case only ``uid`` and
 *    ``enumeration_type`` are valid.
 * 
 *  It should be possible to implement plug-and-play functionality with this
 *  (as is done in Brick Viewer).
 */
TF_ATTRIBUTE_NONNULL(1) void tf_unknown_register_enumerate_callback(TF_Unknown *unknown, TF_UnknownEnumerateHandler handler, void *user_data);
#endif
/**
 * \ingroup BrickletUnknown
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_unknown_callback_tick(TF_Unknown *unknown, uint32_t timeout_us);

/**
 * \ingroup BrickletUnknown
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
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_get_spitfp_error_count(TF_Unknown *unknown, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletUnknown
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
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_set_bootloader_mode(TF_Unknown *unknown, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletUnknown
 *
 * Returns the current bootloader mode, see {@link tf_unknown_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_get_bootloader_mode(TF_Unknown *unknown, uint8_t *ret_mode);

/**
 * \ingroup BrickletUnknown
 *
 * Sets the firmware pointer for {@link tf_unknown_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_set_write_firmware_pointer(TF_Unknown *unknown, uint32_t pointer);

/**
 * \ingroup BrickletUnknown
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_unknown_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_write_firmware(TF_Unknown *unknown, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletUnknown
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_set_status_led_config(TF_Unknown *unknown, uint8_t config);

/**
 * \ingroup BrickletUnknown
 *
 * Returns the configuration as set by {@link tf_unknown_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_get_status_led_config(TF_Unknown *unknown, uint8_t *ret_config);

/**
 * \ingroup BrickletUnknown
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_get_chip_temperature(TF_Unknown *unknown, int16_t *ret_temperature);

/**
 * \ingroup BrickletUnknown
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_reset(TF_Unknown *unknown);

/**
 * \ingroup BrickletUnknown
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_write_uid(TF_Unknown *unknown, uint32_t uid);

/**
 * \ingroup BrickletUnknown
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_read_uid(TF_Unknown *unknown, uint32_t *ret_uid);

/**
 * \ingroup BrickletUnknown
 *
 * This function is equivalent to the normal enumerate function.
 * It is used to trigger the initial enumeration of CoMCU-Bricklets.
 * See {@link tf_unknown_register_enumerate_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_comcu_enumerate(TF_Unknown *unknown);

/**
 * \ingroup BrickletUnknown
 *
 * Broadcasts an enumerate request. All devices will respond with an {@link tf_unknown_register_enumerate_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_enumerate(TF_Unknown *unknown);

/**
 * \ingroup BrickletUnknown
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
TF_ATTRIBUTE_NONNULL(1) int tf_unknown_get_identity(TF_Unknown *unknown, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
