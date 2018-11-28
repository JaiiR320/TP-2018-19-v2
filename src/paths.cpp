#include "main.h"

void mainPathGen(int color){
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{3_ft, color * 0_ft, 0_deg}}, // The next point in the profile, 3 feet forward
    "main_1" // Profile name
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg}},
    "main_2"
  );
}

void secondPathGen(int color){
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{3_ft, color * 0_ft, 0_deg}},
    "second_1"
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg}},
    "second_2"
  );
}

void safePathGen(int color){
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{3_ft, color * 0_ft, 0_deg}},
    "safe_1"
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg}},
    "safe_2"
  );
}
