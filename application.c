#include "application.h"

static int AppDoAction(pApplication app, int action);

void AppInitialize(pApplication app) {
	app->UI = UIInitialize();
	UIAbout(app->UI);
	app->settings = SettingsInitialize();
}

int AppRun(pApplication app) {
	int isExit = 0;
	int actionNumber;


	while (!isExit) {
		actionNumber = UIMenu(app->UI);
		isExit = AppDoAction(app, actionNumber);
	}
	return 0;
}

int AppDoAction(pApplication app, int action) {
	int isExit = 0;
	switch (action) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		isExit = 1;
		break;
	default:
		UIError(app->UI, "Неверный номер действия");
		break;
	}
	return isExit;
}

void AppDestroy(pApplication app) {
	UIDestroy(app->UI);
}