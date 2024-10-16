#ifndef MQTTCONFIG_H
#define MQTTCONFIG_H

#include <PubSubClient.h>

// Configuración de MQTT
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttTopic = "buzzer/control";
const char* mqttPulseTopic = "sensor/pulso";  

WiFiClient espClient;
PubSubClient client(espClient);

void setupMQTT() {
  client.setServer(mqttServer, mqttPort);
  while (!client.connected()) {
    Serial.println("Conectando al broker MQTT...");
    if (client.connect("ESP32BuzzerClient")) {
      Serial.println("Conectado al broker MQTT");
      client.subscribe(mqttTopic);  
    } else {
      Serial.print("Error de conexión al MQTT: ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

#endif
