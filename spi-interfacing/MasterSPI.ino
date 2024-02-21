#include<SPI.h>
void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT);
pinMode(8,INPUT); //7 AHSAN
digitalWrite(SS,HIGH);
SPI.begin();
SPI.setClockDivider(SPI_CLOCK_DIV2);
}

void loop() {
  // put your main code here, to run repeatedly:
int pressed=digitalRead(8);
digitalWrite(SS,LOW);
SPI.transfer(pressed);
digitalWrite(SS,HIGH);

}
