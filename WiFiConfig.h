#ifndef WIFICONFIG_H
#define WIFICONFIG_H

#include <WiFi.h>

// Configuración de WiFi
const char* ssid = "Jar_Punk";
const char* password = "doom3242";

void setupWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando al WiFi...");
  }
  Serial.println("Conectado al WiFi");
}

#endif
