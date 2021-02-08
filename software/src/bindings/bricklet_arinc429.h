/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_ARINC429_H
#define TF_BRICKLET_ARINC429_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletARINC429 ARINC429 Bricklet
 */

struct TF_ARINC429;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_ARINC429HeartbeatHandler)(struct TF_ARINC429 *device, uint8_t seq_number, uint16_t timestamp, uint16_t frames_processed[3], uint16_t frames_lost[3], void *user_data);
typedef void (*TF_ARINC429FrameMessageHandler)(struct TF_ARINC429 *device, uint8_t channel, uint8_t seq_number, uint16_t timestamp, uint8_t frame_status, uint32_t frame, uint16_t age, void *user_data);
typedef void (*TF_ARINC429SchedulerMessageHandler)(struct TF_ARINC429 *device, uint8_t channel, uint8_t seq_number, uint16_t timestamp, uint8_t token, void *user_data);

#endif
/**
 * \ingroup BrickletARINC429
 *
 * TBD
 */
typedef struct TF_ARINC429 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_ARINC429HeartbeatHandler heartbeat_handler;
    void *heartbeat_user_data;

    TF_ARINC429FrameMessageHandler frame_message_handler;
    void *frame_message_user_data;

    TF_ARINC429SchedulerMessageHandler scheduler_message_handler;
    void *scheduler_message_user_data;

#endif
    uint8_t response_expected[2];
} TF_ARINC429;

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_GET_CAPABILITIES 1

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_SET_HEARTBEAT_CALLBACK_CONFIGURATION 2

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_GET_HEARTBEAT_CALLBACK_CONFIGURATION 3

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_SET_CHANNEL_CONFIGURATION 5

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_GET_CHANNEL_CONFIGURATION 6

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_SET_CHANNEL_MODE 7

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_GET_CHANNEL_MODE 8

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_CLEAR_ALL_RX_FILTERS 9

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_CLEAR_RX_FILTER 10

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_SET_RX_STANDARD_FILTERS 11

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_SET_RX_FILTER 12

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_GET_RX_FILTER 13

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_READ_FRAME 14

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_SET_RX_CALLBACK_CONFIGURATION 15

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_GET_RX_CALLBACK_CONFIGURATION 16

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_WRITE_FRAME_DIRECT 18

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_WRITE_FRAME_SCHEDULED 19

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_CLEAR_SCHEDULE_ENTRIES 20

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_SET_SCHEDULE_ENTRY 21

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_GET_SCHEDULE_ENTRY 22

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_RESTART 23

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_RESET 243

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CALLBACK_HEARTBEAT 4

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CALLBACK_FRAME_MESSAGE 17

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CALLBACK_SCHEDULER_MESSAGE 24

#endif

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX 0

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX1 1

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX2 2

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX3 3

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX4 4

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX5 5

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX6 6

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX7 7

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX8 8

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX9 9

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX10 10

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX11 11

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_TX12 12

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX 32

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX1 33

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX2 34

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX3 35

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX4 36

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX5 37

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX6 38

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX7 39

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX8 40

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX9 41

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX10 42

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX11 43

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_RX12 44

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SDI_SDI0 0

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SDI_SDI1 1

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SDI_SDI2 2

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SDI_SDI3 3

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SDI_DATA 4

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_PARITY_DATA 0

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_PARITY_AUTO 1

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SPEED_HS 0

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SPEED_LS 1

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_MODE_PASSIVE 0

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_MODE_ACTIVE 1

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_CHANNEL_MODE_RUN 2

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FRAME_STATUS_NEW 0

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FRAME_STATUS_UPDATE 1

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_FRAME_STATUS_TIMEOUT 1

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SCHEDULER_JOB_SKIP 0

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SCHEDULER_JOB_CALLBACK 1

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SCHEDULER_JOB_STOP 2

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SCHEDULER_JOB_JUMP 3

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SCHEDULER_JOB_RETURN 4

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SCHEDULER_JOB_DWELL 5

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SCHEDULER_JOB_SINGLE 6

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SCHEDULER_JOB_CYCLIC 7

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SCHEDULER_JOB_RETRANS_RX1 8

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_SCHEDULER_JOB_RETRANS_RX2 9

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletARINC429
 */
#define TF_ARINC429_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletARINC429
 *
 * This constant is used to identify a ARINC429 Bricklet.
 *
 * The {@link arinc429_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_ARINC429_DEVICE_IDENTIFIER 2160

/**
 * \ingroup BrickletARINC429
 *
 * This constant represents the display name of a ARINC429 Bricklet.
 */
#define TF_ARINC429_DEVICE_DISPLAY_NAME "ARINC429 Bricklet"

/**
 * \ingroup BrickletARINC429
 *
 * Creates the device object \c arinc429 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_arinc429_create(TF_ARINC429 *arinc429, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletARINC429
 *
 * Removes the device object \c arinc429 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_arinc429_destroy(TF_ARINC429 *arinc429);

/**
 * \ingroup BrickletARINC429
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the arinc429_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_response_expected(TF_ARINC429 *arinc429, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletARINC429
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
TF_ATTRIBUTE_NONNULL_ALL int tf_arinc429_set_response_expected(TF_ARINC429 *arinc429, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletARINC429
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_arinc429_set_response_expected_all(TF_ARINC429 *arinc429, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletARINC429
 *
 * Registers the given \c handler to the Heartbeat callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t seq_number, uint16_t timestamp, uint16_t frames_processed[3], uint16_t frames_lost[3], void *user_data) \endcode
 * 
 * This callback is triggered periodically according to the configuration set by
 * {@link tf_arinc429_set_heartbeat_callback_configuration}. It reports the statistics counters
 * for processed frames and lost frames for all TX and RX channels.
 *  * Seq Number:       running counter that is incremented with each callback, starting with 0 and rolling over after 255 to 1. It will restart from 0 whenever the heartbeat is turned off and on again. This counter can be used to detect lost callbacks.
 *  * Timestamp:        running counter that is incremented on every millisecond, starting when the bricklet is powered up and rolling over after 65535 to 0. This counter can be used to measure the relative timing between events.
 *  * Frames Processed: number of Arinc429 frames that are transmitted or received on the respective channels TX, RX1 and RX2.
 *  * Frames Lost:      TX channel: number of Arinc429 frames that could not be transmitted due to a full transmit buffer, RX channels: number of received Arinc429 frames that could not be reported due to a full callback buffer.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_arinc429_register_heartbeat_callback(TF_ARINC429 *arinc429, TF_ARINC429HeartbeatHandler handler, void *user_data);


/**
 * \ingroup BrickletARINC429
 *
 * Registers the given \c handler to the Frame Message callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t channel, uint8_t seq_number, uint16_t timestamp, uint8_t frame_status, uint32_t frame, uint16_t age, void *user_data) \endcode
 * 
 * This callback is triggered according to the configuration set by {@link tf_arinc429_set_rx_callback_configuration}.
 *  * Channel:      RX channel on which the frame was received.
 *  * Seq Number:   running counter that is incremented with each callback, starting with 0 and rolling over after 255 to 1. It will restart from 0 whenever the callback is turned off and on again. This counter can be used to detect lost callbacks.
 *  * Timestamp:    running counter that is incremented on every millisecond, starting when the bricklet is powered up and rolling over after 65535 to 0. This counter can be used to measure the relative timing between frame receptions.
 *  * Frame Status: 'update' signals that a new frame (new data) was received, whereas 'timeout' signals that the frame (label and SDI combination) encountered the timeout state.
 *  * Frame:        the complete Arinc429 frame including the label and SDI bits. If 'parity_auto' is set for the channel, the parity bit will always come as 0.
 *  * Age:          time in milliseconds since this frame (label + SDI combination) was received last. If not received for so far or after a previous timeout, 60000 or the timeout value set with the 'Set RX Callback Configuration' function will be returned.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_arinc429_register_frame_message_callback(TF_ARINC429 *arinc429, TF_ARINC429FrameMessageHandler handler, void *user_data);


/**
 * \ingroup BrickletARINC429
 *
 * Registers the given \c handler to the Scheduler Message callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t channel, uint8_t seq_number, uint16_t timestamp, uint8_t token, void *user_data) \endcode
 * 
 * This callback is triggered by respective jobs in the transmit schedule.
 *  * Channel:    TX channel sending the callback
 *  * Seq Number: running counter that is incremented with each callback, starting with 0 and rolling over after 255 to 1. It will restart from 0 whenever the scheduler is stopped and started again. This counter can be used to detect lost callbacks.
 *  * Timestamp:  running counter that is incremented on every millisecond, starting when the bricklet is powered up and rolling over after 65535 to 0. This counter can be used to measure the relative timing between frame receptions.
 *  * Token:      number assigned in the 'Frame Index' field when setting up the callback job.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_arinc429_register_scheduler_message_callback(TF_ARINC429 *arinc429, TF_ARINC429SchedulerMessageHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletARINC429
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_arinc429_callback_tick(TF_ARINC429 *arinc429, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletARINC429
 *
 * Get the TX and RX capabilities and their current usage:
 *  * TX Total Scheduler Jobs: total number of job entries in the scheduling table.
 *  * TX Used Scheduler Jobs:  number of job entries that are currently in use.
 *  * RX Total Frame Filters:  total number of frame filters that can be defined per channel.
 *  * RX Used Frame Filters:   number of frame filters that are currently in use per each channel.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_capabilities(TF_ARINC429 *arinc429, uint16_t *ret_tx_total_scheduler_jobs, uint16_t *ret_tx_used_scheduler_jobs, uint16_t *ret_rx_total_frame_filters, uint16_t ret_rx_used_frame_filters[2]);

/**
 * \ingroup BrickletARINC429
 *
 * Set the bricklet heartbeat which reports the statistics counters for processed frames and lost frames.
 * The period is the period with which the {@link tf_arinc429_register_heartbeat_callback} callback is triggered periodically. A value of 0 turns the callback off.
 * When 'Value Has To Change' is enabled, the heartbeat will only be sent if there is a change in the statistics numbers.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_set_heartbeat_callback_configuration(TF_ARINC429 *arinc429, uint8_t period, bool value_has_to_change);

/**
 * \ingroup BrickletARINC429
 *
 * Get the configuration of the bricklet heartbeat reporting the statistics counters.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_heartbeat_callback_configuration(TF_ARINC429 *arinc429, uint8_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletARINC429
 *
 * Set the data transmission properties of the selected channel:
 *  * Channel: channel to configure
 *  * Parity:  'parity_auto' for automatic parity adjustment, 'parity_data' for parity bit supplied by the application or if used for data.
 *  * Speed:   'speed_hs' for high speed mode (100 kbit/s), 'speed_ls' for low speed mode (12.5 kbit/s).
 * When parity set to 'parity_auto', frames received with a parity error will be counted in the lost frames counter but discarded otherwise.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_set_channel_configuration(TF_ARINC429 *arinc429, uint8_t channel, uint8_t parity, uint8_t speed);

/**
 * \ingroup BrickletARINC429
 *
 * Get the data transmission properties of the selected channel.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_channel_configuration(TF_ARINC429 *arinc429, uint8_t channel, uint8_t *ret_parity, uint8_t *ret_speed);

/**
 * \ingroup BrickletARINC429
 *
 * Set the operating mode of the selected channel:
 *  * passive: TX channel: all transmissions are stopped and the hardware interface becomes high-Z. RX channels: all arriving frames will be discarded.
 *  * active:  TX channel: Arinc429 frames can be sent via the 'Write Frame Direct' function. RX channels: arriving frames will be processed according to the frame filter and callback settings.
 *  * run:     TX channels only: the scheduler will run and transmit frames according to the entries made in the scheduler job table.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_set_channel_mode(TF_ARINC429 *arinc429, uint8_t channel, uint8_t mode);

/**
 * \ingroup BrickletARINC429
 *
 * Get the operating mode of the selected channel.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_channel_mode(TF_ARINC429 *arinc429, uint8_t channel, uint8_t *ret_mode);

/**
 * \ingroup BrickletARINC429
 *
 * Clear all receive filters on the selected RX channel.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_clear_all_rx_filters(TF_ARINC429 *arinc429, uint8_t channel);

/**
 * \ingroup BrickletARINC429
 *
 * Clear one receive filter on the selected RX channel.
 *  * Channel: selected channel.
 *  * Label:   label code of the filter.
 *  * SDI:     SDI code of the filter (SDI_SDI0 to SDI_SDI3 or SDI_DATA if SDI bits are used for data).
 *  * Success: returns 'True' if the filter was cleared or 'False' if a respective filter was not set.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_clear_rx_filter(TF_ARINC429 *arinc429, uint8_t channel, uint8_t label, uint8_t sdi, bool *ret_success);

/**
 * \ingroup BrickletARINC429
 *
 * Set a receive filter for each label value (0-255) with SDI bits set for data. Any previously existing filters will be overwritten.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_set_rx_standard_filters(TF_ARINC429 *arinc429, uint8_t channel);

/**
 * \ingroup BrickletARINC429
 *
 * Set a receive filter on the selected channel:
 *  * Channel: selected channel.
 *  * Label:   label code for the filter.
 *  * SDI:     SDI code for the filter (SDI_SDI0 to SDI_SDI3 or SDI_DATA if SDI bits are used for data).
 *  * Success: returns 'True' if the filter was set or 'False' if a respective filter could not be set up (e.g. because label + SDI collides with an already existing filter or all available filters are used up).
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_set_rx_filter(TF_ARINC429 *arinc429, uint8_t channel, uint8_t label, uint8_t sdi, bool *ret_success);

/**
 * \ingroup BrickletARINC429
 *
 * Query if a specific filter is set up or not:
 *  * Channel:    channel to query.
 *  * Label:      label code to query for.
 *  * SDI:        SDI usage to query for (SDI_SDI0 to SDI_SDI3 or SDI_DATA if SDI bits shall be used for data).
 *  * Configured: returns 'True' if the inquired filter exists, else 'False'.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_rx_filter(TF_ARINC429 *arinc429, uint8_t channel, uint8_t label, uint8_t sdi, bool *ret_configured);

/**
 * \ingroup BrickletARINC429
 *
 * Direct read of an Arinc429 frame, i.e. without using the callback mechanism.
 * In order to be able to do a direct read of a frame with a certain label and SDI combination, a respective receive filter needs to be set up beforehand.
 *  * Channel: RX channel to read from.
 *  * Label:   label code of the frame to read.
 *  * SDI:     SDI code of the frame to read (SDI_SDI0 to SDI_SDI3 or SDI_DATA if SDI bits are used for data).
 *  * Status:  returns 'True' if a respective frame was received, else 'False'.
 *  * Frame:   returns the complete Arinc429 frame including the label and SDI bits. If 'parity_auto' is set for the channel, the parity bit will always come as 0.
 *  * Age:     time in milliseconds since this frame (label + SDI combination) was received last. If not received for so far or after a previous timeout, 60000 or the timeout value set with the 'Set RX Callback Configuration' function will be returned.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_read_frame(TF_ARINC429 *arinc429, uint8_t channel, uint8_t label, uint8_t sdi, bool *ret_status, uint32_t *ret_frame, uint16_t *ret_age);

/**
 * \ingroup BrickletARINC429
 *
 * Set the configuration of the Arinc429 frame reception callback:
 *  * Channel:             selected RX channel.
 *  * Enabled:             select 'True' for activating the frame callbacks and 'False' for deactivating them.
 *  * Value Has To Change: select 'True' if callbacks shall only be sent for frames whose data have changed. With 'False' a callback will be sent on every frame reception.
 *  * Timeout:             time period for all frames (label and SDI combinations) on this channel.
 * 
 * Despite on frame reception, a callback is also generated if a frame encounters a timeout, i.e. if it is not periodically received again before the set timeout period has expired.
 * In order to have callbacks being generated at all, respective receive filters need to be set up.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_set_rx_callback_configuration(TF_ARINC429 *arinc429, uint8_t channel, bool enabled, bool value_has_to_change, uint16_t timeout);

/**
 * \ingroup BrickletARINC429
 *
 * Get the configuration of the frame reception callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_rx_callback_configuration(TF_ARINC429 *arinc429, uint8_t channel, bool *ret_enabled, bool *ret_value_has_to_change, uint16_t *ret_timeout);

/**
 * \ingroup BrickletARINC429
 *
 * Immediately transmit an Arinc429 frame:
 *  * Channel: selected transmit channel.
 *  * frame:   complete Arinc429 frame including the label and SDI bits. If 'parity_auto' is set for the channel, the parity bit will be set (adjusted) automatically.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_write_frame_direct(TF_ARINC429 *arinc429, uint8_t channel, uint32_t frame);

/**
 * \ingroup BrickletARINC429
 *
 * Set or update an Arinc429 frame that is transmitted by the scheduler using the job types 'Single' and 'Cyclic'.
 *  * Channel:     selected transmit channel.
 *  * Frame Index: index number that will be used in the transmit scheduler job table to refer to this frame.
 *  * frame:       complete Arinc429 frame including the label and SDI bits. If 'parity_auto' is set for the channel, the parity bit will be set (adjusted) automatically.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_write_frame_scheduled(TF_ARINC429 *arinc429, uint8_t channel, uint16_t frame_index, uint32_t frame);

/**
 * \ingroup BrickletARINC429
 *
 * Clear a range of transmit scheduler job table entries:
 *  * Channel: selected TX channel.
 *  * First:   index of the first table entry to be cleared.
 *  * Last:    index of the last  table entry to be cleared.
 * To clear a single entry, set 'First' and 'Last' to the one index of the one entry to be cleared.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_clear_schedule_entries(TF_ARINC429 *arinc429, uint8_t channel, uint16_t job_index_first, uint16_t job_index_last);

/**
 * \ingroup BrickletARINC429
 *
 * Set an entry in the transmit scheduler job table:
 *  * Channel:     selected TX channel
 *  * Job Index:   index number of the job, the scheduler processes the job table in ascending order of these index numbers.
 *  * Job:         activity assigned to this entry, see below.
 *  * Frame Index: generally, the frame assigned to this job by the 'Frame Index' used along with the :func: `Write Frame Scheduled`.
 *                 In case of a RX1 or RX2 retransmit job, the extended label (label + SDI) of the frame to be retransmitted.
 *                 In case of the Jump command, the Job Index at which execution shall continue.
 *                 In case of the Callback command, this number will be sent as 'Token' code (values 0-255 only).
 *                 In all other cases (Skip, Stop, Dwell, Return) this parameter is not used.
 *  * Dwell Time:  time to wait before executing the next job table entry (0-250 milliseconds).
 * 
 * When the scheduler is set to 'run' mode via the {@link tf_arinc429_set_channel_mode}, it continuously loops through the job table and executes
 * the assigned tasks. It starts with the job stored at job index 0.
 * The scheduler can execute the following activity types (jobs):
 *  * Skip:        the job is skipped, i.e. no frame is transmitted and no dwelling is done. The frame index and dwell time are not used.
 *  * Stop:        the scheduler is stopped, i.e. the channel mode is reverted from 'run' to 'active'. The frame index and dwell time are not used.
 *  * Jump:        the scheduler immediately continues at the Job Index position given by the Frame Index parameter. The assigned dwell time will be executed when the scheduler runs into the next Return job.
 *  * Return:      the scheduler immediately continues at the next Job Index position following the last Jump command. Nested Jumps are not supported. The frame index and dwell time are not used.
 *  * Callback:    the scheduler triggers a callback message and immediately continues with executing the next job (dwell time is not used).
 *  * Dwell        the scheduler executes the dwelling but does not transmit any frame. The frame index is not used.
 *  * Single:      the scheduler transmits the referenced frame, but only once. On subsequent executions the frame is not sent until it is renewed via the {@link tf_arinc429_write_frame_scheduled}, then the process repeats.
 *  * Cyclic:      the scheduler transmits the referenced frame and executed the dwelling on each round.
 *  * Retrans RX1: the scheduler retransmits a frame that was previously received on the RX1 channel. The frame to send is referenced by setting the 'Frame Index' to its extended label code, which is a 10 bit number made of the label code in the lower bits and the two SDI bits in the upper bits. If the SDI bits are used for data, set the SDI bits to zero. As long as the referenced frame was not received yet, or if it is in timeout, no frame will be sent.
 *  * Retrans RX2: same as before, but for frames received on the RX2 channel.
 * 
 * The value assigned to the 'Frame Index' parameter varies with the activity type (job):
 * 
 *  * Single or Cyclic: frame index as used with the :func: `Write Frame Scheduled` of the frame to transmit. Valid range: 0-255
 *  * Retrans RX1/RX2:  extended label (label + SDI) of the frame to re-transmit. Valid range: 0-1023
 *  * Callback:         arbitrary number decided by the user, it will be reported in the callback via the 'Token' value. Valid range: 0-255
 *  * Jump:             next job index to jump to.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_set_schedule_entry(TF_ARINC429 *arinc429, uint8_t channel, uint16_t job_index, uint8_t job, uint16_t frame_index, uint8_t dwell_time);

/**
 * \ingroup BrickletARINC429
 *
 * Get a transmit scheduler job table entry.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_schedule_entry(TF_ARINC429 *arinc429, uint8_t channel, uint16_t job_index, uint8_t *ret_job, uint16_t *ret_frame_index, uint32_t *ret_frame, uint8_t *ret_dwell_time);

/**
 * \ingroup BrickletARINC429
 *
 * Sets the whole bricklet into its power-up default state.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_restart(TF_ARINC429 *arinc429);

/**
 * \ingroup BrickletARINC429
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
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_spitfp_error_count(TF_ARINC429 *arinc429, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletARINC429
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
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_set_bootloader_mode(TF_ARINC429 *arinc429, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletARINC429
 *
 * Returns the current bootloader mode, see {@link tf_arinc429_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_bootloader_mode(TF_ARINC429 *arinc429, uint8_t *ret_mode);

/**
 * \ingroup BrickletARINC429
 *
 * Sets the firmware pointer for {@link tf_arinc429_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_set_write_firmware_pointer(TF_ARINC429 *arinc429, uint32_t pointer);

/**
 * \ingroup BrickletARINC429
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_arinc429_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_write_firmware(TF_ARINC429 *arinc429, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletARINC429
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_set_status_led_config(TF_ARINC429 *arinc429, uint8_t config);

/**
 * \ingroup BrickletARINC429
 *
 * Returns the configuration as set by {@link tf_arinc429_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_status_led_config(TF_ARINC429 *arinc429, uint8_t *ret_config);

/**
 * \ingroup BrickletARINC429
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_chip_temperature(TF_ARINC429 *arinc429, int16_t *ret_temperature);

/**
 * \ingroup BrickletARINC429
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_reset(TF_ARINC429 *arinc429);

/**
 * \ingroup BrickletARINC429
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_write_uid(TF_ARINC429 *arinc429, uint32_t uid);

/**
 * \ingroup BrickletARINC429
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_read_uid(TF_ARINC429 *arinc429, uint32_t *ret_uid);

/**
 * \ingroup BrickletARINC429
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
TF_ATTRIBUTE_NONNULL(1) int tf_arinc429_get_identity(TF_ARINC429 *arinc429, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
