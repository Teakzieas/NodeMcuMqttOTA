#include <Arduino.h>
#include "mqttSetup.h"

void setup() 
{
  Serial.begin(115200);
  setupMQTT({"test1", "test2"});
}

void loop() 
{
  reconnectMqtt();
  client.loop();
}

void MsgReceived(String topic, String payload)
{
  Serial.println("Message arrived in topic: " + topic + " with payload: " + payload);
}