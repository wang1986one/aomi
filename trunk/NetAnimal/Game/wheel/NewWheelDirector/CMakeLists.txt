
ORZ_PRE_BUILD_EVENT(NewWheelDirector)

ADD_DEFINITIONS( -D_CONSOLE -DUSE_LOCK)


INCLUDE_DIRECTORIES(
include

${PROJECT_SOURCE_DIR}/NewWheelController/include
${PROJECT_SOURCE_DIR}/WheelGobal/include 
${PROJECT_SOURCE_DIR}/include 
)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib )



use_precompiled_header(NewWheelDirector
  "${CMAKE_CURRENT_SOURCE_DIR}/include/NewWheelDirectorStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/NewWheelDirectorPrecompiledHeaders.cpp"
)


ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ORZ_SET_PROJECT_FILES(logic\\\\\\\\include include/logic/ .h)
ORZ_SET_PROJECT_FILES(logic\\\\\\\\src src/logic/ .cpp)
ORZ_SET_PROJECT_FILES(def ./ .def)

ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
Framework_Base 
Toolkit_Base 
NewWheelController
)

ORZ_POST_BUILD_EVENT()