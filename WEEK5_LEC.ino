#include <SPI.h>
int STCP_pin =10;
void setup() 
{
  SPI.begin();
  pinMode(STCP_pin, OUTPUT);
}
void loop() 
{
 spi_write(0xAA);
 delay(500);
 spi_write(0x55);
 delay(500);
}
void spi_write(unsigned char cData)
{
  SPI.transfer(cData);
  //Storage register clock input
  digitalWrite(STCP_pin, HIGH);
  digitalWrite(STCP_pin, LOW);
}
