//-------------------------------------------------------
// DS3231 Time, Date & Temp on MAX7219 Dot Matrix Display
// via DS3231_RTC.h & MAX72198by32Disp.h Libraries
// by: Anas Kuzechie
//-------------------------------------------------------
#include <Wire.h>
#include <DS3231_RTC.h>
#include <MAX72198by32Disp.h>
#include "MAX7219_Letters.h"
//-----------------------------
DS3231_RTC rtc;
                    /*DIN CS CLK*/
MAX72198by32Disp disp(2,  3,  4);
//--------------------------------
boolean state = false;
unsigned long millisCapture = millis(), myDelay = 30000;
//==========================================================
void setup()
{
  Wire.begin();
  //-------------------------
  disp.Initialize(0);
  disp.Clear(); delay(1000);
}
//==========================================================
void loop()
{
  if(millis() - millisCapture > myDelay) dispDateTemp();
  //----------------------------------------------------
  //display MSD of hours, LSD & MSD of minutes
  //----------------------------------------------------
  disp.Number(1, (rtc.readHours() & 0x30) >> 4);
  disp.Number(3, (rtc.readMinutes() & 0xF0) >> 4);
  disp.Number(4, rtc.readMinutes() & 0x0F);
  //----------------------------------------------------
  //LSD of hours with blinking decimal point
  //----------------------------------------------------
  if(state == true)  /*LSD without decimal point*/
  {
    disp.Number(2, rtc.readHours() & 0x0F);
    state = !state; delay(1000);
  }
  if(state == false) /*LSD with decimal point*/
  {
    disp.Numberdp(2, rtc.readHours() & 0x0F);
    state = !state; delay(1000);
  }
}
//==========================================================
void dispDateTemp()
{
  disp.Clear(); delay(1000);
  //----------------------------------------------
  //display day of the week (Sun, Mon, ...etc.)
  //----------------------------------------------
  byte weekDay = rtc.readDay();
  switch(weekDay)
  {
    case 1:
    disp.Letter(1, S); disp.Letter(2, u); disp.Letter(3, n);
    break;
    case 2:
    disp.Letter(1, M); disp.Letter(2, o); disp.Letter(3, n);
    break;
    case 3:
    disp.Letter(1, T); disp.Letter(2, u); disp.Letter(3, e);
    break;
    case 4:
    disp.Letter(1, W); disp.Letter(2, e); disp.Letter(3, d);
    break;
    case 5:
    disp.Letter(1, T); disp.Letter(2, h); disp.Letter(3, u);
    break;
    case 6:
    disp.Letter(1, F); disp.Letter(2, r); disp.Letter(3, i);
    break;
    case 7:
    disp.Letter(1, S); disp.Letter(2, a); disp.Letter(3, t);
  }
  //----------------------------------------------
  delay(2000); disp.Clear(); delay(1000);
  //----------------------------------------------
  //display month & day
  //----------------------------------------------
  disp.Number  (1, (rtc.readDate() & 0xF0) >> 4);
  disp.Numberdp(2, rtc.readDate() & 0x0F);
  disp.Number  (3, (rtc.readMonth() & 0x30) >> 4);
  disp.Number  (4, rtc.readMonth() & 0x0F);
  //----------------------------------------------
  delay(2000); disp.Clear(); delay(1000);
  //----------------------------------------------
  //display year
  //----------------------------------------------
  disp.Number(1, 2);
  disp.Number(2, 0);
  disp.Number(3, (rtc.readYear() & 0x30) >> 4);
  disp.Number(4, rtc.readYear() & 0x0F);
  //----------------------------------------------
  delay(2000); disp.Clear(); delay(1000);
  //----------------------------------------------
  //display temperature
  //----------------------------------------------
  disp.Letter(1, T);
  disp.Number(2, rtc.readTemp()/10);
  disp.Number(3, rtc.readTemp()%10);
  disp.Letter(4, dc);
  //----------------------------------------------
  delay(2000); disp.Clear(); delay(1000);
  //----------------------------------------------
  millisCapture = millis();
}