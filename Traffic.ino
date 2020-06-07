#define r 0
#define y 1
#define g 2
int red=3,yellow=4,green=5;
int sen=7, senState;
static unsigned long ts;
int state=r;
bool flag=HIGH;
void setup() {
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(sen,INPUT);
}

void loop() {
  senState=digitalRead(sen);
  switch(senState)
  {
    case HIGH:
      switch(state)
      {
        case r:
          digitalWrite(red,HIGH);
          digitalWrite(yellow,LOW);
          digitalWrite(green,LOW);
          state=g;
        break;
        case y:
          digitalWrite(red,LOW);
          digitalWrite(yellow,HIGH);
          digitalWrite(green,LOW);
          state=g;
        break;
        case g:
          digitalWrite(red,LOW);
          digitalWrite(yellow,LOW);
          digitalWrite(green,HIGH);
          state=g;
        break;
        }
    break;
    case LOW:
      switch(state)
      {
        case r:
          digitalWrite(red,HIGH);
          digitalWrite(yellow,LOW);
          digitalWrite(green,LOW);
          state=r;
        break;
        case y:
          if(flag)
          {
            ts=millis();
           }
          flag=LOW;
          digitalWrite(red,LOW);
          digitalWrite(yellow,HIGH);
          digitalWrite(green,LOW);
          if(millis()>ts+2000)
          {
            state=r;
            flag=HIGH;
          }
        break;
        case g:
          digitalWrite(red,LOW);
          digitalWrite(yellow,LOW);
          digitalWrite(green,HIGH);
          state= y;
        break;
        }
    break;
    }
}
