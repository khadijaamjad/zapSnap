#include <LiquidCrystal.h> 
#include<SPI.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#define PIR_sensor 17 
#define m11 0
#define m12 1
int visitors;
const int buttonPin1 = 14;    
const int buttonPin2 = 15;
const int buttonPin3 = 16;
int buttonState1 = 0;     
int buttonState2 = 0;
int buttonState3 = 0;
byte data;
void setup()
{
    lcd.begin(16, 2);
    lcd.clear ();
    pinMode(m11, OUTPUT);
    pinMode(m12, OUTPUT);
    pinMode(PIR_sensor, INPUT);
    delay(500);
    visitors=0;
    pinMode(buttonPin1, INPUT);
    pinMode(buttonPin2, INPUT);
    pinMode(buttonPin3, INPUT);
    digitalWrite(SS,HIGH);
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV2);
}
void loop()
{
      buttonState1 =digitalRead(buttonPin1);
      buttonState2=digitalRead(buttonPin2);
      buttonState3=digitalRead(buttonPin3);
      if (buttonState1 == LOW) 
          {    
              digitalWrite(SS,LOW);
              data=1;
              SPI.transfer(data);
              digitalWrite(SS,HIGH);
          }    
       if (buttonState2 == LOW) 
          {    
              digitalWrite(SS,LOW);
               data=2;
              SPI.transfer(data);
              digitalWrite(SS,HIGH);
           }
       if (buttonState3 == LOW) 
          {    
              digitalWrite(SS,LOW);
               data=3;
              SPI.transfer(data);
              digitalWrite(SS,HIGH);
          }
      if (!buttonState1 == LOW) 
          {    
              digitalWrite(SS,LOW);
               data=4;
              SPI.transfer(data);
              digitalWrite(SS,HIGH);
          }    
       if (!buttonState2 == LOW) 
          {    
              digitalWrite(SS,LOW);
               data=5;
              SPI.transfer(data);
              digitalWrite(SS,HIGH);
           }
       if (!buttonState3 == LOW) 
          {    
              digitalWrite(SS,LOW);
              data=6;
              SPI.transfer(data);
              digitalWrite(SS,HIGH);
          }
      if(digitalRead(PIR_sensor))
      {
            visitors++;
            lcd.setCursor(0,0);
            lcd.print("Movement Detected");
            lcd.setCursor(0, 1);
            lcd.print("    Gate Opened    ");
            digitalWrite(m11, HIGH);         // gate opening
            digitalWrite(m12, LOW);
            delay(500);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("  Visitor Count  ");
            lcd.setCursor(0, 1);
            lcd.print(visitors);
            delay(800);
            digitalWrite(m11, LOW);          // gate stop for a while
            digitalWrite(m12, LOW);
            delay(800);
            lcd.clear();
            lcd.setCursor(0,1);
            lcd.print("   Gate Closed    ");
            digitalWrite(m11, LOW);           // gate closing
            digitalWrite(m12, HIGH);
            delay(800);
            digitalWrite(m11, LOW);           // gate closed
            digitalWrite(m12, LOW);
            delay(800);
      }
      else
      {
          lcd.setCursor(0,0);
          lcd.print("   No Movement   ");
          lcd.setCursor(0,1);
          lcd.print("   Gate Closed   ");
          delay(500);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(" Visitor Count ");
          lcd.setCursor(0, 1);
          lcd.print(visitors);
          delay(800);
          digitalWrite(m11, LOW);
          digitalWrite(m12, LOW);
      }
}
