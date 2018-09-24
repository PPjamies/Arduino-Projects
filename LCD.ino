
// Library
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

String line = "Sup HotDog!";
 
void setup()
{
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight
}

void loop() 
{
  lcd.setCursor(16,0); // set the cursor to column 0, line 0
  lcd.autoscroll();
  for (int i = 0; i <line.length(); i++){
    lcd.print(line.charAt(i));
    delay(700);
  }
}

