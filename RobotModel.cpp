#include "stdafx.h"
#include "../../../std_lib_facilities.h"
#include "RobotModel.h"
#include "RobotPart.h"
#include "Head.h"
#include "Arm.h"
#include "Torso.h"
#include "Battery.h"
#include "Locomotor.h"
#include <vector>

using namespace std;

string RobotModel::print() {
	//cout << "\tName: " << name << "\tModel Number: " << modelNum << "\n\t\tHead: " << parts[0]->getName() << "\n\t\tArm: " << parts[1]->getName() << "\n\t\tTorso: " << parts[2]->getName() << "\n\t\tBattery: " << parts[3]->getName() << "\n\t\tLocomotor: " << parts[4]->getName() << endl;
	string s = "Name: " + name + "\tModel Number: " + modelNum + "\n\tHead: " + parts[0]->getName() + "\n\tArm: " + parts[1]->getName() + "\n\tTorso: " + parts[2]->getName() + "\n\tBattery: " + parts[3]->getName() + "\n\tLocomotor: " + parts[4]->getName() + "\n";
	return s;
}
void RobotModel::setPrice() {
	price = 0;
	for (int i = 0; i < 5; i++) {
		price += parts[i]->getCost();
	}
}
void RobotModel::printBasic(){
	cout << "Name: " << name << " | Model Number: " << modelNum << endl;
}
