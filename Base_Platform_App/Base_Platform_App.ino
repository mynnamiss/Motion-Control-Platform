/*programmer: Pedro Medellin
Organization: California State University Fullerton
Project: Base platform for PacMin interactive plane model.*/
#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution for your motor
int readIn;
int previousState;
// initialize the stepper library on pins 8 through 11:
//I would like to rename these steppers so that they correspond  better to which motor they will be connected to.
//so +x -x +y -y +z -z etc etc
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
Stepper sendstepper (stepsPerRevolution, 38,39,40,41);
Stepper thirdStepper  (stepsPerRevolution, 22,23,24,25);
Stepper fourthStepper (stepsPerRevolution, 26,27,28,29);
Stepper fifthStepper  (stepsPerRevolution, 30,31,32,33);
Stepper sixthStepper  (stepsPerRevolution, 34,35,36,37);

byte state = 0;
volatile int buttonstate1(0), buttonstate2(0), buttonstate3(0);
const int button1 = 50;
const int button2 = 51;
const int button3 = 52;

void setup() {
  // set the speed for all motors at 60 rpm (ideal)
  myStepper.setSpeed(30);
  sendstepper.setSpeed(30);
  thirdStepper.setSpeed(30);
  fourthStepper.setSpeed(30);
  fifthStepper.setSpeed(30);
  sixthStepper.setSpeed(30);
  pinMode (button1, INPUT);
  pinMode (button2, INPUT);
  pinMode (button3, INPUT);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
//need to figure out how to save previous state, and then check where it was before, then also perform 

while(Serial.available()){
state = Serial.read();
   myStepper.step(0);
   sendstepper.step(0);
   thirdStepper.step(0);
   fourthStepper.step(0);
   fifthStepper.step(0);
   sixthStepper.step(0);
if (state == 0)
        {
           Serial.println("Pitching Down");
   myStepper.step(25);
   sendstepper.step(25);
   thirdStepper.step(25);
   fourthStepper.step(25);
   fifthStepper.step(25);
   sixthStepper.step(25);
   delay(1000);    
        }
    else if (state == 1)
        {
//           case previousState{}
           Serial.println("Pitching Up");
           pitch_U();
           state = 0;
        }
    else if (state == 2)
        {
           Serial.println("Rolling Left");
           roll_L();
           state = 0;
        } 
         else if (state == 2)
        {
           Serial.println("Rolling Left");
           roll_L();
           state = 0;
        } 
    /*else if (state == '4')
        {
           Serial.println("Rolling Right");
           //roll_R();
        }
    else if (state == '5')
        {
          Serial.println("Insert new function here");          
        }
    else if (state == '6')
        {
          Serial.println("Insert new function here"); 
        }
        else if (readIn == '7'){
          Serial.println("Resetting...");
          reset_position(); }
  }*/
}
}
//based on the angles given by David
//also based on the fact that each step is 1.8 deg...
//multiply 1.8 by each number inside the parenthesis to get the delta angle.
void pitch_D(){
   myStepper.step(-18);
   sendstepper.step(18);
   thirdStepper.step(-23);
   fourthStepper.step(23);
   fifthStepper.step(-18);
   sixthStepper.step(18);
   delay(1000);   
}

void neg_pitch_D(){
   myStepper.step(18);
   sendstepper.step(-18);
   thirdStepper.step(23);
   fourthStepper.step(-23);
   fifthStepper.step(18);
   sixthStepper.step(-18);
   delay(1000);
}

void pitch_U(){
   myStepper.step(-13);
   sendstepper.step(-15);
   thirdStepper.step(23);
   fourthStepper.step(-23);
   fifthStepper.step(15);
   sixthStepper.step(-13);
   delay(1000);
}

void neg_pitch_U(){
   myStepper.step(13);
   sendstepper.step(15);
   thirdStepper.step(-23);
   fourthStepper.step(23);
   fifthStepper.step(-15);
   sixthStepper.step(13);
   delay(1000);
}

void roll_L(){
   myStepper.step(2);
   sendstepper.step(4);
   thirdStepper.step(-5);
   fourthStepper.step(-8);
   fifthStepper.step(11);
   sixthStepper.step(-6);
   delay(1000);
}

void neg_roll_L(){
   myStepper.step(-2);
   sendstepper.step(-4);
   thirdStepper.step(5);
   fourthStepper.step(8);
   fifthStepper.step(-11);
   sixthStepper.step(6);
   delay(1000);
}

//void roll_R(){ //roll_L is just the mirror for this since I only had about 3 states to work with until now. will update with new values
//   myStepper.step(-2);
//   sendstepper.step(-4);
////   thirdStepper.step(5);
////   fourthStepper.step(8);
////   fifthStepper.step(-11);
////   sixthStepper.step(6);
//   delay(1000);
//}

void reset_position(){
  /*
  So here the idea is to have some external thing try and tell you where the motor is
  1. encoder.
  2. sets of photo interruptors at each of the angles we need to stop at. Since we only have about 45 deg of motion,
  we need to have maybe 3 of these per motor. Not ideal. 
  3. some sort of  gyroscope? we can then implement this also to the app. until then, this portion will be empty.
  */
}

