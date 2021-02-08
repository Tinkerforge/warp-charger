/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#include "bricklet_rs485.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_rs485_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_RS485 *rs485 = (TF_RS485 *) dev;
    (void)payload;

    switch(fid) {

        case TF_RS485_CALLBACK_READ_LOW_LEVEL: {
            TF_RS485ReadLowLevelHandler fn = rs485->read_low_level_handler;
            void *user_data = rs485->read_low_level_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            uint16_t message_length = tf_packetbuffer_read_uint16_t(payload);
            uint16_t message_chunk_offset = tf_packetbuffer_read_uint16_t(payload);
            char message_chunk_data[60]; for (i = 0; i < 60; ++i) message_chunk_data[i] = tf_packetbuffer_read_char(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, message_length, message_chunk_offset, message_chunk_data, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_ERROR_COUNT: {
            TF_RS485ErrorCountHandler fn = rs485->error_count_handler;
            void *user_data = rs485->error_count_user_data;
            if (fn == NULL)
                return false;

            uint32_t overrun_error_count = tf_packetbuffer_read_uint32_t(payload);
            uint32_t parity_error_count = tf_packetbuffer_read_uint32_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, overrun_error_count, parity_error_count, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_SLAVE_READ_COILS_REQUEST: {
            TF_RS485ModbusSlaveReadCoilsRequestHandler fn = rs485->modbus_slave_read_coils_request_handler;
            void *user_data = rs485->modbus_slave_read_coils_request_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            uint32_t starting_address = tf_packetbuffer_read_uint32_t(payload);
            uint16_t count = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, starting_address, count, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_MASTER_READ_COILS_RESPONSE_LOW_LEVEL: {
            TF_RS485ModbusMasterReadCoilsResponseLowLevelHandler fn = rs485->modbus_master_read_coils_response_low_level_handler;
            void *user_data = rs485->modbus_master_read_coils_response_low_level_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            int8_t exception_code = tf_packetbuffer_read_int8_t(payload);
            uint16_t coils_length = tf_packetbuffer_read_uint16_t(payload);
            uint16_t coils_chunk_offset = tf_packetbuffer_read_uint16_t(payload);
            bool coils_chunk_data[464]; tf_packetbuffer_read_bool_array(payload, coils_chunk_data, 464);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, exception_code, coils_length, coils_chunk_offset, coils_chunk_data, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_SLAVE_READ_HOLDING_REGISTERS_REQUEST: {
            TF_RS485ModbusSlaveReadHoldingRegistersRequestHandler fn = rs485->modbus_slave_read_holding_registers_request_handler;
            void *user_data = rs485->modbus_slave_read_holding_registers_request_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            uint32_t starting_address = tf_packetbuffer_read_uint32_t(payload);
            uint16_t count = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, starting_address, count, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_MASTER_READ_HOLDING_REGISTERS_RESPONSE_LOW_LEVEL: {
            TF_RS485ModbusMasterReadHoldingRegistersResponseLowLevelHandler fn = rs485->modbus_master_read_holding_registers_response_low_level_handler;
            void *user_data = rs485->modbus_master_read_holding_registers_response_low_level_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            int8_t exception_code = tf_packetbuffer_read_int8_t(payload);
            uint16_t holding_registers_length = tf_packetbuffer_read_uint16_t(payload);
            uint16_t holding_registers_chunk_offset = tf_packetbuffer_read_uint16_t(payload);
            uint16_t holding_registers_chunk_data[29]; for (i = 0; i < 29; ++i) holding_registers_chunk_data[i] = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, exception_code, holding_registers_length, holding_registers_chunk_offset, holding_registers_chunk_data, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_SLAVE_WRITE_SINGLE_COIL_REQUEST: {
            TF_RS485ModbusSlaveWriteSingleCoilRequestHandler fn = rs485->modbus_slave_write_single_coil_request_handler;
            void *user_data = rs485->modbus_slave_write_single_coil_request_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            uint32_t coil_address = tf_packetbuffer_read_uint32_t(payload);
            bool coil_value = tf_packetbuffer_read_bool(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, coil_address, coil_value, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_MASTER_WRITE_SINGLE_COIL_RESPONSE: {
            TF_RS485ModbusMasterWriteSingleCoilResponseHandler fn = rs485->modbus_master_write_single_coil_response_handler;
            void *user_data = rs485->modbus_master_write_single_coil_response_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            int8_t exception_code = tf_packetbuffer_read_int8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, exception_code, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_SLAVE_WRITE_SINGLE_REGISTER_REQUEST: {
            TF_RS485ModbusSlaveWriteSingleRegisterRequestHandler fn = rs485->modbus_slave_write_single_register_request_handler;
            void *user_data = rs485->modbus_slave_write_single_register_request_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            uint32_t register_address = tf_packetbuffer_read_uint32_t(payload);
            uint16_t register_value = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, register_address, register_value, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_MASTER_WRITE_SINGLE_REGISTER_RESPONSE: {
            TF_RS485ModbusMasterWriteSingleRegisterResponseHandler fn = rs485->modbus_master_write_single_register_response_handler;
            void *user_data = rs485->modbus_master_write_single_register_response_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            int8_t exception_code = tf_packetbuffer_read_int8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, exception_code, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_SLAVE_WRITE_MULTIPLE_COILS_REQUEST_LOW_LEVEL: {
            TF_RS485ModbusSlaveWriteMultipleCoilsRequestLowLevelHandler fn = rs485->modbus_slave_write_multiple_coils_request_low_level_handler;
            void *user_data = rs485->modbus_slave_write_multiple_coils_request_low_level_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            uint32_t starting_address = tf_packetbuffer_read_uint32_t(payload);
            uint16_t coils_length = tf_packetbuffer_read_uint16_t(payload);
            uint16_t coils_chunk_offset = tf_packetbuffer_read_uint16_t(payload);
            bool coils_chunk_data[440]; tf_packetbuffer_read_bool_array(payload, coils_chunk_data, 440);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, starting_address, coils_length, coils_chunk_offset, coils_chunk_data, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_MASTER_WRITE_MULTIPLE_COILS_RESPONSE: {
            TF_RS485ModbusMasterWriteMultipleCoilsResponseHandler fn = rs485->modbus_master_write_multiple_coils_response_handler;
            void *user_data = rs485->modbus_master_write_multiple_coils_response_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            int8_t exception_code = tf_packetbuffer_read_int8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, exception_code, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_SLAVE_WRITE_MULTIPLE_REGISTERS_REQUEST_LOW_LEVEL: {
            TF_RS485ModbusSlaveWriteMultipleRegistersRequestLowLevelHandler fn = rs485->modbus_slave_write_multiple_registers_request_low_level_handler;
            void *user_data = rs485->modbus_slave_write_multiple_registers_request_low_level_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            uint32_t starting_address = tf_packetbuffer_read_uint32_t(payload);
            uint16_t registers_length = tf_packetbuffer_read_uint16_t(payload);
            uint16_t registers_chunk_offset = tf_packetbuffer_read_uint16_t(payload);
            uint16_t registers_chunk_data[27]; for (i = 0; i < 27; ++i) registers_chunk_data[i] = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, starting_address, registers_length, registers_chunk_offset, registers_chunk_data, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_MASTER_WRITE_MULTIPLE_REGISTERS_RESPONSE: {
            TF_RS485ModbusMasterWriteMultipleRegistersResponseHandler fn = rs485->modbus_master_write_multiple_registers_response_handler;
            void *user_data = rs485->modbus_master_write_multiple_registers_response_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            int8_t exception_code = tf_packetbuffer_read_int8_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, exception_code, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_SLAVE_READ_DISCRETE_INPUTS_REQUEST: {
            TF_RS485ModbusSlaveReadDiscreteInputsRequestHandler fn = rs485->modbus_slave_read_discrete_inputs_request_handler;
            void *user_data = rs485->modbus_slave_read_discrete_inputs_request_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            uint32_t starting_address = tf_packetbuffer_read_uint32_t(payload);
            uint16_t count = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, starting_address, count, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_MASTER_READ_DISCRETE_INPUTS_RESPONSE_LOW_LEVEL: {
            TF_RS485ModbusMasterReadDiscreteInputsResponseLowLevelHandler fn = rs485->modbus_master_read_discrete_inputs_response_low_level_handler;
            void *user_data = rs485->modbus_master_read_discrete_inputs_response_low_level_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            int8_t exception_code = tf_packetbuffer_read_int8_t(payload);
            uint16_t discrete_inputs_length = tf_packetbuffer_read_uint16_t(payload);
            uint16_t discrete_inputs_chunk_offset = tf_packetbuffer_read_uint16_t(payload);
            bool discrete_inputs_chunk_data[464]; tf_packetbuffer_read_bool_array(payload, discrete_inputs_chunk_data, 464);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, exception_code, discrete_inputs_length, discrete_inputs_chunk_offset, discrete_inputs_chunk_data, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_SLAVE_READ_INPUT_REGISTERS_REQUEST: {
            TF_RS485ModbusSlaveReadInputRegistersRequestHandler fn = rs485->modbus_slave_read_input_registers_request_handler;
            void *user_data = rs485->modbus_slave_read_input_registers_request_user_data;
            if (fn == NULL)
                return false;

            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            uint32_t starting_address = tf_packetbuffer_read_uint32_t(payload);
            uint16_t count = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, starting_address, count, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_MODBUS_MASTER_READ_INPUT_REGISTERS_RESPONSE_LOW_LEVEL: {
            TF_RS485ModbusMasterReadInputRegistersResponseLowLevelHandler fn = rs485->modbus_master_read_input_registers_response_low_level_handler;
            void *user_data = rs485->modbus_master_read_input_registers_response_low_level_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            uint8_t request_id = tf_packetbuffer_read_uint8_t(payload);
            int8_t exception_code = tf_packetbuffer_read_int8_t(payload);
            uint16_t input_registers_length = tf_packetbuffer_read_uint16_t(payload);
            uint16_t input_registers_chunk_offset = tf_packetbuffer_read_uint16_t(payload);
            uint16_t input_registers_chunk_data[29]; for (i = 0; i < 29; ++i) input_registers_chunk_data[i] = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, request_id, exception_code, input_registers_length, input_registers_chunk_offset, input_registers_chunk_data, user_data);
            common->locked = false;
            break;
        }

        case TF_RS485_CALLBACK_FRAME_READABLE: {
            TF_RS485FrameReadableHandler fn = rs485->frame_readable_handler;
            void *user_data = rs485->frame_readable_user_data;
            if (fn == NULL)
                return false;

            uint16_t frame_count = tf_packetbuffer_read_uint16_t(payload);
            TF_HalCommon *common = tf_hal_get_common(rs485->tfp->hal);
            common->locked = true;
            fn(rs485, frame_count, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_rs485_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_rs485_create(TF_RS485 *rs485, const char *uid, TF_HalContext *hal) {
    memset(rs485, 0, sizeof(TF_RS485));

    uint32_t numeric_uid;
    int rc = tf_base58_decode(uid, &numeric_uid);
    if (rc != TF_E_OK) {
        return rc;
    }

    uint8_t port_id;
    int inventory_index;
    rc = tf_hal_get_port_id(hal, numeric_uid, &port_id, &inventory_index);
    if (rc < 0) {
        return rc;
    }

    //rc = tf_tfp_init(rs485->tfp, numeric_uid, TF_RS485_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_rs485_callback_handler);
    rc = tf_hal_get_tfp(hal, &rs485->tfp, TF_RS485_DEVICE_IDENTIFIER, inventory_index);
    if (rc != TF_E_OK) {
        return rc;
    }
    rs485->tfp->device = rs485;
    rs485->tfp->uid = numeric_uid;
    rs485->tfp->cb_handler = tf_rs485_callback_handler;
    rs485->response_expected[0] = 0x03;
    rs485->response_expected[1] = 0x1B;
    rs485->response_expected[2] = 0x0E;
    return TF_E_OK;
}

int tf_rs485_destroy(TF_RS485 *rs485) {
    int result = tf_tfp_destroy(rs485->tfp);
    rs485->tfp = NULL;
    return result;
}

int tf_rs485_get_response_expected(TF_RS485 *rs485, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_RS485_FUNCTION_ENABLE_READ_CALLBACK:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_RS485_FUNCTION_DISABLE_READ_CALLBACK:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_RS485_FUNCTION_SET_RS485_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_RS485_FUNCTION_SET_MODBUS_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_RS485_FUNCTION_SET_MODE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_RS485_FUNCTION_SET_COMMUNICATION_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_RS485_FUNCTION_SET_ERROR_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_RS485_FUNCTION_SET_BUFFER_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_RS485_FUNCTION_ENABLE_ERROR_COUNT_CALLBACK:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_RS485_FUNCTION_DISABLE_ERROR_COUNT_CALLBACK:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[1] & (1 << 1)) != 0;
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_REPORT_EXCEPTION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[1] & (1 << 2)) != 0;
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_COILS_REQUEST_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[1] & (1 << 3)) != 0;
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_HOLDING_REGISTERS_REQUEST_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[1] & (1 << 4)) != 0;
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_SINGLE_COIL_REQUEST:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[1] & (1 << 5)) != 0;
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_SINGLE_REGISTER_REQUEST:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[1] & (1 << 6)) != 0;
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_MULTIPLE_COILS_REQUEST:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[1] & (1 << 7)) != 0;
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_MULTIPLE_REGISTERS_REQUEST:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[2] & (1 << 0)) != 0;
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_DISCRETE_INPUTS_REQUEST_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[2] & (1 << 1)) != 0;
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_INPUT_REGISTERS_REQUEST_LOW_LEVEL:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[2] & (1 << 2)) != 0;
            break;
        case TF_RS485_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[2] & (1 << 3)) != 0;
            break;
        case TF_RS485_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[2] & (1 << 4)) != 0;
            break;
        case TF_RS485_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[2] & (1 << 5)) != 0;
            break;
        case TF_RS485_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[2] & (1 << 6)) != 0;
            break;
        case TF_RS485_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rs485->response_expected[2] & (1 << 7)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_rs485_set_response_expected(TF_RS485 *rs485, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_RS485_FUNCTION_ENABLE_READ_CALLBACK:
            if (response_expected) {
                rs485->response_expected[0] |= (1 << 0);
            } else {
                rs485->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_RS485_FUNCTION_DISABLE_READ_CALLBACK:
            if (response_expected) {
                rs485->response_expected[0] |= (1 << 1);
            } else {
                rs485->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_RS485_FUNCTION_SET_RS485_CONFIGURATION:
            if (response_expected) {
                rs485->response_expected[0] |= (1 << 2);
            } else {
                rs485->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_RS485_FUNCTION_SET_MODBUS_CONFIGURATION:
            if (response_expected) {
                rs485->response_expected[0] |= (1 << 3);
            } else {
                rs485->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_RS485_FUNCTION_SET_MODE:
            if (response_expected) {
                rs485->response_expected[0] |= (1 << 4);
            } else {
                rs485->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_RS485_FUNCTION_SET_COMMUNICATION_LED_CONFIG:
            if (response_expected) {
                rs485->response_expected[0] |= (1 << 5);
            } else {
                rs485->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_RS485_FUNCTION_SET_ERROR_LED_CONFIG:
            if (response_expected) {
                rs485->response_expected[0] |= (1 << 6);
            } else {
                rs485->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_RS485_FUNCTION_SET_BUFFER_CONFIG:
            if (response_expected) {
                rs485->response_expected[0] |= (1 << 7);
            } else {
                rs485->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_RS485_FUNCTION_ENABLE_ERROR_COUNT_CALLBACK:
            if (response_expected) {
                rs485->response_expected[1] |= (1 << 0);
            } else {
                rs485->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_RS485_FUNCTION_DISABLE_ERROR_COUNT_CALLBACK:
            if (response_expected) {
                rs485->response_expected[1] |= (1 << 1);
            } else {
                rs485->response_expected[1] &= ~(1 << 1);
            }
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_REPORT_EXCEPTION:
            if (response_expected) {
                rs485->response_expected[1] |= (1 << 2);
            } else {
                rs485->response_expected[1] &= ~(1 << 2);
            }
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_COILS_REQUEST_LOW_LEVEL:
            if (response_expected) {
                rs485->response_expected[1] |= (1 << 3);
            } else {
                rs485->response_expected[1] &= ~(1 << 3);
            }
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_HOLDING_REGISTERS_REQUEST_LOW_LEVEL:
            if (response_expected) {
                rs485->response_expected[1] |= (1 << 4);
            } else {
                rs485->response_expected[1] &= ~(1 << 4);
            }
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_SINGLE_COIL_REQUEST:
            if (response_expected) {
                rs485->response_expected[1] |= (1 << 5);
            } else {
                rs485->response_expected[1] &= ~(1 << 5);
            }
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_SINGLE_REGISTER_REQUEST:
            if (response_expected) {
                rs485->response_expected[1] |= (1 << 6);
            } else {
                rs485->response_expected[1] &= ~(1 << 6);
            }
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_MULTIPLE_COILS_REQUEST:
            if (response_expected) {
                rs485->response_expected[1] |= (1 << 7);
            } else {
                rs485->response_expected[1] &= ~(1 << 7);
            }
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_MULTIPLE_REGISTERS_REQUEST:
            if (response_expected) {
                rs485->response_expected[2] |= (1 << 0);
            } else {
                rs485->response_expected[2] &= ~(1 << 0);
            }
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_DISCRETE_INPUTS_REQUEST_LOW_LEVEL:
            if (response_expected) {
                rs485->response_expected[2] |= (1 << 1);
            } else {
                rs485->response_expected[2] &= ~(1 << 1);
            }
            break;
        case TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_INPUT_REGISTERS_REQUEST_LOW_LEVEL:
            if (response_expected) {
                rs485->response_expected[2] |= (1 << 2);
            } else {
                rs485->response_expected[2] &= ~(1 << 2);
            }
            break;
        case TF_RS485_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION:
            if (response_expected) {
                rs485->response_expected[2] |= (1 << 3);
            } else {
                rs485->response_expected[2] &= ~(1 << 3);
            }
            break;
        case TF_RS485_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                rs485->response_expected[2] |= (1 << 4);
            } else {
                rs485->response_expected[2] &= ~(1 << 4);
            }
            break;
        case TF_RS485_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                rs485->response_expected[2] |= (1 << 5);
            } else {
                rs485->response_expected[2] &= ~(1 << 5);
            }
            break;
        case TF_RS485_FUNCTION_RESET:
            if (response_expected) {
                rs485->response_expected[2] |= (1 << 6);
            } else {
                rs485->response_expected[2] &= ~(1 << 6);
            }
            break;
        case TF_RS485_FUNCTION_WRITE_UID:
            if (response_expected) {
                rs485->response_expected[2] |= (1 << 7);
            } else {
                rs485->response_expected[2] &= ~(1 << 7);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_rs485_set_response_expected_all(TF_RS485 *rs485, bool response_expected) {
    memset(rs485->response_expected, response_expected ? 0xFF : 0, 3);
}

int tf_rs485_write_low_level(TF_RS485 *rs485, uint16_t message_length, uint16_t message_chunk_offset, char message_chunk_data[60], uint8_t *ret_message_chunk_written) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_WRITE_LOW_LEVEL, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    message_length = tf_leconvert_uint16_to(message_length); memcpy(buf + 0, &message_length, 2);
    message_chunk_offset = tf_leconvert_uint16_to(message_chunk_offset); memcpy(buf + 2, &message_chunk_offset, 2);
    memcpy(buf + 4, message_chunk_data, 60);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_message_chunk_written != NULL) { *ret_message_chunk_written = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_read_low_level(TF_RS485 *rs485, uint16_t length, uint16_t *ret_message_length, uint16_t *ret_message_chunk_offset, char ret_message_chunk_data[60]) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_READ_LOW_LEVEL, 2, 64, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    length = tf_leconvert_uint16_to(length); memcpy(buf + 0, &length, 2);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_message_length != NULL) { *ret_message_length = tf_packetbuffer_read_uint16_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 2); }
        if (ret_message_chunk_offset != NULL) { *ret_message_chunk_offset = tf_packetbuffer_read_uint16_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 2); }
        if (ret_message_chunk_data != NULL) { for (i = 0; i < 60; ++i) ret_message_chunk_data[i] = tf_packetbuffer_read_char(&rs485->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 60); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_enable_read_callback(TF_RS485 *rs485) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_ENABLE_READ_CALLBACK, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_ENABLE_READ_CALLBACK, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_disable_read_callback(TF_RS485 *rs485) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_DISABLE_READ_CALLBACK, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_DISABLE_READ_CALLBACK, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_is_read_callback_enabled(TF_RS485 *rs485, bool *ret_enabled) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_IS_READ_CALLBACK_ENABLED, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { *ret_enabled = tf_packetbuffer_read_bool(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_set_rs485_configuration(TF_RS485 *rs485, uint32_t baudrate, uint8_t parity, uint8_t stopbits, uint8_t wordlength, uint8_t duplex) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_SET_RS485_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_SET_RS485_CONFIGURATION, 8, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    baudrate = tf_leconvert_uint32_to(baudrate); memcpy(buf + 0, &baudrate, 4);
    buf[4] = (uint8_t)parity;
    buf[5] = (uint8_t)stopbits;
    buf[6] = (uint8_t)wordlength;
    buf[7] = (uint8_t)duplex;

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_rs485_configuration(TF_RS485 *rs485, uint32_t *ret_baudrate, uint8_t *ret_parity, uint8_t *ret_stopbits, uint8_t *ret_wordlength, uint8_t *ret_duplex) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_RS485_CONFIGURATION, 0, 8, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_baudrate != NULL) { *ret_baudrate = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        if (ret_parity != NULL) { *ret_parity = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        if (ret_stopbits != NULL) { *ret_stopbits = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        if (ret_wordlength != NULL) { *ret_wordlength = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        if (ret_duplex != NULL) { *ret_duplex = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_set_modbus_configuration(TF_RS485 *rs485, uint8_t slave_address, uint32_t master_request_timeout) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_SET_MODBUS_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_SET_MODBUS_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)slave_address;
    master_request_timeout = tf_leconvert_uint32_to(master_request_timeout); memcpy(buf + 1, &master_request_timeout, 4);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_modbus_configuration(TF_RS485 *rs485, uint8_t *ret_slave_address, uint32_t *ret_master_request_timeout) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_MODBUS_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_slave_address != NULL) { *ret_slave_address = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        if (ret_master_request_timeout != NULL) { *ret_master_request_timeout = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_set_mode(TF_RS485 *rs485, uint8_t mode) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_SET_MODE, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_SET_MODE, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_mode(TF_RS485 *rs485, uint8_t *ret_mode) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_set_communication_led_config(TF_RS485 *rs485, uint8_t config) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_SET_COMMUNICATION_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_SET_COMMUNICATION_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_communication_led_config(TF_RS485 *rs485, uint8_t *ret_config) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_COMMUNICATION_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_set_error_led_config(TF_RS485 *rs485, uint8_t config) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_SET_ERROR_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_SET_ERROR_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_error_led_config(TF_RS485 *rs485, uint8_t *ret_config) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_ERROR_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_set_buffer_config(TF_RS485 *rs485, uint16_t send_buffer_size, uint16_t receive_buffer_size) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_SET_BUFFER_CONFIG, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_SET_BUFFER_CONFIG, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    send_buffer_size = tf_leconvert_uint16_to(send_buffer_size); memcpy(buf + 0, &send_buffer_size, 2);
    receive_buffer_size = tf_leconvert_uint16_to(receive_buffer_size); memcpy(buf + 2, &receive_buffer_size, 2);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_buffer_config(TF_RS485 *rs485, uint16_t *ret_send_buffer_size, uint16_t *ret_receive_buffer_size) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_BUFFER_CONFIG, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_send_buffer_size != NULL) { *ret_send_buffer_size = tf_packetbuffer_read_uint16_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 2); }
        if (ret_receive_buffer_size != NULL) { *ret_receive_buffer_size = tf_packetbuffer_read_uint16_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_buffer_status(TF_RS485 *rs485, uint16_t *ret_send_buffer_used, uint16_t *ret_receive_buffer_used) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_BUFFER_STATUS, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_send_buffer_used != NULL) { *ret_send_buffer_used = tf_packetbuffer_read_uint16_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 2); }
        if (ret_receive_buffer_used != NULL) { *ret_receive_buffer_used = tf_packetbuffer_read_uint16_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_enable_error_count_callback(TF_RS485 *rs485) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_ENABLE_ERROR_COUNT_CALLBACK, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_ENABLE_ERROR_COUNT_CALLBACK, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_disable_error_count_callback(TF_RS485 *rs485) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_DISABLE_ERROR_COUNT_CALLBACK, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_DISABLE_ERROR_COUNT_CALLBACK, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_is_error_count_callback_enabled(TF_RS485 *rs485, bool *ret_enabled) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_IS_ERROR_COUNT_CALLBACK_ENABLED, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_enabled != NULL) { *ret_enabled = tf_packetbuffer_read_bool(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_error_count(TF_RS485 *rs485, uint32_t *ret_overrun_error_count, uint32_t *ret_parity_error_count) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_ERROR_COUNT, 0, 8, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_overrun_error_count != NULL) { *ret_overrun_error_count = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        if (ret_parity_error_count != NULL) { *ret_parity_error_count = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_modbus_common_error_count(TF_RS485 *rs485, uint32_t *ret_timeout_error_count, uint32_t *ret_checksum_error_count, uint32_t *ret_frame_too_big_error_count, uint32_t *ret_illegal_function_error_count, uint32_t *ret_illegal_data_address_error_count, uint32_t *ret_illegal_data_value_error_count, uint32_t *ret_slave_device_failure_error_count) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_MODBUS_COMMON_ERROR_COUNT, 0, 28, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_timeout_error_count != NULL) { *ret_timeout_error_count = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        if (ret_checksum_error_count != NULL) { *ret_checksum_error_count = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        if (ret_frame_too_big_error_count != NULL) { *ret_frame_too_big_error_count = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        if (ret_illegal_function_error_count != NULL) { *ret_illegal_function_error_count = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        if (ret_illegal_data_address_error_count != NULL) { *ret_illegal_data_address_error_count = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        if (ret_illegal_data_value_error_count != NULL) { *ret_illegal_data_value_error_count = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        if (ret_slave_device_failure_error_count != NULL) { *ret_slave_device_failure_error_count = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_slave_report_exception(TF_RS485 *rs485, uint8_t request_id, int8_t exception_code) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_MODBUS_SLAVE_REPORT_EXCEPTION, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_SLAVE_REPORT_EXCEPTION, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)request_id;
    buf[1] = (uint8_t)exception_code;

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_slave_answer_read_coils_request_low_level(TF_RS485 *rs485, uint8_t request_id, uint16_t coils_length, uint16_t coils_chunk_offset, bool coils_chunk_data[472]) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_COILS_REQUEST_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_COILS_REQUEST_LOW_LEVEL, 64, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)request_id;
    coils_length = tf_leconvert_uint16_to(coils_length); memcpy(buf + 1, &coils_length, 2);
    coils_chunk_offset = tf_leconvert_uint16_to(coils_chunk_offset); memcpy(buf + 3, &coils_chunk_offset, 2);
    memset(buf + 5, 0, 59); for (i = 0; i < 472; ++i) buf[5 + (i / 8)] |= (coils_chunk_data[i] ? 1 : 0) << (i % 8);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_master_read_coils(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t count, uint8_t *ret_request_id) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_MASTER_READ_COILS, 7, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)slave_address;
    starting_address = tf_leconvert_uint32_to(starting_address); memcpy(buf + 1, &starting_address, 4);
    count = tf_leconvert_uint16_to(count); memcpy(buf + 5, &count, 2);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_request_id != NULL) { *ret_request_id = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_slave_answer_read_holding_registers_request_low_level(TF_RS485 *rs485, uint8_t request_id, uint16_t holding_registers_length, uint16_t holding_registers_chunk_offset, uint16_t holding_registers_chunk_data[29]) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_HOLDING_REGISTERS_REQUEST_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_HOLDING_REGISTERS_REQUEST_LOW_LEVEL, 63, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)request_id;
    holding_registers_length = tf_leconvert_uint16_to(holding_registers_length); memcpy(buf + 1, &holding_registers_length, 2);
    holding_registers_chunk_offset = tf_leconvert_uint16_to(holding_registers_chunk_offset); memcpy(buf + 3, &holding_registers_chunk_offset, 2);
    for (i = 0; i < 29; i++) { uint16_t tmp_holding_registers_chunk_data = tf_leconvert_uint16_to(holding_registers_chunk_data[i]); memcpy(buf + 5 + (i * sizeof(uint16_t)), &tmp_holding_registers_chunk_data, sizeof(uint16_t)); }

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_master_read_holding_registers(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t count, uint8_t *ret_request_id) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_MASTER_READ_HOLDING_REGISTERS, 7, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)slave_address;
    starting_address = tf_leconvert_uint32_to(starting_address); memcpy(buf + 1, &starting_address, 4);
    count = tf_leconvert_uint16_to(count); memcpy(buf + 5, &count, 2);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_request_id != NULL) { *ret_request_id = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_slave_answer_write_single_coil_request(TF_RS485 *rs485, uint8_t request_id) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_SINGLE_COIL_REQUEST, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_SINGLE_COIL_REQUEST, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)request_id;

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_master_write_single_coil(TF_RS485 *rs485, uint8_t slave_address, uint32_t coil_address, bool coil_value, uint8_t *ret_request_id) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_MASTER_WRITE_SINGLE_COIL, 6, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)slave_address;
    coil_address = tf_leconvert_uint32_to(coil_address); memcpy(buf + 1, &coil_address, 4);
    buf[5] = coil_value ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_request_id != NULL) { *ret_request_id = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_slave_answer_write_single_register_request(TF_RS485 *rs485, uint8_t request_id) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_SINGLE_REGISTER_REQUEST, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_SINGLE_REGISTER_REQUEST, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)request_id;

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_master_write_single_register(TF_RS485 *rs485, uint8_t slave_address, uint32_t register_address, uint16_t register_value, uint8_t *ret_request_id) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_MASTER_WRITE_SINGLE_REGISTER, 7, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)slave_address;
    register_address = tf_leconvert_uint32_to(register_address); memcpy(buf + 1, &register_address, 4);
    register_value = tf_leconvert_uint16_to(register_value); memcpy(buf + 5, &register_value, 2);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_request_id != NULL) { *ret_request_id = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_slave_answer_write_multiple_coils_request(TF_RS485 *rs485, uint8_t request_id) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_MULTIPLE_COILS_REQUEST, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_MULTIPLE_COILS_REQUEST, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)request_id;

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_master_write_multiple_coils_low_level(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t coils_length, uint16_t coils_chunk_offset, bool coils_chunk_data[440], uint8_t *ret_request_id) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_MASTER_WRITE_MULTIPLE_COILS_LOW_LEVEL, 64, 1, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)slave_address;
    starting_address = tf_leconvert_uint32_to(starting_address); memcpy(buf + 1, &starting_address, 4);
    coils_length = tf_leconvert_uint16_to(coils_length); memcpy(buf + 5, &coils_length, 2);
    coils_chunk_offset = tf_leconvert_uint16_to(coils_chunk_offset); memcpy(buf + 7, &coils_chunk_offset, 2);
    memset(buf + 9, 0, 55); for (i = 0; i < 440; ++i) buf[9 + (i / 8)] |= (coils_chunk_data[i] ? 1 : 0) << (i % 8);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_request_id != NULL) { *ret_request_id = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_slave_answer_write_multiple_registers_request(TF_RS485 *rs485, uint8_t request_id) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_MULTIPLE_REGISTERS_REQUEST, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_WRITE_MULTIPLE_REGISTERS_REQUEST, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)request_id;

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_master_write_multiple_registers_low_level(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t registers_length, uint16_t registers_chunk_offset, uint16_t registers_chunk_data[27], uint8_t *ret_request_id) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_MASTER_WRITE_MULTIPLE_REGISTERS_LOW_LEVEL, 63, 1, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)slave_address;
    starting_address = tf_leconvert_uint32_to(starting_address); memcpy(buf + 1, &starting_address, 4);
    registers_length = tf_leconvert_uint16_to(registers_length); memcpy(buf + 5, &registers_length, 2);
    registers_chunk_offset = tf_leconvert_uint16_to(registers_chunk_offset); memcpy(buf + 7, &registers_chunk_offset, 2);
    for (i = 0; i < 27; i++) { uint16_t tmp_registers_chunk_data = tf_leconvert_uint16_to(registers_chunk_data[i]); memcpy(buf + 9 + (i * sizeof(uint16_t)), &tmp_registers_chunk_data, sizeof(uint16_t)); }

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_request_id != NULL) { *ret_request_id = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_slave_answer_read_discrete_inputs_request_low_level(TF_RS485 *rs485, uint8_t request_id, uint16_t discrete_inputs_length, uint16_t discrete_inputs_chunk_offset, bool discrete_inputs_chunk_data[472]) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_DISCRETE_INPUTS_REQUEST_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_DISCRETE_INPUTS_REQUEST_LOW_LEVEL, 64, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)request_id;
    discrete_inputs_length = tf_leconvert_uint16_to(discrete_inputs_length); memcpy(buf + 1, &discrete_inputs_length, 2);
    discrete_inputs_chunk_offset = tf_leconvert_uint16_to(discrete_inputs_chunk_offset); memcpy(buf + 3, &discrete_inputs_chunk_offset, 2);
    memset(buf + 5, 0, 59); for (i = 0; i < 472; ++i) buf[5 + (i / 8)] |= (discrete_inputs_chunk_data[i] ? 1 : 0) << (i % 8);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_master_read_discrete_inputs(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t count, uint8_t *ret_request_id) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_MASTER_READ_DISCRETE_INPUTS, 7, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)slave_address;
    starting_address = tf_leconvert_uint32_to(starting_address); memcpy(buf + 1, &starting_address, 4);
    count = tf_leconvert_uint16_to(count); memcpy(buf + 5, &count, 2);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_request_id != NULL) { *ret_request_id = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_slave_answer_read_input_registers_request_low_level(TF_RS485 *rs485, uint8_t request_id, uint16_t input_registers_length, uint16_t input_registers_chunk_offset, uint16_t input_registers_chunk_data[29]) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_INPUT_REGISTERS_REQUEST_LOW_LEVEL, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_SLAVE_ANSWER_READ_INPUT_REGISTERS_REQUEST_LOW_LEVEL, 63, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)request_id;
    input_registers_length = tf_leconvert_uint16_to(input_registers_length); memcpy(buf + 1, &input_registers_length, 2);
    input_registers_chunk_offset = tf_leconvert_uint16_to(input_registers_chunk_offset); memcpy(buf + 3, &input_registers_chunk_offset, 2);
    for (i = 0; i < 29; i++) { uint16_t tmp_input_registers_chunk_data = tf_leconvert_uint16_to(input_registers_chunk_data[i]); memcpy(buf + 5 + (i * sizeof(uint16_t)), &tmp_input_registers_chunk_data, sizeof(uint16_t)); }

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_modbus_master_read_input_registers(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t count, uint8_t *ret_request_id) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_MODBUS_MASTER_READ_INPUT_REGISTERS, 7, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)slave_address;
    starting_address = tf_leconvert_uint32_to(starting_address); memcpy(buf + 1, &starting_address, 4);
    count = tf_leconvert_uint16_to(count); memcpy(buf + 5, &count, 2);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_request_id != NULL) { *ret_request_id = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_set_frame_readable_callback_configuration(TF_RS485 *rs485, uint16_t frame_size) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_SET_FRAME_READABLE_CALLBACK_CONFIGURATION, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    frame_size = tf_leconvert_uint16_to(frame_size); memcpy(buf + 0, &frame_size, 2);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_frame_readable_callback_configuration(TF_RS485 *rs485, uint16_t *ret_frame_size) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_FRAME_READABLE_CALLBACK_CONFIGURATION, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_frame_size != NULL) { *ret_frame_size = tf_packetbuffer_read_uint16_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_spitfp_error_count(TF_RS485 *rs485, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_set_bootloader_mode(TF_RS485 *rs485, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_bootloader_mode(TF_RS485 *rs485, uint8_t *ret_mode) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_set_write_firmware_pointer(TF_RS485 *rs485, uint32_t pointer) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_write_firmware(TF_RS485 *rs485, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_set_status_led_config(TF_RS485 *rs485, uint8_t config) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_status_led_config(TF_RS485 *rs485, uint8_t *ret_config) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_chip_temperature(TF_RS485 *rs485, int16_t *ret_temperature) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 2); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_reset(TF_RS485 *rs485) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_write_uid(TF_RS485 *rs485, uint32_t uid) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rs485_get_response_expected(rs485, TF_RS485_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(rs485->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_read_uid(TF_RS485 *rs485, uint32_t *ret_uid) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 4); }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_get_identity(TF_RS485 *rs485, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(rs485->tfp->hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(rs485->tfp, TF_RS485_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(rs485->tfp->hal) + tf_hal_get_common(rs485->tfp->hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(rs485->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&rs485->tfp->spitfp->recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 8); }
        tf_packetbuffer_pop_n(&rs485->tfp->spitfp->recv_buf, (uint8_t*)tmp_connected_uid, 8);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&rs485->tfp->spitfp->recv_buf);} else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&rs485->tfp->spitfp->recv_buf); } else { tf_packetbuffer_remove(&rs485->tfp->spitfp->recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(rs485->tfp->hal, rs485->tfp->spitfp->port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(rs485->tfp);
    }

    result = tf_tfp_finish_send(rs485->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rs485_write(TF_RS485 *rs485, const char *message, uint16_t message_length, uint16_t *ret_message_written) {
    int ret = TF_E_OK;
    uint16_t message_chunk_offset = 0;
    char message_chunk_data[60];
    uint16_t message_chunk_length = 0;
    uint8_t message_chunk_written = 0;

    *ret_message_written = 0;

    if (message_length == 0) {
        memset(&message_chunk_data, 0, sizeof(char) * 60);

        ret = tf_rs485_write_low_level(rs485, message_length, message_chunk_offset, message_chunk_data, &message_chunk_written);

        if (ret != TF_E_OK) {
            return ret;
        }

        *ret_message_written = message_chunk_written;
    } else {

        while (message_chunk_offset < message_length) {
            message_chunk_length = message_length - message_chunk_offset;

            if (message_chunk_length > 60) {
                message_chunk_length = 60;
            }

            memcpy(message_chunk_data, &message[message_chunk_offset], sizeof(char) * message_chunk_length);
            memset(&message_chunk_data[message_chunk_length], 0, sizeof(char) * (60 - message_chunk_length));

            ret = tf_rs485_write_low_level(rs485, message_length, message_chunk_offset, message_chunk_data, &message_chunk_written);

            if (ret != TF_E_OK) {
                *ret_message_written = 0;

                break;
            }

            *ret_message_written += message_chunk_written;

            if (message_chunk_written < 60) {
                break; // either last chunk or short write
            }

            message_chunk_offset += 60;
        }

    }

    return ret;
}

int tf_rs485_read(TF_RS485 *rs485, uint16_t length, char *ret_message, uint16_t *ret_message_length) {
    int ret = TF_E_OK;
    uint16_t message_length = 0;
    uint16_t message_chunk_offset = 0;
    char message_chunk_data[60];
    bool message_out_of_sync;
    uint16_t message_chunk_length = 0;

    *ret_message_length = 0;

    ret = tf_rs485_read_low_level(rs485, length, &message_length, &message_chunk_offset, message_chunk_data);

    if (ret != TF_E_OK) {
        return ret;
    }

    message_out_of_sync = message_chunk_offset != 0;

    if (!message_out_of_sync) {
        message_chunk_length = message_length - message_chunk_offset;

        if (message_chunk_length > 60) {
            message_chunk_length = 60;
        }

        memcpy(ret_message, message_chunk_data, sizeof(char) * message_chunk_length);
        *ret_message_length = message_chunk_length;

        while (*ret_message_length < message_length) {
            ret = tf_rs485_read_low_level(rs485, length, &message_length, &message_chunk_offset, message_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }

            message_out_of_sync = message_chunk_offset != *ret_message_length;

            if (message_out_of_sync) {
                break;
            }

            message_chunk_length = message_length - message_chunk_offset;

            if (message_chunk_length > 60) {
                message_chunk_length = 60;
            }

            memcpy(&ret_message[*ret_message_length], message_chunk_data, sizeof(char) * message_chunk_length);
            *ret_message_length += message_chunk_length;
        }
    }

    if (message_out_of_sync) {
        *ret_message_length = 0; // return empty array

        // discard remaining stream to bring it back in-sync
        while (message_chunk_offset + 60 < message_length) {
            ret = tf_rs485_read_low_level(rs485, length, &message_length, &message_chunk_offset, message_chunk_data);

            if (ret != TF_E_OK) {
                return ret;
            }
        }

        ret = TF_E_STREAM_OUT_OF_SYNC;
    }

    return ret;
}

int tf_rs485_modbus_slave_answer_read_coils_request(TF_RS485 *rs485, uint8_t request_id, bool *coils, uint16_t coils_length) {
    int ret = TF_E_OK;
    uint16_t coils_chunk_offset = 0;
    bool coils_chunk_data[472];
    uint16_t coils_chunk_length = 0;

    if (coils_length == 0) {
        memset(&coils_chunk_data, 0, sizeof(bool) * 472);

        ret = tf_rs485_modbus_slave_answer_read_coils_request_low_level(rs485, request_id, coils_length, coils_chunk_offset, coils_chunk_data);
    } else {

        while (coils_chunk_offset < coils_length) {
            coils_chunk_length = coils_length - coils_chunk_offset;

            if (coils_chunk_length > 472) {
                coils_chunk_length = 472;
            }

            memcpy(coils_chunk_data, &coils[coils_chunk_offset], sizeof(bool) * coils_chunk_length);
            memset(&coils_chunk_data[coils_chunk_length], 0, sizeof(bool) * (472 - coils_chunk_length));

            ret = tf_rs485_modbus_slave_answer_read_coils_request_low_level(rs485, request_id, coils_length, coils_chunk_offset, coils_chunk_data);

            if (ret != TF_E_OK) {
                break;
            }

            coils_chunk_offset += 472;
        }

    }

    return ret;
}

int tf_rs485_modbus_slave_answer_read_holding_registers_request(TF_RS485 *rs485, uint8_t request_id, uint16_t *holding_registers, uint16_t holding_registers_length) {
    int ret = TF_E_OK;
    uint16_t holding_registers_chunk_offset = 0;
    uint16_t holding_registers_chunk_data[29];
    uint16_t holding_registers_chunk_length = 0;

    if (holding_registers_length == 0) {
        memset(&holding_registers_chunk_data, 0, sizeof(uint16_t) * 29);

        ret = tf_rs485_modbus_slave_answer_read_holding_registers_request_low_level(rs485, request_id, holding_registers_length, holding_registers_chunk_offset, holding_registers_chunk_data);
    } else {

        while (holding_registers_chunk_offset < holding_registers_length) {
            holding_registers_chunk_length = holding_registers_length - holding_registers_chunk_offset;

            if (holding_registers_chunk_length > 29) {
                holding_registers_chunk_length = 29;
            }

            memcpy(holding_registers_chunk_data, &holding_registers[holding_registers_chunk_offset], sizeof(uint16_t) * holding_registers_chunk_length);
            memset(&holding_registers_chunk_data[holding_registers_chunk_length], 0, sizeof(uint16_t) * (29 - holding_registers_chunk_length));

            ret = tf_rs485_modbus_slave_answer_read_holding_registers_request_low_level(rs485, request_id, holding_registers_length, holding_registers_chunk_offset, holding_registers_chunk_data);

            if (ret != TF_E_OK) {
                break;
            }

            holding_registers_chunk_offset += 29;
        }

    }

    return ret;
}

int tf_rs485_modbus_master_write_multiple_coils(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, bool *coils, uint16_t coils_length, uint8_t *ret_request_id) {
    int ret = TF_E_OK;
    uint16_t coils_chunk_offset = 0;
    bool coils_chunk_data[440];
    uint16_t coils_chunk_length = 0;

    if (coils_length == 0) {
        memset(&coils_chunk_data, 0, sizeof(bool) * 440);

        ret = tf_rs485_modbus_master_write_multiple_coils_low_level(rs485, slave_address, starting_address, coils_length, coils_chunk_offset, coils_chunk_data, ret_request_id);
    } else {

        while (coils_chunk_offset < coils_length) {
            coils_chunk_length = coils_length - coils_chunk_offset;

            if (coils_chunk_length > 440) {
                coils_chunk_length = 440;
            }

            memcpy(coils_chunk_data, &coils[coils_chunk_offset], sizeof(bool) * coils_chunk_length);
            memset(&coils_chunk_data[coils_chunk_length], 0, sizeof(bool) * (440 - coils_chunk_length));

            ret = tf_rs485_modbus_master_write_multiple_coils_low_level(rs485, slave_address, starting_address, coils_length, coils_chunk_offset, coils_chunk_data, ret_request_id);

            if (ret != TF_E_OK) {
                break;
            }

            coils_chunk_offset += 440;
        }

    }

    return ret;
}

int tf_rs485_modbus_master_write_multiple_registers(TF_RS485 *rs485, uint8_t slave_address, uint32_t starting_address, uint16_t *registers, uint16_t registers_length, uint8_t *ret_request_id) {
    int ret = TF_E_OK;
    uint16_t registers_chunk_offset = 0;
    uint16_t registers_chunk_data[27];
    uint16_t registers_chunk_length = 0;

    if (registers_length == 0) {
        memset(&registers_chunk_data, 0, sizeof(uint16_t) * 27);

        ret = tf_rs485_modbus_master_write_multiple_registers_low_level(rs485, slave_address, starting_address, registers_length, registers_chunk_offset, registers_chunk_data, ret_request_id);
    } else {

        while (registers_chunk_offset < registers_length) {
            registers_chunk_length = registers_length - registers_chunk_offset;

            if (registers_chunk_length > 27) {
                registers_chunk_length = 27;
            }

            memcpy(registers_chunk_data, &registers[registers_chunk_offset], sizeof(uint16_t) * registers_chunk_length);
            memset(&registers_chunk_data[registers_chunk_length], 0, sizeof(uint16_t) * (27 - registers_chunk_length));

            ret = tf_rs485_modbus_master_write_multiple_registers_low_level(rs485, slave_address, starting_address, registers_length, registers_chunk_offset, registers_chunk_data, ret_request_id);

            if (ret != TF_E_OK) {
                break;
            }

            registers_chunk_offset += 27;
        }

    }

    return ret;
}

int tf_rs485_modbus_slave_answer_read_discrete_inputs_request(TF_RS485 *rs485, uint8_t request_id, bool *discrete_inputs, uint16_t discrete_inputs_length) {
    int ret = TF_E_OK;
    uint16_t discrete_inputs_chunk_offset = 0;
    bool discrete_inputs_chunk_data[472];
    uint16_t discrete_inputs_chunk_length = 0;

    if (discrete_inputs_length == 0) {
        memset(&discrete_inputs_chunk_data, 0, sizeof(bool) * 472);

        ret = tf_rs485_modbus_slave_answer_read_discrete_inputs_request_low_level(rs485, request_id, discrete_inputs_length, discrete_inputs_chunk_offset, discrete_inputs_chunk_data);
    } else {

        while (discrete_inputs_chunk_offset < discrete_inputs_length) {
            discrete_inputs_chunk_length = discrete_inputs_length - discrete_inputs_chunk_offset;

            if (discrete_inputs_chunk_length > 472) {
                discrete_inputs_chunk_length = 472;
            }

            memcpy(discrete_inputs_chunk_data, &discrete_inputs[discrete_inputs_chunk_offset], sizeof(bool) * discrete_inputs_chunk_length);
            memset(&discrete_inputs_chunk_data[discrete_inputs_chunk_length], 0, sizeof(bool) * (472 - discrete_inputs_chunk_length));

            ret = tf_rs485_modbus_slave_answer_read_discrete_inputs_request_low_level(rs485, request_id, discrete_inputs_length, discrete_inputs_chunk_offset, discrete_inputs_chunk_data);

            if (ret != TF_E_OK) {
                break;
            }

            discrete_inputs_chunk_offset += 472;
        }

    }

    return ret;
}

int tf_rs485_modbus_slave_answer_read_input_registers_request(TF_RS485 *rs485, uint8_t request_id, uint16_t *input_registers, uint16_t input_registers_length) {
    int ret = TF_E_OK;
    uint16_t input_registers_chunk_offset = 0;
    uint16_t input_registers_chunk_data[29];
    uint16_t input_registers_chunk_length = 0;

    if (input_registers_length == 0) {
        memset(&input_registers_chunk_data, 0, sizeof(uint16_t) * 29);

        ret = tf_rs485_modbus_slave_answer_read_input_registers_request_low_level(rs485, request_id, input_registers_length, input_registers_chunk_offset, input_registers_chunk_data);
    } else {

        while (input_registers_chunk_offset < input_registers_length) {
            input_registers_chunk_length = input_registers_length - input_registers_chunk_offset;

            if (input_registers_chunk_length > 29) {
                input_registers_chunk_length = 29;
            }

            memcpy(input_registers_chunk_data, &input_registers[input_registers_chunk_offset], sizeof(uint16_t) * input_registers_chunk_length);
            memset(&input_registers_chunk_data[input_registers_chunk_length], 0, sizeof(uint16_t) * (29 - input_registers_chunk_length));

            ret = tf_rs485_modbus_slave_answer_read_input_registers_request_low_level(rs485, request_id, input_registers_length, input_registers_chunk_offset, input_registers_chunk_data);

            if (ret != TF_E_OK) {
                break;
            }

            input_registers_chunk_offset += 29;
        }

    }

    return ret;
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_rs485_register_read_low_level_callback(TF_RS485 *rs485, TF_RS485ReadLowLevelHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->read_low_level_handler = handler;
    rs485->read_low_level_user_data = user_data;
}


void tf_rs485_register_error_count_callback(TF_RS485 *rs485, TF_RS485ErrorCountHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->error_count_handler = handler;
    rs485->error_count_user_data = user_data;
}


void tf_rs485_register_modbus_slave_read_coils_request_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveReadCoilsRequestHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_slave_read_coils_request_handler = handler;
    rs485->modbus_slave_read_coils_request_user_data = user_data;
}


void tf_rs485_register_modbus_master_read_coils_response_low_level_callback(TF_RS485 *rs485, TF_RS485ModbusMasterReadCoilsResponseLowLevelHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_master_read_coils_response_low_level_handler = handler;
    rs485->modbus_master_read_coils_response_low_level_user_data = user_data;
}


void tf_rs485_register_modbus_slave_read_holding_registers_request_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveReadHoldingRegistersRequestHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_slave_read_holding_registers_request_handler = handler;
    rs485->modbus_slave_read_holding_registers_request_user_data = user_data;
}


void tf_rs485_register_modbus_master_read_holding_registers_response_low_level_callback(TF_RS485 *rs485, TF_RS485ModbusMasterReadHoldingRegistersResponseLowLevelHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_master_read_holding_registers_response_low_level_handler = handler;
    rs485->modbus_master_read_holding_registers_response_low_level_user_data = user_data;
}


void tf_rs485_register_modbus_slave_write_single_coil_request_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveWriteSingleCoilRequestHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_slave_write_single_coil_request_handler = handler;
    rs485->modbus_slave_write_single_coil_request_user_data = user_data;
}


void tf_rs485_register_modbus_master_write_single_coil_response_callback(TF_RS485 *rs485, TF_RS485ModbusMasterWriteSingleCoilResponseHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_master_write_single_coil_response_handler = handler;
    rs485->modbus_master_write_single_coil_response_user_data = user_data;
}


void tf_rs485_register_modbus_slave_write_single_register_request_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveWriteSingleRegisterRequestHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_slave_write_single_register_request_handler = handler;
    rs485->modbus_slave_write_single_register_request_user_data = user_data;
}


void tf_rs485_register_modbus_master_write_single_register_response_callback(TF_RS485 *rs485, TF_RS485ModbusMasterWriteSingleRegisterResponseHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_master_write_single_register_response_handler = handler;
    rs485->modbus_master_write_single_register_response_user_data = user_data;
}


void tf_rs485_register_modbus_slave_write_multiple_coils_request_low_level_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveWriteMultipleCoilsRequestLowLevelHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_slave_write_multiple_coils_request_low_level_handler = handler;
    rs485->modbus_slave_write_multiple_coils_request_low_level_user_data = user_data;
}


void tf_rs485_register_modbus_master_write_multiple_coils_response_callback(TF_RS485 *rs485, TF_RS485ModbusMasterWriteMultipleCoilsResponseHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_master_write_multiple_coils_response_handler = handler;
    rs485->modbus_master_write_multiple_coils_response_user_data = user_data;
}


void tf_rs485_register_modbus_slave_write_multiple_registers_request_low_level_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveWriteMultipleRegistersRequestLowLevelHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_slave_write_multiple_registers_request_low_level_handler = handler;
    rs485->modbus_slave_write_multiple_registers_request_low_level_user_data = user_data;
}


void tf_rs485_register_modbus_master_write_multiple_registers_response_callback(TF_RS485 *rs485, TF_RS485ModbusMasterWriteMultipleRegistersResponseHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_master_write_multiple_registers_response_handler = handler;
    rs485->modbus_master_write_multiple_registers_response_user_data = user_data;
}


void tf_rs485_register_modbus_slave_read_discrete_inputs_request_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveReadDiscreteInputsRequestHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_slave_read_discrete_inputs_request_handler = handler;
    rs485->modbus_slave_read_discrete_inputs_request_user_data = user_data;
}


void tf_rs485_register_modbus_master_read_discrete_inputs_response_low_level_callback(TF_RS485 *rs485, TF_RS485ModbusMasterReadDiscreteInputsResponseLowLevelHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_master_read_discrete_inputs_response_low_level_handler = handler;
    rs485->modbus_master_read_discrete_inputs_response_low_level_user_data = user_data;
}


void tf_rs485_register_modbus_slave_read_input_registers_request_callback(TF_RS485 *rs485, TF_RS485ModbusSlaveReadInputRegistersRequestHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_slave_read_input_registers_request_handler = handler;
    rs485->modbus_slave_read_input_registers_request_user_data = user_data;
}


void tf_rs485_register_modbus_master_read_input_registers_response_low_level_callback(TF_RS485 *rs485, TF_RS485ModbusMasterReadInputRegistersResponseLowLevelHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->frame_readable_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->modbus_master_read_input_registers_response_low_level_handler = handler;
    rs485->modbus_master_read_input_registers_response_low_level_user_data = user_data;
}


void tf_rs485_register_frame_readable_callback(TF_RS485 *rs485, TF_RS485FrameReadableHandler handler, void *user_data) {
    if (handler == NULL) {
        rs485->tfp->needs_callback_tick = false;
        rs485->tfp->needs_callback_tick |= rs485->read_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->error_count_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_coils_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_coils_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_holding_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_holding_registers_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_coil_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_coil_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_single_register_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_single_register_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_coils_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_coils_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_write_multiple_registers_request_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_write_multiple_registers_response_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_discrete_inputs_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_discrete_inputs_response_low_level_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_slave_read_input_registers_request_handler != NULL;
        rs485->tfp->needs_callback_tick |= rs485->modbus_master_read_input_registers_response_low_level_handler != NULL;
    } else {
        rs485->tfp->needs_callback_tick = true;
    }
    rs485->frame_readable_handler = handler;
    rs485->frame_readable_user_data = user_data;
}
#endif
int tf_rs485_callback_tick(TF_RS485 *rs485, uint32_t timeout_us) {
    return tf_tfp_callback_tick(rs485->tfp, tf_hal_current_time_us(rs485->tfp->hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
