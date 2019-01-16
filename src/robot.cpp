#include "main.h"

//Controllers
Controller master = ControllerId::master;
Controller partner = ControllerId::partner;

Motor left_front = 1_mtr;
Motor left_back = 2_mtr;
Motor right_front = 3_rmtr;
Motor right_back = 4_rmtr;

Motor flywheel_mtr = 6_rmtr;

Motor lift_mtr = 10_mtr;

Motor intake_mtr = 7_mtr;

Motor index_mtr = 9_mtr;

//drive train control
ChassisControllerIntegrated drive = ChassisControllerFactory::create(
	{left_front, left_back},
	{right_front, right_back},
	AbstractMotor::gearset::green,
	{4_in, 14.25_in}
);

//Motion profile
AsyncMotionProfileController driveProfile = AsyncControllerFactory::motionProfile(
	1.064, //Max Linear velocity m/s (calculated based off rpm of motor)
  4, //max acceleration m/s/s (kailas 4) (me 14.2)
  10, //max jerk m/s/s/s (kailas 10) (me 1400)
	drive //chassis
);

void turn(double degrees, int speed){ //Pos degrees turns right
	double arclength = 2 * 3.1415926 * 7 * (degrees / 360);

	double dist = (arclength / 12.566) * 360;

	left_front.moveRelative(dist, speed);
	left_back.moveRelative(dist, speed);
	right_front.moveRelative(-dist, speed);
	right_back.moveRelative(-dist, speed);
}

void dist(float dist, int speed){//in inches
  dist = ((dist / 12.566) * 360);
  //encoder degrees = pathlength / circumferemce times 1 rotation
  //pathlength = encoder deg / 1 rotation times circumference

  left_front.moveRelative(dist + 12, speed);
	left_back.moveRelative(dist + 12, speed);
	right_front.moveRelative(dist, speed);
	right_back.moveRelative(dist, speed);
}

//lift control
AsyncPosIntegratedController lift = AsyncControllerFactory::posIntegrated(intake_mtr);

//flywheel control
AsyncVelIntegratedController flywheel = AsyncControllerFactory::velIntegrated(flywheel_mtr);


//Motion Profiling Testing
void robot_kinematics(int seconds){
	double pos[seconds * 100];
	double vel[seconds * 100];
	double acl[seconds * 100];
	double jrk[seconds * 100];

	double max_vel = 0;
	double max_acl = 0;
	double max_jrk = 0;
	vel[0] = 0;
    acl[0] = 0;
	jrk[0] = 0;

	drive.forward(1);

	for (size_t i = 1; i < seconds * 100; i++) {
		pos[i] = ((left_back.getPosition() / 360) * 0.31917);
		pros::delay(10);
	}

	drive.stop();

	for (size_t i = 1; i < seconds * 100; i++) {
		vel[i] = (pos[i] - pos[i - 1]) / .01;
		if (vel[i] > max_vel) {
			max_vel = vel[i];
  		}
		pros::delay(10);
	}

	for (size_t i = 1; i < seconds * 100; i++) {
		acl[i] = (vel[i] - vel[i - 1]) / .01;
		if (acl[i] > max_acl) {
			max_acl = acl[i];
		}
		pros::delay(10);
	}

	for (size_t i = 1; i < seconds * 100; i++) {
		jrk[i] = (acl[i] - acl[i - 1]) / .01;
		if (jrk[i] > max_jrk) {
			max_jrk = jrk[i];
		}
		pros::delay(10);
	}

	std::cout << "Max Vel:  " << max_vel << '\n';
	std::cout << "Max Acl:  " << max_acl << '\n';
	std::cout << "Max Jrk:  " << max_jrk << '\n';
}

//Stop entire robot
void robotStop () {
	drive.stop();
	intake_mtr.moveVelocity(0);
	index_mtr.moveVelocity(0);
	flywheel.setTarget(0);
}
