#ifndef __Orz_WheelDirector_h__
#define __Orz_WheelDirector_h__	


#include "NetWheelDirectorStableHeaders.h"
#include "RouletteGameInterfaces.h"
#include <orz/Toolkit_Base/FSMLogic.h>
#include <Ogre/Ogre.h>
namespace Orz
{
	
	class WheelGame;
	class WheelLogic;
	class WheelClock;
	class WheelMediator;
	class AutoEngineDecorator;
	class NetHardwareEngineDecorator;
	class RouletteUIInterfaces;
	class DUI;

	typedef boost::shared_ptr<AutoEngineDecorator> AutoEngineDecoratorPtr;
	typedef boost::shared_ptr<NetHardwareEngineDecorator> NetHardwareEngineDecoratorPtr;
	class WheelDirector: public Director, public KeyListener
	{
	public:
		WheelDirector(const std::string & name);
		virtual ~WheelDirector(void);

		void doExecute(Event * evt);
		void doEnable(void);
		void doDisable(void);
		void doFrame(unsigned int step);
#ifdef _GAME1
		void enableScene(int i);
#else
		void enableScene(const std::string & name, bool second);
#endif
		///通知键盘按下事件
		virtual bool onKeyPressed(const KeyEvent & evt);
		///通知键盘释放事件
		virtual bool onKeyReleased(const KeyEvent & evt);
		
		
	private:

		void setSelectVisible(bool visible);
		void initSlectUI(void);
		boost::scoped_ptr<DUI> _ui;
		FSMLogicHandler<ComponentPtr, WheelLogic> _logic;
		ScenePtr _scene;
		NetHardwareEngineDecoratorPtr _autoEngine;
		Orz::ComponentPtr _gameComp;
		Ogre::OverlayContainer* _select;
		RouletteGameInterfaces * _gameInterface;// = _gameComp->queryInterface<RouletteGameInterfaces>();
	};
}

#endif

