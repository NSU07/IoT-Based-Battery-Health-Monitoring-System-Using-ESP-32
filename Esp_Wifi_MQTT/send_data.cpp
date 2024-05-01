#include "send_data.h"

void send_data() {
  float batt_persent = get_persentage();
  float batt_voltage = get_voltage();
  float temp = get_temp();
  float hum = get_hum();
  show_display(batt_voltage, batt_persent, temp, hum);
  mqttPublish(batt_voltage, batt_persent, temp, hum);
  single_MqttPublish(batt_voltage, batt_persent, temp, hum);
}
