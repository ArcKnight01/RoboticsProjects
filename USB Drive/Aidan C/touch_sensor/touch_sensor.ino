const int softPot = A1; //soft potentiometer
const int graphSize = 50; 

void setup() {
  pinMode(softPot, INPUT);//soft potentiometer as input
  Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:
  int softPotReading = analogRead(softPot);
  int softPotPosition = map(softPotReading, 0, 1023, 0, graphSize);
  Serial.print("["); 
  for(int i = 0; i < graphSize; i++){ 
    if (i == softPotPosition) 
      Serial.print("@"); 
    else 
      Serial.print("-"); 
  } 
  Serial.println("] position - " + String(softPotReading));
  delay(500);
}
