
#ifndef __ROBOTPART_H
#define __ROBOTPART_H 2016
#include <string>
#include <vector>
using namespace std;

class RobotPart{
public:
	RobotPart(string n, string num, double c, double w) :
		 name(n), partNum(num) , cost(c), weight(w){}
	void addDescription();
	virtual string print();
	virtual string getType();
	virtual string getName();
	virtual string getPartNum();
	double getCost();
	double getWeight();
	int num_compartments();
	int getMaxSpeed();
	double getEnergy();
	double getMaxPower();

protected:
	string name;
	string partNum;
	double weight;
	double cost;
	string description;
};

vector<RobotPart*> readPartList();

#endif // !__ROBOTPART_H
