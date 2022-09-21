#include <Servo.h> //include the servo library
Servo myservo; //create a servo object


void setup() {
    myservo.attach(9); //tell the servo object that its servo is plugged into pin 9
}
void loop() {
   int trimpot = analogRead(A0); 
   int servoPosition = map(trimpot, 0, 1023, 20, 160);
   
   myservo.write(servoPosition);
  // put your main code here, to run repeatedly:
}



/*struct DATA{
  int x;
  char y;
  float z; 
}

typedef DATA data;
data d;
*/
