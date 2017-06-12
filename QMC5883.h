/**************************************************************************/
/*
  For modified module QMC5883 instead of HMC5883.
  Call calculate() function before using getX(), getY(), and getZ()
  
  Author: Michael Huang
  Version: V1.0 - 20170612
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

 private:
  uint8_t add;
  int nowX;
  int nowY;
  int nowZ;
};
