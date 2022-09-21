enum STATE {FWD, BWD, TURN};
STATE state = FWD;
const int trig = 11;
const int echo = 12;

float distance = 0;
float timer = 0;

//functions 
void spinLeftMotor(int motorSpeed);
void spinRightMotor(int motorSpeed);
void getDistance();

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  distance = getDistance();
  timer += 0.05;
  if (state == FWD && distance < 20 & distance > 0) {
    state = BWD;
  }
  else if (state == FWD) {
    //driveMotors(100);
  }
  else if (state == BWD && distance >= 40) {
    state = TURN;
  }
  else if (state == BWD) {
    //driveMotors(-70);
  }
  else if (state == TURN && timer > 1.5) {
    state = FWD;
    timer = 0;
  }
  else if (state == TURN) {
    //turnRobot(70);
  }
  delay(50);
}

//float getDistance() {
//  digitalWrite(trig, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trig, LOW);
//  float echoTime = pulseIn(echo, HIGH);
//  float calculateDistance = echoTime / 148.0;
//  return calculateDistance;
//}

//Make your motor driving functions here:
//void driveMotors(int PWM) {
 spinLeftMotor(PWM);
 spinRightMotor(PWM);
}
//void turnRobot(int PWM) {
  spinLeftMotor(-PWM);
  spinRightMotor(PWM);
}
