#ifndef SETTINGS_H
#define SETTINGS_H

//	Модуль "Настройки" содержит функции и определения,
//	необходимые для получения и хранения вводимых
//	пользователем первоначальных настроек модели

#include "utils.h"

typedef struct {
	//	Размер карты
	int map_length;
	//	Шанс размножения кролика в процентах
	int reprod_chance;
	//	Начальный уровень жизни волков
	int wolf_health;
	//	Диапазон количества кроликов (min, max)
	int rab1, rab2;
	//	Диапазон количества волков (min, max)
	int wlf_m1, wlf_m2;
	//	Диапазон количества волчиц (min, max)
	int wlf_f1, wlf_f2;
} Settings;

//	Функция возвращает введенные пользователем настройки
//	(начальные параметры) модели
Settings SettingsInitialize();

#endif // !SETTINGS_H
