#include <Wire.h>


void setup(){
    Wire.begin();
    Serial.begin(115200);
}

void loop(){
    for(int  i=0; i<10;i++){
        Wire.beginTransmission(0x0f);
        Wire.write(i);
        Wire.endTransmission();
        Serial.println(i);
        delay(1000);
        
    }
}
