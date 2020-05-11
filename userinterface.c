#include "userinterface.h"

//	��������������� ������� ������ ����������
void UIPrintStatsHelper(pUserInterface UI, char* animName, int animColor, char animSymbol, int animCount);

pUserInterface UIInitialize() {
	pUserInterface UI = (pUserInterface)malloc(sizeof(UserInterface));
	UI->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	return UI;
}

void UIAbout(pUserInterface UI) {
	(void)UI;
	printf("\n��������� \"������ ������-������\"\n");
	printf("�����: ������ �.�.\n\n");
	system("pause");
}

int UIMenu(pUserInterface UI) {
	static char* menu[] = {
		"��������� ���� ��� ������",
		"��������� n ����� ������",
		"�������� ��������� ������",
		"�������",
		"� ���������"
	};
	int actions_count = sizeof(menu) / sizeof(char*);
	(void)UI;
	
	printf("\n");
	printFrame(40, '-', '+');
	printFrame(40, ' ', '|');
	printf("|                � � � �                 |\n");
	printFrame(40, ' ', '|');
	printFrame(40, '-', '+');
	printFrame(40, ' ', '|');
	for (int i = 0; i < actions_count; i++) {
		printf("|   [ ");
		printColoredSymbol(UI->hConsole, 10, i + 49);
		printf(" ] %-28.28s   |\n", menu[i]);
	}
	printFrame(40, ' ', '|');
	printf("|   [ ");
	printColoredSymbol(UI->hConsole, 12, '0');
	printf(" ] %-28s   |\n", "�����");
	printFrame(40, ' ', '|');
	printFrame(40, '-', '+');

	printf("�������� ��������: ");
	int action;
	action = readIntFromConsole("", 0, actions_count);
	return action;
}

int UIGetTurnsCount(pUserInterface UI) {
	int turns_count;
	(void)UI;
	printf("������� ���������� �����: ");
	do {
		scanf("%d", &turns_count);
	} while (turns_count < 0);

	return turns_count;
}

void UIDrawMap(pUserInterface UI, pAnimals animals, Settings settings) {
	(void)UI;
	int offset;
	system("cls");

	printFrame(settings.map_length, '-', '+');

	for (int mapY = 0; mapY < settings.map_length; mapY++) {
		printf("|");

		for (int mapX = 0; mapX < settings.map_length; mapX++) {
			offset = mapX + mapY * settings.map_length;
			printColoredSymbol(UI->hConsole, Animal_colors[(animals + offset)->type], Animal_symbols[(animals + offset)->type]);
		}
		printf("|\n");
	}
	
	printFrame(settings.map_length, '-', '+');
}

void UIPrintStats(pUserInterface UI, pAnimCounter animCounter, int turnsCount) {
	(void)UI;
	printf("\n����������:\n");
	UIPrintStatsHelper(UI, "�������", Animal_colors[A_RABBIT], Animal_symbols[A_RABBIT], animCounter->rab_cnt);
	UIPrintStatsHelper(UI, "�����", Animal_colors[A_WOLF_M], Animal_symbols[A_WOLF_M], animCounter->wlf_m_cnt);
	UIPrintStatsHelper(UI, "�������", Animal_colors[A_WOLF_F], Animal_symbols[A_WOLF_F], animCounter->wlf_f_cnt);
	printf("���������� ����� - %d", turnsCount);
	printf("\n");
}

void UIPrintStatsHelper(pUserInterface UI,  char* animName, int animColor, char animSymbol, int animCount) {
	(void)UI;

	printf(" ");
	printColoredSymbol(UI->hConsole, animColor, animSymbol);
	printf("  - %-8s - %5d ������\n", animName, animCount);
}

void UIError(pUserInterface UI, char* error) {
	(void)UI;
	printf("������: %s\n", error);
	system("pause");
}

void UIDestroy(pUserInterface UI) {
	free(UI);
}