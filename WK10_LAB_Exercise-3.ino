#define PIN_0 2
#define PIN_1 3
#define PIN_B 5
long count = 0;

void setup()
{
  pinMode(PIN_0, INPUT_PULLUP);
  pinMode(PIN_1, INPUT_PULLUP);
  
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(2), countIt, RISING);
}

void countIt() {
  count += digitalRead(PIN_B) ? -1 : 1;
}

void loop()
{
  Serial.println(count);
  delay(100);
}
