ORZ_FIND(OgreVedio OgreVedio bin/debug/Plugin_OgreVideo_d.dll)
ORZ_FIND(TheoraVideo TheoraVideo include/TheoraAsync.h)
INCLUDE_DIRECTORIES(${OgreVedio_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${TheoraVideo_INCLUDE_DIR})
LINK_DIRECTORIES(${OgreVedio_LIBRARY_DIR})
INSTALL(FILES 
${OgreVedio_BIN_DIR}/debug/Plugin_OgreVideo_d.dll 
DESTINATION 
./bin/debug 
CONFIGURATIONS Debug)

INSTALL(FILES 
${OgreVedio_BIN_DIR}/release/Plugin_OgreVideo.dll
 DESTINATION ./bin/release 
 CONFIGURATIONS Release)

