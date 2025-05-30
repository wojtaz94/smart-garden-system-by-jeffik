#include <WiFi.h>
#include <PubSubClient.h>
#include "config.h"

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void reconnect() {
  while (!client.connected()) {
    client.connect("ESP32Client");
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(MQTT_SERVER, MQTT_PORT);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  int soil = analogRead(SOIL_PIN);
  float temp = 24.5; // Przykładowa temperatura
  String topic = "ogrodek/grzadka" + String(PLANT_ID) + "/wilgotnosc";
  client.publish(topic.c_str(), String(soil).c_str());
  delay(300000); // 5 minut
}