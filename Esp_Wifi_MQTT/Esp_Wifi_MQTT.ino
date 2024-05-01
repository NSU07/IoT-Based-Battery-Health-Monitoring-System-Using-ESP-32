#include "settings.h"
#include "wifi_client.h"
#include "send_data.h"
#include "display.h"



unsigned long lastMsg = 0;

void setup() {
  Serial.begin(SER_BOUD);
  display_Init();
  dht_Init();
  setup_wifi();
  set_mqtt();
}

void loop() {
  mqtt_loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    send_data();

  }
}
