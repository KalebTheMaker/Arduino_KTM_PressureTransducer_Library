#include "KTM_PressureTransducer.h";

float psi;
KTM_PressureTransducer psiGuage(A0);

void setup() {
  Serial.begin(115200);
}

void loop() {
  psi = psiGuage.getPSI();
  Serial.print("Pressure: ");
  Serial.println(psi);
  delay(250);
}