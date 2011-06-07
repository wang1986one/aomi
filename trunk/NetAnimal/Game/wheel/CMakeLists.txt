CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0 FATAL_ERROR)
PROJECT(WheelGame)
IF( COMMAND CMAKE_POLICY )
	CMAKE_POLICY( SET CMP0003 NEW )
ENDIF( COMMAND CMAKE_POLICY )


OPTION( GAME1 "GAME1"  game1?)

IF(GAME1)
	ADD_DEFINITIONS(-D_GAME1)
ENDIF( GAME1)

OPTION( MyWheelDirector "MyWheelDirector"  MyWheelDirector?)
OPTION( NetWheelDirector "NetWheelDirector"  NetWheelDirector?)
OPTION( WheelAnimal2 "WheelAnimal2"  WheelAnimal2?)


MESSAGE(${NetWheelDirector})


LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)
INCLUDE(OrzCMakeModule)

INCLUDE(PrecompiledHeader)


LINK_DIRECTORIES( ${PROJECT_SOURCE_DIR}/lib)


ORZ_PRE_BUILD(WheelGame)
INCLUDE(OrzSingleChip)

INCLUDE(FindOrzProjectBegin)


FILE(TO_CMAKE_PATH ${ORZ_PROJECT_DIR}/interface ORZ_PROJECT_INTERFACE_DIR)
FILE(TO_CMAKE_PATH ${ORZ_PROJECT_DIR}/component ORZ_PROJECT_COMPONENT_DIR)



IF(MyWheelDirector)
	ADD_DEFINITIONS(-D_MyWheelDirector)
ENDIF( MyWheelDirector)


IF(NetWheelDirector)
	ADD_DEFINITIONS(-D_NetWheelDirector)
ENDIF( NetWheelDirector)


IF(WheelAnimal2)
	ADD_DEFINITIONS(-D_WheelAnimal2)
ENDIF( WheelAnimal2)


IF(MyWheelDirector)
    ADD_SUBDIRECTORY(MyWheelDirector)
    ADD_SUBDIRECTORY(MyWheelController)
ENDIF( MyWheelDirector)


IF(NetWheelDirector)
    ADD_SUBDIRECTORY(NetWheelDirector)
    ADD_SUBDIRECTORY(NetWheelController)
ENDIF( NetWheelDirector)


IF(WheelAnimal2)
    ADD_SUBDIRECTORY(WheelAnimal2Controller)
    ADD_SUBDIRECTORY(WheelAnimal2Model)
ENDIF( WheelAnimal2)

ADD_SUBDIRECTORY(UnitTest)
ADD_SUBDIRECTORY(Wheel)

ADD_SUBDIRECTORY(WheelGobal)



IF(MyWheelDirector)
	ADD_DEPENDENCIES(MyWheelController WheelGobal)
	ADD_DEPENDENCIES(MyWheelDirector MyWheelController)
ENDIF( MyWheelDirector)


IF(NetWheelDirector)
	ADD_DEPENDENCIES(NetWheelController WheelGobal)
	ADD_DEPENDENCIES(NetWheelDirector NetWheelController)
	MESSAGE(123)
ENDIF( NetWheelDirector)


IF(WheelAnimal2)
	ADD_DEPENDENCIES(WheelAnimal2Model WheelAnimal2Controller)
	ADD_DEPENDENCIES(UnitTest WheelAnimal2Model)
ENDIF( WheelAnimal2)

ADD_DEPENDENCIES(UnitTest WheelGobal)
ADD_DEPENDENCIES(Wheel UnitTest)


	


#INSTALL(DIRECTORY ${Orz_SDK_DIR}/media  DESTINATION ./ PATTERN "CVS" EXCLUDE  PATTERN ".svn" EXCLUDE PATTERN "*.exe" EXCLUDE)
#INSTALL(DIRECTORY ${PROJECT_SOURCE_DIR}/media DESTINATION ./ PATTERN "CVS" EXCLUDE PATTERN ".svn" EXCLUDE)



ORZ_POST_BUILD()

INCLUDE(FindOrzProjectEnd)



INSTALL(CODE "FILE(APPEND ${CMAKE_INSTALL_PREFIX}/bin/debug/resources.cfg \"\\n
[xml]
FileSystem=${ORZ_MEDIA_DIR}/xml/
\\n\")")

INSTALL(CODE "FILE(APPEND ${CMAKE_INSTALL_PREFIX}/bin/release/resources.cfg \"\\n
[xml]
FileSystem=${ORZ_MEDIA_DIR}/xml/
\\n\")")

INSTALL(CODE "FILE(MAKE_DIRECTORY ${ORZ_MEDIA_DIR}/xml)")


INSTALL(CODE "FILE(WRITE ${ORZ_MEDIA_DIR}/xml/sc.xml 
\"<?xml version=\\\"1.0\\\" standalone=\\\"yes\\\"?>
<single-chips>
  <single-chip port=\\\"COM5\\\" baud-rate=\\\"9600\\\" />
</single-chips>
\" 

)"

)