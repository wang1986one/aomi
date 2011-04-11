ORZ_FIND(Wheel_Game WheelGame bin/debug/MyWheelController.dll)
MESSAGE(${Wheel_Game_DIR}/include)
INCLUDE_DIRECTORIES(${Wheel_Game_DIR}/include )
LINK_DIRECTORIES(${Wheel_Game_DIR}/lib )

INSTALL(FILES ${Wheel_Game_DIR}/bin/debug/WheelGobal.dll
${Wheel_Game_DIR}/bin/debug/MyWheelDirector.dll
${Wheel_Game_DIR}/bin/debug/MyWheelController.dll
${Wheel_Game_DIR}/bin/debug/WheelAnimal2Model.dll
${Wheel_Game_DIR}/bin/debug/WheelAnimal2Controller.dll
DESTINATION ./bin/debug CONFIGURATIONS Debug)


INSTALL(FILES ${Wheel_Game_DIR}/bin/release/WheelGobal.dll
${Wheel_Game_DIR}/bin/release/MyWheelDirector.dll
${Wheel_Game_DIR}/bin/release/MyWheelController.dll
${Wheel_Game_DIR}/bin/release/WheelAnimal2Model.dll
${Wheel_Game_DIR}/bin/release/WheelAnimal2Controller.dll
DESTINATION ./bin/release )
