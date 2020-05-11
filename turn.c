#include "turn.h"

//	Функция-заглушка, необходимая для корректной работы общей функции хода
//	и используемого массива указателей на функции хода каждого животного
//	Animals cur_anim - указатель на зверя, вокруг которого надо получить окружающую местность
//	pAnimals anim_arr - указатель на массив-карту
//	pAnimCounter animCounter - указатель на счетчик животных
//	Settings settings - настройки
//	int map_len - размер карты
void TTurnVoid(pAnimals cur_anim, pAnimals anim_arr, Settings settings, pAnimCounter animCounter);
//	Функция хода кролика
void TTurnRabbit(pAnimals cur_anim, pAnimals anim_arr, Settings settings, pAnimCounter animCounter);
//	Функция хода волка
void TTurnWolf_M(pAnimals cur_anim, pAnimals anim_arr, Settings settings, pAnimCounter animCounter);
//	Функция хода волчицы
void TTurnWolf_F(pAnimals cur_anim, pAnimals anim_arr, Settings settings, pAnimCounter animCounter);
//	Функция осуществляет проверку окружающей животное местности
//	int *id_arr - указатель на массив для записи состояний окружающей местности
void TCheckNearAnims(Animals cur_anim, pAnimals anim_arr, int *id_arr, int map_len);
//	Функция отвечает за появление нового волка или волчицы
//	int X - X-координата волка
//	int Y - Y-координата волка
//	int index - индекс выбранной волчицы в массиве состояний окружающей среды
void TPlaceNewWolf(pAnimals anim_arr, int X, int Y, int index, Settings settings, pAnimCounter animCounter);
//	Функция осуществляет выбор места на поле,
//	в которое будет сделан ход животного
//	int *id_arr - указатель на массив для записи состояний окружающей местности
//	int turn_type - тип зверя, к которому будет сделан ход
//	int turn_num - номер зверя данного типа в массиве
int TPrepareMoving(int *id_arr, int turn_type, int turn_num);
//	Функция осуществляет перемещение заданного животного в заданное место
//	int index - индекс клетки, в которую нужно переместить
pAnimals TMoveAnimal(pAnimals cur_anim, pAnimals anim_arr, int index, int map_len);
//	Функция учета рождения животного в статистике
//	int animalType - тип родившегося животного
void TAnimalBorn(pAnimCounter animCounter, int animalType);
//	Функция учета смерти животного в статистике
//	int animalType - тип умершего животного
void TAnimalDie(pAnimCounter animCounter, int animalType);

void TTurnManager(pAnimals anim_arr, Settings settings, pAnimCounter animCounter, int turnsCount, int * allTurnsCount) {
	int offset;
	static void(*animal_turn[4])(pAnimals, pAnimals, Settings, pAnimCounter);
	animal_turn[A_VOID] = TTurnVoid;
	animal_turn[A_RABBIT] = TTurnRabbit;
	animal_turn[A_WOLF_M] = TTurnWolf_M;
	animal_turn[A_WOLF_F] = TTurnWolf_F;

	while (turnsCount != 0) {
		for (int mapY = 0; mapY < settings.map_length; mapY++) {
			for (int mapX = 0; mapX < settings.map_length; mapX++) {
				offset = mapX + mapY * settings.map_length;
				if ((anim_arr + offset)->isMoved == 0) {
					(anim_arr + offset)->isMoved = 1;
					animal_turn[((anim_arr + offset)->type)]((anim_arr + offset), anim_arr, settings, animCounter);
				}
			}
		}
		for (int mapY = 0; mapY < settings.map_length; mapY++) {
			for (int mapX = 0; mapX < settings.map_length; mapX++) {
				offset = mapX + mapY * settings.map_length;
				(anim_arr + offset)->isMoved = 0;
			}
		}
		turnsCount--;
		(*allTurnsCount)++;
	}
}

void TTurnVoid(pAnimals cur_anim, pAnimals anim_arr, Settings settings, pAnimCounter animCounter) {

}

void TTurnRabbit(pAnimals cur_anim, pAnimals anim_arr, Settings settings, pAnimCounter animCounter) {
	int nearAnims[9];		//	Массив содержимого клеток вокруг животного
	int turn_vars = 0;		//	Количество вариантов хода
	int num;				//	Номер выбранного варианта хода
	int index;				//	Индекс клетки под номером num в массиве nearAnims

	TCheckNearAnims(*cur_anim, anim_arr, nearAnims, settings.map_length);
	for (int i = 0; i < 9; i++) {
		if (nearAnims[i] == A_VOID) {
			turn_vars++;														//	Определяем количество вариантов хода
		}
	}
	num = randomize(1, turn_vars);												//	Определяем номер выбранного варианта хода
	index = TPrepareMoving(nearAnims, A_VOID, num);
	TMoveAnimal(cur_anim, anim_arr, index, settings.map_length);

	if (randomize(1, 100) <= settings.reprod_chance) {
		int offset;
		TCheckNearAnims(*cur_anim, anim_arr, nearAnims, settings.map_length);
		nearAnims[4] = A_RABBIT;
		for (int i = 0; i < 9; i++) {
			if (nearAnims[i] == 0) {
				turn_vars++;													//	Определяем количество клеток, в которых
			}																	//	может появиться новый кролик
		}
		num = randomize(1, turn_vars);
		for (int i = 0; i < 9; i++) {
			if (nearAnims[i] == 0) {
				num--;
			}
			if (num == 0) {
				offset = (cur_anim->x + (i % 3 - 1)) + (cur_anim->y + (i / 3 - 1)) * settings.map_length;
				(anim_arr + offset)->type = A_RABBIT;
				(anim_arr + offset)->isMoved = 1;
				TAnimalBorn(animCounter, A_RABBIT);
				break;
			}
		}
	}
}

void TTurnWolf_M(pAnimals cur_anim, pAnimals anim_arr, Settings settings, pAnimCounter animCounter) {
	int nearAnims[9];		//	Массив содержимого клеток вокруг животного
	int rabbits_cnt = 0;	//	Количество кроликов вокруг волка
	int voids_cnt = 0;		//	Количество пустых клеток вокруг волка
	int wolf_f_cnt = 0;		//	Количество волчиц вокруг волка
	int num;				//	Номер выбранного варианта хода
	int turn_type;			//	Тип хода - тип зверя (волчица/заяц/пустота), к которому сходит волк
	int index;				//	Индекс клетки под номером num в массиве nearAnims

	TCheckNearAnims(*cur_anim, anim_arr, nearAnims, settings.map_length);
	for (int i = 0; i < 9; i++) {
		if (nearAnims[i] == A_VOID) {
			voids_cnt++;
		}
		else if (nearAnims[i] == A_RABBIT) {
			rabbits_cnt++;
		}
		else if (nearAnims[i] == A_WOLF_F) {
			wolf_f_cnt++;
		}
	}

	if ((rabbits_cnt == 0) && (wolf_f_cnt != 0)) {
		num = randomize(1, wolf_f_cnt);
		index = TPrepareMoving(nearAnims, A_WOLF_F, num);
		TPlaceNewWolf(anim_arr, cur_anim->x, cur_anim->y, index, settings, animCounter);
	}
	else {
		if (rabbits_cnt != 0) {
			num = randomize(1, rabbits_cnt);
			turn_type = A_RABBIT;
			cur_anim->health += settings.wolf_health;
			TAnimalDie(animCounter, A_RABBIT);
		}
		else {
			num = randomize(1, voids_cnt);
			turn_type = A_VOID;
		}
		index = TPrepareMoving(nearAnims, turn_type, num);
		cur_anim = TMoveAnimal(cur_anim, anim_arr, index, settings.map_length);
	}

	cur_anim->health--;
	if (cur_anim->health <= 0) {
		cur_anim->type = A_VOID;
		TAnimalDie(animCounter, A_WOLF_M);
	}
}

void TTurnWolf_F(pAnimals cur_anim, pAnimals anim_arr, Settings settings, pAnimCounter animCounter) {
	int nearAnims[9];			//	Массив содержимого клеток вокруг животного
	int rabbits_cnt = 0;		//	Количество кроликов вокруг волчицы
	int voids_cnt = 0;			//	Количество пустых клеток вокруг волчицы
	int num;					//	Номер выбранного варианта хода
	int turn_type;				//	Тип хода - тип зверя (заяц/пустота), к которому сходит волчица
	int index = 0;				//	Индекс клетки под номером num в массиве nearAnims
								
	TCheckNearAnims(*cur_anim, anim_arr, nearAnims, settings.map_length);
	for (int i = 0; i < 9; i++) {
		if (nearAnims[i] == A_VOID) {
			voids_cnt++;
		}
		else if (nearAnims[i] == A_RABBIT) {
			rabbits_cnt++;
		}
	}

	if (rabbits_cnt != 0) {
		num = randomize(1, rabbits_cnt);
		turn_type = A_RABBIT;
		cur_anim->health += settings.wolf_health;
		TAnimalDie(animCounter, A_RABBIT);
	}
	else {
		num = randomize(1, voids_cnt);
		turn_type = A_VOID;
	}

	index = TPrepareMoving(nearAnims, turn_type, num);
	cur_anim = TMoveAnimal(cur_anim, anim_arr, index, settings.map_length);

	cur_anim->health--;
	if (cur_anim->health <= 0) {
		cur_anim->type = A_VOID;
		TAnimalDie(animCounter, A_WOLF_F);
	}
}

void TCheckNearAnims(Animals cur_anim, pAnimals anim_arr, int *id_arr, int map_len) {
	int index = 0;		//	Индекс клетки в массиве nearAnims по указателю id_arr
	int offset;			//	Сдвиг указателя anim_arr
	int offsetX;		//	X-координата клетки под индексом index
	int offsetY;		//	Y-координата клетки под индексом index

	for (int locY = -1; locY <= 1; locY++) {
		for (int locX = -1; locX <= 1; locX++) {
			if ((locY == 0) && (locX == 0)) {
				*(id_arr + index) = A_VOID;
			}
			else {
				offsetX = cur_anim.x + locX;
				offsetY = cur_anim.y + locY;
				if ((offsetY > -1) && (offsetY < map_len) && (offsetX > -1) && (offsetX < map_len)) {
					offset = offsetX + offsetY * map_len;
					*(id_arr + index) = (anim_arr + offset)->type;
				}
				else {
					*(id_arr + index) = -1;
				}
			}
			index++;
		}
	}
}

void TPlaceNewWolf(pAnimals anim_arr, int X, int Y, int index, Settings settings, pAnimCounter animCounter) {
	int locX = X + index % 3 - 1;							//	X-координата волчицы, выбранной волком
	int locY = Y + index / 3 - 1;							//	Y-координата волчицы, выбранной волком
	int wolf_gen;											//	Пол волчонка (волк/волчица)
	int nearAnims[9];										//	Массив содержимого клеток вокруг волчицы
	int num = 0;											//	Номер выбранной клетки для волчонка
	int wolf_places = 0;									//	Количество клеток, куда можно установить волчонка
	int offset = locX + locY * settings.map_length;			//	Сдвиг указателя anim_arr
	int born = -1;											//	Индекс клетки для рождения волчонка в массиве nearAnim

	TCheckNearAnims(*(anim_arr + offset), anim_arr, nearAnims, settings.map_length);
	nearAnims[4] = A_WOLF_F;
	for (int i = 0; i < 9; i++) {
		if (nearAnims[i] == A_VOID) {
			wolf_places++;
		}
	}

	if ((wolf_places > 0) && (wolf_places < 9)) {
		num = randomize(1, wolf_places);
		if ((born = TPrepareMoving(nearAnims, A_VOID, num)) >= 0) {
			locX = locX + born % 3 - 1;						//	X-координата волчонка
			locY = locY + born / 3 - 1;						//	Y-координата волчонка
			offset = locX + locY * settings.map_length;
			wolf_gen = randomize(A_WOLF_M, A_WOLF_F);

			(anim_arr + offset)->isMoved = 1; 
			(anim_arr + offset)->health = settings.wolf_health;
			(anim_arr + offset)->type = wolf_gen;
			TAnimalBorn(animCounter, wolf_gen);
		}
	}
}

int TPrepareMoving(int *id_arr, int turn_type, int turn_num) {
	int index;
	for (int i = 0; i < 9; i++) {
		if (*(id_arr + i) == turn_type) {
			turn_num--;
		}
		if (turn_num == 0) {
			return i;
		}
	}
	return -1;
}

pAnimals TMoveAnimal(pAnimals cur_anim, pAnimals anim_arr, int index, int map_len) {
	int locX = index % 3 - 1;		//	X-координата перемещаемого зверя
	int locY = index / 3 - 1;		//	Y-координата перемещаемого зверя
	int offset;						//	Сдвиг указателя anim_arr

	if (!((locX == 0) && (locY == 0))) {
		locX += cur_anim->x;
		locY += cur_anim->y;
		offset = locX + locY * map_len;
		(anim_arr + offset)->type = cur_anim->type;
		(anim_arr + offset)->health = cur_anim->health;
		(anim_arr + offset)->isMoved = cur_anim->isMoved;
		cur_anim->type = A_VOID;
		return (anim_arr + offset);
	}
	return cur_anim;				// Возвращаем новое положение зверя
}

void TAnimalBorn(pAnimCounter animCounter, int animalType) {
	switch (animalType) {
	case A_RABBIT:
		animCounter->rab_cnt++;
		break;
	case A_WOLF_M:
		animCounter->wlf_m_cnt++;
		break;
	case A_WOLF_F:
		animCounter->wlf_f_cnt++;
		break;
	}
}

void TAnimalDie(pAnimCounter animCounter, int animalType) {
	switch (animalType) {
	case A_RABBIT:
		animCounter->rab_cnt--;
		break;
	case A_WOLF_M:
		animCounter->wlf_m_cnt--;
		break;
	case A_WOLF_F:
		animCounter->wlf_f_cnt--;
		break;
	}
}