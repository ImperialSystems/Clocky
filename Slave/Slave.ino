#include <Wire.h>

#define a 0
#define b 1
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8

void setup(){
  Wire.begin(0x0f);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent);
}

void loop(){
delay(200);
}

void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    //char c = Wire.read(); // receive byte as a character
  }
  int x = Wire.read();    // receive byte as an integer
   switch(x){
       case 0:
       digitalWrite(a, HIGH);
       digitalWrite(b, HIGH);
       digitalWrite(c, HIGH);
       digitalWrite(d, HIGH);
       digitalWrite(e, HIGH);
       digitalWrite(f, HIGH);
       digitalWrite(g, HIGH);
       break;
       case 1:
       digitalWrite(a, LOW);
       digitalWrite(b, HIGH);
       digitalWrite(c, HIGH);
       digitalWrite(d, LOW);
       digitalWrite(e, LOW);
       digitalWrite(f, LOW);
       digitalWrite(g, LOW);
       break;
       case 2:
       digitalWrite(a, HIGH);
       digitalWrite(b, HIGH);
       digitalWrite(c, LOW);
       digitalWrite(d, HIGH);
       digitalWrite(e, HIGH);
       digitalWrite(f, LOW);
       digitalWrite(g, HIGH);
       break;
       case 3:
       digitalWrite(a, HIGH);
       digitalWrite(b, HIGH);
       digitalWrite(c, HIGH);
       digitalWrite(d, HIGH);
       digitalWrite(e, LOW);
       digitalWrite(f, LOW);
       digitalWrite(g, HIGH);
       break;
       case 4:
       digitalWrite(a, LOW);
       digitalWrite(b, HIGH);
       digitalWrite(c, HIGH);
       digitalWrite(d, HIGH);
       digitalWrite(e, LOW);
       digitalWrite(f, HIGH);
       digitalWrite(g, HIGH);
       break;
       case 5:
       digitalWrite(a, HIGH);
       digitalWrite(b, LOW);
       digitalWrite(c, HIGH);
       digitalWrite(d, HIGH);
       digitalWrite(e, LOW);
       digitalWrite(f, HIGH);
       digitalWrite(g, HIGH);
       break;
       case 6:
       digitalWrite(a, HIGH);
       digitalWrite(b, LOW);
       digitalWrite(c, HIGH);
       digitalWrite(d, HIGH);
       digitalWrite(e, HIGH);
       digitalWrite(f, HIGH);
       digitalWrite(g, HIGH);
       break;
       case 7:
       digitalWrite(a, HIGH);
       digitalWrite(b, HIGH);
       digitalWrite(c, HIGH);
       digitalWrite(d, LOW);
       digitalWrite(e, LOW);
       digitalWrite(f, LOW);
       digitalWrite(g, LOW);
       break;
       case 8:
       digitalWrite(a, HIGH);
       digitalWrite(b, HIGH);
       digitalWrite(c, HIGH);
       digitalWrite(d, HIGH);
       digitalWrite(e, HIGH);
       digitalWrite(f, HIGH);
       digitalWrite(g, LOW);
       break;
       case 9:
       digitalWrite(a, HIGH);
       digitalWrite(b, HIGH);
       digitalWrite(c, HIGH);
       digitalWrite(d, HIGH);
       digitalWrite(e, LOW);
       digitalWrite(f, HIGH);
       digitalWrite(g, HIGH);
       break;
       case 10:
       digitalWrite(a, LOW);
       digitalWrite(b, LOW);
       digitalWrite(c, LOW);
       digitalWrite(d, LOW);
       digitalWrite(e, LOW);
       digitalWrite(f, LOW);
       digitalWrite(g, HIGH);
       break;

   }      
}
