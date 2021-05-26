#ifndef KTM_PRESSURETRANSDUCER_LIB_H
#define KTM_PRESSURETRANSDUCER_LIB_H

#include <Arduino.h>

class KTM_PressureTransducer {
  public:
    KTM_PressureTransducer(int pin);
    void setMaxPSI(int maxPSI);
    int getMaxPSI();
    void setCalibration(int pressureZero, int pressureMax);
    float getPSI();

  private:
    int _inputPin;
    int _maxPSI;
    int _pressureZero;
    int _pressureMax;
    float _pressureValue;
};

#endif