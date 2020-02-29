#include <SPI.h> 
#include <Wire.h> 
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h> 
#define SCREEN_WIDTH 128 // OLED display width, in pixels 
#define SCREEN_HEIGHT 64 // OLED display height, in pixels 
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins) 
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin) 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 
void setup() { 
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c 
  display.clearDisplay(); // clears the screen and buffer 
  display.drawPixel(127, 63, WHITE); 
  //display.drawLine(0, 63, 127, 21, WHITE); 
  display.drawCircle(10, 55, 5, WHITE); 
  display.drawCircle(10, 59, 5, WHITE);  
  
  //display.drawTriangle(70, 60, 90, 60, 80, 46, WHITE); 
  display.setTextSize(1); 
  display.setTextColor(WHITE); 
  display.setCursor(0,0); 
  //display.println("Welcome"); 
  //display.setTextSize(2); 
  //display.println("Hello!"); 
  //display.setTextColor(BLACK, WHITE); 
  //display.setTextSize(1); 
  //display.println("www.krai.io"); 
  display.setTextColor(WHITE, BLACK); 
  display.display(); 
} 
 
void loop() { 
  if((digitalRead(2)==LOW)&(digitalRead(3)==LOW))
  {display.clearDisplay();
   display.fillCircle(10, 55, 5, WHITE);
   display.fillCircle(10, 59, 5, WHITE);
   display.display();}

   if((digitalRead(2)==HIGH)&(digitalRead(3)==LOW))
  {display.clearDisplay();
   display.fillCircle(10, 55, 5, WHITE);
   display.drawCircle(10, 59, 5, WHITE);
   display.display();}

   if((digitalRead(2)==LOW)&(digitalRead(3)==HIGH))
  {display.clearDisplay();
   display.drawCircle(10, 55, 5, WHITE);
   display.fillCircle(10, 59, 5, WHITE);
   display.display();}

   if((digitalRead(2)==HIGH)&(digitalRead(3)==HIGH))
  {display.clearDisplay();
   display.drawCircle(10, 55, 5, WHITE);
   display.drawCircle(10, 59, 5, WHITE);
   display.display();}
   
  
 
} 
