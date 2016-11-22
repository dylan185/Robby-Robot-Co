
#include "libraries.h"
#include "newWin.h"
#include "Head.h"
#include "Arm.h"
#include "Torso.h"
#include "Battery.h"
#include "Locomotor.h"
#include "RobotModel.h"
#include "RobotPart.h"
#include <vector>


int main() {
	// Init Windows
	newWin mainWin(640, 480, "Shop");
	//mainWin.test();
	mainWin.newWinProp();
	mainWin.createLogin();
	mainWin.createPM();
	mainWin.createPart();
	mainWin.createModel();
	mainWin.listParts();
	mainWin.listModels();
	mainWin.createHead();

	mainWin.newWinShow();

	return Fl::run();
}