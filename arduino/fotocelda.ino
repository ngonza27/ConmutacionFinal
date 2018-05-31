int luz = 0; //valor luz

void setup() {
  Serial.begin(9600);
}

void loop() {
  //pin A1 !!!
  luz = analogRead(1);
  Serial.println(luz);
}
