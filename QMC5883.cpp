/**************************************************************************/
/*
  For modified module QMC5883 instead of HMC5883.
  Call calculate() function before using any other function.
  Retrieve individual x, y, z readings with getX(), getY(), and getZ(), or 
  directly use getHeading('z') or getHeadingDegree('z') for getting the 
  heading angle with 'z' axis pointing upward. Use a single lower-case letter 
  to indicate the axis.
  
  
  Author: Michael Huang
  Version: V1.2 - 20170612
*/
/**************************************************************************/

#include "Arduino.h"
#include <Wire.h>
#include "QMC5883.h"

QMC5883::QMC5883() {
  add = 0x0D;
  nowX = 0;
  nowY = 0;
  nowZ = 0;
}

void QMC5883::begin() {
  Wire.begin();
  delay(50);
  Wire.beginTransmission(add);
  Wire.write(0x0B);
  Wire.write(0x01);
  Wire.endTransmission();
  delay(50);
  Wire.beginTransmission(add);
  Wire.write(0x20);
  Wire.write(0x40);
  Wire.endTransmission();
  delay(50);
  Wire.beginTransmission(add);
  Wire.write(0x21);
  Wire.write(0x01);
  Wire.endTransmission();
  delay(50);
  Wire.beginTransmission(add);
  Wire.write(0x09);
  Wire.write(0x0D);
  Wire.endTransmission();
  delay(50);
}

void QMC5883::calculate() {
  Wire.beginTransmission(add);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(50);
  Wire.requestFrom(add, 6);
  while(Wire.available()>0){
    nowX = Wire.read();
    nowX |= Wire.read()<<8;
    nowY = Wire.read();
    nowY |= Wire.read()<<8;
    nowZ = Wire.read();
    nowZ |= Wire.read()<<8;
  }
}

int QMC5883::getX() {
  return nowX;
}

int QMC5883::getY() {
  return nowY;
}

int QMC5883::getZ() {
  return nowZ;
}

float QMC5883::getHeading(uint8_t up) {
  if(up == 'x') return atan2(nowZ, nowY);
  else if(up == 'y') return atan2(nowX, nowZ);
  else if(up == 'z') return atan2(nowY, nowX);
  else return 0.0;
}

float QMC5883::getHeadingDegree(uint8_t up) {
  float tmp;
  if(up == 'x'){
    tmp = atan2(nowZ, nowY)*180/3.14159;
    if(tmp < 0) tmp += 360;
    return tmp;
  }else if(up == 'y'){
    tmp = atan2(nowX, nowZ)*180/3.14159;
    if(tmp < 0) tmp += 360;
    return tmp;
  }else if(up == 'z'){
    tmp = atan2(nowY, nowX)*180/3.14159;
    if(tmp < 0) tmp += 360;
    return tmp;
  }else return 0.0;
}
