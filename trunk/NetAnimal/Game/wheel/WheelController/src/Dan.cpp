#include "WheelControllerStableHeaders.h"
#include "Dan.h"
#include "DanListener.h"
using namespace Orz;

DanLine::DanLine(void)
{

}
DanLine::~DanLine(void)
{
}
void DanLine::push_back(CEGUI::Window * win)
{
	_windows.push_back(win);
}
void DanLine::write(int i, const std::string & text)
{
	_windows[i]->setText(text);
}
	
bool Dan::textAccepted(const CEGUI::EventArgs&) 
{
	CEGUI::String text = CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin")->getText();
	
	if(text.empty())
		return true;
	if(text.size() != 9)
	{
		_time = 1.0f;
		CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/W")->setProperty("Image","set:UI4 image:w1");
		
	}else
	{	
		if(_callback)
			_callback->uploadPassword(Ogre::StringConverter::parseInt(text.c_str()));
	}
	CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin")->setText("");
	return true;
}

Dan::Dan(DanListener * listener):_time(-1.f),_callback(listener)
{

	_win= CEGUI::WindowManager::getSingleton().loadWindowLayout("dan.layout");
	_win->setAlwaysOnTop(true);
	_win->hide();
	/*CEGUI::Window * f = CEGUI::WindowManager::getSingleton().getWindow("AnimalUI");
	f->addChildWindow(_win);*/
	

	
	for(int i = 0; i < 10; i++)
	{
		std::string n = boost::lexical_cast<std::string>(i);
		LinePtr line(new DanLine());
		for(int j=0;j<9; ++j)
		{
			//std::cout<<"Dan/Bg/Line0/Tt" + n + boost::lexical_cast<std::string>(j)<<std::endl;
			line->push_back(CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Line0/Tt" + n + boost::lexical_cast<std::string>(j)));
		}
		_lines.push_back(line);

	}

}
void Dan::write(int i, int j, const std::string & text)
{
	_lines[j]->write(i, text);
}
void Dan::show(void)
{

	CEGUI::Window * root = CEGUI::System::getSingleton().getGUISheet();
	if(root)
		root->addChildWindow(_win);

	_win->show();
	CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin")->activate();
	static_cast<CEGUI::Editbox*>(CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin"))->setValidationString("[0-9]*");
	static_cast<CEGUI::Editbox*>(CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin"))->setMaxTextLength(9);
	
  CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin")->
		subscribeEvent(CEGUI::Editbox::EventTextAccepted, CEGUI::Event::Subscriber(&Dan::textAccepted, this));

}
void Dan::hide(void)
{
	CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin")->removeAllEvents();
	_win->hide();

	CEGUI::Window * root = CEGUI::System::getSingleton().getGUISheet();
	if(root)
		root->removeChildWindow(_win);
}
Dan::~Dan(void)
{
	hide();
}
void Dan::update(TimeType time)
{
	if(_time > 0.f)
	{
		_time -= time;
		if( _time <= 0.f)
		{
			CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/W")->setProperty("Image","set:UI4 image:w0");
		}
	}
}

void Dan::result(bool ret)
{
	if(ret)
			CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/W")->setProperty("Image","set:UI4 image:w4");
	else
			CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/W")->setProperty("Image","set:UI4 image:w5");
	_time = 1.0;
}