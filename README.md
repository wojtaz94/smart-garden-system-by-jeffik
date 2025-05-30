# Smart Garden System

Projekt inteligentnego ogródka z ESP32, MQTT i AI analizą obrazu.

## Struktura

- `firmware/grzadka/` – oprogramowanie dla ESP32 z czujnikami
- `firmware/kamera/` – oprogramowanie dla ESP32-CAM
- `config.h` – dane sieci Wi-Fi, MQTT i numer grządki

## Instrukcja

1. Skonfiguruj `config.h` dla każdego ESP32.
2. Wgraj kod przez Arduino IDE.
3. Uruchom backend z Docker Compose lub ręcznie.
4. Korzystaj z aplikacji mobilnej i dashboardu Grafana.