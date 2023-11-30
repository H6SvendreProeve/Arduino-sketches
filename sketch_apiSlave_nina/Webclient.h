/*
 * Webclient
 * -----------------
 * Denne fil håndterer al forbindelse mellem 
 * mikrocontroller og internettet (over Wi-Fi).
 */

#ifndef WEBCLIENT_H
#define WEBCLIENT_H
#include <Arduino.h>
#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>
#include "config.h"


void webclientSetup();
void printWiFiStatus();
void makePostRequest(float value);

#endif
