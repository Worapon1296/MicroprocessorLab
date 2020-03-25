#define PIN_0 2
#define PIN_1 5

int Count = 0; 
 
void setup() 
{   
  pinMode(PIN_0, INPUT_PULLUP);  
  pinMode(PIN_1, INPUT);   
  Serial.begin(9600);   
  attachInterrupt(digitalPinToInterrupt(2),
                 AAA, RISING);
} 
void loop()
{
  Serial.println(Count);
  delay(500);
}

void AAA() 
{   
    Count = analogRead(PIN_1);
}
