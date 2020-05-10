#ifndef TURN_H
#define TURN_H

#include "animals.h"
#include "settings.h"

//	Фунцкция управления ходом/ходами
void TTurnManager(pAnimals anim_arr, Settings settings, pAnimCounter animCounter, int turnsCount, int * allTurnsCount);

#endif // !TURN_H
