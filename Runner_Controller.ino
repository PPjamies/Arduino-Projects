#include <SoftwareSerial.h>
 SoftwareSerial BTserial(0,1);

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

int incomingByte = 0;
int DIRECTION = 0;

void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);

  /turn motors off
  pinMode(fLeft_Forward, OUTPUT);
  pinMode(fLeft_Backward, OUTPUT);
  pinMode(fRight_Forward, OUTPUT);
  pinMode(fRight_Backward, OUTPUT);
  
  pinMode(bLeft_Forward, OUTPUT);
  pinMode(bLeft_Backward, OUTPUT);
  pinMode(bRight_Forward, OUTPUT);
  pinMode(bRight_Backward, OUTPUT); 
}

void loop(){
  DIRECTION = input();
  if(DIRECTION == 3){
    forward();
  }else if (DIRECTION == 4){
    left();
  }else if (DIRECTION == 5){
    right();   
  }else if (DIRECTION == 6){
    backward();
  }
  if(DIRECTION == 0){
    stop();
  }
}


//Read incoming value from user
int input(){
  if(Serial.available() > 0){
    Serial.read() - 48;
    incomingByte = BTserial.read();
    Serial.println(incomingByte);
  }
  return incomingByte;
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
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}
  

