#include<LiquidCrystal.h>
/***
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float sum=0.0;
float arr[10];
int measurePin = A5;
int ledPower = 10;
unsigned int samplingTime = 280;
unsigned int deltaTime = 40;
unsigned int sleepTime = 9680;
int i=0;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
float micrometer=0;
***/
int measurePin = 0;
int ledPower = 10;
unsigned int samplingTime = 280;
unsigned int deltaTime = 40;
unsigned int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
float micrometer=0;
void setup(){
  Serial.begin(9600);
//  pinMode(ledPower,OUTPUT);
  //lcd.begin(16, 2);
}

void loop(){
 
  digitalWrite(ledPower,LOW);
  delayMicroseconds(samplingTime);
  voMeasured = analogRead(measurePin);

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH);
  delayMicroseconds(sleepTime);

  calcVoltage = voMeasured*(5.0/1024);
  dustDensity = 0.17*calcVoltage-0.1;

  
  if ( dustDensity < 0)
  {
     dustDensity = 0.00;
  }

  micrometer = dustDensity*1000; //measured in microgram per cubic metre
//  arr[i]=micrometer;
 // Serial.print(500);  // To freeze the lower limit
  //Serial.print(" ");
  Serial.println(micrometer);
  Serial.println(voMeasured);
 // Serial.print(" ");
 // Serial.print(50);  // To freeze the upper limit
  //Serial.print(" ");

 /** 
  lcd.setCursor(0,0);
  lcd.print(String(micrometer));
  lcd.setCursor(0,4);
  lcd.print(String("<--PM 2.5"));
**/
 // Serial.println("Raw Signal Value (0-1023):");
  //Serial.println(voMeasured);

  //Serial.println("Voltage:");
  //Serial.println(calcVoltage);

  //Serial.println("Dust Density:");
  //Serial.println(micrometer);
 // if(i==9)
 // {
   // for(i=0;i<10;i++)
 //   {
   //   sum=sum+arr[i];
   // }
 //   Serial.print(sum/10);
 // }
 // i++;
  
  delay(2000);
  
}
