ORZ_FIND(Wheel_Game WheelGame bin/debug/WheelGobal.dll)

INCLUDE_DIRECTORIES(${Wheel_Game_INCLUDE_DIR} )
LINK_DIRECTORIES(${Wheel_Game_LIBRARY_DIR} )


OPTION( MyWheelDirector "MyWheelDirector"  MyWheelDirector?)
OPTION( NetWheelDirector "NetWheelDirector"  NetWheelDirector?)
OPTION( WheelAnimal2 "WheelAnimal2"  WheelAnimal2?)


INSTALL(FILES ${Wheel_Game_BIN_DIR}/debug/WheelGobal.dll
DESTINATION ./bin/debug CONFIGURATIONS Debug)


INSTALL(FILES ${Wheel_Game_BIN_DIR}/release/WheelGobal.dll
DESTINATION ./bin/release  CONFIGURATIONS Release)


IF(MyWheelDirector)

	INSTALL(FILES
	${Wheel_Game_BIN_DIR}/debug/MyWheelDirector.dll
	${Wheel_Game_BIN_DIR}/debug/MyWheelController.dll
	DESTINATION ./bin/debug CONFIGURATIONS Debug)
	
	INSTALL(FILES
	${Wheel_Game_BIN_DIR}/release/MyWheelDirector.dll
	${Wheel_Game_BIN_DIR}/release/MyWheelController.dll
	DESTINATION ./bin/release CONFIGURATIONS Release)
	
	
	ADD_DEFINITIONS( -D_MyWheelDirector)
ENDIF( MyWheelDirector)


IF(NetWheelDirector)
   
	INSTALL(FILES
	${Wheel_Game_BIN_DIR}/debug/NetWheelDirector.dll
	${Wheel_Game_BIN_DIR}/debug/NetWheelController.dll
	DESTINATION ./bin/debug CONFIGURATIONS Debug)
	
	INSTALL(FILES
	${Wheel_Game_BIN_DIR}/release/NetWheelDirector.dll
	${Wheel_Game_BIN_DIR}/release/NetWheelController.dll
	DESTINATION ./bin/release CONFIGURATIONS Release)
	ADD_DEFINITIONS( -D_NetWheelDirector)
	
ENDIF( NetWheelDirector)


IF(WheelAnimal2)
	
	INSTALL(FILES
	${Wheel_Game_BIN_DIR}/debug/WheelAnimal2Model.dll
	${Wheel_Game_BIN_DIR}/debug/WheelAnimal2Controller.dll
	DESTINATION ./bin/debug CONFIGURATIONS Debug)
	
	INSTALL(FILES
	${Wheel_Game_BIN_DIR}/release/WheelAnimal2Model.dll
	${Wheel_Game_BIN_DIR}/release/WheelAnimal2Controller.dll
	DESTINATION ./bin/release CONFIGURATIONS Release)
	
	ADD_DEFINITIONS( -D_WheelAnimal2)
ENDIF( WheelAnimal2)


