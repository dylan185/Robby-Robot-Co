#include "libraries.h"

class newWin {
public:
	newWin(int x, int y, const char* l) : x(x), y(y), label(l) {}
	void test();
	void newWinProp();
	void newWinShow();
	void createLogin();
	void createPM();
	void createPart();
    void createModel();
	void listParts();
	void listModels();
	void createHead();
	void createArm();
	void createTorso();
	void createBattery();
	void createLocomotor();
	//void createPartMenu();
	static void partBtnCB(Fl_Widget *w, void *v);
	//static void showPartMenuCB(Fl_Widget *w, void *v);
	static void modelBtnCB(Fl_Widget *w, void *v);
	static void partListBtnCB(Fl_Widget *w, void *v);
    static void modelListBtnCB(Fl_Widget *w, void *v);
	static void headBtnCB(Fl_Widget *w, void *v);
	static void armBtnCB(Fl_Widget *w, void *v);
	static void torsoBtnCB(Fl_Widget *w, void *v);
	static void batteryBtnCB(Fl_Widget *w, void *v);
	static void locomotorBtnCB(Fl_Widget *w, void *v);
	static void loginBtnCB(Fl_Widget *w, void *v);
	static void sendHeadCB(Fl_Widget *w, void *v);
	static void sendArmCB(Fl_Widget *w, void *v);
	static void sendTorsoCB(Fl_Widget *w, void *v);
	static void sendBatteryCB(Fl_Widget *w, void *v);
	static void sendLocomotorCB(Fl_Widget *w, void *v);
	static void leaveCB(Fl_Widget *w, void *v);
	static void leaveListCB(Fl_Widget *w, void *v);
	//static void setNameCB(Fl_Widget *w, void *v);
	static void quitCB(Fl_Widget *w, void *v);
	string compilePart();
	string compileModel();
	Fl_Text_Buffer create();
private:
	int x, y;
	const char* label;
	Fl_Window *win;
	Fl_Menu_Bar *menuBar;
	Fl_Group *login, *pm, *partMenu, *part, *model, *partLst, *modelLst, *head, *arm, *torso, *battery, *locomotor;
	Fl_Input* name;
	Fl_Hold_Browser *tabW;
	Fl_Input *hName;
	Fl_Int_Input *hNum;
	Fl_Float_Input *hWeight, *hCost;
	Fl_Multiline_Input *hDesc;
};