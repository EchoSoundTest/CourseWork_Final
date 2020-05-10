#include <locale.h>
#include <time.h>

#include "application.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	Application app;
	int returnCode;
	AppInitialize(&app);
	returnCode = AppRun(&app);
	AppDestroy(&app);
	return returnCode;
}
