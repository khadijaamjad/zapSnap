#include<LiquidCrystal.h>
#define segA 7
#define segB 8
#define segC 9
#define segD 10
#define segE 11
#define segF 12
#define segG 13
LiquidCrystal LCD(8,7,10,11,12,13); //(RS,En,D1,D2,D3,D4) 
char pressed;
void setup() {      
  for(int i=3;i<=13;i++) 
  { pinMode(i,OUTPUT); } //Setting Keypad row pins and LCD pins as output
  for(int j=0;j<=2;j++)
  { pinMode(j,INPUT_PULLUP); } //Setting keypad col pins as input
  for(int k=3;k<=6;k++)
 { digitalWrite(k,HIGH); } //Setting row pins HIGH
  LCD.begin(16,2);     
  LCD.clear();      
  LCD.setCursor(0,0);
  }

void loop()
{
 for(int i=3;i<=6;i++) //rows A,B,C,D
        {
         digitalWrite(i,LOW);   
         for(int j=0;j<=2;j++) //columns 1,2,3
         {
            if(digitalRead(j)==LOW)
              {              
            if(i==3 && j==0) //display 1
              {     LCD.clear(); LCD.print("1");      }
            else if(i==3 && j==1) //display 2
              {     LCD.clear(); LCD.print("2");      }  
           else if(i==3 && j==2) //display 3
              {    LCD.clear();  LCD.print("3");      }
           if(i==4 && j==0) //display 4
              {    LCD.clear(); LCD.print("4");       }
            else if(i==4 && j==1) //display 5
              {    LCD.clear(); LCD.print("5");       }
            else if(i==4 && j==2) //display 6
              {    LCD.clear(); LCD.print("6");       } 
           if(i==5 && j==0) //display 7
              {    LCD.clear(); LCD.print("7");       }
           else if(i==5 && j==1) //display 8
              {    LCD.clear(); LCD.print("8");       }
           else if(i==5 && j==2) //display 9
              {    LCD.clear(); LCD.print("9");       }
           if(i==6 && j==0) //display *
              {    LCD.clear(); LCD.print("*");       } 
           else if(i==6 && j==1)//display 0
              {    LCD.clear(); LCD.print("0");       }
            else if(i==6 && j==2) //display #
              {   LCD.clear();  LCD.print("#");       }
                digitalWrite(i,HIGH);
         }
      }
   }
}
