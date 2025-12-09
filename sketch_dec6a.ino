#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);
int trig = 9;
int echo = 10;
long duration;
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Distance:");
}

void loop() {

  
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  
  duration = pulseIn(echo, HIGH);
//distance caculation
  distance = duration / 58.3;
//lcd setup
  lcd.setCursor(1, 0); 
  if (distance > 20) {
     lcd.print("No object here");
  } else {
     lcd.setCursor(1, 0);
     lcd.print("               ");
     lcd.setCursor(6, 0);
     lcd.print("Hello");
  } 
  delay(1000); // Delay for stability
}
