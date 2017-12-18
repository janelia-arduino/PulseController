// ----------------------------------------------------------------------------
// PulseController.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef PULSE_CONTROLLER_H
#define PULSE_CONTROLLER_H
#include <Flash.h>
#include <EEPROM.h>
#include <Streaming.h>
#include <ArduinoJson.h>
#include <JsonSanitizer.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <MemoryFree.h>
#include <ConstantVariable.h>
#include <SavedVariable.h>
#include <Functor.h>
#include <IndexedContainer.h>
#include <FunctorCallbacks.h>
#include <Watchdog.h>

#include <ModularClient.h>

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
  void pulseHandler(modular_server::Interrupt * interrupt_ptr);

};

#endif
