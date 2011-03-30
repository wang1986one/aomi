
ORZ_PRE_BUILD_EVENT(UnitTest)

ADD_DEFINITIONS( -D_CONSOLE)


INCLUDE_DIRECTORIES(
include
${ORZ_PROJECT_INTERFACE_DIR}
)

# specify a precompiled header to use
use_precompiled_header(UnitTest
  "${CMAKE_CURRENT_SOURCE_DIR}/include/UnitTestStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/UnitTestPrecompiledHeaders.cpp"
)

ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ADD_EXECUTABLE(${EXE_NAME} ${${EXE_NAME}_FILE})


TARGET_LINK_LIBRARIES(${EXE_NAME} 
View_Fmod 
View_OGRE3D 
View_OIS 
View_CEGUI
Toolkit_Base 
Framework_Base
Toolkit_Component_Task
debug CEGUIBase_d 
optimized CEGUIBase
debug OgreMain_d 
optimized OgreMain 
)

ORZ_POST_BUILD_EVENT()

        