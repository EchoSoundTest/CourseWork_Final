#include "settings.h"

Settings SettingsInitialize() {
	Settings settings;

	system("cls");

	int fieldSize;

	settings.map_length = readIntFromConsole("������� ������ ����", 3, 80);
	fieldSize = settings.map_length * settings.map_length;
	settings.reprod_chance = readIntFromConsole("������� ���� ����������� �������", 1, 100);
	settings.wolf_health = readIntFromConsole("������� ��������� ������� ����� ������", 1, MAXINT);
	settings.rab1 = readIntFromConsole("������� �������� ���������� �������� (�������)", 1, fieldSize);
	settings.rab2 = readIntFromConsole("������� �������� ���������� �������� (��������)", settings.rab1, fieldSize);
	settings.wlf_m1 = readIntFromConsole("������� �������� ���������� ������ (�������)", 1, fieldSize);
	settings.wlf_m2 = readIntFromConsole("������� �������� ���������� ������ (��������)", settings.wlf_m1, fieldSize);
	settings.wlf_f1 = readIntFromConsole("������� �������� ���������� ������ (�������)", 1, fieldSize);
	settings.wlf_f2 = readIntFromConsole("������� �������� ���������� ������ (��������)", settings.wlf_f1, fieldSize);

	system("pause");

	return settings;
}