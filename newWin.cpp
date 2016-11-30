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
	//modelList.push_back(new RobotModel("Test model", "10101", temp2));
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

void newWin::createLogin() {
	login = new Fl_Group(0, 30, 640, 450);
	login->begin();
	// Title 
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Robbie Robot Shop");
	title->labelcolor(FL_BLACK);
	title->labelsize(30);
	// Border
	Fl_Box *border = new Fl_Box(Fl_Boxtype::FL_FLAT_BOX, 120, 140, 400, 200, 0);
	// Login Btn
	Fl_Button *loginBtn = new Fl_Button(420, 280, 75, 40, "LOGIN");
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
	//armBtn->callback((Fl_Callback*)armBtnCB);
	//torsoBtn->callback((Fl_Callback*)torsoBtnCB);
	//batteryBtn->callback((Fl_Callback*)batteryBtnCB);
	//locomotorBtn->callback((Fl_Callback*)locomotorBtnCB);
	leave->callback((Fl_Callback*)leaveCB);
	part->hide();
}

void newWin::createModel() {
	model = new Fl_Group(0, 30, 640, 450);
	model->begin();
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
	model->end();
	leave->callback((Fl_Callback*)leaveCB);
	model->hide();
}

void newWin::listParts() {

	partLst = new Fl_Group(0, 30, 640, 450);
	partLst->begin();
	// Title
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);

	title->label("Listing parts");
	title->labelsize(20);
	//Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Display");
	//Fl_Text_Buffer *buff = new Fl_Text_Buffer();      // text buffer
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	//disp->buffer(buff);
	//win->resizable(*disp);
	//win->show();
	// Text

	//for(citer = partList.begin(); citer != partList.end(); citer++) {
	//	buff->text((buff->text() + (*citer)->print() + "\n").c_str());
	//}

	//win->resizable(*disp);

	partLst->end();
	leave->callback((Fl_Callback*)leaveCB);
	partLst->hide();
}

void newWin::listModels() {

	modelList = new Fl_Group(0, 30, 640, 450);
	modelList->begin();

	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Lets create a part! Select a type of part.");
	title->labelsize(20);
	Fl_Button *headBtn = new Fl_Button(75, 150, 150, 50, "Head");
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	modelList->end();
	leave->callback((Fl_Callback*)leaveCB);
	modelList->hide();
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
	sendbtn->callback(sendPartCB);
	head->hide();
}

void newWin::createArm() {
	arm = new Fl_Group(0, 30, 640, 450);
	arm->begin();
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Creating a Arm.");
	title->labelsize(20);
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	arm->end();
	leave->callback((Fl_Callback*)leaveCB);
	arm->hide();
}
void newWin::createTorso() {
	torso = new Fl_Group(0, 30, 640, 450);
	torso->begin();
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Creating a Torso.");
	title->labelsize(20);
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	torso->end();
	leave->callback((Fl_Callback*)leaveCB);
	torso->hide();
}
void newWin::createBattery() {
	battery = new Fl_Group(0, 30, 640, 450);
	battery->begin();
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Creating a Battery.");
	title->labelsize(20);
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	battery->end();
	leave->callback((Fl_Callback*)leaveCB);
	battery->hide();
}
void newWin::createLocomotor() {
	locomotor = new Fl_Group(0, 30, 640, 450);
	locomotor->begin();
	Fl_Box *title = new Fl_Box(50, 50, 540, 30);
	title->label("Creating a Locomotor.");
	title->labelsize(20);
	Fl_Button *leave = new Fl_Button(230, 350, 150, 50, "Leave");
	locomotor->end();
	leave->callback((Fl_Callback*)leaveCB);
	locomotor->hide();
}

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
	((Fl_Group*)(w->parent()))->hide();
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
//void newWin::armBtnCB(Fl_Widget *w, void *v) {
//		((Fl_Group*)(w->parent()))->hide();
//		((Fl_Group*)(w->parent()->parent()->child(8)))->show();
//}
//void newWin::torsoBtnCB(Fl_Widget *w, void *v) {
//	((Fl_Group*)(w->parent()))->hide();
//	((Fl_Group*)(w->parent()->parent()->child(9)))->show();
//}
//void newWin::batteryBtnCB(Fl_Widget *w, void *v) {
//	((Fl_Group*)(w->parent()))->hide();
//	((Fl_Group*)(w->parent()->parent()->child(10)))->show();
//}
//void newWin::locomotorBtnCB(Fl_Widget *w, void *v) {
//	((Fl_Group*)(w->parent()))->hide();
//	((Fl_Group*)(w->parent()->parent()->child(11)))->show();
//}
//void newWin::setNameCB(Fl_Widget *w, void *v) {
//string s = "Enter the part name";
//string d = "Failed";
//string a = Fl_Input(s, d);
//name = a;

//}
void newWin::sendPartCB(Fl_Widget *w, void *v) {
	partList.push_back(new Head(((Fl_Input*)w->parent()->child(3))->value(), ((Fl_Input*)w->parent()->child(4))->value(), ((Fl_Float_Input*)w->parent()->child(5))->value(), ((Fl_Float_Input*)w->parent()->child(6))->value()));
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