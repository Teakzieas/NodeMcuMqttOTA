#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>


// Replace with your network credentials
const char* ssidota = "divyessh";
const char* passwordota = "divyessh";

void otaSetup() {
  Serial.println("OTA Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssidota, passwordota);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("OTA Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.onStart([]() {});
  ArduinoOTA.onEnd([]() {});
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {});
  ArduinoOTA.onError([](ota_error_t error) {});
  ArduinoOTA.begin();
  Serial.println("OTA Ready");
  Serial.print("OTA IP address: ");
  Serial.println(WiFi.localIP());
}
void otaLoop() {
  ArduinoOTA.handle();
}