ORZ_FIND(Orz_OgreNewt View_OgreNewt bin/debug/View_OgreNewt.dll)

INCLUDE_DIRECTORIES(${Orz_OgreNewt_INCLUDE_DIR} ${Orz_OgreNewt_DIR}/dependencies/include)
LINK_DIRECTORIES(${Orz_OgreNewt_LIBRARY_DIR} ${Orz_OgreNewt_DIR}/dependencies/lib)


INSTALL(FILES ${Orz_OgreNewt_BIN_DIR}/debug/View_OgreNewt.dll 
${Orz_OgreNewt_BIN_DIR}/debug/newton.dll
${Orz_OgreNewt_BIN_DIR}/debug/NewtonDebuggerServer.dll
${Orz_OgreNewt_BIN_DIR}/debug/OgreNewt.dll
${Orz_OgreNewt_BIN_DIR}/debug/JointLibrary.dll
DESTINATION ./bin/debug CONFIGURATIONS Debug)


INSTALL(FILES ${Orz_OgreNewt_BIN_DIR}/release/View_OgreNewt.dll 
${Orz_OgreNewt_BIN_DIR}/release/newton.dll
${Orz_OgreNewt_BIN_DIR}/release/NewtonDebuggerServer.dll
${Orz_OgreNewt_BIN_DIR}/release/OgreNewt.dll
${Orz_OgreNewt_BIN_DIR}/release/JointLibrary.dll
DESTINATION ./bin/release CONFIGURATIONS Release)



