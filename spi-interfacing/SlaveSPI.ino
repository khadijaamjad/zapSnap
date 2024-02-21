#include<SPI.h>
int x;
void setup() {
  // put your setup code here, to run once:
pinMode(MISO,OUTPUT);
pinMode(7,OUTPUT);
SPCR=_BV(SPE);
SPI.attachInterrupt();
}
ISR(SPI_STC_vect){
  x=SPDR;
  }
void loop() {
  // put your main code here, to run repeatedly:
if(x==1){
  digitalWrite(7,HIGH);
  }
  if(x==0)
  {
    digitalWrite(7,LOW);
  }
  }
