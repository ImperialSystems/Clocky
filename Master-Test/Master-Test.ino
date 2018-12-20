#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 RTC;
int SEG;
int MIN=0;
int HOUR;
void setup(){
    Wire.begin();
    Serial.begin(2000000);
}

void loop(){
    DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
   SEG = now.second();
   Wire.beginTransmission(0x0f);
  Wire.write(SEG);
  Wire.endTransmission();
  if (MIN-SEG<0){
    Serial.println(HOUR);
    MIN=SEG;
    HOUR=0;
  }
  HOUR=HOUR+1;

}
