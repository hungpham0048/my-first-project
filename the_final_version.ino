#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
 
LiquidCrystal_I2C lcd1(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
LiquidCrystal_I2C lcd2(0x26, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
const int trigPin = 6;
const int echoPin = 7;
float distance_cm;
 
void setup() {
  lcd1.begin(16, 2);
  lcd2.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  lcd1.setCursor(0, 0);
  lcd1.print("Distance: ");
  lcd1.setCursor(0, 1);
  lcd1.print("(cm)");
}
 
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  long duration = pulseIn(echoPin, HIGH);
 
  distance_cm = duration / 58.0;
 
  lcd1.setCursor(10, 0);
  lcd1.print("     ");
  lcd1.setCursor(10, 0);
  lcd1.print(distance_cm);
lcd2.setCursor(3, 0);
  if (distance_cm > 20) {
     lcd2.print("No-one here");
  } else {
     lcd2.setCursor(3, 0);
     lcd2.print("           ");
     lcd2.setCursor(6, 0);
     lcd2.print("Hello");
  }
  delay(1000);
}