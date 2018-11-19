#include "main.h"

Controller master;

auto drive = ChassisControllerFactory::create({left_front, left_back},
	{right_front, right_back},
	AbstractMotor::gearset::green,
	{4_in, 14_in});

void opcontrol() {
	int left, right;
	while (true) {

		left = master.getAnalog(ControllerAnalog::leftY);
		right = master.getAnalog(ControllerAnalog::rightY);
		drive.tank(left, right);

		pros::Task::delay(20);
	}
}
