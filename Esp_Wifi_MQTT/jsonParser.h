#include <ArduinoJson.h>
#include "settings.h"

extern String recived_payload;

String serialize_Payload(float batt_voltage, float batt_persent, float temp, float hum);
void deserialize_Payload();
double round2(double value);
