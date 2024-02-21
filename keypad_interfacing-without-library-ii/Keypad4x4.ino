#define segA 7
#define segB 8
#define segC 9
#define segD 10
#define segE 11
#define segF 12
#define segG 13
char pressed;
void setup() {
  for(int i=3;i<=13;i++) 
  { pinMode(i,OUTPUT); } //Setting 7SEG PINS and Keypad row pins as output
  for(int j=0;j<=2;j++)
  { pinMode(j,INPUT_PULLUP); } //Setting keypad col pins as input
  for(int k=3;k<=6;k++)
 { digitalWrite(k,HIGH); }
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
              {
                digitalWrite(segA,LOW);
                digitalWrite(segB,HIGH);
                digitalWrite(segC,HIGH);
                digitalWrite(segD,LOW);
                digitalWrite(segE,LOW);
                digitalWrite(segF,LOW);
                digitalWrite(segG,LOW); 
               }
            else if(i==3 && j==1) //display 2
              {
                digitalWrite(segA,HIGH);
                digitalWrite(segB,HIGH);
                digitalWrite(segC,LOW);
                digitalWrite(segD,HIGH);
                digitalWrite(segE,HIGH);
                digitalWrite(segF,LOW);
                digitalWrite(segG,HIGH);
                }  
           else if(i==3 && j==2) //display 3
              {
                digitalWrite(segA,HIGH);
                digitalWrite(segB,HIGH);
                digitalWrite(segC,HIGH);
                digitalWrite(segD,HIGH);
                digitalWrite(segE,LOW);
                digitalWrite(segF,LOW);
                digitalWrite(segG,HIGH);
              }
           if(i==4 && j==0) //display 4
              {
                 digitalWrite(segA,LOW);
                digitalWrite(segB,HIGH);
                digitalWrite(segC,HIGH);
                digitalWrite(segD,LOW);
                digitalWrite(segE,LOW);
                digitalWrite(segF,HIGH);
                digitalWrite(segG,HIGH);
                 }
            else if(i==4 && j==1) //display 5
              {
                digitalWrite(segA,HIGH);
                digitalWrite(segB,LOW);
                digitalWrite(segC,HIGH);
                digitalWrite(segD,HIGH);
                digitalWrite(segE,LOW);
                digitalWrite(segF,HIGH);
                digitalWrite(segG,HIGH);
             }
            else if(i==4 && j==2) //display 6
              {
                digitalWrite(segA,HIGH);
                digitalWrite(segB,LOW);
                digitalWrite(segC,HIGH);
                digitalWrite(segD,HIGH);
                digitalWrite(segE,HIGH);
                digitalWrite(segF,HIGH);
                digitalWrite(segG,HIGH);
              } 
           if(i==5 && j==0) //display 7
              {
                digitalWrite(segA,HIGH);
                digitalWrite(segB,HIGH);
                digitalWrite(segC,HIGH);
                digitalWrite(segD,LOW);
                digitalWrite(segE,LOW);
                digitalWrite(segF,LOW);
                digitalWrite(segG,LOW);
              }
           else if(i==5 && j==1) //display 8
              {
                digitalWrite(segA,HIGH);
                digitalWrite(segB,HIGH);
                digitalWrite(segC,HIGH);
                digitalWrite(segD,HIGH);
                digitalWrite(segE,HIGH);
                digitalWrite(segF,HIGH);
                digitalWrite(segG,HIGH);
              }
           else if(i==5 && j==2) //display 9
              {
                 digitalWrite(segA,HIGH);
                digitalWrite(segB,HIGH);
                digitalWrite(segC,HIGH);
                digitalWrite(segD,HIGH);
                digitalWrite(segE,LOW);
                digitalWrite(segF,HIGH);
                digitalWrite(segG,HIGH);
              }
           if(i==6 && j==0) //Clear display on * press
              {digitalWrite(segA,LOW);
                digitalWrite(segB,LOW);
                digitalWrite(segC,LOW);
                digitalWrite(segD,LOW);
                digitalWrite(segE,LOW);
                digitalWrite(segF,LOW);
                digitalWrite(segG,LOW);
              } 
           else if(i==6 && j==1)//display 0
              {
               digitalWrite(segA,HIGH);
                digitalWrite(segB,HIGH);
                digitalWrite(segC,HIGH);
                digitalWrite(segD,HIGH);
                digitalWrite(segE,HIGH);
                digitalWrite(segF,HIGH);
                digitalWrite(segG,LOW);
                }
            else if(i==6 && j==2) //Clear display on # press
              {digitalWrite(segA,LOW);
                digitalWrite(segB,LOW);
                digitalWrite(segC,LOW);
                digitalWrite(segD,LOW);
                digitalWrite(segE,LOW);
                digitalWrite(segF,LOW);
                digitalWrite(segG,LOW);
                }
                digitalWrite(i,HIGH);
          }
        }
   }
  }
