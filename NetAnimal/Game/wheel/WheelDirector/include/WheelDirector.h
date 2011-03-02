#ifndef __Orz_WheelDirector_h__
#define __Orz_WheelDirector_h__	


#include "WheelDirectorStableHeaders.h"
#include <orz/Toolkit_Base/FSMLogic.h>
namespace Orz
{
	
	class WheelGame;
	class WheelLogic;
	class WheelClock;
	class WheelMediator;
	class EntityLoader;
	class AutoEngineDecorator;
	
	typedef boost::shared_ptr<AutoEngineDecorator> AutoEngineDecoratorPtr;
	class WheelDirector: public Director
	{
	public:
		WheelDirector(const std::string & name/* , const std::string & xmlFile*/);
		virtual ~WheelDirector(void);

		void doExecute(Event * evt);
		void doEnable(void);
		void doDisable(void);
		void doFrame(unsigned int step);
		void enableScene(const std::string & name);
	private:
		boost::scoped_ptr<WheelGame> _game;
		boost::scoped_ptr<EntityLoader> _loader;
		//
	//	boost::scoped_ptr<WheelMediator> _mediator;
		//boost::scoped_ptr<WheelClock> _clock;
		FSMLogicHandler<WheelGame, WheelLogic> _logic;
		ScenePtr _scene;
		AutoEngineDecoratorPtr _autoEngine;
	};
}

#endif

