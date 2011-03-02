
ORZ_PRE_BUILD_EVENT(UnitTest)

ADD_DEFINITIONS( -D_CONSOLE)


INCLUDE_DIRECTORIES(
include
${PROJECT_SOURCE_DIR}/MyWheelController/include
${PROJECT_SOURCE_DIR}/WheelGobal/include 
${PROJECT_SOURCE_DIR}/WheelAnimalController/include 

${ORZ_PROJECT_INTERFACE_DIR}/

)


# specify a precompiled header to use
use_precompiled_header(CodingComponent
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
View_SingleChip
Toolkit_Base 
Framework_Base
WheelGobal
MyWheelController
WheelAnimal2Controller
)

ORZ_POST_BUILD_EVENT()