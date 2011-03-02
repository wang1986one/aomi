#ifndef __Orz_WheelAnimalGame_h__
#define __Orz_WheelAnimalGame_h__	
 
#include "WheelAnimalControllerConfig.h"
namespace Orz
{
	class Event;
	class WheelAnimalSceneObj;
	class WheelAnimalProcessManager;
	class WheelAnimalUI;
	typedef boost::shared_ptr< WheelAnimalUI> WheelAnimalUIPtr;
	class _OrzWheelAnimal2ControllerExport WheelAnimalGame
	{
	public:
		WheelAnimalGame();
		~WheelAnimalGame(void);
		
		void notice(Event * evt);
		void update(TimeType interval);
	private:
		boost::shared_ptr<WheelAnimalSceneObj> _scene;
		
		boost::shared_ptr<WheelAnimalProcessManager> _processManager;

	};
}
#endif