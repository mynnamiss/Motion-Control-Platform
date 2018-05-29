# Motion-Control-Platform
Control 6 Stepper Motors to perform dynamic movement. A project to move a mounted airplane model to simulate its flight.
//author: Pedro Medellin
//project: Motion control platform
***********************
All motors should be at 90 degrees before plugging in and controlling via app or laptop. Motors 1 and 6 should be a little lower than 90.
***********************

Controls for the Motion Platform

Using Keyboard/computer interface

Open Arduino IDE and press ctrl+shift+M to open the serial monitor
from there, the first thing you should push, assuming the motors are moved to their locations, is 'I' then enter. This is the initialization.

To leave it, press '0'; will need to press 0 before doing anything else.

for any adjustments,
'A' is to move motors 1 and 6 Up*******

'S' is to move motors 1 and 6 Down

'C' is to move motors 3 and 4 Up

'V' is to move motors 3 and 4 Down

'B' is to move motors 2 and 5 Up

'N' is to move motors 2 and 5 Down

for flight -> 'F'
	It will run by itself for a time
Secondary flight plan -> 'Z'

This one should look more like actual flight with pitch up first, other motions in between, and pitch down last.

	
Individual motor control.

Press the number of the motor you would like to control followed by the direction ('u'/'d'). To stop, press '0'. To exit that motor's control, press 'x'.

The control for the states are:
'w' for pitch up

's' for pitch down

'a' for roll left

'd' for roll right

'q' for yaw left

'e' for yaw right
/////////////////////////
*****************************************
For the app control, there are two apps. The top view of the plane should be the flight states. buttons match the serial monitor commands.

The other app has letters that match the paired motor controls. These apps do not control individual motors for the safety of the model.
*****************************************

The landing gear had issues despite it being simple code. It would freeze up the serial monitor. Could be a parts issue, but we aren't sure.
'G' to bring the landing gear up
'g' to bring the landing gear down 
