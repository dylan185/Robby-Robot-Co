#include "libraries.h"

class newWin {
public:
	newWin(int x, int y, const char* l) : x(x), y(y), label(l) {}
	//void test();
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
	static void partBtnCB(Fl_Widget *w, void *v);
	static void modelBtnCB(Fl_Widget *w, void *v);
	static void partListBtnCB(Fl_Widget *w, void *v);
	static void modelListBtnCB(Fl_Widget *w, void *v);
	static void headBtnCB(Fl_Widget *w, void *v);
	static void armBtnCB(Fl_Widget *w, void *v);
	static void torsoBtnCB(Fl_Widget *w, void *v);
	static void batteryBtnCB(Fl_Widget *w, void *v);
	static void locomotorBtnCB(Fl_Widget *w, void *v);
	static void loginBtnCB(Fl_Widget *w, void *v);
	static void sendPartCB(Fl_Widget *w, void *v);
	static void leaveCB(Fl_Widget *w, void *v);
	//static void setNameCB(Fl_Widget *w, void *v);
	static void quitCB(Fl_Widget *w, void *v);

private:
	int x, y;
	const char* label;
	Fl_Window *win;
	Fl_Menu_Bar *menuBar;
	Fl_Group *login, *pm, *part, *model, *partLst, *modelList, *head, *arm, *torso, *battery, *locomotor;
	Fl_Input* name;
};