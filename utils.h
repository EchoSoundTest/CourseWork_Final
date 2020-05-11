#ifndef UTILS_H
#define UTILS_H

//	Модуль "Вспомогательные функции" содержит функции,
//	которые упрощают разработанные алгоритмы

#include <stdio.h>
#include <windows.h>

//	Функция возвращает случайное целое число в диапазоне от val1 до val2 включительно
int randomize(int val1, int val2);
//	Вспомогательная функция рисования рамки заданными символами заданного размера
//	int count - длина боковой стороны рамки (количество filler)
//	char filler - символ, составляющий боковую сторону рамки
//	char frameSymbol - символ угла рамки
void printFrame(int count, char filler, char frameSymbol);
//	Вспомогательная функция вывода цветного символа заданного цвета
//	HANDLE hConsole - дескриптиор консоли
//	WORD color - цвет выводимого символа
//	char symbol - выводимый символ
void printColoredSymbol(HANDLE hConsole, WORD color, char symbol);
//	Функция считывания целого числа из консоли в заданном диапазоне
//	char * str - строка с информацией о вводимом числе
//	int min - минимальное значение вводимого числа
//	int max - максимальное значение вводимого числа
int readIntFromConsole(char * str, int min, int max);

#endif // !UTILS_H
