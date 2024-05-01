#include "settings.h"
#include "DHT.h"
#include "display.h"

void dht_Init();
float get_temp();
float get_hum();

float get_persentage();
float get_voltage();
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
