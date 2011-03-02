
ORZ_PRE_BUILD_EVENT(SanModel)

ADD_DEFINITIONS( -D_CONSOLE )


INCLUDE_DIRECTORIES(
include
${PROJECT_SOURCE_DIR}/CCS/include
)

# specify a precompiled header to use
use_precompiled_header(SanModel 
  "${CMAKE_CURRENT_SOURCE_DIR}/include/SanModelBaseStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/SanModelBasePrecompiledHeaders.cpp"
)


ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ORZ_SET_PROJECT_FILES(def ./ .def)


ORZ_SET_PROJECT_FILES(ui\\\\\\\\include ${CMAKE_CURRENT_SOURCE_DIR}/include/ui/ .h)
ORZ_SET_PROJECT_FILES(ui\\\\\\\\src ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/ .cpp)



ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
Framework_Base 
Toolkit_Base 
Toolkit_Component_Task
WheelGobal

CCS
debug OgreMain_d 
optimized OgreMain 
debug CEGUIBase_d 
optimized CEGUIBase
)


ORZ_POST_BUILD_EVENT()