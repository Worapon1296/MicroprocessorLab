#include <ThreeWire.h>
ThreeWire myWire(4,5,2); // IO, SCLK, CE

void setup() 
{ 
 pinMode(13, OUTPUT);
} 

void loop() { 
 for(int i=0; i<60; i++) 
 {
   delay(1000);
   digitalWrite(13, HIGH);
   delay(1000);
   digitalWrite(13, LOW);
 }

}
