/********Turn Left**************/

void turnLeft(int motorSpeed){
  
  spinLeftMotor(-motorSpeed);
  spinRightMotor(motorSpeed);
  
}

/********Turn Right*************/

void turnRight(int motorSpeed){
  
  spinLeftMotor(motorSpeed);
  spinRightMotor(-motorSpeed);
  
}
