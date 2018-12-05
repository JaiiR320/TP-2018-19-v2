#include "main.h"
#include "okapi/api.hpp"

int color = 1;
int auton = 1;

void mainAuton(int side){
  //3 flags + cap and mid low flags
  flywheel.setTarget(200);
  intake_mtr.moveVelocity(200);
  driveProfile.setTarget("main_1");
  waitUntilSettled();
  driveProfile.setTarget("main_1", true);
  drive.turnAngle(side * 90_deg);



  /*
  driveProfile.setTarget("main_1");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("main_2");
  driveProfile.waitUntilSettled();
  */
}

void secondAuton(int side){


  /*
  driveProfile.setTarget("second_1");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("second_2");
  driveProfile.waitUntilSettled();
  */
}

void safeAuton(int side){


  /*
  driveProfile.setTarget("safe_1");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("safe_2");
  driveProfile.waitUntilSettled();
  */
}
