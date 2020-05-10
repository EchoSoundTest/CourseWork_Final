#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <windows.h>

//	������� ���������� ��������� ����� ����� � ��������� �� val1 �� val2 ������������
int randomize(int val1, int val2);

void printFrame(int count, char filler, char frameSymbol);

void printColoredSymbol(HANDLE hConsole, WORD color, char symbol);

int readIntFromConsole(char * str, int min, int max);

#endif // !UTILS_H
