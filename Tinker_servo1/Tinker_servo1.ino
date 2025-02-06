#include <Servo.h>

#include <Adafruit_LiquidCrystal.h>

int pos = 0;

Servo servo_9; //the signal pin of the servo

Adafruit_LiquidCrystal lcd(0);


void setup()
{
  
  servo_9.attach(9);
  
  lcd.begin(16, 2);  //initialized 16 columns of the lcd and 2 rows

  
  lcd.setBacklight(1);  //leds of the lcd are high

  
  lcd.print("MOTOR STARTING"); //welcome message will run once

  
  delay(2000);  //delay by two seconds

  
  
}

void loop()
{
//sweep the servo from 0 to 180 degrees in steps of 5degrees
  
  for (pos =0; pos <= 180; pos += 5){
    
    //the servo0 to go to position a pos
    
    servo_9.write(pos);
    
    delay(15);
    
    lcd.print(pos);
    
    lcd.print(" DEGREES ");
    
    delay(500);

    lcd.clear();
  
 }
  
  for (pos = 180; pos >= 0; pos -= 5){
    
    servo_9.write(pos);
    
    delay(15);
    
   
    lcd.print(" DEGREES ");
    
    lcd.print(pos);
    
    delay(500); // Wait for 2 seconds.

    lcd.clear();
    
    //wait for 15 milliseconds
    
  }
  
  
}