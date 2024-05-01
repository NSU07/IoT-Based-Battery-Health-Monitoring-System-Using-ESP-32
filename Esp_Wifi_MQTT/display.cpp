#include "display.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void display_setup(String value) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 5);            // Start at top-left corner
  display.println(F("----Please Wait!----"));
  display.println(F(""));
  display.println(F(""));
  display.print(F("Setting: "));
  display.println(value);
  

  display.display();
  delay(2000);
}
void display_Init() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 5);            // Start at top-left corner
  display.println(F("----Please Wait!----"));

  display.setTextSize(2);             // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(16, 32);
  display.print(F("Booting"));
  display.display();
  delay(6000);
}

void show_display(float batt_voltage, float batt_persent, float temp, float hum) {
  display.clearDisplay();

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0, 0);            // Start at top-left corner
  display.print(F("Voltage:"));
  display.print(batt_voltage);
  display.println(F("V"));
  display.println(F(""));

  display.print(F("Battery Left:"));
  display.print(batt_persent);
  display.println(F("%"));
  display.println(F(""));

  display.print(F("Temperature:"));
  display.print(temp);
  display.println(F("C"));
  display.println(F(""));

  display.print(F("Humidity:"));
  display.print(hum);
  display.println(F("%"));


  display.display();
  delay(100);
}
