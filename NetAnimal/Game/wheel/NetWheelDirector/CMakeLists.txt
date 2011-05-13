
ORZ_PRE_BUILD_EVENT(NetWheelDirector)

ADD_DEFINITIONS( -D_CONSOLE -DUSE_LOCK)

IF(GAME1)
	ADD_DEFINITIONS(-D_GAME1)
ENDIF( GAME1)

INCLUDE_DIRECTORIES(
include
${ORZ_PROJECT_INTERFACE_DIR}/
${PROJECT_SOURCE_DIR}/NetWheelController/include
${PROJECT_SOURCE_DIR}/WheelGobal/include 
${PROJECT_SOURCE_DIR}/include 
)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib )



use_precompiled_header(NetWheelDirector
  "${CMAKE_CURRENT_SOURCE_DIR}/include/NetWheelDirectorStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/NetWheelDirectorPrecompiledHeaders.cpp"
)


ORZ_SET_PROJECT_FILES(interface ${ORZ_PROJECT_INTERFACE_DIR}/ .h)
ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ORZ_SET_PROJECT_FILES(logic\\\\\\\\include include/logic/ .h)
ORZ_SET_PROJECT_FILES(logic\\\\\\\\src src/logic/ .cpp)
ORZ_SET_PROJECT_FILES(ui\\\\\\\\include include/DUI/ .h)
ORZ_SET_PROJECT_FILES(ui\\\\\\\\src src/DUI/ .cpp)
ORZ_SET_PROJECT_FILES(def ./ .def)

ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
Framework_Base 
Toolkit_Base 
debug CEGUIBase_d 
optimized CEGUIBase
NetWheelController
Toolkit_Component_Task
)

ORZ_POST_BUILD_EVENT()