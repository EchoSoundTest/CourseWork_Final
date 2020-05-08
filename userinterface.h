#ifndef USERINTERFACE_H
#define USERINTERFACE_H


//	Определяем структурный тип UserInterface
typedef struct {
	int dummy;
} UserInterface;

//	Определяем указатель типа pUserInterface на структуру UserInterface
typedef UserInterface* pUserInterface;
//	Функция возвращает указатель на пользовательский интерфейс
pUserInterface UIInitialize();
//	Функция выводит краткую справку о программе
void UIAbout(pUserInterface UI);
//	Функция выводит меню для взаимодействия с пользователем
//	и возвращает выбранный пользователем пункт
int UIMenu(pUserInterface UI);
//	Функция возвращает введенное пользователем количество
//	шагов, которые должна совершить модель
int UIGetTurnsCount(pUserInterface UI);
//	Функция вывода возникших ошибок
void UIError(pUserInterface UI, char* error);
//	Функция очистки памяти из-под структуры пользовательского интерфейса
void UIDestroy(pUserInterface UI);

#endif // !USERINTERFACE_H
