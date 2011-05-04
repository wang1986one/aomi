CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0 FATAL_ERROR)

PROJECT(OrzSingleChip)

IF( COMMAND CMAKE_POLICY )
	CMAKE_POLICY( SET CMP0003 NEW )
ENDIF( COMMAND CMAKE_POLICY )



LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../cmake)
INCLUDE(CPack)
INCLUDE(OrzCmakeModule)





ORZ_PRE_BUILD(OrzSingleChip)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/View_SingleChip/include)
INSTALL(DIRECTORY ${PROJECT_SOURCE_DIR}/orz DESTINATION ./include PATTERN "CVS" EXCLUDE PATTERN ".svn" EXCLUDE)





ADD_SUBDIRECTORY(View_SingleChip)
ADD_SUBDIRECTORY(UT_SingleChip)


ADD_DEPENDENCIES(UT_SingleChip View_SingleChip)


ORZ_POST_BUILD()

MESSAGE(${CMAKE_INSTALL_PREFIX}/)


INSTALL(CODE "FILE(APPEND ${CMAKE_INSTALL_PREFIX}/bin/debug/resources.cfg \"\\n
[xml]
FileSystem=../../media/xml/
\\n\")")

INSTALL(CODE "FILE(APPEND ${CMAKE_INSTALL_PREFIX}/bin/release/resources.cfg \"\\n
[xml]
FileSystem=../../media/xml/
\\n\")")

INSTALL(CODE "FILE(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/media/xml)")


INSTALL(CODE "FILE(WRITE ${CMAKE_INSTALL_PREFIX}/media/xml/sc.xml 
\"<?xml version=\\\"1.0\\\" standalone=\\\"yes\\\"?>
<single-chips>
  <single-chip port=\\\"COM2\\\" baud-rate=\\\"9600\\\" />
  <single-chip port=\\\"COM3\\\" baud-rate=\\\"9600\\\" />
  <single-chip port=\\\"COM4\\\" baud-rate=\\\"9600\\\" />
  <single-chip port=\\\"COM5\\\" baud-rate=\\\"9600\\\" />
  <single-chip port=\\\"COM6\\\" baud-rate=\\\"9600\\\" />
  <single-chip port=\\\"COM7\\\" baud-rate=\\\"9600\\\" />
  <single-chip port=\\\"COM8\\\" baud-rate=\\\"9600\\\" />
  <single-chip port=\\\"COM9\\\" baud-rate=\\\"9600\\\" />
  <single-chip port=\\\"COM10\\\" baud-rate=\\\"9600\\\" />
  <single-chip port=\\\"COM11\\\" baud-rate=\\\"9600\\\" />
</single-chips>
\" 

)"

)
