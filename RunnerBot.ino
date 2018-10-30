#include <SoftwareSerial.h>
SoftwareSerial bluetooth(0,1);

//front wheels
const int fLeft_Forward = 2;
const int fLeft_Backward = 3;
const int fRight_Forward = 4;
const int fRight_Backward = 5;

//back wheels
const int bLeft_Forward = 6;
const int bLeft_Backward = 7;
const int bRight_Forward = 8;
const int bRight_Backward = 9;

int incByte = 0;
int DIRECTION = 0;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  
//Set motors to output
  pinMode(fLeft_Forward, OUTPUT);
  pinMode(fLeft_Backward, OUTPUT);
  pinMode(fRight_Forward, OUTPUT);
  pinMode(fRight_Backward, OUTPUT);
  
  pinMode(bLeft_Forward, OUTPUT);
  pinMode(bLeft_Backward, OUTPUT);
  pinMode(bRight_Forward, OUTPUT);
  pinMode(bRight_Backward, OUTPUT); 

//Turn motors off
  digitalWrite(fLeft_Forward, LOW);
  digitalWrite(fLeft_Backward, LOW);
  digitalWrite(fRight_Forward, LOW);
  digitalWrite(fRight_Backward, LOW);

  digitalWrite(bLeft_Forward, LOW);
  digitalWrite(bLeft_Backward, LOW);
  digitalWrite(bRight_Forward, LOW);
  digitalWrite(bRight_Backward, LOW);   
}

void loop(){
  DIRECTION = input();
  if(DIRECTION == 51){
    forward();
  }else if (DIRECTION == 52){
    left();
  }else if (DIRECTION == 53){
    right();   
  }else if (DIRECTION == 54){
    backward();
  }
  if(DIRECTION == 48){
    stop();
  }
}

//Read incoming value from user
int input(){
  if(bluetooth.available() > 0){
    incByte = bluetooth.read();
  }
  return incByte;
}

void forward() {
  // run forward
  digitalWrite(fLeft_Forward, HIGH);
  digitalWrite(fLeft_Backward, LOW);
  digitalWrite(fRight_Forward, HIGH);
  digitalWrite(fRight_Backward, LOW);

  digitalWrite(bLeft_Forward, HIGH);
  digitalWrite(bLeft_Backward, LOW);
  digitalWrite(bRight_Forward, HIGH);
  digitalWrite(bRight_Backward, LOW);
}

void backward(){
  //run backward
  digitalWrite(fLeft_Forward, LOW);
  digitalWrite(fLeft_Backward, HIGH);
  digitalWrite(fRight_Forward, LOW);
  digitalWrite(fRight_Backward, HIGH);

  digitalWrite(bLeft_Forward, LOW);
  digitalWrite(bLeft_Backward, HIGH);
  digitalWrite(bRight_Forward, LOW);
  digitalWrite(bRight_Backward, HIGH);
}

void right(){
  //turn right
  digitalWrite(fLeft_Forward, HIGH);
  digitalWrite(fLeft_Backward, LOW);
  digitalWrite(fRight_Forward, LOW);
  digitalWrite(fRight_Backward, HIGH);

  digitalWrite(bLeft_Forward, HIGH);
  digitalWrite(bLeft_Backward, LOW);
  digitalWrite(bRight_Forward, LOW);
  digitalWrite(bRight_Backward, HIGH);
}

void left(){
  //turn left
  digitalWrite(fLeft_Forward, LOW);
  digitalWrite(fLeft_Backward, HIGH);
  digitalWrite(fRight_Forward, HIGH);
  digitalWrite(fRight_Backward, LOW);

  digitalWrite(bLeft_Forward, LOW);
  digitalWrite(bLeft_Backward, HIGH);
  digitalWrite(bRight_Forward, HIGH);
  digitalWrite(bRight_Backward, LOW);
}

void stop(){
  //Execute
  digitalWrite(fLeft_Forward, LOW);
  digitalWrite(fLeft_Backward, LOW);
  digitalWrite(fRight_Forward, LOW);
  digitalWrite(fRight_Backward, LOW);

  digitalWrite(bLeft_Forward, LOW);
  digitalWrite(bLeft_Backward, LOW);
  digitalWrite(bRight_Forward, LOW);
  digitalWrite(bRight_Backward, LOW);
}
