#ifndef __Orz_WheelGobalConfig_h__
#define __Orz_WheelGobalConfig_h__	

#include <orz/Toolkit_Base/Global.h>


#if ORZ_PLATFORM == ORZ_PLATFORM_WIN32
#	if defined( WHEELGOBAL_EXPORTS )
#		define _OrzWheelGobalExport __declspec( dllexport )
#	else
#		if defined( __MINGW32__ )
#			define _OrzWheelGobalExport
#		else
#			define _OrzWheelGobalExport __declspec( dllimport )
#		endif
#	endif
#define _OrzWheelGobalPrivate

#elif ORZ_PLATFORM == ORZ_PLATFORM_LINUX  

// Enable GCC symbol visibility
#   if defined( ORZ_GCC_VISIBILITY )
#       define _OrzWheelGobalExport  __attribute__ ((visibility("default")))
#       define _OrzWheelGobalPrivate __attribute__ ((visibility("hidden")))
#   else
#       define _OrzWheelGobalExport
#       define _OrzWheelGobalPrivate
#   endif

#endif


typedef boost::array<int, 9> SetupInfo;
typedef boost::shared_ptr<SetupInfo > SetupInfoPtr;

#endif

