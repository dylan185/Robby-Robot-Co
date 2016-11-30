#ifndef ROBOTMODEL_H_INCLUDED
#define ROBOTMODEL_H_INCLUDED

#include <string>
#include <vector>
#include "RobotPart.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <string>

using namespace std;

class RobotModel {
public:
	RobotModel(string n, string num, vector<RobotPart*> temp):
	    name(n), modelNum(num), parts(temp) {}
	string print();
    void printBasic();
    string getName(){
        return name;
    }
    string getModelNum(){
        return modelNum;
    }
    double getPrice(){
        return price;
    }
    vector<RobotPart*> getPartVector(){
        return parts;
    }
    void setPrice();

private:
	string name;
	string modelNum;
	double price;
	vector<RobotPart*> parts;



};

void makeRobotModelFile(vector<RobotModel*> modelList);
vector<RobotModel*> readRobotModels();


#endif // BUILDROBOT_H_INCLUDED
