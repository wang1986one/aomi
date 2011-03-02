ORZ_FIND(Orz_WheelGame OrzWheelGame bin/debug/View_SingleChip.dll)
INCLUDE_DIRECTORIES(${Orz_SingleChip_INCLUDE_DIR})
LINK_DIRECTORIES(${Orz_SingleChip_LIBRARY_DIR})
INSTALL(FILES 
${Orz_SingleChip_BIN_DIR}/debug/View_SingleChip.dll 
DESTINATION 
./bin/debug 
CONFIGURATIONS Debug)

INSTALL(FILES 
${Orz_SingleChip_BIN_DIR}/release/View_SingleChip.dll
 DESTINATION ./bin/release 
 CONFIGURATIONS Release)

