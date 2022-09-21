const int LED1 = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED1, LOW);
  delay(500);
  
  
}
