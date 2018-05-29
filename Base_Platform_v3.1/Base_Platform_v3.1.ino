/*programmer: Pedro Medellin
  Organization: California State University Fullerton
  Project: Base platform for PacMin interactive plane model.
  Version: 2 - This version is a result of the driver changes on March 8th*/

volatile char state;
//steps= 25600
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


void pitch_D() {
  for (int a = 0; a < 1; a++) {
    for (int i = 0; i < 2207; i++) { //Forward i steps
      digitalWrite(DIR, HIGH); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);
    }
    for (int j = 0; j < 2347; j++) {
      digitalWrite(DIR2, LOW); //dir low = forward motor2
      digitalWrite(PUL2, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL2, LOW);
    }

    for (int k = 0; k < 2961; k++) {
      digitalWrite(DIR3, HIGH); //dir high = backward motor3
      digitalWrite(PUL3, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL3, LOW);
    }

    for (int l = 0; l < 2961; l++) {
      digitalWrite(DIR4, LOW); //dir low = forward motor4
      digitalWrite(PUL4, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL4, LOW);
    }

    for (int m = 0; m < 2347; m++) {
      digitalWrite(DIR5, HIGH); //dir high = backward motor5
      digitalWrite(PUL5, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL5, LOW);
    }
    for (int n = 0; n < 2207; n++) {
      digitalWrite(DIR6, LOW); //dir low = forward motor6
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL6, LOW);
    }
  }
}

void neg_pitch_D() {
  ///////////////////////////////////////////////////
  //reverse pitch down
  for (int a = 0; a < 1; a++) {
    for (int i = 0; i < 2207; i++) { //Forward i steps
      digitalWrite(DIR, LOW); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL, LOW);}
    for (int j = 0; j < 2347; j++) {
      digitalWrite(DIR2, HIGH); //dir low = forward motor2
      digitalWrite(PUL2, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL2, LOW);}

    for (int k = 0; k < 2961; k++) {
      digitalWrite(DIR3, LOW); //dir high = backward motor3
      digitalWrite(PUL3, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL3, LOW);}

    for (int l = 0; l < 2961; l++) {
      digitalWrite(DIR4, HIGH); //dir low = forward motor4
      digitalWrite(PUL4, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL4, LOW);}

    for (int m = 0; m < 2347; m++) {
      digitalWrite(DIR5, LOW); //dir high = backward motor5
      digitalWrite(PUL5, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL5, LOW);}
    for (int n = 0; n < 2207; n++) {
      digitalWrite(DIR6, HIGH); //dir low = forward motor6
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
      digitalWrite(PUL6, LOW);}
  }
}
///////////////////////////////////////////////////////////////////////////////
//
void pitch_U() {
  //pitch up
  for (int a = 0; a < 1; a++) {
    for (int i = 0; i < 1695; i++) { //Forward i steps
      digitalWrite(DIR, LOW); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL, LOW);
    }

    for (int j = 0; j < 1889; j++) {
      digitalWrite(DIR2, HIGH); //dir low = forward motor2
      digitalWrite(PUL2, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL2, LOW);
    }

    for (int k = 0; k < 2928; k++) {
      digitalWrite(DIR3, LOW); //dir high = backward motor3
      digitalWrite(PUL3, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL3, LOW);
    }

    for (int l = 0; l < 2928; l++) {
      digitalWrite(DIR4, HIGH); //dir low = forward motor4
      digitalWrite(PUL4, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL4, LOW);
    }

    for (int m = 0; m < 1889; m++) {
      digitalWrite(DIR5, LOW); //dir high = backward motor5
      digitalWrite(PUL5, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL5, LOW);
    }

    for (int n = 0; n < 1695; n++) {
      digitalWrite(DIR6, HIGH); //dir low = forward motor6
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL6, LOW);
    }
  }
}
////reverse pitchup
void neg_pitch_U() {
  for (int a = 0; a < 1; a++) {
    for (int i = 0; i < 1695; i++) { //Forward i steps
      digitalWrite(DIR, HIGH); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL, LOW);
    }

    for (int j = 0; j < 1889; j++) {
      digitalWrite(DIR2, LOW); //dir low = forward motor2
      digitalWrite(PUL2, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL2, LOW);
    }

    for (int k = 0; k < 2928; k++) {
      digitalWrite(DIR3, HIGH); //dir high = backward motor3
      digitalWrite(PUL3, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL3, LOW);
    }

    for (int l = 0; l < 2928; l++) {
      digitalWrite(DIR4, LOW); //dir low = forward motor4
      digitalWrite(PUL4, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL4, LOW);
    }

    for (int m = 0; m < 1889; m++) {
      digitalWrite(DIR5, HIGH); //dir high = backward motor5
      digitalWrite(PUL5, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL5, LOW);
    }

    for (int n = 0; n < 1695; n++) {
      digitalWrite(DIR6, LOW); //dir low = forward motor6
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL6, LOW);
    }
  }
}///////////////////////////////////////////////////////////////////

////ROLL
void roll() {
  for (int a = 0; a < 1; a++) {
    for (int i = 0; i < 225; i++) { //Forward i steps
      digitalWrite(DIR, HIGH); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL, LOW);
    }

    for (int j = 0; j < 440; j++) {
      digitalWrite(DIR2, HIGH); //dir low = forward motor2
      digitalWrite(PUL2, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL2, LOW);
    }

    for (int k = 0; k < 637; k++) {
      digitalWrite(DIR3, LOW); //dir high = backward motor3
      digitalWrite(PUL3, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL3, LOW);
    }

    for (int l = 0; l < 1058; l++) {
      digitalWrite(DIR4, LOW); //dir low = forward motor4
      digitalWrite(PUL4, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL4, LOW);
    }

    for (int m = 0; m < 1450; m++) {
      digitalWrite(DIR5, HIGH); //dir high = backward motor5
      digitalWrite(PUL5, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL5, LOW);
    }

    for (int n = 0; n < 809; n++) {
      digitalWrite(DIR6, LOW); //dir low = forward motor6
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL6, LOW);
    }
  }
}
////negative ROLL
void neg_roll() {
  for (int a = 0; a < 1; a++) {
    for (int i = 0; i < 225; i++) { //Forward i steps
      digitalWrite(DIR, LOW); //dir High = backward motor1
      digitalWrite(PUL, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL, LOW);
    }

    for (int j = 0; j < 440; j++) {
      digitalWrite(DIR2, LOW); //dir low = forward motor2
      digitalWrite(PUL2, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL2, LOW);
    }

    for (int k = 0; k < 637; k++) {
      digitalWrite(DIR3, HIGH); //dir high = backward motor3
      digitalWrite(PUL3, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL3, LOW);
    }

    for (int l = 0; l < 1058; l++) {
      digitalWrite(DIR4, HIGH); //dir low = forward motor4
      digitalWrite(PUL4, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL4, LOW);
    }

    for (int m = 0; m < 1450; m++) {
      digitalWrite(DIR5, LOW); //dir high = backward motor5
      digitalWrite(PUL5, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL5, LOW);
    }

    for (int n = 0; n < 809; n++) {
      digitalWrite(DIR6, HIGH); //dir low = forward motor6
      digitalWrite(PUL6, HIGH);
      delayMicroseconds(50);
    digitalWrite(PUL6, LOW);
    }
  }
}






