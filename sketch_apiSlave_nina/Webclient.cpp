/*
 * Webclient
 * -----------------
 * Denne fil implementer funtioner fra Webclient.h
 * webclientSetup
 * printWiFiStatus
 * makePostRequest
 */

#include "Webclient.h"

char ssid[] = "H6 Svendeprove grp3";
char pass[] = "iltsvind";
char host[] = HOST;
char path[] = PATH;
int status = WL_IDLE_STATUS;

void webclientSetup(){
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
  HttpClient client = HttpClient(wifiClient, host, 8088);
  
  String jsonData = "{\"oxygenValue\": " + String(value) + "}";
  client.post(path, "application/json", jsonData);

  int statusCode = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);

  client.stop();
}
