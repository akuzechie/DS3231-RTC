//-------------------------------------------------
// DS3231_RTC.cpp - Source File
// Library for Programming DS3231 Real-Time Clock
// by: Anas Kuzechie (May 25, 2022)
//-------------------------------------------------
#include <Arduino.h>
#include <DS3231_RTC.h>
//========================================================================
// Constructor
//========================================================================
DS3231_RTC::DS3231_RTC() {}

byte DS3231_data[8];
//========================================================================
// Methods
//========================================================================
void DS3231_RTC::setTime(byte seconds, byte minutes, byte hours)
{
  Wire.beginTransmission(0x68); //I2C address of DS3231
  Wire.write(0x00);             //point to Seconds register
  Wire.write(seconds);
  Wire.write(minutes);
  Wire.write(hours);
  Wire.endTransmission();
  delay(10);
}
//------------------------------------------------------------------
void DS3231_RTC::setDate(byte day, byte date, byte month, byte year)
{
  Wire.beginTransmission(0x68); //I2C address of DS3231
  Wire.write(0x03);             //point to Day register
  Wire.write(day);
  Wire.write(date);
  Wire.write(month);
  Wire.write(year);
  Wire.endTransmission();
  delay(10);
}
//------------------------------------------------------------------
byte DS3231_RTC::readSeconds()
{
  Wire.beginTransmission(0x68);
  Wire.write(0x00);             //point to Seconds register
  Wire.endTransmission();
  //-------------------------------------------------------
  Wire.requestFrom(0x68, 1);
  if(Wire.available())
  {
    DS3231_data[0] = Wire.read();
  }
  //delay(10);
  return DS3231_data[0];
}
//------------------------------------------------------------------
byte DS3231_RTC::readMinutes()
{
  Wire.beginTransmission(0x68);
  Wire.write(0x01);             //point to Minutes register
  Wire.endTransmission();
  //-------------------------------------------------------
  Wire.requestFrom(0x68, 1);
  if(Wire.available())
  {
    DS3231_data[1] = Wire.read();
  }
  //delay(10);
  return DS3231_data[1];
}
//------------------------------------------------------------------
byte DS3231_RTC::readHours()
{
  Wire.beginTransmission(0x68);
  Wire.write(0x02);             //point to Hours register
  Wire.endTransmission();
  //-------------------------------------------------------
  Wire.requestFrom(0x68, 1);
  if(Wire.available())
  {
    DS3231_data[2] = Wire.read();
  }
  //delay(10);
  return DS3231_data[2];
}
//------------------------------------------------------------------
byte DS3231_RTC::readDay()
{
  Wire.beginTransmission(0x68);
  Wire.write(0x03);             //point to Day register
  Wire.endTransmission();
  //-------------------------------------------------------
  Wire.requestFrom(0x68, 1);
  if(Wire.available())
  {
    DS3231_data[3] = Wire.read();
  }
  //delay(10);
  return DS3231_data[3];
}
//------------------------------------------------------------------
byte DS3231_RTC::readDate()
{
  Wire.beginTransmission(0x68);
  Wire.write(0x04);             //point to Date register
  Wire.endTransmission();
  //-------------------------------------------------------
  Wire.requestFrom(0x68, 1);
  if(Wire.available())
  {
    DS3231_data[4] = Wire.read();
  }
  //delay(10);
  return DS3231_data[4];
}
//------------------------------------------------------------------
byte DS3231_RTC::readMonth()
{
  Wire.beginTransmission(0x68);
  Wire.write(0x05);             //point to Month register
  Wire.endTransmission();
  //-------------------------------------------------------
  Wire.requestFrom(0x68, 1);
  if(Wire.available())
  {
    DS3231_data[5] = Wire.read();
  }
  //delay(10);
  return DS3231_data[5];
}
//------------------------------------------------------------------
byte DS3231_RTC::readYear()
{
  Wire.beginTransmission(0x68);
  Wire.write(0x06);             //point to Year register
  Wire.endTransmission();
  //-------------------------------------------------------
  Wire.requestFrom(0x68, 1);
  if(Wire.available())
  {
    DS3231_data[6] = Wire.read();
  }
  //delay(10);
  return DS3231_data[6];
}
//------------------------------------------------------------------
byte DS3231_RTC::readTemp()
{
  Wire.beginTransmission(0x68);
  Wire.write(0x11);             //point to Temp register
  Wire.endTransmission();
  //-------------------------------------------------------
  Wire.requestFrom(0x68, 1);
  if(Wire.available())
  {
    DS3231_data[7] = Wire.read();
  }
  //delay(10);
  return DS3231_data[7];
}