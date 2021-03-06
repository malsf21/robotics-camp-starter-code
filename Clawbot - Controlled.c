#pragma config(Motor,  port1,            rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port10,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port6,            clawMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port7,            armMotor,      tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
// Here, each of the motors are initialized and configured.
// Notice how the names that each motor is binded to is used later in the code.

// This is the main task - everything inside here runs when the robot starts.
task main(){
	// This is a crude infinite loop - everything inside the while loop is repeated forever.
	while (1 == 1){
		motor[rightMotor] = vexRT[Ch2]; // binds the right motor to the third joystick channel
		motor[leftMotor] = vexRT[Ch3]; // binds the left motor to the second joystick channel

		// This if structure controls the arm
		if (vexRT[Btn5U] == 1){ // if button 5U is pressed, do next action
			motor[armMotor] = -63; // sets arm motor to -127
		}
		else if (vexRT[Btn5D] == 1){ // else if button 5D is pressed, do next action
			motor[armMotor] = 63; // sets arm motor to 127
		}
		else{ // default action - this is very important! if not, the motors will lock after a single command
			motor[armMotor] = 0; // turns off arm motor
		}

		// This control flow is the exact same as the arm control flow, just applied to the claw and the 6U/6D buttons
		if (vexRT[Btn6U] == 1){
			motor[clawMotor] = 127;
		}
		else if (vexRT[Btn6D] == 1){
			motor[clawMotor] = -127;
		}
		else{
			motor[clawMotor] = 0;
		}
	}
}
