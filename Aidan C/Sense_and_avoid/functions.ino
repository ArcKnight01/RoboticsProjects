/*void spinLeftMotor(int motorSpeed) { // this drives the motor
  if (motorSpeed > 0) {          // if the motor is given a positive speed
    digitalWrite(AIN1, HIGH);    //pin 1 is high
    digitalWrite(AIN2, LOW);     // pin 2 is low
  }
  else if (motorSpeed < 0) {     //if the motor should drive backwards (negative speed)
    digitalWrite(AIN1, LOW);     //set pin 1 to low
    digitalWrite(AIN2, HIGH);    //set pin 2 to high
  }
  else {                         //if the motor should stop
    digitalWrite(AIN1, LOW);     //set pin 1 to low
    digitalWrite(AIN2, LOW);     //set pin 2 to low
  }
  analogWrite(PWMA, abs(motorSpeed));//now that the motor direction is set, drive it at the entered speed
}

/*------------------ Right Motor ------------------*//*
void spinRightMotor(int motorSpeed) { // this drives the motor
  if (motorSpeed > 0) {           // if the motor is given a positive speed
    digitalWrite(BIN1, HIGH);     //pin 1 is high
    digitalWrite(BIN2, LOW);      // pin 2 is low
  }
  else if (motorSpeed < 0) {      //if the motor should drive backwards (negative speed)
    digitalWrite(BIN1, LOW);      //set pin 1 to low
    digitalWrite(BIN2, HIGH);     //set pin 2 to high
  }
  else {                          //if the motor should stop
    digitalWrite(BIN1, LOW);      //set pin 1 to low
    digitalWrite(BIN2, LOW);      //set pin 2 to low
  }
  analogWrite(PWMB, abs(motorSpeed)); //now that the motor direction is set, drive it at the entered speed
}
*/
float getDistance(){

  digitalWrite(trig, HIGH); //signal time
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);

  float echoTime = pulseIn(echo, HIGH);      //how long it takes for the signal to bounce back
  float calculateDistance = echoTime / 148.0;  //distance calculation

  return calculateDistance;              //returns the calculated distance to the getDistance function
}
