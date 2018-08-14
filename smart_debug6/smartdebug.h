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
  #define DEBUG_PRINTLN(txt) Serial.print(txt)
  #define DEBUG_PRINTLN_VALUE(txt, val) Serial.print(txt); Serial.print(": "); Serial.println(val)
  #define DEBUG_WAIT(txt, condition) if (condition) DebugWait(txt)
#else
  #define DEBUG_INIT(speed)
  #define DEBUG_PRINTLN(txt)
  #define DEBUG_PRINTLN_VALUE(txt, val)
  #define DEBUG_WAIT(txt, condition)
#endif
