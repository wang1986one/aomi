#include "MyWheelDirectorStableHeaders.h"
#include "DUI/Dan2.h"
#include "WheelUIListener.h"
#include "BlackBoardSystem.h"
#include "WheelEnum.h"
#include "F6TableInterface.h"
using namespace Orz;

Dan2::Dan2(DanListener * listener):KeyListener(true),_n(0), _time(-1.f),_callback(listener)
{

	_f6table = Orz::ComponentFactories::getInstance().create("F5Table");
	_win= CEGUI::WindowManager::getSingleton().loadWindowLayout("Dan2.layout");
	_win->setAlwaysOnTop(true);
	_win->hide();
	for(int i = 0; i<9; ++i)
	{
		_editboxs[i] = static_cast<CEGUI::Editbox*>(CEGUI::WindowManager::getSingleton().getWindow("Dan2/Bg/" + Ogre::StringConverter::toString(i+1)));
		_editboxs[i]->setMaxTextLength(1);

	//	_editboxs[i]->subscribeEvent(CEGUI::Editbox::EventValidationStringChanged, CEGUI::Event::Subscriber(&Dan2::textAccepted, this));
	}

	_editboxs[0]->setValidationString("[1-7]*");
	_editboxs[1]->setValidationString("[1-4]*");
	_editboxs[2]->setValidationString("[1-4]*");
	_editboxs[3]->setValidationString("[1-6]*");
	_editboxs[4]->setValidationString("[0-3]*");
	_editboxs[5]->setValidationString("[0-9]*");
	_editboxs[6]->setValidationString("[1-5]*");
	_editboxs[7]->setValidationString("[1-9]*");
	_editboxs[8]->setValidationString("[1-7]*");

}

bool Dan2::textAccepted(const CEGUI::EventArgs&) 
{
	setup();
	return true;
}

bool Dan2::onKeyPressed(const KeyEvent & evt)
{
	return false;
}
bool Dan2::onKeyReleased(const KeyEvent & evt)
{
	int old = _n;
	if(evt.getKey() == Orz::KC_UP)
	{

		if(_n > 0)
			--_n;
	}
	if(evt.getKey() == Orz::KC_DOWN)
	{
		if(_n < 8)
			++_n;
	}
	int now =  _n;
	redo(old, now);
	return false;
}


void Dan2::result(bool ret)
{
	if(ret)
		CEGUI::WindowManager::getSingleton().getWindow("Dan2/Result")->setProperty("Image","set:UI4 image:w4");
	else
		CEGUI::WindowManager::getSingleton().getWindow("Dan2/Result")->setProperty("Image","set:UI4 image:w5");
	_time = 1.0;
}
void Dan2::show(void)
{
	F6TableInterface * f6table = _f6table->queryInterface<F6TableInterface>();
	for(int i = 0; i< F6TableInterface::ITEM_SIZE; ++i)
	{
		setDan2Data(i, f6table->getDataIndex(F6TableInterface::ITEM(i)) );
	}
	CEGUI::Window * win = CEGUI::System::getSingleton().getGUISheet();
	if(win)
	{
		win->addChildWindow(_win);
	}
	if(BlackBoardSystem::getInstance().has(WheelEnum::SETUP_STR))
	{

		SetupInfoPtr setup = BlackBoardSystem::getInstance().read<SetupInfoPtr>(WheelEnum::SETUP_STR);
		for(size_t i=0; i< setup->size(); ++i)
		{
			setDan2Data(i, setup->at(i));
		}

	}
	Orz::IInputManager::getSingleton().addKeyListener(this);
	_win->show();
	_n = 0;
	redo(_n, _n);

}

void Dan2::redo(int old, int now)
{

	_editboxs[old]->setSelection(0, 0);
	_editboxs[now]->activate();
	_editboxs[now]->setSelection(0, 1);
}



void Dan2::setDan2Data(int i, int data)
{
	_editboxs[i]->setText(Ogre::StringConverter::toString(data));
}
void Dan2::hide(void)
{
	Orz::IInputManager::getSingleton().removeKeyListener(this);
	_win->hide();	
	CEGUI::Window * win = CEGUI::System::getSingleton().getGUISheet();
	if(win)
	{
		win->removeChildWindow(_win);
	}
	setup();
}
void Dan2::setup(void)
{

	F6TableInterface * f6table = _f6table->queryInterface<F6TableInterface>();
	for(int i = 0; i< F6TableInterface::ITEM_SIZE; ++i)
	{
		int data = Ogre::StringConverter::parseInt(_editboxs[i]->getText().c_str());
		f6table->setDataIndex(F6TableInterface::ITEM(i), data);
		//setDan2Data(i, f6table->getDataIndex(F6TableInterface::ITEM(i)) );
	}
	f6table->save();
	/*_callback->updateUIData(
		Ogre::StringConverter::parseInt(_editboxs[0]->getText().c_str()),
		Ogre::StringConverter::parseInt(_editboxs[1]->getText().c_str()),
		Ogre::StringConverter::parseInt(_editboxs[2]->getText().c_str()),
		Ogre::StringConverter::parseInt(_editboxs[3]->getText().c_str()),
		Ogre::StringConverter::parseInt(_editboxs[4]->getText().c_str()),
		Ogre::StringConverter::parseInt(_editboxs[5]->getText().c_str()),
		Ogre::StringConverter::parseInt(_editboxs[6]->getText().c_str()),
		Ogre::StringConverter::parseInt(_editboxs[7]->getText().c_str()),
		Ogre::StringConverter::parseInt(_editboxs[8]->getText().c_str())
		);*/

}
void Dan2::update(TimeType time)
{
	if(_time > 0.f)
	{
		_time -= time;
		if( _time <= 0.f)
		{
			CEGUI::WindowManager::getSingleton().getWindow("Dan2/Result")->setProperty("Image","set:UI4 image:w0");
		}
	}
}
Dan2::~Dan2(void)
{
	for(int i = 0; i<9; ++i)
	{

		_editboxs[i]->removeAllEvents();
	}
}

void Dan2::bao_zhang_ma(const std::string & n)
{
	CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/BzmText")->setText(n);
}

