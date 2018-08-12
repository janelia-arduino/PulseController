// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "Constants.h"


namespace pulse_controller
{
namespace constants
{
CONSTANT_STRING(device_name,"pulse_controller");

CONSTANT_STRING(firmware_name,"PulseController");
// Use semantic versioning http://semver.org/
const modular_server::FirmwareInfo firmware_info =
{
  .name_ptr=&firmware_name,
  .version_major=1,
  .version_minor=0,
  .version_patch=1,
};

// Pins

// Units

// Properties
CONSTANT_STRING(pulse_channels_property_name,"pulseChannels");
const long pulse_channels_default[power_switch_controller::constants::CHANNEL_COUNT] = {0};
const size_t pulse_channels_array_length_min = 1;
const size_t pulse_channels_array_length_default = 1;

CONSTANT_STRING(pulse_delay_property_name,"pulseDelay");
const long pulse_delay_default = 0;

CONSTANT_STRING(pulse_period_property_name,"pulsePeriod");
const long pulse_period_default = 100;

CONSTANT_STRING(pulse_on_duration_property_name,"pulseOnDuration");
const long pulse_on_duration_default = 50;

CONSTANT_STRING(pulse_count_property_name,"pulseCount");
const long pulse_count_default = 1;

// Parameters

// Functions

// Callbacks
CONSTANT_STRING(pulse_callback_name,"pulse");

// Errors
}
}
