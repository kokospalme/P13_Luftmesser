
int pin_grueneLed = 14; //grüne led: D5 = 14
int pin_gelbeLed = 1;
int pin_roteled = 2;
int pin_sensor = 6; //Sensor: C4 = D6

int sensorwert;

void setup() {
  pinMode(pin_grueneLed, OUTPUT);  //grüne Led (pin 14) = output
  pinMode(pin_gelbeLed, OUTPUT);
  pinMode(pin_roteled, OUTPUT);
  pinMode(pin_sensor, INPUT);

  digitalWrite(pin_grueneLed, HIGH);
  digitalWrite(pin_gelbeLed, HIGH);
  digitalWrite(pin_roteled, HIGH);
  delay(2000);
}

void loop() {


  sensorwert = analogRead(pin_sensor);

  if(sensorwert >100){  //wenn wert über 100 --> grüne LED an
    digitalWrite(pin_grueneLed, HIGH);
  }else{
    digitalWrite(pin_grueneLed, LOW);
  }


  if(sensorwert >110){  //wenn wert über 110 --> gelbe LED an
    digitalWrite(pin_gelbeLed,  HIGH);
  }else{
    digitalWrite(pin_gelbeLed,  LOW);
  }





  delay(500);
}
