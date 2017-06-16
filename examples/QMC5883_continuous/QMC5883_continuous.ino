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
  Serial.print(qq.getHeading('z'));
  Serial.print("rad, ");
  Serial.print(qq.getHeadingDegree('z'));
  Serial.println("deg");
}
