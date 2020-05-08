#include <locale.h>
#include "application.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Application app;
	int returnCode;
	AppInitialize(&app);
	returnCode = AppRun(&app);
	AppDestroy(&app);
	return returnCode;
}
