#ifndef AUTON_H
#define AUTON_H

#include "okapi/api.hpp"
using namespace okapi;

extern int auton;
extern int color;

void mainAuton(int side);
void secondAuton(int side);
void safeAuton(int side);

#endif
