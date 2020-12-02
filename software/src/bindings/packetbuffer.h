/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#ifndef TF_PACKETBUFFER_H
#define TF_PACKETBUFFER_H

#include <stdbool.h>
#include <stdint.h>
#include "macros.h"

//TODO: fix circular includes, then use TF_SPITFP_MAX_MESSAGE_LENGTH + 1
//#include "spitfp.h"
#define PACKET_BUFFER_SIZE 84

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    //index of first valid elemnt
	uint8_t start;
    //index of first invalid element
	uint8_t end;
	uint8_t buffer[PACKET_BUFFER_SIZE];
} TF_Packetbuffer;

uint8_t tf_packetbuffer_get_size(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
uint8_t tf_packetbuffer_get_used(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
uint8_t tf_packetbuffer_get_free(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
bool tf_packetbuffer_is_empty(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
bool tf_packetbuffer_is_full(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
bool tf_packetbuffer_push(TF_Packetbuffer *rb, const uint8_t data) TF_ATTRIBUTE_NONNULL_ALL;
void tf_packetbuffer_remove(TF_Packetbuffer *rb, const uint8_t num) TF_ATTRIBUTE_NONNULL_ALL;
bool tf_packetbuffer_pop(TF_Packetbuffer *rb, uint8_t *data) TF_ATTRIBUTE_NONNULL_ALL;
bool tf_packetbuffer_peek(TF_Packetbuffer *rb, uint8_t *data) TF_ATTRIBUTE_NONNULL_ALL;
bool tf_packetbuffer_peek_offset(TF_Packetbuffer *rb, uint8_t *data, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;
void tf_packetbuffer_init(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
void tf_packetbuffer_print(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
bool tf_packetbuffer_free_array_view(TF_Packetbuffer *rb, uint8_t length, uint8_t **first_chunk, uint8_t *first_len, uint8_t **second_chunk, uint8_t *second_len) TF_ATTRIBUTE_NONNULL_ALL;

void tf_packetbuffer_pop_n(TF_Packetbuffer *rb, uint8_t* dest, uint8_t count) TF_ATTRIBUTE_NONNULL_ALL;
void tf_packetbuffer_peek_offset_n(TF_Packetbuffer *rb, uint8_t* dest, uint8_t count, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;

int8_t tf_packetbuffer_read_int8_t(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
uint8_t tf_packetbuffer_read_uint8_t(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
uint16_t tf_packetbuffer_read_uint16_t(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
uint32_t tf_packetbuffer_read_uint32_t(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
uint64_t tf_packetbuffer_read_uint64_t(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
int16_t tf_packetbuffer_read_int16_t(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
int32_t tf_packetbuffer_read_int32_t(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
int64_t tf_packetbuffer_read_int64_t(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
char tf_packetbuffer_read_char(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
float tf_packetbuffer_read_float(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
bool tf_packetbuffer_read_bool(TF_Packetbuffer *rb) TF_ATTRIBUTE_NONNULL_ALL;
void tf_packetbuffer_read_bool_array(TF_Packetbuffer *rb, bool* dest, uint16_t count) TF_ATTRIBUTE_NONNULL_ALL;

int8_t tf_packetbuffer_peek_int8_t(TF_Packetbuffer *rb, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;
uint8_t tf_packetbuffer_peek_uint8_t(TF_Packetbuffer *rb, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;
uint16_t tf_packetbuffer_peek_uint16_t(TF_Packetbuffer *rb, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;
uint32_t tf_packetbuffer_peek_uint32_t(TF_Packetbuffer *rb, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;
uint64_t tf_packetbuffer_peek_uint64_t(TF_Packetbuffer *rb, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;
int16_t tf_packetbuffer_peek_int16_t(TF_Packetbuffer *rb, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;
int32_t tf_packetbuffer_peek_int32_t(TF_Packetbuffer *rb, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;
int64_t tf_packetbuffer_peek_int64_t(TF_Packetbuffer *rb, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;
char tf_packetbuffer_peek_char(TF_Packetbuffer *rb, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;
float tf_packetbuffer_peek_float(TF_Packetbuffer *rb, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;
bool tf_packetbuffer_peek_bool(TF_Packetbuffer *rb, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;
void tf_packetbuffer_peek_bool_array(TF_Packetbuffer *rb, bool* dest, uint16_t count, uint8_t offset) TF_ATTRIBUTE_NONNULL_ALL;

#ifdef __cplusplus
}
#endif

#endif // DAEMONLIB_PACKETBUFFER_H
