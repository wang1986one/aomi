#ifndef __Orz_WheelControllerConfig_h__
#define __Orz_WheelControllerConfig_h__	

#include <orz/Toolkit_Base/Global.h>


#if ORZ_PLATFORM == ORZ_PLATFORM_WIN32
#	if defined( WHEELCONTROLLER_EXPORTS )
#		define _OrzWheelControlleExport __declspec( dllexport )
#	else
#		if defined( __MINGW32__ )
#			define _OrzWheelControlleExport
#		else
#			define _OrzWheelControlleExport __declspec( dllimport )
#		endif
#	endif
#define _OrzWheelControllePrivate

#elif ORZ_PLATFORM == ORZ_PLATFORM_LINUX  

// Enable GCC symbol visibility
#   if defined( ORZ_GCC_VISIBILITY )
#       define _OrzWheelControlleExport  __attribute__ ((visibility("default")))
#       define _OrzWheelControllePrivate __attribute__ ((visibility("hidden")))
#   else
#       define _OrzWheelControlleExport
#       define _OrzWheelControllePrivate
#   endif

#endif


#endif

