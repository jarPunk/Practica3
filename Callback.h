#ifndef CALLBACK_H
#define CALLBACK_H

#include "BuzzerConfig.h"

class Callback {
  private:
    BuzzerConfig& buzzerConfig;

  public:
    Callback(BuzzerConfig& buzzer) : buzzerConfig(buzzer) {}

    void handleCallback(char* topic, byte* payload, unsigned int length) {
      String message = "";
      for (int i = 0; i < length; i++) {
        message += (char)payload[i];
      }
      Serial.print("Mensaje recibido: ");
      Serial.println(message);

      
      if (message == "ON") {
        buzzerConfig.on();  
      } else if (message == "OFF") {
        buzzerConfig.off();  
      }
    }
};

#endif
