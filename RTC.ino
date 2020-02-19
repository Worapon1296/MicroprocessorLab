#include <ThreeWire.h>
#include <RtcDS1302.h> 
RtcDateTime start_time; 
ThreeWire myWire(4,5,2); // IO, SCLK, CE 
RtcDS1302<ThreeWire> Rtc(myWire); 
void printDateTime(const RtcDateTime& dt)
{ 
 Serial.print(dt.Year(), DEC); 
 Serial.print('/'); 
 Serial.print(dt.Month(), DEC); 
 Serial.print('/'); 
 Serial.print(dt.Day(), DEC); 
 Serial.print(' '); 
 Serial.print(dt.Hour(), DEC); 
 Serial.print(':'); 
 Serial.print(dt.Minute(), DEC); 
 Serial.print(':'); 
 Serial.print(dt.Second(), DEC); 
 Serial.println(); 
 Serial.print("Total Seconds since 1/1/2000 : "); 
 Serial.print(dt.TotalSeconds()); 
 Serial.println();
}
void setup() { 
 pinMode(13, HIGH);
 Serial.begin(9600); 
 Rtc.Begin(); 
 RtcDateTime setting_time(2020,2,19,0,0,0); 
 // year, month, dayOfMonth, hour, minute, second 
 printDateTime(setting_time); 
 Rtc.SetDateTime(setting_time); 
 start_time = Rtc.GetDateTime().TotalSeconds();
} 

void loop() { 
 RtcDateTime now = Rtc.GetDateTime(); 
 auto CTime = now.TotalSeconds();
 if(CTime - start_time <= (120)) 
 {
  printDateTime(now);
  digitalWrite(13, CTime % 2);
 }
 else 
 {
  digitalWrite(13, LOW);
 }
 delay(500); 
}
