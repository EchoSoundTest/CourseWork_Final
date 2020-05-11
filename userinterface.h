#ifndef USERINTERFACE_H
#define USERINTERFACE_H

//	������ "���������������� ���������" ��������
//	������� � �����������, ����������� ��� ������ � �������������

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#include "animals.h"
#include "settings.h"
#include "utils.h"

//	���������� ����������� ��� UserInterface,
//	���������� �� ������ � �������������
typedef struct {
	//	���������� �������
	HANDLE hConsole;
} UserInterface;

//	���������� ��������� ���� pUserInterface �� ��������� UserInterface
typedef UserInterface* pUserInterface;

//	������� ���������� ��������� �� ���������������� ���������
pUserInterface UIInitialize();
//	������� ������� ������� ������� � ���������
void UIAbout(pUserInterface UI);
//	������� ������� ���� ��� �������������� � �������������
//	� ���������� ��������� ������������� �����
int UIMenu(pUserInterface UI);
//	������� ���������� ��������� ������������� ����������
//	�����, ������� ������ ��������� ������
int UIGetTurnsCount(pUserInterface UI);
//	������� ������ ����� �������
void UIDrawMap(pUserInterface UI, pAnimals animals, Settings settings);
//	������� ������ ���������� �������� ������� ����
void UIPrintStats(pUserInterface UI, pAnimCounter animCounter, int turnsCount);
//	������� ������ ��������� ������
void UIError(pUserInterface UI, char* error);
//	������� ������� ������ ��-��� ��������� ����������������� ����������
void UIDestroy(pUserInterface UI);

#endif // !USERINTERFACE_H
