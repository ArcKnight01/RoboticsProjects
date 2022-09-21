//headers

//Global variables
// right motor
const int AIN1 = 7; // control motor pin A1
const int AIN2 = 4; // control motor pin A2
const int PWMA = 6; // control the speed

// left motor
const int BIN1 = 2;  // control motor pin B1
const int BIN2 = 3;  // control motor pin B2
const int PWMB = 5; // control the speed

int LEDright = 6; //back right LED
int LEDleft = 5; //back left LED

int slideSwitch = 8; // hold to turn the button on

//functions 
void spinRightMotor();
void spinLeftMotor();
void driveForward();
void turnRight();
void turnLeft();
void driveBackwards();
void rightTurn();

void setup() {
  // put your setup code here, to run once:
  pinMode(slideSwitch, INPUT_PULLUP); 
  pinMode(AIN1, OUTPUT); 
  pinMode(AIN2, OUTPUT); 
  pinMode(PWMA, OUTPUT); 
  pinMode(BIN1, OUTPUT); 
  pinMode(BIN2, OUTPUT); 
  pinMode(PWMB, OUTPUT); 
  pinMode(LEDright, OUTPUT);
  pinMode(LEDleft, OUTPUT);
}

void loop() {
  int buttonPressed = digitalRead(slideSwitch); // check to see if the button is pressed

  if (buttonPressed == LOW) {  // run this code if the switch is on
     
    driveForward();
    //right turn
    delay(1000);
//    rightTurn(); //led
    turnRight();
    delay(750);
  }
  else {
    digitalWrite(AIN1, LOW); //allstop
    digitalWrite(AIN2, LOW); 
    digitalWrite(BIN1, LOW); 
    digitalWrite(BIN2, LOW);  
  }
  // put your main code here, to run repeatedly:

}
void rightTurn() { 
// digitalWrite(LEDright, HIGH); 
// delay(250); 
// digitalWrite(LEDright, LOW); 
// delay(75); 
// digitalWrite(LEDright, HIGH); 
// delay(250); 
// digitalWrite(LEDright, LOW); 
// delay(75); 
 } 
 void leftTurn() { 
// digitalWrite(LEDleft, HIGH); 
// delay(250); 
// digitalWrite(LEDleft, LOW); 
// delay(75); 
// digitalWrite(LEDleft, HIGH); 
// delay(250); 
// digitalWrite(LEDleft, LOW); 
// delay(75); 
 } 
 void driveForward(){
   digitalWrite(AIN1, HIGH);  // pin A1 is high
   digitalWrite(AIN2, LOW);   // pin A2 is low
    
   digitalWrite(BIN1, HIGH);  // pin B1 is high
   digitalWrite(BIN2, LOW);   // pin B2 is low
    
   analogWrite(PWMA, 100);    // speed of right motor
   analogWrite(PWMB, 100);    // speed of left motor
 }
 void driveBackwards(){
   digitalWrite(AIN1, LOW);  // pin A1 is high
   digitalWrite(AIN2, HIGH);   // pin A2 is low
    
   digitalWrite(BIN1, LOW);  // pin B1 is high
   digitalWrite(BIN2, HIGH);   // pin B2 is low
    
   analogWrite(PWMA, 100);    // speed of right motor
   analogWrite(PWMB, 100);    // speed of left motor
 }
 void turnRight(){
    digitalWrite(AIN1, LOW);   // pin A1 is low
    digitalWrite(AIN2, HIGH);  // pin A2 is high //right goes backwards
    
    digitalWrite(BIN1, HIGH);  // pin B1 is high
    digitalWrite(BIN2, LOW);   // pin B2 is low
    
    analogWrite(PWMA, 110);    // speed of right motor
    analogWrite(PWMB, 100);    // speed of left motor
 }
 void turnLeft(){
    digitalWrite(AIN1, HIGH);   // pin A1 is high
    digitalWrite(AIN2, LOW);  // pin A2 is low //left goes backwards
    
    digitalWrite(BIN1, LOW);  // pin B1 is low
    digitalWrite(BIN2, HIGH);   // pin B2 is high
    
    analogWrite(PWMA, 100);    // speed of right motor
    analogWrite(PWMB, 110);    // speed of left motor
 }

 //assembly 6502 lookup
