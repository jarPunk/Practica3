#ifndef PULSESENSOR_H
#define PULSESENSOR_H

const int pulsePin = 32;  
int pulseValue = 0;       
int pulseCount = 0;       

void setupPulseSensor() {
  pinMode(pulsePin, INPUT);   
}

int readPulse() {
  return analogRead(pulsePin);
}

int calculatePPM() {
  return pulseCount * 4;  
}

#endif
