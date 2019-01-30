#include "main.h"

void opcontrol() {
	float left, right;
	lift.tarePosition();
	//1 controller
	while (1){
		while (duo == false){
			//Drive - WIP
			left = master.getAnalog(ControllerAnalog::leftY);
			right = master.getAnalog(ControllerAnalog::rightY);

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

			//lift
			if (master.getDigital(ControllerDigital::R1) == true) {
				lift.setMaxVelocity(150);
				lift.setTarget(900);
			} else if (master.getDigital(ControllerDigital::R2) == true) {
				lift.setMaxVelocity(85);
				lift.setTarget(220);
			} else {
				lift.setMaxVelocity(180);
				lift.setTarget(0);
			}

			pros::delay(20);
		}


		//2 controllers
		while (duo == true) {
			//Drive - WIP
			left = partner.getAnalog(ControllerAnalog::leftY);
			right = partner.getAnalog(ControllerAnalog::rightY);

			drive.tank(left * .9, right * .9);

			while(partner.getDigital(ControllerDigital::R1) == true){
				left_back.moveRelative(0, 0);
				left_front.moveRelative(0, 0);
				right_back.moveRelative(0, 0);
				right_front.moveRelative(0, 0);
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
				lift.setMaxVelocity(150);
				lift.setTarget(900);
			} else if (master.getDigital(ControllerDigital::R2) == true) {
				lift.setMaxVelocity(85);
				lift.setTarget(220);
			} else {
				lift.setMaxVelocity(180);
				lift.setTarget(0);
			}

			pros::delay(20);
		}
	}
}
