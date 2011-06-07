CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0 FATAL_ERROR)

IF( COMMAND CMAKE_POLICY )
	CMAKE_POLICY( SET CMP0003 NEW )
ENDIF( COMMAND CMAKE_POLICY )

 
PROJECT(NewGame)


LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../CMake)
INCLUDE(OrzCMakeModule)
INCLUDE(WheelGame)
INCLUDE(OrzParticleUniverse)
INCLUDE(PrecompiledHeader)
INCLUDE(OgreVedio)

LINK_DIRECTORIES( ${PROJECT_SOURCE_DIR}/lib)


ORZ_PRE_BUILD(NewGame)
OPTION(Video "Video"  Video)

IF(Video)
	ADD_DEFINITIONS( -D_LogoVideo)
ENDIF( Video)

FILE(TO_CMAKE_PATH ${SAN_PROJECT_DIR}/interface SAN_PROJECT_INTERFACE_DIR)
FILE(TO_CMAKE_PATH ${SAN_PROJECT_DIR}/component SAN_PROJECT_COMPONENT_DIR)

INCLUDE_DIRECTORIES(
${SAN_PROJECT_INTERFACE_DIR}
)

INCLUDE(OrzSingleChip)



ADD_SUBDIRECTORY(CCS)
ADD_SUBDIRECTORY(Tasks)
ADD_SUBDIRECTORY(SanController)
ADD_SUBDIRECTORY(SanModel)
ADD_SUBDIRECTORY(SanExecute)
ADD_SUBDIRECTORY(SanUnitTest)
ADD_SUBDIRECTORY(NewGameComponents)
ADD_SUBDIRECTORY(TasksUnitTest)


ADD_DEPENDENCIES(SanModel SanController)
ADD_DEPENDENCIES(SanController CCS)


ADD_DEPENDENCIES(SanExecute SanModel)
ADD_DEPENDENCIES(TasksUnitTest Tasks)
ADD_DEPENDENCIES(SanUnitTest SanExecute SanModel SanController)


INSTALL(CODE "FILE(APPEND ${CMAKE_INSTALL_PREFIX}/bin/debug/plugins.cfg \"
Plugin=ParticleUniverse_d
Plugin=Plugin_OgreVideo_d
\")")
INSTALL(CODE "FILE(APPEND ${CMAKE_INSTALL_PREFIX}/bin/release/plugins.cfg \"
Plugin=ParticleUniverse
Plugin=Plugin_OgreVideo
\")")

ORZ_POST_BUILD()


INCLUDE(FindSanProject)


INSTALL(CODE "FILE(APPEND ${CMAKE_INSTALL_PREFIX}/bin/debug/resources.cfg \"\\n
[xml]
FileSystem=${Media_DIR}/xml/
\\n\")")

INSTALL(CODE "FILE(APPEND ${CMAKE_INSTALL_PREFIX}/bin/release/resources.cfg \"\\n
[xml]
FileSystem=${Media_DIR}/xml/
\\n\")")

INSTALL(CODE "FILE(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/media/xml)")


INSTALL(CODE "FILE(WRITE ${Media_DIR}/xml/sc.xml 
\"<?xml version=\\\"1.0\\\" standalone=\\\"yes\\\"?>
<single-chips>
  <single-chip port=\\\"COM5\\\" baud-rate=\\\"9600\\\" />
</single-chips>
\" 

)"

)