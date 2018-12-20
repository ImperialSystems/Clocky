#include <Wire.h>
#include <TimeLib.h>
#include <RTClib.h>
RTC_DS3231 RTC;//Define RTC type.
#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE DHT11//Define DHT type.
#define DHTPIN 8
DHT dht(DHTPIN, DHTTYPE);

//Define slave 7 digits i2c display adress..................................

#define REG_SEG  0x0f
#define REG_MIN  0x05
#define REG_HOUR 0x7b

#define REG_TEMP 0xf5

//Define alarm pin..........................................................
#define RINGPIN 8

int TIME_LEFT;
#define BREAKTIME=10;

int SEG;
int MIN;
int HOUR;

int TEMP=0;

void CHCK_TIME() {
}

void GET_TEMP(){
  TEMP=dht.readTemperature();
  
}

void GET_TIME() {
  DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
  SEG = now.second();
  HOUR = now.hour();
  MIN = now.minute();
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

void setup() {
  Wire.begin();
  dht.begin();
  pinMode(RINGPIN, OUTPUT);
  TIME_LEFT = 0;
}

void loop() {
  GET_TIME();
  GET_TEMP();
  //CHCK_TIME();
  PRINT_TIME();
}
