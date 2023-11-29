#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>
#include "config.h"
#include "I2c_slave.h"

char ssid[] = "H6 Svendeprove grp3";
char pass[] = "iltsvind";
char host[] = HOST;
char path[] = PATH;
int status = WL_IDLE_STATUS;  // Initialize status variable

void setup() {
  // Start serial communication
  Serial.begin(9600);
  i2cSlaveSetup();
  
  // Connect to Wi-Fi
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(1000);  // Try to connect every 10 seconds
  }

  // Print your MKR 1010's IP address
  Serial.println("Connected to Wi-Fi");
  printWiFiStatus();
}

void loop() {
  makePostRequest();
  //String respones = sendHttpRequsetchar(host, path);
  //Serial.println("printing respones:");
  //Serial.println(respones);
  delay(1000);
}

void printWiFiStatus() {
  // Print the IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void makePostRequest() {
  // Create a client object
  WiFiClient wifiClient;
  HttpClient client = HttpClient(wifiClient, host, 8088);

  // Define the POST data
  //String postData = "oxygenValue=5.40";
  String jsonData = "{\"oxygenValue\": " + String(receivedFloat) + "}";

  // Make the POST request
  client.post(path, "application/json", jsonData);

  // Get the response from the server
  int statusCode = client.responseStatusCode();
  String response = client.responseBody();

  // Print the response
  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);

    // Close the client to release the socket
  client.stop();
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
