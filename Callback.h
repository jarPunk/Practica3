#ifndef CALLBACK_H
#define CALLBACK_H

#include "BuzzerConfig.h"

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.print("Mensaje recibido: ");
  Serial.println(message);

  if (message == "ON") {
    digitalWrite(buzzerPin, HIGH);  
  } else if (message == "OFF") {
    digitalWrite(buzzerPin, LOW);   
  }
}

#endif
