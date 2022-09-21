const int motor = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(motor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(motor, HIGH); 
//  delay(500);           
//  digitalWrite(motor, LOW); 
//  delay(500);
    analogWrite(motor, 0); // turn the motor on
    delay(1000);                // delay
    analogWrite(motor, 50); 
    delay(1000); 
    analogWrite(motor, 100); 
    delay(1000); 
    analogWrite(motor, 255); 
    delay(1000);      
}
