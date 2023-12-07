/*
 * Webclient
 * -----------------
 * Denne fil implementer funtioner fra Webclient.h
 * webclientSetup
 * printWiFiStatus
 * makePostRequest
 */

#include "Webclient.h"

char ssid[] = SSID;
char pass[] = PASSWORD;           
uint16_t port = PORT;
char host[] = HOST;
char path[] = PATH;
int status = WL_IDLE_STATUS;


void webclientSetup(){
  Serial.println("Connected to Wi-Fi");
  
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(1000);
  }
}


void printWiFiStatus() {
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

 
void makePostRequest(float value) {
  WiFiClient wifiClient;
  HttpClient client = HttpClient(wifiClient, host, port);
  String keyValue = "{\"oxygenValue\": "; // keyValue er nøgle værdien til body´en af post requested
  String jsonData = keyValue + String(value) + ", \"OxygenMeasurementSystemId\": " + 1 + "}";

This will result in a JSON string like:
  client.post(path, "application/json", jsonData);

  int statusCode = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);

  client.stop();
}
