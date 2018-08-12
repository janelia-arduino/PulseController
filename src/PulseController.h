// ----------------------------------------------------------------------------
// PulseController.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef PULSE_CONTROLLER_H
#define PULSE_CONTROLLER_H
#include <ArduinoJson.h>
#include <JsonSanitizer.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <ConstantVariable.h>
#include <Functor.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>
#include <PowerSwitchController.h>

#include "PulseController/Constants.h"


class PulseController : public PowerSwitchController
{
public:
  PulseController();
  virtual void setup();

  void pulse();

private:
  modular_server::Property properties_[pulse_controller::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[pulse_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[pulse_controller::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[pulse_controller::constants::CALLBACK_COUNT_MAX];

  // Handlers
  void pulseHandler(modular_server::Pin * pin_ptr);

};

#endif
