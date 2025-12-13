#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3  , POSITIVE); //lcd is a user-defined name


const int trigPin = 6; // Define the digital pin for the ultrasonic sensor trigger
const int echoPin = 7; // Define the digital pin for the ultrasonic sensor echo
float distance_cm;

void setup() {
  lcd.begin(16, 2); // Initialize the LCD display with 16 columns and 2 rows
  pinMode(trigPin, OUTPUT); // Set the trigger pin as an output
  pinMode(echoPin, INPUT);  // Set the echo pin as an input
  lcd.print("Distance: "); // Print a static label on the LCD
  lcd.setCursor(0,1);
  lcd.print("(cm)");
}

void loop() {
  
  // Generate microsecond pulses to initiate the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the echo pulse on the echo pin
  long duration = pulseIn(echoPin, HIGH);
  
  distance_cm = duration / 58.3;

  // Display the distance on the LCD display
  lcd.setCursor(10, 0); // Set the cursor position to print the distance value
  lcd.print("     "); // Clear the previous distance value
  lcd.setCursor(10, 0); // Set the cursor position again
  lcd.print(distance_cm); // Print the calculated distance in centimeters
  
  delay(500); // Delay for stability

}