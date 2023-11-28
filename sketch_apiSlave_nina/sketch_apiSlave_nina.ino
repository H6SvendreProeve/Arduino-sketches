#include <WiFiNINA.h>

char ssid[] = "H6 Svendeprove grp3";
char pass[] = "iltsvind";
int status = WL_IDLE_STATUS;  // Initialize status variable
void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Connect to Wi-Fi
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(10000);  // Try to connect every 10 seconds
  }

  // Print your MKR 1010's IP address
  Serial.println("Connected to Wi-Fi");
  printWiFiStatus();
}

void loop() {
  // Your main code goes here
}

void printWiFiStatus() {
  // Print the IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}
