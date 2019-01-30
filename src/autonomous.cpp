#include "main.h"


void autonomous() {

  switch (Aauton) {
    case 1: mainAuton(Acolor);
    case 2: backAuton(Acolor);
    case 3: skillsAuton(Acolor);
  }
  pros::delay(99999);
}
