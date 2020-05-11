#ifndef APPLICATION_H
#define APPLICATION_H

//	Модуль "Приложение", содержащий функции и определения,
//	необходимые для работы всего приложения в целом

#include "userinterface.h"
#include "settings.h"
#include "animals.h"
#include "animalsmap.h"
#include "turn.h"

//	Определяем структурный тип Application,
//	отвечающий за работу приложения
typedef struct {
	//	Указатель на исполнитель "Пользовательский интерфейс"
	pUserInterface UI;
	//	Структура "Настройки"
	Settings settings;
	//	Указатель на карту-массив животных
	pAnimals animals;
	//	Указатель на счетчик количества животных
	pAnimCounter animCount;
	//	Счетчик количества ходов
	int turnsCount;
} Application;

//	Определяем указатель типа pApplication на структуру Application
typedef Application* pApplication;

//	Функция инициализации приложения
void AppInitialize(pApplication app);
//	Функция выполнения приложения
int AppRun(pApplication app);
//	Функция закрытия приложения
void AppDestroy(pApplication app);



#endif // !APPLICATION_H
