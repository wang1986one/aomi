#ifndef __Orz_WheelControllerConfig_h__
#define __Orz_WheelControllerConfig_h__	

#include <orz/Toolkit_Base/Global.h>


#if ORZ_PLATFORM == ORZ_PLATFORM_WIN32
#	if defined( NEWWHEELCONTROLLER_EXPORTS )
#		define _OrzNewWheelControlleExport __declspec( dllexport )
#	else
#		if defined( __MINGW32__ )
#			define _OrzNewWheelControlleExport
#		else
#			define _OrzNewWheelControlleExport __declspec( dllimport )
#		endif
#	endif
#define _OrzNewWheelControllePrivate

#elif ORZ_PLATFORM == ORZ_PLATFORM_LINUX  

// Enable GCC symbol visibility
#   if defined( ORZ_GCC_VISIBILITY )
#       define _OrzNewWheelControlleExport  __attribute__ ((visibility("default")))
#       define _OrzNewWheelControllePrivate __attribute__ ((visibility("hidden")))
#   else
#       define _OrzNewWheelControlleExport
#       define _OrzNewWheelControllePrivate
#   endif

#endif


#endif

