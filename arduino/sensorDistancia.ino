const int trigger = 22;
const int echo = 24;

long duracion;
int distancia;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigger, 0);
  delayMicroseconds(2);
  digitalWrite(trigger, 1);
  delayMicroseconds(10);
  digitalWrite(trigger, 0);
  duracion = pulseIn(echo, HIGH);

  distancia = duracion * 0.034 / 2;
  if (distancia < 30) {
    digitalWrite(53, 1);
  } else {
    digitalWrite(53, 0);
  }
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println("cm");
  delay(500);
}
