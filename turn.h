#ifndef TURN_H
#define TURN_H

//	Модуль "Ход" содержит функции, необходимые
//	для совершения хода зверями и обработки результатов
//	совершенного хода

#include "animals.h"
#include "settings.h"

//	Фунцкция управления ходом/ходами
//	pAnimals anim_arr - указатель на массив-карту
//	pAnimCounter animCounter - указатель на счетчик животных
//	Settings settings - настройки
//	int turnsCount - количество ходов, которые надо выполнить
//	int * allTurnsCount - указатель на общее выполненное количество ходов
void TTurnManager(pAnimals anim_arr, Settings settings, pAnimCounter animCounter, int turnsCount, int * allTurnsCount);

#endif // !TURN_H
