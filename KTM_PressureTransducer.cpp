#include <Arduino.h>
#include "KTM_PressureTransducer.h"

KTM_PressureTransducer::KTM_PressureTransducer(int pin) {
  _inputPin = pin;
  _pressureZero = 99.0;
  _pressureMax = 921.0;
  _maxPSI = 100;

}

void KTM_PressureTransducer::setMaxPSI(int maxPSI) {
  _maxPSI = maxPSI;
}

int KTM_PressureTransducer::getMaxPSI() {
  return _maxPSI;
}

void KTM_PressureTransducer::setCalibration(int pressureZero, int pressureMax) {
  _pressureZero = pressureZero;
  _pressureMax = pressureMax;
}

float KTM_PressureTransducer::getPSI() {
  _pressureValue = analogRead(_inputPin); //reads value from input pin and assigns to variable
  _pressureValue = ((_pressureValue-_pressureZero)*_maxPSI)/(_pressureMax-_pressureZero); //conversion equation to convert analog reading to psi
  return _pressureValue;
}