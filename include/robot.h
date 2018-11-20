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

extern Motor flywheel1;
extern Motor flywheel2;

extern Motor lift_mtr;

extern Motor intake_mtr;

//Okapi controllers
extern ChassisControllerIntegrated drive;
extern AsyncVelIntegratedController flywheel;
extern AsyncPosIntegratedController lift;

#endif
