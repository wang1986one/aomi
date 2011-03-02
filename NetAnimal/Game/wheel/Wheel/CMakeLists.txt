
ORZ_PRE_BUILD_EVENT(Wheel)

ADD_DEFINITIONS( -D_CONSOLE -DTIXML_USE_STL)

INCLUDE(OrzSingleChip)
INCLUDE_DIRECTORIES("include")


INCLUDE_DIRECTORIES(
"include" 
 )


ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ADD_EXECUTABLE(${EXE_NAME} ${${EXE_NAME}_FILE})

use_precompiled_header(Wheel
  "${CMAKE_CURRENT_SOURCE_DIR}/include/WheelConfig.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/Wheel.cpp"
)





TARGET_LINK_LIBRARIES(${EXE_NAME} 
View_Fmod 
View_OGRE3D 
View_OIS 
View_CEGUI
View_SingleChip
Toolkit_Base 
Framework_Base

debug OgreMain_d 
optimized OgreMain 
)

ORZ_POST_BUILD_EVENT()