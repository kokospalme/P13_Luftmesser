/*
 * Projekt Luftmessgerät version 1
 * Level 1
 * C. Wüpping, 2022
 * Das gesamte Projekt inkl. Code unterliegt der Creative Common Lizenz CC BY-NC 4.0 (https://creativecommons.org/licenses/by-nc/4.0/deed.de)
 * 
 */
 
/*** PINS ***/

#define SENSOR_PIN 6  // Sensor (MQ 135), Pin C4
#define LED1_PIN 0  // LED noch gut (grün), Pin A1
#define LED2_PIN 1  // LED geht so (gelb), Pin A2
#define LED3_PIN 2  // LED nicht OK (rot), Pin A3

/*** Kalibrierung **/
#define INTERVALL 500 // alle x Millisekunden messen

#define LEVEL_2 200 // ab x Level 2: "naja"
#define LEVEL_3 500 // ab x Level 3: "schlecht/Gefahr"

/*** Variablen ***/
int luftverschmutzung;

void setup() {  // läuft einmal durch
  Serial_begin(9600); //Serial communication
  Serial_print_s("Luftmessgerät booting");  //schreibe Zeile beim Booten
  Serial_print_s("\n");
  
  pinMode(SENSOR_PIN, INPUT); // Sensor-pin  = input

  pinMode(LED1_PIN, OUTPUT);  // LED1 = output
  pinMode(LED2_PIN, OUTPUT);  // LED2 = output
  pinMode(LED3_PIN, OUTPUT);  // LED3 = output

}

void loop() { //läuft immer wieder durch

  luftverschmutzung = analogRead(SENSOR_PIN);
  
  digitalWrite(LED1_PIN, HIGH); //LED1 an
  
  if(luftverschmutzung >= LEVEL_2){  // LED2 ab Level 2 an
    digitalWrite(LED2_PIN, HIGH);  //Low und high vertauscht (nur bei STM8!)
  }else{  //sonst LED2 aus
    digitalWrite(LED2_PIN, LOW);
  }
  
  if(luftverschmutzung >= LEVEL_3){  // LED3 ab Level 3 an
    digitalWrite(LED3_PIN, HIGH);
  }else{  //sonst LED3 aus
    digitalWrite(LED3_PIN, LOW);
  }

  Serial_print_u(luftverschmutzung);  //gebe Sensorwert über Serielle Schnittstelle aus (Pin TX/PD5)
  Serial_print_s("\n");
  
  delay(INTERVALL);   //warte x Millisekunden
  
}  //Ende des Loops
