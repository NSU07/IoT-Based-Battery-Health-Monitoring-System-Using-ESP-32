#include "wifi_client.h"
WiFiClient espClient;
PubSubClient client(espClient);


void mqttCallback(char* topic, byte* payload, unsigned int len) {

  if (payload) {
    recived_payload = "";
    for (int k = 0; k < len; ++k) {
      recived_payload += String(char(payload[k]));
    }
    Serial.println(recived_payload);
    deserialize_Payload();
    //    mqttPublish();
  }
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());
  display_setup("WiFi");

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void set_mqtt() {
  display_setup("MQTT");
  client.setServer(mqtt_server, 1883);
  client.setCallback(mqttCallback);
}



void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");

    // Attempt to connect
    if (client.connect(DEVICE_ID)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish(topicOut, "Smart Battery Monitoring Device Started!");
      // ... and resubscribe
      client.subscribe(topicIn);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void mqtt_loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void mqttPublish(float batt_voltage, float batt_persent, float temp, float hum) {
  if (client.connected()) {

    char Buf[JSON_DOCUMENT_SIZE];
    String transmitt_Payload = serialize_Payload(batt_voltage, batt_persent, temp, hum);
    transmitt_Payload.toCharArray(Buf, JSON_DOCUMENT_SIZE);
    client.publish(topicOut, Buf);
    //Clear All Value Stored on Gateway
    transmitt_Payload = "";
  }
}


void single_MqttPublish(float batt_voltage, float batt_persent, float temp, float hum) {
  if (client.connected()) {

    char Voltage_Buff[50];
    to_Str(batt_voltage).toCharArray(Voltage_Buff, 50);

    char Percent_Buff[50];
    to_Str(batt_persent).toCharArray(Percent_Buff, 50);

    char Temp_Buff[50];
    to_Str(temp).toCharArray(Temp_Buff, 50);

    char Hum_Buff[50];
    to_Str(hum).toCharArray(Hum_Buff, 50);



    client.publish(topicVoltage, Voltage_Buff);
    delay(200);
    client.publish(topicPercent, Percent_Buff);
    delay(200);
    client.publish(topicTemp, Temp_Buff);
    delay(200);
    client.publish(topicHum, Hum_Buff);
    delay(200);


  }

}

String to_Str(float in_value) {
  String return_Str = String(in_value);
  return return_Str;
}
