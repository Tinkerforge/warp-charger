/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#ifndef TF_ERRORS_H
#define TF_ERRORS_H

#ifdef __cplusplus
extern "C" {
#endif

#define TF_E_OK 0
#define TF_E_TIMEOUT -1
#define TF_E_INVALID_PARAMETER -2
#define TF_E_NOT_SUPPORTED -3
#define TF_E_UNKNOWN_ERROR_CODE -4
#define TF_E_STREAM_OUT_OF_SYNC -5

#define TF_E_INVALID_CHAR_IN_UID -6
#define TF_E_UID_TOO_LONG -7
#define TF_E_UID_OVERFLOW -8

#define TF_E_TOO_MANY_DEVICES -9
#define TF_E_DEVICE_NOT_FOUND -10
#define TF_E_WRONG_DEVICE_TYPE -11

#define TF_E_LOCKED -12

#define TF_E_PORT_NOT_FOUND -13

#ifdef __cplusplus
}
#endif

#endif
