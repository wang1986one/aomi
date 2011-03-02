#ifndef __Orz_WheelScene_h__
#define __Orz_WheelScene_h__	


#include "WheelSceneConfig.h"
#include <orz/Toolkit_Base/FSMLogic.h>
namespace Orz
{
	
	class WheelScene: public Director
	{
	public:
		WheelScene(const std::string & name = IDManager::BLANK);
		virtual ~WheelScene(void);

		void doExecute(Event * evt);
		void doEnable(void);
		void doDisable(void);
		void doFrame(void);
	private:;
	};
}

#endif

