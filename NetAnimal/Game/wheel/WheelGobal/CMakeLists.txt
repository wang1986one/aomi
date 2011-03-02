
ORZ_PRE_BUILD_EVENT(WheelGobal)

ADD_DEFINITIONS( -D_CONSOLE -D${LIB_NAME_TOUPPER}_EXPORTS  -DTIXML_USE_STL)


INCLUDE_DIRECTORIES(
include
)

use_precompiled_header(WheelGobal
  "${CMAKE_CURRENT_SOURCE_DIR}/include/WheelGobalStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/WheelGobalPrecompiledHeaders.cpp"
)

ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)

ORZ_SET_PROJECT_FILES(Ofusion\\\\\\\\include include/ThirdParty/Ofusion/ .h)
ORZ_SET_PROJECT_FILES(Ofusion\\\\\\\\src src/ThirdParty/Ofusion/ .cpp)


ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
View_Fmod 
View_OGRE3D 
View_OIS 
Framework_Base 
Toolkit_Base 
Framework_Base
debug OgreMain_d 
optimized OgreMain 

debug tinyxmld_STL 
optimized tinyxml_STL
)

INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/  DESTINATION ./include/WheelGobal PATTERN "CVS" EXCLUDE  PATTERN ".svn" EXCLUDE)
ORZ_POST_BUILD_EVENT()