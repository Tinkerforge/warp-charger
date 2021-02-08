/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_RS485_H
#define TF_BRICKLET_RS485_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletRS485 RS485 Bricklet
 */

struct TF_RS485;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_RS485ReadLowLevelHandler)(struct TF_RS485 *device, uint16_t message_length, uint16_t message_chunk_offset, char message_chunk_data[60], void *user_data);
typedef void (*TF_RS485ErrorCountHandler)(struct TF_RS485 *device, uint32_t overrun_error_count, uint32_t parity_error_count, void *user_data);
typedef void (*TF_RS485ModbusSlaveReadCoilsRequestHandler)(struct TF_RS485 *device, uint8_t request_id, uint32_t starting_address, uint16_t count, void *user_data);
typedef void (*TF_RS485ModbusMasterReadCoilsResponseLowLevelHandler)(struct TF_RS485 *device, uint8_t request_id, int8_t exception_code, uint16_t coils_length, uint16_t coils_chunk_offset, bool coils_chunk_data[464], void *user_data);
typedef void (*TF_RS485ModbusSlaveReadHoldingRegistersRequestHandler)(struct TF_RS485 *device, uint8_t request_id, uint32_t starting_address, uint16_t count, void *user_data);
typedef void (*TF_RS485ModbusMasterReadHoldingRegistersResponseLowLevelHandler)(struct TF_RS485 *device, uint8_t request_id, int8_t exception_code, uint16_t holding_registers_length, uint16_t holding_registers_chunk_offset, uint16_t holding_registers_chunk_data[29], void *user_data);
typedef void (*TF_RS485ModbusSlaveWriteSingleCoilRequestHandler)(struct TF_RS485 *device, uint8_t request_id, uint32_t coil_address, bool coil_value, void *user_data);
typedef void (*TF_RS485ModbusMasterWriteSingleCoilResponseHandler)(struct TF_RS485 *device, uint8_t request_id, int8_t exception_code, void *user_data);
typedef void (*TF_RS485ModbusSlaveWriteSingleRegisterRequestHandler)(struct TF_RS485 *device, uint8_t request_id, uint32_t register_address, uint16_t register_value, void *user_data);
typedef void (*TF_RS485ModbusMasterWriteSingleRegisterResponseHandler)(struct TF_RS485 *device, uint8_t request_id, int8_t exception_code, void *user_data);
typedef void (*TF_RS485ModbusSlaveWriteMultipleCoilsRequestLowLevelHandler)(struct TF_RS485 *device, uint8_t request_id, uint32_t starting_address, uint16_t coils_length, uint16_t coils_chunk_offset, bool coils_chunk_data[440], void *user_data);
typedef void (*TF_RS485ModbusMasterWriteMultipleCoilsResponseHandler)(struct TF_RS485 *device, uint8_t request_id, int8_t exception_code, void *user_data);
typedef void (*TF_RS485ModbusSlaveWriteMultipleRegistersRequestLowLevelHandler)(struct TF_RS485 *device, uint8_t request_id, uint32_t starting_address, uint16_t registers_length, uint16_t registers_chunk_offset, uint16_t registers_chunk_data[27], void *user_data);
typedef void (*TF_RS485ModbusMasterWriteMultipleRegistersResponseHandler)(struct TF_RS485 *device, uint8_t request_id, int8_t exception_code, void *user_data);
typedef void (*TF_RS485ModbusSlaveReadDiscreteInputsRequestHandler)(struct TF_RS485 *device, uint8_t request_id, uint32_t starting_address, uint16_t count, void *user_data);
typedef void (*TF_RS485ModbusMasterReadDiscreteInputsResponseLowLevelHandler)(struct TF_RS485 *device, uint8_t request_id, int8_t exception_code, uint16_t discrete_inputs_length, uint16_t discrete_inputs_chunk_offset, bool discrete_inputs_chunk_data[464], void *user_data);
typedef void (*TF_RS485ModbusSlaveReadInputRegistersRequestHandler)(struct TF_RS485 *device, uint8_t request_id, uint32_t starting_address, uint16_t count, void *user_data);
typedef void (*TF_RS485ModbusMasterReadInputRegistersResponseLowLevelHandler)(struct TF_RS485 *device, uint8_t request_id, int8_t exception_code, uint16_t input_registers_length, uint16_t input_registers_chunk_offset, uint16_t input_registers_chunk_data[29], void *user_data);
typedef void (*TF_RS485FrameReadableHandler)(struct TF_RS485 *device, uint16_t frame_count, void *user_data);

#endif
/**
 * \ingroup BrickletRS485
 *
 * Communicates with RS485/Modbus devices with full- or half-duplex
 */
typedef struct TF_RS485 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_RS485ReadLowLevelHandler read_low_level_handler;
    void *read_low_level_user_data;

    TF_RS485ErrorCountHandler error_count_handler;
    void *error_count_user_data;

    TF_RS485ModbusSlaveReadCoilsRequestHandler modbus_slave_read_coils_request_handler;
    void *modbus_slave_read_coils_request_user_data;

    TF_RS485ModbusMasterReadCoilsResponseLowLevelHandler modbus_master_read_coils_response_low_level_handler;
    void *modbus_master_read_coils_response_low_level_user_data;

    TF_RS485ModbusSlaveReadHoldingRegistersRequestHandler modbus_slave_read_holding_registers_request_handler;
    void *modbus_slave_read_holding_registers_request_user_data;

    TF_RS485ModbusMasterReadHoldingRegistersResponseLowLevelHandler modbus_master_read_holding_registers_response_low_level_handler;
    void *modbus_master_read_holding_registers_response_low_level_user_data;

    TF_RS485ModbusSlaveWriteSingleCoilRequestHandler modbus_slave_write_single_coil_request_handler;
    void *modbus_slave_write_single_coil_request_user_data;

    TF_RS485ModbusMasterWriteSingleCoilResponseHandler modbus_master_write_single_coil_response_handler;
    void *modbus_master_write_single_coil_response_user_data;

    TF_RS485ModbusSlaveWriteSingleRegisterRequestHandler modbus_slave_write_single_register_request_handler;
    void *modbus_slave_write_single_register_request_user_data;

    TF_RS485ModbusMasterWriteSingleRegisterResponseHandler modbus_master_write_single_register_response_handler;
    void *modbus_master_write_single_register_response_user_data;

    TF_RS485ModbusSlaveWriteMultipleCoilsRequestLowLevelHandler modbus_slave_write_multiple_coils_request_low_level_handler;
    void *modbus_slave_write_multiple_coils_request_low_level_user_data;

    TF_RS485ModbusMasterWriteMultipleCoilsResponseHandler modbus_master_write_multiple_coils_response_handler;
    void *modbus_master_write_multiple_coils_response_user_data;

    TF_RS485ModbusSlaveWriteMultipleRegistersRequestLowLevelHandler modbus_slave_write_multiple_registers_request_low_level_handler;
    void *modbus_slave_write_multiple_registers_request_low_level_user_data;

    TF_RS485ModbusMasterWriteMultipleRegistersResponseHandler modbus_master_write_multiple_registers_response_handler;
    void *modbus_master_write_multiple_registers_response_user_data;

    TF_RS485ModbusSlaveReadDiscreteInputsRequestHandler modbus_slave_read_discrete_inputs_request_handler;
    void *modbus_slave_read_discrete_inputs_request_user_data;

    TF_RS485ModbusMasterReadDiscreteInputsResponseLowLevelHandler modbus_master_read_discrete_inputs_response_low_level_handler;
    void *modbus_master_read_discrete_inputs_response_low_level_user_data;

    TF_RS485ModbusSlaveReadInputRegistersRequestHandler modbus_slave_read_input_registers_request_handler;
    void *modbus_slave_read_input_registers_request_user_data;

    TF_RS485ModbusMasterReadInputRegistersResponseLowLevelHandler modbus_master_read_input_registers_response_low_level_handler;
    void *modbus_master_read_input_registers_response_low_level_user_data;

    TF_RS485FrameReadableHandler frame_readable_handler;
    void *frame_readable_user_data;

#endif
    uint8_t response_expected[3];
} TF_RS485;

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_WRITE_LOW_LEVEL 1

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_READ_LOW_LEVEL 2

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_ENABLE_READ_CALLBACK 3

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_DISABLE_READ_CALLBACK 4

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_IS_READ_CALLBACK_ENABLED 5

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_SET_RS485_CONFIGURATION 6

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_RS485_CONFIGURATION 7

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_SET_MODBUS_CONFIGURATION 8

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_MODBUS_CONFIGURATION 9

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_SET_MODE 10

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_MODE 11

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_SET_COMMUNICATION_LED_CONFIG 12

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_COMMUNICATION_LED_CONFIG 13

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_SET_ERROR_LED_CONFIG 14

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_ERROR_LED_CONFIG 15

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_SET_BUFFER_CONFIG 16

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_BUFFER_CONFIG 17

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_BUFFER_STATUS 18

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_ENABLE_ERROR_COUNT_CALLBACK 19

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_DISABLE_ERROR_COUNT_CALLBACK 20

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_IS_ERROR_COUNT_CALLBACK_ENABLED 21

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_ERROR_COUNT 22

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_MODBUS_COMMON_ERROR_COUNT 23

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_SLAVE_REPORT_EXCEPTION 24

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_COILS_REQUEST_LOW_LEVEL 25

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_MASTER_READ_COILS 26

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_HOLDING_REGISTERS_REQUEST_LOW_LEVEL 27

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_MASTER_READ_HOLDING_REGISTERS 28

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_SINGLE_COIL_REQUEST 29

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_MASTER_WRITE_SINGLE_COIL 30

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_SINGLE_REGISTER_REQUEST 31

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_MASTER_WRITE_SINGLE_REGISTER 32

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_MULTIPLE_COILS_REQUEST 33

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_MASTER_WRITE_MULTIPLE_COILS_LOW_LEVEL 34

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_MULTIPLE_REGISTERS_REQUEST 35

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_MASTER_WRITE_MULTIPLE_REGISTERS_LOW_LEVEL 36

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_DISCRETE_INPUTS_REQUEST_LOW_LEVEL 37

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_MASTER_READ_DISCRETE_INPUTS 38

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_INPUT_REGISTERS_REQUEST_LOW_LEVEL 39

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_MODBUS_MASTER_READ_INPUT_REGISTERS 40

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION 59

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_FRAME_READABLE_CALLBACK_CONFIGURATION 60

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_RESET 243

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_READ_LOW_LEVEL 41

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_ERROR_COUNT 42

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_SLAVE_READ_COILS_REQUEST 43

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_MASTER_READ_COILS_RESPONSE_LOW_LEVEL 44

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_SLAVE_READ_HOLDING_REGISTERS_REQUEST 45

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_MASTER_READ_HOLDING_REGISTERS_RESPONSE_LOW_LEVEL 46

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_SLAVE_WRITE_SINGLE_COIL_REQUEST 47

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_MASTER_WRITE_SINGLE_COIL_RESPONSE 48

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_SLAVE_WRITE_SINGLE_REGISTER_REQUEST 49

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_MASTER_WRITE_SINGLE_REGISTER_RESPONSE 50

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_SLAVE_WRITE_MULTIPLE_COILS_REQUEST_LOW_LEVEL 51

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_MASTER_WRITE_MULTIPLE_COILS_RESPONSE 52

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_SLAVE_WRITE_MULTIPLE_REGISTERS_REQUEST_LOW_LEVEL 53

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_MASTER_WRITE_MULTIPLE_REGISTERS_RESPONSE 54

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_SLAVE_READ_DISCRETE_INPUTS_REQUEST 55

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_MASTER_READ_DISCRETE_INPUTS_RESPONSE_LOW_LEVEL 56

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_SLAVE_READ_INPUT_REGISTERS_REQUEST 57

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_MODBUS_MASTER_READ_INPUT_REGISTERS_RESPONSE_LOW_LEVEL 58

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_CALLBACK_FRAME_READABLE 61

#endif

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_PARITY_NONE 0

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_PARITY_ODD 1

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_PARITY_EVEN 2

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_STOPBITS_1 1

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_STOPBITS_2 2

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_WORDLENGTH_5 5

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_WORDLENGTH_6 6

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_WORDLENGTH_7 7

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_WORDLENGTH_8 8

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_DUPLEX_HALF 0

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_DUPLEX_FULL 1

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_MODE_RS485 0

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_MODE_MODBUS_MASTER_RTU 1

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_MODE_MODBUS_SLAVE_RTU 2

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_COMMUNICATION_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_COMMUNICATION_LED_CONFIG_ON 1

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_COMMUNICATION_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_COMMUNICATION_LED_CONFIG_SHOW_COMMUNICATION 3

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_ERROR_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_ERROR_LED_CONFIG_ON 1

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_ERROR_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_ERROR_LED_CONFIG_SHOW_ERROR 3

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_EXCEPTION_CODE_TIMEOUT -1

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_EXCEPTION_CODE_SUCCESS 0

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_EXCEPTION_CODE_ILLEGAL_FUNCTION 1

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_EXCEPTION_CODE_ILLEGAL_DATA_ADDRESS 2

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_EXCEPTION_CODE_ILLEGAL_DATA_VALUE 3

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_EXCEPTION_CODE_SLAVE_DEVICE_FAILURE 4

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_EXCEPTION_CODE_ACKNOWLEDGE 5

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_EXCEPTION_CODE_SLAVE_DEVICE_BUSY 6

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_EXCEPTION_CODE_MEMORY_PARITY_ERROR 8

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_EXCEPTION_CODE_GATEWAY_PATH_UNAVAILABLE 10

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_EXCEPTION_CODE_GATEWAY_TARGET_DEVICE_FAILED_TO_RESPOND 11

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletRS485
 */
#define TF_RS485_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletRS485
 *
 * This constant is used to identify a RS485 Bricklet.
 *
 * The {@link rs485_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_RS485_DEVICE_IDENTIFIER 277

/**
 * \ingroup BrickletRS485
 *
 * This constant represents the display name of a RS485 Bricklet.
 */
#define TF_RS485_DEVICE_DISPLAY_NAME "RS485 Bricklet"

/**
 * \ingroup BrickletRS485
 *
 * Creates the device object \c rs485 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_rs485_create(TF_RS485 *rs485, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletRS485
 *
 * Removes the device object \c rs485 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_rs485_destroy(TF_RS485 *rs485);

/**
 * \ingroup BrickletRS485
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the rs485_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_response_expected(TF_RS485 *rs485, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletRS485
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
TF_ATTRIBUTE_NONNULL_ALL int tf_rs485_set_response_expected(TF_RS485 *rs485, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletRS485
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_rs485_set_response_expected_all(TF_RS485 *rs485, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Read Low Level callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t message_length, uint16_t message_chunk_offset, char message_chunk_data[60], void *user_data) \endcode
 * 
 * This callback is called if new data is available.
 * 
 * To enable this callback, use {@link tf_rs485_enable_read_callback}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_read_low_level_callback(TF_RS485 *rs485, TF_RS485ReadLowLevelHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Error Count callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint32_t overrun_error_count, uint32_t parity_error_count, void *user_data) \endcode
 * 
 * This callback is called if a new error occurs. It returns
 * the current overrun and parity error count.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_error_count_callback(TF_RS485 *rs485, TF_RS485ErrorCountHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Slave Read Coils Request callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, uint32_t starting_address, uint16_t count, void *user_data) \endcode
 * 
 * This callback is called only in Modbus slave mode when the slave receives a
 * valid request from a Modbus master to read coils. The parameters are
 * request ID of the request, the number of the first coil to be read and the number of coils to
 * be read as received by the request. The number of the first coil is called starting address for backwards compatibility reasons.
 * It is not an address, but instead a coil number in the range of 1 to 65536.
 * 
 * To send a response of this request use {@link tf_rs485_modbus_slave_answer_read_coils_request}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_slave_read_coils_request_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveReadCoilsRequestHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Master Read Coils Response Low Level callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, int8_t exception_code, uint16_t coils_length, uint16_t coils_chunk_offset, bool coils_chunk_data[464], void *user_data) \endcode
 * 
 * This callback is called only in Modbus master mode when the master receives a
 * valid response of a request to read coils.
 * 
 * The parameters are request ID
 * of the request, exception code of the response and the data as received by the
 * response.
 * 
 * Any non-zero exception code indicates a problem. If the exception code
 * is greater than 0 then the number represents a Modbus exception code. If it is
 * less than 0 then it represents other errors. For example, -1 indicates that
 * the request timed out or that the master did not receive any valid response of the
 * request within the master request timeout period as set by
 * {@link tf_rs485_set_modbus_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_master_read_coils_response_low_level_callback(TF_RS485 *rs485, TF_RS485ModbusMasterReadCoilsResponseLowLevelHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Slave Read Holding Registers Request callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, uint32_t starting_address, uint16_t count, void *user_data) \endcode
 * 
 * This callback is called only in Modbus slave mode when the slave receives a
 * valid request from a Modbus master to read holding registers. The parameters
 * are request ID of the request, the number of the first holding register to be read and the number of holding
 * registers to be read as received by the request. The number of the first holding register is called starting address for backwards compatibility reasons.
 * It is not an address, but instead a holding register number in the range of 1 to 65536. The prefix digit 4 (for holding register) is omitted.
 * 
 * To send a response of this request use {@link tf_rs485_modbus_slave_answer_read_holding_registers_request}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_slave_read_holding_registers_request_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveReadHoldingRegistersRequestHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Master Read Holding Registers Response Low Level callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, int8_t exception_code, uint16_t holding_registers_length, uint16_t holding_registers_chunk_offset, uint16_t holding_registers_chunk_data[29], void *user_data) \endcode
 * 
 * This callback is called only in Modbus master mode when the master receives a
 * valid response of a request to read holding registers.
 * 
 * The parameters are
 * request ID of the request, exception code of the response and the data as received
 * by the response.
 * 
 * Any non-zero exception code indicates a problem. If the exception
 * code is greater than 0 then the number represents a Modbus exception code. If
 * it is less than 0 then it represents other errors. For example, -1 indicates that
 * the request timed out or that the master did not receive any valid response of the
 * request within the master request timeout period as set by
 * {@link tf_rs485_set_modbus_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_master_read_holding_registers_response_low_level_callback(TF_RS485 *rs485, TF_RS485ModbusMasterReadHoldingRegistersResponseLowLevelHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Slave Write Single Coil Request callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, uint32_t coil_address, bool coil_value, void *user_data) \endcode
 * 
 * This callback is called only in Modbus slave mode when the slave receives a
 * valid request from a Modbus master to write a single coil. The parameters
 * are request ID of the request, the number of the coil and the value of coil to be
 * written as received by the request. The number of the coil is called coil address for backwards compatibility reasons.
 * It is not an address, but instead a coil number in the range of 1 to 65536.
 * 
 * To send a response of this request use {@link tf_rs485_modbus_slave_answer_write_single_coil_request}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_slave_write_single_coil_request_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveWriteSingleCoilRequestHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Master Write Single Coil Response callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, int8_t exception_code, void *user_data) \endcode
 * 
 * This callback is called only in Modbus master mode when the master receives a
 * valid response of a request to write a single coil.
 * 
 * The parameters are
 * request ID of the request and exception code of the response.
 * 
 * Any non-zero exception code indicates a problem.
 * If the exception code is greater than 0 then the number represents a Modbus
 * exception code. If it is less than 0 then it represents other errors. For
 * example, -1 indicates that the request timed out or that the master did not receive
 * any valid response of the request within the master request timeout period as set
 * by {@link tf_rs485_set_modbus_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_master_write_single_coil_response_callback(TF_RS485 *rs485, TF_RS485ModbusMasterWriteSingleCoilResponseHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Slave Write Single Register Request callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, uint32_t register_address, uint16_t register_value, void *user_data) \endcode
 * 
 * This callback is called only in Modbus slave mode when the slave receives a
 * valid request from a Modbus master to write a single holding register. The parameters
 * are request ID of the request, the number of the holding register and the register value to
 * be written as received by the request. The number of the holding register is called starting address for backwards compatibility reasons.
 * It is not an address, but instead a holding register number in the range of 1 to 65536. The prefix digit 4 (for holding register) is omitted.
 * 
 * To send a response of this request use {@link tf_rs485_modbus_slave_answer_write_single_register_request}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_slave_write_single_register_request_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveWriteSingleRegisterRequestHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Master Write Single Register Response callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, int8_t exception_code, void *user_data) \endcode
 * 
 * This callback is called only in Modbus master mode when the master receives a
 * valid response of a request to write a single register.
 * 
 * The parameters are
 * request ID of the request and exception code of the response.
 * 
 * Any non-zero exception code
 * indicates a problem. If the exception code is greater than 0 then the number
 * represents a Modbus exception code. If it is less than 0 then it represents
 * other errors. For example, -1 indicates that the request timed out or that the
 * master did not receive any valid response of the request within the master request
 * timeout period as set by {@link tf_rs485_set_modbus_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_master_write_single_register_response_callback(TF_RS485 *rs485, TF_RS485ModbusMasterWriteSingleRegisterResponseHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Slave Write Multiple Coils Request Low Level callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, uint32_t starting_address, uint16_t coils_length, uint16_t coils_chunk_offset, bool coils_chunk_data[440], void *user_data) \endcode
 * 
 * This callback is called only in Modbus slave mode when the slave receives a
 * valid request from a Modbus master to write multiple coils. The parameters
 * are request ID of the request, the number of the first coil and the data to be written as
 * received by the request. The number of the first coil is called starting address for backwards compatibility reasons.
 * It is not an address, but instead a coil number in the range of 1 to 65536.
 * 
 * To send a response of this request use {@link tf_rs485_modbus_slave_answer_write_multiple_coils_request}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_slave_write_multiple_coils_request_low_level_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveWriteMultipleCoilsRequestLowLevelHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Master Write Multiple Coils Response callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, int8_t exception_code, void *user_data) \endcode
 * 
 * This callback is called only in Modbus master mode when the master receives a
 * valid response of a request to read coils.
 * 
 * The parameters are
 * request ID of the request and exception code of the response.
 * 
 * Any non-zero exception code
 * indicates a problem. If the exception code is greater than 0 then the number
 * represents a Modbus exception code. If it is less than 0 then it represents
 * other errors. For example, -1 indicates that the request timedout or that the
 * master did not receive any valid response of the request within the master request
 * timeout period as set by {@link tf_rs485_set_modbus_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_master_write_multiple_coils_response_callback(TF_RS485 *rs485, TF_RS485ModbusMasterWriteMultipleCoilsResponseHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Slave Write Multiple Registers Request Low Level callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, uint32_t starting_address, uint16_t registers_length, uint16_t registers_chunk_offset, uint16_t registers_chunk_data[27], void *user_data) \endcode
 * 
 * This callback is called only in Modbus slave mode when the slave receives a
 * valid request from a Modbus master to write multiple holding registers. The parameters
 * are request ID of the request, the number of the first holding register and the data to be written as
 * received by the request. The number of the first holding register is called starting address for backwards compatibility reasons.
 * It is not an address, but instead a holding register number in the range of 1 to 65536. The prefix digit 4 (for holding register) is omitted.
 * 
 * To send a response of this request use {@link tf_rs485_modbus_slave_answer_write_multiple_registers_request}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_slave_write_multiple_registers_request_low_level_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveWriteMultipleRegistersRequestLowLevelHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Master Write Multiple Registers Response callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, int8_t exception_code, void *user_data) \endcode
 * 
 * This callback is called only in Modbus master mode when the master receives a
 * valid response of a request to write multiple registers.
 * 
 * The parameters
 * are request ID of the request and exception code of the response.
 * 
 * Any non-zero
 * exception code indicates a problem. If the exception code is greater than 0 then
 * the number represents a Modbus exception code. If it is less than 0 then it
 * represents other errors. For example, -1 indicates that the request timedout or
 * that the master did not receive any valid response of the request within the master
 * request timeout period as set by {@link tf_rs485_set_modbus_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_master_write_multiple_registers_response_callback(TF_RS485 *rs485, TF_RS485ModbusMasterWriteMultipleRegistersResponseHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Slave Read Discrete Inputs Request callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, uint32_t starting_address, uint16_t count, void *user_data) \endcode
 * 
 * This callback is called only in Modbus slave mode when the slave receives a
 * valid request from a Modbus master to read discrete inputs. The parameters
 * are request ID of the request, the number of the first discrete input and the number of discrete
 * inputs to be read as received by the request. The number of the first discrete input is called starting address for backwards compatibility reasons.
 * It is not an address, but instead a discrete input number in the range of 1 to 65536. The prefix digit 1 (for discrete input) is omitted.
 * 
 * To send a response of this request use {@link tf_rs485_modbus_slave_answer_read_discrete_inputs_request}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_slave_read_discrete_inputs_request_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveReadDiscreteInputsRequestHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Master Read Discrete Inputs Response Low Level callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, int8_t exception_code, uint16_t discrete_inputs_length, uint16_t discrete_inputs_chunk_offset, bool discrete_inputs_chunk_data[464], void *user_data) \endcode
 * 
 * This callback is called only in Modbus master mode when the master receives a
 * valid response of a request to read discrete inputs.
 * 
 * The parameters are
 * request ID of the request, exception code of the response and the data as received
 * by the response.
 * 
 * Any non-zero exception code indicates a problem. If the exception
 * code is greater than 0 then the number represents a Modbus exception code. If
 * it is less than 0 then it represents other errors. For example, -1 indicates that
 * the request timedout or that the master did not receive any valid response of the
 * request within the master request timeout period as set by
 * {@link tf_rs485_set_modbus_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_master_read_discrete_inputs_response_low_level_callback(TF_RS485 *rs485, TF_RS485ModbusMasterReadDiscreteInputsResponseLowLevelHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Slave Read Input Registers Request callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, uint32_t starting_address, uint16_t count, void *user_data) \endcode
 * 
 * This callback is called only in Modbus slave mode when the slave receives a
 * valid request from a Modbus master to read input registers. The parameters
 * are request ID of the request, the number of the first input register and the number of input
 * registers to be read as received by the request. The number of the first input register is called starting address for backwards compatibility reasons.
 * It is not an address, but instead a input register number in the range of 1 to 65536. The prefix digit 3 (for input register) is omitted.
 * 
 * To send a response of this request use {@link tf_rs485_modbus_slave_answer_read_input_registers_request}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_slave_read_input_registers_request_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveReadInputRegistersRequestHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Modbus Master Read Input Registers Response Low Level callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint8_t request_id, int8_t exception_code, uint16_t input_registers_length, uint16_t input_registers_chunk_offset, uint16_t input_registers_chunk_data[29], void *user_data) \endcode
 * 
 * This callback is called only in Modbus master mode when the master receives a
 * valid response of a request to read input registers.
 * 
 * The parameters are
 * request ID of the request, exception code of the response and the data as received
 * by the response.
 * 
 * Any non-zero exception code indicates a problem. If the exception
 * code is greater than 0 then the number represents a Modbus exception code. If
 * it is less than 0 then it represents other errors. For example, -1 indicates that
 * the request timedout or that the master did not receive any valid response of the
 * request within the master request timeout period as set by
 * {@link tf_rs485_set_modbus_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_modbus_master_read_input_registers_response_low_level_callback(TF_RS485 *rs485, TF_RS485ModbusMasterReadInputRegistersResponseLowLevelHandler handler, void *user_data);


/**
 * \ingroup BrickletRS485
 *
 * Registers the given \c handler to the Frame Readable callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t frame_count, void *user_data) \endcode
 * 
 * This callback is called if at least one frame of data is readable. The frame size is configured with {@link tf_rs485_set_frame_readable_callback_configuration}.
 * The frame count parameter is the number of frames that can be read.
 * This callback is triggered only once until {@link tf_rs485_read} is called. This means, that if you have configured a frame size of X bytes,
 * you can read exactly X bytes using the {@link tf_rs485_read} function, every time the callback triggers without checking the frame count parameter.
 * 
 * .. versionadded:: 2.0.5$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) void tf_rs485_register_frame_readable_callback(TF_RS485 *rs485, TF_RS485FrameReadableHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletRS485
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_rs485_callback_tick(TF_RS485 *rs485, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletRS485
 *
 * Writes characters to the RS485 interface. The characters can be binary data,
 * ASCII or similar is not necessary.
 * 
 * The return value is the number of characters that were written.
 * 
 * See {@link tf_rs485_set_rs485_configuration} for configuration possibilities
 * regarding baudrate, parity and so on.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_write_low_level(TF_RS485 *rs485, uint16_t message_length, uint16_t message_chunk_offset, char message_chunk_data[60], uint8_t *ret_message_chunk_written);

/**
 * \ingroup BrickletRS485
 *
 * Returns up to *length* characters from receive buffer.
 * 
 * Instead of polling with this function, you can also use
 * callbacks. But note that this function will return available
 * data only when the read callback is disabled.
 * See {@link tf_rs485_enable_read_callback} and {@link tf_rs485_register_read_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_read_low_level(TF_RS485 *rs485, uint16_t length, uint16_t *ret_message_length, uint16_t *ret_message_chunk_offset, char ret_message_chunk_data[60]);

/**
 * \ingroup BrickletRS485
 *
 * Enables the {@link tf_rs485_register_read_callback} callback. This will disable the {@link tf_rs485_register_frame_readable_callback} callback.
 * 
 * By default the callback is disabled.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_enable_read_callback(TF_RS485 *rs485);

/**
 * \ingroup BrickletRS485
 *
 * Disables the {@link tf_rs485_register_read_callback} callback.
 * 
 * By default the callback is disabled.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_disable_read_callback(TF_RS485 *rs485);

/**
 * \ingroup BrickletRS485
 *
 * Returns *true* if the {@link tf_rs485_register_read_callback} callback is enabled,
 * *false* otherwise.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_is_read_callback_enabled(TF_RS485 *rs485, bool *ret_enabled);

/**
 * \ingroup BrickletRS485
 *
 * Sets the configuration for the RS485 communication.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_set_rs485_configuration(TF_RS485 *rs485, uint32_t baudrate, uint8_t parity, uint8_t stopbits, uint8_t wordlength, uint8_t duplex);

/**
 * \ingroup BrickletRS485
 *
 * Returns the configuration as set by {@link tf_rs485_set_rs485_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_rs485_configuration(TF_RS485 *rs485, uint32_t *ret_baudrate, uint8_t *ret_parity, uint8_t *ret_stopbits, uint8_t *ret_wordlength, uint8_t *ret_duplex);

/**
 * \ingroup BrickletRS485
 *
 * Sets the configuration for the RS485 Modbus communication. Available options:
 * 
 * * Slave Address: Address to be used as the Modbus slave address in Modbus slave mode. Valid Modbus slave address range is 1 to 247.
 * * Master Request Timeout: Specifies how long the master should wait for a response from a slave when in Modbus master mode.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_set_modbus_configuration(TF_RS485 *rs485, uint8_t slave_address, uint32_t master_request_timeout);

/**
 * \ingroup BrickletRS485
 *
 * Returns the configuration as set by {@link tf_rs485_set_modbus_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_modbus_configuration(TF_RS485 *rs485, uint8_t *ret_slave_address, uint32_t *ret_master_request_timeout);

/**
 * \ingroup BrickletRS485
 *
 * Sets the mode of the Bricklet in which it operates. Available options are
 * 
 * * RS485,
 * * Modbus Master RTU and
 * * Modbus Slave RTU.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_set_mode(TF_RS485 *rs485, uint8_t mode);

/**
 * \ingroup BrickletRS485
 *
 * Returns the configuration as set by {@link tf_rs485_set_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_mode(TF_RS485 *rs485, uint8_t *ret_mode);

/**
 * \ingroup BrickletRS485
 *
 * Sets the communication LED configuration. By default the LED shows RS485
 * communication traffic by flickering.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is off.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_set_communication_led_config(TF_RS485 *rs485, uint8_t config);

/**
 * \ingroup BrickletRS485
 *
 * Returns the configuration as set by {@link tf_rs485_set_communication_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_communication_led_config(TF_RS485 *rs485, uint8_t *ret_config);

/**
 * \ingroup BrickletRS485
 *
 * Sets the error LED configuration.
 * 
 * By default the error LED turns on if there is any error (see {@link tf_rs485_register_error_count_callback}
 * callback). If you call this function with the SHOW ERROR option again, the LED
 * will turn off until the next error occurs.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is off.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_set_error_led_config(TF_RS485 *rs485, uint8_t config);

/**
 * \ingroup BrickletRS485
 *
 * Returns the configuration as set by {@link tf_rs485_set_error_led_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_error_led_config(TF_RS485 *rs485, uint8_t *ret_config);

/**
 * \ingroup BrickletRS485
 *
 * Sets the send and receive buffer size in byte. In sum there is
 * 10240 byte (10KiB) buffer available and the minimum buffer size
 * is 1024 byte (1KiB) for both.
 * 
 * The current buffer content is lost if this function is called.
 * 
 * The send buffer holds data that was given by {@link tf_rs485_write} and
 * could not be written yet. The receive buffer holds data that is
 * received through RS485 but could not yet be send to the
 * user, either by {@link tf_rs485_read} or through {@link tf_rs485_register_read_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_set_buffer_config(TF_RS485 *rs485, uint16_t send_buffer_size, uint16_t receive_buffer_size);

/**
 * \ingroup BrickletRS485
 *
 * Returns the buffer configuration as set by {@link tf_rs485_set_buffer_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_buffer_config(TF_RS485 *rs485, uint16_t *ret_send_buffer_size, uint16_t *ret_receive_buffer_size);

/**
 * \ingroup BrickletRS485
 *
 * Returns the currently used bytes for the send and received buffer.
 * 
 * See {@link tf_rs485_set_buffer_config} for buffer size configuration.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_buffer_status(TF_RS485 *rs485, uint16_t *ret_send_buffer_used, uint16_t *ret_receive_buffer_used);

/**
 * \ingroup BrickletRS485
 *
 * Enables the {@link tf_rs485_register_error_count_callback} callback.
 * 
 * By default the callback is disabled.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_enable_error_count_callback(TF_RS485 *rs485);

/**
 * \ingroup BrickletRS485
 *
 * Disables the {@link tf_rs485_register_error_count_callback} callback.
 * 
 * By default the callback is disabled.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_disable_error_count_callback(TF_RS485 *rs485);

/**
 * \ingroup BrickletRS485
 *
 * Returns *true* if the {@link tf_rs485_register_error_count_callback} callback is enabled,
 * *false* otherwise.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_is_error_count_callback_enabled(TF_RS485 *rs485, bool *ret_enabled);

/**
 * \ingroup BrickletRS485
 *
 * Returns the current number of overrun and parity errors.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_error_count(TF_RS485 *rs485, uint32_t *ret_overrun_error_count, uint32_t *ret_parity_error_count);

/**
 * \ingroup BrickletRS485
 *
 * Returns the current number of errors occurred in Modbus mode.
 * 
 * * Timeout Error Count: Number of timeouts occurred.
 * * Checksum Error Count: Number of failures due to Modbus frame CRC16 checksum mismatch.
 * * Frame Too Big Error Count: Number of times frames were rejected because they exceeded maximum Modbus frame size which is 256 bytes.
 * * Illegal Function Error Count: Number of errors when an unimplemented or illegal function is requested. This corresponds to Modbus exception code 1.
 * * Illegal Data Address Error Count: Number of errors due to invalid data address. This corresponds to Modbus exception code 2.
 * * Illegal Data Value Error Count: Number of errors due to invalid data value. This corresponds to Modbus exception code 3.
 * * Slave Device Failure Error Count: Number of errors occurred on the slave device which were unrecoverable. This corresponds to Modbus exception code 4.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_modbus_common_error_count(TF_RS485 *rs485, uint32_t *ret_timeout_error_count, uint32_t *ret_checksum_error_count, uint32_t *ret_frame_too_big_error_count, uint32_t *ret_illegal_function_error_count, uint32_t *ret_illegal_data_address_error_count, uint32_t *ret_illegal_data_value_error_count, uint32_t *ret_slave_device_failure_error_count);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to report a Modbus exception for
 * a Modbus master request.
 * 
 * * Request ID: Request ID of the request received by the slave.
 * * Exception Code: Modbus exception code to report to the Modbus master.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_report_exception(TF_RS485 *rs485, uint8_t request_id, int8_t exception_code);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to answer a master request to
 * read coils.
 * 
 * * Request ID: Request ID of the corresponding request that is being answered.
 * * Coils: Data that is to be sent to the Modbus master for the corresponding request.
 * 
 * This function must be called from the {@link tf_rs485_register_modbus_slave_read_coils_request_callback} callback
 * with the Request ID as provided by the argument of the callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_answer_read_coils_request_low_level(TF_RS485 *rs485, uint8_t request_id, uint16_t coils_length, uint16_t coils_chunk_offset, bool coils_chunk_data[472]);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus master mode this function can be used to read coils from a slave. This
 * function creates a Modbus function code 1 request.
 * 
 * * Slave Address: Address of the target Modbus slave.
 * * Starting Address: Number of the first coil to read. For backwards compatibility reasons this parameter is called Starting Address. It is not an address, but instead a coil number in the range of 1 to 65536.
 * * Count: Number of coils to read.
 * 
 * Upon success the function will return a non-zero request ID which will represent
 * the current request initiated by the Modbus master. In case of failure the returned
 * request ID will be 0.
 * 
 * When successful this function will also invoke the {@link tf_rs485_register_modbus_master_read_coils_response_callback}
 * callback. In this callback the Request ID provided by the callback argument must be
 * matched with the Request ID returned from this function to verify that the callback
 * is indeed for a particular request.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_master_read_coils(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t count, uint8_t *ret_request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to answer a master request to
 * read holding registers.
 * 
 * * Request ID: Request ID of the corresponding request that is being answered.
 * * Holding Registers: Data that is to be sent to the Modbus master for the corresponding request.
 * 
 * This function must be called from the {@link tf_rs485_register_modbus_slave_read_holding_registers_request_callback}
 * callback with the Request ID as provided by the argument of the callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_answer_read_holding_registers_request_low_level(TF_RS485 *rs485, uint8_t request_id, uint16_t holding_registers_length, uint16_t holding_registers_chunk_offset, uint16_t holding_registers_chunk_data[29]);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus master mode this function can be used to read holding registers from a slave.
 * This function creates a Modbus function code 3 request.
 * 
 * * Slave Address: Address of the target Modbus slave.
 * * Starting Address: Number of the first holding register to read. For backwards compatibility reasons this parameter is called Starting Address. It is not an address, but instead a holding register number in the range of 1 to 65536. The prefix digit 4 (for holding register) is implicit and must be omitted.
 * * Count: Number of holding registers to read.
 * 
 * Upon success the function will return a non-zero request ID which will represent
 * the current request initiated by the Modbus master. In case of failure the returned
 * request ID will be 0.
 * 
 * When successful this function will also invoke the {@link tf_rs485_register_modbus_master_read_holding_registers_response_callback}
 * callback. In this callback the Request ID provided by the callback argument must be matched
 * with the Request ID returned from this function to verify that the callback is indeed for a
 * particular request.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_master_read_holding_registers(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t count, uint8_t *ret_request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to answer a master request to
 * write a single coil.
 * 
 * * Request ID: Request ID of the corresponding request that is being answered.
 * 
 * This function must be called from the {@link tf_rs485_register_modbus_slave_write_single_coil_request_callback}
 * callback with the Request ID as provided by the arguments of the callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_answer_write_single_coil_request(TF_RS485 *rs485, uint8_t request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus master mode this function can be used to write a single coil of a slave.
 * This function creates a Modbus function code 5 request.
 * 
 * * Slave Address: Address of the target Modbus slave.
 * * Coil Address: Number of the coil to be written. For backwards compatibility reasons, this parameter is called Starting Address. It is not an address, but instead a coil number in the range of 1 to 65536.
 * * Coil Value: Value to be written.
 * 
 * Upon success the function will return a non-zero request ID which will represent
 * the current request initiated by the Modbus master. In case of failure the returned
 * request ID will be 0.
 * 
 * When successful this function will also invoke the {@link tf_rs485_register_modbus_master_write_single_coil_response_callback}
 * callback. In this callback the Request ID provided by the callback argument must be matched
 * with the Request ID returned from this function to verify that the callback is indeed for a
 * particular request.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_master_write_single_coil(TF_RS485 *rs485, uint8_t slave_address, uint32_t coil_address, bool coil_value, uint8_t *ret_request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to answer a master request to
 * write a single register.
 * 
 * * Request ID: Request ID of the corresponding request that is being answered.
 * 
 * This function must be called from the {@link tf_rs485_register_modbus_slave_write_single_register_request_callback}
 * callback with the Request ID, Register Address and Register Value as provided by
 * the arguments of the callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_answer_write_single_register_request(TF_RS485 *rs485, uint8_t request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus master mode this function can be used to write a single holding register of a
 * slave. This function creates a Modbus function code 6 request.
 * 
 * * Slave Address: Address of the target Modbus slave.
 * * Register Address: Number of the holding register to be written. For backwards compatibility reasons, this parameter is called Starting Address. It is not an address, but instead a holding register number in the range of 1 to 65536. The prefix digit 4 (for holding register) is implicit and must be omitted.
 * * Register Value: Value to be written.
 * 
 * Upon success the function will return a non-zero request ID which will represent
 * the current request initiated by the Modbus master. In case of failure the returned
 * request ID will be 0.
 * 
 * When successful this function will also invoke the {@link tf_rs485_register_modbus_master_write_single_register_response_callback}
 * callback. In this callback the Request ID provided by the callback argument must be matched
 * with the Request ID returned from this function to verify that the callback is indeed for a
 * particular request.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_master_write_single_register(TF_RS485 *rs485, uint8_t slave_address, uint32_t register_address, uint16_t register_value, uint8_t *ret_request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to answer a master request to
 * write multiple coils.
 * 
 * * Request ID: Request ID of the corresponding request that is being answered.
 * 
 * This function must be called from the {@link tf_rs485_register_modbus_slave_write_multiple_coils_request_callback}
 * callback with the Request ID of the callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_answer_write_multiple_coils_request(TF_RS485 *rs485, uint8_t request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus master mode this function can be used to write multiple coils of a slave.
 * This function creates a Modbus function code 15 request.
 * 
 * * Slave Address: Address of the target Modbus slave.
 * * Starting Address: Number of the first coil to write. For backwards compatibility reasons, this parameter is called Starting Address.It is not an address, but instead a coil number in the range of 1 to 65536.
 * 
 * Upon success the function will return a non-zero request ID which will represent
 * the current request initiated by the Modbus master. In case of failure the returned
 * request ID will be 0.
 * 
 * When successful this function will also invoke the {@link tf_rs485_register_modbus_master_write_multiple_coils_response_callback}
 * callback. In this callback the Request ID provided by the callback argument must be matched
 * with the Request ID returned from this function to verify that the callback is indeed for a
 * particular request.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_master_write_multiple_coils_low_level(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t coils_length, uint16_t coils_chunk_offset, bool coils_chunk_data[440], uint8_t *ret_request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to answer a master request to
 * write multiple registers.
 * 
 * * Request ID: Request ID of the corresponding request that is being answered.
 * 
 * This function must be called from the {@link tf_rs485_register_modbus_slave_write_multiple_registers_request_callback}
 * callback with the Request ID of the callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_answer_write_multiple_registers_request(TF_RS485 *rs485, uint8_t request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus master mode this function can be used to write multiple registers of a slave.
 * This function creates a Modbus function code 16 request.
 * 
 * * Slave Address: Address of the target Modbus slave.
 * * Starting Address: Number of the first holding register to write. For backwards compatibility reasons, this parameter is called Starting Address. It is not an address, but instead a holding register number in the range of 1 to 65536. The prefix digit 4 (for holding register) is implicit and must be omitted.
 * 
 * Upon success the function will return a non-zero request ID which will represent
 * the current request initiated by the Modbus master. In case of failure the returned
 * request ID will be 0.
 * 
 * When successful this function will also invoke the {@link tf_rs485_register_modbus_master_write_multiple_registers_response_callback}
 * callback. In this callback the Request ID provided by the callback argument must be matched
 * with the Request ID returned from this function to verify that the callback is indeed for a
 * particular request.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_master_write_multiple_registers_low_level(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t registers_length, uint16_t registers_chunk_offset, uint16_t registers_chunk_data[27], uint8_t *ret_request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to answer a master request to
 * read discrete inputs.
 * 
 * * Request ID: Request ID of the corresponding request that is being answered.
 * * Discrete Inputs: Data that is to be sent to the Modbus master for the corresponding request.
 * 
 * This function must be called from the {@link tf_rs485_register_modbus_slave_read_discrete_inputs_request_callback}
 * callback with the Request ID as provided by the argument of the callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_answer_read_discrete_inputs_request_low_level(TF_RS485 *rs485, uint8_t request_id, uint16_t discrete_inputs_length, uint16_t discrete_inputs_chunk_offset, bool discrete_inputs_chunk_data[472]);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus master mode this function can be used to read discrete inputs from a slave.
 * This function creates a Modbus function code 2 request.
 * 
 * * Slave Address: Address of the target Modbus slave.
 * * Starting Address: Number of the first discrete input to read. For backwards compatibility reasons, this parameter is called Starting Address. It is not an address, but instead a discrete input number in the range of 1 to 65536. The prefix digit 1 (for discrete input) is implicit and must be omitted.
 * * Count: Number of discrete inputs to read.
 * 
 * Upon success the function will return a non-zero request ID which will represent
 * the current request initiated by the Modbus master. In case of failure the returned
 * request ID will be 0.
 * 
 * When successful this function will also invoke the {@link tf_rs485_register_modbus_master_read_discrete_inputs_response_callback}
 * callback. In this callback the Request ID provided by the callback argument must be matched
 * with the Request ID returned from this function to verify that the callback is indeed for a
 * particular request.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_master_read_discrete_inputs(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t count, uint8_t *ret_request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to answer a master request to
 * read input registers.
 * 
 * * Request ID: Request ID of the corresponding request that is being answered.
 * * Input Registers: Data that is to be sent to the Modbus master for the corresponding request.
 * 
 * This function must be called from the {@link tf_rs485_register_modbus_slave_read_input_registers_request_callback} callback
 * with the Request ID as provided by the argument of the callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_answer_read_input_registers_request_low_level(TF_RS485 *rs485, uint8_t request_id, uint16_t input_registers_length, uint16_t input_registers_chunk_offset, uint16_t input_registers_chunk_data[29]);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus master mode this function can be used to read input registers from a slave.
 * This function creates a Modbus function code 4 request.
 * 
 * * Slave Address: Address of the target Modbus slave.
 * * Starting Address: Number of the first input register to read. For backwards compatibility reasons, this parameter is called Starting Address. It is not an address, but instead an input register number in the range of 1 to 65536. The prefix digit 3 (for input register) is implicit and must be omitted.
 * * Count: Number of input registers to read.
 * 
 * Upon success the function will return a non-zero request ID which will represent
 * the current request initiated by the Modbus master. In case of failure the returned
 * request ID will be 0.
 * 
 * When successful this function will also invoke the {@link tf_rs485_register_modbus_master_read_input_registers_response_callback}
 * callback. In this callback the Request ID provided by the callback argument must be matched
 * with the Request ID returned from this function to verify that the callback is indeed for a
 * particular request.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_master_read_input_registers(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t count, uint8_t *ret_request_id);

/**
 * \ingroup BrickletRS485
 *
 * Configures the {@link tf_rs485_register_frame_readable_callback} callback. The frame size is the number of bytes, that have to be readable to trigger the callback.
 * A frame size of 0 disables the callback. A frame size greater than 0 enables the callback and disables the {@link tf_rs485_register_read_callback} callback.
 * 
 * By default the callback is disabled.
 * 
 * .. versionadded:: 2.0.5$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_set_frame_readable_callback_configuration(TF_RS485 *rs485, uint16_t frame_size);

/**
 * \ingroup BrickletRS485
 *
 * Returns the callback configuration as set by {@link tf_rs485_set_frame_readable_callback_configuration}.
 * 
 * .. versionadded:: 2.0.5$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_frame_readable_callback_configuration(TF_RS485 *rs485, uint16_t *ret_frame_size);

/**
 * \ingroup BrickletRS485
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
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_spitfp_error_count(TF_RS485 *rs485, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletRS485
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
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_set_bootloader_mode(TF_RS485 *rs485, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletRS485
 *
 * Returns the current bootloader mode, see {@link tf_rs485_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_bootloader_mode(TF_RS485 *rs485, uint8_t *ret_mode);

/**
 * \ingroup BrickletRS485
 *
 * Sets the firmware pointer for {@link tf_rs485_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_set_write_firmware_pointer(TF_RS485 *rs485, uint32_t pointer);

/**
 * \ingroup BrickletRS485
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_rs485_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_write_firmware(TF_RS485 *rs485, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletRS485
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_set_status_led_config(TF_RS485 *rs485, uint8_t config);

/**
 * \ingroup BrickletRS485
 *
 * Returns the configuration as set by {@link tf_rs485_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_status_led_config(TF_RS485 *rs485, uint8_t *ret_config);

/**
 * \ingroup BrickletRS485
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_chip_temperature(TF_RS485 *rs485, int16_t *ret_temperature);

/**
 * \ingroup BrickletRS485
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_reset(TF_RS485 *rs485);

/**
 * \ingroup BrickletRS485
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_write_uid(TF_RS485 *rs485, uint32_t uid);

/**
 * \ingroup BrickletRS485
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_read_uid(TF_RS485 *rs485, uint32_t *ret_uid);

/**
 * \ingroup BrickletRS485
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
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_get_identity(TF_RS485 *rs485, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

/**
 * \ingroup BrickletRS485
 *
 * Writes characters to the RS485 interface. The characters can be binary data,
 * ASCII or similar is not necessary.
 * 
 * The return value is the number of characters that were written.
 * 
 * See {@link tf_rs485_set_rs485_configuration} for configuration possibilities
 * regarding baudrate, parity and so on.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_write(TF_RS485 *rs485, const char *message, uint16_t message_length, uint16_t *ret_message_written);

/**
 * \ingroup BrickletRS485
 *
 * Returns up to *length* characters from receive buffer.
 * 
 * Instead of polling with this function, you can also use
 * callbacks. But note that this function will return available
 * data only when the read callback is disabled.
 * See {@link tf_rs485_enable_read_callback} and {@link tf_rs485_register_read_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_read(TF_RS485 *rs485, uint16_t length, char *ret_message, uint16_t *ret_message_length);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to answer a master request to
 * read coils.
 * 
 * * Request ID: Request ID of the corresponding request that is being answered.
 * * Coils: Data that is to be sent to the Modbus master for the corresponding request.
 * 
 * This function must be called from the {@link tf_rs485_register_modbus_slave_read_coils_request_callback} callback
 * with the Request ID as provided by the argument of the callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_answer_read_coils_request(TF_RS485 *rs485, uint8_t request_id, bool *coils, uint16_t coils_length);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to answer a master request to
 * read holding registers.
 * 
 * * Request ID: Request ID of the corresponding request that is being answered.
 * * Holding Registers: Data that is to be sent to the Modbus master for the corresponding request.
 * 
 * This function must be called from the {@link tf_rs485_register_modbus_slave_read_holding_registers_request_callback}
 * callback with the Request ID as provided by the argument of the callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_answer_read_holding_registers_request(TF_RS485 *rs485, uint8_t request_id, uint16_t *holding_registers, uint16_t holding_registers_length);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus master mode this function can be used to write multiple coils of a slave.
 * This function creates a Modbus function code 15 request.
 * 
 * * Slave Address: Address of the target Modbus slave.
 * * Starting Address: Number of the first coil to write. For backwards compatibility reasons, this parameter is called Starting Address.It is not an address, but instead a coil number in the range of 1 to 65536.
 * 
 * Upon success the function will return a non-zero request ID which will represent
 * the current request initiated by the Modbus master. In case of failure the returned
 * request ID will be 0.
 * 
 * When successful this function will also invoke the {@link tf_rs485_register_modbus_master_write_multiple_coils_response_callback}
 * callback. In this callback the Request ID provided by the callback argument must be matched
 * with the Request ID returned from this function to verify that the callback is indeed for a
 * particular request.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_master_write_multiple_coils(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, bool *coils, uint16_t coils_length, uint8_t *ret_request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus master mode this function can be used to write multiple registers of a slave.
 * This function creates a Modbus function code 16 request.
 * 
 * * Slave Address: Address of the target Modbus slave.
 * * Starting Address: Number of the first holding register to write. For backwards compatibility reasons, this parameter is called Starting Address. It is not an address, but instead a holding register number in the range of 1 to 65536. The prefix digit 4 (for holding register) is implicit and must be omitted.
 * 
 * Upon success the function will return a non-zero request ID which will represent
 * the current request initiated by the Modbus master. In case of failure the returned
 * request ID will be 0.
 * 
 * When successful this function will also invoke the {@link tf_rs485_register_modbus_master_write_multiple_registers_response_callback}
 * callback. In this callback the Request ID provided by the callback argument must be matched
 * with the Request ID returned from this function to verify that the callback is indeed for a
 * particular request.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_master_write_multiple_registers(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t *registers, uint16_t registers_length, uint8_t *ret_request_id);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to answer a master request to
 * read discrete inputs.
 * 
 * * Request ID: Request ID of the corresponding request that is being answered.
 * * Discrete Inputs: Data that is to be sent to the Modbus master for the corresponding request.
 * 
 * This function must be called from the {@link tf_rs485_register_modbus_slave_read_discrete_inputs_request_callback}
 * callback with the Request ID as provided by the argument of the callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_answer_read_discrete_inputs_request(TF_RS485 *rs485, uint8_t request_id, bool *discrete_inputs, uint16_t discrete_inputs_length);

/**
 * \ingroup BrickletRS485
 *
 * In Modbus slave mode this function can be used to answer a master request to
 * read input registers.
 * 
 * * Request ID: Request ID of the corresponding request that is being answered.
 * * Input Registers: Data that is to be sent to the Modbus master for the corresponding request.
 * 
 * This function must be called from the {@link tf_rs485_register_modbus_slave_read_input_registers_request_callback} callback
 * with the Request ID as provided by the argument of the callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_rs485_modbus_slave_answer_read_input_registers_request(TF_RS485 *rs485, uint8_t request_id, uint16_t *input_registers, uint16_t input_registers_length);

#ifdef __cplusplus
}
#endif

#endif
