#include <SoftwareSerial.h>
#include "Timer.h"

//Bluetooth set up
int bluetoothTX = 2; //Tx-0
int bluetoothRX = 3; //Rx-1
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
     
//Create timer object
Timer timer;

//Variables
int motor = 2;
int incomingByte = 0;
int input = 0;

//Time variables
int hours = 0;
int minutes = 0;
int setTime = 0;

void setup() {
  Serial.begin(9600); //this may need to match bluetooth speed
  bluetooth.begin(115200);

  pinMode(motor, OUTPUT);//set motor to output
}

//Read incoming value from bluetooth serial monitor
int incomingCommand(){
  if(bluetooth.available() > 0){
    incomingByte = bluetooth.read() - 48;
    Serial.println(incomingByte);
  }
  return incomingByte;
}


void loop() {
  input = incomingCommand();
  if(input == 0){
    feedNow();
  }else{ 
    setTimer();
    feedNow();
  }
}

//Open dog feeder now
void feedNow(){
  //test delay//
  digitalWrite(motor,HIGH);
  delay(1500);
  digitalWrite(motor, LOW);
}

//Set timer for dog feeder
void setTimer(){
  bluetooth.println("Set hours:");
    if (bluetooth.available()){
    hours = bluetooth.read() * 3600000;
  }
  bluetooth.println("Set minutes:");
  if (bluetooth.available()){
    minutes = bluetooth.read() * 60000;
  }
  setTime = hours + minutes;
  timer.pulse(motor,setTime,LOW);//turn off motor for this long
  //setting time variables back to zero
  hours = 0, minutes = 0, setTime = 0; 
}

