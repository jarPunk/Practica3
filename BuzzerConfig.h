#ifndef BUZZERCONFIG_H
#define BUZZERCONFIG_H

const int buzzerPin = 13;

void setupBuzzer() {
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);  
}

#endif
