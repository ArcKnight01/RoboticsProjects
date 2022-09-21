int redLED = 10;
int greenLED = 9;
int blueLED = 8;
int LEDtrimPot = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(LEDtrimPot, OUTPUT);

}
void color(int red, int green,int  blue){
  analogWrite(redLED, red);
  analogWrite(greenLED, green);
  analogWrite(blueLED, blue);
}
void blinkRED(float seconds){
  digitalWrite(redLED, HIGH);
  delay(seconds*1000);
  digitalWrite(redLED, LOW);
  delay(seconds*1000);
}
void blinkGREEN(float seconds){
  digitalWrite(greenLED, HIGH);
  delay(seconds*1000);
  digitalWrite(greenLED, LOW);
  delay(seconds*1000);
}
void blinkBLUE(float seconds){
  digitalWrite(blueLED, HIGH);
  delay(seconds*1000);
  digitalWrite(blueLED, LOW);
  delay(seconds*1000);
}
void loop() {
  // put your main code here, to run repeatedly:
  float time = .25;
  
  int potPosition = analogRead(A0);

  potPosition = map(potPosition, 0, 1023, 0, 255);
  analogWrite(LEDtrimPot, potPosition);
  if(potPosition <= 100){
    color(0,225,0);
  } else if (potPosition > 100 && potPosition < 175){
    color(225,110,0);
    Serial.println(potPosition); 
  } else {
    color(225,0,0);
  }
  Serial.println(potPosition); 
  
 /* 
  blinkRED(time);
  blinkGREEN(time);
  blinkBLUE(time);
  
  blinkRED(time);
  blinkBLUE(time);
  blinkGREEN(time);
  
  blinkBLUE(time);
  blinkRED(time);
  blinkGREEN(time);

  blinkBLUE(time);
  blinkGREEN(time);
  blinkRED(time);

  blinkGREEN(time);
  blinkBLUE(time);
  blinkRED(time);

  blinkGREEN(time);
  blinkRED(time);
  blinkBLUE(time);
*/
  
}
/*
red green blue
red blue green
blue red green
blue green red
green blue red
green red blue
*/
