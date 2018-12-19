#include <Wire.h>


void setup(){
    Wire.begin();
}

void loop(){
    for(int  i=0; i<10;i++){
        Wire.beginTransmission(0x0f);
        Wire.write(i);
        Wire.endTransmission();
        delay(200);
    }
}