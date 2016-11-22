#ifndef __BATTERY_H
#define __BATTERY_H 2016
#include "RobotPart.h"
#include <vector>

void makeBatteryFile(vector<RobotPart*> partList);

class Battery :public RobotPart {
public:
	Battery(string n, string num,double c, double w, double e, double p) :
		RobotPart(n, num, c, w), energy(e), maxPower(p),type("Battery") {}
	virtual string print();
	virtual string getType();
	virtual string getName();
	virtual string getPartNum();
	double getEnergy();
	double getMaxPower();
private:
	string type;
	double energy;
	double maxPower;
};
#endif
