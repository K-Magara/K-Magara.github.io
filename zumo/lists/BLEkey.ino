#include <Zumo32U4.h>

Zumo32U4Motors  motors;

void setup()
{
  ledRed(1);
  ledYellow(1);
  ledGreen(1);
  Serial1.begin(9600);
  while(!Serial1);
  ledRed(0);
  ledYellow(0);
  ledGreen(0);
}

void loop()
{
  if ( Serial1.available() <= 0 ) {
    delay(100);
    return;
  }
  ledRed(1);
  byte  var = Serial1.read();
  switch ( var ) {
  case 0:
    motors.setSpeeds(0,0);
    break;
  case 1:
    motors.setSpeeds(100, 100);
    break;
  case 2:
    motors.setSpeeds(-100, -100);
    break;
  case 3:
    motors.setSpeeds(100, -100);
    break;
  case 4:
    motors.setSpeeds(-100, 100);
    break;
  }
  delay(100);
  ledRed(0);
}
