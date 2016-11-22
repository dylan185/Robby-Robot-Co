#ifndef __TORSO_H
#define __TORSO_H 2016
#include "RobotPart.h"
#include <vector>

void makeTorsoFile(vector<RobotPart*> partList);

class Torso :public RobotPart {
public:
	Torso(string n, string num, double c, double w, int com) :
		RobotPart(n, num, c, w) ,compartments(com),type("Torso"){}
	virtual string print();
	virtual string getType();
	virtual string getName();
	virtual string getPartNum();
	int num_compartments();
private:
	string type;
	int compartments;
};
#endif // !__ARM_H

