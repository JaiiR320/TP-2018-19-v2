#include "main.h"

void opcontrol() {
	float left, right, left_pwr, right_pwr;
	int side = 1;
	//1 controller
	while (1){
		while (duo == false){
			//Side Selection - WIP
			if(master.getDigital(ControllerDigital::up) == true){
				side = 1;
			} else if(partner.getDigital(ControllerDigital::up) == true){
				side = -1;
			}

			//Drive
			left = master.getAnalog(ControllerAnalog::leftY);
			right = master.getAnalog(ControllerAnalog::rightY);

			if (side == 1){
				left_pwr = left * side;
				right_pwr = right * side;
			} else {
				left_pwr = right * side;
				right_pwr = left * side;
			}

			drive.tank(left, right);

			//Flywheel
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
			if (master.getDigital(ControllerDigital::R1) == true) {
				index_mtr.moveVelocity(200);
			} else if (master.getDigital(ControllerDigital::R2) == true) {
				index_mtr.moveVelocity(-200);
			} else {
				index_mtr.moveVelocity(0);
			}

			pros::delay(20);
		}


		//2 controllers
		while (duo == true) {
			//Side Selection - WIP
			if(partner.getDigital(ControllerDigital::up) == true){
				side = 1;
			} else if(partner.getDigital(ControllerDigital::up) == true){
				side = -1;
			}

			//Drive - WIP
			left = partner.getAnalog(ControllerAnalog::leftY);
			right = partner.getAnalog(ControllerAnalog::rightY);
			drive.tank(left, right);

			//flywheel - OK
			if (master.getDigital(ControllerDigital::Y) == true) {
				flywheel.setTarget(200);
			} else if (master.getDigital(ControllerDigital::B) == true) {
				flywheel.setTarget(0);
			}

			//intake - WIP
			if (master.getDigital(ControllerDigital::L1) == true) {
				intake_mtr.moveVelocity(200);
			} else if (master.getDigital(ControllerDigital::L2) == true) {
				intake_mtr.moveVelocity(-200);
			} else {
				intake_mtr.moveVelocity(0);
			}

			//index
			if (master.getDigital(ControllerDigital::R1) == true) {
				index_mtr.moveVelocity(200);
			} else if (master.getDigital(ControllerDigital::R2) == true) {
				index_mtr.moveVelocity(-200);
			} else {
				index_mtr.moveVelocity(0);
			}

			pros::delay(20);
		}
	}
}
