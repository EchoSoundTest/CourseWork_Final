#ifndef ANIMALSMAP_H
#define ANIMALSMAP_H

#include "animals.h"
#include "settings.h"
#include "utils.h"

//	Функция возвращает указатель на структуру счетчика животных
pAnimCounter AMInitializeAnimalCounter();
//	Функция возвращает указатель на массив-карту животных
pAnimals AMGenerateModel(pAnimCounter anim_cnt, Settings settings);
//	Функция очистки памяти из-под массива-карты животных и счетчика животных
void AMDestroy(pAnimals animals, pAnimCounter animCounter);

#endif // !ANIMALSMAP_H
