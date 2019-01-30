#include "main.h"

using namespace pros;

//main Auton
void mainAuton(int side){
  flySet(200);
  intake(200);

  driveProfile.setTarget("38");
  driveProfile.waitUntilSettled();
  drive.setMaxVelocity(175);
  if (side == -1) {
    driveProfile.setTarget("34 red", true);
    driveProfile.waitUntilSettled();
  } else {
    driveProfile.setTarget("34 blue", true);
    driveProfile.waitUntilSettled();
  }
  delay(500);
  drive.setMaxVelocity(200);

  driveTurn(90, side, 85);

  delay(1400);
  intake(0);
  index(200); // shoot
  delay(700);
  index(-1);
  delay(20);

  intake(200); // start pushing ball into indexer

  driveProfile.setTarget("28");
  driveProfile.waitUntilSettled(); // aim middle

  index(200); // 2nd shoot
  delay(750);

  flySet(0); // stop shooting devices
  intake(0);
  index(0);

  driveProfile.removePath("38"); // remove old paths for memory
  driveProfile.removePath("34 red"); // remove old paths for memory
  driveProfile.removePath("34 blue"); // remove old paths for memory

  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{18_in, 0_ft, 0_deg}},
    "18"
  );

  driveTurn(14, side, 100);
  delay(500);
  driveProfile.setTarget("18");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("18", true); // move into flag
  driveProfile.waitUntilSettled();

  driveTurn(-112, side, 100);
  delay(800);

  intake(-200);
  drive.setMaxVelocity(150);
  driveProfile.setTarget("28");
  driveProfile.waitUntilSettled();

  driveTurn(85, side, 100);
  driveDist(36, 200);
  delay(3000);

  robotStop();
}

void backAuton(int side){

}

void skillsAuton(int side){

}
