ORZ_FIND(Orz_Trigger OrzTrigger bin/debug/Toolkit_Trigger.dll)

INCLUDE_DIRECTORIES(${Orz_Trigger_INCLUDE_DIR})
LINK_DIRECTORIES(${Orz_Trigger_LIBRARY_DIR})


INSTALL(FILES ${Orz_Trigger_BIN_DIR}/debug/Toolkit_Trigger.dll
DESTINATION ./bin/debug CONFIGURATIONS Debug)


INSTALL(FILES ${Orz_Trigger_BIN_DIR}/release/Toolkit_Trigger.dll
DESTINATION ./bin/release CONFIGURATIONS Release)



