#include <SoftwareSerial.h>

////Bluetooth set up
int bluetoothTX = 1; //Tx-0
int bluetoothRX = 0; //Rx-1
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

//Variables
int blue = 2;
int incomingByte = 0;
int input = 0;

void setup() {
  Serial.begin(9600); //this may need to match bluetooth speed
  bluetooth.begin(9600);
  pinMode(blue, OUTPUT);//set motor to output
}

//Read incoming value from bluetooth
int incomingCommand(){
  if(bluetooth.available() > 0){
    incomingByte = bluetooth.read() - 48;
    Serial.println(incomingByte);
  }
  return incomingByte;
}

void loop() {
  input = incomingCommand();
  if(input == 1){
    feedNow();
  }
}

//Open dog feeder now
void feedNow(){
  digitalWrite(blue,HIGH);
  delay(1500);
  digitalWrite(blue, LOW);
}
