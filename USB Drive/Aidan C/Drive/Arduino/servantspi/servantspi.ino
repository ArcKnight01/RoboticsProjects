#include <SPI.h>

void setup() {
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.setDataMode(SPI_MODE0);
  delay(1000);
}

void loop() {
  char buff[128] = {0};
  int msgLength = 0;
  digitalWrite(10, LOW);
  delay(1);
//  if (SPI.transfer(1) == 170) {
//    SPI.transfer(&msgLength, 4);
//    if (temp > 0) {
//      SPI.transfer(&buff, msgLength);
//    }
//  }
//  digitalWrite(10, HIGH);
//  Serial.println(buff);
//  delay(1);
}
