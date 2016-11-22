#include "stdafx.h"
#include "../../../std_lib_facilities.h"
#include "Locomotor.h"
#include <iostream>
#include <iomanip>

using namespace std;

string Locomotor::print() {
	//cout << "\tType: " << type << setw(8) << " | Name: " << name << setw(8) << " | Part Number: " << partNum << endl;
	return "";
}
string Locomotor::getType() {
	return type;
};
string Locomotor::getName() {
	return name;
};
string Locomotor::getPartNum(){
    return partNum;
}
int Locomotor::getMaxSpeed(){
    return maxSpeed;
}
