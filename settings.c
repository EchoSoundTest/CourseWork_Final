#include <stdio.h>

#include "settings.h"

Settings SettingsInitialize() {
	Settings settings;

#ifndef DEBUG
	system("cls");

	int fieldSize;

	//printf("������� ������ ����: ");
	settings.map_length = readIntFromConsole("������� ������ ����", 3, 80);
	fieldSize = settings.map_length * settings.map_length;
	//scanf("%d", &set.map_length);
	//printf("������� ���� ����������� �������: ");
	//scanf("%d", &set.reprod_chance);
	settings.reprod_chance = readIntFromConsole("������� ���� ����������� �������", 1, 100);
	//printf("������� ������������ ������� ����� ������: ");
	//scanf("%d", &set.wolf_health);
	settings.wolf_health = readIntFromConsole("������� ������������ ������� ����� ������", 1, MAXINT);
	//printf("������� �������� ���������� ��������: ");
	//scanf("%d %d", &set.rab1, &set.rab2);
	settings.rab1 = readIntFromConsole("������� �������� ���������� ��������", 1, fieldSize);
	settings.rab2 = readIntFromConsole("������� �������� ���������� ��������", settings.rab1, fieldSize);
	//printf("������� �������� ���������� ������: ");
	//scanf("%d %d", &set.wlf_m1, &set.wlf_m2);
	settings.wlf_m1 = readIntFromConsole("������� �������� ���������� ������", 1, fieldSize);
	settings.wlf_m2 = readIntFromConsole("������� �������� ���������� ������", settings.wlf_m1, fieldSize);
	//printf("������� �������� ���������� ������: ");
	//scanf("%d %d", &set.wlf_f1, &set.wlf_f2);
	settings.wlf_f1 = readIntFromConsole("������� �������� ���������� ������", 1, fieldSize);
	settings.wlf_f2 = readIntFromConsole("������� �������� ���������� ������", settings.wlf_f1, fieldSize);

	system("pause");
#else
	settings.map_length = 10;
	settings.reprod_chance = 100;
	settings.rab1 = 5;
	settings.rab2 = 10;
	settings.wlf_f1 = 5;
	settings.wlf_f2 = 10;
	settings.wlf_m1 = 5; 
	settings.wlf_m2 = 10;
	settings.wolf_health = 2;
#endif

	return settings;
}