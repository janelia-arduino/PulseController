// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef PULSE_CONTROLLER_CONSTANTS_H
#define PULSE_CONTROLLER_CONSTANTS_H
#include <ConstantVariable.h>
#include <PowerSwitchController.h>


namespace pulse_controller
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PROPERTY_COUNT_MAX=5};
enum{PARAMETER_COUNT_MAX=1};
enum{FUNCTION_COUNT_MAX=1};
enum{CALLBACK_COUNT_MAX=1};

extern ConstantString device_name;

extern ConstantString firmware_name;
extern const modular_server::FirmwareInfo firmware_info;

// Pins

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern ConstantString pulse_channels_property_name;
extern const long pulse_channels_default[power_switch_controller::constants::CHANNEL_COUNT];
extern const size_t pulse_channels_array_length_min;
extern const size_t pulse_channels_array_length_default;

extern ConstantString pulse_delay_property_name;
extern const long pulse_delay_default;

extern ConstantString pulse_period_property_name;
extern const long pulse_period_default;

extern ConstantString pulse_on_duration_property_name;
extern const long pulse_on_duration_default;

extern ConstantString pulse_count_property_name;
extern const long pulse_count_default;

// Parameters

// Functions

// Callbacks
extern ConstantString pulse_callback_name;

// Errors
}
}
#include "5x3.h"
#include "3x2.h"
#endif
