/**************************************************************************/
/*
  For modified module QMC5883 instead of HMC5883.
  Call calculate() function before using getX(), getY(), and getZ()
  Or directly use getHeading('z') for getting the heading angle with 'z' axis
  pointing upward. Use a single lower-case letter to indicate the axis.
  
  Author: Michael Huang
  Version: V1.2 - 20170612
*/
/**************************************************************************/

#include<Wire.h>
#include<QMC5883.h>

QMC5883 qq;

void setup() {
  Serial.begin(9600);
  qq.begin();
}

void loop() {
  delay(200);
  qq.calculate();
  Serial.print("x ");
  Serial.print(qq.getX());
  Serial.print(", ");
  Serial.print("y ");
  Serial.print(qq.getY());
  Serial.print(", ");
  Serial.print("z ");
  Serial.println(qq.getZ());
  
  delay(200);
  Serial.print("heading angle: ");
  Serial.println(qq.getHeading('z'));
}
