#ifndef APPLICATION_H
#define APPLICATION_H

#include "userinterface.h"
#include "settings.h"

UserInterface;

//	���������� ����������� ��� Application
typedef struct {
	pUserInterface UI;
	pSettings settings;
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
