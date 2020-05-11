#ifndef ANIMALS_H
#define ANIMALS_H

//	Модуль "Животные" содержит определения,
//	необходимые для функционирования всей модели

//	Перечисление типов животных
enum Animals_ID {
	A_VOID,
	A_RABBIT,
	A_WOLF_M,
	A_WOLF_F
};

//	Структура, содержащая информацию о животном
typedef struct {
	//	Тип животного
	int type;
	//	Х-координата животного
	int x;
	//	Y-координата животного
	int y;
	//	Количество жизни животного
	int health;
	//	Флаг, означающий, ходило животное (1) или нет (0)
	int isMoved;
} Animals;

//	Указатель на структуру Animals
typedef Animals* pAnimals;

//	Массив, содежращий символы, обозначающие разные типы животных
static const char Animal_symbols[4] = { ' ', 191, '@', 167 }; 
// Массив, содержащий цвета для вывода символов животных
static const int Animal_colors[4] = { 0, 2, 4, 8 };


//	Структура, содержащаю счетчики для животных всех типов
typedef struct {
	int rab_cnt;
	int wlf_m_cnt;
	int wlf_f_cnt;
} AnimCounter;

//	Указатель на структуру AnimCounter
typedef AnimCounter* pAnimCounter;

#endif // !ANIMALS_H
