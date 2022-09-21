#include <SoftwareSerial.h> 
//SoftwareSerial serialTest(9, 10); 
void setup() {
  Serial.begin(9600);
  //serialTest.begin(9600);
}

void loop() {
  //For sending messages
  Serial.println("hi"); //prints to console / serial monitor
  if (serialTest.available() > 0) {
  Serial.write(serialTest.read());
  //For receiving messages
  serialTest.write("Hello!");
  delay(1000);
  //}
}
