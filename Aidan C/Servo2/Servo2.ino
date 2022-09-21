#include <Servo.h> //include the servo library
#define SERIAL_SPEED 9600
Servo myservo; //create a servo object


void setup() {
    myservo.attach(9); //tell the servo object that its servo is plugged into pin 9
    Serial.begin(SERIAL_SPEED);

    Serial.println("Tell the servo to turn left or right");
    Serial.println("Type l for left and r for right");
    Serial.println();

}
void loop() {
   int trimpot = analogRead(A0); 
   int servoPosition = map(trimpot, 0, 1023, 20, 160);
   
   
   if (Serial.available() > 0) { 
   char servoCommand = Serial.read(); 
   switch (servoCommand) {
      case 'l': //left
        myservo.write(10);
        delay(250);
        myservo.write(90);
        break;
      case 'r'://right
        myservo.write(170);
        delay(250);
        myservo.write(90);
        break;
      default://if nothing is happening
        myservo.write(90);
        break;
    }
   } 
   //myservo.write(servoPosition);
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
