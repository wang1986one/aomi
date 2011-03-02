
ORZ_PRE_BUILD_EVENT(WheelData)

ADD_DEFINITIONS( -D_CONSOLE -D${LIB_NAME_TOUPPER}_EXPORTS)


INCLUDE_DIRECTORIES(
include
${PROJECT_SOURCE_DIR}/WheelGobal/include 
)




ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)


ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
View_Fmod 
View_OGRE3D 
View_OIS 
Framework_Base 
Toolkit_Base 
Framework_Base
debug OgreMain_d 
optimized OgreMain 

)

ORZ_POST_BUILD_EVENT()