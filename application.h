#ifndef APPLICATION_H
#define APPLICATION_H

//	������ "����������", ���������� ������� � �����������,
//	����������� ��� ������ ����� ���������� � �����

#include "userinterface.h"
#include "settings.h"
#include "animals.h"
#include "animalsmap.h"
#include "turn.h"

//	���������� ����������� ��� Application,
//	���������� �� ������ ����������
typedef struct {
	//	��������� �� ����������� "���������������� ���������"
	pUserInterface UI;
	//	��������� "���������"
	Settings settings;
	//	��������� �� �����-������ ��������
	pAnimals animals;
	//	��������� �� ������� ���������� ��������
	pAnimCounter animCount;
	//	������� ���������� �����
	int turnsCount;
} Application;

//	���������� ��������� ���� pApplication �� ��������� Application
typedef Application* pApplication;

//	������� ������������� ����������
void AppInitialize(pApplication app);
//	������� ���������� ����������
int AppRun(pApplication app);
//	������� �������� ����������
void AppDestroy(pApplication app);



#endif // !APPLICATION_H
