#include <stdlib.h>
#include <stdio.h>

#include "userinterface.h"

pUserInterface UIInitialize() {
	pUserInterface UI = (pUserInterface)malloc(sizeof(UserInterface));
	return UI;
}

void UIAbout(pUserInterface UI) {
	(void)UI;
	printf("��������� \"������ ������-������\"\n");
	printf("�����: ������ �.�.\n");
	system("pause");
}

int UIMenu(pUserInterface UI) {
	static char* menu[] = {
		"������� ��������� ������",
		"��������� ���� ��� ������",
		"��������� n ����� ������",
		"�����"
	};
	int actions_count = sizeof(menu) / sizeof(char*);
	(void)UI;

	system("cls");
	for (int i = 0; i < actions_count; i++) {
		printf("%d. %s\n", i + 1, menu[i]);
	}

	printf("�������� ��������: ");
	int action;
	action = UIGetAction(UI) - 1;
	return action;
}

//	������� ���������� ��������� ������������� ����� ����
int UIGetAction(pUserInterface UI) {
	int action;
	(void)UI;
	scanf("%d", &action);
	return action;
}

int UIGetTurnsCount(pUserInterface UI) {
	int turns_count;
	(void)UI;
	printf("������� ���������� �����: ");
	scanf("%d", &turns_count);
	return turns_count;
}

void UIError(pUserInterface UI, char* error) {
	(void)UI;
	printf("������: %s\n", error);
	system("pause");
}

void UIDestroy(pUserInterface UI) {
	free(UI);
}