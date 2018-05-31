#include <Servo.h>
Servo servo;

//COMENTAR LOS OTROS DOS SERVOS QUE NO SE VAN A USAR !!!

//REGADOR DE PLANTAS
void setup() {
  Serial.begin(9600);
  servo.attach(8);
}

void loop() {
  delay(100);
  servo.write(180);
  while (Serial.available() > 0) {
    if (Serial.read() == 'r')
      Serial.println("Comenzando regado");
    for (int j = 0; j < 3; j++) {
      for (int i = 180 ; i >= 0; i -= 30) {
        servo.write(i);
        delay(499);
        Serial.println(i);
      }
    }
    Serial.println("Termino el regado");
    delay(1000);
  }
}


//PUERTA GARAJE
void setup() {
  Serial.begin(9600);
  servo.attach(8);
}

void loop() {
  delay(100);
  servo.write(90);
  while (Serial.available() > 0) {
    if (Serial.read() == 'g') {
      delay(50);
      servo.write(5);
      int tiempoInicio = millis();
      while ((millis() - tiempoInicio) <= 8000) {
        Serial.println("Hacer algo extra (prender luces)...");
      }
    }
  }
}



//PUERTA DE LA CASA
void setup() {
  Serial.begin(9600);
  servo.attach(8);
}

void loop() {
  delay(100);
  servo.write(90);
  while (Serial.available() > 0) {
    if (Serial.read() == 'p') {
      delay(50);
      servo.write(5);
      int tiempoInicio = millis();
      while ((millis() - tiempoInicio) <= 3000) {
        Serial.println("Hacer algo extra (prender luces)...");
      }
    }
  }
}
