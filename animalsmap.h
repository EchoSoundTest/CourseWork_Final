#ifndef ANIMALSMAP_H
#define ANIMALSMAP_H

//	Модуль "Карта" содержит функции,
//	необходимые для генерации карты модели

#include "animals.h"
#include "settings.h"
#include "utils.h"

//	Функция возвращает указатель на структуру счетчика животных
pAnimCounter AMInitializeAnimalCounter();
//	Функция возвращает указатель на массив-карту животных
//	pAnimals animals - указатель на массив-карту
//	pAnimCounter animCounter - указатель на счетчик животных
//	Settings settings - настройки
pAnimals AMGenerateModel(pAnimCounter animCounter, Settings settings);
//	Функция очистки памяти из-под массива-карты животных и счетчика животных
void AMDestroy(pAnimals animals, pAnimCounter animCounter);

#endif // !ANIMALSMAP_H
