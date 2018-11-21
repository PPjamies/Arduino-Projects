#include <SoftwareSerial.h>

//Bluetooth set up
int bluetoothTX = 0; //Tx-0
int bluetoothRX = 1; //Rx-1
SoftwareSerial bluetooth(bluetoothTX, bluetoothRX);

//Variables
int MOTOR_1 = 2;
int MOTOR_2 = 3;
int incByte = 0;

void setup() {
  Serial.begin(9600); //this may need to match bluetooth speed
  bluetooth.begin(115200);

  pinMode(MOTOR_1, OUTPUT);//set motor_1 to output
  pinMode(MOTOR_2, OUTPUT);//set motor_2 to output

}

void loop() {
 if(Serial.available() > 0){
    incByte = Serial.read() - 48;
    Serial.println(incByte);
    if(incByte == 2){
      feedNow();
    }
  }
}

//Open dog feeder now
void feedNow(){
  digitalWrite(MOTOR_1,HIGH);
  digitalWrite(MOTOR_2,HIGH);
  delay(1000);
  digitalWrite(MOTOR_1,LOW);
  digitalWrite(MOTOR_2,LOW);
}
