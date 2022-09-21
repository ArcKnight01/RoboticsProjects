//full code of driving bot

//declarations
enum DIR {fwd, rev, noDir};

// declares fwd and rev
//const int fwd = 1;
//const int rev = -1;
//other variables (constants)

//pins
// right motor
const int AIN1 = 7; // control motor pin A1
const int AIN2 = 4; // control motor pin A2
const int PWMA = 6; // control the A speed

// left motor
const int BIN1 = 2;  // control motor pin B1
const int BIN2 = 3;  // control motor pin B2
const int PWMB = 5;  // control the B speed

int switchPin = 8;   // start the program

int motorSpeed = 0;  // starting motor speed

const int trig = 11; //trigger pin
const int echo = 12; //echo pin


float distance = 0;  //start program with sensor data at 0
//functions
void stopMotors();
void spinRightMotor(int motorSpeed); // parameters  fwd/rev, speed, delay
void spinLeftMotor(int motorSpeed);
void driveForward();
void driveReverse();
void turnRight();
void turnLeft();
void rightTurnLED();
void leftTurnLED();
float getDistance();


void setup() {
  pinMode(switchPin, INPUT_PULLUP); // button

  pinMode(AIN1, OUTPUT);            // motor OUTPUTs
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  Serial.begin (9600);              //start the serial

  pinMode(trig, OUTPUT);            //pin is OUTPUT because trig is an INPUT on the sensor
  pinMode(echo, INPUT);             //pin is INPUT because echo is an OUTPUT on the sensor
}

void loop() {
  int switchOn = digitalRead(switchPin); // check to see if the switch is on
  distance = getDistance();              //check the sensor reading

  Serial.println(String(distance) + " in");   //print the distance
//  delay(100);      //delay between readings

  if (switchOn == LOW) { //switch is on 
     if (distance < 10) {              //obstacledetected
//      spinRightMotor(distance*15);
//      spinLeftMotor(distance*15);
     //stop
      spinRightMotor(0);
      spinLeftMotor(0);
      delay(500);

      //back up
      spinRightMotor(-150);
      spinLeftMotor(-150);
      delay(300);

      //turn away right
      spinRightMotor(-150);
      spinLeftMotor(150);
      delay(200);
     }
     else {                          //no obstacle detected
      //Serial.println("hello");
      spinRightMotor(150);
      spinLeftMotor(150);
      delay(200);
     }
   }
   else {
//    stopMotors();
    spinRightMotor(0);
    spinLeftMotor(0);
   }
   delay(50);
}
void spinLeftMotor(int motorSpeed) { // this drives the motor
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

/*------------------ Right Motor ------------------*/
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
float getDistance(){

  digitalWrite(trig, HIGH); //signal time
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);

  float echoTime = pulseIn(echo, HIGH);      //how long it takes for the signal to bounce back
  float calculateDistance = echoTime / 148.0;  //distance calculation

  return calculateDistance;              //returns the calculated distance to the getDistance function
}
//void stopMotors(){
//    spinRightMotor(0);
//    spinLeftMotor(0);
//}
