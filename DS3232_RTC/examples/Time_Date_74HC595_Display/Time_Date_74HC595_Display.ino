//-----------------------------------------------------
// DS3231 Time, Date & Temp on 74HC595 4-Digit Display
// via DS3231_RTC.h & Reg74595Disp.h Libraries
// by: Anas Kuzechie
//-----------------------------------------------------
#include <Wire.h>
#include <DS3231_RTC.h>
#include <Reg74595Disp.h>
//---------------------------------
DS3231_RTC rtc;
                /*DIO RCLK SCLK*/
Reg74595Disp disp(2,  3,   4);
//---------------------------------
unsigned long millisCapture = millis(), myDelay = 10000;
//=======================================================
void setup()
{
  Wire.begin();
  disp.Clear(); delay(1000);
}
//=======================================================
void loop()
{
  disp.Num  (1, (rtc.readHours() & 0xF0) >> 4);
  disp.Numdp(2, rtc.readHours() & 0x0F);
  disp.Num  (3, (rtc.readMinutes() & 0xF0) >> 4);
  disp.Num  (4, rtc.readMinutes() & 0x0F);
  //----------------------------------------------------
  if(millis() - millisCapture > myDelay) dispDateTemp();
}
//=======================================================
void dispDateTemp()
{
  disp.Clear(); delay(1000);
  for(int i=1; i<1000; i++)
  {
    disp.Num  (1, (rtc.readDate() & 0xF0) >> 4);
    disp.Numdp(2, rtc.readDate() & 0x0F);
    disp.Num  (3, (rtc.readMonth() & 0x30) >> 4);
    disp.Num  (4, rtc.readMonth() & 0x0F);
  }
  disp.Clear(); delay(1000);
  //---------------------------------------------
  for(int i=1; i<1000; i++)
  {
    disp.Num(1, 2);
    disp.Num(2, 0);
    disp.Num(3, (rtc.readYear() & 0x30) >> 4);
    disp.Num(4, rtc.readYear() & 0x0F);
  }
  disp.Clear(); delay(1000);
  //---------------------------------------------
  for(int i=1; i<1000; i++)
  {
    disp.Char(1, 't');
    disp.Num (2, rtc.readTemp() / 10);
    disp.Num (3, rtc.readTemp() % 10);
    disp.Char(4, 'c');
  }
  disp.Clear(); delay(1000);
  //---------------------------------------------
  millisCapture = millis();
}