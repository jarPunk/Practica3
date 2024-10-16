#ifndef MQTTCONFIG_H
#define MQTTCONFIG_H

#include <WiFi.h>
#include <PubSubClient.h>

class MQTTConfig {
  private:
    const char* mqttServer;
    int mqttPort;
    const char* mqttTopic;
    const char* mqttPulseTopic;
    PubSubClient& client;

  public:
    MQTTConfig(const char* server, int port, const char* topic, const char* pulseTopic, PubSubClient& clientRef) 
      : mqttServer(server), mqttPort(port), mqttTopic(topic), mqttPulseTopic(pulseTopic), client(clientRef) {}

    void connect() {
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

    void publish(const char* topic, const char* message) {
      client.publish(topic, message);
    }

    void loop() {
      client.loop();
    }

    void setCallback(MQTT_CALLBACK_SIGNATURE) {
      client.setCallback(callback);
    }
};

#endif
