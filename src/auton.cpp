#include "main.h"

int color = 0;
int auton = 0;

void mainAuton(int side){
  driveProfile.setTarget("main_1");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("main_2");
}

void secondAuton(int side){
  driveProfile.setTarget("second_1");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("second_2");
}

void safeAuton(int side){
  driveProfile.setTarget("safe_1");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("safe_2");
}
