/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_CAN_V2_H
#define TF_BRICKLET_CAN_V2_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletCANV2 CAN Bricklet 2.0
 */

struct TF_CANV2;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_CANV2FrameReadLowLevelHandler)(struct TF_CANV2 *device, uint8_t frame_type, uint32_t identifier, uint8_t data_length, uint8_t data_data[15], void *user_data);
typedef void (*TF_CANV2FrameReadableHandler)(struct TF_CANV2 *device, void *user_data);
typedef void (*TF_CANV2ErrorOccurredHandler)(struct TF_CANV2 *device, void *user_data);

#endif
/**
 * \ingroup BrickletCANV2
 *
 * Communicates with CAN bus devices
 */
typedef struct TF_CANV2 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_CANV2FrameReadLowLevelHandler frame_read_low_level_handler;
    void *frame_read_low_level_user_data;

    TF_CANV2FrameReadableHandler frame_readable_handler;
    void *frame_readable_user_data;

    TF_CANV2ErrorOccurredHandler error_occurred_handler;
    void *error_occurred_user_data;

#endif
    uint8_t response_expected[2];
} TF_CANV2;

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_WRITE_FRAME_LOW_LEVEL 1

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_READ_FRAME_LOW_LEVEL 2

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_SET_FRAME_READ_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_FRAME_READ_CALLBACK_CONFIGURATION 4

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_SET_TRANSCEIVER_CONFIGURATION 5

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_TRANSCEIVER_CONFIGURATION 6

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_SET_QUEUE_CONFIGURATION_LOW_LEVEL 7

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_QUEUE_CONFIGURATION_LOW_LEVEL 8

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_SET_READ_FILTER_CONFIGURATION 9

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_READ_FILTER_CONFIGURATION 10

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_ERROR_LOG_LOW_LEVEL 11

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_SET_COMMUNICATION_LED_CONFIG 12

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_COMMUNICATION_LED_CONFIG 13

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_SET_ERROR_LED_CONFIG 14

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_ERROR_LED_CONFIG 15

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION 17

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_FRAME_READABLE_CALLBACK_CONFIGURATION 18

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_SET_ERROR_OCCURRED_CALLBACK_CONFIGURATION 20

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_ERROR_OCCURRED_CALLBACK_CONFIGURATION 21

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_CALLBACK_FRAME_READ_LOW_LEVEL 16

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_CALLBACK_FRAME_READABLE 19

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_CALLBACK_ERROR_OCCURRED 22

#endif

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FRAME_TYPE_STANDARD_DATA 0

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FRAME_TYPE_STANDARD_REMOTE 1

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FRAME_TYPE_EXTENDED_DATA 2

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FRAME_TYPE_EXTENDED_REMOTE 3

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_TRANSCEIVER_MODE_NORMAL 0

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_TRANSCEIVER_MODE_LOOPBACK 1

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_TRANSCEIVER_MODE_READ_ONLY 2

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FILTER_MODE_ACCEPT_ALL 0

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FILTER_MODE_MATCH_STANDARD_ONLY 1

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FILTER_MODE_MATCH_EXTENDED_ONLY 2

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_FILTER_MODE_MATCH_STANDARD_AND_EXTENDED 3

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_TRANSCEIVER_STATE_ACTIVE 0

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_TRANSCEIVER_STATE_PASSIVE 1

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_TRANSCEIVER_STATE_DISABLED 2

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_COMMUNICATION_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_COMMUNICATION_LED_CONFIG_ON 1

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_COMMUNICATION_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_COMMUNICATION_LED_CONFIG_SHOW_COMMUNICATION 3

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_ERROR_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_ERROR_LED_CONFIG_ON 1

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_ERROR_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_ERROR_LED_CONFIG_SHOW_TRANSCEIVER_STATE 3

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_ERROR_LED_CONFIG_SHOW_ERROR 4

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletCANV2
 */
#define TF_CAN_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletCANV2
 *
 * This constant is used to identify a CAN Bricklet 2.0.
 *
 * The {@link can_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_CAN_V2_DEVICE_IDENTIFIER 2107

/**
 * \ingroup BrickletCANV2
 *
 * This constant represents the display name of a CAN Bricklet 2.0.
 */
#define TF_CAN_V2_DEVICE_DISPLAY_NAME "CAN Bricklet 2.0"

/**
 * \ingroup BrickletCANV2
 *
 * Creates the device object \c can_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_can_v2_create(TF_CANV2 *can_v2, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletCANV2
 *
 * Removes the device object \c can_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_can_v2_destroy(TF_CANV2 *can_v2);

/**
 * \ingroup BrickletCANV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the can_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_response_expected(TF_CANV2 *can_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletCANV2
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
TF_ATTRIBUTE_NONNULL_ALL int tf_can_v2_set_response_expected(TF_CANV2 *can_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletCANV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_can_v2_set_response_expected_all(TF_CANV2 *can_v2, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletCANV2
 *
 * Registers the given \c handler to the Frame Read Low Level callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t frame_type, uint32_t identifier, uint8_t data_length, uint8_t data_data[15], void *user_data) \endcode
 * 
 * This callback is triggered if a data or remote frame was received by the CAN
 * transceiver.
 * 
 * The ``identifier`` return value follows the identifier format described for
 * {@link tf_can_v2_write_frame}.
 * 
 * For details on the ``data`` return value see {@link tf_can_v2_read_frame}.
 * 
 * A configurable read filter can be used to define which frames should be
 * received by the CAN transceiver and put into the read queue (see
 * {@link tf_can_v2_set_read_filter_configuration}).
 * 
 * To enable this callback, use {@link tf_can_v2_set_frame_read_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_can_v2_register_frame_read_low_level_callback(TF_CANV2 *can_v2, TF_CANV2FrameReadLowLevelHandler handler, void *user_data);


/**
 * \ingroup BrickletCANV2
 *
 * Registers the given \c handler to the Frame Readable callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(void *user_data) \endcode
 * 
 * This callback is triggered if a data or remote frame was received by the CAN
 * transceiver. The received frame can be read with {@link tf_can_v2_read_frame}.
 * If additional frames are received, but {@link tf_can_v2_read_frame} was not called yet, the callback
 * will not trigger again.
 * 
 * A configurable read filter can be used to define which frames should be
 * received by the CAN transceiver and put into the read queue (see
 * {@link tf_can_v2_set_read_filter_configuration}).
 * 
 * To enable this callback, use {@link tf_can_v2_set_frame_readable_callback_configuration}.
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) void tf_can_v2_register_frame_readable_callback(TF_CANV2 *can_v2, TF_CANV2FrameReadableHandler handler, void *user_data);


/**
 * \ingroup BrickletCANV2
 *
 * Registers the given \c handler to the Error Occurred callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(void *user_data) \endcode
 * 
 * This callback is triggered if any error occurred while writing, reading or transmitting CAN frames.
 * 
 * The callback is only triggered once until {@link tf_can_v2_get_error_log} is called. That function will return
 * details abount the error(s) occurred.
 * 
 * To enable this callback, use {@link tf_can_v2_set_error_occurred_callback_configuration}.
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) void tf_can_v2_register_error_occurred_callback(TF_CANV2 *can_v2, TF_CANV2ErrorOccurredHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletCANV2
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_can_v2_callback_tick(TF_CANV2 *can_v2, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletCANV2
 *
 * Writes a data or remote frame to the write queue to be transmitted over the
 * CAN transceiver.
 * 
 * The Bricklet supports the standard 11-bit (CAN 2.0A) and the additional extended
 * 29-bit (CAN 2.0B) identifiers. For standard frames the Bricklet uses bit 0 to 10
 * from the ``identifier`` parameter as standard 11-bit identifier. For extended
 * frames the Bricklet uses bit 0 to 28 from the ``identifier`` parameter as
 * extended 29-bit identifier.
 * 
 * The ``data`` parameter can be up to 15 bytes long. For data frames up to 8 bytes
 * will be used as the actual data. The length (DLC) field in the data or remote
 * frame will be set to the actual length of the ``data`` parameter. This allows
 * to transmit data and remote frames with excess length. For remote frames only
 * the length of the ``data`` parameter is used. The actual ``data`` bytes are
 * ignored.
 * 
 * Returns *true* if the frame was successfully added to the write queue. Returns
 * *false* if the frame could not be added because write queue is already full or
 * because the write buffer or the write backlog are configured with a size of
 * zero (see {@link tf_can_v2_set_queue_configuration}).
 * 
 * The write queue can overflow if frames are written to it at a higher rate
 * than the Bricklet can transmitted them over the CAN transceiver. This may
 * happen if the CAN transceiver is configured as read-only or is using a low baud
 * rate (see {@link tf_can_v2_set_transceiver_configuration}). It can also happen if the CAN
 * bus is congested and the frame cannot be transmitted because it constantly loses
 * arbitration or because the CAN transceiver is currently disabled due to a high
 * write error level (see {@link tf_can_v2_get_error_log}).
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_write_frame_low_level(TF_CANV2 *can_v2, uint8_t frame_type, uint32_t identifier, uint8_t data_length, uint8_t data_data[15], bool *ret_success);

/**
 * \ingroup BrickletCANV2
 *
 * Tries to read the next data or remote frame from the read queue and returns it.
 * If a frame was successfully read, then the ``success`` return value is set to
 * *true* and the other return values contain the frame. If the read queue is
 * empty and no frame could be read, then the ``success`` return value is set to
 * *false* and the other return values contain invalid data.
 * 
 * The ``identifier`` return value follows the identifier format described for
 * {@link tf_can_v2_write_frame}.
 * 
 * The ``data`` return value can be up to 15 bytes long. For data frames up to the
 * first 8 bytes are the actual received data. All bytes after the 8th byte are
 * always zero and only there to indicate the length of a data or remote frame
 * with excess length. For remote frames the length of the ``data`` return value
 * represents the requested length. The actual ``data`` bytes are always zero.
 * 
 * A configurable read filter can be used to define which frames should be
 * received by the CAN transceiver and put into the read queue (see
 * {@link tf_can_v2_set_read_filter_configuration}).
 * 
 * Instead of polling with this function, you can also use callbacks. See the
 * {@link tf_can_v2_set_frame_read_callback_configuration} function and the {@link tf_can_v2_register_frame_read_callback}
 * callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_read_frame_low_level(TF_CANV2 *can_v2, bool *ret_success, uint8_t *ret_frame_type, uint32_t *ret_identifier, uint8_t *ret_data_length, uint8_t ret_data_data[15]);

/**
 * \ingroup BrickletCANV2
 *
 * Enables and disables the {@link tf_can_v2_register_frame_read_callback} callback.
 * 
 * By default the callback is disabled. Enabling this callback will disable the {@link tf_can_v2_register_frame_readable_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_set_frame_read_callback_configuration(TF_CANV2 *can_v2, bool enabled);

/**
 * \ingroup BrickletCANV2
 *
 * Returns *true* if the {@link tf_can_v2_register_frame_read_callback} callback is enabled, *false* otherwise.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_frame_read_callback_configuration(TF_CANV2 *can_v2, bool *ret_enabled);

/**
 * \ingroup BrickletCANV2
 *
 * Sets the transceiver configuration for the CAN bus communication.
 * 
 * The CAN transceiver has three different modes:
 * 
 * * Normal: Reads from and writes to the CAN bus and performs active bus
 *   error detection and acknowledgement.
 * * Loopback: All reads and writes are performed internally. The transceiver
 *   is disconnected from the actual CAN bus.
 * * Read-Only: Only reads from the CAN bus, but does neither active bus error
 *   detection nor acknowledgement. Only the receiving part of the transceiver
 *   is connected to the CAN bus.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_set_transceiver_configuration(TF_CANV2 *can_v2, uint32_t baud_rate, uint16_t sample_point, uint8_t transceiver_mode);

/**
 * \ingroup BrickletCANV2
 *
 * Returns the configuration as set by {@link tf_can_v2_set_transceiver_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_transceiver_configuration(TF_CANV2 *can_v2, uint32_t *ret_baud_rate, uint16_t *ret_sample_point, uint8_t *ret_transceiver_mode);

/**
 * \ingroup BrickletCANV2
 *
 * Sets the write and read queue configuration.
 * 
 * The CAN transceiver has 32 buffers in total in hardware for transmitting and
 * receiving frames. Additionally, the Bricklet has a backlog for 768 frames in
 * total in software. The buffers and the backlog can be freely assigned to the
 * write and read queues.
 * 
 * {@link tf_can_v2_write_frame} writes a frame into the write backlog. The Bricklet moves
 * the frame from the backlog into a free write buffer. The CAN transceiver then
 * transmits the frame from the write buffer to the CAN bus. If there are no
 * write buffers (``write_buffer_size`` is zero) or there is no write backlog
 * (``write_backlog_size`` is zero) then no frames can be transmitted and
 * {@link tf_can_v2_write_frame} returns always *false*.
 * 
 * The CAN transceiver receives a frame from the CAN bus and stores it into a
 * free read buffer. The Bricklet moves the frame from the read buffer into the
 * read backlog. {@link tf_can_v2_read_frame} reads the frame from the read backlog and
 * returns it. If there are no read buffers (``read_buffer_sizes`` is empty) or
 * there is no read backlog (``read_backlog_size`` is zero) then no frames can be
 * received and {@link tf_can_v2_read_frame} returns always *false*.
 * 
 * There can be multiple read buffers, because the CAN transceiver cannot receive
 * data and remote frames into the same read buffer. A positive read buffer size
 * represents a data frame read buffer and a negative read buffer size represents
 * a remote frame read buffer. A read buffer size of zero is not allowed. By
 * default the first read buffer is configured for data frames and the second read
 * buffer is configured for remote frame. There can be up to 32 different read
 * buffers, assuming that no write buffer is used. Each read buffer has its own
 * filter configuration (see {@link tf_can_v2_set_read_filter_configuration}).
 * 
 * A valid queue configuration fulfills these conditions::
 * 
 *  write_buffer_size + abs(read_buffer_size_0) + abs(read_buffer_size_1) + ... + abs(read_buffer_size_31) <= 32
 *  write_backlog_size + read_backlog_size <= 768
 * 
 * The write buffer timeout has three different modes that define how a failed
 * frame transmission should be handled:
 * 
 * * Single-Shot (< 0): Only one transmission attempt will be made. If the
 *   transmission fails then the frame is discarded.
 * * Infinite (= 0): Infinite transmission attempts will be made. The frame will
 *   never be discarded.
 * * Milliseconds (> 0): A limited number of transmission attempts will be made.
 *   If the frame could not be transmitted successfully after the configured
 *   number of milliseconds then the frame is discarded.
 * 
 * The current content of the queues is lost when this function is called.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_set_queue_configuration_low_level(TF_CANV2 *can_v2, uint8_t write_buffer_size, int32_t write_buffer_timeout, uint16_t write_backlog_size, uint8_t read_buffer_sizes_length, int8_t read_buffer_sizes_data[32], uint16_t read_backlog_size);

/**
 * \ingroup BrickletCANV2
 *
 * Returns the queue configuration as set by {@link tf_can_v2_set_queue_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_queue_configuration_low_level(TF_CANV2 *can_v2, uint8_t *ret_write_buffer_size, int32_t *ret_write_buffer_timeout, uint16_t *ret_write_backlog_size, uint8_t *ret_read_buffer_sizes_length, int8_t ret_read_buffer_sizes_data[32], uint16_t *ret_read_backlog_size);

/**
 * \ingroup BrickletCANV2
 *
 * Set the read filter configuration for the given read buffer index. This can be
 * used to define which frames should be received by the CAN transceiver and put
 * into the read buffer.
 * 
 * The read filter has four different modes that define if and how the filter mask
 * and the filter identifier are applied:
 * 
 * * Accept-All: All frames are received.
 * * Match-Standard-Only: Only standard frames with a matching identifier are
 *   received.
 * * Match-Extended-Only: Only extended frames with a matching identifier are
 *   received.
 * * Match-Standard-And-Extended: Standard and extended frames with a matching
 *   identifier are received.
 * 
 * The filter mask and filter identifier are used as bit masks. Their usage
 * depends on the mode:
 * 
 * * Accept-All: Mask and identifier are ignored.
 * * Match-Standard-Only: Bit 0 to 10 (11 bits) of filter mask and filter
 *   identifier are used to match the 11-bit identifier of standard frames.
 * * Match-Extended-Only: Bit 0 to 28 (29 bits) of filter mask and filter
 *   identifier are used to match the 29-bit identifier of extended frames.
 * * Match-Standard-And-Extended: Bit 18 to 28 (11 bits) of filter mask and filter
 *   identifier are used to match the 11-bit identifier of standard frames, bit 0
 *   to 17 (18 bits) are ignored in this case. Bit 0 to 28 (29 bits) of filter
 *   mask and filter identifier are used to match the 29-bit identifier of extended
 *   frames.
 * 
 * The filter mask and filter identifier are applied in this way: The filter mask
 * is used to select the frame identifier bits that should be compared to the
 * corresponding filter identifier bits. All unselected bits are automatically
 * accepted. All selected bits have to match the filter identifier to be accepted.
 * If all bits for the selected mode are accepted then the frame is accepted and
 * is added to the read buffer.
 * 
 * \verbatim
 *  "Filter Mask Bit", "Filter Identifier Bit", "Frame Identifier Bit", "Result"
 * 
 *  0, X, X, Accept
 *  1, 0, 0, Accept
 *  1, 0, 1, Reject
 *  1, 1, 0, Reject
 *  1, 1, 1, Accept
 * \endverbatim
 * 
 * For example, to receive standard frames with identifier 0x123 only, the mode
 * can be set to Match-Standard-Only with 0x7FF as mask and 0x123 as identifier.
 * The mask of 0x7FF selects all 11 identifier bits for matching so that the
 * identifier has to be exactly 0x123 to be accepted.
 * 
 * To accept identifier 0x123 and identifier 0x456 at the same time, just set
 * filter 2 to 0x456 and keep mask and filter 1 unchanged.
 * 
 * There can be up to 32 different read filters configured at the same time,
 * because there can be up to 32 read buffer (see {@link tf_can_v2_set_queue_configuration}).
 * 
 * The default mode is accept-all for all read buffers.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_set_read_filter_configuration(TF_CANV2 *can_v2, uint8_t buffer_index, uint8_t filter_mode, uint32_t filter_mask, uint32_t filter_identifier);

/**
 * \ingroup BrickletCANV2
 *
 * Returns the read filter configuration as set by {@link tf_can_v2_set_read_filter_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_read_filter_configuration(TF_CANV2 *can_v2, uint8_t buffer_index, uint8_t *ret_filter_mode, uint32_t *ret_filter_mask, uint32_t *ret_filter_identifier);

/**
 * \ingroup BrickletCANV2
 *
 * Returns information about different kinds of errors.
 * 
 * The write and read error levels indicate the current level of stuffing, form,
 * acknowledgement, bit and checksum errors during CAN bus write and read
 * operations. For each of this error kinds there is also an individual counter.
 * 
 * When the write error level extends 255 then the CAN transceiver gets disabled
 * and no frames can be transmitted or received anymore. The CAN transceiver will
 * automatically be activated again after the CAN bus is idle for a while.
 * 
 * The write buffer timeout, read buffer and backlog overflow counts represents the
 * number of these errors:
 * 
 * * A write buffer timeout occurs if a frame could not be transmitted before the
 *   configured write buffer timeout expired (see {@link tf_can_v2_set_queue_configuration}).
 * * A read buffer overflow occurs if a read buffer of the CAN transceiver
 *   still contains the last received frame when the next frame arrives. In this
 *   case the last received frame is lost. This happens if the CAN transceiver
 *   receives more frames than the Bricklet can handle. Using the read filter
 *   (see {@link tf_can_v2_set_read_filter_configuration}) can help to reduce the amount of
 *   received frames. This count is not exact, but a lower bound, because the
 *   Bricklet might not able detect all overflows if they occur in rapid succession.
 * * A read backlog overflow occurs if the read backlog of the Bricklet is already
 *   full when the next frame should be read from a read buffer of the CAN
 *   transceiver. In this case the frame in the read buffer is lost. This
 *   happens if the CAN transceiver receives more frames to be added to the read
 *   backlog than are removed from the read backlog using the {@link tf_can_v2_read_frame}
 *   function. Using the {@link tf_can_v2_register_frame_read_callback} callback ensures that the read backlog
 *   can not overflow.
 * 
 * The read buffer overflow counter counts the overflows of all configured read
 * buffers. Which read buffer exactly suffered from an overflow can be figured
 * out from the read buffer overflow occurrence list
 * (``read_buffer_overflow_error_occurred``). Reading the error log clears the
 * occurence list.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_error_log_low_level(TF_CANV2 *can_v2, uint8_t *ret_transceiver_state, uint8_t *ret_transceiver_write_error_level, uint8_t *ret_transceiver_read_error_level, uint32_t *ret_transceiver_stuffing_error_count, uint32_t *ret_transceiver_format_error_count, uint32_t *ret_transceiver_ack_error_count, uint32_t *ret_transceiver_bit1_error_count, uint32_t *ret_transceiver_bit0_error_count, uint32_t *ret_transceiver_crc_error_count, uint32_t *ret_write_buffer_timeout_error_count, uint32_t *ret_read_buffer_overflow_error_count, uint8_t *ret_read_buffer_overflow_error_occurred_length, bool ret_read_buffer_overflow_error_occurred_data[32], uint32_t *ret_read_backlog_overflow_error_count);

/**
 * \ingroup BrickletCANV2
 *
 * Sets the communication LED configuration. By default the LED shows
 * CAN-Bus traffic, it flickers once for every 40 transmitted or received frames.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is off.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_set_communication_led_config(TF_CANV2 *can_v2, uint8_t config);

/**
 * \ingroup BrickletCANV2
 *
 * Returns the configuration as set by {@link tf_can_v2_set_communication_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_communication_led_config(TF_CANV2 *can_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletCANV2
 *
 * Sets the error LED configuration.
 * 
 * By default (show-transceiver-state) the error LED turns on if the CAN
 * transceiver is passive or disabled state (see {@link tf_can_v2_get_error_log}). If
 * the CAN transceiver is in active state the LED turns off.
 * 
 * If the LED is configured as show-error then the error LED turns on if any error
 * occurs. If you call this function with the show-error option again, the LED will
 * turn off until the next error occurs.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is off.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_set_error_led_config(TF_CANV2 *can_v2, uint8_t config);

/**
 * \ingroup BrickletCANV2
 *
 * Returns the configuration as set by {@link tf_can_v2_set_error_led_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_error_led_config(TF_CANV2 *can_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletCANV2
 *
 * Enables and disables the {@link tf_can_v2_register_frame_readable_callback} callback.
 * 
 * By default the callback is disabled. Enabling this callback will disable the {@link tf_can_v2_register_frame_read_callback} callback.
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_set_frame_readable_callback_configuration(TF_CANV2 *can_v2, bool enabled);

/**
 * \ingroup BrickletCANV2
 *
 * Returns *true* if the {@link tf_can_v2_register_frame_readable_callback} callback is enabled, *false* otherwise.
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_frame_readable_callback_configuration(TF_CANV2 *can_v2, bool *ret_enabled);

/**
 * \ingroup BrickletCANV2
 *
 * Enables and disables the {@link tf_can_v2_register_error_occurred_callback} callback.
 * 
 * By default the callback is disabled.
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_set_error_occurred_callback_configuration(TF_CANV2 *can_v2, bool enabled);

/**
 * \ingroup BrickletCANV2
 *
 * Returns *true* if the {@link tf_can_v2_register_error_occurred_callback} callback is enabled, *false* otherwise.
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_error_occurred_callback_configuration(TF_CANV2 *can_v2, bool *ret_enabled);

/**
 * \ingroup BrickletCANV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_spitfp_error_count(TF_CANV2 *can_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletCANV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_set_bootloader_mode(TF_CANV2 *can_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletCANV2
 *
 * Returns the current bootloader mode, see {@link tf_can_v2_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_bootloader_mode(TF_CANV2 *can_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletCANV2
 *
 * Sets the firmware pointer for {@link tf_can_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_set_write_firmware_pointer(TF_CANV2 *can_v2, uint32_t pointer);

/**
 * \ingroup BrickletCANV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_can_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_write_firmware(TF_CANV2 *can_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletCANV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_set_status_led_config(TF_CANV2 *can_v2, uint8_t config);

/**
 * \ingroup BrickletCANV2
 *
 * Returns the configuration as set by {@link tf_can_v2_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_status_led_config(TF_CANV2 *can_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletCANV2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_chip_temperature(TF_CANV2 *can_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletCANV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_reset(TF_CANV2 *can_v2);

/**
 * \ingroup BrickletCANV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_write_uid(TF_CANV2 *can_v2, uint32_t uid);

/**
 * \ingroup BrickletCANV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_read_uid(TF_CANV2 *can_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletCANV2
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
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_identity(TF_CANV2 *can_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

/**
 * \ingroup BrickletCANV2
 *
 * Writes a data or remote frame to the write queue to be transmitted over the
 * CAN transceiver.
 * 
 * The Bricklet supports the standard 11-bit (CAN 2.0A) and the additional extended
 * 29-bit (CAN 2.0B) identifiers. For standard frames the Bricklet uses bit 0 to 10
 * from the ``identifier`` parameter as standard 11-bit identifier. For extended
 * frames the Bricklet uses bit 0 to 28 from the ``identifier`` parameter as
 * extended 29-bit identifier.
 * 
 * The ``data`` parameter can be up to 15 bytes long. For data frames up to 8 bytes
 * will be used as the actual data. The length (DLC) field in the data or remote
 * frame will be set to the actual length of the ``data`` parameter. This allows
 * to transmit data and remote frames with excess length. For remote frames only
 * the length of the ``data`` parameter is used. The actual ``data`` bytes are
 * ignored.
 * 
 * Returns *true* if the frame was successfully added to the write queue. Returns
 * *false* if the frame could not be added because write queue is already full or
 * because the write buffer or the write backlog are configured with a size of
 * zero (see {@link tf_can_v2_set_queue_configuration}).
 * 
 * The write queue can overflow if frames are written to it at a higher rate
 * than the Bricklet can transmitted them over the CAN transceiver. This may
 * happen if the CAN transceiver is configured as read-only or is using a low baud
 * rate (see {@link tf_can_v2_set_transceiver_configuration}). It can also happen if the CAN
 * bus is congested and the frame cannot be transmitted because it constantly loses
 * arbitration or because the CAN transceiver is currently disabled due to a high
 * write error level (see {@link tf_can_v2_get_error_log}).
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_write_frame(TF_CANV2 *can_v2, uint8_t frame_type, uint32_t identifier, uint8_t *data, uint8_t data_length, bool *ret_success);

/**
 * \ingroup BrickletCANV2
 *
 * Tries to read the next data or remote frame from the read queue and returns it.
 * If a frame was successfully read, then the ``success`` return value is set to
 * *true* and the other return values contain the frame. If the read queue is
 * empty and no frame could be read, then the ``success`` return value is set to
 * *false* and the other return values contain invalid data.
 * 
 * The ``identifier`` return value follows the identifier format described for
 * {@link tf_can_v2_write_frame}.
 * 
 * The ``data`` return value can be up to 15 bytes long. For data frames up to the
 * first 8 bytes are the actual received data. All bytes after the 8th byte are
 * always zero and only there to indicate the length of a data or remote frame
 * with excess length. For remote frames the length of the ``data`` return value
 * represents the requested length. The actual ``data`` bytes are always zero.
 * 
 * A configurable read filter can be used to define which frames should be
 * received by the CAN transceiver and put into the read queue (see
 * {@link tf_can_v2_set_read_filter_configuration}).
 * 
 * Instead of polling with this function, you can also use callbacks. See the
 * {@link tf_can_v2_set_frame_read_callback_configuration} function and the {@link tf_can_v2_register_frame_read_callback}
 * callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_read_frame(TF_CANV2 *can_v2, bool *ret_success, uint8_t *ret_frame_type, uint32_t *ret_identifier, uint8_t *ret_data, uint8_t *ret_data_length);

/**
 * \ingroup BrickletCANV2
 *
 * Sets the write and read queue configuration.
 * 
 * The CAN transceiver has 32 buffers in total in hardware for transmitting and
 * receiving frames. Additionally, the Bricklet has a backlog for 768 frames in
 * total in software. The buffers and the backlog can be freely assigned to the
 * write and read queues.
 * 
 * {@link tf_can_v2_write_frame} writes a frame into the write backlog. The Bricklet moves
 * the frame from the backlog into a free write buffer. The CAN transceiver then
 * transmits the frame from the write buffer to the CAN bus. If there are no
 * write buffers (``write_buffer_size`` is zero) or there is no write backlog
 * (``write_backlog_size`` is zero) then no frames can be transmitted and
 * {@link tf_can_v2_write_frame} returns always *false*.
 * 
 * The CAN transceiver receives a frame from the CAN bus and stores it into a
 * free read buffer. The Bricklet moves the frame from the read buffer into the
 * read backlog. {@link tf_can_v2_read_frame} reads the frame from the read backlog and
 * returns it. If there are no read buffers (``read_buffer_sizes`` is empty) or
 * there is no read backlog (``read_backlog_size`` is zero) then no frames can be
 * received and {@link tf_can_v2_read_frame} returns always *false*.
 * 
 * There can be multiple read buffers, because the CAN transceiver cannot receive
 * data and remote frames into the same read buffer. A positive read buffer size
 * represents a data frame read buffer and a negative read buffer size represents
 * a remote frame read buffer. A read buffer size of zero is not allowed. By
 * default the first read buffer is configured for data frames and the second read
 * buffer is configured for remote frame. There can be up to 32 different read
 * buffers, assuming that no write buffer is used. Each read buffer has its own
 * filter configuration (see {@link tf_can_v2_set_read_filter_configuration}).
 * 
 * A valid queue configuration fulfills these conditions::
 * 
 *  write_buffer_size + abs(read_buffer_size_0) + abs(read_buffer_size_1) + ... + abs(read_buffer_size_31) <= 32
 *  write_backlog_size + read_backlog_size <= 768
 * 
 * The write buffer timeout has three different modes that define how a failed
 * frame transmission should be handled:
 * 
 * * Single-Shot (< 0): Only one transmission attempt will be made. If the
 *   transmission fails then the frame is discarded.
 * * Infinite (= 0): Infinite transmission attempts will be made. The frame will
 *   never be discarded.
 * * Milliseconds (> 0): A limited number of transmission attempts will be made.
 *   If the frame could not be transmitted successfully after the configured
 *   number of milliseconds then the frame is discarded.
 * 
 * The current content of the queues is lost when this function is called.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_set_queue_configuration(TF_CANV2 *can_v2, uint8_t write_buffer_size, int32_t write_buffer_timeout, uint16_t write_backlog_size, int8_t *read_buffer_sizes, uint8_t read_buffer_sizes_length, uint16_t read_backlog_size);

/**
 * \ingroup BrickletCANV2
 *
 * Returns the queue configuration as set by {@link tf_can_v2_set_queue_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_queue_configuration(TF_CANV2 *can_v2, uint8_t *ret_write_buffer_size, int32_t *ret_write_buffer_timeout, uint16_t *ret_write_backlog_size, int8_t *ret_read_buffer_sizes, uint8_t *ret_read_buffer_sizes_length, uint16_t *ret_read_backlog_size);

/**
 * \ingroup BrickletCANV2
 *
 * Returns information about different kinds of errors.
 * 
 * The write and read error levels indicate the current level of stuffing, form,
 * acknowledgement, bit and checksum errors during CAN bus write and read
 * operations. For each of this error kinds there is also an individual counter.
 * 
 * When the write error level extends 255 then the CAN transceiver gets disabled
 * and no frames can be transmitted or received anymore. The CAN transceiver will
 * automatically be activated again after the CAN bus is idle for a while.
 * 
 * The write buffer timeout, read buffer and backlog overflow counts represents the
 * number of these errors:
 * 
 * * A write buffer timeout occurs if a frame could not be transmitted before the
 *   configured write buffer timeout expired (see {@link tf_can_v2_set_queue_configuration}).
 * * A read buffer overflow occurs if a read buffer of the CAN transceiver
 *   still contains the last received frame when the next frame arrives. In this
 *   case the last received frame is lost. This happens if the CAN transceiver
 *   receives more frames than the Bricklet can handle. Using the read filter
 *   (see {@link tf_can_v2_set_read_filter_configuration}) can help to reduce the amount of
 *   received frames. This count is not exact, but a lower bound, because the
 *   Bricklet might not able detect all overflows if they occur in rapid succession.
 * * A read backlog overflow occurs if the read backlog of the Bricklet is already
 *   full when the next frame should be read from a read buffer of the CAN
 *   transceiver. In this case the frame in the read buffer is lost. This
 *   happens if the CAN transceiver receives more frames to be added to the read
 *   backlog than are removed from the read backlog using the {@link tf_can_v2_read_frame}
 *   function. Using the {@link tf_can_v2_register_frame_read_callback} callback ensures that the read backlog
 *   can not overflow.
 * 
 * The read buffer overflow counter counts the overflows of all configured read
 * buffers. Which read buffer exactly suffered from an overflow can be figured
 * out from the read buffer overflow occurrence list
 * (``read_buffer_overflow_error_occurred``). Reading the error log clears the
 * occurence list.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_can_v2_get_error_log(TF_CANV2 *can_v2, uint8_t *ret_transceiver_state, uint8_t *ret_transceiver_write_error_level, uint8_t *ret_transceiver_read_error_level, uint32_t *ret_transceiver_stuffing_error_count, uint32_t *ret_transceiver_format_error_count, uint32_t *ret_transceiver_ack_error_count, uint32_t *ret_transceiver_bit1_error_count, uint32_t *ret_transceiver_bit0_error_count, uint32_t *ret_transceiver_crc_error_count, uint32_t *ret_write_buffer_timeout_error_count, uint32_t *ret_read_buffer_overflow_error_count, bool *ret_read_buffer_overflow_error_occurred, uint8_t *ret_read_buffer_overflow_error_occurred_length, uint32_t *ret_read_backlog_overflow_error_count);

#ifdef __cplusplus
}
#endif

#endif
