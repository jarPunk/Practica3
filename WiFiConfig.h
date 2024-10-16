#ifndef WIFICONFIG_H
#define WIFICONFIG_H

#include <WiFi.h>

class WiFiConfig {
  private:
    const char* ssid;
    const char* password;

  public:
    WiFiConfig(const char* ssid, const char* password) {
      this->ssid = ssid;
      this->password = password;
    }

    void connect() {
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Conectando al WiFi...");
      }
      Serial.println("Conectado al WiFi");
    }
};

#endif
