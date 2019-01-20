#ifndef ROBOT_H
#define ROBOT_H

#include "okapi/api.hpp"
using namespace okapi;

//Controllers
extern Controller master;
extern Controller partner;

//Drive Motor definitions
extern Motor left_front;
extern Motor right_front;
extern Motor left_back;
extern Motor right_back;

extern Motor flywheel_mtr;

extern Motor lift_mtr;

extern Motor intake_mtr;

extern Motor index_mtr;

//Okapi controllers
extern ChassisControllerIntegrated drive;
extern AsyncMotionProfileController driveProfile;
extern AsyncVelIntegratedController flywheel;
extern AsyncLinearMotionProfileController lift;

//Motion Profile Testing
void robot_kinematics(int seconds);

void turn(double degrees, int speed);

void dist(float dist, int speed);

void maxVel(int left, int right);

void robotStop();

#endif
