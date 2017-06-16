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

/*=========================================================================
I2C ADDRESS/BITS
-----------------------------------------------------------------------*/
#define QMC5883_address                       (0x0D)
/*=========================================================================*/


class QMC5883{
 public:
  QMC5883();
  void begin(void);
  void calculate(void);
  int getX(void);
  int getY(void);
  int getZ(void);
  float getHeading(uint8_t);
  float getHeadingDegree(uint8_t);

 private:
  uint8_t add;
  int nowX;
  int nowY;
  int nowZ;
};
