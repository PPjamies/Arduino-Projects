/*
 * Button incrememts motor speed every time it is pressed
 * Once motor reaches max speed, speed resets
 * Speed is read using analogRead() and outputted to serial monitor
 * Speed is incremented using analogWrite()
 */

int potPin = A0;  //set potentiometer pin to A0
int tranPin = 3;  //set transistor pin to 3 
int sensorValue;  //reads analog value from potentiometer
int outputValue;  //sen

void setup () {
  Serial.begin(9600);
  pinMode(tranPin,OUTPUT);  //Set to OUTPUT to write to arduino
}

void loop () {
  sensorValue = analogRead(potPin); //reads analog values from potentiometer
  Serial.println("Sensor Value: " + sensorValue); 
  outputValue = map(sensorValue, 0, 1023, 0, 255);  // Map an analog value to 8 bits (0 to 255)
  Serial.println("Output Value: " + outputValue);
  analogWrite(tranPin,outputValue); //writes to arduino to change motor speed
}
