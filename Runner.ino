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

void setup() {
  // put your setup code here, to run once:
  pinMode(fLeft_Forward, OUTPUT);
  pinMode(fLeft_Backward, OUTPUT);
  pinMode(fRight_Forward, OUTPUT);
  pinMode(fRight_Backward, OUTPUT);
  
  pinMode(bLeft_Forward, OUTPUT);
  pinMode(bLeft_Backward, OUTPUT);
  pinMode(bRight_Forward, OUTPUT);
  pinMode(bRight_Backward, OUTPUT);

  //set up for user input
  Serial.begin(9600);
}

void loop() {
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

void loop(){
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


void loop(){
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

void loop(){
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
  
