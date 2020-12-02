/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#include "packetbuffer.h"

#include <stdio.h>
#include <string.h>

#include "macros.h"
#include "endian_convert.h"

uint8_t tf_packetbuffer_get_size(TF_Packetbuffer *rb) {
	return sizeof(rb->buffer) - 1;
}

uint8_t tf_packetbuffer_get_used(TF_Packetbuffer *rb) {
	if(rb->end < rb->start) {
		return sizeof(rb->buffer) + rb->end - rb->start;
	}

	return rb->end - rb->start;
}

uint8_t tf_packetbuffer_get_free(TF_Packetbuffer *rb) {
	const uint8_t free = tf_packetbuffer_get_size(rb) - tf_packetbuffer_get_used(rb);

	return free;
}

bool tf_packetbuffer_is_empty(TF_Packetbuffer *rb) {
    return tf_packetbuffer_get_used(rb) == 0;
}

bool tf_packetbuffer_is_full(TF_Packetbuffer *rb) {
	return tf_packetbuffer_get_free(rb) == 0;
}

bool tf_packetbuffer_push(TF_Packetbuffer *rb, const uint8_t data) {
	rb->buffer[rb->end] = data;
	rb->end++;
	if(rb->end >= sizeof(rb->buffer)) {
		rb->end = 0;
	}

	if(rb->end == rb->start) {
		if(rb->end == 0) {
			rb->end = sizeof(rb->buffer)-1;
		} else {
			rb->end--;
		}
		return false;
	}

	return true;
}

void tf_packetbuffer_remove(TF_Packetbuffer *rb, const uint8_t num) {
	// Make sure that we don't remove more then is available in the buffer
	uint8_t incr = MIN(tf_packetbuffer_get_used(rb), num);

	rb->start += incr;
	if(rb->start >= sizeof(rb->buffer)) {
		rb->start -= sizeof(rb->buffer);
	}
}

bool tf_packetbuffer_pop(TF_Packetbuffer *rb, uint8_t *data) {
	//Silence Wmaybe-uninitialized in the _read_[type] functions.
	*data = 0;
	if(tf_packetbuffer_is_empty(rb)) {
		return false;
	}

	*data = rb->buffer[rb->start];
	rb->start++;
	if(rb->start >= sizeof(rb->buffer)) {
		rb->start = 0;
	}

	return true;
}

bool tf_packetbuffer_peek(TF_Packetbuffer *rb, uint8_t *data) {
	if(tf_packetbuffer_is_empty(rb)) {
		return false;
	}

	*data = rb->buffer[rb->start];
	return true;
}

bool tf_packetbuffer_peek_offset(TF_Packetbuffer *rb, uint8_t *data, uint8_t offset) {
	if(tf_packetbuffer_get_used(rb) <= offset) {
		return false;
	}

    if (rb->start + offset >= sizeof(rb->buffer)) {
        *data = rb->buffer[rb->start + offset - sizeof(rb->buffer)];
    } else {
        *data = rb->buffer[rb->start + offset];
    }

	return true;
}

void tf_packetbuffer_init(TF_Packetbuffer *rb) {
    //TODO: The context is memsetted by tf_tfp_init, so this could be removed
    memset(rb->buffer, 0, sizeof(rb->buffer));
	rb->start         = 0;
	rb->end           = 0;
}

void tf_packetbuffer_print(TF_Packetbuffer *rb) {
	int32_t end = rb->end - rb->start;
	uint8_t i;

	if(end < 0) {
		end += sizeof(rb->buffer);
	}

	printf("TF_Packetbuffer (start %u, end %u, size %u): [\n",
	       rb->start, rb->end, PACKET_BUFFER_SIZE);

	for(i = 0; i < end; i++) {
		if((i % 16) == 0) {
			printf("    ");
		}

		printf("%x, ", rb->buffer[(rb->start + i) % sizeof(rb->buffer)]);

		if((i % 16) == 15) {
			printf("\n");
		}
	}

	printf("]\n");
}

bool tf_packetbuffer_free_array_view(TF_Packetbuffer *rb, uint8_t length, uint8_t **first_chunk, uint8_t *first_len, uint8_t **second_chunk, uint8_t *second_len) {
    if (length > tf_packetbuffer_get_free(rb))
        return false;

    bool wraps = (rb->end + length) >= sizeof(rb->buffer);

    *first_chunk = rb->buffer + rb->end;
    if (wraps) {
        *first_len = sizeof(rb->buffer) - rb->end;
        *second_chunk = rb->buffer;
        *second_len = length - *first_len;
        rb->end = *second_len;
    } else {
        *first_len = length;
        *second_chunk = NULL;
        *second_len = 0;
        rb->end = rb->end + length;
    }

    return true;
}

void tf_packetbuffer_pop_n(TF_Packetbuffer *rb, uint8_t* dest, uint8_t count) {
    for(int i = 0; i < count; ++i) {
        tf_packetbuffer_pop(rb, dest + i);
    }
}

void tf_packetbuffer_peek_offset_n(TF_Packetbuffer *rb, uint8_t* dest, uint8_t count, uint8_t offset) {
    for(int i = 0; i < count; ++i) {
        tf_packetbuffer_peek_offset(rb, dest + i, offset + i);
    }
}

uint8_t tf_packetbuffer_read_uint8_t(TF_Packetbuffer *rb) {
    uint8_t result;
    tf_packetbuffer_pop(rb, &result);
    return result;
}

int8_t tf_packetbuffer_read_int8_t(TF_Packetbuffer *rb) {
    int8_t result;
    tf_packetbuffer_pop(rb, (uint8_t*)(&result));
    return result;
}

uint16_t tf_packetbuffer_read_uint16_t(TF_Packetbuffer *rb) {
    uint16_t result;
    tf_packetbuffer_pop_n(rb, (uint8_t*)(&result), sizeof(result));
    return tf_leconvert_uint16_from(result);
}

uint32_t tf_packetbuffer_read_uint32_t(TF_Packetbuffer *rb) {
    uint32_t result;
    tf_packetbuffer_pop_n(rb, (uint8_t*)(&result), sizeof(result));
    return tf_leconvert_uint32_from(result);
}

uint64_t tf_packetbuffer_read_uint64_t(TF_Packetbuffer *rb) {
    uint64_t result;
    tf_packetbuffer_pop_n(rb, (uint8_t*)(&result), sizeof(result));
    return tf_leconvert_uint64_from(result);
}

int16_t tf_packetbuffer_read_int16_t(TF_Packetbuffer *rb) {
    int16_t result;
    tf_packetbuffer_pop_n(rb, (uint8_t*)(&result), sizeof(result));
    return tf_leconvert_int16_from(result);
}

int32_t tf_packetbuffer_read_int32_t(TF_Packetbuffer *rb) {
    int32_t result;
    tf_packetbuffer_pop_n(rb, (uint8_t*)(&result), sizeof(result));
    return tf_leconvert_int32_from(result);
}

int64_t tf_packetbuffer_read_int64_t(TF_Packetbuffer *rb) {
    int64_t result;
    tf_packetbuffer_pop_n(rb, (uint8_t*)(&result), sizeof(result));
    return tf_leconvert_int64_from(result);
}

char tf_packetbuffer_read_char(TF_Packetbuffer *rb) {
    char result;
    tf_packetbuffer_pop_n(rb, (uint8_t*)(&result), sizeof(result));
    return result;
}

float tf_packetbuffer_read_float(TF_Packetbuffer *rb){
    float result;
    tf_packetbuffer_pop_n(rb, (uint8_t*)(&result), sizeof(result));
    return tf_leconvert_float_from(result);
}

bool tf_packetbuffer_read_bool(TF_Packetbuffer *rb) {
    bool result;
    tf_packetbuffer_pop_n(rb, (uint8_t*)(&result), sizeof(result));
    return result;
}

void tf_packetbuffer_read_bool_array(TF_Packetbuffer *rb, bool* dest, uint16_t count) {
    uint8_t byte = 0;
    for(int i = 0; i < count; ++i) {
        if (i % 8 == 0) {
            tf_packetbuffer_pop(rb, &byte);
        }
        dest[i] = (byte & (1 << (i % 8))) != 0;
    }
}

uint8_t tf_packetbuffer_peek_uint8_t(TF_Packetbuffer *rb, uint8_t offset) {
    uint8_t result;
    tf_packetbuffer_peek_offset(rb, &result, offset);
    return result;
}

int8_t tf_packetbuffer_peek_int8_t(TF_Packetbuffer *rb, uint8_t offset) {
    int8_t result;
    tf_packetbuffer_peek_offset(rb, (uint8_t*)(&result), offset);
    return result;
}

uint16_t tf_packetbuffer_peek_uint16_t(TF_Packetbuffer *rb, uint8_t offset) {
    uint16_t result;
    tf_packetbuffer_peek_offset_n(rb, (uint8_t*)(&result), sizeof(result), offset);
    return tf_leconvert_uint16_from(result);
}

uint32_t tf_packetbuffer_peek_uint32_t(TF_Packetbuffer *rb, uint8_t offset) {
    uint32_t result;
    tf_packetbuffer_peek_offset_n(rb, (uint8_t*)(&result), sizeof(result), offset);
    return tf_leconvert_uint32_from(result);
}

uint64_t tf_packetbuffer_peek_uint64_t(TF_Packetbuffer *rb, uint8_t offset) {
    uint64_t result;
    tf_packetbuffer_peek_offset_n(rb, (uint8_t*)(&result), sizeof(result), offset);
    return tf_leconvert_uint64_from(result);
}

int16_t tf_packetbuffer_peek_int16_t(TF_Packetbuffer *rb, uint8_t offset) {
    int16_t result;
    tf_packetbuffer_peek_offset_n(rb, (uint8_t*)(&result), sizeof(result), offset);
    return tf_leconvert_int16_from(result);
}

int32_t tf_packetbuffer_peek_int32_t(TF_Packetbuffer *rb, uint8_t offset) {
    int32_t result;
    tf_packetbuffer_peek_offset_n(rb, (uint8_t*)(&result), sizeof(result), offset);
    return tf_leconvert_int32_from(result);
}

int64_t tf_packetbuffer_peek_int64_t(TF_Packetbuffer *rb, uint8_t offset) {
    int64_t result;
    tf_packetbuffer_peek_offset_n(rb, (uint8_t*)(&result), sizeof(result), offset);
    return tf_leconvert_int64_from(result);
}

char tf_packetbuffer_peek_char(TF_Packetbuffer *rb, uint8_t offset) {
    char result;
    tf_packetbuffer_peek_offset_n(rb, (uint8_t*)(&result), sizeof(result), offset);
    return result;
}

float tf_packetbuffer_peek_float(TF_Packetbuffer *rb, uint8_t offset){
    float result;
    tf_packetbuffer_peek_offset_n(rb, (uint8_t*)(&result), sizeof(result), offset);
    return tf_leconvert_float_from(result);
}

bool tf_packetbuffer_peek_bool(TF_Packetbuffer *rb, uint8_t offset) {
    bool result;
    tf_packetbuffer_peek_offset_n(rb, (uint8_t*)(&result), sizeof(result), offset);
    return result;
}

void tf_packetbuffer_peek_bool_array(TF_Packetbuffer *rb, bool* dest, uint16_t count, uint8_t offset) {
    uint8_t byte = 0;
    for(int i = 0; i < count; ++i) {
        if (i % 8 == 0) {
            tf_packetbuffer_peek_offset(rb, &byte, offset);
        }
        dest[i] = (byte & (1 << (i % 8))) != 0;
    }
}
