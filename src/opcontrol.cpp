#include "main.h"

void opcontrol() {
	float left, right;
	int side = 1;

	robot_kinematics(3);

	while (true) {

		//Side Selection
		if(partner.getDigital(ControllerDigital::up) == true){
			side = 1;
		} else if(partner.getDigital(ControllerDigital::up) == true){
			side = -1;
		}

		//Drive
		left = partner.getAnalog(ControllerAnalog::leftY);
		right = partner.getAnalog(ControllerAnalog::rightY);

		drive.tank(left, right);

		//flywheel
		if (master.getDigital(ControllerDigital::Y) == true) {
			flywheel.setTarget(185);
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
			lift.setTarget(180);
		} else if (master.getDigital(ControllerDigital::R2) == true) {
			lift.setTarget(0);
		}

		pros::delay(20);
	}
}
