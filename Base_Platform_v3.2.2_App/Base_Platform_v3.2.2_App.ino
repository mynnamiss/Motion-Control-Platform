/*programmer: Pedro Medellin
  Organization: California State University Fullerton
  Project: Base platform for PacMin interactive plane model.
  Version: 3.22- The final iteration one where we have functioning states.
  Pitch, yaw, roll, translation in both directions.*/

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
  state= Serial.read();}

  if (state == '4') {
  Serial.println("Pitching Up:");
  pitch_U(); delay(1000);}
  
  else if (state == '2') {
  Serial.println("Rolling left:");
  roll_L(); delay(1000);}
  
  else if (state == '1') {
  Serial.println("Pitching Down:");
  pitch_D(); delay(1000);}
  
  else if (state == '3') {
  Serial.println("Rolling right:");
  roll_R(); delay(1000);}

   else if (state == 'q') {
  Serial.println("Yaw left:");
  yawL(); delay(1000);}

  else if (state == 'e') {
  Serial.println("Yaw right:");
  yawR(); delay(1000);}
  
  else if (state == 'F') {
  Serial.println("Flight:");
  flight(); delay(1000);}
  
  else if (state == 'a') {
  Serial.println("Moving 1 and 6 up.");
  stateAU(); delay(1000);}
  
  else if (state == 'b') {
  Serial.println("Moving 1 and 6 down.");
  stateAD(); delay(1000);}
  
  else if (state == 'c') {
  Serial.println("Moving 3 and 4 up.");
  stateCU(); delay(1000);}
  
  else if (state == 'd') {
  Serial.println("Moving 3 and 4 down.");
  stateCD(); delay(1000);}
  
  else if (state == 'e') {
  Serial.println("Moving 2 and 5 up.");
  stateBU(); delay(1000);}
  
  else if (state == 'f') {
  Serial.println("Moving 2 and 5 down.");
  stateBD(); delay(1000);}
  else if (state == 'I') {
  Serial.println("Initialization.");
  initialization(); delay(1000);}
  else if (state == 'Z') {
  Serial.println("Flight 2.");
  flight2(); delay(1000);}}

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
void roll_R() {
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
    neg_roll_R(counter);}

////negative ROLL
void neg_roll_R(long int count) {
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
void roll_L(){
  innerstate = '1';
  counter = 0;
  while (innerstate != '0') {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR5, HIGH);  digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, LOW);  digitalWrite(PUL6, HIGH);
    digitalWrite(DIR2, HIGH); digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR3, LOW); digitalWrite(PUL3, HIGH);  
    delayMicroseconds(800);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL6,LOW);    digitalWrite(PUL3, LOW); counter++;}
    Serial.println(counter);
    delay(1000);
    Serial.println("Rolling back");
    neg_roll_L(counter);}

void neg_roll_L(long int count){
  while (count>0) {
    digitalWrite(DIR5, LOW);  digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, HIGH);  digitalWrite(PUL6, HIGH); 
    digitalWrite(DIR2, LOW); digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR3, HIGH); digitalWrite(PUL3, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL6,LOW); digitalWrite(PUL3, LOW);count--;}
    Serial.println(count);}

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
    digitalWrite(PUL2, LOW);  digitalWrite(PUL3, LOW);
    digitalWrite(PUL,LOW); count--;}
    Serial.println(count);}


void lateral_L() {
  innerstate = '1';
  counter = 0;
  while (innerstate != '0') {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR4, LOW);  digitalWrite(PUL4, HIGH);
    digitalWrite(DIR5, HIGH);  digitalWrite(PUL5, HIGH); 
    digitalWrite(DIR6, LOW); digitalWrite(PUL6, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL4, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL6,LOW); counter++;}
    Serial.println(counter);
    delay(1000);
    Serial.println("Lateral back");
    lateral_RB(counter);}

////lateral right back
void lateral_LB(long int count) {
  while (count>0) {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR4, HIGH);  digitalWrite(PUL4, HIGH);
    digitalWrite(DIR5, LOW);  digitalWrite(PUL5, HIGH); 
    digitalWrite(DIR6, HIGH); digitalWrite(PUL6, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL4, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL6,LOW); count--;}
    Serial.println(count);}

////////////////////////////////////////////////////////////////

void yawL(){//SET C DOWN
  innerstate = '1';
  counter = 0;
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR4, LOW); digitalWrite(PUL4, HIGH);
    digitalWrite(DIR5, HIGH);digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, LOW); digitalWrite(PUL6, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL5, LOW);digitalWrite(PUL4, LOW);
    digitalWrite(PUL6, LOW); counter++;}
    Serial.println(counter);
    delay(1000);
    Serial.println("Yaw back");
    yawLB(counter);}

void yawLB(long int count){//SET C DOWN
  innerstate = '1';
  while (count>0) {
    innerstate = Serial.read();
    digitalWrite(DIR4, HIGH); digitalWrite(PUL4, HIGH);
    digitalWrite(DIR5, LOW);  digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, HIGH); digitalWrite(PUL6, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL5, LOW);  digitalWrite(PUL4, LOW);
    digitalWrite(PUL6, LOW);  count--;}
    Serial.println(count);}

void yawR(){//SET C DOWN
  innerstate = '1';
  counter = 0;
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, HIGH);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, LOW);  digitalWrite(PUL2, HIGH);
    digitalWrite(DIR3, HIGH); digitalWrite(PUL3, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL, LOW);   digitalWrite(PUL2, LOW);
    digitalWrite(PUL3, LOW);  counter++;}
    Serial.println(counter); delay(5000);
    Serial.println("Yawing back");
    yawRB(counter);}

void yawRB(long int count){//SET C DOWN
  innerstate = '1';
  while (count>0) {
    innerstate = Serial.read();
    digitalWrite(DIR, LOW);   digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, HIGH); digitalWrite(PUL2, HIGH);
    digitalWrite(DIR3, LOW);  digitalWrite(PUL3, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL, LOW);   digitalWrite(PUL2, LOW);
    digitalWrite(PUL3, LOW);  count--;}
    Serial.println(count);}
/////////////////////////////////////////////////////////////////////////////

void Motor1() {//down
  innerstate = '1';
  Serial.println("Motor 1");
  while(innerstate != 'x'){
    innerstate = Serial.read();
    if(innerstate == 'u'){
      Serial.println("Moving Motor 1 up...");// up is backwards  
      while (innerstate != '0') {
        innerstate = Serial.read();
        digitalWrite(DIR, HIGH); digitalWrite(PUL, HIGH); //dir High = backward 
        delayMicroseconds(650);
        digitalWrite(PUL, LOW);}}
  
    else if(innerstate == 'd') {
      Serial.println("Moving Motor 1 down...");// up is backwards
      while (innerstate != '0') {
        innerstate = Serial.read();
        digitalWrite(DIR, LOW); digitalWrite(PUL, HIGH);//dir High = backward
        delayMicroseconds(650);
        digitalWrite(PUL, LOW);}}}
        Serial.println("Motor 1 exit");}

void Motor2() {//up
  innerstate = 'u';
  Serial.println("Motor 2");
  while(innerstate != 'x'){
    innerstate = Serial.read();
    if(innerstate == 'u'){
      Serial.println("Moving Motor 2 up...");// up is backwards
      while (innerstate != '0') {
        innerstate = Serial.read();
        digitalWrite(DIR2, LOW); digitalWrite(PUL2, HIGH);//dir High = backward
        delayMicroseconds(650);
        digitalWrite(PUL2, LOW);}}
   
    else if (innerstate == 'd'){
      Serial.println("Moving Motor 2 down...");// up is backwards
      while (innerstate != '0') {
        innerstate = Serial.read();
        digitalWrite(DIR2, HIGH); digitalWrite(PUL2, HIGH);//dir High = backward 
        delayMicroseconds(650);
        digitalWrite(PUL2, LOW);}}}
        Serial.println("Motor 2 exit");}

void Motor3() {
  innerstate = '1';
  Serial.println("Motor 3");
  while(innerstate != 'x'){
    innerstate = Serial.read();
    if(innerstate == 'd'){
      Serial.println("Moving Motor 3 down...");// up is backwards
      while (innerstate != '0') {
        innerstate = Serial.read();
        digitalWrite(DIR3, LOW); digitalWrite(PUL3, HIGH);//dir High = backward 
        delayMicroseconds(650);
        digitalWrite(PUL3, LOW);}}
    
    else if (innerstate == 'u'){
      Serial.println("Moving Motor 3 up...");// up is backwards
      while (innerstate != '0') {
        innerstate = Serial.read(); 
        digitalWrite(DIR3, HIGH);digitalWrite(PUL3, HIGH); //dir High = backward 
        delayMicroseconds(650);
        digitalWrite(PUL3, LOW);}}}
        Serial.println("Motor 3 exit");}

void Motor4() {
  innerstate = '1';
  Serial.println("Motor 4");
  while(innerstate != 'x'){
    innerstate = Serial.read();
    if (innerstate == 'u'){
      Serial.println("Moving Motor 4 up...");// up is backwards
      while (innerstate != '0') {
        innerstate = Serial.read();
        digitalWrite(DIR4, LOW);  digitalWrite(PUL4, HIGH); //dir High = backward
        delayMicroseconds(650);
        digitalWrite(PUL4, LOW);}}
   
    else if (innerstate == 'd'){ 
      Serial.println("Moving Motor 4 down...");// up is backwards
      while (innerstate != '0') {
        innerstate = Serial.read();
        digitalWrite(DIR4, HIGH); digitalWrite(PUL4, HIGH);//dir High = backward 
        delayMicroseconds(650);
        digitalWrite(PUL4, LOW);}}}
        Serial.println("Motor 4 exit");}

void Motor5() {
  innerstate = '1';
  Serial.println("Motor 5");
  while(innerstate != 'x'){
    innerstate = Serial.read();
    if(innerstate == 'd'){
      Serial.println("Moving Motor 5 down...");// up is backwards
      while (innerstate != '0') {
        innerstate = Serial.read();
        digitalWrite(DIR5, LOW); digitalWrite(PUL5, HIGH);//dir High = backward
        delayMicroseconds(650);
        digitalWrite(PUL5, LOW);}}
   
    else if(innerstate == 'u'){
      Serial.println("Moving Motor 5 up...");// up is backwards
      while (innerstate != '0') {
        innerstate = Serial.read();
        digitalWrite(DIR5, HIGH); digitalWrite(PUL5, HIGH);//dir High = backward
        delayMicroseconds(650);
        digitalWrite(PUL5, LOW);}}}
        Serial.println("Motor 5 exit");}

void Motor6() {
  innerstate = '1';
  Serial.println("Motor 6");
  while(innerstate != 'x'){
    innerstate = Serial.read();
    if (innerstate == 'u'){
      Serial.println("Moving Motor 6 up...");// up is backwards
      while (innerstate != '0') {
        innerstate = Serial.read();
        digitalWrite(DIR6, LOW); digitalWrite(PUL6, HIGH);//dir High = backward 
        delayMicroseconds(650);
        digitalWrite(PUL6, LOW);}}
    
    else if (innerstate == 'd'){
      Serial.println("Moving Motor 6 down...");// up is backwards
      while (innerstate != '0') {
        innerstate = Serial.read();
        digitalWrite(DIR6, HIGH); digitalWrite(PUL6, HIGH);//dir High = backward
        delayMicroseconds(650);
        digitalWrite(PUL6, LOW);}}}
        Serial.println("Motor 6 exit");}
////////////////////////////////////////////

void stateAU(){//SET A UP
  innerstate = '1';
  counter = 0;
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, HIGH); digitalWrite(PUL, HIGH);//dir High = backward
    digitalWrite(DIR6, LOW); digitalWrite(PUL6, HIGH);  
    delayMicroseconds(300);
    digitalWrite(PUL, LOW); digitalWrite(PUL6, LOW);}}
void stateAD(){//SET A UP
  innerstate = '1';
  counter =0;
  while (innerstate != '0') {
    innerstate = Serial.read();//dir High = backward
    digitalWrite(DIR, LOW);   digitalWrite(PUL, HIGH);
    digitalWrite(DIR6, HIGH); digitalWrite(PUL6, HIGH);  
    delayMicroseconds(300);
    digitalWrite(PUL, LOW);  digitalWrite(PUL6, LOW);}}
/////////////////////////////////

void stateCD(){//SET C DOWN
  innerstate = '1';
  counter = 0;
  while (innerstate != '0') {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR3, LOW);  digitalWrite(PUL3, HIGH);
    digitalWrite(DIR4, HIGH); digitalWrite(PUL4, HIGH);  
    delayMicroseconds(650);
    digitalWrite(PUL3, LOW);  digitalWrite(PUL4, LOW);}}
void stateCU(){//SET C UP
  innerstate = '1';
  counter = 0;
  while (innerstate != '0') {
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR3, HIGH); digitalWrite(PUL3, HIGH);
    digitalWrite(DIR4, LOW);  digitalWrite(PUL4, HIGH);  
    delayMicroseconds(650);
    digitalWrite(PUL3, LOW);  digitalWrite(PUL4, LOW);}}
void stateBU(){
  innerstate = '1';
  counter = 0;
  while(innerstate !='0'){
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR2, LOW); digitalWrite(PUL2, HIGH);
    digitalWrite(DIR5, HIGH);  digitalWrite(PUL5, HIGH);  
    delayMicroseconds(300);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);}}
void stateBD(){
  innerstate = '1';
  counter =0;
  while(innerstate !='0'){
    innerstate = Serial.read();//dir High = backward 
    digitalWrite(DIR2, HIGH); digitalWrite(PUL2, HIGH);
    digitalWrite(DIR5, LOW);  digitalWrite(PUL5, HIGH);  
    delayMicroseconds(300);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);}}

void flight(){
  counter = 0;
  for(int i = 0;i<5;i++){
  Serial.println("Pitch up");
  while(counter<=10000){//pitch up
    digitalWrite(DIR2, HIGH); digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR5, LOW);  digitalWrite(PUL5, HIGH);  
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);counter++;}
  delayMicroseconds(2000);
  Serial.println("Coming back");
  while(counter>=10000 && counter<=20000){//pitch up return
    digitalWrite(DIR2, LOW);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR5, HIGH); digitalWrite(PUL5, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);counter++;}
  delayMicroseconds(2000);
  
  Serial.println("Yawing right");
  while(counter>=20000 && counter<=30000){//pitch down
    digitalWrite(DIR, HIGH);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, LOW);  digitalWrite(PUL2, HIGH);
    digitalWrite(DIR3, HIGH); digitalWrite(PUL3, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL, LOW);   digitalWrite(PUL2, LOW);
    digitalWrite(PUL3, LOW);  counter++;}
  delayMicroseconds(2000);
  Serial.println("Coming back");
  while(counter >=30000&& counter <=40000){//pitch down return
    digitalWrite(DIR, LOW);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, HIGH);  digitalWrite(PUL2, HIGH);
    digitalWrite(DIR3, LOW); digitalWrite(PUL3, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL, LOW);   digitalWrite(PUL2, LOW);
    digitalWrite(PUL3, LOW);  counter++;}
    delayMicroseconds(2000);
    
  Serial.println("Rolling left");  
  while(counter>=40000&& counter <=55000){
    digitalWrite(DIR5, HIGH);  digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, LOW);  digitalWrite(PUL6, HIGH);
    digitalWrite(DIR2, HIGH); digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR3, LOW); digitalWrite(PUL3, HIGH);  
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL6,LOW);    digitalWrite(PUL3, LOW); counter++;}
  delayMicroseconds(2000);
  Serial.println("Rolling back");
  while(counter >=55000&& counter <=70000){
    digitalWrite(DIR5, LOW);  digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, HIGH);  digitalWrite(PUL6, HIGH); 
    digitalWrite(DIR2, LOW); digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR3, HIGH); digitalWrite(PUL3, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL6,LOW); digitalWrite(PUL3, LOW);counter++;}
  delayMicroseconds(2000);

  Serial.println("Rolling right");
  while(counter >=70000&& counter <=85000){
    digitalWrite(DIR, HIGH);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, LOW);  digitalWrite(PUL2, HIGH);
    digitalWrite(DIR4, HIGH); digitalWrite(PUL4, HIGH); 
    digitalWrite(DIR5, LOW); digitalWrite(PUL5, HIGH);  
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL,LOW);    digitalWrite(PUL4, LOW); counter++;}
  delayMicroseconds(2000);
  Serial.println("Rolling back");
  while(counter >=85000&& counter <=100000){
    digitalWrite(DIR, LOW);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, HIGH);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR4, LOW); digitalWrite(PUL4, HIGH); 
    digitalWrite(DIR5, HIGH); digitalWrite(PUL5, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL,LOW); digitalWrite(PUL4, LOW);counter++;}
  delayMicroseconds(2000);
  
Serial.println("Yaw Left");
  while(counter >=100000&& counter <=110000){
    digitalWrite(DIR4, LOW); digitalWrite(PUL4, HIGH);
    digitalWrite(DIR5, HIGH);digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, LOW); digitalWrite(PUL6, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL5, LOW);digitalWrite(PUL4, LOW);
    digitalWrite(PUL6, LOW); counter++;}
  delayMicroseconds(2000);
  Serial.println("Yawing back");
  while(counter >=110000&& counter <=120000){
    digitalWrite(DIR4, HIGH); digitalWrite(PUL4, HIGH);
    digitalWrite(DIR5, LOW);  digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, HIGH); digitalWrite(PUL6, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL5, LOW);  digitalWrite(PUL4, LOW);
    digitalWrite(PUL6, LOW);  counter++;}
  delayMicroseconds(2000);

Serial.println("Pitching down");
  while(counter >=120000&& counter <=130000){
    digitalWrite(DIR2, LOW); digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR5, HIGH);  digitalWrite(PUL5, HIGH);  
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);counter++;}
  delayMicroseconds(2000);
  Serial.println("Coming back");
  while(counter >=130000&& counter <=140000){
    digitalWrite(DIR2, HIGH);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR5, LOW); digitalWrite(PUL5, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);counter++;}
  }}

void flight2(){
  counter = 0;
  for(int i = 0;i<5;i++){
  Serial.println("Pitch up");
  while(counter<=10000){//pitch up
    digitalWrite(DIR2, HIGH); digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR5, LOW);  digitalWrite(PUL5, HIGH);  
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);counter++;}
  delayMicroseconds(2000);
  Serial.println("Yawing right");
  while(counter>=10000 && counter<=20000){//pitch down
    digitalWrite(DIR, HIGH);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, LOW);  digitalWrite(PUL2, HIGH);
    digitalWrite(DIR3, HIGH); digitalWrite(PUL3, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL, LOW);   digitalWrite(PUL2, LOW);
    digitalWrite(PUL3, LOW);  counter++;}
  delayMicroseconds(2000);
  
  Serial.println("Pitch up return");
  while(counter>=20000 && counter<=30000){//pitch up return
    digitalWrite(DIR2, LOW);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR5, HIGH); digitalWrite(PUL5, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);counter++;}
  delayMicroseconds(2000);
  
    Serial.println("Yaw right return");
  while(counter >=30000&& counter <=40000){//pitch down return
    digitalWrite(DIR, LOW);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, HIGH);  digitalWrite(PUL2, HIGH);
    digitalWrite(DIR3, LOW); digitalWrite(PUL3, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL, LOW);   digitalWrite(PUL2, LOW);
    digitalWrite(PUL3, LOW);  counter++;}
    delayMicroseconds(2000);
    
  Serial.println("Rolling left");  
  while(counter>=40000&& counter <=55000){
    digitalWrite(DIR5, HIGH);  digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, LOW);  digitalWrite(PUL6, HIGH);
    digitalWrite(DIR2, HIGH); digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR3, LOW); digitalWrite(PUL3, HIGH);  
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL6,LOW);    digitalWrite(PUL3, LOW); counter++;}
  delayMicroseconds(2000);
  Serial.println("Rolling back");
  while(counter >=55000&& counter <=70000){
    digitalWrite(DIR5, LOW);  digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, HIGH);  digitalWrite(PUL6, HIGH); 
    digitalWrite(DIR2, LOW); digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR3, HIGH); digitalWrite(PUL3, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL6,LOW); digitalWrite(PUL3, LOW);counter++;}
  delayMicroseconds(2000);

  Serial.println("Rolling right");
  while(counter >=70000&& counter <=85000){
    digitalWrite(DIR, HIGH);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, LOW);  digitalWrite(PUL2, HIGH);
    digitalWrite(DIR4, HIGH); digitalWrite(PUL4, HIGH); 
    digitalWrite(DIR5, LOW); digitalWrite(PUL5, HIGH);  
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL,LOW);    digitalWrite(PUL4, LOW); counter++;}
  delayMicroseconds(2000);
  Serial.println("Rolling back");
  while(counter >=85000&& counter <=100000){
    digitalWrite(DIR, LOW);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, HIGH);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR4, LOW); digitalWrite(PUL4, HIGH); 
    digitalWrite(DIR5, HIGH); digitalWrite(PUL5, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);
    digitalWrite(PUL,LOW); digitalWrite(PUL4, LOW);counter++;}
  delayMicroseconds(2000);
  
Serial.println("Yaw Left");
  while(counter >=100000&& counter <=110000){
    digitalWrite(DIR4, LOW); digitalWrite(PUL4, HIGH);
    digitalWrite(DIR5, HIGH);digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, LOW); digitalWrite(PUL6, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL5, LOW);digitalWrite(PUL4, LOW);
    digitalWrite(PUL6, LOW); counter++;}
  delayMicroseconds(2000);
  Serial.println("Yawing back");
  while(counter >=110000&& counter <=120000){
    digitalWrite(DIR4, HIGH); digitalWrite(PUL4, HIGH);
    digitalWrite(DIR5, LOW);  digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, HIGH); digitalWrite(PUL6, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL5, LOW);  digitalWrite(PUL4, LOW);
    digitalWrite(PUL6, LOW);  counter++;}
  delayMicroseconds(2000);

  Serial.println("Translation left");
  while(counter >=120000 && counter <= 130000){
    digitalWrite(DIR, HIGH);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, LOW);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR3, HIGH); digitalWrite(PUL3, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL3, LOW);
    digitalWrite(PUL,LOW); counter++;}
  delayMicroseconds(2000);
  Serial.println("Translating left back");
  while (counter>=130000 && counter<=140000){
    digitalWrite(DIR, LOW);  digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, HIGH);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR3, LOW); digitalWrite(PUL3, HIGH); 
    delayMicroseconds(800);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL3, LOW);
    digitalWrite(PUL,LOW); counter++;}
    
Serial.println("Pitching down");
  while(counter >=140000&& counter <=150000){
    digitalWrite(DIR2, LOW); digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR5, HIGH);  digitalWrite(PUL5, HIGH);  
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);counter++;}
  delayMicroseconds(2000);
  Serial.println("Coming back");
  while(counter >=130000&& counter <=140000){
    digitalWrite(DIR2, HIGH);  digitalWrite(PUL2, HIGH); 
    digitalWrite(DIR5, LOW); digitalWrite(PUL5, HIGH); 
    delayMicroseconds(1000);
    digitalWrite(PUL2, LOW);  digitalWrite(PUL5, LOW);counter++;}
  }}


void initialization(){
 counter = 0;
 innerstate = '1';
 while (counter<=51300){
  digitalWrite(DIR, LOW);  digitalWrite(PUL, HIGH);
  digitalWrite(DIR2, HIGH);  digitalWrite(PUL2, HIGH);
  digitalWrite(DIR5, LOW); digitalWrite(PUL5, HIGH); 
  digitalWrite(DIR6, HIGH); digitalWrite(PUL6, HIGH); 
  delayMicroseconds(300);
  digitalWrite(PUL, LOW);   digitalWrite(PUL2, LOW);
  digitalWrite(PUL5, LOW);  digitalWrite(PUL6, LOW);  counter++;}
 while  (counter >=51300 && counter<52500){
  digitalWrite(DIR, LOW);  digitalWrite(PUL, HIGH); 
  digitalWrite(DIR6, HIGH); digitalWrite(PUL6, HIGH); 
  delayMicroseconds(300);
  digitalWrite(PUL, LOW);   digitalWrite(PUL2, LOW);
  digitalWrite(PUL5, LOW);  digitalWrite(PUL6, LOW);  counter++;}
  Serial.println("Initialized...");
  while (innerstate != '0'){
    innerstate = Serial.read();  counter = 0;Serial.println("!");}
 while(counter<52000){
  digitalWrite(DIR3, LOW);  digitalWrite(PUL3, HIGH);
  digitalWrite(DIR4, HIGH);  digitalWrite(PUL4, HIGH);
  delayMicroseconds(300); digitalWrite(PUL3, LOW);digitalWrite(PUL4, LOW); counter++;}   
  }
