#ifndef __Orz_SanModelBaseStableHeaders__
#define __Orz_SanModelBaseStableHeaders__

#include <orz/Toolkit_Base/ToolkitBaseAllInclude.h>
#include <orz/Framework_Base/FrameworkBaseAllInclude.h>
#include <orz/Toolkit_Component_Task/Component/ComponentInterface.h>	
#include <orz/Toolkit_Component_Task/Component/Component.h>	
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
#include <orz/View_OGRE3D/OgreHeader.h>
#include <orz/Toolkit_Component_Task/Component/ComponentFactories.h>
#include <cegui/cegui.h>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <WheelGobal/ReferenceCount.h>
#include <WheelGobal/WheelEvents.h>
#include <WheelGobal/WheelEnum.h>
#include <WheelGobal/WinData.h>

//#include "OgreEntityComponent.h"
//#include "OgrePlayerComponent.h"
//#include "OgreResourceComponent.h"
//#include "AllCInterface.h" 
namespace Orz
{
	class nodeleter
	{
	public:
		template<class T> void operator ()(T * t){}
	};
}
#endif