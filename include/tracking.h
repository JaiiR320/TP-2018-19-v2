#ifndef TRACKING_H
#define TRACKING_H

#include "okapi/api.hpp"
#include "api.h"

using namespace okapi;

extern ADIGyro gyroA;
extern ADIGyro gyroB;

extern double thetaT, thetaA, dtheta;
extern int dir;

extern pros::task_fn_t update(void);
extern pros::Task tracking;

#endif
