#include "main.h"

void opcontrol() {
	int left, right;
	int side = 1;
	int target = 0;
	while (true) {

		robot_kinematics(3);

		/*  STANDARD Program
		//Side Selection
		if(master.getDigital(ControllerDigital::up) == true){
			side = 1;
		} else if(master.getDigital(ControllerDigital::up) == true){
			side = -1;
		}

		//Drive
		left = master.getAnalog(ControllerAnalog::leftY);
		right = master.getAnalog(ControllerAnalog::rightY);

		if(side == 1) {
			drive.tank(left, right);
		} else {
			drive.tank(-right, -left);
		}

		//flywheel
		if (master.getDigital(ControllerDigital::Y) == true) {
			flywheel.setTarget(200);
		} else if (master.getDigital(ControllerDigital::B) == true) {
			flywheel.setTarget(0);
		}

		//intake
		if (master.getDigital(ControllerDigital::L1) == true) {
			intake_mtr.moveVelocity(200);
		} else if (master.getDigital(ControllerDigital::L2) == true) {
			intake_mtr.moveVelocity(-200);
		} else {
			intake_mtr.moveVelocity(0);
		}

		//lift
		if (master.getDigital(ControllerDigital::R1) == true) {
			lift.setTarget(target);
		} else if (master.getDigital(ControllerDigital::R2) == true) {
			lift.setTarget(0);
		}
		*/
		pros::delay(20);
	}
}
