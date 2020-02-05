int clk_pin = 13; //SHCP 
int latch_pin = 10;  //STCP 
int data_pin = 11;  //DS 
bool toggle; 
int map7seg[10] ={
  0b00111111,0b00000110,0b01011011,0b01001111,
  0b01100110,0b01101101,0b01111101,
  0b00000111,0b01111111,0b01101111,
};
void setLed(uint8_t state)
{
  for(int i = 0 ; i < 8 ; i++) 
    {
      digitalWrite(data_pin,state>>7-i & 0x01); 
      digitalWrite(clk_pin,HIGH); 
      digitalWrite(clk_pin,LOW); 
   }
   digitalWrite(latch_pin,HIGH); 
   digitalWrite(latch_pin,LOW); 
   delay(1000);
}

void setup() { 
  Serial.begin(9600);
  while(!Serial)
  {}
  Serial.println("\n\nString toInt():");
  Serial.println();
  pinMode(clk_pin,OUTPUT); 
  pinMode(latch_pin,OUTPUT); 
  pinMode(data_pin,OUTPUT); 
} 
void loop()
{
  String inString;
  if (Serial.available()!=0)
  {
     while(Serial.available()>0)
     {
    int inChar = Serial.read();
    inString = (char)inChar;
    Serial.print("Value:");
    Serial.println(inString.toInt());
     }
  setLed(map7seg[inString.toInt()]);
  }
} 
