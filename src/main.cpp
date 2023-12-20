#include <Arduino.h>
#include "mqtt.h"
#include "ota.h"

void setup() 
{
  Serial.begin(115200);
  mqttSetup("NodemcuLog",{"test30", "test2"});
  otaSetup();
}

void loop() 
{
  otaLoop();
  mqttloop();
  
}

void MsgReceived(String topic, String payload)
{
  Serial.println("Message arrived in topic: " + topic + " with payload: " + payload);
}