/*
 * Button incrememts motor speed every time it is pressed
 * Once motor reaches max speed, speed resets
 * Speed is incremented using analogWrite()
 */

int motorPin = 3; //PWM pin, gets analog signals using digital means 
int button = 2; //controls motor speed

boolean lastButton = LOW; //tracks previous state of button
boolean currentButton = LOW;  //tracks current state of button
int motorSpeed = 0;  //PWM analog values [0-255], set default speed

void setup() {
  pinMode(motorPin, OUTPUT); //pin is set as OUTPUT to write to arduino
  pinMode(button, INPUT); //pin is set to INPUT to read from arduino
}

/* 
 * Reads the current state of the button and compares it 
 * to the last state of the button
 */
boolean debounce(boolean last){
   boolean current = digitalRead(button);
   if(last != current)
   {
    delay(5); //CRUCIAL: without pause button will reset too quickly to read
    current = digitalRead(button);
   }
   return current;  //returns debounce value
}

void loop() {
  currentButton = debounce(lastButton);
  if(lastButton == LOW && currentButton == HIGH)
  {  //button has been pressed
    motorSpeed += 51; //any increment value works
  }
  lastButton = currentButton;
  if(motorSpeed > 255)
  {
    motorSpeed = 0; //reset motor speed
  }
  analogWrite(motorPin, motorSpeed);
}
