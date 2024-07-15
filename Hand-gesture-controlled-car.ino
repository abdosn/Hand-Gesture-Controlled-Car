#include <MPU6050_tockn.h>
#include <Wire.h>

int IN1 = 3;
int IN2 = 4;
int IN3 = 5;
int IN4 = 6;
int intr = 2 ; 
//12 right
//34 left
MPU6050 mpu6050(Wire);
double x,y,z;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(intr, INPUT);
}

void loop() {
  mpu6050.update();
  Serial.print("angleX : ");
  x=mpu6050.getAngleX();
  Serial.println(x);
  Serial.print("\tangleY : ");
  y=mpu6050.getAngleY();
  Serial.println(y);
  //Serial.print("\tangleZ : ");
  z=mpu6050.getAngleZ();
  //Serial.println(z);

  if((y>-5.0)&&(y<5))
{
      if(x>5.0)
      {
      digitalWrite(IN1,1);
      digitalWrite(IN2,0);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0);
      }
      else if(x<-5.0)
      {
      digitalWrite(IN1,0);
      digitalWrite(IN2,1);
      digitalWrite(IN3,0);
      digitalWrite(IN4,1);
      }
      else
      {
      digitalWrite(IN1,0);
      digitalWrite(IN2,0);
      digitalWrite(IN3,0);
      digitalWrite(IN4,0);
      }
}
  else if(y>5.0)
  {
      if(x>0.0)
      {
      digitalWrite(IN1,0);
      digitalWrite(IN2,0);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0);
      }
      else if(x<0.0)
      {
      digitalWrite(IN1,0);
      digitalWrite(IN2,0);
      digitalWrite(IN3,0);
      digitalWrite(IN4,1);
      }  
  }
  else if(y<-5.0)
  {
        if(x>5.0)
      {
      digitalWrite(IN1,1);
      digitalWrite(IN2,0);
      digitalWrite(IN3,0);
      digitalWrite(IN4,0);
      }
      else if(x<-5.0)
      {
      digitalWrite(IN1,0);
      digitalWrite(IN2,1);
      digitalWrite(IN3,0);
      digitalWrite(IN4,0);
      }  
  }
}
