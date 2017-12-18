// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
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
    .version_patch=0,
  };

// Interrupts

// Units

// Properties
CONSTANT_STRING(pulse_channels_property_name,"pulseChannels");
const long pulse_channels_default[power_switch_controller::constants::CHANNEL_COUNT] = {0};

// Parameters

// Functions

// Callbacks
CONSTANT_STRING(pulse_callback_name,"pulse");

// Errors
}
}
