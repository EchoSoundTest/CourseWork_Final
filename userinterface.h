#ifndef USERINTERFACE_H
#define USERINTERFACE_H


//	���������� ����������� ��� UserInterface
typedef struct {
	int dummy;
} UserInterface;

//	���������� ��������� ���� pUserInterface �� ��������� UserInterface
typedef UserInterface* pUserInterface;
//	������� ���������� ��������� �� ���������������� ���������
pUserInterface UIInitialize();
//	������� ������� ������� ������� � ���������
void UIAbout(pUserInterface UI);
//	������� ������� ���� ��� �������������� � �������������
//	� ���������� ��������� ������������� �����
int UIMenu(pUserInterface UI);
//	������� ���������� ��������� ������������� ����������
//	�����, ������� ������ ��������� ������
int UIGetTurnsCount(pUserInterface UI);
//	������� ������ ��������� ������
void UIError(pUserInterface UI, char* error);
//	������� ������� ������ ��-��� ��������� ����������������� ����������
void UIDestroy(pUserInterface UI);

#endif // !USERINTERFACE_H
