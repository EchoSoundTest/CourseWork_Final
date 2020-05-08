#include <stdlib.h>
#include <stdio.h>

#include "userinterface.h"

pUserInterface UIInitialize() {
	pUserInterface UI = (pUserInterface)malloc(sizeof(UserInterface));
	return UI;
}

void UIAbout(pUserInterface UI) {
	(void)UI;
	printf("Программа \"Модель Хищник-жертва\"\n");
	printf("Автор: Киреев А.П.\n");
	system("pause");
}

int UIMenu(pUserInterface UI) {
	static char* menu[] = {
		"Вывести состояние модели",
		"Выполнить один шаг модели",
		"Выполнить n шагов модели",
		"Выход"
	};
	int actions_count = sizeof(menu) / sizeof(char*);
	(void)UI;

	system("cls");
	for (int i = 0; i < actions_count; i++) {
		printf("%d. %s\n", i + 1, menu[i]);
	}

	printf("Выберите действие: ");
	int action;
	action = UIGetAction(UI) - 1;
	return action;
}

//	Функция возвращает выбранный пользователем пункт меню
int UIGetAction(pUserInterface UI) {
	int action;
	(void)UI;
	scanf("%d", &action);
	return action;
}

int UIGetTurnsCount(pUserInterface UI) {
	int turns_count;
	(void)UI;
	printf("Введите количество шагов: ");
	scanf("%d", &turns_count);
	return turns_count;
}

void UIError(pUserInterface UI, char* error) {
	(void)UI;
	printf("Ошибка: %s\n", error);
	system("pause");
}

void UIDestroy(pUserInterface UI) {
	free(UI);
}