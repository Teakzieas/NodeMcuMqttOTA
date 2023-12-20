#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <vector>

/****** WiFi Connection Details *******/
const char* ssid = "divyessh";
const char* password = "divyessh";

/******* MQTT Broker Connection Details *******/
const char* mqtt_server = "www.svntech.one";
const char* mqtt_username = "User1";
const char* mqtt_password = "qwerty";
const char* mqtt_id = "ESP8266Client";
bool connected = false;
#define ledPin  D4

/******* MQTT Topic Details *******/
std::vector<String> mqtt_topics;

/**** WiFi and MQTT Connectivity Initialisation *****/
WiFiClient espClient;
PubSubClient client(espClient);

bool FirstRun = false;
char* mqtt_log = "";

void MsgReceived(String topic, String payload);
void reconnectMqtt();
void mqttSetup(char* mqtt_log_channel,std::vector<String> topics);
void callback(char* topic, byte* payload, unsigned int length);
void mqttloop();

void reconnectMqtt() 
{
  if (!client.connected()) 
  {
    connected = false;
    digitalWrite(ledPin, HIGH);
    while (!client.connected()) 
    {
      Serial.println("Connecting to MQTT...");
      if (client.connect(mqtt_id, mqtt_username, mqtt_password)) 
      { 
        for (const auto& str : mqtt_topics) {
          client.subscribe(str.c_str());
        }
      } 
      else 
      {
        delay(5000);
      }
    }
  }
  else 
  {
    if(!connected)
    {
      Serial.println("connected to MQTT");
      connected = true;
    }
    
    digitalWrite(ledPin, LOW);
  }
}
void mqttSetup(char* mqtt_log_channel,std::vector<String> topics)
{
  mqtt_log = mqtt_log_channel;
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  mqtt_topics = topics;
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}
void callback(char* topic, byte* payload, unsigned int length) 
{
  // Handle MQTT messages
  payload[length] = '\0'; // Null-terminate the payload
  MsgReceived(topic, (char*)payload);
}
void mqttloop()
{
  
  reconnectMqtt();
  client.loop();
  if(!FirstRun)
  {
    client.publish(mqtt_log, (String(mqtt_id)+String(" connected")).c_str());
    FirstRun = true;
  }
}