#ifndef USERINTERFACE_H
#define USERINTERFACE_H

//	Модуль "Пользовательский интерфейс" содержит
//	функции и определения, необходимые для работы с пользователем

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#include "animals.h"
#include "settings.h"
#include "utils.h"

//	Определяем структурный тип UserInterface,
//	отвечающий за работу с пользователем
typedef struct {
	//	Дескриптор консоли
	HANDLE hConsole;
} UserInterface;

//	Определяем указатель типа pUserInterface на структуру UserInterface
typedef UserInterface* pUserInterface;

//	Функция возвращает указатель на пользовательский интерфейс
pUserInterface UIInitialize();
//	Функция выводит краткую справку о программе
void UIAbout(pUserInterface UI);
//	Функция выводит меню для взаимодействия с пользователем
//	и возвращает выбранный пользователем пункт
int UIMenu(pUserInterface UI);
//	Функция возвращает введенное пользователем количество
//	шагов, которые должна совершить модель
int UIGetTurnsCount(pUserInterface UI);
//	Функция вывода карты острова
void UIDrawMap(pUserInterface UI, pAnimals animals, Settings settings);
//	Функция вывода количества животных каждого вида
void UIPrintStats(pUserInterface UI, pAnimCounter animCounter, int turnsCount);
//	Функция вывода возникших ошибок
void UIError(pUserInterface UI, char* error);
//	Функция очистки памяти из-под структуры пользовательского интерфейса
void UIDestroy(pUserInterface UI);

#endif // !USERINTERFACE_H
