#include "NewGameComponentsStableHeaders.h"	
#include "UIProcessComponent.h"	
#include "UIProcessInterface.h"	
#include "TheTime.h"
#include "Money.h"
#include "UIList.h"
#include "TVUI.h"
#include "VedioUIInterface.h"
#include "Banker.h"
#include "WinBg.h"
#include "Light.h"
#include "CGameActionInterface.h"
using namespace Orz;



bool UIProcessComponent::_enable(void)
{
	_currTime = 0.f;
	return true;
}

bool UIProcessComponent::enableLogo(void)
{
	_logo->show();
	/*VedioUIInterface * vedio =  _vedio->queryInterface<VedioUIInterface>();
	CEGUI::Window * window = CEGUI::System::getSingleton().getGUISheet(); 
	Orz::ISoundManager::getSingleton().quickPlay("Fly.wav");
	vedio->play();

	vedio->getWindow()->setAlwaysOnTop(true);
	_logo = 0.05f;
	_migic = 3.0f;*/
	return true;
}
bool UIProcessComponent::updateLogo(TimeType i)
{
	//VedioUIInterface * vedio =  _vedio->queryInterface<VedioUIInterface>();
	return false;//!vedio->isEnd();
}
void UIProcessComponent::disableLogo(void)
{
	_logo->hide();
	//VedioUIInterface * vedio =  _vedio->queryInterface<VedioUIInterface>();
	
	CEGUI::Window * window = CEGUI::System::getSingleton().getGUISheet(); 
	//window->removeChildWindow(vedio->getWindow());	
	//vedio->reset();
}
void UIProcessComponent::_disable(void)
{
	Orz::ISoundManager::getSingleton().quickPlay("prize_double.wav");

}
bool UIProcessComponent::activate(SanProcess process)
{

	boost::scoped_ptr<UI::TVUI> _tvui;

	while(!_eventQueue.empty())
	{
		_eventQueue.pop();
	}
	switch(process)
	{
	case PROCESS_LOGO:
		_money->clear();
		_light->clear();
		if(_bonus->playing())
			_bonus->stop();
		if(_rotate&&_rotate->playing())
		{
			_rotate->stop();
			_rotate->unload();
		}
		_actionInterface->enable =  boost::bind(&UIProcessComponent::enableLogo, this);
		_actionInterface->update = boost::bind(&UIProcessComponent::updateLogo, this, _1);
		_actionInterface->disable = boost::bind(&UIProcessComponent::disableLogo, this);

		return true;
		break;
	case PROCESS_READY:
		break;
	case PROCESS_START:
		break;
	case PROCESS_PRORUN:
		if(WinData::getInstance().getWinMode() == Orz::WheelEnum::DOUBLE)
		{
			Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();

			_eventQueue.push(std::make_pair(0.f, boost::bind(&ISoundManager::quickPlay, Orz::ISoundManager::getSingletonPtr(),"lightning.wav", false)));
			_eventQueue.push(std::make_pair(2.f, boost::bind(&Ogre::SceneManager::setAmbientLight,sm, Ogre::ColourValue(1,1, 1))));
			_eventQueue.push(std::make_pair(0.f, boost::bind(&UI::Light::x2, _light.get())));
			_eventQueue.push(std::make_pair(0.2f, boost::bind(&Ogre::SceneManager::setAmbientLight,sm, Ogre::ColourValue(0.7f,0.8f, 0.7f))));
			_eventQueue.push(std::make_pair(0.1f, boost::bind(&Ogre::SceneManager::setAmbientLight,sm, Ogre::ColourValue(1,1, 1))));
			_eventQueue.push(std::make_pair(0.2f, boost::bind(&Ogre::SceneManager::setAmbientLight,sm, Ogre::ColourValue(0.7f,0.8f, 0.7f))));

			_eventQueue.push(std::make_pair(1.5f, boost::bind(&ISoundManager::quickPlay, Orz::ISoundManager::getSingletonPtr(),"prize_double.wav", false)));


		}else if(WinData::getInstance().getWinMode() == Orz::WheelEnum::TREBLE)
		{
			Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();

			_eventQueue.push(std::make_pair(0.f, boost::bind(&ISoundManager::quickPlay, Orz::ISoundManager::getSingletonPtr(),"lightning.wav", false)));
			_eventQueue.push(std::make_pair(2.f, boost::bind(&Ogre::SceneManager::setAmbientLight,sm, Ogre::ColourValue(1,1, 1))));
			_eventQueue.push(std::make_pair(0.f, boost::bind(&UI::Light::x3, _light.get())));
			_eventQueue.push(std::make_pair(0.2f, boost::bind(&Ogre::SceneManager::setAmbientLight,sm, Ogre::ColourValue(0.7f,0.8f, 0.7f))));
			_eventQueue.push(std::make_pair(0.1f, boost::bind(&Ogre::SceneManager::setAmbientLight,sm, Ogre::ColourValue(1,1, 1))));
			_eventQueue.push(std::make_pair(0.2f, boost::bind(&Ogre::SceneManager::setAmbientLight,sm, Ogre::ColourValue(0.7f,0.8f, 0.7f))));

			_eventQueue.push(std::make_pair(1.5f, boost::bind(&ISoundManager::quickPlay, Orz::ISoundManager::getSingletonPtr(),"prize_double.wav", false)));


		}


		break;
	case PROCESS_RUN:

		switch(WinData::getInstance().getWinMode())
		{
		case Orz::WheelEnum::ALL_ANIMAL:
			_rotate = Orz::ISoundManager::getSingleton().createPlayer("songdongwu.mp3", true);
			break;
		case Orz::WheelEnum::ALL_COLOR:
			_rotate = Orz::ISoundManager::getSingleton().createPlayer("songyanse.mp3", true);
			break;
		case Orz::WheelEnum::MANY:
			_rotate = Orz::ISoundManager::getSingleton().createPlayer("songshuzi.mp3", true);
			break;
		case Orz::WheelEnum::DOUBLE:
		case Orz::WheelEnum::TREBLE:
			_rotate = Orz::ISoundManager::getSingleton().createPlayer("double.mp3", true);
			break;		
		case Orz::WheelEnum::GOLD:
			_rotate = Orz::ISoundManager::getSingleton().createPlayer("Bonus.wav", true);
			break;
		default:
			_rotate = Orz::ISoundManager::getSingleton().createPlayer("Rotate_Loop.wav", true);
		}
		_rotate->load();
		_rotate->play(0);
		_rotate->setVolume(0.8f);
		break;
	case PROCESS_WIN:
		_money->setBonus(WinData::getInstance().getBonus().bonus);
		switch(WinData::getInstance().getWinMode())
		{
		case Orz::WheelEnum::DOUBLE:
		case Orz::WheelEnum::TREBLE:
		case Orz::WheelEnum::ALL_ANIMAL:
		case Orz::WheelEnum::ALL_COLOR:
		case Orz::WheelEnum::MANY:
			break;
		case Orz::WheelEnum::GOLD:


			break;
		default:

			_rotate->stop();
			_rotate->unload();
			_bonus->play(0);
		}
		break;
	case PROCESS_PLAY:
		break;
	case PROCESS_END:
		_eventQueue.push(std::make_pair(0.f, boost::bind(&ISoundManager::quickPlay, Orz::ISoundManager::getSingletonPtr(),"win.wav", false)));
		_eventQueue.push(std::make_pair(5.f, boost::bind(&___disable)));


		break;
	}

	if(!_eventQueue.empty())
	{
		_currTime = 0.f;
		_actionInterface->enable =  boost::lambda::constant(true);
		_actionInterface->update = boost::bind(&___updateEventQueue, _1,boost::ref(_currTime), boost::ref(_eventQueue));
		_actionInterface->disable = boost::bind(&___disable);

		return true;
	}
	return false;
}
UIProcessComponent::UIProcessComponent(void):_actionInterface(new CGameActionInterface)/*,_logo(-1.f),_migic(-1)*/,_currTime(0.f)
{

	  
	using namespace CEGUI;
	CEGUI::ImagesetManager::getSingleton().createFromImageFile("mylogo", "logo.jpg");
	_logo = WindowManager::getSingleton().createWindow("TaharezLook/StaticImage", "vedio");
	_logo->setProperty("Image", "set:mylogo image:full_image"); 
	_logo->setVisible(false);
	SchemeManager::getSingleton().create("TaharezLook.scheme");
	CEGUI::SchemeManager::getSingleton().create("VanillaSkin.scheme");
	ImagesetManager::getSingleton().create("sample.imageset");
	ImagesetManager::getSingleton().create("sample1.imageset");
	ImagesetManager::getSingleton().create("sample2.imageset");

	ImagesetManager::getSingleton().create("UI1.imageset");
	ImagesetManager::getSingleton().create("UI2.imageset");
	ImagesetManager::getSingleton().create("UI3.imageset");
	ImagesetManager::getSingleton().create("UI4.imageset");
	CEGUI::System::getSingleton().setGUISheet(CEGUI::WindowManager::getSingleton().loadWindowLayout("GUI.layout"));
	_time.reset(new UI::Time());
	_money.reset(new UI::Money());

	_list.reset(new UI::UIList());
	_list->draw();
	_banker.reset(new UI::Banker());
	_light.reset(new UI::Light());
	_winBg.reset(new UI::WinBg());

	CEGUI::WindowManager::getSingleton().getWindow("PICTURE")->hide();

	_wait = Orz::ISoundManager::getSingleton().createPlayer("Wait.wav", true);
	_wait->load();
	/*_rotate = Orz::ISoundManager::getSingleton().createPlayer("Rotate_Loop.wav", true);
	_rotate->load();*/
	_bonus  = Orz::ISoundManager::getSingleton().createPlayer("Win_2.wav", true);
	_bonus ->load();
	_bonus->setVolume(0.8f);


	//_vedio = Orz::ComponentFactories::getInstance().create("VedioUI");
	//VedioUIInterface * vedio =  _vedio->queryInterface<VedioUIInterface>();
	//vedio->load("startmovie.ogg");

	_tvui.reset(new UI::TVUI);

	_actionInterface->activate = boost::bind(&UIProcessComponent::activate, this, _1);
}
UIProcessComponent::~UIProcessComponent(void)
{
	_wait->unload();



	_bonus->unload();
}
ComponentInterface * UIProcessComponent::_queryInterface(const TypeInfo & info) const
{


	if(info == TypeInfo(typeid(UIProcessInterface)))
		return const_cast<UIProcessComponent *>(this);
	if(info == TypeInfo(typeid(CGameActionInterface)))
		return _actionInterface.get();
	return NULL;
}


void UIProcessComponent::setTheTime(int second)
{if(second <=5 && second >=1)
{
	Orz::ISoundManager::getSingleton().quickPlay("Countdown.wav");
}else if(second == 0)
{

}
_time->show(second);
}
void UIProcessComponent::setMenuDataVisible(bool visible)
{

}
void UIProcessComponent::setSetupVisible(bool visible)
{

}
void UIProcessComponent::menuResult(bool result)
{

}
void UIProcessComponent::writeMenuXY(int x, int y, unsigned long n)
{

}
void UIProcessComponent::setLogoShow(bool show)
{
	
}
void UIProcessComponent::setStartVisible(bool visible)
{



	if(visible)
	{
		_wait->play(0);
		_time->comeIn();
		CEGUI::WindowManager::getSingleton().getWindow("PICTURE")->show();
	}
	else
	{

		Orz::ISoundManager::getSingleton().quickPlay("Countdown_2.wav");
		_wait->stop();
		_time->goOut();
		CEGUI::WindowManager::getSingleton().getWindow("PICTURE")->hide();
	}
}
void UIProcessComponent::setEndUIVisible(bool visible)
{
	if(visible)
	{
		_winBg->show();
	}
	else
	{

	}
}
void UIProcessComponent::runWinner(void)
{
	WheelEnum::WINNER winner = WinData::getInstance().getWinner();
	_banker->play(winner);
}
void UIProcessComponent::addBottom(void)
{
	//WinData::getInstance().load();
	_list->add();
}
void UIProcessComponent::update(TimeType interval)
{
	//if(_logo>0.f)
	//{
	//	_logo -= interval;
	//	if(_logo<=0)
	//	{
	//		_winBg->hide();
	//		//VedioUIInterface * vedio =  _vedio->queryInterface<VedioUIInterface>();
	//		CEGUI::Window * window = CEGUI::System::getSingleton().getGUISheet(); 


	//		//window->addChildWindow(vedio->getWindow());

	//	}
	//}

	//if(_migic>0.f)
	//{
	//	_migic -= interval;
	//	if(_migic<=0)
	//	{

	//		Orz::ISoundManager::getSingleton().quickPlay("magic.wav");

	//	}
	//}
	_banker->update(interval);
	_money->update(interval);
	_time->update(interval);
	_light->update(interval);
	_winBg->update(interval);
}