//----------------------------
// DS3231 RTC Set Time & Date
// via DS3231_RTC.h Library
// by: Anas Kuzechie
//----------------------------
#include <Wire.h>
#include <DS3231_RTC.h>
//----------------------------
DS3231_RTC rtc;
//=============================================================
void setup()
{
  Wire.begin();
  //-----------------------------------------------------------
  /*enter time & date in BCD*/
  rtc.setTime(0x00, 0x38, 0x17);    /*seconds, minutes, hours*/
  /*day: 1-Sun, 2-Mon, 3-Tue, 4-Wed, 5-Thu, 6-Fri, 7-Sat*/
  rtc.setDate(4, 0x18, 0x05, 0x22); /*day, date, month, year*/
}
//=============================================================
void loop() {}