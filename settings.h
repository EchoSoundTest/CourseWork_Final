#ifndef SETTINGS_H
#define SETTINGS_H

#define DEBUG
#define _PDEBUG

#include "utils.h"

typedef struct {
	int map_length;
	int reprod_chance;
	int wolf_health;
	int rab1, rab2;
	int wlf_m1, wlf_m2;
	int wlf_f1, wlf_f2;
} Settings;

//	Функция возвращает введенные пользователем настройки
//	(начальные параметры) модели
Settings SettingsInitialize();

#endif // !SETTINGS_H
