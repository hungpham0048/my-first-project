#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3  , POSITIVE);


const int trigPin = 6; 
const int echoPin = 7; 
float distance_cm;

void setup() {
  lcd.begin(16, 2); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
}
void loop() {
  
  // Generate microsecond pulses to initiate the ultrasonic sensor (on off)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the echo pulse on the echo pin
  long duration = pulseIn(echoPin, HIGH);
  
  distance_cm = duration / 58.0;

  // Display the distance on the LCD display
  lcd.setCursor(3, 0); 
  if (distance_cm > 10) {
     lcd.print("No-one here");
  } else {
     lcd.setCursor(3, 0);
     lcd.print("           ");
     lcd.setCursor(6, 0);
     lcd.print("Hello");
  } 
  delay(1000); // Delay for stability
}