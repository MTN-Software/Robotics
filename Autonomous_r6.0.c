#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IRseeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     distanceSensor, sensorSONAR)
#pragma config(Motor,  motorA,          rotationMotor, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     extentionMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     flagMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     leftdrive,     tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     rightdrive,    tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     liftMotor,     tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    verticalArm,          tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    GPM,                  tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    verticalArm2,         tServoStandard)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "\\GlobVars.h";
#include "\\GlobFuncs.c";

task main()
{
	/*
	Close GPM.
	Lift arm up to position servo 1 = 250 and servo 2 = 5.
	Spin the turntable 90 deg.
	Extend arm at 40% power for 2 sec.
	Drive forward until the encoder count is x.
	Stop motors.
	Open GPM
	Drive forward until the encoder count is y
	*/

	// these variables serve no purpose other than being placeholders
	//int NinetyDegrees = 90;
	int x = 1000; // changeable
	int y = 1000; // changeable
	int rotationVal = 90;  //changeable

	// autonomous



	motor[GPM] = 130;		// Close Servo
	servo[verticalArm] = 5;		// Lift arm up to 5
	servo[verticalArm2] = 250;	// Lift arm up to 250
	while (nMotorEncoder[rotationMotor] < rotationVal)		// Repeatedly Check if the motor encoder value is less than the rotation val
	{
		motor[rotationMotor] = 75;			// Power the motor
	}
	motor[rotationMotor] = 0;					// Set the rotation motor's power to 0

	// Power the extension motor for 2 seconds
	motor[extentionMotor] = 40;
	wait1Msec(2000);
	motor[extentionMotor] = 0;

	while (nMotorEncoder[leftdrive] < x)		// While the leftdrive's motor encoder reads less than x
	{
		motor[leftdrive] = 75;								// Power the leftdrive
		motor[rightdrive] = 75;								// Power the rightdrive
	}

	motor[leftdrive] = 0;										// Set the leftdrive's motor power to 0
	motor[rightdrive] = 0;									// Set the rightdrive's motor power to 0
	wait1Msec(500);													// Wait 1/2 of a second

	motor[GPM] = 177;												// Set GPM's power to 177 (open it)
	wait1Msec(500);													// Wait 1/2 of a second

	nMotorEncoder[leftdrive] = 0;						// Reset the leftdrive's motor encoder value
	while (nMotorEncoder[leftdrive] < y)		// While the leftdrive's motor encoder value reads less than y
	{
		motor[leftdrive] = 75;								// Power leftdrive
		motor[rightdrive] = 75;								// Power rightdrive
	}

	motor[leftdrive] = 0;										// Set leftdrive's motor power to 0
	motor[rightdrive] = 0;									// Set rightdrive's motor power to 0

}
