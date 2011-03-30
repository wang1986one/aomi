ORZ_FIND(Wheel_Game WheelGame bin/debug/MyWheelController.dll)
MESSAGE(${Wheel_Game_DIR}/include)
INCLUDE_DIRECTORIES(${Wheel_Game_DIR}/include )
LINK_DIRECTORIES(${Wheel_Game_DIR}/lib )

INSTALL(FILES ${Wheel_Game_BIN_DIR}/debug/WheelGobal.dll
${Wheel_Game_BIN_DIR}/debug/MyWheelDirector.dll
${Wheel_Game_BIN_DIR}/debug/MyWheelController.dll
${Wheel_Game_BIN_DIR}/debug/WheelAnimal2Model.dll
${Wheel_Game_BIN_DIR}/debug/WheelAnimal2Controller.dll
DESTINATION ./bin/debug CONFIGURATIONS Debug)


INSTALL(FILES ${Wheel_Game_BIN_DIR}/release/WheelGobal.dll
${Wheel_Game_BIN_DIR}/release/MyWheelDirector.dll
${Wheel_Game_BIN_DIR}/release/MyWheelController.dll
${Wheel_Game_BIN_DIR}/release/WheelAnimal2Model.dll
${Wheel_Game_BIN_DIR}/release/WheelAnimal2Controller.dll
DESTINATION ./bin/release )
