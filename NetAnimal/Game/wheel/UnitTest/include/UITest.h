#ifndef __Orz_UnitTest_UITest__
#define __Orz_UnitTest_UITest__
#include "UnitTestConfig.h"
#include <CEGUI/cegui.h>
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/

BOOST_AUTO_TEST_CASE(UITest)
{	
	
	using namespace CEGUI;
	//CEGUI::SchemeManager::getSingleton().create("TaharezLook.scheme");
	//CEGUI::SchemeManager::getSingleton().create("VanillaSkin.scheme");
	ImagesetManager::getSingleton().create("UI1.imageset");
	ImagesetManager::getSingleton().create("UI2.imageset");
	ImagesetManager::getSingleton().create("UI3.imageset");
	//ImagesetManager::getSingleton().create("UI4.imageset");
	CEGUI::System::getSingleton().setGUISheet(CEGUI::WindowManager::getSingleton().loadWindowLayout("AnimalUI.layout"));
	CEGUI::System::getSingleton().updateWindowContainingMouse();


	
	CEGUI::Window * _win= CEGUI::WindowManager::getSingleton().loadWindowLayout("dan.layout");
	_win->setAlwaysOnTop(true);
	_win->hide();
	CEGUI::Window * f = CEGUI::WindowManager::getSingleton().getWindow("AnimalUI");
	f->addChildWindow(_win);
	_win->show();
	CEGUI::System::getSingleton().updateWindowContainingMouse();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
}

#endif