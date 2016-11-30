#include "stdafx.h"
#include "../../../std_lib_facilities.h"
#include "Battery.h"
#include <iostream>
#include <iomanip>

using namespace std;

string Battery::print() {
	//cout << "\tType: " << type << setw(8) << " | Name: " << name << setw(8) << " | Part Number: " << partNum << endl;
	string s = "Type: " + getType() + "  Name: " + getName() + " PartNum: " + getPartNum();
	return s;
};
string Battery::getType() {
	return type;
};
string Battery::getName() {
	return name;
};
string Battery::getPartNum(){
    return partNum;
}
double Battery::getEnergy(){
    return energy;
}
double Battery::getMaxPower(){
    return maxPower;
}
