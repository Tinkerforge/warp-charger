/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_THERMAL_IMAGING_H
#define TF_BRICKLET_THERMAL_IMAGING_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletThermalImaging Thermal Imaging Bricklet
 */

struct TF_ThermalImaging;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_ThermalImagingHighContrastImageLowLevelHandler)(struct TF_ThermalImaging *device, uint16_t image_chunk_offset, uint8_t image_chunk_data[62], void *user_data);
typedef void (*TF_ThermalImagingTemperatureImageLowLevelHandler)(struct TF_ThermalImaging *device, uint16_t image_chunk_offset, uint16_t image_chunk_data[31], void *user_data);

#endif
/**
 * \ingroup BrickletThermalImaging
 *
 * 80x60 pixel thermal imaging camera
 */
typedef struct TF_ThermalImaging {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_ThermalImagingHighContrastImageLowLevelHandler high_contrast_image_low_level_handler;
    void *high_contrast_image_low_level_user_data;

    TF_ThermalImagingTemperatureImageLowLevelHandler temperature_image_low_level_handler;
    void *temperature_image_low_level_user_data;

#endif
    uint8_t response_expected[2];
} TF_ThermalImaging;

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_HIGH_CONTRAST_IMAGE_LOW_LEVEL 1

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_TEMPERATURE_IMAGE_LOW_LEVEL 2

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_STATISTICS 3

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_SET_RESOLUTION 4

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_RESOLUTION 5

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_SET_SPOTMETER_CONFIG 6

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_SPOTMETER_CONFIG 7

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_SET_HIGH_CONTRAST_CONFIG 8

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_HIGH_CONTRAST_CONFIG 9

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_SET_IMAGE_TRANSFER_CONFIG 10

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_IMAGE_TRANSFER_CONFIG 11

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_SET_FLUX_LINEAR_PARAMETERS 14

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_FLUX_LINEAR_PARAMETERS 15

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_RESET 243

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_CALLBACK_HIGH_CONTRAST_IMAGE_LOW_LEVEL 12

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_CALLBACK_TEMPERATURE_IMAGE_LOW_LEVEL 13

#endif

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_RESOLUTION_0_TO_6553_KELVIN 0

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_RESOLUTION_0_TO_655_KELVIN 1

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FFC_STATUS_NEVER_COMMANDED 0

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FFC_STATUS_IMMINENT 1

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FFC_STATUS_IN_PROGRESS 2

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_FFC_STATUS_COMPLETE 3

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_IMAGE_TRANSFER_MANUAL_HIGH_CONTRAST_IMAGE 0

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_IMAGE_TRANSFER_MANUAL_TEMPERATURE_IMAGE 1

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_IMAGE_TRANSFER_CALLBACK_HIGH_CONTRAST_IMAGE 2

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_IMAGE_TRANSFER_CALLBACK_TEMPERATURE_IMAGE 3

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletThermalImaging
 */
#define TF_THERMAL_IMAGING_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletThermalImaging
 *
 * This constant is used to identify a Thermal Imaging Bricklet.
 *
 * The {@link thermal_imaging_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_THERMAL_IMAGING_DEVICE_IDENTIFIER 278

/**
 * \ingroup BrickletThermalImaging
 *
 * This constant represents the display name of a Thermal Imaging Bricklet.
 */
#define TF_THERMAL_IMAGING_DEVICE_DISPLAY_NAME "Thermal Imaging Bricklet"

/**
 * \ingroup BrickletThermalImaging
 *
 * Creates the device object \c thermal_imaging with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_thermal_imaging_create(TF_ThermalImaging *thermal_imaging, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletThermalImaging
 *
 * Removes the device object \c thermal_imaging from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_thermal_imaging_destroy(TF_ThermalImaging *thermal_imaging);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the thermal_imaging_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_response_expected(TF_ThermalImaging *thermal_imaging, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletThermalImaging
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
TF_ATTRIBUTE_NONNULL_ALL int tf_thermal_imaging_set_response_expected(TF_ThermalImaging *thermal_imaging, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletThermalImaging
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_thermal_imaging_set_response_expected_all(TF_ThermalImaging *thermal_imaging, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletThermalImaging
 *
 * Registers the given \c handler to the High Contrast Image Low Level callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t image_chunk_offset, uint8_t image_chunk_data[62], void *user_data) \endcode
 * 
 * This callback is triggered with every new high contrast image if the transfer image
 * config is configured for high contrast callback (see {@link tf_thermal_imaging_set_image_transfer_config}).
 * 
 * The data is organized as a 8-bit value 80x60 pixel matrix linearized in
 * a one-dimensional array. The data is arranged line by line from top left to
 * bottom right.
 * 
 * Each 8-bit value represents one gray-scale image pixel that can directly be
 * shown to a user on a display.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_thermal_imaging_register_high_contrast_image_low_level_callback(TF_ThermalImaging *thermal_imaging, TF_ThermalImagingHighContrastImageLowLevelHandler handler, void *user_data);


/**
 * \ingroup BrickletThermalImaging
 *
 * Registers the given \c handler to the Temperature Image Low Level callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(uint16_t image_chunk_offset, uint16_t image_chunk_data[31], void *user_data) \endcode
 * 
 * This callback is triggered with every new temperature image if the transfer image
 * config is configured for temperature callback (see {@link tf_thermal_imaging_set_image_transfer_config}).
 * 
 * The data is organized as a 16-bit value 80x60 pixel matrix linearized in
 * a one-dimensional array. The data is arranged line by line from top left to
 * bottom right.
 * 
 * Each 16-bit value represents one temperature measurement in either
 * Kelvin/10 or Kelvin/100 (depending on the resolution set with {@link tf_thermal_imaging_set_resolution}).
 */
TF_ATTRIBUTE_NONNULL(1) void tf_thermal_imaging_register_temperature_image_low_level_callback(TF_ThermalImaging *thermal_imaging, TF_ThermalImagingTemperatureImageLowLevelHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletThermalImaging
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_thermal_imaging_callback_tick(TF_ThermalImaging *thermal_imaging, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the current high contrast image. See `here <https://www.tinkerforge.com/en/doc/Hardware/Bricklets/Thermal_Imaging.html#high-contrast-image-vs-temperature-image>`__
 * for the difference between
 * High Contrast and Temperature Image. If you don't know what to use
 * the High Contrast Image is probably right for you.
 * 
 * The data is organized as a 8-bit value 80x60 pixel matrix linearized in
 * a one-dimensional array. The data is arranged line by line from top left to
 * bottom right.
 * 
 * Each 8-bit value represents one gray-scale image pixel that can directly be
 * shown to a user on a display.
 * 
 * Before you can use this function you have to enable it with
 * {@link tf_thermal_imaging_set_image_transfer_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_high_contrast_image_low_level(TF_ThermalImaging *thermal_imaging, uint16_t *ret_image_chunk_offset, uint8_t ret_image_chunk_data[62]);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the current temperature image. See `here <https://www.tinkerforge.com/en/doc/Hardware/Bricklets/Thermal_Imaging.html#high-contrast-image-vs-temperature-image>`__
 * for the difference between High Contrast and Temperature Image.
 * If you don't know what to use the High Contrast Image is probably right for you.
 * 
 * The data is organized as a 16-bit value 80x60 pixel matrix linearized in
 * a one-dimensional array. The data is arranged line by line from top left to
 * bottom right.
 * 
 * Each 16-bit value represents one temperature measurement in either
 * Kelvin/10 or Kelvin/100 (depending on the resolution set with {@link tf_thermal_imaging_set_resolution}).
 * 
 * Before you can use this function you have to enable it with
 * {@link tf_thermal_imaging_set_image_transfer_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_temperature_image_low_level(TF_ThermalImaging *thermal_imaging, uint16_t *ret_image_chunk_offset, uint16_t ret_image_chunk_data[31]);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the spotmeter statistics, various temperatures, current resolution and status bits.
 * 
 * The spotmeter statistics are:
 * 
 * * Index 0: Mean Temperature.
 * * Index 1: Maximum Temperature.
 * * Index 2: Minimum Temperature.
 * * Index 3: Pixel Count of spotmeter region of interest.
 * 
 * The temperatures are:
 * 
 * * Index 0: Focal Plain Array temperature.
 * * Index 1: Focal Plain Array temperature at last FFC (Flat Field Correction).
 * * Index 2: Housing temperature.
 * * Index 3: Housing temperature at last FFC.
 * 
 * The resolution is either `0 to 6553 Kelvin` or `0 to 655 Kelvin`. If the resolution is the former,
 * the temperatures are in Kelvin/10, if it is the latter the temperatures are in Kelvin/100.
 * 
 * FFC (Flat Field Correction) Status:
 * 
 * * FFC Never Commanded: Only seen on startup before first FFC.
 * * FFC Imminent: This state is entered 2 seconds prior to initiating FFC.
 * * FFC In Progress: Flat field correction is started (shutter moves in front of lens and back). Takes about 1 second.
 * * FFC Complete: Shutter is in waiting position again, FFC done.
 * 
 * Temperature warning bits:
 * 
 * * Index 0: Shutter lockout (if true shutter is locked out because temperature is outside -10°C to +65°C)
 * * Index 1: Overtemperature shut down imminent (goes true 10 seconds before shutdown)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_statistics(TF_ThermalImaging *thermal_imaging, uint16_t ret_spotmeter_statistics[4], uint16_t ret_temperatures[4], uint8_t *ret_resolution, uint8_t *ret_ffc_status, bool ret_temperature_warning[2]);

/**
 * \ingroup BrickletThermalImaging
 *
 * Sets the resolution. The Thermal Imaging Bricklet can either measure
 * 
 * * from 0 to 6553 Kelvin (-273.15°C to +6279.85°C) with 0.1°C resolution or
 * * from 0 to 655 Kelvin (-273.15°C to +381.85°C) with 0.01°C resolution.
 * 
 * The accuracy is specified for -10°C to 450°C in the
 * first range and -10°C and 140°C in the second range.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_set_resolution(TF_ThermalImaging *thermal_imaging, uint8_t resolution);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the resolution as set by {@link tf_thermal_imaging_set_resolution}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_resolution(TF_ThermalImaging *thermal_imaging, uint8_t *ret_resolution);

/**
 * \ingroup BrickletThermalImaging
 *
 * Sets the spotmeter region of interest. The 4 values are
 * 
 * * Index 0: Column start (has to be smaller then Column end).
 * * Index 1: Row start (has to be smaller then Row end).
 * * Index 2: Column end (has to be smaller then 80).
 * * Index 3: Row end (has to be smaller then 60).
 * 
 * The spotmeter statistics can be read out with {@link tf_thermal_imaging_get_statistics}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_set_spotmeter_config(TF_ThermalImaging *thermal_imaging, uint8_t region_of_interest[4]);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the spotmeter config as set by {@link tf_thermal_imaging_set_spotmeter_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_spotmeter_config(TF_ThermalImaging *thermal_imaging, uint8_t ret_region_of_interest[4]);

/**
 * \ingroup BrickletThermalImaging
 *
 * Sets the high contrast region of interest, dampening factor, clip limit and empty counts.
 * This config is only used in high contrast mode (see {@link tf_thermal_imaging_set_image_transfer_config}).
 * 
 * The high contrast region of interest consists of four values:
 * 
 * * Index 0: Column start (has to be smaller or equal then Column end).
 * * Index 1: Row start (has to be smaller then Row end).
 * * Index 2: Column end (has to be smaller then 80).
 * * Index 3: Row end (has to be smaller then 60).
 * 
 * The algorithm to generate the high contrast image is applied to this region.
 * 
 * Dampening Factor: This parameter is the amount of temporal dampening applied to the HEQ
 * (history equalization) transformation function. An IIR filter of the form::
 * 
 *  (N / 256) * previous + ((256 - N) / 256) * current
 * 
 * is applied, and the HEQ dampening factor
 * represents the value N in the equation, i.e., a value that applies to the amount of
 * influence the previous HEQ transformation function has on the current function. The
 * lower the value of N the higher the influence of the current video frame whereas
 * the higher the value of N the more influence the previous damped transfer function has.
 * 
 * Clip Limit Index 0 (AGC HEQ Clip Limit High): This parameter defines the maximum number of pixels allowed
 * to accumulate in any given histogram bin. Any additional pixels in a given bin are clipped.
 * The effect of this parameter is to limit the influence of highly-populated bins on the
 * resulting HEQ transformation function.
 * 
 * Clip Limit Index 1 (AGC HEQ Clip Limit Low): This parameter defines an artificial population that is added to
 * every non-empty histogram bin. In other words, if the Clip Limit Low is set to L, a bin
 * with an actual population of X will have an effective population of L + X. Any empty bin
 * that is nearby a populated bin will be given an artificial population of L. The effect of
 * higher values is to provide a more linear transfer function; lower values provide a more
 * non-linear (equalized) transfer function.
 * 
 * Empty Counts: This parameter specifies the maximum number of pixels in a bin that will be
 * interpreted as an empty bin. Histogram bins with this number of pixels or less will be
 * processed as an empty bin.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_set_high_contrast_config(TF_ThermalImaging *thermal_imaging, uint8_t region_of_interest[4], uint16_t dampening_factor, uint16_t clip_limit[2], uint16_t empty_counts);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the high contrast config as set by {@link tf_thermal_imaging_set_high_contrast_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_high_contrast_config(TF_ThermalImaging *thermal_imaging, uint8_t ret_region_of_interest[4], uint16_t *ret_dampening_factor, uint16_t ret_clip_limit[2], uint16_t *ret_empty_counts);

/**
 * \ingroup BrickletThermalImaging
 *
 * The necessary bandwidth of this Bricklet is too high to use getter/callback or
 * high contrast/temperature image at the same time. You have to configure the one
 * you want to use, the Bricklet will optimize the internal configuration accordingly.
 * 
 * Corresponding functions:
 * 
 * * Manual High Contrast Image: {@link tf_thermal_imaging_get_high_contrast_image}.
 * * Manual Temperature Image: {@link tf_thermal_imaging_get_temperature_image}.
 * * Callback High Contrast Image: {@link tf_thermal_imaging_register_high_contrast_image_callback} callback.
 * * Callback Temperature Image: {@link tf_thermal_imaging_register_temperature_image_callback} callback.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_set_image_transfer_config(TF_ThermalImaging *thermal_imaging, uint8_t config);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the image transfer config, as set by {@link tf_thermal_imaging_set_image_transfer_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_image_transfer_config(TF_ThermalImaging *thermal_imaging, uint8_t *ret_config);

/**
 * \ingroup BrickletThermalImaging
 *
 * Sets the flux linear parameters that can be used for radiometry calibration.
 * 
 * See FLIR document 102-PS245-100-01 for more details.
 * 
 * .. versionadded:: 2.0.5$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_set_flux_linear_parameters(TF_ThermalImaging *thermal_imaging, uint16_t scene_emissivity, uint16_t temperature_background, uint16_t tau_window, uint16_t temperatur_window, uint16_t tau_atmosphere, uint16_t temperature_atmosphere, uint16_t reflection_window, uint16_t temperature_reflection);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the flux linear parameters, as set by {@link tf_thermal_imaging_set_flux_linear_parameters}.
 * 
 * .. versionadded:: 2.0.5$nbsp;(Plugin)
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_flux_linear_parameters(TF_ThermalImaging *thermal_imaging, uint16_t *ret_scene_emissivity, uint16_t *ret_temperature_background, uint16_t *ret_tau_window, uint16_t *ret_temperatur_window, uint16_t *ret_tau_atmosphere, uint16_t *ret_temperature_atmosphere, uint16_t *ret_reflection_window, uint16_t *ret_temperature_reflection);

/**
 * \ingroup BrickletThermalImaging
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
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_spitfp_error_count(TF_ThermalImaging *thermal_imaging, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletThermalImaging
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
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_set_bootloader_mode(TF_ThermalImaging *thermal_imaging, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the current bootloader mode, see {@link tf_thermal_imaging_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_bootloader_mode(TF_ThermalImaging *thermal_imaging, uint8_t *ret_mode);

/**
 * \ingroup BrickletThermalImaging
 *
 * Sets the firmware pointer for {@link tf_thermal_imaging_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_set_write_firmware_pointer(TF_ThermalImaging *thermal_imaging, uint32_t pointer);

/**
 * \ingroup BrickletThermalImaging
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_thermal_imaging_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_write_firmware(TF_ThermalImaging *thermal_imaging, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletThermalImaging
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_set_status_led_config(TF_ThermalImaging *thermal_imaging, uint8_t config);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the configuration as set by {@link tf_thermal_imaging_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_status_led_config(TF_ThermalImaging *thermal_imaging, uint8_t *ret_config);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_chip_temperature(TF_ThermalImaging *thermal_imaging, int16_t *ret_temperature);

/**
 * \ingroup BrickletThermalImaging
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_reset(TF_ThermalImaging *thermal_imaging);

/**
 * \ingroup BrickletThermalImaging
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_write_uid(TF_ThermalImaging *thermal_imaging, uint32_t uid);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_read_uid(TF_ThermalImaging *thermal_imaging, uint32_t *ret_uid);

/**
 * \ingroup BrickletThermalImaging
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
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_identity(TF_ThermalImaging *thermal_imaging, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the current high contrast image. See `here <https://www.tinkerforge.com/en/doc/Hardware/Bricklets/Thermal_Imaging.html#high-contrast-image-vs-temperature-image>`__
 * for the difference between
 * High Contrast and Temperature Image. If you don't know what to use
 * the High Contrast Image is probably right for you.
 * 
 * The data is organized as a 8-bit value 80x60 pixel matrix linearized in
 * a one-dimensional array. The data is arranged line by line from top left to
 * bottom right.
 * 
 * Each 8-bit value represents one gray-scale image pixel that can directly be
 * shown to a user on a display.
 * 
 * Before you can use this function you have to enable it with
 * {@link tf_thermal_imaging_set_image_transfer_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_high_contrast_image(TF_ThermalImaging *thermal_imaging, uint8_t *ret_image, uint16_t *ret_image_length);

/**
 * \ingroup BrickletThermalImaging
 *
 * Returns the current temperature image. See `here <https://www.tinkerforge.com/en/doc/Hardware/Bricklets/Thermal_Imaging.html#high-contrast-image-vs-temperature-image>`__
 * for the difference between High Contrast and Temperature Image.
 * If you don't know what to use the High Contrast Image is probably right for you.
 * 
 * The data is organized as a 16-bit value 80x60 pixel matrix linearized in
 * a one-dimensional array. The data is arranged line by line from top left to
 * bottom right.
 * 
 * Each 16-bit value represents one temperature measurement in either
 * Kelvin/10 or Kelvin/100 (depending on the resolution set with {@link tf_thermal_imaging_set_resolution}).
 * 
 * Before you can use this function you have to enable it with
 * {@link tf_thermal_imaging_set_image_transfer_config}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_thermal_imaging_get_temperature_image(TF_ThermalImaging *thermal_imaging, uint16_t *ret_image, uint16_t *ret_image_length);

#ifdef __cplusplus
}
#endif

#endif
