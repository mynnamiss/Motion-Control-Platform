/*programmer: Pedro Medellin
  Organization: California State University Fullerton
  Project: Base platform for PacMin interactive plane model.
  Version: 3 .1- This version has states for different states of the plane.
  Pitch in both directions and one roll state, as provided.*/

volatile char state;
//steps= 25600
//motor declarations
//motor1
int PUL = 3; //define Pulse pin
int DIR = 4; //define Direction pin
//int ENA=7; //define Enable Pin
/////////
//motor2
int PUL2 = 6; //define Pulse pin
int DIR2 = 7; //define Direction pin
//int ENA2=10; //define Enable Pin
/////////
//motor3
int PUL3 = 9; //define Pulse pin
int DIR3 = 10; //define Direction pin
//int ENA3=24; //define Enable Pin
/////////
//motor4
int PUL4 = 12; //define Pulse pin
int DIR4 = 13; //define Direction pin
//int ENA4=27; //define Enable Pin
/////////
//motor5
int PUL5 = 22; //define Pulse pin
int DIR5 = 23; //define Direction pin
//int ENA5=30; //define Enable Pin
/////////
//motor6
int PUL6 = 26; //define Pulse pin
int DIR6 = 27; //define Direction pin
//int ENA6=33; //define Enable Pin
//////end of motor declaration


void setup() {
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (PUL2, OUTPUT);
  pinMode (DIR2, OUTPUT);
  pinMode (PUL3, OUTPUT);
  pinMode (DIR3, OUTPUT);
  pinMode (PUL4, OUTPUT);
  pinMode (DIR4, OUTPUT);
  pinMode (PUL5, OUTPUT);
  pinMode (DIR5, OUTPUT);
  pinMode (PUL6, OUTPUT);
  pinMode (DIR6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  state = Serial.read();
//  while (Serial.available()) {
    
    if (state == '1') {
      Serial.println("Pitching Up:");
      pitch_U();
      delay(1000);
      neg_pitch_U();
      delay(1000);
    }
    if (state == '2') {
      Serial.println("Pitching Down:");
      pitch_D();
      delay(1000);
      neg_pitch_D();
      delay(1000);
    }
    if (state == '3') {
      Serial.println("Rolling:");
      roll();
      delay(1000);
      neg_roll();
      delay(1000);
    }
    

//  }
}

//There is something wrong with a couple of these states. The motors stop running despite the fact that they are supposed to be running.
void pitch_D() {
    for (int i = 0; i < 2961*47;) {
    while(i<=2207*47){
      digitalWrite(DIR, HIGH); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
      digitalWrite(DIR2, LOW); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);
      digitalWrite(DIR3, HIGH); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      digitalWrite(DIR4, LOW); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      digitalWrite(DIR5, HIGH); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      digitalWrite(DIR6, LOW); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=2347*47&&i>=2207*47){
      digitalWrite(DIR2, LOW); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);
      digitalWrite(DIR3, HIGH); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      digitalWrite(DIR4, LOW); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      digitalWrite(DIR5, HIGH); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=2961*47&&i>=2347*47){
      digitalWrite(DIR3, HIGH); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      digitalWrite(DIR4, LOW); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);

      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }
    }
}

void neg_pitch_D() {
  ///////////////////////////////////////////////////
  //reverse pitch down
    for (int i = 0; i < 2961*47;) {
    while(i<=2207*47){
      digitalWrite(DIR, LOW); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
    
      digitalWrite(DIR2, HIGH); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);
      
      digitalWrite(DIR3, LOW); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      
      digitalWrite(DIR4, HIGH); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, LOW); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      
      digitalWrite(DIR6, HIGH); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
      
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=2347*47&&i>=2207*47){
      digitalWrite(DIR2, HIGH); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);

      digitalWrite(DIR3, LOW); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);

      digitalWrite(DIR4, HIGH); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);

      digitalWrite(DIR5, LOW); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=2961*47&&i>=2347*47){
      digitalWrite(DIR3, LOW); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      
      digitalWrite(DIR4, HIGH); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);

      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }
    }
}
///////////////////////////////////////////////////////////////////////////////
//
void pitch_U() {
  //pitch up
      for (int i = 0; i < 2928*47;) {
    while(i<=1695*47){
      digitalWrite(DIR, LOW); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
      
      digitalWrite(DIR2, HIGH); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);
      
      digitalWrite(DIR3, LOW); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      
      digitalWrite(DIR4, HIGH); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, LOW); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      
      digitalWrite(DIR6, HIGH); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=1889*47&&i>=1695*47){
      digitalWrite(DIR2, HIGH); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);
      
      digitalWrite(DIR3, LOW); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      
      digitalWrite(DIR4, HIGH); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, LOW); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=2928*47&&i>=1889*47){
      digitalWrite(DIR3, LOW); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
    
      digitalWrite(DIR4, HIGH); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);

      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }
    }
}
////reverse pitchup
void neg_pitch_U() {
        for (int i = 0; i < 2928*47;) {
    while(i<=1695*47){
      digitalWrite(DIR, HIGH); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
      
      digitalWrite(DIR2, LOW); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);
      
      digitalWrite(DIR3, HIGH); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      
      digitalWrite(DIR4, LOW); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, HIGH); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      
      digitalWrite(DIR6, LOW); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=1889*47&&i>=1695*47){
      digitalWrite(DIR2, LOW); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);
      
      digitalWrite(DIR3, HIGH); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      
      digitalWrite(DIR4, LOW); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, HIGH); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=2928*47&&i>=1889*47){
      digitalWrite(DIR3, HIGH); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      digitalWrite(DIR4, HIGH); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);

      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }
    }
}///////////////////////////////////////////////////////////////////

////ROLL
void roll() {
for (int i = 0; i < 1450*47;) {
    while(i<=225*47){
      digitalWrite(DIR, HIGH); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
      
      digitalWrite(DIR2, HIGH); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);
      
      digitalWrite(DIR3, LOW); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      
      digitalWrite(DIR4, LOW); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, HIGH); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      
      digitalWrite(DIR6, LOW); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=440*47&&i>=225*47){
      digitalWrite(DIR2, HIGH); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);
      
      digitalWrite(DIR3, LOW); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      
      digitalWrite(DIR4, LOW); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, HIGH); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      
      digitalWrite(DIR6, LOW); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=637*47&&i>=440*47){
      digitalWrite(DIR3, LOW); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      
      digitalWrite(DIR4, LOW); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, HIGH); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      
      digitalWrite(DIR6, LOW); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=809*47&&i>=637*47){
      digitalWrite(DIR4, LOW); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, HIGH); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      
      digitalWrite(DIR6, LOW); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=1058*47&&i>=809*47){

      digitalWrite(DIR4, LOW); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, HIGH); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);

      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=1450*47&&i>=1058*47){
       digitalWrite(DIR5, HIGH); //dir High = backward motor1
       digitalWrite(PUL5, HIGH);

      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }
    }
}
////negative ROLL
void neg_roll() {
for (int i = 0; i < 1450*47;) {
    while(i<=225*47){
      digitalWrite(DIR, LOW); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
      
      digitalWrite(DIR2, LOW); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);
      
      digitalWrite(DIR3, HIGH); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      
      digitalWrite(DIR4, HIGH); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, LOW); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      
      digitalWrite(DIR6, HIGH); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=440*47&&i>=225*47){
      digitalWrite(DIR2, LOW); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);
      
      digitalWrite(DIR3, HIGH); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      
      digitalWrite(DIR4, HIGH); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, LOW); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      
      digitalWrite(DIR6, HIGH); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=637*47&&i>=440*47){
      digitalWrite(DIR3, HIGH); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);
      
      digitalWrite(DIR4, HIGH); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, LOW); //dir LOW = backward motor1
      digitalWrite(PUL5, HIGH);
      
      digitalWrite(DIR6, HIGH); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=809*47&&i>=637*47){
      digitalWrite(DIR4, HIGH); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, LOW); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);
      
      digitalWrite(DIR6, HIGH); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=1058*47&&i>=809*47){

      digitalWrite(DIR4, HIGH); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);
      
      digitalWrite(DIR5, LOW); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);

      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }

      while(i<=1450*47&&i>=1058*47){
       digitalWrite(DIR5, LOW); //dir High = backward motor1
       digitalWrite(PUL5, HIGH);

      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }
    }
}

void freeMove(){
for (int i = 0; i < 2961*47;) {
    while(i<=2207*47){
      digitalWrite(DIR, HIGH); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
      
      digitalWrite(DIR2, LOW); //dir High = backward motor1
      digitalWrite(PUL2, HIGH);

      digitalWrite(DIR3, HIGH); //dir High = backward motor1
      digitalWrite(PUL3, HIGH);

      digitalWrite(DIR4, LOW); //dir High = backward motor1
      digitalWrite(PUL4, HIGH);

      digitalWrite(DIR5, HIGH); //dir High = backward motor1
      digitalWrite(PUL5, HIGH);

      digitalWrite(DIR6, LOW); //dir High = backward motor1
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
      digitalWrite(PUL2, LOW);
      digitalWrite(PUL3, LOW);
      digitalWrite(PUL4, LOW);
      digitalWrite(PUL5, LOW);
      digitalWrite(PUL6, LOW);
      i++;
      }}
      }



