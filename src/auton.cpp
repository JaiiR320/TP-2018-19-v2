#include "main.h"

int Acolor = 0;
int Aauton = 0;

//main Auton
void mainAuton(int side){
  //3 flags + cap and mid low flag
  flywheel.setTarget(200);
  intake_mtr.moveVelocity(200); // start intake

  dist(39.0, 200);
  pros::delay(1700); // cap

  dist(-36.0, 200);
   pros::delay(1700); // back up
  if(Acolor == -1){
    dist(-4, 100);
    pros::delay(700);
  }


  turn(side * 90, 150); // turn towards flags
  pros::delay(500);

  dist(4, 100); // move closer for top flag
  pros::delay(500);

  intake_mtr.moveVelocity(0); // shoot
  index_mtr.moveVelocity(200);
  pros::delay(400);
  index_mtr.moveVelocity(0);

  dist(21, 100); // aim for middle flag
  pros::delay(650);

  intake_mtr.moveVelocity(200);
  index_mtr.moveVelocity(200); // shoot
  pros::delay(700);

  intake_mtr.moveVelocity(0);
  index_mtr.moveVelocity(0); // stop shooting system
  flywheel.setTarget(0);

  dist(32, 100);
  pros::delay(600);
  turn(side * -50, 100); // turn into flag
  pros::delay(400);
  dist(6, 100);
  pros::delay(600);
  dist(-6, 100);
  pros::delay(600);
  turn(side * 50, 100);
  pros::delay(400);
  dist(-42, 100);
  pros::delay(600);

  drive.setMaxVelocity(100);
  turn(side * -105, 150);
  pros::delay(800);
  if (Acolor == 1) {
    turn(side * -20, 100); // turn into flag
    pros::delay(400);
  }

  intake_mtr.moveVelocity(-200); // drive into cap & flip
  dist(24, 50);
  pros::delay(2000);
  drive.stop();
  Aauton = 0;
  Acolor = 0;
  pros::delay(10000);
  robotStop();
}





//Second Auton
void secondAuton(int side){
  //far side
  //3 flags + cap and mid low flag
  intake_mtr.moveVelocity(200); // start intake
  index_mtr.moveVelocity(200);

  dist(39.0, 200);
  pros::delay(1700); // cap

  turn(side * -85, 100);
  pros::delay(700);
  intake_mtr.moveVelocity(-200); // flip cap
  dist(24, 50);
  pros::delay(700);

  pros::delay(99999);
  robotStop();
  pros::delay(99999);

  Acolor = 0;
  Aauton = 0;
}





//Cheese Auton
void safeAuton(int side){
  intake_mtr.moveVelocity(200); // start intake
  index_mtr.moveVelocity(200);

  dist(39.0, 200);
  pros::delay(1700); // cap

  turn(side * -85, 100);
  pros::delay(700);
  intake_mtr.moveVelocity(-200); // flip cap
  dist(24, 50);
  pros::delay(700);

  robotStop();
  /*
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
  */
}
