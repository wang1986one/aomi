


CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0 FATAL_ERROR)

IF( COMMAND CMAKE_POLICY )
   CMAKE_POLICY( SET CMP0003 NEW )
ENDIF( COMMAND CMAKE_POLICY )


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../CMake)


INCLUDE(CPack)
INCLUDE(OrzCMakeModule)
INCLUDE(PrecompiledHeader)
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
 
 
ADD_SUBDIRECTORY(QtExecute)

ORZ_POST_BUILD()

INSTALL(CODE "FILE(APPEND ${CMAKE_INSTALL_PREFIX}/bin/debug/plugins.cfg \"
Plugin=ParticleUniverse_d
Plugin=Plugin_OgreVideo_d
\")")
INSTALL(CODE "FILE(APPEND ${CMAKE_INSTALL_PREFIX}/bin/release/plugins.cfg \"
Plugin=ParticleUniverse
Plugin=Plugin_OgreVideo
\")")


INCLUDE(OrzHunterGame)