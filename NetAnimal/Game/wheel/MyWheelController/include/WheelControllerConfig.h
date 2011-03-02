#ifndef __Orz_WheelControllerConfig_h__
#define __Orz_WheelControllerConfig_h__	

#include <orz/Toolkit_Base/Global.h>


#if ORZ_PLATFORM == ORZ_PLATFORM_WIN32
#	if defined( MYWHEELCONTROLLER_EXPORTS )
#		define _OrzMyWheelControlleExport __declspec( dllexport )
#	else
#		if defined( __MINGW32__ )
#			define _OrzMyWheelControlleExport
#		else
#			define _OrzMyWheelControlleExport __declspec( dllimport )
#		endif
#	endif
#define _OrzMyWheelControllePrivate

#elif ORZ_PLATFORM == ORZ_PLATFORM_LINUX  

// Enable GCC symbol visibility
#   if defined( ORZ_GCC_VISIBILITY )
#       define _OrzMyWheelControlleExport  __attribute__ ((visibility("default")))
#       define _OrzMyWheelControllePrivate __attribute__ ((visibility("hidden")))
#   else
#       define _OrzMyWheelControlleExport
#       define _OrzMyWheelControllePrivate
#   endif

#endif


#endif

