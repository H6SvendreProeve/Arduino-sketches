/*
 * Logger
 * -----------------
 * Denne klasse er til håndtere serial.print til com port
 * for at samle alle debug, fejlhåndtering og beskeder som skal skrives til 
 * com porten
 */

#ifndef LOGGER_H
#define LOGGER_H
#include <Arduino.h>

class Logger{
  public:
    void printArrLength(int arrLength);
    void printNoBytes();
    void printInvalidArrSize();
    void printRandomNumber(String servoName);
};


#endif
