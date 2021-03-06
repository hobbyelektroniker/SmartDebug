/*********************************************
 * smart_debug5
 * Einfache Blinkschaltung mit Wartefunktion
 * 
 * 12.08.2018 Der Hobbyelektroniker
 * Vers. 1.0
 * Der Code ist lizenzfrei und darf von jedermann frei verwendet werden
 *********************************************/

// Debugging einschalten, zum ausschalten auskommentieren
#define _SMARTDEBUG

// Debug Makros
#ifdef _SMARTDEBUG
  // Hilfsfunktion für WAIT - Makro
  void DebugWait(String txt) {
    // buffer leeren
    char ch;
    while (Serial.available()) ch = Serial.read();
    ch = 0;
  
    Serial.print(txt);
    Serial.println(" >press 'c' to continue..."); 

    // auf 'c' warten
    do {
      if (Serial.available() > 0) ch = Serial.read();
    } while (ch != 'c'); 
    // buffer leeren
    while (Serial.available()) ch = Serial.read();
  }  


  #define DEBUG_INIT(speed) Serial.begin(speed)
  #define DEBUG_PRINTLN(txt) Serial.println(txt)
  #define DEBUG_PRINTLN_VALUE(txt, val) Serial.print(txt); Serial.print(": "); Serial.println(val)
  #define DEBUG_WAIT(txt, condition) if (condition) DebugWait(txt)
#else
  #define DEBUG_INIT(speed)
  #define DEBUG_PRINTLN(txt)
  #define DEBUG_PRINTLN_VALUE(txt, val)
  #define DEBUG_WAIT(txt, condition)
#endif



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
