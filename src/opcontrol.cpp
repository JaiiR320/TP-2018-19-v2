#include "main.h"

void opcontrol() {
	float left, right;
	int side = 1;
	while (true) {

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
