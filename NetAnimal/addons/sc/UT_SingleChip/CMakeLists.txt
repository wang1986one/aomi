ORZ_PRE_BUILD_EVENT(UT_SingleChip)

ADD_DEFINITIONS( -D_CONSOLE -D_WIN32_WINNT=0x0501 -DWIN32_LEAN_AND_MEAN)

INCLUDE_DIRECTORIES("include")




ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)


ADD_EXECUTABLE(${EXE_NAME} ${${EXE_NAME}_FILE})



TARGET_LINK_LIBRARIES(
${EXE_NAME} 
Framework_Base
View_SingleChip
View_OGRE3D
Toolkit_Base
View_OIS
debug OgreMain_d
optimized OgreMain
)

ORZ_POST_BUILD_EVENT()