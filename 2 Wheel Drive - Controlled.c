#pragma config(Motor,  port1,            rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port10,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
// Here, each of the motors are initialized and configured.
// Notice how the names that each motor is binded to is used later in the code.

// This is the main task - everything inside here runs when the robot starts.
task main(){
	// This is a crude infinite loop - everything inside the while loop is repeated forever.
	while (1 == 1){
		motor[rightMotor] = -vexRT[Ch2]; // binds the right motor to the third joystick channel
		motor[leftMotor] = -vexRT[Ch3]; // binds the left motor to the second joystick channel
	}
}
