#include <WiFi101.h>
#include "config.h"



char ssid[] = SSID;
char pass[] = PASSWORD;
char host[] = HOST;
char path[] = PATH;
int status = WL_IDLE_STATUS;

void setup() {
  startSerial();
  connecteToWifi();


}

void loop() {
  String respones = sendHttpRequsetchar(host, path);
  Serial.println("printing respones:");
  Serial.println(respones);

}

void startSerial(){
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
}

void connecteToWifi(){
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(2000);
  }
  Serial.println("Connected to wifi");
}



String sendHttpRequsetchar(const char* host, const char* path){
  String message = "";
  WiFiClient client;
    if(client.connect(host, 8088)){
     Serial.println("Connected to server");
     
     client.print("GET " + String(path) + " HTTP/1.1\r\n");
     client.print("Host: " + String(host) + "\r\n");
     //client.print("X-Api-Key: " + String(apiKey) + "\r\n");
     //client.print("X-MasterArduinoId: " + String(masterArduinoId) + "\r\n");
     client.print("Connection: close\r\n\r\n");

     while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.print(c);
        message = message + c;
      }
    }

    client.stop();
    Serial.println("Disconnected from server");   
  } else {
    Serial.println("Connection failed");
  }
  Serial.println("returns");
  return message;
}
