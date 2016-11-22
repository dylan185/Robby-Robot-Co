#include "stdafx.h"
#include "../../../std_lib_facilities.h"
#include "RobotPart.h"
#include <iostream>
#include <iomanip>

using namespace std;

void RobotPart::addDescription() {
	cout << "Add a description:";
	getline(cin, description);
}
string RobotPart::print() {
	//cout << "this happened in robotPart.cpp. Oops" << endl;
	return "";
}
string RobotPart::getType() {
	return "None";
}
string RobotPart::getName() {
	return name;
};
double RobotPart::getCost() {
	return cost;
}
double RobotPart::getWeight() {
	return weight;
}
string RobotPart::getPartNum(){
    return partNum;
}
int RobotPart::num_compartments(){
    return 0;
}

int RobotPart::getMaxSpeed(){
    return 0;
}

double RobotPart::getEnergy(){
    return 0;
}

double RobotPart::getMaxPower(){
    return 0;
}
