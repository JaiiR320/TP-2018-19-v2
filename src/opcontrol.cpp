#include "main.h"

void opcontrol() {
	float left, right;
	//1 controller
	while (1){
		while (duo == false){
			//Drive - WIP
			left = partner.getAnalog(ControllerAnalog::leftY);
			right = partner.getAnalog(ControllerAnalog::rightY);

			left *= abs(left) / 100;
			right *= abs(right) / 100;

			drive.tank(left, right);

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

			//index
			if (master.getDigital(ControllerDigital::X) == true) {
				index_mtr.moveVelocity(200);
			} else if (master.getDigital(ControllerDigital::A) == true) {
				index_mtr.moveVelocity(-200);
			} else {
				index_mtr.moveVelocity(0);
			}

			//lift Position
			if (master.getDigital(ControllerDigital::R1) == true) {
				lift.setTarget(2);
			} else if (master.getDigital(ControllerDigital::R2) == true) {
				lift.setTarget(1);
			} else {
				lift.setTarget(0);
			}

			pros::delay(20);
		}


		//2 controllers
		while (duo == true) {
			//Drive - WIP
			left = partner.getAnalog(ControllerAnalog::leftY);
			right = partner.getAnalog(ControllerAnalog::rightY);

			left *= abs(left) / 100;
			right *= abs(right) / 100;

			drive.tank(left, right);

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

			//index
			if (master.getDigital(ControllerDigital::X) == true) {
				index_mtr.moveVelocity(200);
			} else if (master.getDigital(ControllerDigital::A) == true) {
				index_mtr.moveVelocity(-200);
			} else {
				index_mtr.moveVelocity(0);
			}

			//lift Position
			if (master.getDigital(ControllerDigital::R1) == true) {
				lift.setTarget(2);
			} else if (master.getDigital(ControllerDigital::R2) == true) {
				lift.setTarget(1);
			} else {
				lift.setTarget(0);
			}

			pros::delay(20);
		}
	}
}
