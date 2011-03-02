ORZ_FIND(Wheel_Game WheelGame bin/debug/MyWheelController.dll)

INCLUDE_DIRECTORIES(${Wheel_Game_INCLUDE_DIR} )
LINK_DIRECTORIES(${Wheel_Game_LIBRARY_DIR} )

INSTALL(FILES ${Wheel_Game_BIN_DIR}/debug/WheelGobal.dll
${Wheel_Game_BIN_DIR}/debug/MyWheelDirector.dll
${Wheel_Game_BIN_DIR}/debug/MyWheelController.dll
DESTINATION ./bin/debug CONFIGURATIONS Debug)


INSTALL(FILES ${Wheel_Game_BIN_DIR}/release/WheelGobal.dll
${Wheel_Game_BIN_DIR}/release/MyWheelDirector.dll
${Wheel_Game_BIN_DIR}/release/MyWheelController.dll
DESTINATION ./bin/release )
