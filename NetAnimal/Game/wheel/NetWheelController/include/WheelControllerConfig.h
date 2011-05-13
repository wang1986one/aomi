#ifndef __Orz_WheelControllerConfig_h__
#define __Orz_WheelControllerConfig_h__	

#include <orz/Toolkit_Base/Global.h>


#if ORZ_PLATFORM == ORZ_PLATFORM_WIN32
#	if defined( NETWHEELCONTROLLER_EXPORTS )
#		define _OrzNetWheelControlleExport __declspec( dllexport )
#	else
#		if defined( __MINGW32__ )
#			define _OrzNetWheelControlleExport
#		else
#			define _OrzNetWheelControlleExport __declspec( dllimport )
#		endif
#	endif
#define _OrzNetWheelControllePrivate

#elif ORZ_PLATFORM == ORZ_PLATFORM_LINUX  

// Enable GCC symbol visibility
#   if defined( ORZ_GCC_VISIBILITY )
#       define _OrzNetWheelControlleExport  __attribute__ ((visibility("default")))
#       define _OrzNetWheelControllePrivate __attribute__ ((visibility("hidden")))
#   else
#       define _OrzNetWheelControlleExport
#       define _OrzNetWheelControllePrivate
#   endif

#endif


#endif

