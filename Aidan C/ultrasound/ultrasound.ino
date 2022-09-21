const int trig = 11;           //trigger pin     
const int echo = 12;           //echo pin  
float distance = 0;            //start program with sensor data at 0

void setup(){
  Serial.begin (9600);         //start the serial

  pinMode(trig, OUTPUT);       //pin is OUTPUT because trig is an INPUT on the sensor
  pinMode(echo, INPUT);        //pin is INPUT because echo is an OUTPUT on the sensor
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = getDistance();    //check the sensor reading
  Serial.println(String(distance) + " in");   //print the distance
  delay(100);      //delay between readings
}
float getDistance(){

  digitalWrite(trig, HIGH); //signal time
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);

  float echoTime = pulseIn(echo, HIGH);      //how long it takes for the signal to bounce back
  float calculateDistance = echoTime / 148.0;  //distance calculation

  return calculateDistance;              //returns the calculated distance to the getDistance function
}
