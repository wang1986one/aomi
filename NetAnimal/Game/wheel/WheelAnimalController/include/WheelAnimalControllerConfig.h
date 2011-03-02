#ifndef __Orz_WheelAnimalControllerConfig_h__
#define __Orz_WheelAnimalControllerConfig_h__	


#include <orz/Toolkit_Base/Global.h>
#include <orz/View_Fmod/FmodSoundManager.h>

#if ORZ_PLATFORM == ORZ_PLATFORM_WIN32
#	if defined( WHEELANIMALCONTROLLER_EXPORTS )
#		define _OrzWheelAnimalControllerExport __declspec( dllexport )
#	else
#		if defined( __MINGW32__ )
#			define _OrzWheelAnimalControllerExport
#		else
#			define _OrzWheelAnimalControllerExport __declspec( dllimport )
#		endif
#	endif
#define _OrzWheelAnimalControllerPrivate

#elif ORZ_PLATFORM == ORZ_PLATFORM_LINUX  

// Enable GCC symbol visibility
#   if defined( ORZ_GCC_VISIBILITY )
#       define _OrzWheelAnimalControllerExport  __attribute__ ((visibility("default")))
#       define _OrzWheelAnimalControllerPrivate __attribute__ ((visibility("hidden")))
#   else
#       define _OrzWheelAnimalControllerExport
#       define _OrzWheelAnimalControllerPrivate
#   endif

#endif


enum SceneItemMark
{
   SCENE_CAMERA,
   LIGHT_0,
   LIGHT_1,
   LIGHT_2,
   LIGHT_3,
   LIGHT_4,
   LIGHT_5,
   LIGHT_6,
   LIGHT_7,
   LIGHT_8,
   LIGHT_9,
   LIGHT_10,
   LIGHT_11,
   LIGHT_12,
   LIGHT_13,
   LIGHT_14,
   LIGHT_15,
   LIGHT_16,
   LIGHT_17,
   LIGHT_18,
   LIGHT_19,
   LIGHT_20,
   LIGHT_21,
   LIGHT_22,
   LIGHT_23,
   LIGHT_ALL,
   BASE_0,
   BASE_1,
   BASE_2,
   BASE_3,
   BASE_4,
   BASE_5,
   BASE_6,
   BASE_7,
   BASE_8,
   BASE_9,
   BASE_10,
   BASE_11,
   BASE_12,
   BASE_13,
   BASE_14,
   BASE_15,
   BASE_16,
   BASE_17,
   BASE_18,
   BASE_19,
   BASE_20,
   BASE_21,
   BASE_22,
   BASE_23,
   BASE_ALL,
   NEEDLE,
   SCENE_ANIMATION_0,
   SCENE_ANIMATION_1,
   SCENE_ANIMATION_2,
   SCENE_ANIMATION_3,
   SCENE_ANIMATION_4

};

#endif

