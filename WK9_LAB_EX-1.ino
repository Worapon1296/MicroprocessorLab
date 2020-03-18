#define LED_PIN_0 9
#define INT_PIN   3

int toggle=1;
int t = 1000;
int count = 0;
void setup()
{
  pinMode(LED_PIN_0, OUTPUT);
  pinMode(INT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(INT_PIN),
  ISR_Callback, RISING);
  //RISING  : 0V to 5V
  //FALLING : 5V to 0V
  //CHANGE  : 0V to 5V or 5V to 0V
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(LED_PIN_0, HIGH);
  delay(t); 
  digitalWrite(LED_PIN_0, LOW);
  delay(t); 
}
void ISR_Callback()
{
  count++;
  digitalWrite(LED_PIN_0, toggle);
  toggle= !toggle ;
  if((count%3)==0)
  t = 1000;
  if((count%3)==1)
  t = 2000;
  if((count%3)==2)
  t = 3000;
  Serial.println("Called");
  Serial.println(t);
}
