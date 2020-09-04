// ----------------------------------------------------------------------------
// PulseController.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "../PulseController.h"


using namespace pulse_controller;

PulseController::PulseController()
{
}

void PulseController::setup()
{
  // Parent Setup
  PowerSwitchController::setup();

  // Reset Watchdog
  resetWatchdog();

  // Variable Setup

  // Set Device ID
  modular_server_.setDeviceName(constants::device_name);

  // Add Hardware

  // Pins
  modular_server::Pin & bnc_a_pin = modular_server_.pin(modular_device_base::constants::bnc_a_pin_name);
  modular_server::Pin & btn_a_pin = modular_server_.pin(modular_device_base::constants::btn_a_pin_name);

#if defined(__MK64FX512__)
  modular_server::Pin & bnc_b_pin = modular_server_.pin(modular_device_base::constants::bnc_b_pin_name);
  modular_server::Pin & btn_b_pin = modular_server_.pin(modular_device_base::constants::btn_b_pin_name);
#endif

  // Add Firmware
  modular_server_.addFirmware(constants::firmware_info,
    properties_,
    parameters_,
    functions_,
    callbacks_);

  // Properties
  modular_server::Property & pulse_channels_property = modular_server_.createProperty(constants::pulse_channels_property_name,constants::pulse_channels_default);
  pulse_channels_property.setArrayLengthDefault(constants::pulse_channels_array_length_default);
  pulse_channels_property.setRange((long)0,(long)power_switch_controller::constants::CHANNEL_COUNT-1);

  modular_server::Property & pulse_delay_property = modular_server_.createProperty(constants::pulse_delay_property_name,constants::pulse_delay_default);
  pulse_delay_property.setUnits(power_switch_controller::constants::ms_units);
  pulse_delay_property.setRange(power_switch_controller::constants::delay_min,power_switch_controller::constants::delay_max);

  modular_server::Property & pulse_period_property = modular_server_.createProperty(constants::pulse_period_property_name,constants::pulse_period_default);
  pulse_period_property.setUnits(power_switch_controller::constants::ms_units);
  pulse_period_property.setRange(power_switch_controller::constants::period_min,power_switch_controller::constants::period_max);

  modular_server::Property & pulse_on_duration_property = modular_server_.createProperty(constants::pulse_on_duration_property_name,constants::pulse_on_duration_default);
  pulse_on_duration_property.setUnits(power_switch_controller::constants::ms_units);
  pulse_on_duration_property.setRange(power_switch_controller::constants::on_duration_min,power_switch_controller::constants::on_duration_max);

  modular_server::Property & pulse_count_property = modular_server_.createProperty(constants::pulse_count_property_name,constants::pulse_count_default);
  pulse_count_property.setUnits(power_switch_controller::constants::ms_units);
  pulse_count_property.setRange(power_switch_controller::constants::count_min,power_switch_controller::constants::count_max);

  // Parameters

  // Functions

  // Callbacks
  modular_server::Callback & pulse_callback = modular_server_.createCallback(constants::pulse_callback_name);
  pulse_callback.attachFunctor(makeFunctor((Functor1<modular_server::Pin *> *)0,*this,&PulseController::pulseHandler));
  pulse_callback.attachTo(bnc_a_pin,modular_server::constants::pin_mode_interrupt_falling);
  pulse_callback.attachTo(btn_a_pin,modular_server::constants::pin_mode_interrupt_falling);

}

void PulseController::pulse()
{
  modular_server::Property & pulse_channels_property = modular_server_.property(constants::pulse_channels_property_name);
  Array<long,power_switch_controller::constants::CHANNEL_COUNT> pulse_channels;
  pulse_channels_property.getValue(pulse_channels);
  uint32_t channels = 0;
  uint32_t bit = 1;
  for (size_t i=0; i<pulse_channels.size(); ++i)
  {
    long channel = pulse_channels[i];
    channels |= bit << channel;
  }

  long delay;
  modular_server_.property(constants::pulse_delay_property_name).getValue(delay);

  long period;
  modular_server_.property(constants::pulse_period_property_name).getValue(period);

  long on_duration;
  modular_server_.property(constants::pulse_on_duration_property_name).getValue(on_duration);

  long count;
  modular_server_.property(constants::pulse_count_property_name).getValue(count);

  addPwm(channels,
    delay,
    period,
    on_duration,
    count);
}

// Handlers must be non-blocking (avoid 'delay')
//
// modular_server_.parameter(parameter_name).getValue(value) value type must be either:
// fixed-point number (int, long, etc.)
// floating-point number (float, double)
// bool
// const char *
// ArduinoJson::JsonArray
// ArduinoJson::JsonObject
// const ConstantString *
//
// For more info read about ArduinoJson parsing https://github.com/janelia-arduino/ArduinoJson
//
// modular_server_.property(property_name).getValue(value) value type must match the property default type
// modular_server_.property(property_name).setValue(value) value type must match the property default type
// modular_server_.property(property_name).getElementValue(element_index,value) value type must match the property array element default type
// modular_server_.property(property_name).setElementValue(element_index,value) value type must match the property array element default type

void PulseController::pulseHandler(modular_server::Pin * pin_ptr)
{
  pulse();
}
