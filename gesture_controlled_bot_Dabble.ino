#define lm1 10 
#define lm2 11 
#define rm1 9 
#define rm2 5
#define led 13


#define CUSTOM_SETTINGS
#define INCLUDE_SENSOR_MODULE
#include <Dabble.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(led,OUTPUT);
  Dabble.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Dabble.processInput();
  float xr= Sensor.getAccelerometerXaxis();
  float yr= Sensor.getAccelerometerYaxis();
  float lux = Sensor.getLightIntensity();
  if (yr <= -4.50)
  {
    fwd();
    Serial.println("FORWARD");
  }
  else if(yr >= 4.50)
  {
    bck();
    Serial.println("BACKWARD");
  }
  else if(xr >= 4.50)
  {
    lft();
    Serial.println("LEFT");
  }
  else if(xr <= -4.50)
  {
    rit();
    Serial.println("RIGHT");
  }
  else
  {
    stp();
    Serial.println("STOP");
  }


  if (lux <= 1.00)
  {
    Serial.println("Low Light, Switching On LED");
    digitalWrite(led, HIGH);
  }
  else
  {
    Serial.println("Sufficient Light, Switching Off LED");
    digitalWrite(led, LOW);
  }
}




void fwd()
{
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
}
void bck()
{
  digitalWrite(rm2,HIGH);
  digitalWrite(rm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(lm1,LOW);
  
}
void lft()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}
void rit()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}
void stp()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}
