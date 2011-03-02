
ORZ_PRE_BUILD_EVENT(CodingComponent)

ADD_DEFINITIONS(-D_CONSOLE -D${LIB_NAME_TOUPPER}_EXPORTS -DTIXML_USE_STL -DCCS_OGRE_1_7)


INCLUDE_DIRECTORIES(
include
ui/include
${PROJECT_SOURCE_DIR}/Tasks/include
)


# specify a precompiled header to use
use_precompiled_header(CodingComponent
  "${CMAKE_CURRENT_SOURCE_DIR}/include/CodingComponentStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/CodingComponentPrecompiledHeaders.cpp"
)

ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)

ORZ_SET_PROJECT_FILES(interface ${SAN_PROJECT_INTERFACE_DIR}/ .h)
ORZ_SET_PROJECT_FILES(def ./ .def)

ORZ_SET_PROJECT_FILES("ui\\\\\\\\include" ${CMAKE_CURRENT_SOURCE_DIR}/ui/include/ .h)
ORZ_SET_PROJECT_FILES("ui\\\\\\\\src" ${CMAKE_CURRENT_SOURCE_DIR}/ui/src/ .cpp)






ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
Framework_Base 
Toolkit_Base 
Toolkit_Component_Task
EleCryptST
EliteeST
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