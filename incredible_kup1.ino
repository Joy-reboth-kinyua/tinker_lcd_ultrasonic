#include <Adafruit_LiquidCrystal.h>

#define trigPin 5  //Trig connected to pin5

#define echoPin 7   //Echo connected to pin 7

//int // long / word // char // float //int long

long distanceCm, distanceInch; //long(64 bit) takes more no of numbers than int(32 bit) 

long duration;



Adafruit_LiquidCrystal lcd(0); //by default the address is selected

void setup()//the code will run once
{
  pinMode(trigPin, OUTPUT);
  
  pinMode(echoPin, INPUT);
  
  lcd.begin(16, 2); //columns and rows
  
  lcd.setBacklight(1);  //the led's have been set high
  
  lcd.print("Distance measuring");
  
  delay(2000);
  
  
  
}

void loop()
{
  //lcd.setCursor(0,1); //setting the position of the cursor
  
  digitalWrite(trigPin, LOW);
  
  delayMicroseconds(2); // Wait for 2000 millisecond(s)
  
  digitalWrite(trigPin, HIGH);
  
  delayMicroseconds(10); // Wait for 2000 millisecond(s)
  
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); //measuring the time
  
  distanceCm = duration * 0.034/2;
  
  distanceInch = duration * 0.0133/2;
  
  lcd.setCursor(0,0);  //where the text starts to be printed on
  
  lcd.print("Distance; "); //prints string distance on the lcd
  
  lcd.print(distanceCm);
  
  lcd.print(" cm");
  
  delay(10);
  
  lcd.setCursor(0,10);
  
  lcd.print("Distance: ");
  
  lcd.print(distanceInch);
  
  lcd.print(" inch");
  
  delay(20);
                
                  
}