
ORZ_PRE_BUILD_EVENT(Sample)

ADD_DEFINITIONS( -D_CONSOLE)


INCLUDE_DIRECTORIES(
"include"

${PROJECT_SOURCE_DIR}/PUComponent/interface
)




ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)
ADD_EXECUTABLE(${EXE_NAME} ${${EXE_NAME}_FILE})


TARGET_LINK_LIBRARIES(${LIB_NAME} 
debug OgreMain_d 
optimized OgreMain
debug ParticleUniverse_d 
optimized ParticleUniverse
View_Fmod 
View_OGRE3D 
View_CEGUI 
View_OIS 
Framework_Base 
Toolkit_Base 
Toolkit_Component_Task
)

ORZ_POST_BUILD_EVENT()