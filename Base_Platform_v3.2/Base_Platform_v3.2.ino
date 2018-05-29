/*programmer: Pedro Medellin
  Organization: California State University Fullerton
  Project: Base platform for PacMin interactive plane model.
  Version: 3 - this version is a result of state changes. Now this version has individual motor control.*/

volatile char state;
volatile int innerstate;

//declaration of pins
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

  Serial.println("Input D and onward for group control.");
}

void loop() {

  if (Serial.available() > 0) {
    state = Serial.read();
    if (state == '0') {
      Serial.println("Turning motors off");
      Motor_off();
      delay(1000);
    }

    if (state == '1') {
      Serial.println("Moving Motor 1 up...");
      Motor1b();
      delay(1000);
    }
    else if (state == '2') {
      Serial.println("Moving Motor 1 down...");
      Motor1();
      delay(1000);
    }
    else if (state == '3') {
      Serial.println("Moving Motor 2 up...");
      Motor2();
      delay(1000);
    }
    else if (state == '4') {
      Serial.println("Moving Motor 2 down:");
      Motor2b();
      delay(1000);
    }
    else if (state == '5') {
      Serial.println("Moving Motor 3 up...");
      Motor3b();
      delay(1000);
    }
    else if (state == '6') {
      Serial.println("Moving Motor 3 down...");
      Motor3();
      delay(1000);
    }
    else if (state == '7') {
      Serial.println("Moving Motor 4 up...");
      Motor4();
      delay(1000);
    }
    else if (state == '8') {
      Serial.println("Moving Motor 4 down...");
      Motor4b();
      delay(1000);
    }
    else if (state == '9') {
      Serial.println("Moving Motor 5 up...");
      Motor5b();
      delay(1000);
    }
    else if (state == 'a') {
      Serial.println("Moving Motor 5 down...");
      Motor5();
      delay(1000);
    }
    else if (state == 'b') {
      Serial.println("Moving Motor 6 up...");
      Motor6();
      delay(1000);
    }
    else if (state == 'c') {
      Serial.println("Moving Motor 6 down...");
      Motor6b();
      delay(1000);
    }
    else if (state == 'd') {
      Serial.println("Moving Motor 6 down...");
      stateAU();
      delay(1000);
    }
    else if (state == 'e') {
      Serial.println("Moving Motor 6 down...");
      stateAD();
      delay(1000);
    }
    else if (state == 'f') {
      Serial.println("Moving Motor 6 down...");
      stateCU();
      delay(1000);
    }
    else if (state == 'g') {
      Serial.println("Moving Motor 6 down...");
      stateCD();
      delay(1000);
    }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    
    else if (state == 'K') {
      Serial.println("Yaw L");
      yawL();
      delay(1000);
    }
    else if (state == 'L') {
      Serial.println("Yaw L back");
      yawLB();
      delay(1000);
    }
    else if (state == 'R') {
      Serial.println("Yaw R");
      yawR();
      delay(1000);
    }
    else if (state == 'T') {
      Serial.println("Yaw R back");
      yawRB();
      delay(1000);
    }
    else if (state == 'A') {
      Serial.println("Roll");
      Roll();
      delay(1000);
    }
    else if (state == 'S') {
      Serial.println("Roll back");
      RollB();
      delay(1000);
    }
    else if (state == 'U') {
      Serial.println("UP");
      pitchU();
      delay(1000);
    }
    else if (state == 'I') {
      Serial.println("UP back");
      pitchUB();
      delay(1000);
    }
  }
}

//function names are self explanatory
//Theses are for each respective direction. 0 makes the motor stop running.
void Motor1() {//down
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, LOW); //dir High = backward 
    digitalWrite(PUL, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL, LOW);
  }
}

void Motor1b() {//up
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, HIGH); //dir High = backward 
    digitalWrite(PUL, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL, LOW);
  }
}

void Motor2() {//up
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR2, LOW); //dir High = backward 
    digitalWrite(PUL2, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL2, LOW);
  }
}

void Motor2b() {//down
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR2, HIGH); //dir High = backward 
    digitalWrite(PUL2, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL2, LOW);
  }
}

void Motor3() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR3, LOW); //dir High = backward 
    digitalWrite(PUL3, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL3, LOW);
  }
}

void Motor3b() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR3, HIGH); //dir High = backward 
    digitalWrite(PUL3, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL3, LOW);
  }
}

void Motor4() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR4, LOW); //dir High = backward
    digitalWrite(PUL4, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL4, LOW);
  }
}

void Motor4b() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR4, HIGH); //dir High = backward 
    digitalWrite(PUL4, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL4, LOW);
  }
}

void Motor5() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR5, LOW); //dir High = backward 
    digitalWrite(PUL5, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL5, LOW);
  }
}

void Motor5b() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR5, HIGH); //dir High = backward 
    digitalWrite(PUL5, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL5, LOW);
  }
}

void Motor6() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR6, LOW); //dir High = backward 
    digitalWrite(PUL6, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL6, LOW);
  }
}

void Motor6b() {
  innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR6, HIGH); //dir High = backward 
    digitalWrite(PUL6, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL6, LOW);
  }
}
//motor off might be unnecessary, but leave it in, in case.
void Motor_off() {
  digitalWrite(PUL, LOW);
  digitalWrite(PUL2, LOW);
  digitalWrite(PUL3, LOW);
  digitalWrite(PUL4, LOW);
  digitalWrite(PUL5, LOW);
  digitalWrite(PUL6, LOW);
}

///////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void stateAU(){//SET A UP
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, HIGH); //dir High = backward 
    digitalWrite(PUL, HIGH);
    digitalWrite(DIR6, LOW);
    digitalWrite(PUL6, HIGH);  
    delayMicroseconds(350);
    digitalWrite(PUL, LOW);
    digitalWrite(PUL6, LOW);  
  }
}
void stateAD(){//SET A UP
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, LOW); //dir High = backward 
    digitalWrite(PUL, HIGH);
    digitalWrite(DIR6, HIGH);
    digitalWrite(PUL6, HIGH);  
    delayMicroseconds(350);
    digitalWrite(PUL, LOW);
    digitalWrite(PUL6, LOW);  
  }
}

void stateCU(){//SET C UP
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR3, LOW); //dir High = backward 
    digitalWrite(PUL3, HIGH);
    digitalWrite(DIR4, HIGH);
    digitalWrite(PUL4, HIGH);  
    delayMicroseconds(350);
    digitalWrite(PUL3, LOW);
    digitalWrite(PUL4, LOW);  
  }
}
void stateCD(){//SET C DOWN
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR3, HIGH); //dir High = backward 
    digitalWrite(PUL3, HIGH);
    digitalWrite(DIR4, LOW);
    digitalWrite(PUL4, HIGH);  
    delayMicroseconds(350);
    digitalWrite(PUL3, LOW);
    digitalWrite(PUL4, LOW);  
  }
}

void pitchU(){//SET C DOWN
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, HIGH);
    digitalWrite(PUL, HIGH);
    digitalWrite(DIR6, LOW); //dir High = backward 
    digitalWrite(PUL6, HIGH); 
    digitalWrite(DIR3, HIGH); //dir High = backward 
    digitalWrite(PUL3, HIGH);
    digitalWrite(DIR4, LOW); //dir High = backward 
    digitalWrite(PUL4, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL, LOW);
    digitalWrite(PUL6, LOW); 
    digitalWrite(PUL3, LOW);
    digitalWrite(PUL4, LOW); 
  }
}

void pitchUB(){//SET C DOWN
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, LOW);
    digitalWrite(PUL, HIGH);
    digitalWrite(DIR6, HIGH); //dir High = backward 
    digitalWrite(PUL6, HIGH); 
    digitalWrite(DIR3, LOW); 
    digitalWrite(PUL3, HIGH);
    digitalWrite(DIR4, HIGH); //dir High = backward 
    digitalWrite(PUL4, HIGH);

    delayMicroseconds(350);
    digitalWrite(PUL, LOW);
    digitalWrite(PUL6, LOW); 
    digitalWrite(PUL3, LOW);
    digitalWrite(PUL4, LOW);  
  }
}


void yawL(){//SET C DOWN
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR4, LOW); //dir High = backward 
    digitalWrite(PUL4, HIGH);
    digitalWrite(DIR5, HIGH);
    digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, LOW); //dir High = backward 
    digitalWrite(PUL6, HIGH); 
    delayMicroseconds(350);
    digitalWrite(PUL5, LOW);
    digitalWrite(PUL4, LOW);
    digitalWrite(PUL6, LOW);  
  }
}

void yawLB(){//SET C DOWN
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR4, HIGH); //dir High = backward 
    digitalWrite(PUL4, HIGH);
    digitalWrite(DIR5, LOW);
    digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, HIGH); //dir High = backward 
    digitalWrite(PUL6, HIGH); 
    delayMicroseconds(350);
    digitalWrite(PUL5, LOW);
    digitalWrite(PUL4, LOW);
    digitalWrite(PUL6, LOW);  
  }
}

void yawR(){//SET C DOWN
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, HIGH); //dir High = backward 
    digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, LOW);
    digitalWrite(PUL2, HIGH);
    digitalWrite(DIR3, HIGH); //dir High = backward 
    digitalWrite(PUL3, HIGH); 
    delayMicroseconds(350);
    digitalWrite(PUL, LOW);
    digitalWrite(PUL2, LOW);
    digitalWrite(PUL3, LOW);  
  }
}

void yawRB(){//SET C DOWN
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR, LOW); //dir High = backward 
    digitalWrite(PUL, HIGH);
    digitalWrite(DIR2, HIGH);
    digitalWrite(PUL2, HIGH);
    digitalWrite(DIR3, LOW); //dir High = backward 
    digitalWrite(PUL3, HIGH); 
    delayMicroseconds(350);
    digitalWrite(PUL, LOW);
    digitalWrite(PUL2, LOW);
    digitalWrite(PUL3, LOW); 
  }
}

void Roll(){//SET C DOWN
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR2, HIGH); //dir High = backward 
    digitalWrite(PUL2, HIGH);
    digitalWrite(DIR3, LOW); //dir High = backward 
    digitalWrite(PUL3, HIGH);
    digitalWrite(DIR4, LOW); //dir High = backward 
    digitalWrite(PUL4, HIGH);
    digitalWrite(DIR5, HIGH); //dir High = backward 
    digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, LOW); //dir High = backward 
    digitalWrite(PUL6, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL, LOW);
    digitalWrite(PUL6, LOW);
    digitalWrite(PUL3, LOW);
    digitalWrite(PUL4, LOW); 
    digitalWrite(PUL2, LOW);
    digitalWrite(PUL5, LOW);
  }
}

void RollB(){//SET C DOWN
innerstate = '1';
  while (innerstate != '0') {
    innerstate = Serial.read();
    digitalWrite(DIR2, LOW); //dir High = backward 
    digitalWrite(PUL2, HIGH);
    digitalWrite(DIR3, HIGH); //dir High = backward 
    digitalWrite(PUL3, HIGH);
    digitalWrite(DIR4, HIGH); //dir High = backward 
    digitalWrite(PUL4, HIGH);
    digitalWrite(DIR5, LOW); //dir High = backward 
    digitalWrite(PUL5, HIGH);
    digitalWrite(DIR6, HIGH); //dir High = backward 
    digitalWrite(PUL6, HIGH);
    delayMicroseconds(350);
    digitalWrite(PUL, LOW);
    digitalWrite(PUL6, LOW);
    digitalWrite(PUL3, LOW);
    digitalWrite(PUL4, LOW); 
    digitalWrite(PUL2, LOW);
    digitalWrite(PUL5, LOW); 
  }
}

