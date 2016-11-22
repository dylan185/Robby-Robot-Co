#ifndef __HEAD_H
#define __HEAD_H 201609
#include <string>
#include "RobotPart.h"
#include <vector>

using namespace std;

void makeHeadFile(vector<RobotPart*> partList);

class Head : public RobotPart {
public:
	Head(string n, string num, double c, double w) :
		RobotPart(n, num, c, w),type("Head") {}
	virtual string print();
	virtual string getName();
	virtual string getType();
	virtual string getPartNum();
private:
	string type;
};
#endif
