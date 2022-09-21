#include <Servo.h>

Servo myservo;
int button = 12;
bool buttonPress = false; 

void setup() {
  // put your setup code here, to run once:
  myservo.attach(7); //attach servo
  pinMode(button, INPUT_PULLUP); // initiate button as a pullup input
//  myservo.write(180);

}

void loop() {
  // put your main code here, to run repeatedly:
  int checkButtonPress = digitalRead(button);
  
  if (checkButtonPress == LOW) {  //swap the state of the button press

    delay(50);    //slight delay so servo doesn't react too quickly

    buttonPress = !buttonPress;  //make the buttonPress the opposite of itself

  }
  if (buttonPress == true) { //close servo on first press

    myservo.write(0);

    delay(250);

  }

  else if (buttonPress == false) { //open servo on alternate press

    myservo.write(180);

    delay(250);

  }

}
