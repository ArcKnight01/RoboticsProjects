#include <Servo.h>

Servo myservo;
const int button = 12;
const int ledPin = LED_BUILTIN;

bool buttonPress = false;

int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(7); //attach servo
  //input pullup - no resistor needed:
  pinMode(button, INPUT_PULLUP); // initiate button as a pullup input
  //input (normal) - resitor needed as ref to 5V.
  pinMode(button, INPUT);
  //  myservo.write(180);

}

void loop() {
  // put your main code here, to run repeatedly:
 
  //for input normal:
  buttonState = digitalRead(ButtonPin)

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  //for input pull up: 
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
