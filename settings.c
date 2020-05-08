#include <stdio.h>

#include "settings.h"

pSettings SettingsInitialize() {
	Settings set;

#ifndef DEBUG
	system("cls");
	printf("������� ������ ����: ");
	scanf("%d", &set.map_length);
	printf("������� ���� ����������� �������: ");
	scanf("%d", &set.reprod_chance);
	printf("������� ������������ ������� ����� ������: ");
	scanf("%d", &set.wolf_health);
	printf("������� �������� ���������� ��������: ");
	scanf("%d %d", &set.rab1, &set.rab2);
	printf("������� �������� ���������� ������: ");
	scanf("%d %d", &set.wlf_m1, &set.wlf_m2);
	printf("������� �������� ���������� ������: ");
	scanf("%d %d", &set.wlf_f1, &set.wlf_f2);
	system("pause");
#else
	set.map_length = 50;
	set.reprod_chance = 30;
	set.rab1 = 10;
	set.rab2 = 20;
	set.wlf_f1 = 10;
	set.wlf_f2 = 20;
	set.wlf_m1 = 10;
	set.wlf_m2 = 20;
	set.wolf_health = 5;
#endif

	return &set;
}