int clk_pin = 13;
int latch_pin = 10;
int data_pin = 11;
bool toggle;
int count;
int val;

void setLED(uint16_t state){
  digitalWrite(latch_pin,LOW);
  for(int i = 0; i < 16 ; i++){

     digitalWrite(data_pin, (state>>(15-i)) & 0x01);

     digitalWrite(clk_pin,HIGH);
     digitalWrite(clk_pin,LOW);
  }
  digitalWrite(latch_pin,HIGH);
}
  void setup() {

    pinMode(clk_pin,OUTPUT);
    pinMode(latch_pin,OUTPUT);
    pinMode(data_pin,OUTPUT);

    pinMode(A0,INPUT_PULLUP);
    pinMode(A1,INPUT_PULLUP);
    pinMode(A2,INPUT);
  }
  void loop(){
    val= analogRead(A2);

    setLED(~(0x0001<<count));  //count++;
    if(count>15)
      count=0;
    if(count<0)
      count=16;
    if(((PINC>>0) & 0x01) == 0)
    {
      count++ ;
    }
    else if (((PINC>>1) & 0x01) == 0)
    {
      count-- ;  
    }
    
    delay(val);
  }
