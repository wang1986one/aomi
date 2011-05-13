#ifndef __Orz_WheelDirector_h__
#define __Orz_WheelDirector_h__	


#include "MyWheelDirectorStableHeaders.h"
#include <orz/Toolkit_Base/FSMLogic.h>
namespace Orz
{
	
	class WheelGame;
	class WheelLogic;
	class WheelClock;
	class WheelMediator;
	//class EntityLoader;
	class AutoEngineDecorator;
	class MyHardwareEngineDecorator;
	class DUI;
	//class MyHardwareCode;
	typedef boost::shared_ptr<AutoEngineDecorator> AutoEngineDecoratorPtr;
	typedef boost::shared_ptr<MyHardwareEngineDecorator> MyHardwareEngineDecoratorPtr;
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
		boost::scoped_ptr<WheelGame> _game;
	//	boost::scoped_ptr<EntityLoader> _loader;
		boost::scoped_ptr<DUI> _ui;
		FSMLogicHandler<WheelGame, WheelLogic> _logic;
		ScenePtr _scene;
		MyHardwareEngineDecoratorPtr _autoEngine;
		Orz::ComponentPtr _keyTable;
	};
}

#endif

