#include "application.h"

static int AppDoAction(pApplication app, int action);
static int AppCheckSettings(pApplication app);

void AppInitialize(pApplication app) {
	app->UI = UIInitialize();
	UIAbout(app->UI);
	int isSettings = 0;
	while (!isSettings) {
		app->settings = SettingsInitialize();
		isSettings = AppCheckSettings(app);
	}
}

int AppCheckSettings(pApplication app) {
	int isSettings = 1;
	int maxAnimalsCount = app->settings->rab2 + app->settings->wlf_m2 + app->settings->wlf_f2;
	int placesAnimals = app->settings->map_length * app->settings->map_length;
	if (maxAnimalsCount >= placesAnimals) {
		UIError(app->UI, "Максимальное количество животных превышает вместимость острова");
		isSettings = 0;
	}
	return isSettings;
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