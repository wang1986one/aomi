ORZ_FIND(Ajax ajax html/panel.html)



INSTALL(DIRECTORY ${Ajax_DIR}/html/ DESTINATION ./bin/debug/html/ PATTERN "CVS" EXCLUDE PATTERN ".svn"  EXCLUDE)
INSTALL(DIRECTORY ${Ajax_DIR}/html/ DESTINATION ./bin/release/html/ PATTERN "CVS" EXCLUDE PATTERN ".svn" EXCLUDE)