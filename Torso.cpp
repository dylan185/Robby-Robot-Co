#include "stdafx.h"
#include "../../../std_lib_facilities.h"
#include "Torso.h"
#include <iostream>
#include <iomanip>

using namespace std;

string Torso::print() {
	//cout << "\tType: " << type << setw(8) << " | Name: " << name << setw(8) << " | Part Number: " << partNum << endl;
	return "";
};
string Torso::getType() {
	return type;
};
string Torso::getName() {
	return name;
};
string Torso::getPartNum(){
    return partNum;
}
int Torso::num_compartments() {
	return compartments;
}
