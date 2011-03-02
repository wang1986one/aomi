
ORZ_PRE_BUILD_EVENT(WheelAnimalModel)

ADD_DEFINITIONS( -D_CONSOLE )


INCLUDE_DIRECTORIES(
include
${PROJECT_SOURCE_DIR}/WheelAnimalController/include
${PROJECT_SOURCE_DIR}/WheelController/include
${PROJECT_SOURCE_DIR}/WheelGobal/include 
)



use_precompiled_header(WheelAnimalModel
  "${CMAKE_CURRENT_SOURCE_DIR}/include/WheelAnimalModelStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/WheelAnimalModelPrecompiledHeaders.cpp"
)


ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ORZ_SET_PROJECT_FILES(def ./ .def)

ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
WheelAnimalController
Framework_Base 
Toolkit_Base 

WheelGobal
)

ORZ_POST_BUILD_EVENT()