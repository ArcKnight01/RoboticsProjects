const int flexSensor = A0; 
int stopLED = 10; //stop LED
int cautionLED = 9; //cautionLED
int goLED = 8;  //goLED

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(stopLED, OUTPUT);
  pinMode(cautionLED, OUTPUT);
  pinMode(goLED, OUTPUT);
  pinMode(flexSensor, INPUT); 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int flexAngle = analogRead(flexSensor); 
  Serial.println(flexAngle);
  delay(500);
  int flexPosition = map(flexAngle, 740, 880, 0, 90);
  flexPosition = constrain(flexPosition, 0, 90);
  Serial.println("Current angle is " + String(flexPosition) + " degrees.");  
//  normal: 741
//  stop: 850
//  caution 815
  if (flexAngle > 755 && flexAngle < 850){
    //caution
    digitalWrite(goLED, LOW);
    digitalWrite(cautionLED, HIGH);
    digitalWrite(stopLED, LOW);
    Serial.println("Watch your surroundings...");
    Serial.println();
  }
  else if(flexAngle >= 850){
    //full stop
    digitalWrite(goLED, LOW);
    digitalWrite(cautionLED, LOW);
    digitalWrite(stopLED, HIGH);
    Serial.println("STOP!");//full stop
    Serial.println();
  }
  else {
    //go time
    digitalWrite(goLED, HIGH);
    digitalWrite(cautionLED, LOW);
    digitalWrite(stopLED, LOW);
    Serial.println("All clear.");
    Serial.println();
  }
}
