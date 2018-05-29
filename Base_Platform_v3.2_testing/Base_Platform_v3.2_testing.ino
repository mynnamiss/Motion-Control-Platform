/*programmer: Pedro Medellin
  Organization: California State University Fullerton
  Project: Base platform for PacMin interactive plane model.
  Version: 3.21- This is the near final iteration one where we have functioning states.
  Pitch in both directions and one roll state, as provided.*/

volatile char state;
volatile int innerstate; 
long int counter;

/////////Motor Declaration
/////////motor1
int PUL = 3; int DIR = 4;//define Pulse pin //define Direction pin
/////////motor2
int PUL2 = 6; int DIR2 = 7; //define Pulse pin//define Direction pin
/////////motor3
int PUL3 = 9; int DIR3 = 10;//define Pulse pin //define Direction pin
/////////motor4
int PUL4 = 12; int DIR4 = 13;//define Pulse pin //define Direction pin
/////////motor5
int PUL5 = 22; int DIR5 = 23;//define Pulse pin //define Direction pin
////////motor6
int PUL6 = 26; int DIR6 = 27; //define Pulse pin //define Direction pin
//////end of motor declaration


void setup() {
  pinMode (PUL, OUTPUT);  pinMode (DIR, OUTPUT);
  pinMode (PUL2, OUTPUT); pinMode (DIR2, OUTPUT);
  pinMode (PUL3, OUTPUT); pinMode (DIR3, OUTPUT);
  pinMode (PUL4, OUTPUT); pinMode (DIR4, OUTPUT);
  pinMode (PUL5, OUTPUT); pinMode (DIR5, OUTPUT);
  pinMode (PUL6, OUTPUT); pinMode (DIR6, OUTPUT);
  Serial.begin(9600);}

void loop() {
  if (Serial.available()>0) {
    state = Serial.read();
    if (state == 'a') {
      Serial.println("Pitching Up:");
      pitch_U();
      delay(1000);}
    else if (state == 'b') {
      Serial.println("Rolling:");
      roll();
      delay(1000);}
      else if (state == 'c') {
      Serial.println("Pitching Down:");
      pitch_D();
      delay(1000);}
    else if (state == '1') {
      Serial.println("Moving Motor 1 up...");
      Motor1b();
      delay(1000);}
    else if (state == '2') {
      Serial.println("Moving Motor 1 down...");
      Motor1();
      delay(1000);}
    else if (state == '3') {
      Serial.println("Moving Motor 2 up...");
      Motor2();
      delay(1000);}
    else if (state == '4') {
      Serial.println("Moving Motor 2 down:");
      Motor2b();
      delay(1000);}
    else if (state == '5') {
      Serial.println("Moving Motor 3 up...");
      Motor3b();
      delay(1000);}
    else if (state == '6') {
      Serial.println("Moving Motor 3 down...");
      Motor3();
      delay(1000);}
    else if (state == '7') {
      Serial.println("Moving Motor 4 up...");
      Motor4();
      delay(1000);}
    else if (state == '8') {
      Serial.println("Moving Motor 4 down...");
      Motor4b();
      delay(1000);}
    else if (state == '9') {
      Serial.println("Moving Motor 5 up...");
      Motor5b();
      delay(1000);}
    else if (state == 'Q') {
      Serial.println("Moving Motor 5 down...");
      Motor5();
      delay(1000);}
    else if (state == 'W') {
      Serial.println("Moving Motor 6 up...");
      Motor6();
      delay(1000);}
    else if (state == 'EZ') {
      Serial.println("Moving Motor 6 down...");
      Motor6b();
      delay(1000);}
    else if (state == 'A') {
      Serial.println("Moving 1and 6 up.");
      stateAU();
      delay(1000);}
    else if (state == 'S') {
      Serial.println("Moving 1 and 6 down.");
      stateAD();
      delay(1000);}
    else if (state == 'C') {
      Serial.println("Moving 3 and 4 up.");
      stateCU();
      delay(1000);}
    else if (state == 'V') {
      Serial.println("Moving 3 and 4 down.");
      stateCD();
      delay(1000);}}}

/////////////////////////////////////////////////////////////////////////////
void pitch_D() {
    innerstate = '1';
counter = 0;
  while (innerstate != '0') {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR2, LOW); digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR5, HIGH);  digitalWrite(PUL5, HIGH);  
    delayMicroseconds(800);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);counter++;}
    Serial.println(counter);
    delay(1000);
    Serial.println("Reversing pitch up");
    neg_pitch_U(counter);}
////pitchDown reversed
void neg_pitch_D(long int count){//SET C DOWN
  while (count>0) {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR2, HIGH);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR5, LOW); digitalWrite(PUL5, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);count--;}
    Serial.println(count);}
///////////////////////////////////////////////////////////////////////////////
void pitch_U(){//SET C DOWN
innerstate = '1';
counter = 0;
  while (innerstate != '0') {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR2, HIGH); digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR5, LOW);  digitalWrite(PUL5, HIGH);  
    delayMicroseconds(800);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);counter++;}
    Serial.println(counter);
    delay(1000);
    Serial.println("Reversing pitch up");
    neg_pitch_U(counter);}
    
////reverse pitchup
void neg_pitch_U(long int count){//SET C DOWN
  while (count>0) {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR2, LOW);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR5, HIGH); digitalWrite(PUL5, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);count--;}
    Serial.println(count);}
///////////////////////////////////////////////////////////////////

////ROLL
void roll() {
  innerstate = '1';
  counter = 0;
  while (innerstate != '0') {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR, HIGH);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, LOW);  digitalWrite(PUL2, HIGH);
    digitalWrite(DIR4, HIGH); digitalWrite(PUL4, HIGH); 
    digitalWrite(DIR5, LOW); digitalWrite(PUL5, HIGH);  
    delayMicroseconds(800);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL,LOW);    digitalWrite(PUL4, LOW); counter++;}
    Serial.println(counter);
    delay(1000);
    Serial.println("Rolling back");
    neg_roll(counter);}

////negative ROLL
void neg_roll(long int count) {
  while (count>0) {
    digitalWrite(DIR, LOW);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, HIGH);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR4, LOW); digitalWrite(PUL4, HIGH); 
    digitalWrite(DIR5, HIGH); digitalWrite(PUL5, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL,LOW); digitalWrite(PUL4, LOW);count--;}
    Serial.println(count);}
///////////////////////////////////////////////////////

//lateral right
void lateral_R() {
  innerstate = '1';
  counter = 0;
  while (innerstate != '0') {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR, HIGH);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, LOW);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR3, HIGH); digitalWrite(PUL3, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL3, LOW);
    digitalWrite(PUL,LOW); counter++;}
    Serial.println(counter);
    delay(1000);
    Serial.println("Lateral back");
    lateral_RB(counter);}

////lateral right back
void lateral_RB(long int count) {
  while (count>0) {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR, LOW);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, HIGH);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR3, LOW); digitalWrite(PUL3, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL,LOW); count--;}
    Serial.println(count);}
//////////////////////////////////////

void Motor1() {//down
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, LOW); digitalWrite(PUL, HIGH);//dir High = backward
    delayMicroseconds(650);
    digitalWrite(PUL, LOW);}}

void Motor1b() {//up
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, HIGH); digitalWrite(PUL, HIGH); //dir High = backward 
    delayMicroseconds(650);
    digitalWrite(PUL, LOW);}}

void Motor2() {//up
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR2, LOW); digitalWrite(PUL2, HIGH);//dir High = backward
    delayMicroseconds(650);
    digitalWrite(PUL2, LOW);}}

void Motor2b() {//down
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR2, HIGH); digitalWrite(PUL2, HIGH);//dir High = backward 
    delayMicroseconds(650);
    digitalWrite(PUL2, LOW);}}

void Motor3() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR3, LOW); digitalWrite(PUL3, HIGH);//dir High = backward 
    delayMicroseconds(650);
    digitalWrite(PUL3, LOW);}}

void Motor3b() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR3, HIGH);digitalWrite(PUL3, HIGH); //dir High = backward 
    delayMicroseconds(650);
    digitalWrite(PUL3, LOW);}}

void Motor4() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR4, LOW);  digitalWrite(PUL4, HIGH); //dir High = backward
    delayMicroseconds(650);
    digitalWrite(PUL4, LOW);}}

void Motor4b() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR4, HIGH); digitalWrite(PUL4, HIGH);//dir High = backward 
    delayMicroseconds(650);
    digitalWrite(PUL4, LOW);}}

void Motor5() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR5, LOW); digitalWrite(PUL5, HIGH);//dir High = backward
    delayMicroseconds(650);
    digitalWrite(PUL5, LOW);}}

void Motor5b() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR5, HIGH); digitalWrite(PUL5, HIGH);//dir High = backward
    delayMicroseconds(650);
    digitalWrite(PUL5, LOW);}}

void Motor6() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR6, LOW); digitalWrite(PUL6, HIGH);//dir High = backward 
    delayMicroseconds(650);
    digitalWrite(PUL6, LOW);}}

void Motor6b() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR6, HIGH); digitalWrite(PUL6, HIGH);//dir High = backward
    delayMicroseconds(650);
    digitalWrite(PUL6, LOW);}}
////////////////////////////////////////////

void stateAU(){//SET A UP
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, HIGH); digitalWrite(PUL, HIGH);//dir High = backward
    digitalWrite(DIR6, LOW); digitalWrite(PUL6, HIGH);  
    delayMicroseconds(650);
    digitalWrite(PUL, LOW); digitalWrite(PUL6, LOW);}}
    
void stateAD(){//SET A UP
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();//dir High = backward
    digitalWrite(DIR, LOW);   digitalWrite(PUL, HIGH);
    digitalWrite(DIR6, HIGH); digitalWrite(PUL6, HIGH);  
    delayMicroseconds(650);
    digitalWrite(PUL, LOW);  digitalWrite(PUL6, LOW);}}
/////////////////////////////////

void stateCD(){//SET C UP
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR3, LOW);  digitalWrite(PUL3, HIGH);
    digitalWrite(DIR4, HIGH); digitalWrite(PUL4, HIGH);  
    delayMicroseconds(650);
    digitalWrite(PUL3, LOW);  digitalWrite(PUL4, LOW); }}

void stateCU(){//SET C DOWN
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR3, HIGH); digitalWrite(PUL3, HIGH);
    digitalWrite(DIR4, LOW);  digitalWrite(PUL4, HIGH);  
    delayMicroseconds(650);
    digitalWrite(PUL3, LOW);  digitalWrite(PUL4, LOW);}}
////////////////////////////////////////////////////////////////
