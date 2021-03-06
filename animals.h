#ifndef ANIMALS_H
#define ANIMALS_H

//	������ "��������" �������� �����������,
//	����������� ��� ���������������� ���� ������

//	������������ ����� ��������
enum Animals_ID {
	A_VOID,
	A_RABBIT,
	A_WOLF_M,
	A_WOLF_F
};

//	���������, ���������� ���������� � ��������
typedef struct {
	//	��� ���������
	int type;
	//	�-���������� ���������
	int x;
	//	Y-���������� ���������
	int y;
	//	���������� ����� ���������
	int health;
	//	����, ����������, ������ �������� (1) ��� ��� (0)
	int isMoved;
} Animals;

//	��������� �� ��������� Animals
typedef Animals* pAnimals;

//	������, ���������� �������, ������������ ������ ���� ��������
static const char Animal_symbols[4] = { ' ', 191, '@', 167 }; 
// ������, ���������� ����� ��� ������ �������� ��������
static const int Animal_colors[4] = { 0, 2, 4, 8 };


//	���������, ���������� �������� ��� �������� ���� �����
typedef struct {
	int rab_cnt;
	int wlf_m_cnt;
	int wlf_f_cnt;
} AnimCounter;

//	��������� �� ��������� AnimCounter
typedef AnimCounter* pAnimCounter;

#endif // !ANIMALS_H
