#include "settings.h"

Settings SettingsInitialize() {
	Settings settings;

	system("cls");

	int fieldSize;

	settings.map_length = readIntFromConsole("¬ведите размер пол€", 3, 80);
	fieldSize = settings.map_length * settings.map_length;
	settings.reprod_chance = readIntFromConsole("¬ведите шанс размножени€ кролика", 1, 100);
	settings.wolf_health = readIntFromConsole("¬ведите начальный уровень жизни волков", 1, MAXINT);
	settings.rab1 = readIntFromConsole("¬ведите диапазон количества кроликов (минимум)", 1, fieldSize);
	settings.rab2 = readIntFromConsole("¬ведите диапазон количества кроликов (максимум)", settings.rab1, fieldSize);
	settings.wlf_m1 = readIntFromConsole("¬ведите диапазон количества волков (минимум)", 1, fieldSize);
	settings.wlf_m2 = readIntFromConsole("¬ведите диапазон количества волков (максимум)", settings.wlf_m1, fieldSize);
	settings.wlf_f1 = readIntFromConsole("¬ведите диапазон количества волчиц (минимум)", 1, fieldSize);
	settings.wlf_f2 = readIntFromConsole("¬ведите диапазон количества волчиц (максимум)", settings.wlf_f1, fieldSize);

	system("pause");

	return settings;
}