#include <SoftwareSerial.h>
#include "Timer.h"

////Bluetooth set up
//int bluetoothTX = 2; //Tx-0
//int bluetoothRX = 3; //Rx-1
//SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
     
//Create timer object
Timer timer;

//Variables
int blue = 2;
int incomingByte = 0;
int input = 0;

//Time variables
int hours = 0;
int minutes = 0;
int setTime = 0;

void setup() {
  Serial.begin(115200); //this may need to match bluetooth speed
// bluetooth.begin(115200);

  pinMode(blue, OUTPUT);//set motor to output
}

//Read incoming value from bluetooth serial monitor
int incomingCommand(){
  if(Serial.available() > 0){
    incomingByte = Serial.read() - 48;
    Serial.println(incomingByte);
  }
  return incomingByte;
}


void loop() {
  input = incomingCommand();
  if(input == 1){
    feedNow();
  }else if( input == 2){ 
    setTimer();
    feedNow();
  }
}

//Open dog feeder now
void feedNow(){
  //test delay//
  //digitalWrite(blue,HIGH);
  //delay(1500);
  digitalWrite(blue, LOW);
}

//Set timer for dog feeder
void setTimer(){
  Serial.println("Set hours:");
    if (Serial.available()){
    hours = Serial.read() * 3600000;
  }
  Serial.println("Set minutes:");
  if (Serial.available()){
    minutes = Serial.read() * 60000;
  }
  setTime = hours + minutes;
  timer.pulse(blue,setTime,LOW);//turn off motor for this long
  //setting time variables back to zero
  hours = 0, minutes = 0, setTime = 0; 
}

