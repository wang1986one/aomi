
ORZ_PRE_BUILD_EVENT(WheelScene)

ADD_DEFINITIONS( -D_CONSOLE )


INCLUDE_DIRECTORIES(
include
${PROJECT_SOURCE_DIR}/WheelController/include
${PROJECT_SOURCE_DIR}/WheelGobal/include 
)




ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ORZ_SET_PROJECT_FILES(def ./ .def)

ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
Framework_Base 
Toolkit_Base 
)

ORZ_POST_BUILD_EVENT()