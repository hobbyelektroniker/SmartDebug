/*********************************************
 * smart_debug7
 * Einfache Blinkschaltung
 * Weitere nützliche Funktionen
 * 
 * 12.08.2018 Der Hobbyelektroniker
 * Vers. 1.0
 * Der Code ist lizenzfrei und darf von jedermann frei verwendet werden
 *********************************************/

// Debugging einschalten, zum ausschalten auskommentieren
// WICHTIG: zuerst define, dann include !!!
#define _SMARTDEBUG
#include "smartdebug.h"

const int led1 = 7;
const int led2 = 8;

void setup() {
  DEBUG_INIT(19200); // Initialisierung der seriellen Schnittstelle
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  // Debug - Ausgabe auf die Konsole
  DEBUG_WAIT("Gleich geht's los! Bist du bereit?", true);
}


void blinkLed1() {
  const unsigned long waitTime = 5000;  
  static unsigned long oldTime = 0;
  static int state = LOW;
  
  if (oldTime + waitTime < millis()) {
    if (state == LOW) state = HIGH; else state = LOW;
    oldTime = millis();
    digitalWrite(led1,state);
    // Debug - Ausgabe auf die Konsole
    DEBUG_PRINTLN_VALUE("Lample 1 ein: ",(state == HIGH));
  }  
}

void blinkLed2() {
  const unsigned long waitTime = 500;  
  static unsigned long oldTime = 0;
  static int state = LOW;
  
  if (oldTime + waitTime < millis()) {
    if (state == LOW) state = HIGH; else state = LOW;
    oldTime = millis();
    digitalWrite(led2,state);
    // Debug - Ausgabe auf die Konsole
    DEBUG_PRINTLN_VALUE("Lample 2 ein: ",(state == HIGH));
  }  
}


void loop() {
  blinkLed1();  
  blinkLed2();
}
