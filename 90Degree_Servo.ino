int servopin = 9;   //use digital pin 4
int pulse = ;   


void setup() {
  // put your setup code here, to run once:
   //pinMode() specifies pin to be either input or output
  pinMode(servopin, OUTPUT);
  Serial.begin(9600);        //set data rates in bits-per-second
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (servopin, HIGH);
  delayMicroseconds(pulse);
  digitalWrite (servopin, LOW);
  delayMicroseconds(pulse);
 
 
                                
}
