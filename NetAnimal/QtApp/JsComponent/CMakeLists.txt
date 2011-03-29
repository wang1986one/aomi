
ORZ_PRE_BUILD_EVENT(JsComponent)

ADD_DEFINITIONS( -D_WIN32_WINNT=0x0500)


INCLUDE_DIRECTORIES(
include
${ORZ_PROJECT_INTERFACE_DIR}
)

# specify a precompiled header to use
use_precompiled_header(${LIB_NAME}
  "${CMAKE_CURRENT_SOURCE_DIR}/include/${LIB_NAME}StableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/${LIB_NAME}PrecompiledHeaders.cpp"
)
ORZ_SET_PROJECT_FILES(include include/ .h)


ORZ_SET_PROJECT_FILES(interface ${ORZ_PROJECT_INTERFACE_DIR}/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ORZ_SET_PROJECT_FILES(def ./ .def)



ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
Framework_Base 
Toolkit_Base 
Toolkit_Component_Task
)


INSTALL(TARGETS ${LIB_NAME}
 RUNTIME DESTINATION ${ORZ_PROJECT_DIR}/component/bin/debug
 CONFIGURATIONS Debug
)

INSTALL(TARGETS ${LIB_NAME}
 RUNTIME DESTINATION ${ORZ_PROJECT_DIR}/component/bin/release
 CONFIGURATIONS Release
)


ORZ_POST_BUILD_EVENT()
