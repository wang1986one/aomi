#ifndef __Orz_WheelAnimalScene_h__
#define __Orz_WheelAnimalScene_h__	


#include "WheelAnimalUI.h"
namespace Orz
{
	class WheelAnimalGame;/*
	class WheelAnimalProcessManager;*/
	class WheelAnimalScene: public Scene
	{
	public:
		WheelAnimalScene(const std::string & name = IDManager::BLANK);
		virtual ~WheelAnimalScene(void);

		void doExecute(Event * evt);
		void doEnable(void);
		void doDisable(void);
		void doFrame(unsigned int step);

	private:

		
		boost::scoped_ptr<WheelAnimalGame> _controller;
		
	};
}

#endif

