#include "main.h"

//Controllers
Controller master = ControllerId::master;
Controller partner = ControllerId::partner;

Motor left_front = 2_mtr;
Motor left_back = 1_mtr;
Motor right_front = 4_rmtr;
Motor right_back = 3_rmtr;

Motor flywheel_mtr = 6_rmtr;

Motor lift_mtr = 10_mtr;

Motor intake_mtr = 7_mtr;

Motor index_mtr = 9_mtr;

//drive train control
ChassisControllerIntegrated drive = ChassisControllerFactory::create(
	{left_front, left_back},
	{right_front, right_back},
	AbstractMotor::gearset::green,
	{4_in, 14.5_in}
);

//Motion profile
AsyncMotionProfileController driveProfile = AsyncControllerFactory::motionProfile(
	1.06, //Max Linear velocity m/s (calculated based off rpm of motor)
  4, //max acceleration m/s/s (kailas 4) (me 14.2)
  10, //max jerk m/s/s/s (kailas 10) (me 1400)
	drive //chassis
);

//flywheel control
AsyncVelIntegratedController flywheel = AsyncControllerFactory::velIntegrated(flywheel_mtr);

//lift control
AsyncPosIntegratedController lift = AsyncControllerFactory::posIntegrated(lift_mtr);

void driveTurn(int degrees, int side, int speed){ //Pos degrees turns right
	double arclength = 2 * 3.1415926 * 7.25 * (double(degrees) / 360);

	double dist = (arclength / 12.566) * 360;

  dist *= side;

	left_back.moveRelative(dist, speed);
	left_front.moveRelative(dist, speed);
	right_back.moveRelative(-dist, speed);
	right_front.moveRelative(-dist, speed);
}

void driveDist(float dist, int speed){//in inches
  dist = ((dist / 12.566) * 360);

  left_front.moveRelative(dist, speed);
	left_back.moveRelative(dist, speed);
	right_front.moveRelative(dist, speed);
	right_back.moveRelative(dist, speed);
}

void intake(int speed){
	intake_mtr.moveVelocity(speed);
}

void index(int speed){
	index_mtr.moveVelocity(speed);
}

void flySet(int speed){
	flywheel.setTarget(speed);
}

void liftPos(int pos){
	if (pos == 2) {
		lift.setTarget(900);
	} else if (pos == 1) {
		lift.setTarget(220);
	} else if (pos == 0) {
		lift.setTarget(0);
	}
}

//Stop entire robot
void robotStop () {
	drive.stop();
	intake_mtr.moveVelocity(0);
	index_mtr.moveVelocity(0);
	flywheel.setTarget(0);
}
