//import libraries
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

//set LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2); 

//Set up Tempurature Pin
const int tempPin = A0;


void setup() {
 lcd.init();
 lcd.backlight();
 pinMode(tempPin, INPUT); 
}

void loop() {
  int tempSensorValue = analogRead(tempPin);

 //Conversion: voltage --> temperature C and temperature F
  float voltage = (tempSensorValue / 1024.0) * 5.0; 
  float tempC = (voltage - .5) * 100;
  float tempF = (tempC * 1.8) + 32;
  
  lcd.setCursor(16,0);
  lcd.print("Degrees C: ");
  lcd.print(tempC);
  lcd.setCursor(16,1);
  lcd.print("Degrees F: ");
  lcd.print(tempF);
  delay(300);  
}
