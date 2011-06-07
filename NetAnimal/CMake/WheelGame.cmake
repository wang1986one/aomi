ORZ_FIND(Wheel_Game WheelGame bin/debug/WheelGobal.dll)

INCLUDE_DIRECTORIES(${Wheel_Game_DIR}/include/ )
LINK_DIRECTORIES(${Wheel_Game_DIR}/lib/ )


OPTION( MyWheelDirector "MyWheelDirector"  MyWheelDirector?)
OPTION( NetWheelDirector "NetWheelDirector"  NetWheelDirector?)
OPTION( WheelAnimal2 "WheelAnimal2"  WheelAnimal2?)


INSTALL(FILES ${Wheel_Game_DIR}/bin/debug/WheelGobal.dll
DESTINATION ./bin/debug CONFIGURATIONS Debug)


INSTALL(FILES ${Wheel_Game_DIR}/bin/release/WheelGobal.dll
DESTINATION ./bin/release  CONFIGURATIONS Release)


IF(MyWheelDirector)

	INSTALL(FILES
	${Wheel_Game_DIR}/bin/debug/MyWheelDirector.dll
	${Wheel_Game_DIR}/bin/debug/MyWheelController.dll
	DESTINATION ./bin/debug CONFIGURATIONS Debug)
	
	INSTALL(FILES
	${Wheel_Game_DIR}/bin/release/MyWheelDirector.dll
	${Wheel_Game_DIR}/bin/release/MyWheelController.dll
	DESTINATION ./bin/release CONFIGURATIONS Release)
ENDIF( MyWheelDirector)


IF(NetWheelDirector)
   
	INSTALL(FILES
	${Wheel_Game_DIR}/bin/debug/NetWheelDirector.dll
	${Wheel_Game_DIR}/bin/debug/NetWheelController.dll
	DESTINATION ./bin/debug CONFIGURATIONS Debug)
	
	INSTALL(FILES
	${Wheel_Game_DIR}/bin/release/NetWheelDirector.dll
	${Wheel_Game_DIR}/bin/release/NetWheelController.dll
	DESTINATION ./bin/release CONFIGURATIONS Release)
	
ENDIF( NetWheelDirector)


IF(WheelAnimal2)
	
	INSTALL(FILES
	${Wheel_Game_DIR}/bin/debug/WheelAnimal2Model.dll
	${Wheel_Game_DIR}/bin/debug/WheelAnimal2Controller.dll
	DESTINATION ./bin/debug CONFIGURATIONS Debug)
	
	INSTALL(FILES
	${Wheel_Game_DIR}/bin/release/WheelAnimal2Model.dll
	${Wheel_Game_DIR}/bin/release/WheelAnimal2Controller.dll
	DESTINATION ./bin/release CONFIGURATIONS Release)
	
ENDIF( WheelAnimal2)


