
ORZ_PRE_BUILD_EVENT(PUComponent)

ADD_DEFINITIONS( -D_CONSOLE )


INCLUDE_DIRECTORIES(
include
interface
)

# specify a precompiled header to use
use_precompiled_header(SanModel 
  "${CMAKE_CURRENT_SOURCE_DIR}/include/PUComponentStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/PUComponentPrecompiledHeaders.cpp"
)


ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(interface interface/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ORZ_SET_PROJECT_FILES(def ./ .def)





ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
Framework_Base 
Toolkit_Base 
Toolkit_Component_Task
debug OgreMain_d 
optimized OgreMain
debug ParticleUniverse_d 
optimized ParticleUniverse
View_OGRE3D 
)


INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/interface/ DESTINATION ./include/orz/PUComponent PATTERN "CVS" EXCLUDE  PATTERN ".svn" EXCLUDE PATTERN "*.exe" EXCLUDE)
ORZ_POST_BUILD_EVENT()