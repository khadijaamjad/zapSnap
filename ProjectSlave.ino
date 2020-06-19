#include<SPI.h>
byte x;  //for incoming spi data
const int relayPin1 = 4;      // the number of the relay pin
const int relayPin2 = 5 ;
const int relayPin3 = 6;
//byte xx;
void setup()
{
    pinMode(relayPin1, OUTPUT);
    pinMode(relayPin2,OUTPUT);
    pinMode(relayPin3,OUTPUT);
    pinMode(MISO,OUTPUT);
    SPCR=_BV(SPE);  //turns on slave mode
    SPI.attachInterrupt();
}
ISR(SPI_STC_vect){
  x=SPDR;  //spdr is received from master
  } 
void loop() {
          if(x==1) 
          {
              digitalWrite(relayPin1, HIGH);
          }
           if(x==2)
          {
              digitalWrite(relayPin2, HIGH);
          }
           if (x==3)
          {
              digitalWrite(relayPin3, HIGH);
          }
           if (x==4)
          {
              digitalWrite(relayPin1, LOW);
          }
           if(x==5)
          {
              digitalWrite(relayPin2, LOW);
          }
           if (x==6)
          {
              digitalWrite(relayPin3, LOW);
          }
}
