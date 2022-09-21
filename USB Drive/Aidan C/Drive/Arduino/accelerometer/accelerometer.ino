#include <SparkFun_MMA8452Q.h>
#include <Wire.h>

MMA8452Q accel;
float accX = 0;
float velX = 0;
float posX = 0;
float accY = 0;
float rotAccZ = 0;
float rotVelZ = 0;
float rotPosZ = 0;
float facing = 0;
const float sensorDistance = 0.15;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Wire.begin();

  if (accel.begin() == false) {
    Serial.println("Not Connected. Please check connections and read the hookup guide.");
    while (1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
 if(accel.available()){
    accX = accel.getCalculatedX() * 9.8;
    velX += accX * 0.005;
    posX += velX * 0.005;
    accY = accel.getCalculationY() * 9.8
//    Serial.print(accel.getCalculatedX(), 3);
    Serial.println(posX);
    Serial.print("\t");
    Serial.print(accel.getCalculatedY(), 3);
    Serial.print("\t");
    Serial.println(accel.getCalculatedZ(), 3);
  }
  delay(5);
}
