#include "settings.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void display_setup(String value);
void display_Init();
void show_display(float batt_voltage, float batt_persent, float temp, float hum);
