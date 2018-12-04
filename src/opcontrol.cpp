#include "main.h"

void opcontrol() {
	float left, right;
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

			//Drive - WIP
			left = master.getAnalog(ControllerAnalog::leftY);
			right = master.getAnalog(ControllerAnalog::rightY);
			drive.tank(left, right);

			//flywheel - OK
			if (master.getDigital(ControllerDigital::Y) == true) {
				flywheel.setTarget(185);
			} else if (master.getDigital(ControllerDigital::B) == true) {
				flywheel.setTarget(0);
			}

			//intake - WIP
			if (master.getDigital(ControllerDigital::L1) == true) {
				intake_mtr.moveVelocity(120);
			} else if (master.getDigital(ControllerDigital::L2) == true) {
				intake_mtr.moveVelocity(-120);
			} else {
				intake_mtr.moveVelocity(0);
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
				flywheel.setTarget(185);
			} else if (master.getDigital(ControllerDigital::B) == true) {
				flywheel.setTarget(0);
			}

			//intake - WIP
			if (master.getDigital(ControllerDigital::L1) == true) {
				intake_mtr.moveVelocity(120);
			} else if (master.getDigital(ControllerDigital::L2) == true) {
				intake_mtr.moveVelocity(-120);
			}

			pros::delay(20);
		}
	}
}
