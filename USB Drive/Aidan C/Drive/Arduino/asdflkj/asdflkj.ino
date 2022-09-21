#include <SoftwareSerial.h>

// right motor
const int AIN1 = 7; // control motor pin A1
const int AIN2 = 4; // control motor pin A2
const int PWMA = 6; // control the A speed

// left motor
const int BIN1 = 2;  // control motor pin B1
const int BIN2 = 3;  // control motor pin B2
const int PWMB = 5;  // control the B speed

const int trig = 8;
const int echo = 9;

bool algoFunc1 = true;
bool algoFunc2 = true;
bool algoFunc3 = true;
bool algoFunc4 = true;
bool algoFunc5 = true;
bool algoFunc6 = true;
bool algoFunc7 = true;

bool nextFunc = false;

int indata;
SoftwareSerial mySerial(10, 11);

void allstop() {
    digitalWrite(AIN1, LOW);  
    digitalWrite(AIN2, LOW);   
    digitalWrite(BIN1, LOW);  
    digitalWrite(BIN2, LOW);   
    analogWrite(PWMA, 0);    
    analogWrite(PWMB, 0);    
}

void  moveforward() {
    digitalWrite(AIN1, HIGH);  
    digitalWrite(AIN2, LOW);   
    digitalWrite(BIN1, HIGH);  
    digitalWrite(BIN2, LOW);   
    analogWrite(PWMA, 100);    
    analogWrite(PWMB, 100);    
}

void turnright3()  {
    digitalWrite(AIN1, LOW);  
    digitalWrite(AIN2, HIGH); 
    digitalWrite(BIN1, HIGH); 
    digitalWrite(BIN2, LOW);  
    analogWrite(PWMA, 200);   
    analogWrite(PWMB, 100);   
}

void turnright2() {
    digitalWrite(AIN1, LOW);  
    digitalWrite(AIN2, HIGH); 
    digitalWrite(BIN1, HIGH); 
    digitalWrite(BIN2, LOW);  
    analogWrite(PWMA, 166);   
    analogWrite(PWMB, 100);  
}

void turnright1() {
    digitalWrite(AIN1, LOW);  
    digitalWrite(AIN2, HIGH); 
    digitalWrite(BIN1, HIGH); 
    digitalWrite(BIN2, LOW);  
    analogWrite(PWMA, 133);   
    analogWrite(PWMB, 100);  
}

void turnleft3() {
    digitalWrite(AIN1, LOW);  
    digitalWrite(AIN2, HIGH); 
    digitalWrite(BIN1, HIGH); 
    digitalWrite(BIN2, LOW);  
    analogWrite(PWMA, 100);   
    analogWrite(PWMB, 200);
}

void turnleft2() {
    digitalWrite(AIN1, LOW);  
    digitalWrite(AIN2, HIGH); 
    digitalWrite(BIN1, HIGH); 
    digitalWrite(BIN2, LOW);  
    analogWrite(PWMA, 100);   
    analogWrite(PWMB, 166);
}

void turnleft1() {
    digitalWrite(AIN1, LOW);  
    digitalWrite(AIN2, HIGH); 
    digitalWrite(BIN1, HIGH); 
    digitalWrite(BIN2, LOW);  
    analogWrite(PWMA, 100);   
    analogWrite(PWMB, 200);
}

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  bool nextFunc = true;
  // put your setup code here, to run once:

}

void loop() {
  if(mySerial.available() > 0)
  {
indata = mySerial.parseInt();
Serial.println(indata);

  if(0 < indata < 23)
  {
    algoFunc1 = false;
  }
  if(23 < indata < 46)
  {
    algoFunc2 = false;
  }
  if(46 < indata < 69)
  {
    algoFunc3 = false;
  }
  if(69 < indata < 91)
  {
    algoFunc4 = false;
  }
  if(91 < indata < 114)
  {
    algoFunc5 = false;
  }
  if(114 < indata < 137)
  {
    algoFunc6 = false;
  }
  if(137 < indata < 160)
  {
    algoFunc7 = false;
  }
//  else
//  {
//    
//  }

  if(nextFunc = true)
  
    if(!algoFunc1 && algoFunc2 && algoFunc3 && algoFunc4 && algoFunc5 && algoFunc6 && algoFunc7)
    {
      turnleft3();
    }
    if(algoFunc1 && !algoFunc2 && algoFunc3 && algoFunc4 && algoFunc5 && algoFunc6 && algoFunc7)
    {
      turnleft2();
    }
    if(algoFunc1 && algoFunc2 && !algoFunc3 && algoFunc4 && algoFunc5 && algoFunc6 && algoFunc7)
    {
      turnleft1();
    }
    if(algoFunc1 && algoFunc2 && algoFunc3 && !algoFunc4 && algoFunc5 && algoFunc6 && algoFunc7)
    {
      moveforward();
    }
    if(algoFunc1 && algoFunc2 && algoFunc3 && algoFunc4 && !algoFunc5 && algoFunc6 && algoFunc7)
    {
      turnright1();
    }
    if(algoFunc1 && algoFunc2 && algoFunc3 && algoFunc4 && algoFunc5 && !algoFunc6 && algoFunc7)
    {
      turnright2();
    }
    if(algoFunc1 && algoFunc2 && algoFunc3 && algoFunc4 && algoFunc5 && algoFunc6 && !algoFunc7)
    {
      turnright3();
    }
  else
  {
    allstop(); 
  }
  }
    
  Serial.println(indata);
  delay(50);
}
