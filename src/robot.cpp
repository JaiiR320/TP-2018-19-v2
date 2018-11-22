#include "main.h"

//Controllers
Controller master = ControllerId::master;
Controller partner = ControllerId::partner;

Motor left_front = 1_mtr;
Motor right_front = 2_rmtr;
Motor left_back = 3_mtr;
Motor right_back = 4_rmtr;

Motor flywheel1 = 5_mtr;
Motor flywheel2 = 6_rmtr;

Motor lift_mtr = 7_mtr;

Motor intake_mtr = 8_mtr;

//drive train control
ChassisControllerIntegrated drive = ChassisControllerFactory::create(
	{left_front, left_back},
	{right_front, right_back},
	AbstractMotor::gearset::green,
	{4_in, 14_in}
);

//Motion profile
AsyncMotionProfileController driveProfile = AsyncControllerFactory::motionProfile(
  1.0, //Max Linear velocity m/s
  1.0, //max acceleration m/s/s
  1.0, //max jerk m/s/s/s
  drive //chassis
);

//lift control
AsyncPosIntegratedController lift = AsyncControllerFactory::posIntegrated(intake_mtr);

//flywheel control
MotorGroup flywheel_mtrs({flywheel1, flywheel2});
AsyncVelIntegratedController flywheel = AsyncControllerFactory::velIntegrated(flywheel_mtrs);


//Motion Profiling Testing
void robot_kinematics(int seconds){
	double pos[seconds * 10];
	double vel[seconds * 10];
	double acl[seconds * 10];
	double jrk[seconds * 10];

	double max_vel;
	double max_acl;
	double max_jrk;
	vel[0] = 0;
  acl[0] = 0;
	jrk[0] = 0;

	drive.forward(1);

	for (size_t i = 0; i < seconds * 10; i++) {
		pos[i] = left_back.getPosition();
		pros::delay(10);
	}

	drive.stop();

	for (size_t i = 1; i < seconds * 10; i++) {
		vel[i] = pos[i] - pos[i - 1];
		if (vel[i] < vel[i - 1]) {
			max_vel = vel[i];
  	}
		pros::delay(10);
	}
	for (size_t i = 1; i < seconds * 10; i++) {
		acl[i] = vel[i] - vel[i - 1];
		if (acl[i] < acl[i - 1]) {
			max_vel = acl[i];
		}
		pros::delay(10);
	}
	for (size_t i = 1; i < seconds * 10; i++) {
		jrk[i] = acl[i] - acl[i - 1];
		if (jrk[i] < jrk[i - 1]) {
			max_vel = jrk[i];
		}
		pros::delay(10);
	}

	std::cout << "Max Vel:   " << '\n';
	std::cout << "Max Accel: " << '\n';
	std::cout << "Max Jerk:  " << '\n';
}
