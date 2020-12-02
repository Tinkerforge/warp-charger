/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#ifndef TF_CONFIG_H
#define TF_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

// This is the size of the inventory i.e. the mapping from
// UIDs to the ports under which they are reachable.
// Increase this if the HAL initialization returns TF_E_TOO_MANY_DEVICES.
// Decrease this if you don't need as much devices and want decrease the
// program size.
#define TF_INVENTORY_SIZE 10

// Remove this define to disable the callback implementation.
// This will reduce the program size.
#define TF_IMPLEMENT_CALLBACKS

// Set this to a higher log level to reduce debug output and program size.
#define TF_LOG_LEVEL TF_LOG_LEVEL_INFO

// Remove this to remove the tf_hal_strerror implementation.
#define TF_IMPLEMENT_STRERROR

// Remove this to remove the tf_get_device_display_name implementation.
#define TF_IMPLEMENT_GET_DEVICE_DISPLAY_NAME

#ifdef __cplusplus
}
#endif

#endif
