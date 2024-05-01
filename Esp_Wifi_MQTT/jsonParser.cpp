#include "jsonParser.h"

String recived_payload;


//********************************************** Serialized JSON Payload***********************//
String serialize_Payload(float batt_voltage, float batt_persent, float temp, float hum) {
  String transmitt_Payload = "";

  StaticJsonDocument<JSON_DOCUMENT_SIZE> doc;
  JsonObject root = doc.to<JsonObject>();
  root ["ID"] = DEVICE_ID;
  root ["BV"] = round2(batt_voltage);
  root ["BP"] = batt_persent;
  root ["TM"] = round2(temp);
  root ["HM"] = round2(hum);
  serializeJson(doc, transmitt_Payload);
  root.clear();
  //  Serial.print(F("Publishing To Broker: "));
  Serial.println(transmitt_Payload);
  return transmitt_Payload;

}

double round2(double value) {
  return (int)(value * 100 + 0.5) / 100.0;
}


//******************************************************** deserialized JSON Payload ******************************************//
void deserialize_Payload() {
  StaticJsonDocument<JSON_DOCUMENT_SIZE> doc;
  if ( !strcmp( recived_payload.c_str(), "false" ) ) {
    Serial.println("Error");
  }
  else {
    DeserializationError error = deserializeJson(doc, recived_payload);
    if (error) {
      Serial.print(F("deserializeJson() failed"));
      Serial.println(error.f_str());
    }
    else {

      Serial.println(recived_payload);
      //      jsonVehicle_ID = (const char*)doc["GID"];
      //      json_TS = doc["TS"]; // 0

    }
  }
}
