#define MOTOR_D1_PIN 7 
#define MOTOR_D2_PIN 8 
#define MOTOR_PWM_PIN 6 
void setup() 
{
  Serial.begin(9600);
  pinMode(MOTOR_D1_PIN,OUTPUT);   
  pinMode(MOTOR_D2_PIN,OUTPUT);   
  pinMode(MOTOR_PWM_PIN,OUTPUT); 
} 
void loop() 
{delay(500);}

void MotorControl(int A)
{
  if(A>0)
  {
     digitalWrite(MOTOR_D1_PIN,HIGH); 
     digitalWrite(MOTOR_D2_PIN,LOW); 
     analogWrite(MOTOR_PWM_PIN,A);
  }
  else if(A<0)
  {
     digitalWrite(MOTOR_D1_PIN,LOW); 
     digitalWrite(MOTOR_D2_PIN,HIGH); 
     analogWrite(MOTOR_PWM_PIN,A);
  }
  else if(A==0)
  {
     digitalWrite(MOTOR_D1_PIN,LOW); 
     digitalWrite(MOTOR_D2_PIN,LOW); 
     analogWrite(MOTOR_PWM_PIN,A);
  }
  Serial.print("SPEED = ");
  Serial.println(A);
}
 
void serialEvent() 
{    
  int SPEED = Serial.parseInt();
  Serial.print("INPUT = ");
  Serial.println(SPEED);
  MotorControl(SPEED);
}
