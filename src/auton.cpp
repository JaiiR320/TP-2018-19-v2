#include "main.h"

int Acolor = 1;
int Aauton = 1;

//main Auton
void mainAuton(int side){
  //3 flags + cap and mid low flag
  flywheel.setTarget(200);
  intake_mtr.moveVelocity(200); // start intake

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
  drive.turnAngle(side * 80_deg); // turn towards flags
  pros::delay(700);

  drive.setMaxVelocity(200);
  driveProfile.setTarget("6_in"); // move closer for top flag
  driveProfile.waitUntilSettled();

  intake_mtr.moveVelocity(200); // shoot
  index_mtr.moveVelocity(200);
  pros::delay(400);
  index_mtr.moveVelocity(0);

  driveProfile.setTarget("6_in"); // move closer for middle flag
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("middle_aim"); // aim for middle
  driveProfile.waitUntilSettled();

  intake_mtr.moveVelocity(200);
  index_mtr.moveVelocity(200); // shoot
  pros::delay(700);

  intake_mtr.moveVelocity(0);
  index_mtr.moveVelocity(0); // stop shooting system
  flywheel.setTarget(0);

  drive.setMaxVelocity(100);
  drive.turnAngle(side * -50_deg); // turn into bottom flag
  pros::delay(700);

  drive.setMaxVelocity(100);
  drive.turnAngle(side * 50_deg); // turn out of flag
  pros::delay(700);

  drive.setMaxVelocity(200);
  driveProfile.setTarget("towards_flag", true); // aim to other cap
  driveProfile.waitUntilSettled();

  drive.setMaxVelocity(100);
  drive.turnAngle(side * -80_deg); // turn towards flags
  pros::delay(700);

  intake_mtr.moveVelocity(-200); // drive into cap & flip
  drive.setMaxVelocity(50);
  drive.moveDistance(24_in);
  pros::delay(2000);

  robotStop();

  Acolor = 0;
  Aauton = 0;
}





//Second Auton
void secondAuton(int side){
  //1 cap, 2 flags park
  flywheel.setTarget(200);
  intake_mtr.moveVelocity(200); // start intake

  driveProfile.setTarget("to_cap");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("to_cap_ball");
  driveProfile.waitUntilSettled(); // move to first cap
  pros::delay(500);

  driveProfile.setTarget("flag_backup", true);
  driveProfile.waitUntilSettled(); // back up to platform
  pros::delay(500);

  drive.setMaxVelocity(100);
  drive.turnAngle(side * 65_deg); // turn towards middle flags
  pros::delay(700);
  drive.setMaxVelocity(200);

  intake_mtr.moveVelocity(200);
  index_mtr.moveVelocity(200); // shoot
  pros::delay(1200);

  intake_mtr.moveVelocity(0);
  index_mtr.moveVelocity(0); // stop shooting system
  flywheel.setTarget(0);

  drive.setMaxVelocity(100);
  drive.turnAngle(side * 25_deg); // turn towards middle flags
  pros::delay(700);
  drive.setMaxVelocity(200);

  drive.moveDistance(30_in);
  pros::delay(1500);

  robotStop();

  Acolor = 0;
  Aauton = 0;
}





//Cheese Auton
void safeAuton(int side){
  flywheel.setTarget(100);
  intake_mtr.moveVelocity(200); // start intake

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
    drive.turnAngle(-86_deg); // turn towards cap
  } else {
    drive.turnAngle(86_deg);
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
    drive.turnAngle(-86_deg); // turn towards cap
  } else {
    drive.turnAngle(86_deg);
  }
  pros::delay(700);
  drive.setMaxVelocity(150);

  driveProfile.setTarget("2_ft", true);
  driveProfile.waitUntilSettled();

  drive.setMaxVelocity(100);
  if(side == -1){
    drive.turnAngle(86_deg); // turn towards cap
  } else {
    drive.turnAngle(-86_deg);
  }
  pros::delay(700);
  drive.setMaxVelocity(150);

  index_mtr.moveVelocity(200);
  intake_mtr.moveVelocity(200);

  robotStop();

  Acolor = 0;
  Aauton = 0;
}
