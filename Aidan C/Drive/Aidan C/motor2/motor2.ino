#define SERIAL_SPEED 9600

//Global variables (Constants)
//const int motor = 10;
const int AIN1 = 13; 
const int AIN2 = 12; 
const int PWMA = 11; 

int buttonPin = 7; 
int motorSpeed = 0; 

void setup() {
  // put your setup code here, to run once:
  //pinMode(motor, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // button
  pinMode(AIN1, OUTPUT);            //motor OUTPUTs
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Choose a motor speed from 0 to 255."); 
  Serial.println("Type 0 to stop."); 
  
}
void motorTurn(int motorSpeed) {
  if (motorSpeed > 0) {        // if the motor is given a positive speed
    digitalWrite(AIN1, HIGH);  // pin 1 is high
    digitalWrite(AIN2, LOW);   // pin 2 is low
  }
  else if (motorSpeed < 0) {   // if the motor is given a negative speed
    digitalWrite(AIN1, LOW);   // pin 1 is low
    digitalWrite(AIN2, HIGH);  // pin 2 is high
  }
  else {                       //if the motor is given 0 speed
    digitalWrite(AIN1, LOW);   // pin 1 is low
    digitalWrite(AIN2, LOW);   // pin 2 is low
  } 
  analogWrite(PWMA, abs(motorSpeed));    
}

void loop() {
  int buttonPressed = digitalRead(buttonPin);
  

  
  if(Serial.available() > 0){
    motorSpeed = Serial.parseInt();
    //motorSpeed = constrain(motorSpeed, 0, 255); //set constraints
    Serial.println("Current speed: " + String(motorSpeed));
    //analogWrite(motor, motorSpeed); //Change motor speed
  }
  if(buttonPressed == LOW) {
    motorTurn(motorSpeed);
  }
  else {
    motorTurn(0);
  }

  
//    analogWrite(motor, 0); // turn the motor on
//    delay(1000);                // delay
//    analogWrite(motor, 255); 
//    delay(1000);      
}
