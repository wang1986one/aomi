
ORZ_PRE_BUILD_EVENT(Tasks)

ADD_DEFINITIONS(-D_CONSOLE -D${LIB_NAME_TOUPPER}_EXPORTS -DTIXML_USE_STL)


INCLUDE_DIRECTORIES(
include
)


# specify a precompiled header to use
use_precompiled_header(Tasks
  "${CMAKE_CURRENT_SOURCE_DIR}/include/TasksStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/TasksPrecompiledHeaders.cpp"
)

ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)








ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
Framework_Base 
Toolkit_Base 
Toolkit_Component_Task
)

ORZ_POST_BUILD_EVENT()