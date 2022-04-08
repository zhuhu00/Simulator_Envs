#include <ros.h>
#include "rover_udes/CamCommand.h"
#include "kg_encoder.h" //uses timer2
#include <Servo.h>

// Servomotors
/*The vertical servo (up-down) uses Arduino pin 7
  The horizontal servo (left-right) uses Arduino pin 6
  The encoder for the horizontal servo has to be plugged in Arduino pin A0 */
Servo verticalCamServo; 
Servo horizontalCamServo;
Encoder horizontalServoControl(A0);
int horizontalServoGoal = 0;
bool currentlyTakingPanorama = false;

// ROS node
ros::NodeHandle nh;

// ROS callback
void callback_camServo (const rover_udes::CamCommand &angles)
{
	/* This will be used for implementing constant intervals picture taking for panoramas */

	// if (angles.is_pano and !currentlyTakingPanorama)
	// {
	// 	currentlyTakingPanorama = true;
	// }

	// if (currentlyTakingPanorama)
	// {
	// 	horizontalServoGoal = 0;
	// 	verticalCamServo.writeMicroseconds((int)1500);
	// }
	// else
	// {
		horizontalServoGoal = angles.cam_horizontal;
		verticalCamServo.writeMicroseconds((int)1500+angles.cam_vertical*500/90);
	// }
}

// servoHorizontal
void updateHorizontalCamServo()
{
	const float encoderRotationsForEachServoRotation = 48.0/16.0;
	float position = horizontalServoControl.ReadAngle() / encoderRotationsForEachServoRotation;

	/* This will be used for implementing constant intervals picture taking for panoramas */

	// static bool panoramaBeginning = true;

	// if (currentlyTakingPanorama)
	// {
	// 	float initialPosition;
	// 	if (panoramaBeginning)
	// 	{
	// 		initialPosition = position;
	// 		panoramaBeginning = false;
	// 	}

	// 	if (position < (initialPosition + 360))
	// 	{
	// 		horizontalCamServo.writeMicroseconds(1600);
	// 	}
	// 	else
	// 	{
	// 		currentlyTakingPanorama = false;
	// 		panoramaBeginning = true;
	// 	}
	// }
	// else
	// {	
		int delta = horizontalServoGoal - position;
	
	/*  These two statements can be enabled for the camera to always use the shortest path to reach its goal,
	    but this could cause problems with the wires */
				// while (delta >= 180)delta -= 360;
				// while (delta < -180)delta += 360;
		int speed = 1500;
		if (delta > 5) speed = 1700;
		else if (delta > 0) speed = 1600;
		else if (delta < -5) speed = 1300;
		else if (delta < 0) speed = 1400;

		horizontalCamServo.writeMicroseconds(speed);
	// }
}

// Subcriber using callback callback_camServo
ros::Subscriber<rover_udes::CamCommand> ear ("cam_cmd",callback_camServo);

void setup()
{
	horizontalCamServo.attach(6);
	verticalCamServo.attach(7);
	Timer2Manager::add(updateHorizontalCamServo);

	Serial.begin(57600);
	nh.initNode();
	nh.subscribe(ear);
}

void loop()
{
	// Continuously updating the node
	nh.spinOnce();
}