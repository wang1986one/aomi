
ORZ_PRE_BUILD_EVENT(NewGameSceneComponent)

ADD_DEFINITIONS(-D_CONSOLE -D${LIB_NAME_TOUPPER}_EXPORTS -DTIXML_USE_STL -DCCS_OGRE_1_7)


INCLUDE_DIRECTORIES(
include
)


# specify a precompiled header to use
use_precompiled_header(NewGameSceneComponent
  "${CMAKE_CURRENT_SOURCE_DIR}/include/NewGameSceneComponentStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/NewGameSceneComponentPrecompiledHeaders.cpp"
)

ORZ_SET_PROJECT_FILES(include include/ .h)


ORZ_SET_PROJECT_FILES(interface ${SAN_PROJECT_INTERFACE_DIR}/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ORZ_SET_PROJECT_FILES(def ./ .def)


ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
Framework_Base 
Toolkit_Base 
Toolkit_Component_Task
View_OGRE3D 
debug OgreMain_d 
optimized OgreMain 
debug tinyxmld_STL 
optimized tinyxml_STL
debug ParticleUniverse_d 
optimized ParticleUniverse
)


INSTALL(TARGETS ${LIB_NAME}
 RUNTIME DESTINATION ${SAN_PROJECT_COMPONENT_DIR}/debug
 CONFIGURATIONS Debug
)

INSTALL(TARGETS ${LIB_NAME}
 RUNTIME DESTINATION ${SAN_PROJECT_COMPONENT_DIR}/release
 CONFIGURATIONS Release
)


ORZ_POST_BUILD_EVENT()
