#include "stdafx.h"
#include "../../../std_lib_facilities.h"
#include "Head.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

string Head::print() {
	string s = "Type: " + getType() + "  Name: " + getName() + " PartNum: " + getPartNum();
	return s;
};
string Head::getType() {
	return type;
};
string Head::getName() {
	return name;
};
string Head::getPartNum(){
    return partNum;
}
