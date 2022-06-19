/*
 * Luftmessgerät version 1
 * Level 1
 */
 
/*** PINS ***/
#define SENSOR_PIN A3  // Sensor (MQ 135)
#define LED1_PIN D3  // LED noch gut (grün)
#define LED2_PIN D1  // LED geht so (gelb)
#define LED3_PIN C6  // LED nicht OK (rot)

/*** Kalibrierung **/
#define INTERVALL 500 // alle x Millisekunden messen
#define PREHEAT_ZEIT 15000 // warte x Millisekunden bevor gemessen wird
#define PREHEAT_BLINKZEIT 1000; // Zeit zum Blinken

#define LEVEL_2 205 // ab x Level gut
#define LEVEL_3 410 // ab x Level ok
#define LEVEL_4 615 // ab x Level naja

void setup() {  // läuft einmal durch
  pinMode(Sensor_PIN, INPUT); // Sensor-pin  = input

  pinMode(LED1_PIN, OUTPUT);  // LED1 = output
  pinMode(LED2_PIN, OUTPUT);  // LED2 = output
  pinMode(LED3_PIN, OUTPUT);  // LED3 = output

  while(millis() < PREHEAT_ZEIT){ //warte bis Sensor startklar ist und blinke dabei mit LED1
    digitalWrite(LED1_PIN, HIGH); //LED1 an
    delay(PREHEAT_BLINKZEIT);
    digitalWrite(LED1_PIN, LOW); //LED1 aus
    delay(PREHEAT_BLINKZEIT);
  }

}

void loop() { //läuft immer wieder durch

  digitalWrite(LED1_PIN, HIGH); //LED1 an
  
  if(mittelwert >= LEVEL_2){  // LED2 ab Level 2 an
    digitalWrite(LED2_PIN, HIGH);
  }else{  //sonst LED2 aus
    digitalWrite(LED2_PIN, HIGH);
  }
  
  if(mittelwert >= LEVEL_3){  // LED3 ab Level 3 an
    digitalWrite(LED3_PIN, HIGH);
  }else{  //sonst LED3 aus
    digitalWrite(LED3_PIN, HIGH);
  }

  delay(INTERVALL);   //warte x Millisekunden
  
}  //Ende des Loops
