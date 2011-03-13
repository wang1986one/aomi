ORZ_FIND(Orz_SingleChip OrzSingleChip bin/debug/View_SingleChip.dll)
INCLUDE_DIRECTORIES(${Orz_SingleChip_DIR}/include)
LINK_DIRECTORIES(${Orz_SingleChip_DIR}/lib)

INSTALL(FILES ${Orz_SingleChip_DIR}/bin/debug/View_SingleChip.dll DESTINATION ./bin/debug CONFIGURATIONS Debug)
INSTALL(FILES ${Orz_SingleChip_DIR}/bin/release/View_SingleChip.dll DESTINATION ./bin/release CONFIGURATIONS Release)

