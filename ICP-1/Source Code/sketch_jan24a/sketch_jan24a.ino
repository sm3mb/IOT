void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop(){

  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  delay(10000);
  digitalWrite(3, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  delay(2000);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);

  delay(10000) ;
  }
