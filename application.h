#ifndef APPLICATION_H
#define APPLICATION_H

#include "userinterface.h"
#include "settings.h"
#include "animals.h"
#include "animalsmap.h"
#include "turn.h"

//	Определяем структурный тип Application
typedef struct {
	pUserInterface UI;
	Settings settings;
	pAnimals animals;
	pAnimCounter animCount;
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
