
MACRO(ORZ_ADD_PROJECT type group dir)

	FOREACH(var ${ARGN})
		LIST(APPEND ${LIB_NAME}_${type} ${dir}${var})
		SOURCE_GROUP(${group} FILES ${dir}${var})
	ENDFOREACH( var )

ENDMACRO(ORZ_ADD_PROJECT)


# create vcproj.user file for Visual Studio to set debug working directory
FUNCTION(CREATE_VCPROJ_USERFILE target)
   FILE(TO_CMAKE_PATH  ${CMAKE_INSTALL_PREFIX} MY_PROJECT_BINARY_DIR)
   FILE(TO_CMAKE_PATH  ${CMAKE_INSTALL_PREFIX} MY_PROJECT_WORK_DIR)
   CONFIGURE_FILE(
	   ${PROJECT_SOURCE_DIR}/CMake/Templates/VisualStudioUserFile.vcproj.user.in
	   ${CMAKE_CURRENT_BINARY_DIR}/${target}.vcproj.user
	  @ONLY
	)
ENDFUNCTION(CREATE_VCPROJ_USERFILE)

MACRO(ORZ_SET_PROJECT type group dir match)

	FILE(GLOB var ${dir}*${match})
	
	FOREACH(f ${var})
		GET_FILENAME_COMPONENT(f ${f} NAME_WE)
		ORZ_ADD_PROJECT(${type} ${group} ${dir} "${f}${match}")
	ENDFOREACH()

ENDMACRO(ORZ_SET_PROJECT)



MACRO(ORZ_ADD_PROJECT_FILE group dir)
	FOREACH(var ${ARGN})
		LIST(APPEND ${LIB_NAME}_FILE ${dir}${var})
		SOURCE_GROUP(${group} FILES ${dir}${var})
	ENDFOREACH( var )
ENDMACRO(ORZ_ADD_PROJECT_FILE)



MACRO(ORZ_SET_PROJECT_FILES group dir match)

	FILE(GLOB orz_files  ${dir}*${match})
	
	FOREACH(f ${orz_files})
		GET_FILENAME_COMPONENT(f ${f} NAME_WE)
		ORZ_ADD_PROJECT_FILE(${group} ${dir} "${f}${match}")

	ENDFOREACH()

ENDMACRO(ORZ_SET_PROJECT_FILES)






MACRO( ORZ_PRE_BUILD_EVENT target )
	SET( LIB_NAME ${target} )
	SET( EXE_NAME ${target} )
	STRING(TOUPPER ${LIB_NAME} LIB_NAME_TOUPPER)
ENDMACRO( ORZ_PRE_BUILD_EVENT )


MACRO( ORZ_POST_BUILD_EVENT )
	INSTALL(TARGETS ${LIB_NAME} 
		RUNTIME DESTINATION bin/debug
		CONFIGURATIONS Debug
		LIBRARY DESTINATION lib/debug
		CONFIGURATIONS Debug
		ARCHIVE DESTINATION lib/debug
		CONFIGURATIONS Debug
	)

	INSTALL(TARGETS ${LIB_NAME} 
		RUNTIME DESTINATION bin/release
		CONFIGURATIONS Release
		LIBRARY DESTINATION lib/release 
		CONFIGURATIONS Release
		ARCHIVE DESTINATION lib/release
		CONFIGURATIONS Release
	)

	
	CREATE_VCPROJ_USERFILE(${LIB_NAME})
ENDMACRO(  ORZ_POST_BUILD_EVENT)





MACRO(ORZ_FIND name dir file)
	SET(${name}_DIR "" CACHE PATH "the directory of the ${name}")


	IF(${name}_DIR)
 		FIND_PATH( 
		_temp_ 	
		${file}
		PATHS 
		${${name}_DIR}
		NO_DEFAULT_PATH
		)
	
		IF(NOT _temp_)
			MESSAGE("\"${${name}}\" is not the ${name}'s directory")
			UNSET(${name} CACHE)
		ENDIF(NOT _temp_)
	
		UNSET(_temp_ CACHE)
	ENDIF(${name}_DIR)

	IF(NOT ${name}_DIR)
		UNSET(${name} CACHE)
	FIND_PATH(
		_temp_	
		${file}
		PATHS 
		${PROJECT_SOURCE_DIR}/build/${dir}
		${PROJECT_SOURCE_DIR}/../build/${dir}
		${PROJECT_SOURCE_DIR}/../../build/${dir}
		NO_DEFAULT_PATH
		)
		SET(${name}_DIR  ${_temp_} CACHE PATH "the directory of the ${name}" FORCE)
		UNSET(_temp_ CACHE)

		
		MESSAGE(${name}_DIR)	


	ENDIF(NOT ${name}_DIR)

	IF(NOT ${name}_DIR)
		MESSAGE("[You have to select the directory of the ${name}!]  ")
	ELSE(NOT ${name}_DIR)
		SET(${name}_LIBRARY_DIR  ${${name}_DIR}/lib CACHE PATH "the directory of the ${name} library" FORCE)
		SET(${name}_INCLUDE_DIR  ${${name}_DIR}/include CACHE PATH "the directory of the ${name} include" FORCE)
		SET(${name}_BIN_DIR  ${${name}_DIR}/bin CACHE PATH "the directory of the ${name} bin" FORCE)
	ENDIF(NOT ${name}_DIR)
	
ENDMACRO(ORZ_FIND)



MACRO( ORZ_PRE_BUILD project )


	PROJECT(${project})
	


	SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
	SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)


	
	FIND_PACKAGE(OrzSDK)


	LINK_DIRECTORIES(
		${Orz_SDK_DIR}/lib 
		${Orz_SDK_DIR}/dependencies/lib
		)


	INCLUDE_DIRECTORIES(${Orz_SDK_DIR}/dependencies/include ${Orz_SDK_DIR}/include)
	INSTALL(DIRECTORY ${Orz_SDK_DIR}/media DESTINATION ./ PATTERN "CVS" EXCLUDE  PATTERN ".svn" EXCLUDE PATTERN "*.exe" EXCLUDE)


	INSTALL(DIRECTORY ${Orz_SDK_DIR}/bin DESTINATION ./ PATTERN "CVS" EXCLUDE  PATTERN ".svn" EXCLUDE PATTERN "*.exe" EXCLUDE)
ENDMACRO(ORZ_PRE_BUILD)


MACRO( ORZ_POST_BUILD)
  
  #SET(CMAKE_INSTALL_PREFIX "${Orz_SDK_DIR}/../${PROJECT_NAME}/" CACHE PATH "${PROJECT_NAME} install prefix" FORCE ) 

ENDMACRO(  ORZ_POST_BUILD)