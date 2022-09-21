//headers
#include <SoftwareSerial.h>
//SoftwareSerial serialTest(9, 10);

//Global variables
unsigned long baud = 9600; //serial baud rate.

// right motor
const int AIN1 = 13; // control motor pin A1      | 13 -> 
const int AIN2 = 12; // control motor pin A2      | 12 ->
const int PWMA = 11; // control the speed (PWMA)  | 11 (pwm) ->

// left motor
const int BIN1 = 8;  // control motor pin B1      | 8 -> 
const int BIN2 = 9;  // control motor pin B2      | 9 ->
const int PWMB = 10; // control the speed PWMB    | 10 (pwm) ->

/* 
 *  white wire: pwm 
 *  green wire: AIN1/BIN1
 *  yellow wire: AIN2/BIN2
 */
const int slideSwitch = 7; // hold to turn the button on

//RGB led:
//const int redLED = 6;  // rgb led r pwm
//const int greenLED = 5; // rgb led g pwm
//const int blueLED = 4;  // rgb led b
const int redLED = A1;  // rgb led r pwm
const int greenLED = A2; // rgb led g pwm
const int blueLED = A3;  // rgb led b

class Color {
  private:
    int r, g, b;
  public:
    Color(int red, int green, int blue){ //constructor
      r = red; g = green; b = blue;
    }
    int red(){return r;}
    int green(){return g;}
    int blue(){return b;}
};

void color(Color color){ //function that draws led color
  analogWrite(redLED, color.red());
  analogWrite(greenLED, color.green());
  analogWrite(blueLED, color.blue());
}

//colors used to repersent motor speed red=lowest, blue = highest. 
Color red (255, 0,  0);
Color orange  (255, 35, 0);
Color yellow  (225, 100,0);
Color green (0,   225,0);
Color cyan  (0, 255, 255);
Color blue  (0, 0, 255);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baud);              //start the serial
  //serialTest.begin(baud);
  //serialTest.setTimeout(300);
  Serial.println("Serial initialized."); 
  delay(10);
  
  pinMode(slideSwitch, INPUT_PULLUP); //switch to turn motors ON/OFF
  
  pinMode(AIN1, OUTPUT); //motor a digital input  
  pinMode(AIN2, OUTPUT); //motor a digital input 
  pinMode(PWMA, OUTPUT); //motor a pwm speed input
  pinMode(BIN1, OUTPUT); //motor b digital input 
  pinMode(BIN2, OUTPUT); //motor b digital input 
  pinMode(PWMB, OUTPUT); //motor b digital output
  pinMode(A0, INPUT); //this is optional... controls the analog trimpot
  
  pinMode(redLED, OUTPUT); //pwm
  pinMode(greenLED, OUTPUT); //pwm
  pinMode(blueLED, OUTPUT);

}

void loop() {
  //check to see if switch is on:
  int buttonPressed = digitalRead(slideSwitch); // check to see if the button is pressed (return low/high)
  bool switchIsOn;
  if (buttonPressed == LOW){
    switchIsOn = true;
  } else { 
    switchIsOn = false;
  }

  //check the pot Position
  int potPosition = analogRead(A0);
  potPosition = map(potPosition, 0, 1023, 0, 255); //map to value between 0 and 255.
  Serial.println(potPosition); 
  
  if (switchIsOn && potPosition != 0) {  // run this code if the switch is on
    if (potPosition >= 255){
      color(blue);
    }
    else if (potPosition < 255 && potPosition >= 250){
      color(cyan); 
    }
    else if (potPosition < 250 && potPosition >= 100){
      color(green); 
    }
    else if (potPosition < 100 && potPosition >= 10){
      color(yellow); 
    }
    else if (potPosition < 10 && potPosition > 0){
      color(blue);
    }
    
    digitalWrite(AIN1, HIGH);  // pin A1 is high
    digitalWrite(AIN2, LOW);   // pin A2 is low
    
    digitalWrite(BIN1, HIGH);  // pin A1 is high
    digitalWrite(BIN2, LOW);   // pin A2 is low
    
    analogWrite(PWMA, potPosition);    // speed of right motor (a good speed is 100); at least 25 for ability to move
    analogWrite(PWMB, potPosition);    // speed of left motor  (a good speed is 100);
    
  }
  else {
    color(red);
    
    digitalWrite(AIN1, LOW); 
    digitalWrite(AIN2, LOW); 
    digitalWrite(BIN1, LOW); 
    digitalWrite(BIN2, LOW);  
   // analogWrite(PWMA, 0);    // speed of right motor (a good speed is 100);
   // analogWrite(PWMB, 0);    // speed of left motor  (a good speed is 100);
    
  }
  delay(10);
}
