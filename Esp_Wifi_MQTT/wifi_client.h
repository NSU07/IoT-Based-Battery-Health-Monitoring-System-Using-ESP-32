#include "settings.h"
#include "jsonParser.h"
#include "display.h"
#include <WiFi.h>
#include <PubSubClient.h>

void setup_wifi();
void set_mqtt();
void mqtt_loop();
void mqttPublish(float batt_voltage, float batt_persent, float temp, float hum);
void single_MqttPublish(float batt_voltage, float batt_persent, float temp, float hum);
String to_Str(float in_value);
