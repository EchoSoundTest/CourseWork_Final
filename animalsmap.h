#ifndef ANIMALSMAP_H
#define ANIMALSMAP_H

//	������ "�����" �������� �������,
//	����������� ��� ��������� ����� ������

#include "animals.h"
#include "settings.h"
#include "utils.h"

//	������� ���������� ��������� �� ��������� �������� ��������
pAnimCounter AMInitializeAnimalCounter();
//	������� ���������� ��������� �� ������-����� ��������
//	pAnimals animals - ��������� �� ������-�����
//	pAnimCounter animCounter - ��������� �� ������� ��������
//	Settings settings - ���������
pAnimals AMGenerateModel(pAnimCounter animCounter, Settings settings);
//	������� ������� ������ ��-��� �������-����� �������� � �������� ��������
void AMDestroy(pAnimals animals, pAnimCounter animCounter);

#endif // !ANIMALSMAP_H
