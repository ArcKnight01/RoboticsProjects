//headers

//Global variables
// right motor
const int AIN1 = 13; // control motor pin A1
const int AIN2 = 12; // control motor pin A2
const int PWMA = 11; // control the speed

// left motor
const int BIN1 = 8;  // control motor pin B1
const int BIN2 = 9;  // control motor pin B2
const int PWMB = 10; // control the speed

int slideSwitch = 7; // hold to turn the button on

void setup() {
  // put your setup code here, to run once:
  pinMode(slideSwitch, INPUT_PULLUP); 
  pinMode(AIN1, OUTPUT); 
  pinMode(AIN2, OUTPUT); 
  pinMode(PWMA, OUTPUT); 
  pinMode(BIN1, OUTPUT); 
  pinMode(BIN2, OUTPUT); 
  pinMode(PWMB, OUTPUT); 
}

void loop() {
  int buttonPressed = digitalRead(slideSwitch); // check to see if the button is pressed

  if (buttonPressed == LOW) {  // run this code if the switch is on
    digitalWrite(AIN1, HIGH);  // pin A1 is high
    digitalWrite(AIN2, LOW);   // pin A2 is low
    digitalWrite(BIN1, HIGH);  // pin A1 is high
    digitalWrite(BIN2, LOW);   // pin A2 is low
    analogWrite(PWMA, 100);    // speed of right motor
    analogWrite(PWMB, 100);    // speed of left motor
  }
  else {
    digitalWrite(AIN1, LOW); 
    digitalWrite(AIN2, LOW); 
    digitalWrite(BIN1, LOW); 
    digitalWrite(BIN2, LOW);  
  }
  // put your main code here, to run repeatedly:

}
