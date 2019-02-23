#include "main.h"

ADIGyro gyroA(7, .1);
ADIGyro gyroB(8, .1);

double thetaT = 0;
double thetaA = 0;
double dTheta;
int dir = 1;

void update(void* params){
  while (1) {
    if (gyroA.get() < 0) {
      dir = -1;
    } else {
      dir = 1;
    }
    thetaA = (fabs(gyroA.get()) + fabs(gyroB.get()) / 2) * dir;
    dtheta = thetaA - thetaT;
    pros::delay(1);
  }
}

pros::Task tracking(update);
