#include <SoftwareSerial.h>
 SoftwareSerial BTserial(0,1);
 
 int BLUE = 2;
 int incomingByte = 0;
 int COLOR;

void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);

  pinMode(BLUE, OUTPUT);
  digitalWrite(BLUE, LOW);
 }

void loop() {
  COLOR = input();
}

//Read incoming value from user
int input(){
  if(Serial.available()){
    incomingByte = Serial.read() - 48;
    Serial.println(incomingByte);
  }
   if(BTserial.available()){
    incomingByte = BTserial.read();
  }
  return incomingByte;
}

//turns off any light previously on
void turnOffLight(int prev){
  digitalWrite(prev, LOW);
}

//turns on light commanded by user
void turnOnLight(int COLOR){
  digitalWrite(COLOR, HIGH);
}


