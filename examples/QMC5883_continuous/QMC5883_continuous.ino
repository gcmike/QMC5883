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
}
