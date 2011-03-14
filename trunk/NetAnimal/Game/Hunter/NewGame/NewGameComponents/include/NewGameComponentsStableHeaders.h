#ifndef __Orz_NewGameComponentsStableHeaders__
#define __Orz_NewGameComponentsStableHeaders__
#include <orz/Toolkit_Base/ToolkitBaseAllInclude.h>
#include <orz/Framework_Base/FrameworkBaseAllInclude.h>
#include <orz/Toolkit_Component_Task/Component/ComponentInterface.h>	
#include <orz/Toolkit_Component_Task/Component/Component.h>	
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
#include <orz/View_OGRE3D/OgreHeader.h>
#include <orz/Toolkit_Component_Task/Component/ComponentFactories.h>
#include <cegui/cegui.h>
#include <boost/multi_array.hpp>


#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <WheelGobal/ReferenceCount.h>
#include <WheelGobal/WheelEvents.h>
#include <WheelGobal/WheelEnum.h>
#include <WheelGobal/WinData.h>
namespace Orz
{
	
	typedef std::queue<std::pair<TimeType,  boost::function<void (void)> > > EventQueue; 
	
	bool ___enable(void);
	bool ___update(TimeType t);
	bool ___updateEventQueue(TimeType t, TimeType & currTime, EventQueue & eventQueue);
	
	void ___disable(void);
}
#endif