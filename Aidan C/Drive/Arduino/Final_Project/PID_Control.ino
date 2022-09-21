void checkPID(){
   int screenCenter = 80;
   float motor_a;
   float motor_b;
if (serialTest.available() > 0){
  int positionX = serialTest.parseInt();
//int positionX = 0;
  Serial.println(positionX);
  if (positionX > -1){
     templateOnScreen = true;
     prev_error = error;
     error = positionX - screenCenter;
     sum_error += error;
     diff_error = error - prev_error;
     turnSpeed = Kp * error + Ki*sum_error + Kd * diff_error;
      //turnspeed = Kp - error;
      
      motor_a = driveSpeed + turnSpeed;
      motor_b = driveSpeed - turnSpeed;
      if (motor_a > 255){
        motor_a = 255;
      }
      if (motor_b > 255){ 
        motor_b = 255; 
      }
      else{
        templateOnScreen = true;
      }
      driveMotors(motor_a, motor_b);
  }
//
// PosX PosZ PosX = (SerialOutput(PositionX)) mod(1000)
// PosZ = SerialOutput-PosX/1000








    
  }
}
