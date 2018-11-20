#include "main.h"

//Controllers
Controller master = ControllerId::master;
Controller partner = ControllerId::partner;

Motor left_front = 1_mtr;
Motor right_front = 2_rmtr;
Motor left_back = 3_mtr;
Motor right_back = 4_rmtr;

Motor flywheel1 = 5_mtr;
Motor flywheel2 = 6_rmtr;

Motor lift_mtr = 7_mtr;

Motor intake_mtr = 8_mtr;

//drive train control
ChassisControllerIntegrated drive = ChassisControllerFactory::create({left_front, left_back},
	{right_front, right_back},
	AbstractMotor::gearset::green,
	{4_in, 14_in});

//lift control
AsyncPosIntegratedController lift = AsyncControllerFactory::posIntegrated(intake_mtr);

//flywheel control
MotorGroup flywheel_mtrs({flywheel1, flywheel2});
AsyncVelIntegratedController flywheel = AsyncControllerFactory::velIntegrated(flywheel_mtrs);
