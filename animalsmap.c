#include <stdlib.h>

#include "animalsmap.h"

//	Функция случайным образом распределяет животных по карте
void AMPlaceAnimals(pAnimals anim_arr, Settings settings, int cur_anim_cnt, int an_type);

pAnimCounter AMInitializeAnimalCounter() {
	pAnimCounter anim_cnt = (pAnimCounter)malloc(sizeof(AnimCounter));
	return anim_cnt;
}

pAnimals AMGenerateModel(pAnimCounter anim_cnt, Settings settings) {
	int offset;
	pAnimals animals = (pAnimals)calloc(settings.map_length * settings.map_length, sizeof(Animals));
	anim_cnt->rab_cnt = randomize(settings.rab1, settings.rab2);
	anim_cnt->wlf_m_cnt = randomize(settings.wlf_m1, settings.wlf_m2);
	anim_cnt->wlf_f_cnt = randomize(settings.wlf_f1, settings.wlf_f2);

	for (int mapY = 0; mapY < settings.map_length; mapY++) {
		for (int mapX = 0; mapX < settings.map_length; mapX++) {
			offset = mapX + mapY * settings.map_length;
			(animals + offset)->type = A_VOID;
			(animals + offset)->x = mapX;
			(animals + offset)->y = mapY;
		}
	}

	AMPlaceAnimals(animals, settings, anim_cnt->rab_cnt, A_RABBIT);
	AMPlaceAnimals(animals, settings, anim_cnt->wlf_m_cnt, A_WOLF_M);
	AMPlaceAnimals(animals, settings, anim_cnt->wlf_f_cnt, A_WOLF_F);
	return animals;
}

void AMPlaceAnimals(pAnimals anim_arr, Settings settings, int cur_anim_cnt, int an_type) {
	int offset;
	while (cur_anim_cnt > 0) {
		for (int mapY = 0; mapY < settings.map_length; mapY++) {
			for (int mapX = 0; mapX < settings.map_length; mapX++) {
				offset = mapX + mapY * settings.map_length;
				if ((cur_anim_cnt > 0) && ((anim_arr + offset)->type == A_VOID) && (randomize(0, 100) > 99)) {
					(anim_arr + offset)->type = an_type;
					(anim_arr + offset)->x = mapX;
					(anim_arr + offset)->y = mapY;
					(anim_arr + offset)->health = settings.wolf_health;
					(anim_arr + offset)->isMoved = 0;
					cur_anim_cnt--;
				}
			}
		}
	}
}

void AMDestroy(pAnimals animals, pAnimCounter animCounter) {
	free(animals);
	free(animCounter);
}