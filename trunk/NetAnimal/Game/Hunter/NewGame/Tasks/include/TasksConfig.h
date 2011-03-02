#ifndef __Orz_Tasks_TasksConfig_h__
#define __Orz_Tasks_TasksConfig_h__

#include <orz/Toolkit_Base/Global.h>
#include <orz/Toolkit_Base/LogSystem.h>

#if ORZ_PLATFORM == ORZ_PLATFORM_WIN32
#	if defined( TASKS_EXPORTS )
#		define _OrzTasksExport __declspec( dllexport )
#	else
#		if defined( __MINGW32__ )
#			define _OrzTasksExport
#		else
#			define _OrzTasksExport __declspec( dllimport )
#		endif
#	endif
#define _OrzTasksPrivate

#elif ORZ_PLATFORM == ORZ_PLATFORM_LINUX  

// Enable GCC symbol visibility
#   if defined( ORZ_GCC_VISIBILITY )
#       define _OrzTasksExport  __attribute__ ((visibility("default")))
#       define _OrzTasksPrivate __attribute__ ((visibility("hidden")))
#   else
#       define _OrzTasksExport
#       define _OrzTasksPrivate
#   endif

#endif

#endif