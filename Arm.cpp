#include "stdafx.h"
#include "../../../std_lib_facilities.h"
#include "Arm.h"
#include <iostream>
#include <iomanip>

using namespace std;


string Arm::print() {
    //cout << "\tType: " << type << setw(8) << " | Name: " << name << setw(8) << " | Part Number: " << partNum << endl;
	return "";
};
string Arm::getType() {
    return type;
};
string Arm::getName() {
    return name;
};
string Arm::getPartNum(){
    return partNum;
};

