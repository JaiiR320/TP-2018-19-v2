#include "main.h"

void mainPathGen(int color){
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{39_in, 0_ft, 0_deg}}, // The next point in the profile, 3 feet forward
    "main_1" // Profile name
  );
}

void secondPathGen(int color){

}

void safePathGen(int color){

}
