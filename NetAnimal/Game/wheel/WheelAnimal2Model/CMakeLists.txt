
ORZ_PRE_BUILD_EVENT(WheelAnimal2Model)

ADD_DEFINITIONS( -D_CONSOLE )

IF(GAME1)
	ADD_DEFINITIONS(-D_GAME1)
ENDIF( GAME1)


INCLUDE_DIRECTORIES(
include
${PROJECT_SOURCE_DIR}/WheelAnimal2Controller/include
${PROJECT_SOURCE_DIR}/WheelController/include
${PROJECT_SOURCE_DIR}/WheelGobal/include 
)



use_precompiled_header(WheelAnimal2Model
  "${CMAKE_CURRENT_SOURCE_DIR}/include/WheelAnimalModelStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/WheelAnimalModelPrecompiledHeaders.cpp"
)


ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ORZ_SET_PROJECT_FILES(def ./ .def)

ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
WheelAnimal2Controller
Framework_Base 
Toolkit_Base 
Toolkit_Component_Task
WheelGobal
)

ORZ_POST_BUILD_EVENT()