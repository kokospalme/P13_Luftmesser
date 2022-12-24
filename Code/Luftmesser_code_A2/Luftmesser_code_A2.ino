/*
 * Projekt Luftmessgerät version 1, Gerät As
 * Level 2
 * C. Wüpping, 2022
 * Das gesamte Projekt inkl. Code unterliegt der Creative Common Lizenz CC BY-NC 4.0 (https://creativecommons.org/licenses/by-nc/4.0/deed.de)
 * 
 */
 
/*** PINS ***/

#define SENSOR_PIN A0  // Sensor (MQ 135),    Pin D6/A0 (software), PC4 (hardware)
#define LED1_PIN 5  // LED noch gut (grün),  Pin D5 (sfotware),   PC3 (hardware)
#define LED2_PIN 7  // LED geht so (gelb),    Pin D7 (software),    PC5 (hardware)
#define LED3_PIN 10  // LED nicht OK (rot),    Pin D10(software),     PD1 (hardware)

/*** Kalibrierung **/
#define ANZAHL_MESSUNGEN 10 //Anzahl x der Messungen für Mittelwert
#define INTERVALL 500 // alle x Millisekunden messen
#define PREHEAT_ZEIT 30000 // warte x Millisekunden bevor gemessen wird
#define PREHEAT_BLINKZEIT 200 // Zeit zum Blinken

#define LEVEL_2 200 // ab x Level ok
#define LEVEL_3 500 // ab x Level shclecht

/*** Variablen ***/
int messungen[ANZAHL_MESSUNGEN]; // x "container" für Messungen (so viel wie Anzahl der Messungen) --> Array
int mittelwert; // "container" für Mittelwert --> Variable des Typs 'int'

void setup() {  // läuft einmal durch
  pinMode(SENSOR_PIN, INPUT); // Sensor-pin  = input

  pinMode(LED1_PIN, OUTPUT);  // LED1 = output
  pinMode(LED2_PIN, OUTPUT);  // LED2 = output
  pinMode(LED3_PIN, OUTPUT);  // LED3 = output



for(int i = 0; i < 100; i++){
    digitalWrite(LED1_PIN, HIGH); //LED1 an
    digitalWrite(LED2_PIN, HIGH); //LED2 an
    digitalWrite(LED3_PIN, HIGH); //LED3 an
    delay(PREHEAT_BLINKZEIT);
    digitalWrite(LED1_PIN, LOW); //LED1 aus
    digitalWrite(LED2_PIN, LOW); //LED2 an
    digitalWrite(LED3_PIN, LOW); //LED3 an
    delay(PREHEAT_BLINKZEIT);
    
}

}

void loop() { //läuft immer wieder durch
  
  for(int i = 0; i < ANZAHL_MESSUNGEN; i++){  // Wiederhole eine Messung, solange i kleiner der Anzahl der Messungen ist, i wird hochgezählt --> 'i++'
    messungen[i] = analogRead(SENSOR_PIN);  // schreibe in Container 0, 1, 2, 3 ... 9 die Messungen (analogRead gibt Werte zwischen 0 und 1023 aus)
    mittelwert = mittelwert + messungen[i]; // addiere zum vorhandenen Mittelwert die Messung 0, 1, 2, 3 ... 9
  }
  mittelwert = mittelwert / ANZAHL_MESSUNGEN; // dividiere alle addierten Werte durch Anzahl --> Mittelwert ist berechnet


  digitalWrite(LED1_PIN, HIGH); //LED1 an
  
  if(mittelwert >= LEVEL_2){  // LED2 ab Level 2 an
    digitalWrite(LED2_PIN, HIGH);  //Low und high vertauscht (nur bei STM8!)
  }else{  //sonst LED2 aus
    digitalWrite(LED2_PIN, LOW);
  }
  
  if(mittelwert >= LEVEL_3){  // LED3 ab Level 3 an
    digitalWrite(LED3_PIN, HIGH);
  }else{  //sonst LED3 aus
    digitalWrite(LED3_PIN, LOW);
  }

  
  delay(INTERVALL);   //warte x Millisekunden
  
}  //Ende des Loops