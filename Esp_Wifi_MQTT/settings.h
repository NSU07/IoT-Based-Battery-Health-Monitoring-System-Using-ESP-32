#include <Arduino.h>

#define DEVICE_ID "SBMS001"
#define DEVICE_USERNAME "SBMS001"
#define DEVICE_PASS "SBMS001"


#define AP_SSID "ESP 32"
#define AP_PASS "iot12345"


#define BROKER "18.142.160.101" //http://13.250.61.118/


#define TOPIC_IN "v1/devices/me/rpc/request/+"
#define TOPIC_OUT "v1/devices/me/telemetry"

#define TOPIC_VOLTAGE DEVICE_ID"/Voltage"
#define TOPIC_PERCENT DEVICE_ID"/Percent"
#define TOPIC_TEMP    DEVICE_ID"/Temp"
#define TOPIC_HUM     DEVICE_ID"/Hum"

#define JSON_DOCUMENT_SIZE 200
#define SER_BOUD 115200 // Serial Baud Rate for Debugging

#define V_SENSOR 34
#define CUTOFF_VOLTAGE 2.8
#define MAX_VOLTAGE 4.2
#define BATT_CALIBRATION 0.37 // Check Battery voltage using multimeter & add/subtract the value

#define DHTPIN 4     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)







extern const char* ssid;
extern const char* password;
extern const char* mqtt_server;
extern const char* topicIn;
extern const char* topicOut;

extern const char* topicVoltage;
extern const char* topicPercent;
extern const char* topicTemp;
extern const char* topicHum;
