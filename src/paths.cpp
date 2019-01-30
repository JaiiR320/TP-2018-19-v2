#include "main.h"

//Motion profiling
//Point{FORWARD, LEFT, CCLOCK}

void mainPathGen(){
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{38_in, 0_ft, 0_deg}}, // The next point in the profile, 3 feet forward
    "38" // Profile name
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{38_in, -7_in, 0_deg}},
    "34 red"
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{38_in, 7_in, 0_deg}},
    "34 blue"
  );
  driveProfile.generatePath({ // generate 28 inch path
    Point{0_ft, 0_ft, 0_deg},
    Point{28_in, 0_ft, 0_deg}},
    "28"
  );
}
