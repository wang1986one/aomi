ORZ_FIND(SAN_PROJECT SAN_PROJECT media/resources.cfg.in)
UNSET(SAN_PROJECT_BIN_DIR CACHE)
UNSET(SAN_PROJECT_INCLUDE_DIR CACHE)
UNSET(SAN_PROJECT_LIBRARY_DIR CACHE)
FILE(TO_CMAKE_PATH ${SAN_PROJECT_DIR}/media Media_DIR)
FILE(TO_CMAKE_PATH ${SAN_PROJECT_DIR}/media ORZ_MEDIA_DIR)
configure_file(${Media_DIR}/resources.cfg.in ${Media_DIR}/resources.cfg)
configure_file(${Media_DIR}/HunterScene.cfg.in ${Media_DIR}/HunterScene.cfg)
configure_file(${Media_DIR}/WheelScene.cfg.in ${Media_DIR}/WheelScene.cfg)

install(FILES ${Media_DIR}/resources.cfg  DESTINATION ./bin/debug)
install(FILES ${Media_DIR}/resources.cfg  DESTINATION ./bin/release)
install(FILES ${Media_DIR}/HunterScene.cfg  DESTINATION ./bin/debug)
install(FILES ${Media_DIR}/HunterScene.cfg  DESTINATION ./bin/release)

install(FILES ${Media_DIR}/WheelScene.cfg  DESTINATION ./bin/debug)
install(FILES ${Media_DIR}/WheelScene.cfg  DESTINATION ./bin/release)

install(DIRECTORY  ${SAN_PROJECT_DIR}/component/ DESTINATION ./bin/ )