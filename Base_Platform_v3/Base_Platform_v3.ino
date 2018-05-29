/*programmer: Pedro Medellin
  Organization: California State University Fullerton
  Project: Base platform for PacMin interactive plane model.
  Version: 2 - This version is a result of the driver changes on March 8th*/


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
  //while (Serial.available()){
  char state = Serial.read();
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


}
void pitch_D() {
  for (int i = 0; i < 2207; i++) { //Forward 5000 steps
    digitalWrite(DIR, HIGH); //dir High = backward motor1
    digitalWrite(PUL, HIGH);
    if (!i) {
      for (int j = 0; j < 2347; j++) {
        digitalWrite(DIR2, LOW); //dir low = forward motor2
        digitalWrite(PUL2, HIGH);

        if (!j) {
          for (int k = 0; k < 2961; k++) {
            digitalWrite(DIR3, HIGH); //dir high = backward motor3
            digitalWrite(PUL3, HIGH);

            if (!k) {
              for (int l = 0; l < 2961; l++) {
                digitalWrite(DIR4, LOW); //dir low = forward motor4
                digitalWrite(PUL4, HIGH);

                if (!l) {
                  for (int m = 0; m < 2347; m++) {
                    digitalWrite(DIR5, HIGH); //dir high = backward motor5
                    digitalWrite(PUL5, HIGH);
                    if (!m) {
                      for (int n = 0; n < 2207; n++) {
                        digitalWrite(DIR6, LOW); //dir low = forward motor6
                        digitalWrite(PUL6, HIGH);
                      }
                    } Serial.println("6");
                  }
                } Serial.println("5");
              }
            } Serial.println("4");
          }
        } Serial.println("3");
      }
    } Serial.println("2");
  } Serial.println("moving");


  delayMicroseconds(50);
  digitalWrite(PUL, LOW);
  digitalWrite(PUL2, LOW);
  digitalWrite(PUL3, LOW);
  digitalWrite(PUL4, LOW);
  digitalWrite(PUL5, LOW);
  digitalWrite(PUL6, LOW);
}


void neg_pitch_D() {
  ///////////////////////////////////////////////////
  //reverse pitch down
  for (int i = 0; i < 2207; i++) { //Forward 5000 steps
    digitalWrite(DIR, LOW); //dir High = backward motor1
    digitalWrite(PUL, HIGH);
    for (int j = 0; j < 2347; j++) {
      digitalWrite(DIR2, HIGH); //dir low = forward motor2
      digitalWrite(PUL2, HIGH);

      for (int k = 0; k < 2961; k++) {
        digitalWrite(DIR3, LOW); //dir high = backward motor3
        digitalWrite(PUL3, HIGH);

        for (int l = 0; l < 2961; l++) {
          digitalWrite(DIR4, HIGH); //dir low = forward motor4
          digitalWrite(PUL4, HIGH);

          for (int m = 0; m < 2347; m++) {
            digitalWrite(DIR5, LOW); //dir high = backward motor5
            digitalWrite(PUL5, HIGH);
            for (int n = 0; n < 2207; n++) {
              digitalWrite(DIR6, HIGH); //dir low = forward motor6
              digitalWrite(PUL6, HIGH);}}}}}
  }
  delayMicroseconds(50);
  digitalWrite(PUL, LOW);
  digitalWrite(PUL2, LOW);
  digitalWrite(PUL3, LOW);
  digitalWrite(PUL4, LOW);
  digitalWrite(PUL5, LOW);
  digitalWrite(PUL6, LOW);

}
///////////////////////////////////////////////////////////////////////////////
//
void pitch_U(){
//pitch up
    for (int i=0; i<1695; i++){    //Forward 5000 steps
        if(!i) Serial.println("Starting Loop 1...");
        digitalWrite(DIR,LOW); //dir High = backward motor1
        digitalWrite(PUL,HIGH);
          delayMicroseconds(50);
  digitalWrite(PUL,LOW);
        if (i == 1694) Serial.println("Loop 1 finished!");
       
        if (!i) {
          for (int j=0; j<1889;j++){ 
          if(!j) Serial.println("Starting Loop 2...");
          digitalWrite(DIR2,HIGH); //dir low = forward motor2
          digitalWrite(PUL2,HIGH); 
          delayMicroseconds(50);
          digitalWrite(PUL2,LOW);
          if (j == 1888) Serial.println("Loop 2 finished!");
          
          if (!j) { 
            for (int k=0; k<2928;k++){ 
            if(!k) Serial.println("Starting Loop 3..."); 
            digitalWrite(DIR3,LOW); //dir high = backward motor3
            digitalWrite(PUL3,HIGH); 
            delayMicroseconds(50);
            digitalWrite(PUL3,LOW);
            if (k == 2927) Serial.println("Loop 3 finished!");
          
            if (!k) { 
              for (int l=0; l<2928;l++){
              if(!l) Serial.println("Starting Loop 4...");
              digitalWrite(DIR4,HIGH); //dir low = forward motor4
              digitalWrite(PUL4,HIGH);
              delayMicroseconds(50);
              digitalWrite(PUL4,LOW);
              if (l == 2927) Serial.println("Loop 4 finished!"); 
          
              if (!l) { 
                for (int m=0; m<1889;m++) {
                if(!m) Serial.println("Starting Loop 5...");
                digitalWrite(DIR5,LOW); //dir high = backward motor5
                digitalWrite(PUL5,HIGH); 
                 delayMicroseconds(50);
                digitalWrite(PUL5,LOW);
                if (m == 1888) Serial.println("Loop 5 finished!");
                
                if(!m) { 
                  for (int n=0; n<1695;n++){
                  if(!n) Serial.println("Starting Loop 6...");
                  digitalWrite(DIR6,HIGH); //dir low = forward motor6
                  digitalWrite(PUL6,HIGH);
                  delayMicroseconds(50);
                  digitalWrite(PUL6,LOW);
                  if (n == 1694) Serial.println("Loop 6 finished!");
                }}
                
              }}
              
            }}
            
          }}
          
        }}
        
      }


}
////reverse pitchup
void neg_pitch_U() {
  for (int i = 0; i < 1695; i++) { //Forward 5000 steps
    digitalWrite(DIR, HIGH); //dir High = backward motor1
    digitalWrite(PUL, HIGH);

    for (int j = 0; j < 1889; j++) {
      digitalWrite(DIR2, LOW); //dir low = forward motor2
      digitalWrite(PUL2, HIGH);

      for (int k = 0; k < 2928; k++) {
        digitalWrite(DIR3, HIGH); //dir high = backward motor3
        digitalWrite(PUL3, HIGH);

        for (int l = 0; l < 2928; l++) {
          digitalWrite(DIR4, LOW); //dir low = forward motor4
          digitalWrite(PUL4, HIGH);

          for (int m = 0; m < 1889; m++) {
            digitalWrite(DIR5, HIGH); //dir high = backward motor5
            digitalWrite(PUL5, HIGH);

            for (int n = 0; n < 1695; n++) {
              digitalWrite(DIR6, LOW); //dir low = forward motor6
              digitalWrite(PUL6, HIGH);
            }
          }
        }
      }
    }
  }

  delayMicroseconds(50);
  digitalWrite(PUL, LOW);
  digitalWrite(PUL2, LOW);
  digitalWrite(PUL3, LOW);
  digitalWrite(PUL4, LOW);
  digitalWrite(PUL5, LOW);
  digitalWrite(PUL6, LOW);
}///////////////////////////////////////////////////////////////////

////ROLL
void roll() {
  for (int i = 0; i < 225; i++) { //Forward 5000 steps
    digitalWrite(DIR, HIGH); //dir High = backward motor1
    digitalWrite(PUL, HIGH);

    for (int j = 0; j < 440; j++) {
      digitalWrite(DIR2, HIGH); //dir low = forward motor2
      digitalWrite(PUL2, HIGH);

      for (int k = 0; k < 637; k++) {
        digitalWrite(DIR3, LOW); //dir high = backward motor3
        digitalWrite(PUL3, HIGH);

        for (int l = 0; l < 1058; l++) {
          digitalWrite(DIR4, LOW); //dir low = forward motor4
          digitalWrite(PUL4, HIGH);

          for (int m = 0; m < 1450; m++) {
            digitalWrite(DIR5, HIGH); //dir high = backward motor5
            digitalWrite(PUL5, HIGH);

            for (int n = 0; n < 809; n++) {
              digitalWrite(DIR6, LOW); //dir low = forward motor6
              digitalWrite(PUL6, HIGH);
            }
          }
        }
      }
    }
  }

  delayMicroseconds(50);
  digitalWrite(PUL, LOW);
  digitalWrite(PUL2, LOW);
  digitalWrite(PUL3, LOW);
  digitalWrite(PUL4, LOW);
  digitalWrite(PUL5, LOW);
  digitalWrite(PUL6, LOW);
  //////////////////////////////////////////////////
}
////negative ROLL
void neg_roll() {
  for (int i = 0; i < 225; i++) { //Forward 5000 steps
    digitalWrite(DIR, LOW); //dir High = backward motor1
    digitalWrite(PUL, HIGH);

    for (int j = 0; j < 440; j++) {
      digitalWrite(DIR2, LOW); //dir low = forward motor2
      digitalWrite(PUL2, HIGH);

      for (int k = 0; k < 637; k++) {
        digitalWrite(DIR3, HIGH); //dir high = backward motor3
        digitalWrite(PUL3, HIGH);

        for (int l = 0; l < 1058; l++) {
          digitalWrite(DIR4, HIGH); //dir low = forward motor4
          digitalWrite(PUL4, HIGH);

          for (int m = 0; m < 1450; m++) {
            digitalWrite(DIR5, LOW); //dir high = backward motor5
            digitalWrite(PUL5, HIGH);

            for (int n = 0; n < 809; n++) {
              digitalWrite(DIR6, HIGH); //dir low = forward motor6
              digitalWrite(PUL6, HIGH);
            }
          }
        }
      }
    }
  }

  delayMicroseconds(50);
  digitalWrite(PUL, LOW);
  digitalWrite(PUL2, LOW);
  digitalWrite(PUL3, LOW);
  digitalWrite(PUL4, LOW);
  digitalWrite(PUL5, LOW);
  digitalWrite(PUL6, LOW);
}






