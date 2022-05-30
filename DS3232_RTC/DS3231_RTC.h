//-------------------------------------------------
// DS3231_RTC.h - Header File
// Library for Programming DS3231 Real-Time Clock
// by: Anas Kuzechie (May 25, 2022)
//-------------------------------------------------
#include <Wire.h>
//-------------------
//header guards
#ifndef DS3231_RTC_h
#define DS3231_RTC_h
//-----------------------------------------------------------
//class definition
class DS3231_RTC
{
    public:
        //constructor
        DS3231_RTC();
        //methods
        void setTime(byte seconds, byte minutes, byte hours);
        void setDate(byte day, byte date, byte month, byte year);
        byte readSeconds();
        byte readMinutes();
        byte readHours();
        byte readDay();
        byte readDate();
        byte readMonth();
        byte readYear();
        byte readTemp();
};
//-----------------------------------------------------------
#endif