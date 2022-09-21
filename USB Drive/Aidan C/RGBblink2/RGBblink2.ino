//pins
int redLED = 10;  // rgb led r pwm
int greenLED = 9; // rgb led g pwm
int blueLED = 8;  // rgb led b 
int LEDtrimPot = 11; //white led

void color(int red, int green, int blue);
class Color {
  public:
    int r, g, b;
    Color(int red, int green, int blue){ //constructor
      r = red;
      g = green;
      b = blue;
    }
};

Color red (255, 0,  0);
Color orange  (255, 35, 0);
Color yellow  (225, 110,0);
Color green (0,   225,0);
Color cyan  (0, 255, 255);
Color blue  (0, 0, 255);
Color blue_white  (255, 255, 255);
Color indigo (128, 0, 128);
Color purple  (255,0, 255);
Color pink  (255, 20, 147);
Color black (0, 0, 0);
Color temp  (255, 225, 0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(redLED, OUTPUT); //pwm
  pinMode(greenLED, OUTPUT); //pwm
  pinMode(blueLED, OUTPUT);
  pinMode(LEDtrimPot, OUTPUT);
  pinMode(A0, INPUT); //this is optional...
}
void color(Color color){ //function that draws led color
  analogWrite(redLED, color.r);
  analogWrite(greenLED, color.g);
  analogWrite(blueLED, color.b);
}
void blinkLED(int colorLED, float seconds){
  digitalWrite(colorLED, HIGH);
  delay(seconds * 1000);
  digitalWrite(colorLED, LOW);
  delay(seconds * 1000);
}
void loop() {
  // put your main code here, to run repeatedly:
  float time = 1; // in seconds
  //color(255,255,0);
  //blinkLED(redLED, time);
  int potPosition = analogRead(A0);
  potPosition = map(potPosition, 0, 1023, 0, 255);
  Serial.println(potPosition); 
  analogWrite(LEDtrimPot, potPosition);
    if(potPosition <= 20){
      color(red);
    } 
    else if (potPosition > 20 && potPosition <= 40){
      color(orange); 
    } 
    else if (potPosition > 40 && potPosition <= 60){
      color(yellow); 
    } 
    else if (potPosition > 60 && potPosition <= 80){
      color(green); 
    } 
    else if (potPosition > 80 && potPosition <= 100){
      color(cyan); 
    } 
     else if (potPosition > 100 && potPosition <= 120){
      color(blue); 
    } 
     else if (potPosition > 120 && potPosition <= 140){
      color(blue_white); 
    } 
     else if (potPosition > 140 && potPosition <= 160){
      color(indigo); 
    } 
     else if (potPosition > 160 && potPosition <= 180){
      color(purple); 
    } 
    else if (potPosition > 180 && potPosition <= 200){
      color(pink); 
    } 
     else if (potPosition > 200 && potPosition <= 220){
      color(black); 
    } 
     else if (potPosition > 220 && potPosition <= 240){
      color(black); 
    } 
    else if (potPosition > 240 && potPosition <= 255){
      color(temp);
    }
}
 
