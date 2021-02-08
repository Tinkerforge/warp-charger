/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef TF_BRICKLET_IMU_V3_H
#define TF_BRICKLET_IMU_V3_H

#include "config.h"
#include "tfp.h"
#include "hal_common.h"
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletIMUV3 IMU Bricklet 3.0
 */

struct TF_IMUV3;
#ifdef TF_IMPLEMENT_CALLBACKS

typedef void (*TF_IMUV3AccelerationHandler)(struct TF_IMUV3 *device, int16_t x, int16_t y, int16_t z, void *user_data);
typedef void (*TF_IMUV3MagneticFieldHandler)(struct TF_IMUV3 *device, int16_t x, int16_t y, int16_t z, void *user_data);
typedef void (*TF_IMUV3AngularVelocityHandler)(struct TF_IMUV3 *device, int16_t x, int16_t y, int16_t z, void *user_data);
typedef void (*TF_IMUV3TemperatureHandler)(struct TF_IMUV3 *device, int8_t temperature, void *user_data);
typedef void (*TF_IMUV3LinearAccelerationHandler)(struct TF_IMUV3 *device, int16_t x, int16_t y, int16_t z, void *user_data);
typedef void (*TF_IMUV3GravityVectorHandler)(struct TF_IMUV3 *device, int16_t x, int16_t y, int16_t z, void *user_data);
typedef void (*TF_IMUV3OrientationHandler)(struct TF_IMUV3 *device, int16_t heading, int16_t roll, int16_t pitch, void *user_data);
typedef void (*TF_IMUV3QuaternionHandler)(struct TF_IMUV3 *device, int16_t w, int16_t x, int16_t y, int16_t z, void *user_data);
typedef void (*TF_IMUV3AllDataHandler)(struct TF_IMUV3 *device, int16_t acceleration[3], int16_t magnetic_field[3], int16_t angular_velocity[3], int16_t euler_angle[3], int16_t quaternion[4], int16_t linear_acceleration[3], int16_t gravity_vector[3], int8_t temperature, uint8_t calibration_status, void *user_data);

#endif
/**
 * \ingroup BrickletIMUV3
 *
 * Full fledged AHRS with 9 degrees of freedom
 */
typedef struct TF_IMUV3 {
    TF_TfpContext *tfp;
#ifdef TF_IMPLEMENT_CALLBACKS
    TF_IMUV3AccelerationHandler acceleration_handler;
    void *acceleration_user_data;

    TF_IMUV3MagneticFieldHandler magnetic_field_handler;
    void *magnetic_field_user_data;

    TF_IMUV3AngularVelocityHandler angular_velocity_handler;
    void *angular_velocity_user_data;

    TF_IMUV3TemperatureHandler temperature_handler;
    void *temperature_user_data;

    TF_IMUV3LinearAccelerationHandler linear_acceleration_handler;
    void *linear_acceleration_user_data;

    TF_IMUV3GravityVectorHandler gravity_vector_handler;
    void *gravity_vector_user_data;

    TF_IMUV3OrientationHandler orientation_handler;
    void *orientation_user_data;

    TF_IMUV3QuaternionHandler quaternion_handler;
    void *quaternion_user_data;

    TF_IMUV3AllDataHandler all_data_handler;
    void *all_data_user_data;

#endif
    uint8_t response_expected[2];
} TF_IMUV3;

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_ACCELERATION 1

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_MAGNETIC_FIELD 2

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_ANGULAR_VELOCITY 3

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_TEMPERATURE 4

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_ORIENTATION 5

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_LINEAR_ACCELERATION 6

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_GRAVITY_VECTOR 7

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_QUATERNION 8

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_ALL_DATA 9

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SAVE_CALIBRATION 10

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_SENSOR_CONFIGURATION 11

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_SENSOR_CONFIGURATION 12

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_SENSOR_FUSION_MODE 13

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_SENSOR_FUSION_MODE 14

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_ACCELERATION_CALLBACK_CONFIGURATION 15

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_ACCELERATION_CALLBACK_CONFIGURATION 16

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_MAGNETIC_FIELD_CALLBACK_CONFIGURATION 17

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_MAGNETIC_FIELD_CALLBACK_CONFIGURATION 18

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_ANGULAR_VELOCITY_CALLBACK_CONFIGURATION 19

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_ANGULAR_VELOCITY_CALLBACK_CONFIGURATION 20

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION 21

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_TEMPERATURE_CALLBACK_CONFIGURATION 22

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_ORIENTATION_CALLBACK_CONFIGURATION 23

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_ORIENTATION_CALLBACK_CONFIGURATION 24

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_LINEAR_ACCELERATION_CALLBACK_CONFIGURATION 25

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_LINEAR_ACCELERATION_CALLBACK_CONFIGURATION 26

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_GRAVITY_VECTOR_CALLBACK_CONFIGURATION 27

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_GRAVITY_VECTOR_CALLBACK_CONFIGURATION 28

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_QUATERNION_CALLBACK_CONFIGURATION 29

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_QUATERNION_CALLBACK_CONFIGURATION 30

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_ALL_DATA_CALLBACK_CONFIGURATION 31

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_ALL_DATA_CALLBACK_CONFIGURATION 32

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_RESET 243

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_FUNCTION_GET_IDENTITY 255

#ifdef TF_IMPLEMENT_CALLBACKS

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_CALLBACK_ACCELERATION 33

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_CALLBACK_MAGNETIC_FIELD 34

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_CALLBACK_ANGULAR_VELOCITY 35

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_CALLBACK_TEMPERATURE 36

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_CALLBACK_LINEAR_ACCELERATION 37

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_CALLBACK_GRAVITY_VECTOR 38

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_CALLBACK_ORIENTATION 39

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_CALLBACK_QUATERNION 40

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_CALLBACK_ALL_DATA 41

#endif

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_MAGNETOMETER_RATE_2HZ 0

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_MAGNETOMETER_RATE_6HZ 1

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_MAGNETOMETER_RATE_8HZ 2

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_MAGNETOMETER_RATE_10HZ 3

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_MAGNETOMETER_RATE_15HZ 4

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_MAGNETOMETER_RATE_20HZ 5

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_MAGNETOMETER_RATE_25HZ 6

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_MAGNETOMETER_RATE_30HZ 7

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_RANGE_2000DPS 0

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_RANGE_1000DPS 1

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_RANGE_500DPS 2

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_RANGE_250DPS 3

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_RANGE_125DPS 4

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_BANDWIDTH_523HZ 0

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_BANDWIDTH_230HZ 1

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_BANDWIDTH_116HZ 2

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_BANDWIDTH_47HZ 3

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_BANDWIDTH_23HZ 4

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_BANDWIDTH_12HZ 5

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_BANDWIDTH_64HZ 6

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_GYROSCOPE_BANDWIDTH_32HZ 7

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_ACCELEROMETER_RANGE_2G 0

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_ACCELEROMETER_RANGE_4G 1

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_ACCELEROMETER_RANGE_8G 2

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_ACCELEROMETER_RANGE_16G 3

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_ACCELEROMETER_BANDWIDTH_7_81HZ 0

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_ACCELEROMETER_BANDWIDTH_15_63HZ 1

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_ACCELEROMETER_BANDWIDTH_31_25HZ 2

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_ACCELEROMETER_BANDWIDTH_62_5HZ 3

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_ACCELEROMETER_BANDWIDTH_125HZ 4

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_ACCELEROMETER_BANDWIDTH_250HZ 5

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_ACCELEROMETER_BANDWIDTH_500HZ 6

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_ACCELEROMETER_BANDWIDTH_1000HZ 7

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_SENSOR_FUSION_OFF 0

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_SENSOR_FUSION_ON 1

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_SENSOR_FUSION_ON_WITHOUT_MAGNETOMETER 2

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_SENSOR_FUSION_ON_WITHOUT_FAST_MAGNETOMETER_CALIBRATION 3

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletIMUV3
 */
#define TF_IMU_V3_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletIMUV3
 *
 * This constant is used to identify a IMU Bricklet 3.0.
 *
 * The {@link imu_v3_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define TF_IMU_V3_DEVICE_IDENTIFIER 2161

/**
 * \ingroup BrickletIMUV3
 *
 * This constant represents the display name of a IMU Bricklet 3.0.
 */
#define TF_IMU_V3_DEVICE_DISPLAY_NAME "IMU Bricklet 3.0"

/**
 * \ingroup BrickletIMUV3
 *
 * Creates the device object \c imu_v3 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_imu_v3_create(TF_IMUV3 *imu_v3, const char *uid, TF_HalContext *hal);

/**
 * \ingroup BrickletIMUV3
 *
 * Removes the device object \c imu_v3 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_imu_v3_destroy(TF_IMUV3 *imu_v3);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the imu_v3_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_response_expected(TF_IMUV3 *imu_v3, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletIMUV3
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
TF_ATTRIBUTE_NONNULL_ALL int tf_imu_v3_set_response_expected(TF_IMUV3 *imu_v3, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletIMUV3
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
TF_ATTRIBUTE_NONNULL_ALL void tf_imu_v3_set_response_expected_all(TF_IMUV3 *imu_v3, bool response_expected);
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletIMUV3
 *
 * Registers the given \c handler to the Acceleration callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int16_t x, int16_t y, int16_t z, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_imu_v3_set_acceleration_callback_configuration}. The parameters are the acceleration
 * for the x, y and z axis.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_imu_v3_register_acceleration_callback(TF_IMUV3 *imu_v3, TF_IMUV3AccelerationHandler handler, void *user_data);


/**
 * \ingroup BrickletIMUV3
 *
 * Registers the given \c handler to the Magnetic Field callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int16_t x, int16_t y, int16_t z, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_imu_v3_set_magnetic_field_callback_configuration}. The parameters are the magnetic
 * field for the x, y and z axis.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_imu_v3_register_magnetic_field_callback(TF_IMUV3 *imu_v3, TF_IMUV3MagneticFieldHandler handler, void *user_data);


/**
 * \ingroup BrickletIMUV3
 *
 * Registers the given \c handler to the Angular Velocity callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int16_t x, int16_t y, int16_t z, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_imu_v3_set_angular_velocity_callback_configuration}. The parameters are the angular
 * velocity for the x, y and z axis.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_imu_v3_register_angular_velocity_callback(TF_IMUV3 *imu_v3, TF_IMUV3AngularVelocityHandler handler, void *user_data);


/**
 * \ingroup BrickletIMUV3
 *
 * Registers the given \c handler to the Temperature callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int8_t temperature, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_imu_v3_set_temperature_callback_configuration}. The parameter is the temperature.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_imu_v3_register_temperature_callback(TF_IMUV3 *imu_v3, TF_IMUV3TemperatureHandler handler, void *user_data);


/**
 * \ingroup BrickletIMUV3
 *
 * Registers the given \c handler to the Linear Acceleration callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int16_t x, int16_t y, int16_t z, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_imu_v3_set_linear_acceleration_callback_configuration}. The parameters are the
 * linear acceleration for the x, y and z axis.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_imu_v3_register_linear_acceleration_callback(TF_IMUV3 *imu_v3, TF_IMUV3LinearAccelerationHandler handler, void *user_data);


/**
 * \ingroup BrickletIMUV3
 *
 * Registers the given \c handler to the Gravity Vector callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int16_t x, int16_t y, int16_t z, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_imu_v3_set_gravity_vector_callback_configuration}. The parameters gravity vector
 * for the x, y and z axis.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_imu_v3_register_gravity_vector_callback(TF_IMUV3 *imu_v3, TF_IMUV3GravityVectorHandler handler, void *user_data);


/**
 * \ingroup BrickletIMUV3
 *
 * Registers the given \c handler to the Orientation callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int16_t heading, int16_t roll, int16_t pitch, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_imu_v3_set_orientation_callback_configuration}. The parameters are the orientation
 * (heading (yaw), roll, pitch) of the IMU Brick in Euler angles. See
 * {@link tf_imu_v3_get_orientation} for details.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_imu_v3_register_orientation_callback(TF_IMUV3 *imu_v3, TF_IMUV3OrientationHandler handler, void *user_data);


/**
 * \ingroup BrickletIMUV3
 *
 * Registers the given \c handler to the Quaternion callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int16_t w, int16_t x, int16_t y, int16_t z, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_imu_v3_set_quaternion_callback_configuration}. The parameters are the orientation
 * (w, x, y, z) of the IMU Brick in quaternions. See {@link tf_imu_v3_get_quaternion}
 * for details.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_imu_v3_register_quaternion_callback(TF_IMUV3 *imu_v3, TF_IMUV3QuaternionHandler handler, void *user_data);


/**
 * \ingroup BrickletIMUV3
 *
 * Registers the given \c handler to the All Data callback. The
 * \c user_data will be passed as the last parameter to the \c handler.
 *
 * Signature: \code void callback(int16_t acceleration[3], int16_t magnetic_field[3], int16_t angular_velocity[3], int16_t euler_angle[3], int16_t quaternion[4], int16_t linear_acceleration[3], int16_t gravity_vector[3], int8_t temperature, uint8_t calibration_status, void *user_data) \endcode
 * 
 * This callback is triggered periodically with the period that is set by
 * {@link tf_imu_v3_set_all_data_callback_configuration}. The parameters are as for
 * {@link tf_imu_v3_get_all_data}.
 */
TF_ATTRIBUTE_NONNULL(1) void tf_imu_v3_register_all_data_callback(TF_IMUV3 *imu_v3, TF_IMUV3AllDataHandler handler, void *user_data);
#endif
#ifdef TF_IMPLEMENT_CALLBACKS
/**
 * \ingroup BrickletIMUV3
 *
 * Polls for callbacks. Will block for the given timeout in microseconds.
 *
 * This function can be used in a non-blocking fashion by calling it with a timeout of 0.
 */
TF_ATTRIBUTE_NONNULL_ALL int tf_imu_v3_callback_tick(TF_IMUV3 *imu_v3, uint32_t timeout_us);
#endif

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the calibrated acceleration from the accelerometer for the
 * x, y and z axis. The acceleration is in the range configured with
 * {@link tf_imu_v3_set_sensor_configuration}.
 * 
 * If you want to get the acceleration periodically, it is recommended
 * to use the {@link tf_imu_v3_register_acceleration_callback} callback and set the period with
 * {@link tf_imu_v3_set_acceleration_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_acceleration(TF_IMUV3 *imu_v3, int16_t *ret_x, int16_t *ret_y, int16_t *ret_z);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the calibrated magnetic field from the magnetometer for the
 * x, y and z axis.
 * 
 * If you want to get the magnetic field periodically, it is recommended
 * to use the {@link tf_imu_v3_register_magnetic_field_callback} callback and set the period with
 * {@link tf_imu_v3_set_magnetic_field_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_magnetic_field(TF_IMUV3 *imu_v3, int16_t *ret_x, int16_t *ret_y, int16_t *ret_z);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the calibrated angular velocity from the gyroscope for the
 * x, y and z axis. The angular velocity is in the range configured with
 * {@link tf_imu_v3_set_sensor_configuration}.
 * 
 * If you want to get the angular velocity periodically, it is recommended
 * to use the {@link tf_imu_v3_register_angular_velocity_callback} acallback nd set the period with
 * {@link tf_imu_v3_set_angular_velocity_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_angular_velocity(TF_IMUV3 *imu_v3, int16_t *ret_x, int16_t *ret_y, int16_t *ret_z);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the temperature of the IMU Brick.
 * The temperature is measured in the core of the BNO055 IC, it is not the
 * ambient temperature
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_temperature(TF_IMUV3 *imu_v3, int8_t *ret_temperature);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the current orientation (heading, roll, pitch) of the IMU Brick as
 * independent Euler angles. Note that Euler angles always
 * experience a `gimbal lock <https://en.wikipedia.org/wiki/Gimbal_lock>`__.
 * We recommend that you use quaternions instead, if you need the absolute
 * orientation.
 * 
 * If you want to get the orientation periodically, it is recommended
 * to use the {@link tf_imu_v3_register_orientation_callback} callback and set the period with
 * {@link tf_imu_v3_set_orientation_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_orientation(TF_IMUV3 *imu_v3, int16_t *ret_heading, int16_t *ret_roll, int16_t *ret_pitch);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the linear acceleration of the IMU Brick for the
 * x, y and z axis. The acceleration is in the range configured with
 * {@link tf_imu_v3_set_sensor_configuration}.
 * 
 * The linear acceleration is the acceleration in each of the three
 * axis of the IMU Brick with the influences of gravity removed.
 * 
 * It is also possible to get the gravity vector with the influence of linear
 * acceleration removed, see {@link tf_imu_v3_get_gravity_vector}.
 * 
 * If you want to get the linear acceleration periodically, it is recommended
 * to use the {@link tf_imu_v3_register_linear_acceleration_callback} callback and set the period with
 * {@link tf_imu_v3_set_linear_acceleration_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_linear_acceleration(TF_IMUV3 *imu_v3, int16_t *ret_x, int16_t *ret_y, int16_t *ret_z);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the current gravity vector of the IMU Brick for the
 * x, y and z axis.
 * 
 * The gravity vector is the acceleration that occurs due to gravity.
 * Influences of additional linear acceleration are removed.
 * 
 * It is also possible to get the linear acceleration with the influence
 * of gravity removed, see {@link tf_imu_v3_get_linear_acceleration}.
 * 
 * If you want to get the gravity vector periodically, it is recommended
 * to use the {@link tf_imu_v3_register_gravity_vector_callback} callback and set the period with
 * {@link tf_imu_v3_set_gravity_vector_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_gravity_vector(TF_IMUV3 *imu_v3, int16_t *ret_x, int16_t *ret_y, int16_t *ret_z);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the current orientation (w, x, y, z) of the IMU Brick as
 * `quaternions <https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation>`__.
 * 
 * You have to divide the return values by 16383 (14 bit) to get
 * the usual range of -1.0 to +1.0 for quaternions.
 * 
 * If you want to get the quaternions periodically, it is recommended
 * to use the {@link tf_imu_v3_register_quaternion_callback} callback and set the period with
 * {@link tf_imu_v3_set_quaternion_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_quaternion(TF_IMUV3 *imu_v3, int16_t *ret_w, int16_t *ret_x, int16_t *ret_y, int16_t *ret_z);

/**
 * \ingroup BrickletIMUV3
 *
 * Return all of the available data of the IMU Brick.
 * 
 * * acceleration (see {@link tf_imu_v3_get_acceleration})
 * * magnetic field (see {@link tf_imu_v3_get_magnetic_field})
 * * angular velocity (see {@link tf_imu_v3_get_angular_velocity})
 * * Euler angles (see {@link tf_imu_v3_get_orientation})
 * * quaternion (see {@link tf_imu_v3_get_quaternion})
 * * linear acceleration (see {@link tf_imu_v3_get_linear_acceleration})
 * * gravity vector (see {@link tf_imu_v3_get_gravity_vector})
 * * temperature (see {@link tf_imu_v3_get_temperature})
 * * calibration status (see below)
 * 
 * The calibration status consists of four pairs of two bits. Each pair
 * of bits represents the status of the current calibration.
 * 
 * * bit 0-1: Magnetometer
 * * bit 2-3: Accelerometer
 * * bit 4-5: Gyroscope
 * * bit 6-7: System
 * 
 * A value of 0 means for "not calibrated" and a value of 3 means
 * "fully calibrated". In your program you should always be able to
 * ignore the calibration status, it is used by the calibration
 * window of the Brick Viewer and it can be ignored after the first
 * calibration. See the documentation in the calibration window for
 * more information regarding the calibration of the IMU Brick.
 * 
 * If you want to get the data periodically, it is recommended
 * to use the {@link tf_imu_v3_register_all_data_callback} callback and set the period with
 * {@link tf_imu_v3_set_all_data_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_all_data(TF_IMUV3 *imu_v3, int16_t ret_acceleration[3], int16_t ret_magnetic_field[3], int16_t ret_angular_velocity[3], int16_t ret_euler_angle[3], int16_t ret_quaternion[4], int16_t ret_linear_acceleration[3], int16_t ret_gravity_vector[3], int8_t *ret_temperature, uint8_t *ret_calibration_status);

/**
 * \ingroup BrickletIMUV3
 *
 * A call of this function saves the current calibration to be used
 * as a starting point for the next restart of continuous calibration
 * of the IMU Brick.
 * 
 * A return value of *true* means that the calibration could be used and
 * *false* means that it could not be used (this happens if the calibration
 * status is not "fully calibrated").
 * 
 * This function is used by the calibration window of the Brick Viewer, you
 * should not need to call it in your program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_save_calibration(TF_IMUV3 *imu_v3, bool *ret_calibration_done);

/**
 * \ingroup BrickletIMUV3
 *
 * Sets the available sensor configuration for the Magnetometer, Gyroscope and
 * Accelerometer. The Accelerometer Range is user selectable in all fusion modes,
 * all other configurations are auto-controlled in fusion mode.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_sensor_configuration(TF_IMUV3 *imu_v3, uint8_t magnetometer_rate, uint8_t gyroscope_range, uint8_t gyroscope_bandwidth, uint8_t accelerometer_range, uint8_t accelerometer_bandwidth);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the sensor configuration as set by {@link tf_imu_v3_set_sensor_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_sensor_configuration(TF_IMUV3 *imu_v3, uint8_t *ret_magnetometer_rate, uint8_t *ret_gyroscope_range, uint8_t *ret_gyroscope_bandwidth, uint8_t *ret_accelerometer_range, uint8_t *ret_accelerometer_bandwidth);

/**
 * \ingroup BrickletIMUV3
 *
 * If the fusion mode is turned off, the functions {@link tf_imu_v3_get_acceleration},
 * {@link tf_imu_v3_get_magnetic_field} and {@link tf_imu_v3_get_angular_velocity} return uncalibrated
 * and uncompensated sensor data. All other sensor data getters return no data.
 * 
 * Since firmware version 2.0.6 you can also use a fusion mode without magnetometer.
 * In this mode the calculated orientation is relative (with magnetometer it is
 * absolute with respect to the earth). However, the calculation can't be influenced
 * by spurious magnetic fields.
 * 
 * Since firmware version 2.0.13 you can also use a fusion mode without fast
 * magnetometer calibration. This mode is the same as the normal fusion mode,
 * but the fast magnetometer calibration is turned off. So to find the orientation
 * the first time will likely take longer, but small magnetic influences might
 * not affect the automatic calibration as much.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_sensor_fusion_mode(TF_IMUV3 *imu_v3, uint8_t mode);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the sensor fusion mode as set by {@link tf_imu_v3_set_sensor_fusion_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_sensor_fusion_mode(TF_IMUV3 *imu_v3, uint8_t *ret_mode);

/**
 * \ingroup BrickletIMUV3
 *
 * The period is the period with which the {@link tf_imu_v3_register_acceleration_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_acceleration_callback_configuration(TF_IMUV3 *imu_v3, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the callback configuration as set by {@link tf_imu_v3_set_acceleration_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_acceleration_callback_configuration(TF_IMUV3 *imu_v3, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * The period is the period with which the {@link tf_imu_v3_register_magnetic_field_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_magnetic_field_callback_configuration(TF_IMUV3 *imu_v3, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the callback configuration as set by {@link tf_imu_v3_set_magnetic_field_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_magnetic_field_callback_configuration(TF_IMUV3 *imu_v3, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * The period is the period with which the {@link tf_imu_v3_register_angular_velocity_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_angular_velocity_callback_configuration(TF_IMUV3 *imu_v3, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the callback configuration as set by {@link tf_imu_v3_set_angular_velocity_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_angular_velocity_callback_configuration(TF_IMUV3 *imu_v3, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * The period is the period with which the {@link tf_imu_v3_register_temperature_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_temperature_callback_configuration(TF_IMUV3 *imu_v3, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the callback configuration as set by {@link tf_imu_v3_set_temperature_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_temperature_callback_configuration(TF_IMUV3 *imu_v3, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * The period is the period with which the {@link tf_imu_v3_register_orientation_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_orientation_callback_configuration(TF_IMUV3 *imu_v3, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the callback configuration as set by {@link tf_imu_v3_set_orientation_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_orientation_callback_configuration(TF_IMUV3 *imu_v3, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * The period is the period with which the {@link tf_imu_v3_register_linear_acceleration_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_linear_acceleration_callback_configuration(TF_IMUV3 *imu_v3, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the callback configuration as set by {@link tf_imu_v3_set_linear_acceleration_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_linear_acceleration_callback_configuration(TF_IMUV3 *imu_v3, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * The period is the period with which the {@link tf_imu_v3_register_gravity_vector_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_gravity_vector_callback_configuration(TF_IMUV3 *imu_v3, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the callback configuration as set by {@link tf_imu_v3_set_gravity_vector_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_gravity_vector_callback_configuration(TF_IMUV3 *imu_v3, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * The period is the period with which the {@link tf_imu_v3_register_quaternion_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_quaternion_callback_configuration(TF_IMUV3 *imu_v3, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the callback configuration as set by {@link tf_imu_v3_set_quaternion_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_quaternion_callback_configuration(TF_IMUV3 *imu_v3, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * The period is the period with which the {@link tf_imu_v3_register_all_data_callback} callback
 * is triggered periodically. A value of 0 turns the callback off.
 * 
 * If the `value has to change`-parameter is set to true, the callback is only
 * triggered after the value has changed. If the value didn't change within the
 * period, the callback is triggered immediately on change.
 * 
 * If it is set to false, the callback is continuously triggered with the period,
 * independent of the value.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_all_data_callback_configuration(TF_IMUV3 *imu_v3, uint32_t period, bool value_has_to_change);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the callback configuration as set by {@link tf_imu_v3_set_all_data_callback_configuration}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_all_data_callback_configuration(TF_IMUV3 *imu_v3, uint32_t *ret_period, bool *ret_value_has_to_change);

/**
 * \ingroup BrickletIMUV3
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
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_spitfp_error_count(TF_IMUV3 *imu_v3, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletIMUV3
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
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_bootloader_mode(TF_IMUV3 *imu_v3, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the current bootloader mode, see {@link tf_imu_v3_set_bootloader_mode}.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_bootloader_mode(TF_IMUV3 *imu_v3, uint8_t *ret_mode);

/**
 * \ingroup BrickletIMUV3
 *
 * Sets the firmware pointer for {@link tf_imu_v3_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_write_firmware_pointer(TF_IMUV3 *imu_v3, uint32_t pointer);

/**
 * \ingroup BrickletIMUV3
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link tf_imu_v3_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_write_firmware(TF_IMUV3 *imu_v3, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletIMUV3
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_set_status_led_config(TF_IMUV3 *imu_v3, uint8_t config);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the configuration as set by {@link tf_imu_v3_set_status_led_config}
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_status_led_config(TF_IMUV3 *imu_v3, uint8_t *ret_config);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_chip_temperature(TF_IMUV3 *imu_v3, int16_t *ret_temperature);

/**
 * \ingroup BrickletIMUV3
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_reset(TF_IMUV3 *imu_v3);

/**
 * \ingroup BrickletIMUV3
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_write_uid(TF_IMUV3 *imu_v3, uint32_t uid);

/**
 * \ingroup BrickletIMUV3
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_read_uid(TF_IMUV3 *imu_v3, uint32_t *ret_uid);

/**
 * \ingroup BrickletIMUV3
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
TF_ATTRIBUTE_NONNULL(1) int tf_imu_v3_get_identity(TF_IMUV3 *imu_v3, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
