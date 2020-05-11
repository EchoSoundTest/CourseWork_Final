#ifndef SETTINGS_H
#define SETTINGS_H

//	������ "���������" �������� ������� � �����������,
//	����������� ��� ��������� � �������� ��������
//	������������� �������������� �������� ������

#include "utils.h"

typedef struct {
	//	������ �����
	int map_length;
	//	���� ����������� ������� � ���������
	int reprod_chance;
	//	��������� ������� ����� ������
	int wolf_health;
	//	�������� ���������� �������� (min, max)
	int rab1, rab2;
	//	�������� ���������� ������ (min, max)
	int wlf_m1, wlf_m2;
	//	�������� ���������� ������ (min, max)
	int wlf_f1, wlf_f2;
} Settings;

//	������� ���������� ��������� ������������� ���������
//	(��������� ���������) ������
Settings SettingsInitialize();

#endif // !SETTINGS_H
