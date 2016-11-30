#ifndef __GLOBAL_H
#define __GLOBAL_H 
#include "Libraries.h"
#include <vector>

//vector<SalesRep> salesRepLibrary = readSalesRepList();
//vector<Customer> customerLibrary = readCustomerList();
//vector<orders> ordersLibrary = readOrderList();
vector<RobotPart*> partList;// = readPartList();
vector<RobotModel*> modelList; //= readRobotModels();
vector<RobotModel*> temp;
vector<RobotPart*> temp1;
vector<RobotPart*> temp2;
vector<RobotModel*>::iterator cipher;
vector<RobotPart*>::iterator citer;

#endif