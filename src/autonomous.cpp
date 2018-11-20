#include "main.h"

void autonomous() {
  drive.moveDistance(1_ft);
  drive.turnAngle(90_deg);
  flywheel.setTarget(200);
  intake_mtr.moveVelocity(200);
}
