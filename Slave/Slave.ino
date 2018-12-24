#include <Wire.h>

//#define DIR  0x0f//For Seconds Display
//#define DIR  0x05//For Miniute Display
//#define  DIR 0x7b//For Hour Display
//#define DIR 0xf5 //For Temperature Display

#define a 2
#define b 3
#define c 4
#define d 5
#define a2 14
#define b2 15
#define c2 16
#define d2 17

int unit = 0;
int dec = 0;s

void setup() {
  Wire.begin(DIR);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(d2, OUTPUT);
}


void loop() {
}

void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    //char c = Wire.read(); // receive byte as a character
  }
  int x = Wire.read();    // receive byte as an integer
  dec = x / 10;
  unit = x - (dec * 10);
  switch (dec) {
    case 0:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      break;
    case 1:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      break;
    case 2:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      break;
    case 3:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      break;
    case 4:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      break;
    case 5:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      break;
    case 6:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      break;
    case 7:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      break;
    case 8:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      break;
    case 9:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      break;
  }
  switch (unit) {
    case 0:
      digitalWrite(a2, LOW);
      digitalWrite(b2, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(d2, LOW);
      break;
    case 1:
      digitalWrite(a2, HIGH);
      digitalWrite(b2, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(d2, LOW);
      break;
    case 2:
      digitalWrite(a2, LOW);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, LOW);
      digitalWrite(d2, LOW);
      break;
    case 3:
      digitalWrite(a2, HIGH);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, LOW);
      digitalWrite(d2, LOW);
      break;
    case 4:
      digitalWrite(a2, LOW);
      digitalWrite(b2, LOW);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, LOW);
      break;
    case 5:
      digitalWrite(a2, HIGH);
      digitalWrite(b2, LOW);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, LOW);
      break;
    case 6:
      digitalWrite(a2, LOW);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, LOW);
      break;
    case 7:
      digitalWrite(a2, HIGH);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, LOW);
      break;
    case 8:
      digitalWrite(a2, LOW);
      digitalWrite(b2, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(d2, HIGH);
      break;
    case 9:
      digitalWrite(a2, HIGH);
      digitalWrite(b2, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(d2, HIGH);
      break;
  }
}