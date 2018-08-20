/*********************************************
 * smartdebug
 * Debug - Makros für die Arduino - IDE
 * 
 * 12.08.2018 Vers. 2.0
 * Der Hobbyelektroniker
 * der.hobbyelektroniker@gmail.com
 * https://www.youtube.com/c/HobbyelektronikerCh (Youtube - Kanal)
 * https://community.hobbyelektroniker.ch
 * https://www.hobbyelektroniker.ch
 *
 * Der Code ist lizenzfrei und darf von jedermann frei verwendet werden
 * Trotzdem freut es mich natürlich, wenn dieser Kommentar stehen bleibt ;-)
 * Feedback, Verbesserungen und Erweiterungen sind ebenfalls sehr erwünscht.
 *********************************************/


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

  // Initialisierung
  #define DEBUG_INIT(speed) Serial.begin(speed)

  // Textausgabe
  #define DEBUG_PRINT(txt) Serial.print(txt)
  #define DEBUG_PRINTLN(txt) Serial.println(txt)
  #define DEBUG_PRINT_VALUE(txt, val) Serial.print(txt); Serial.print(": "); Serial.print(val)
  #define DEBUG_PRINTLN_VALUE(txt, val) Serial.print(txt); Serial.print(": "); Serial.println(val)
  #define DEBUG_PRINTLN_EMPTY() Serial.println()
  
  // andere Befehle
  #define DEBUG_DELAY(ms) delay(ms)
  #define DEBUG_WAIT(txt, condition) if (condition) DebugWait(txt)
#else
  // Leere Makro - Rümpfe, für den Fall, dass kein Debugging erwünscht ist
  #define DEBUG_INIT(speed)
  #define DEBUG_PRINT(txt)
  #define DEBUG_PRINTLN(txt)
  #define DEBUG_PRINT_VALUE(txt, val)
  #define DEBUG_PRINTLN_VALUE(txt, val)
  #define DEBUG_PRINTLN_EMPTY()
  #define DEBUG_DELAY(ms)
  #define DEBUG_WAIT(txt, condition)
#endif
