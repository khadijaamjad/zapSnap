#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
 lcd.begin(16,2);
 pinMode(A0,INPUT); 
}

void loop() {
  int temp=analogRead(A0);
  float temp2=temp*0.48828125;
  lcd.setCursor(0,0);
  lcd.print(temp2);
  delay(1000);
  lcd.clear();
  delay(1000);
}
