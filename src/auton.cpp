#include "main.h"

int Acolor = 1;
int Aauton = 1;

//main Auton
void mainAuton(int side){
  //3 flags + cap and mid low flag
  flywheel.setTarget(200);
  intake_mtr.moveVelocity(200);
  driveProfile.setTarget("to_cap");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("to_cap_ball");
  driveProfile.waitUntilSettled(); // move to first cap
  pros::delay(500);

  driveProfile.setTarget("to_cap", true);
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("flag_backup", true);
  driveProfile.waitUntilSettled(); // back up to wall
  pros::delay(500);

  drive.setMaxVelocity(100);
  if(side == -1){
    drive.turnAngle(-93_deg); // turn towards flags
  } else {
    drive.turnAngle(93_deg);
  }
  pros::delay(700);

  driveProfile.setTarget("6_in"); // move closer for top flag
  driveProfile.waitUntilSettled();

  intake_mtr.moveVelocity(20); // shoot
  index_mtr.moveVelocity(200);
  pros::delay(400);
  index_mtr.moveVelocity(0);

  drive.setMaxVelocity(150);
  driveProfile.setTarget("6_in"); // move closer for top flag
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("middle_aim"); // aim for middle
  driveProfile.waitUntilSettled();

  intake_mtr.moveVelocity(200);
  index_mtr.moveVelocity(200);
  pros::delay(1000); // shoot

  intake_mtr.moveVelocity(0);
  index_mtr.moveVelocity(0); // stop shootin system
  flywheel.setTarget(0);

  driveProfile.setTarget("middle_aim"); // flag move
  driveProfile.waitUntilSettled();

  if(side == -1){
    drive.turnAngle(50_deg); // turn into bottom flag
  } else {
    drive.turnAngle(-50_deg);
  }

  drive.moveDistance(4_in); // drive into bottom flag
}

//Second Auton
void secondAuton(int side){
  robot_kinematics(3);
}

//Cheese Auton
void safeAuton(int side){
  flywheel.setTarget(100);
  intake_mtr.moveVelocity(200);
  driveProfile.setTarget("to_cap");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("to_cap_ball");
  driveProfile.waitUntilSettled(); // move to first cap
  pros::delay(500);

  intake_mtr.moveVelocity(0);
  index_mtr.moveVelocity(200); // shoot behind othor robot
  pros::delay(700);
  index_mtr.moveVelocity(0);
  flywheel.setTarget(200);

  intake_mtr.moveVelocity(200);
  driveProfile.setTarget("middle_aim", true); // line up with cap
  driveProfile.waitUntilSettled();

  drive.setMaxVelocity(100);
  if(side == -1){
    drive.turnAngle(-93_deg); // turn towards cap
  } else {
    drive.turnAngle(93_deg);
  }
  pros::delay(700);
  drive.setMaxVelocity(150);

  intake_mtr.moveVelocity(-200);
  driveProfile.setTarget("6_in");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("6_in", true); // flip cap
  driveProfile.waitUntilSettled();
  intake_mtr.moveVelocity(0);

  drive.setMaxVelocity(100);
  if(side == -1){
    drive.turnAngle(-93_deg); // turn towards cap
  } else {
    drive.turnAngle(93_deg);
  }
  pros::delay(700);
  drive.setMaxVelocity(150);

  driveProfile.setTarget("2_ft", true);
  driveProfile.waitUntilSettled();

  drive.setMaxVelocity(100);
  if(side == -1){
    drive.turnAngle(93_deg); // turn towards cap
  } else {
    drive.turnAngle(-93_deg);
  }
  pros::delay(700);
  drive.setMaxVelocity(150);

  index_mtr.moveVelocity(200);
  intake_mtr.moveVelocity(200);
}
