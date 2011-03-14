#ifndef __Orz_GameNeedleComponentStableHeaders__
#define __Orz_GameNeedleComponentStableHeaders__

#include <orz/Toolkit_Base/ToolkitBaseAllInclude.h>
#include <orz/Framework_Base/FrameworkBaseAllInclude.h>
#include <Ogre/Ogre.h>
#include <CEGUI/CEGUI.h>
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
#include <orz/Toolkit_Component_Task/Component/ComponentInterface.h>	
#include <orz/Toolkit_Component_Task/Component/Component.h>	
#include <orz/Toolkit_Component_Task/Component/ComponentFactories.h>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <WheelGobal/ReferenceCount.h>
#include <WheelGobal/WheelEvents.h>
#include <WheelGobal/WheelEnum.h>
#include <WheelGobal/WinData.h>
namespace Orz
{
inline float interpolation(float value)
{

	float newvalue = (value * Ogre::Math::PI) - (Ogre::Math::PI/2);
	return (Ogre::Math::Sin(newvalue) +1.f)/2.f;
}


inline float time2Degree(TimeType time, TimeType allTime)
{
	if(time > allTime || allTime == 0)
		return 1.f;
	return interpolation(time/allTime);
}
}
#endif