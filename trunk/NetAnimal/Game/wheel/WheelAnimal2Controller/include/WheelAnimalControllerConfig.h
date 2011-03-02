#ifndef __Orz_WheelAnimalControllerConfig_h__
#define __Orz_WheelAnimalControllerConfig_h__	


#include <orz/Toolkit_Base/Global.h>
#include <orz/View_Fmod/FmodSoundManager.h>

#if ORZ_PLATFORM == ORZ_PLATFORM_WIN32
#	if defined( WHEELANIMAL2CONTROLLER_EXPORTS )
#		define _OrzWheelAnimal2ControllerExport __declspec( dllexport )
#	else
#		if defined( __MINGW32__ )
#			define _OrzWheelAnimal2ControllerExport
#		else
#			define _OrzWheelAnimal2ControllerExport __declspec( dllimport )
#		endif
#	endif
#define _OrzWheelAnimalControllerPrivate

#elif ORZ_PLATFORM == ORZ_PLATFORM_LINUX  

// Enable GCC symbol visibility
#   if defined( ORZ_GCC_VISIBILITY )
#       define _OrzWheelAnimal2ControllerExport  __attribute__ ((visibility("default")))
#       define _OrzWheelAnimalControllerPrivate __attribute__ ((visibility("hidden")))
#   else
#       define _OrzWheelAnimal2ControllerExport
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
   SCENE_ANIMATION_4,
   TABLE_0,
   TABLE_1,
   TABLE_2,
   TABLE_3,
   TABLE_4,
   TABLE_5,
   TABLE_6,
   TABLE_7,
   TABLE_8,
   TABLE_9,
   TABLE_10,
   TABLE_11,
   TABLE_12,
   TABLE_13,
   TABLE_14,
   TABLE_15,
   TABLE_16,
   TABLE_17,
   TABLE_18,
   TABLE_19,
   TABLE_20,
   TABLE_21,
   TABLE_22,
   TABLE_23,
   TABLE_ALL

};

#endif

