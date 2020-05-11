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
	CONSOLE_SCREEN_BUFFER_INFO csbi;	//	Информация о настройках вывода консоли пользователя
	int defColor = 0;					//	Цвет консоли пользователя
	
	if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		defColor = csbi.wAttributes;	// Получаем цвет консоли пользователя
	}	

	//	Данная операция позволяет получить цвет фона консоли пользователя
	//	и на его основе вывести цветной символ, не меняя фона
	SetConsoleTextAttribute(hConsole, (DWORD)(((defColor >> 4) << 4) | color));
	printf("%c", symbol);
	SetConsoleTextAttribute(hConsole, defColor);
}

int readIntFromConsole(char * str, int min, int max) {
	char action[1024];	//	Строка, вводимая пользователем
	int val;			//	Значение, полученное из строки, введенной пользователем

	if (str != "") {
		printf("%s (%d-%d): ", str, min, max);
	}
	do {																			//	Получаем введенную пользователем строку
		scanf("%s", &action);														//	И проверяем ее на то, что это: 1) число
	} while ((sscanf(action, "%d", &val) != 1) || (val < min) || (val > max));		//	2) число в заданном диапазоне

	return val;
}
