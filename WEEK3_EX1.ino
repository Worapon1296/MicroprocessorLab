int clk_pin = 13;
int latch_pin = 10;
int data_pin = 11;
bool toggle;
int count;

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
  }
  void loop(){
    for(count = 0 ; count < 16 ; count ++ ){

    setLED(~(0x0001<<count));
    delay(1000);}
  }
