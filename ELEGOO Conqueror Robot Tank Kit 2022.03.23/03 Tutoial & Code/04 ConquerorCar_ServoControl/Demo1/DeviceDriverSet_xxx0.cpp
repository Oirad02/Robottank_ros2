/*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2020-06-12 16:36:20
 * @LastEditors: Changhua
 * @Description: conqueror robot tank
 * @FilePath: 
 */
#include "DeviceDriverSet_xxx0.h"
#include <arduino.h>
/*Servo*/

Servo myservo; // create servo object to control a servo
void DeviceDriverSet_Servo::DeviceDriverSet_Servo_Init(unsigned int Position_angle)
{
  myservo.attach(PIN_Servo_z, 500, 2400); //500: 0 degree  2400: 180 degree
  myservo.attach(PIN_Servo_z);
  myservo.write(Position_angle); //sets the servo position according to the 90（middle）
  delay(500);

  myservo.attach(PIN_Servo_y, 500, 2400); //500: 0 degree  2400: 180 degree
  myservo.attach(PIN_Servo_y);
  myservo.write(Position_angle); //sets the servo position according to the 90（middle）
  delay(500);
  myservo.detach();
}
#if _Test_DeviceDriverSet
void DeviceDriverSet_Servo::DeviceDriverSet_Servo_Test(void)
{
  for (;;)
  {
    myservo.attach(PIN_Servo_z);
    myservo.write(180);
    delay(500);
    myservo.write(0);
    delay(500);
  }
}
#endif

/*0.17sec/60degree(4.8v)*/
void DeviceDriverSet_Servo::DeviceDriverSet_Servo_control(unsigned int Position_angle)
{
  myservo.attach(PIN_Servo_z);
  myservo.write(Position_angle);
  delay(450);
  myservo.detach();
}
//选择舵机、角度
void DeviceDriverSet_Servo::DeviceDriverSet_Servo_controls(uint8_t Servo, unsigned int Position_angle)
{
  if (Servo == 1) //Servo_z
  {
    myservo.attach(PIN_Servo_z);
    myservo.write(10 * Position_angle);
    //delay(30 * 3);
    delay(500);
  }
  else if (Servo == 2) //Servo_y
  {
    myservo.attach(PIN_Servo_y);
    myservo.write(10 * Position_angle);
    //delay(30 * 3);
    delay(500);
  }
  myservo.detach();
}
