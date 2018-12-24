#include <Wire.h>
#include <TimeLib.h>
#include <TimeAlarms.h>
AlarmId id;
#include <RTClib.h>
RTC_DS3231 RTC;//Define RTC type
#include <DHT.h>
#define DHTTYPE DHT11//Define DHT type.
#define DHTPIN 8
DHT dht(DHTPIN, DHTTYPE);

//Define slave 7 digits i2c display adress..................................

#define REG_SEG  0x0f
#define REG_MIN  0x05
#define REG_HOUR 0x7b

#define REG_TEMP 0xf5

//Define alarm adress......................................................
#define REG_RING 0xcc

boolean IS_BREAK = false;
#define BREAKTIME=10;
int SEG_LEFT;
int MIN_LEFT;
int MIN_BREAK_END

int SEG;
int MIN;
int HOUR;

int TEMP = 0;

void CHCK_TIME() {
  if(IS_BREAK==true){
    SEG_LEFT=59-SEG;
    MIN_LEFT=MIN_BREAK_END-MIN;
  }
}

void GET_TEMP() {
  TEMP = dht.readTemperature();
}

void GET_TIME() {
  DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
  SEG = now.second();
  HOUR = now.hour();
  MIN = now.minute();
}

void PRINT_TEMP() {
  Wire.beginTransmission(REG_TEMP);
  Wire.write(TEMP);
  Wire.endTransmission();

}

void PRINT_TIME() {
  Wire.beginTransmission(REG_SEG);
  Wire.write(SEG);
  Wire.endTransmission();
  /*Wire.beginTransmission(REG_MIN);
    Wire.write(MIN);
    Wire.endTransmission();
    Wire.beginTransmission(REG_HOUR);
    Wire.write(HOUR);
    Wire.endTransmission();*/
}

void RING() {
  Wire.beginTransmission(REG_RING);
  Wire.write(1);
  Wire.endTransmission();
  IS_BREAK = false;
}

void BREAK() {
  RING();
  IS_BREAK = true;
  MIN_BREAK_END=MIN+BREAKTIME;
}

void ALARMS() {
  Alarm.alarmRepeat(7, 30, 0, RING);
  Alarm.alarmRepeat(8, 20, 0, RING);
  Alarm.alarmRepeat(9, 00, 0, BREAK);
  Alarm.alarmRepeat(9, 10, 0, RING);
  Alarm.alarmRepeat(9, 50, 0, RING);
  Alarm.alarmRepeat(10, 30, 0, BREAK);
  Alarm.alarmRepeat(10, 40, 0, RING);
  Alarm.alarmRepeat(11, 20, 0, RING);
  Alarm.alarmRepeat(12, 00, 0, BREAK);
  Alarm.alarmRepeat(12, 10, 0, RING);
  Alarm.alarmRepeat(12, 50, 0, RING);
  Alarm.alarmRepeat(13, 30, 0, BREAK);
  Alarm.alarmRepeat(13, 40, 0, RING);
  Alarm.alarmRepeat(14, 20, 0, RING);
  Alarm.alarmRepeat(15, 00, 0, RING);
  Alarm.alarmRepeat(15, 40, 0, RING);
}

void setup() {
  Wire.begin();
  dht.begin();
  TIME_LEFT = 0;
  ALARMS();
}

void loop() {
  GET_TIME();
  GET_TEMP();
  CHCK_TIME();
  PRINT_TIME();
  PRINT_TEMP();
}
