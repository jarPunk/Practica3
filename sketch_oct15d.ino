#include <WiFi.h>
#include <PubSubClient.h>
#include "WiFiConfig.h"
#include "MQTTConfig.h"
#include "BuzzerConfig.h"
#include "PulseSensor.h"
#include "Callback.h"

unsigned long previousMillis = 0;
const long interval = 5000; // Intervalo de 5 segundos

void setup() {
  Serial.begin(115200);

  setupBuzzer();
  setupPulseSensor();
  setupWiFi();
  
  client.setCallback(callback);
  setupMQTT();
}

void loop() {
  client.loop();

  
  pulseValue = readPulse();

 
  if (pulseValue > 1000) { 
    pulseCount++;
  }

  
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    int pulsePerMinute = calculatePPM();  
    pulseCount = 0;  
    
    String pulseMessage = String(pulsePerMinute);
    client.publish(mqttPulseTopic, pulseMessage.c_str());
  }

  delay(100);  
}
