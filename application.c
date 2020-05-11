#include "application.h"

//	������� ������� ������������� ��������, ����� � ���������
void AppStart(pApplication app);
//	������� ���������� ���������� ������ ���������� �� ������
//	���������� ������������� ������ ����
int AppDoAction(pApplication app, int action);
//	������� ��������� ��������� ������������� ���������
//	�� ����������� ������������� �������� ������
int AppCheckSettings(pApplication app);
//	������� ������ ������� �������� ������
void AppShowSettings(Settings settings);

void AppInitialize(pApplication app) {
	app->UI = UIInitialize();
	UIAbout(app->UI);
	AppStart(app);
}

void AppStart(pApplication app) {
	int isSettings = 0;
	while (!isSettings) {
		app->settings = SettingsInitialize();
		isSettings = AppCheckSettings(app);
	}
	app->animCount = AMInitializeAnimalCounter();
	app->animals = AMGenerateModel(app->animCount, app->settings);
	app->turnsCount = 0;
}

int AppCheckSettings(pApplication app) {
	int isSettings = 1;
	int maxAnimalsCount = app->settings.rab2 + app->settings.wlf_m2 + app->settings.wlf_f2;
	int placesAnimals = app->settings.map_length * app->settings.map_length;
	if (maxAnimalsCount >= placesAnimals) {
		UIError(app->UI, "������������ ���������� �������� ��������� ����������� �������");
		isSettings = 0;
	}
	return isSettings;
}

int AppRun(pApplication app) {
	int isExit = 0;
	int actionNumber;

	while (!isExit) {
		UIDrawMap(app->UI, app->animals, app->settings);
		UIPrintStats(app->UI, app->animCount, app->turnsCount);
		actionNumber = UIMenu(app->UI);
		isExit = AppDoAction(app, actionNumber);
	}
	return 0;
}

int AppDoAction(pApplication app, int action) {
	int isExit = 0;
	int turnsCount = 1;
	switch (action) {
	case 1:
		TTurnManager(app->animals, app->settings, app->animCount, turnsCount, &(app->turnsCount));
		break;
	case 2:
		turnsCount = UIGetTurnsCount(app->UI);
		TTurnManager(app->animals, app->settings, app->animCount, turnsCount, &(app->turnsCount));
		break;
	case 3:
		AppShowSettings(app->settings);
		break;
	case 4:
		AppStart(app);
		break;
	case 5:
		UIAbout(app->UI);
		break;
	case 0:
		isExit = 1;
		break;
	default:
		UIError(app->UI, "�������� ����� ��������");
		break;
	}
	return isExit;
}

void AppShowSettings(Settings settings) {
	printf("\n");

	printf("������� ���������:\n");
	printf("%s: %d x %d ������\n", "������ ����", settings.map_length, settings.map_length);
	printf("%s: %d%%\n", "���� ����������� �������", settings.reprod_chance);
	printf("%s: %dHP\n", "������������ ������� ����� ������", settings.wolf_health);
	printf("%s: %d - %d\n", "�������� ���������� ��������", settings.rab1, settings.rab2);
	printf("%s: %d - %d\n", "�������� ���������� ������", settings.wlf_m1, settings.wlf_m2);
	printf("%s: %d - %d\n", "�������� ���������� ������", settings.wlf_f1, settings.wlf_f2);

	printf("\n");

	system("pause");
}												 

void AppDestroy(pApplication app) {
	UIDestroy(app->UI);
	AMDestroy(app->animals, app->animCount);
}