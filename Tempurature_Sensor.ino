



// include the LCD library code:
#include <LiquidCrystal.h>


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set up a constant for the temperature sensor
const int TempPin = A0;

void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);

  // set up the temperature pin as an input
  pinMode(TempPin, INPUT);
}

void loop() {
  // read the value on AnalogIn pin 0
  // and store it in a variable
  int sensorVal = analogRead(TempPin);

  // convert the ADC reading to voltage
  float voltage = (sensorVal / 1024.0) * 5.0;

  // set the cursor and
  // convert the voltage to temperature in degrees celsius
  // the sensor changes 10 mV per degree
  // the datasheet says there's a 500 mV offset
  // ((volatge - 500mV) times 100)
  lcd.setCursor(0, 0);
  lcd.print("Degrees C: ");
  float temperatureC = (voltage - .5) * 100;
  lcd.print(temperatureC);

  // set the cursor and 
  // convert celsius to fahrenheit
  lcd.setCursor(0, 1);
  lcd.print("Degrees F: ");
  float temperatureF = (temperatureC * 1.8) + 32;
  lcd.println(temperatureF);
  delay(1500);
}
