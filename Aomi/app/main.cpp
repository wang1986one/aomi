#include "Application.h"
#include <windows.h>

int main()
{
	try
	{
		Application app;

		while(!app.shouldQuit)
			app.update();
	}
	catch( Ogre::Exception& e )
	{
		ShowCursor(true);
		MessageBox(NULL, L"ss", L"An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
	}

	return 0;
}