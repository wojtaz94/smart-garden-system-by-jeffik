#include "esp_camera.h"
#include <WiFi.h>
#include "config.h"

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  camera_config_t config; 
  // Konfiguracja kamery (uzupełnij dla modelu kamery)
  esp_camera_init(&config);
}

void loop() {
  delay(60000); // Przykład pętli - tu będzie robienie zdjęcia i wysyłka
}