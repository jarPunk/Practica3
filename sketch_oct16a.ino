#include <WiFi.h>
#include <PubSubClient.h>
#include "WiFiConfig.h"
#include "MQTTConfig.h"
#include "BuzzerConfig.h"
#include "PulseSensor.h"
#include "Callback.h"


const char* ssid = "Prueba";
const char* password = "12345678";
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttTopic = "buzzer/control";
const char* mqttPulseTopic = "sensor/pulso";


WiFiClient espClient;
PubSubClient client(espClient);


WiFiConfig wifiConfig(ssid, password);
MQTTConfig mqttConfig(mqttServer, mqttPort, mqttTopic, mqttPulseTopic, client);
BuzzerConfig buzzerConfig(13);
PulseSensor pulseSensor(32);
Callback callback(buzzerConfig);

unsigned long previousMillis = 0;
const long interval = 5000; 


void mqttCallback(char* topic, byte* payload, unsigned int length) {
  callback.handleCallback(topic, payload, length);
}

void setup() {
  Serial.begin(115200);

  
  wifiConfig.connect();

  
  mqttConfig.setCallback(mqttCallback);
  mqttConfig.connect();
}

void loop() {
  mqttConfig.loop();

  
  int pulseValue = pulseSensor.read();

  
  if (pulseValue > 1000) {
    pulseSensor.countPulse();
  }

  
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    int pulsePerMinute = pulseSensor.calculatePPM();  
    pulseSensor.resetCount(); 

    
    String pulseMessage = String(pulsePerMinute);
    mqttConfig.publish(mqttPulseTopic, pulseMessage.c_str());
  }

  delay(100); 
}
