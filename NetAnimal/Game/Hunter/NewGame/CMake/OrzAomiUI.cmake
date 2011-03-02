ORZ_FIND(Orz_AomiUI OrzAomiUI bin/debug/View_AomiUI.dll)
INCLUDE_DIRECTORIES(${Orz_AomiUI_INCLUDE_DIR} ${Orz_AomiUI_DIR}/dependencies/include
 ${Orz_AomiUI_DIR}/dependencies/include/awesomium
)
LINK_DIRECTORIES(${Orz_AomiUI_LIBRARY_DIR} ${Orz_AomiUI_DIR}/dependencies/lib)
INSTALL(FILES 
${Orz_AomiUI_BIN_DIR}/debug/View_AomiUI.dll 
${Orz_AomiUI_BIN_DIR}/debug/Awesomium_d.dll
${Orz_AomiUI_BIN_DIR}/debug/icudt38.dll
${Orz_AomiUI_BIN_DIR}/debug/avcodec-52.dll
${Orz_AomiUI_BIN_DIR}/debug/avformat-52.dll
${Orz_AomiUI_BIN_DIR}/debug/avutil-50.dll
DESTINATION ./bin/debug )





INSTALL(FILES 
${Orz_AomiUI_BIN_DIR}/release/View_AomiUI.dll 
${Orz_AomiUI_BIN_DIR}/release/Awesomium.dll
${Orz_AomiUI_BIN_DIR}/release/icudt38.dll
${Orz_AomiUI_BIN_DIR}/debug/avcodec-52.dll
${Orz_AomiUI_BIN_DIR}/debug/avformat-52.dll
${Orz_AomiUI_BIN_DIR}/debug/avutil-50.dll
 DESTINATION ./bin/release)

INSTALL(DIRECTORY ${Orz_AomiUI_BIN_DIR}/debug/plugins DESTINATION ./bin/debug PATTERN "CVS" EXCLUDE PATTERN ".svn" )
INSTALL(DIRECTORY ${Orz_AomiUI_BIN_DIR}/release/plugins DESTINATION ./bin/release PATTERN "CVS" EXCLUDE PATTERN ".svn" )