#include <Wire.h>
#include <TimeLib.h>
#include <ESP8266WiFi.h>
#include <RTClib.h>
RTC_DS1307 RTC;

//Define slave 7 digits i2c display adress..................................

#define REG_SEG  0x0f
#define REG_MIN  0x05
#define REG_HOUR 0x7b

//Define alarm pin..........................................................
#define RINGPIN 8

int TIME_LEFT;
#define BREAKTIME=10;

//WiFi variables............................................................
const char ssid[] = "abc";        //your network SSID (name)
const char pass[] = "progsnob";       // your network password

int SEG;
int MIN;
int HOUR;

void CHCK_TIME(){
}

void GET_TIME(){
   DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
   SEG = now.second();
   HOUR = now.hour();
   MIN = now.minute();
}
void setup() {
  Wire.begin();
  RTC.begin();
  pinMode(RINGPIN, OUTPUT);
  TIME_LEFT=0;
}

void loop() {
 GET_TIME();
 CHCK_TIME();
  //printDigits(int(hour() * 100 + minute()));


}
