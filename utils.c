#include "utils.h"

int randomize(int val1, int val2) {
	int res = val1 + rand() % (val2 - val1 + 1);
	return res;
}

void printFrame(int count, char filler, char frameSymbol) {
	printf("%c", frameSymbol);
	for (int i = 0; i < count; i++) {
		printf("%c", filler);
	}
	printf("%c\n", frameSymbol);
}

void printColoredSymbol(HANDLE hConsole, WORD color, char symbol) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;	//	���������� � ���������� ������ ������� ������������
	DWORD defColor = 0;					//	���� ������� ������������
	DWORD clForeground = 7;				//  ���� ������ ������� �� ���������
	DWORD clBackground = 0;				//  ���� ���� ������� �� ���������
	
	if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		defColor = csbi.wAttributes;	// �������� ���� ������� ������������

		// ��������� ����� ���� � ������
		clBackground = (defColor >> 4);
		clForeground = defColor ^ (clBackground << 4);

		// ���������� ���� ������ ������ ����� ������������
		if (clBackground == color) {
			color = clForeground;
		}
		// ����������� ���� ������������, ���� �� ����� ������ � ������������ ������ �������
		if (clForeground == color) {
			color = 15 ^ clBackground;
		}
	}	

	//	������ �������� ��������� �������� ���� ���� ������� ������������
	//	� �� ��� ������ ������� ������� ������, �� ����� ����
	SetConsoleTextAttribute(hConsole, (DWORD)((clBackground << 4) | color));
	printf("%c", symbol);
	SetConsoleTextAttribute(hConsole, defColor);
}

int readIntFromConsole(char * str, int min, int max) {
	char action[1024];	//	������, �������� �������������
	int val;			//	��������, ���������� �� ������, ��������� �������������

	if (str != "") {
		printf("%s (%d-%d): ", str, min, max);
	}
	do {																			//	�������� ��������� ������������� ������
		scanf("%s", &action);														//	� ��������� �� �� ��, ��� ���: 1) �����
	} while ((sscanf(action, "%d", &val) != 1) || (val < min) || (val > max));		//	2) ����� � �������� ���������

	return val;
}
