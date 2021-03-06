#pragma config(Sensor, dgtl1,           sonarSensor,       sensorSONAR_cm)
#pragma config(Motor,  port1,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port6,           clawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Here, each of the motors are initialized and configured.
// Notice how the names that each motor is binded to is used later in the code.

// This is the main task - everything inside here runs when the robot starts.
task main(){
	// This is a crude infinite loop - everything inside the while loop is repeated forever.
	int speed;
	int sonar_value;
	int distance = 25;

	while (1==1){

		sonar_value = SensorValue(sonarSensor);

		bLCDBacklight = true;
		clearLCDLine(0);                          /* Display the    */
    displayLCDPos(0,0);                       /* reading of the */
    displayNextLCDString("Sonar:");          /* Sonar Sensor   */
    displayNextLCDNumber(sonar_value);        /* on line 0.     */
    displayNextLCDString(" cm");

		if (sonar_value < 0){
				speed = 127;
		}
		else {
      speed = (sonar_value - distance)*2;     // Move the robot at a speed proportional to how far off its desired distance it currently is
    }

		motor[leftMotor]  = speed;
    motor[rightMotor] = speed;
	}
}
