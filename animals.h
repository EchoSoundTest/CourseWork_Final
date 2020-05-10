#ifndef ANIMALS_H
#define ANIMALS_H

enum Animals_ID {
	A_VOID,
	A_RABBIT,
	A_WOLF_M,
	A_WOLF_F
};

typedef struct {
	int type;
	int x;
	int y;
	int health;
	int isMoved;
} Animals;

typedef Animals* pAnimals;


//static const char Animal_symbols[4] = { '.', 191, 134, 135 }; 
static const char Animal_symbols[4] = { ' ', 191, '@', 167 }; 
static const int Animal_colors[4] = { 0, 2, 4, 8 };

typedef struct {
	int rab_cnt;
	int wlf_m_cnt;
	int wlf_f_cnt;
} AnimCounter;

typedef AnimCounter* pAnimCounter;

#endif // !ANIMALS_H
