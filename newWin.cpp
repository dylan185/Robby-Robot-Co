#include "newWin.h"
//Create the constant vectors for the robots and models
vector<RobotPart*> partList;// = readPartList();
vector<RobotModel*> modelList; //= readRobotModels();
vector<RobotModel*> temp;
vector<RobotPart*> temp1;
vector<RobotPart*> temp2;
vector<RobotModel*>::iterator cipher;
vector<RobotPart*>::iterator citer;

//basic struct for creating input
//struct Info {
//Fl_Input* name;
//Fl_Float_Input* cost;
//Fl_Input* partNum;
//Fl_Float_Input* weight;

// Saved values
//char nval[40];
//double  wval;
//char pval[40];
//double  cval;
//};

void newWin::test() {
	partList.push_back(new Head("Test Head", "00000", 1.00, 0));
	partList.push_back(new Arm("Test Arm", "00001", 2.00, 0));
	partList.push_back(new Torso("Test Torso", "00002", 3.00, 0, 0));
	partList.push_back(new Battery("Test Battery", "00003", 4.00, 0, 100, 100));
	partList.push_back(new Locomotor("Test Arm", "00004", 5.00, 0));
	for (citer = partList.begin(); citer != partList.end(); citer++) {
		temp2.push_back(*citer);
	}
    modelList.push_back(new RobotModel("Test model", "10101", temp2));
	temp2.clear();
	
}

void newWin::newWinProp() {
	win = new Fl_Window(x, y, label);
	win->color(FL_WHITE);
	menuBar = new Fl_Menu_Bar(0, 0, 640, 30);
	menuBar->add("File/Quit", 0, 0, 0, 0);
	menuBar->color(FL_WHITE);
	menuBar->box(FL_THIN_UP_BOX);
}

void newWin::newWinShow() {
	win->show();
	win->end();
}
//windows
void newWin::createLogin() {
	login = new Fl_Group(0, 30, 640, 450);
	login->begin();
	// Title 
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Robbie Robot Shop");
	title->labelcolor(FL_BLACK);
	title->labelsize(30);
	// Border
	
	// Login Btn
	Fl_Button *loginBtn = new Fl_Button(150, 150, 150, 40, "PROJECT MANAGER");
	Fl_Button *SalesBtn = new Fl_Button(350, 150, 150, 40, "SALES REP");
	Fl_Button *CustomerBtn = new Fl_Button(250, 250, 150, 40, "CUSTOMER");
	loginBtn->callback((Fl_Callback*)loginBtnCB);
	login->end();
}

void newWin::createPM() {
	pm = new Fl_Group(0, 30, 640, 450);
	pm->begin();
	// Title
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Welcome Project Manager");
	title->labelsize(20);
	// Create Part Btn
	Fl_Button *partsBtn = new Fl_Button(130, 150, 150, 50, "Create Parts");
	// Create Robot Btn
	Fl_Button *modelBtn = new Fl_Button(330, 150, 150, 50, "Create Robot");
	Fl_Button *listPBtn = new Fl_Button(130, 250, 150, 50, "List Parts");
	Fl_Button *listMBtn = new Fl_Button(330, 250, 150, 50, "List models");
	Fl_Button *quit = new Fl_Button(230, 350, 150, 50, "Quit");
	partsBtn->callback((Fl_Callback*)partBtnCB);
	modelBtn->callback((Fl_Callback*)modelBtnCB);
	listPBtn->callback(partListBtnCB);
	listMBtn->callback(modelListBtnCB);
	quit->callback(quitCB);
	pm->end();
	pm->hide();
}
void newWin::createPart() {
	part = new Fl_Group(0, 30, 640, 450);
	part->begin();
	// Title
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Lets create a part! Select a type of part.");
	title->labelsize(20);
	Fl_Button *headBtn = new Fl_Button(75, 150, 150, 50, "Head");
	Fl_Button *armBtn = new Fl_Button(250, 150, 150, 50, "Arm");
	Fl_Button *torsoBtn = new Fl_Button(425, 150, 150, 50, "Torso");
	Fl_Button *batteryBtn = new Fl_Button(150, 250, 150, 50, "Battery");
	Fl_Button *locomotorBtn = new Fl_Button(350, 250, 150, 50, "Locomotor");
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	part->end();
	headBtn->callback((Fl_Callback*)headBtnCB);
	armBtn->callback((Fl_Callback*)armBtnCB);
	torsoBtn->callback((Fl_Callback*)torsoBtnCB);
	batteryBtn->callback((Fl_Callback*)batteryBtnCB);
	locomotorBtn->callback((Fl_Callback*)locomotorBtnCB);
	leave->callback((Fl_Callback*)leaveCB);
	part->hide();
}

void newWin::createModel() {
	model = new Fl_Group(0, 30, 640, 450);
	model->begin();
	// Title
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Lets create a Model! Select five parts");
	title->labelsize(20);
	Fl_Button *headBtn = new Fl_Button(75, 150, 150, 50, "Head");
	Fl_Button *armBtn = new Fl_Button(250, 150, 150, 50, "Arm");
	Fl_Button *torsoBtn = new Fl_Button(425, 150, 150, 50, "Torso");
	Fl_Button *batteryBtn = new Fl_Button(150, 250, 150, 50, "Battery");
	Fl_Button *locomotorBtn = new Fl_Button(350, 250, 150, 50, "Locomotor");
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	model->end();
	leave->callback((Fl_Callback*)leaveCB);
	model->hide();
}

void newWin::listParts() {

	partLst = new Fl_Group(0, 30, 640, 450);
	partLst->begin();
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 50, 580, 300, "Part List");
	disp->buffer(buff);
	partLst->resizable(*disp);
	string s = compilePart();
	buff->text(s.c_str());
	Fl_Button *leave = new Fl_Button(230, 375, 150, 50, "Leave");
	partLst->end();
	leave->callback((Fl_Callback*)leaveListCB);
	partLst->hide();
	
}

void newWin::listModels() {

	modelLst = new Fl_Group(0, 30, 640, 450);
	modelLst->begin();
	
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 50, 580, 300, "Model List");
	disp->buffer(buff);
	modelLst->resizable(*disp);
	buff->text(compileModel().c_str());
	Fl_Button *leave = new Fl_Button(230, 375, 150, 50, "Leave");
	modelLst->end();
	leave->callback((Fl_Callback*)leaveCB);
	modelLst->hide();
}

void newWin::createHead() {
	//Info input;
	head = new Fl_Group(0, 30, 640, 450);
	head->begin();
	// Title
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Creating a Head.");
	title->labelsize(20);
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	Fl_Input *name = new Fl_Input(100, 150, 150, 50, "Name");
	Fl_Input *partNum = new Fl_Input(100, 200, 150, 50, "Part Number");
	Fl_Float_Input *weight = new Fl_Float_Input(100, 250, 150, 50, "weight");
	Fl_Float_Input *cost = new Fl_Float_Input(100, 300, 150, 50, "cost");
	Fl_Button *sendbtn = new Fl_Button(450, 400, 150, 50, "Send");
	head->end();
	leave->callback((Fl_Callback*)leaveCB);
	sendbtn->callback(sendHeadCB);
	head->hide();
}

void newWin::createArm() {
	arm = new Fl_Group(0, 30, 640, 450);
	arm->begin();
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Creating a Arm.");
	title->labelsize(20);
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	Fl_Input *name = new Fl_Input(100, 150, 150, 50, "Name");
	Fl_Input *partNum = new Fl_Input(100, 200, 150, 50, "Part Number");
	Fl_Float_Input *weight = new Fl_Float_Input(100, 250, 150, 50, "weight");
	Fl_Float_Input *cost = new Fl_Float_Input(100, 300, 150, 50, "cost");
	Fl_Button *sendbtn = new Fl_Button(450, 400, 150, 50, "Send");
	arm->end();
	leave->callback((Fl_Callback*)leaveCB);
	sendbtn->callback(sendArmCB);
	arm->hide();
}
void newWin::createTorso() {
	torso = new Fl_Group(0, 30, 640, 450);
	torso->begin();
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Creating a Torso.");
	title->labelsize(20);
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	Fl_Input *name = new Fl_Input(100, 150, 150, 50, "Name");
	Fl_Input *partNum = new Fl_Input(100, 200, 150, 50, "Part Number");
	Fl_Float_Input *weight = new Fl_Float_Input(100, 250, 150, 50, "weight");
	Fl_Float_Input *cost = new Fl_Float_Input(100, 300, 150, 50, "cost");
	Fl_Button *sendbtn = new Fl_Button(450, 400, 150, 50, "Send");
	torso->end();
	leave->callback((Fl_Callback*)leaveCB);
	sendbtn->callback(sendTorsoCB);
	torso->hide();
}
void newWin::createBattery() {
	battery = new Fl_Group(0, 30, 640, 450);
	battery->begin();
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Creating a Battery.");
	title->labelsize(20);
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	Fl_Input *name = new Fl_Input(100, 150, 150, 50, "Name");
	Fl_Input *partNum = new Fl_Input(100, 200, 150, 50, "Part Number");
	Fl_Float_Input *weight = new Fl_Float_Input(100, 250, 150, 50, "weight");
	Fl_Float_Input *cost = new Fl_Float_Input(100, 300, 150, 50, "cost");
	Fl_Button *sendbtn = new Fl_Button(450, 400, 150, 50, "Send");
	battery->end();
	leave->callback((Fl_Callback*)leaveCB);
	sendbtn->callback(sendBatteryCB);
	battery->hide();
}
void newWin::createLocomotor() {
	locomotor = new Fl_Group(0, 30, 640, 450);
	locomotor->begin();
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Creating a Locomotor.");
	title->labelsize(20);
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	Fl_Input *name = new Fl_Input(100, 150, 150, 50, "Name");
	Fl_Input *partNum = new Fl_Input(100, 200, 150, 50, "Part Number");
	Fl_Float_Input *weight = new Fl_Float_Input(100, 250, 150, 50, "weight");
	Fl_Float_Input *cost = new Fl_Float_Input(100, 300, 150, 50, "cost");
	Fl_Button *sendbtn = new Fl_Button(450, 400, 150, 50, "Send");
	locomotor->end();
	leave->callback((Fl_Callback*)leaveCB);
	sendbtn->callback(sendLocomotorCB);
	locomotor->hide();
}



//callbacks
void newWin::loginBtnCB(Fl_Widget *w, void *v) {
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(2)))->show();
}
void newWin::partBtnCB(Fl_Widget *w, void *v) {
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(3)))->show();
}
void newWin::modelBtnCB(Fl_Widget *w, void *v) {
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(4)))->show();
}
void newWin::partListBtnCB(Fl_Widget *w, void *v) {
	for (citer = partList.begin(); citer != partList.end(); citer++) {
		cout << (*citer)->print() << endl;
	}
	cout << endl;
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(5)))->redraw();
	((Fl_Group*)(w->parent()->parent()->child(5)))->show();
}
void newWin::modelListBtnCB(Fl_Widget *w, void *v) {
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(6)))->show();
}
void newWin::headBtnCB(Fl_Widget *w, void *v) {
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(7)))->show();
}
void newWin::armBtnCB(Fl_Widget *w, void *v) {
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(8)))->show();
}
void newWin::torsoBtnCB(Fl_Widget *w, void *v) {
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(9)))->show();
}
void newWin::batteryBtnCB(Fl_Widget *w, void *v) {
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(10)))->show();
}
void newWin::locomotorBtnCB(Fl_Widget *w, void *v) {
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(11)))->show();
}

void newWin::sendHeadCB(Fl_Widget *w, void *v) {
	
	string name = ((Fl_Input*)w->parent()->child(2))->value();
	string partNum = ((Fl_Input*)w->parent()->child(3))->value();
	double cost = stod(((Fl_Float_Input*)w->parent()->child(4))->value());
	double weight = stod(((Fl_Float_Input*)w->parent()->child(5))->value());
	partList.push_back(new Head(name, partNum, cost, weight));
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(2)))->show();
}
void newWin::sendArmCB(Fl_Widget *w, void *v) {

	string name = ((Fl_Input*)w->parent()->child(2))->value();
	string partNum = ((Fl_Input*)w->parent()->child(3))->value();
	double cost = stod(((Fl_Float_Input*)w->parent()->child(4))->value());
	double weight = stod(((Fl_Float_Input*)w->parent()->child(5))->value());
	partList.push_back(new Arm(name, partNum, cost, weight));
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(2)))->show();
}
void newWin::sendTorsoCB(Fl_Widget *w, void *v) {

	string name = ((Fl_Input*)w->parent()->child(2))->value();
	string partNum = ((Fl_Input*)w->parent()->child(3))->value();
	double cost = stod(((Fl_Float_Input*)w->parent()->child(4))->value());
	double weight = stod(((Fl_Float_Input*)w->parent()->child(5))->value());
	partList.push_back(new Torso(name, partNum, cost, weight, 4));
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(2)))->show();
}
void newWin::sendBatteryCB(Fl_Widget *w, void *v) {

	string name = ((Fl_Input*)w->parent()->child(2))->value();
	string partNum = ((Fl_Input*)w->parent()->child(3))->value();
	double cost = stod(((Fl_Float_Input*)w->parent()->child(4))->value());
	double weight = stod(((Fl_Float_Input*)w->parent()->child(5))->value());
	partList.push_back(new Battery(name, partNum, cost, weight, 1, 3));
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(2)))->show();
}
void newWin::sendLocomotorCB(Fl_Widget *w, void *v) {

	string name = ((Fl_Input*)w->parent()->child(2))->value();
	string partNum = ((Fl_Input*)w->parent()->child(3))->value();
	double cost = stod(((Fl_Float_Input*)w->parent()->child(4))->value());
	double weight = stod(((Fl_Float_Input*)w->parent()->child(5))->value());
	partList.push_back(new Locomotor(name, partNum, cost, weight));
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(2)))->show();
}

void newWin::leaveListCB(Fl_Widget *w, void *v) {
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(2)))->show();

}
void newWin::leaveCB(Fl_Widget *w, void *v) {
	((Fl_Group*)(w->parent()))->hide();
	((Fl_Group*)(w->parent()->parent()->child(2)))->show();
	
}

void newWin::quitCB(Fl_Widget *w, void *v) {
	exit(0);
}
string newWin::compilePart() {
	string s = "";
	for (citer = partList.begin(); citer != partList.end(); citer++) {
		s = s + (*citer)->print() + "\n";
	}
	cout << "\n" << s << endl;
	return s;
}
string newWin::compileModel() {
	string s = "";
	for (cipher = modelList.begin(); cipher != modelList.end(); cipher++) {
		s = s + (*cipher)->print() + "\n";
	}
	cout << "\n" << s << endl;
	return s;
}
