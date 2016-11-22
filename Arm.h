#ifndef __ARM_H
#define __ARM_H 2016
#include "RobotPart.h"
#include <vector>

void makeArmFile(vector<RobotPart*> partList);

class Arm :public RobotPart{
public:
	Arm(string n, string num, double c, double w) :
		RobotPart(n, num, c, w),type("Arm") {}
	virtual string print();
	virtual string getName();
	virtual string getType();
	virtual string getPartNum();
private:
	string type;
};
#endif // !__ARM_H

