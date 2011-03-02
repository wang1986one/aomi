
ORZ_PRE_BUILD_EVENT(MyWheelController)

ADD_DEFINITIONS( -D_CONSOLE -D${LIB_NAME_TOUPPER}_EXPORTS -D_SCL_SECURE_NO_WARNINGS)


INCLUDE_DIRECTORIES(
include
${PROJECT_SOURCE_DIR}/WheelGobal/include 
${PROJECT_SOURCE_DIR}/include 
${ORZ_PROJECT_INTERFACE_DIR}/
)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib )

use_precompiled_header(MyWhesselController
  "${CMAKE_CURRENT_SOURCE_DIR}/include/MyWheelControllerStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/MyWheelControllerPrecompiledHeaders.cpp"
)


ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ORZ_SET_PROJECT_FILES(interface ${ORZ_PROJECT_INTERFACE_DIR}/ .h)

ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
View_Fmod 
View_OGRE3D 
View_OIS 
Framework_Base 
Toolkit_Base 
Framework_Base
View_SingleChip
debug OgreMain_d 
optimized OgreMain 
WheelGobal

Toolkit_Component_Task
View_SingleChip
)
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/  DESTINATION ./include/WheelController PATTERN "CVS" EXCLUDE  PATTERN ".svn" EXCLUDE)
ORZ_POST_BUILD_EVENT()