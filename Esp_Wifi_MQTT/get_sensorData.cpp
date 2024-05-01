#include "get_sensorData.h"

DHT dht(DHTPIN, DHTTYPE);

float voltage;
int bat_percentage;
int sensorValue;


void dht_Init() {
  dht.begin();
  display_setup("All Sensors");
}

float get_temp() {
  return dht.readTemperature();
}

float get_hum() {
  return dht.readHumidity();
}

float get_voltage() {
  sensorValue = analogRead(V_SENSOR);
  voltage = (((sensorValue * 3.3) / 4096) * 2 + BATT_CALIBRATION); //multiply by two as voltage divider network is 100K & 100K Resistor
  return voltage;
}

float get_persentage() {
  sensorValue = analogRead(V_SENSOR);
  voltage = (((sensorValue * 3.3) / 4096) * 2 + BATT_CALIBRATION); //multiply by two as voltage divider network is 100K & 100K Resistor
  bat_percentage = mapfloat(voltage, CUTOFF_VOLTAGE, MAX_VOLTAGE, 0, 100); //2.8V as Battery Cut off Voltage & 4.2V as Maximum Voltage

  if (bat_percentage >= 100)
  {
    bat_percentage = 100;
    return bat_percentage;
  }
  else if (bat_percentage <= 0)
  {
    bat_percentage = 1;
    return bat_percentage;
  }
  else return bat_percentage;
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
