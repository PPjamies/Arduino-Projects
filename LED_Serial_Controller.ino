int BLUE = 2;
int GREEN = 3;
int YELLOW = 4;
int RED = 5;

int incomingByte = 0;
int COLOR = 0;
int prevCOLOR = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  
  //turn lights off
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
  
}

void loop(){
  //saves users command to colored
  COLOR = input();
  if( prevCOLOR != COLOR){
      turnOnLight(COLOR);
      turnOffLight(prevCOLOR);
      prevCOLOR = COLOR;
  }
  if(COLOR == 0){
    end();
  }
}


//Read incoming value from user
int input(){
  if(Serial.available() > 0){
    incomingByte = Serial.read() - 48;
    Serial.println(incomingByte);
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

//Execute
void end(){
    //turn lights off
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}

