#include "main.h"

void mainPathGen(int color){
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{29_in, 0_ft, 0_deg}}, // The next point in the profile, 3 feet forward
    "to_cap" // Profile name
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{10_in, 0_ft, 0_deg}},
    "to_cap_ball"
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{10_in, 0_ft, 0_deg}},
    "unused"
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{6_in, 0_ft, 0_deg}},
    "6_in"
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{14_in, 0_ft, 0_deg}},
    "middle_aim"
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{9_in, 0_ft, 0_deg}},
    "flag_backup"
  );

  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{2_ft, 0_ft, 0_deg}}, // The next point in the profile, 3 feet forward
    "2_ft" // Profile name
  );

  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{1_ft, 1_ft, 90_deg}}, // The next point in the profile, 3 feet forward
    "circle" // Profile name
  );
}
