#define TRIG A1
#define ECHO A0

#define RED_LED 2
#define BLUE_LED 3
#define YELLOW_LED 4
#define GREEN_LED 5

#define BUZZER 12

long sure;
long mesafe;

void setup(){
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  pinMode(TRIG, OUTPUT);

  pinMode(BUZZER, OUTPUT);
}

void loop(){
  digitalWrite(TRIG, 1);
  delayMicroseconds(1000);
  digitalWrite(TRIG, 0);

  sure = pulseIn(ECHO, 1);
  mesafe = (sure/2)/29.1;

  if(mesafe <= 5){
    digitalWrite(RED_LED, 1);
    digitalWrite(BLUE_LED, 0);
    digitalWrite(YELLOW_LED, 0);
    digitalWrite(GREEN_LED, 0);
    digitalWrite(BUZZER, 1);
  }
  else if(mesafe <= 15){
    digitalWrite(RED_LED, 0);
    digitalWrite(BLUE_LED, 1);
    digitalWrite(YELLOW_LED, 0);
    digitalWrite(GREEN_LED, 0);
    digitalWrite(BUZZER, 1);
    delay(100);
    digitalWrite(BLUE_LED, 0);
    digitalWrite(BUZZER, 0);
    delay(100);
  }
  else if(mesafe <= 25){
    digitalWrite(RED_LED, 0);
    digitalWrite(BLUE_LED, 0);
    digitalWrite(YELLOW_LED, 1);
    digitalWrite(GREEN_LED, 0);
    digitalWrite(BUZZER, 1);
    delay(150);
    digitalWrite(YELLOW_LED, 0);
    digitalWrite(BUZZER, 0);
    delay(150);
  }
  else {
    digitalWrite(RED_LED, 0);
    digitalWrite(BLUE_LED, 0);
    digitalWrite(YELLOW_LED, 0);
    digitalWrite(GREEN_LED, 1);
    digitalWrite(BUZZER, 0);
    delay(100);
  }
}
