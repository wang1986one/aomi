
ORZ_PRE_BUILD_EVENT(TasksUnitTest)

ADD_DEFINITIONS( -D_CONSOLE)


INCLUDE_DIRECTORIES(
include
${PROJECT_SOURCE_DIR}/Tasks/include
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
Toolkit_Component_Task
Tasks
)

ORZ_POST_BUILD_EVENT()