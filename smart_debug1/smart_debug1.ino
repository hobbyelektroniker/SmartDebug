/*********************************************
 * smart_debug1
 * Einfache Blinkschaltung ohne Debug - Code
 * 
 * 12.08.2018 Der Hobbyelektroniker
 * Vers. 1.0
 * Der Code ist lizenzfrei und darf von jedermann frei verwendet werden
 *********************************************/

const int led1 = 7;
const int led2 = 8;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}


void blinkLed1() {
  const unsigned long waitTime = 5000;  
  static unsigned long oldTime = 0;
  static int state = LOW;
  
  if (oldTime + waitTime < millis()) {
    if (state == LOW) state = HIGH; else state = LOW;
    oldTime = millis();
    digitalWrite(led1,state);
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
  }  
}


void loop() {
  blinkLed1();  
  blinkLed2();
}
