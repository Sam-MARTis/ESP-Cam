void setup() {
  // put your setup code here, to run once:
 pinMode(2, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(300);
  digitalWrite(2, HIGH);
  delay(300);
  digitalWrite(2, LOW);
  

}
