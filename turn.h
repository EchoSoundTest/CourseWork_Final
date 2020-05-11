#ifndef TURN_H
#define TURN_H

//	������ "���" �������� �������, �����������
//	��� ���������� ���� ������� � ��������� �����������
//	������������ ����

#include "animals.h"
#include "settings.h"

//	�������� ���������� �����/������
//	pAnimals anim_arr - ��������� �� ������-�����
//	pAnimCounter animCounter - ��������� �� ������� ��������
//	Settings settings - ���������
//	int turnsCount - ���������� �����, ������� ���� ���������
//	int * allTurnsCount - ��������� �� ����� ����������� ���������� �����
void TTurnManager(pAnimals anim_arr, Settings settings, pAnimCounter animCounter, int turnsCount, int * allTurnsCount);

#endif // !TURN_H
