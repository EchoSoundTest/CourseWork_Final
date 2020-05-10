#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <windows.h>

//	Функция возвращает случайное целое число в диапазоне от val1 до val2 включительно
int randomize(int val1, int val2);

void printFrame(int count, char filler, char frameSymbol);

void printColoredSymbol(HANDLE hConsole, WORD color, char symbol);

int readIntFromConsole(char * str, int min, int max);

#endif // !UTILS_H
