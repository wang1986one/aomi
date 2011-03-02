#ifndef __Orz_WheelDataConfig_h__
#define __Orz_WheelDataConfig_h__	

#include <orz/Toolkit_Base/Global.h>


#if ORZ_PLATFORM == ORZ_PLATFORM_WIN32
#	if defined( WHEELDATA_EXPORTS )
#		define _OrzWheelDataConfigExport __declspec( dllexport )
#	else
#		if defined( __MINGW32__ )
#			define _OrzWheelDataConfigExport
#		else
#			define _OrzWheelDataConfigExport __declspec( dllimport )
#		endif
#	endif
#define _OrzWheelDataConfigPrivate

#elif ORZ_PLATFORM == ORZ_PLATFORM_LINUX  

// Enable GCC symbol visibility
#   if defined( ORZ_GCC_VISIBILITY )
#       define _OrzWheelDataConfigExport  __attribute__ ((visibility("default")))
#       define _OrzWheelDataConfigPrivate __attribute__ ((visibility("hidden")))
#   else
#       define _OrzWheelDataConfigExport
#       define _OrzWheelDataConfigPrivate
#   endif

#endif


#endif

