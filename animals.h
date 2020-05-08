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

const char Animal_symbols[] = { '.', 0x7F, '@', '#' };
const int Animal_colors[] = { 0, 12, 14, 10 };

typedef struct {
	int rab_cnt;
	int wlf_m_cnt;
	int wlf_f_cnt;
} Anim_counter;

#endif // !ANIMALS_H
