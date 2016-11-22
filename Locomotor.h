#ifndef __Locomotor_H
#define __Locomotor_H 2016
#include "RobotPart.h"
#include <vector>

void makeLocomotorFile(vector<RobotPart*> partList);

class Locomotor :public RobotPart {
public:
	Locomotor(string n, string num, double c, double w) :
		RobotPart(n, num, c, w),type("Locomotor") {}
	virtual string print();
	virtual string getType();
	virtual string getName();
	virtual string getPartNum();
	int getMaxSpeed();
private:
	string type;
	int maxSpeed;
};
#endif

