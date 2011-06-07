


CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0 FATAL_ERROR)
PROJECT(OrzQt)
IF( COMMAND CMAKE_POLICY )
   CMAKE_POLICY( SET CMP0003 NEW )
ENDIF( COMMAND CMAKE_POLICY )


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../CMake)


INCLUDE(CPack)
INCLUDE(OrzCMakeModule)
INCLUDE(PrecompiledHeader)
INCLUDE(FindOrzProjectBeginInstall)
INCLUDE(Ajax)

FIND_PACKAGE(OrzSDK)
FIND_PACKAGE(Qt4 REQUIRED) # find and setup Qt4 for this project

ORZ_PRE_BUILD(OrzQt)

INSTALL(FILES 
${QT_BINARY_DIR}/QtGuid4.dll
${QT_BINARY_DIR}/QtCored4.dll
${QT_BINARY_DIR}/QtWebKitd4.dll
${QT_BINARY_DIR}/QtNetworkd4.dll
${QT_BINARY_DIR}/phonond4.dll
 DESTINATION ./bin/Debug)
 
 
INSTALL(FILES 
${QT_BINARY_DIR}/QtGui4.dll
${QT_BINARY_DIR}/QtCore4.dll
${QT_BINARY_DIR}/QtWebKit4.dll
${QT_BINARY_DIR}/QtNetwork4.dll
${QT_BINARY_DIR}/phonon4.dll
 DESTINATION ./bin/Release)
 
INCLUDE(OrzHunterGame)
INCLUDE(WheelGame)
 
ADD_SUBDIRECTORY(JsComponent)
ADD_SUBDIRECTORY(QtExecute)
ADD_SUBDIRECTORY(UnitTest)

ORZ_POST_BUILD()

INSTALL(CODE "FILE(WRITE ${CMAKE_INSTALL_PREFIX}/bin/debug/plugins.cfg \"
# Defines plugins to load

# Define plugin folder
PluginFolder=.

# Define plugins
 Plugin=RenderSystem_GL_d
 Plugin=Plugin_ParticleFX_d
 Plugin=Plugin_BSPSceneManager_d
 Plugin=Plugin_CgProgramManager_d
 Plugin=Plugin_PCZSceneManager_d
 Plugin=Plugin_OctreeZone_d
 Plugin=Plugin_OctreeSceneManager_d

Plugin=ParticleUniverse_d
Plugin=Plugin_OgreVideo_d

\")")



#INSTALL(DIRECTORY ${ORZ_PROJECT_DIR}/media DESTINATION ./bin/debug PATTERN "CVS" EXCLUDE PATTERN ".svn"  EXCLUDE)

#INSTALL(DIRECTORY ${ORZ_PROJECT_DIR}/media DESTINATION ./bin/release PATTERN "CVS" EXCLUDE PATTERN ".svn"  EXCLUDE)



INCLUDE(FindOrzProjectEnd)	
MESSAGE(${CMAKE_INSTALL_PREFIX})
INSTALL(CODE "FILE(WRITE ${CMAKE_INSTALL_PREFIX}/bin/release/plugins.cfg \"
# Defines plugins to load

# Define plugin folder
PluginFolder=.


# Define plugins
 Plugin=RenderSystem_GL
 Plugin=Plugin_ParticleFX
 Plugin=Plugin_BSPSceneManager
 Plugin=Plugin_CgProgramManager
 Plugin=Plugin_PCZSceneManager
 Plugin=Plugin_OctreeZone
 Plugin=Plugin_OctreeSceneManager
 Plugin=ParticleUniverse
 Plugin=Plugin_OgreVideo
\")")
