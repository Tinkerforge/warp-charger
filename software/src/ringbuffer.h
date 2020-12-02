/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

template <typename T, size_t SIZE>
class TF_Ringbuffer {
public:
    TF_Ringbuffer() : start(0), end(0), buffer{0} {}

    void clear() {
        start = 0;
        end = 0;
    }

    size_t size() {
        return SIZE - 1;
    }

    size_t used() {
        if(end < start) {
            return SIZE + end - start;
        }

        return end - start;
    };

    size_t free() {
        return size() - used();
    }

    void push(T val) {
        buffer[end] = val;
        end++;
        if(end >= sizeof(buffer) / sizeof(buffer[0])) {
            end = 0;
        }

        // This is true if we've just overwritten the oldest item
        if(end == start) {
            ++start;
            if(start >= sizeof(buffer) / sizeof(buffer[0])) {
                start = 0;
            }
        }
    }
    bool pop(T* val) {
        //Silence Wmaybe-uninitialized in the _read_[type] functions.
        *val = 0;
        if(used() == 0) {
            return false;
        }

        *val = buffer[start];
        start++;
        if(start >= sizeof(buffer) / sizeof(buffer[0])) {
            start = 0;
        }

        return true;
    }

    bool peek(T* val) {
        if(used() == 0) {
            return false;
        }

        *val = buffer[start];
        return true;
    }

    bool peek_offset(T* val, size_t offset) {
        if(used() <= offset) {
            return false;
        }

        if (start + offset >= sizeof(buffer) / sizeof(buffer[0])) {
            *val = buffer[start + offset - sizeof(buffer) / sizeof(buffer[0])];
        } else {
            *val = buffer[start + offset];
        }

        return true;
    }

    //index of first valid elemnt
	size_t start;
    //index of first invalid element
	size_t end;
	T buffer[SIZE];
};
