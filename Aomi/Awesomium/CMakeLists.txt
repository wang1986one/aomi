
ORZ_PRE_BUILD_EVENT(Awesomium)


IF(CMAKE_C_COMPILER MATCHES cl)
   IF(NOT WITH_SHARED_LIBS)
     IF(CMAKE_GENERATOR STREQUAL "Visual Studio 6")
       SET(CMAKE_C_FLAGS "/nologo /W3 /GX /Gy /YX")
       SET(CMAKE_C_FLAGS_DEBUG "/MTd /Z7 /Od")
       SET(CMAKE_C_FLAGS_RELEASE "/MT /O2")
       SET(CMAKE_C_FLAGS_MINSIZEREL "/MT /O2")
       SET(CMAKE_C_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od")
     ENDIF(CMAKE_GENERATOR STREQUAL "Visual Studio 6")
     IF(CMAKE_GENERATOR STREQUAL "Visual Studio 7" OR CMAKE_GENERATOR 
STREQUAL "Visual Studio 7 .NET 2003")
       SET(CMAKE_C_FLAGS "/nologo /W3 /Gy")
       SET(CMAKE_C_FLAGS_DEBUG "/MTd /Z7 /Od")
       SET(CMAKE_C_FLAGS_RELEASE "/MT /O2")
       SET(CMAKE_C_FLAGS_MINSIZEREL "/MT /O2")
       SET(CMAKE_C_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od")
     ENDIF(CMAKE_GENERATOR STREQUAL "Visual Studio 7" OR CMAKE_GENERATOR 
STREQUAL "Visual Studio 7 .NET 2003")
     IF(CMAKE_GENERATOR STREQUAL "Visual Studio 8 2005")
       SET(CMAKE_C_FLAGS "/nologo /W3 /Gy")
       SET(CMAKE_C_FLAGS_DEBUG "/MTd /Z7 /Od")
       SET(CMAKE_C_FLAGS_RELEASE "/MT /O2")
       SET(CMAKE_C_FLAGS_MINSIZEREL "/MT /O2")
       SET(CMAKE_C_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od")
     ENDIF(CMAKE_GENERATOR STREQUAL "Visual Studio 8 2005")
   ENDIF(NOT WITH_SHARED_LIBS)
ENDIF(CMAKE_C_COMPILER MATCHES cl)
# settings for Microsoft Visual C++
IF(CMAKE_CXX_COMPILER MATCHES cl)
   IF(NOT WITH_SHARED_LIBS)
     IF(CMAKE_GENERATOR STREQUAL "Visual Studio 6")
       SET(CMAKE_CXX_FLAGS "/nologo /W3 /GX /Gy /YX")
       SET(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od")
       SET(CMAKE_CXX_FLAGS_RELEASE "/MT /O2")
       SET(CMAKE_CXX_FLAGS_MINSIZEREL "/MT /O2")
       SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od")
     ENDIF(CMAKE_GENERATOR STREQUAL "Visual Studio 6")
     IF(CMAKE_GENERATOR STREQUAL "Visual Studio 7" OR CMAKE_GENERATOR 
STREQUAL "Visual Studio 7 .NET 2003")
       SET(CMAKE_CXX_FLAGS "/nologo /W3 /Gy")
       SET(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od")
       SET(CMAKE_CXX_FLAGS_RELEASE "/MT /O2")
       SET(CMAKE_CXX_FLAGS_MINSIZEREL "/MT /O2")
       SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od")
     ENDIF(CMAKE_GENERATOR STREQUAL "Visual Studio 7" OR CMAKE_GENERATOR 
STREQUAL "Visual Studio 7 .NET 2003")
     IF(CMAKE_GENERATOR STREQUAL "Visual Studio 8 2005")
       SET(CMAKE_CXX_FLAGS "/nologo /W3 /Gy")
       SET(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od")
       SET(CMAKE_CXX_FLAGS_RELEASE "/MT /O2")
       SET(CMAKE_CXX_FLAGS_MINSIZEREL "/MT /O2")
       SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od")
     ENDIF(CMAKE_GENERATOR STREQUAL "Visual Studio 8 2005")
   ENDIF(NOT WITH_SHARED_LIBS)
ENDIF(CMAKE_CXX_COMPILER MATCHES cl)



ADD_DEFINITIONS( -D${LIB_NAME_TOUPPER}_EXPORTS -D_USRDLL
-DWIN32
-D_WIN32
-DUNICODE
-DOSM_NONCLIENT_BUILD
-D_WINDOWS
-DNOMINMAX
-DWEBKIT_USING_SKIA
-DU_HAVE_INT32_T=1
-DU_HAVE_UINT32_T=1
)
 

set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG /EHsc")
LINK_DIRECTORIES(${chromium_src}/chrome/$(OutDir)/lib)

INCLUDE_DIRECTORIES(
"include"
${chromium_src}/webkit/api/public
${chromium_src}/
${chromium_src}/skia/config/win
${chromium_src}/skia/config
${chromium_src}/skia/include/corecg
${chromium_src}/skia/include
${chromium_src}/third_party/skia/include/core
${chromium_src}/third_party/WebKit/JavaScriptCore
${chromium_src}/third_party/npapi
${chromium_src}/third_party/WebKit/WebKit/chromium/public
${chromium_src}/third_party/WebKit/WebKit/chromium/public/win
${chromium_src}/third_party/WebKit/WebCore/platform/text
${chromium_src}/third_party/icu38/public/common
)






ORZ_SET_PROJECT_FILES("include"  include/ .h)
ORZ_SET_PROJECT_FILES("include"  src/ .h)
ORZ_SET_PROJECT_FILES("src" src/ .cpp)
   
ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})


TARGET_LINK_LIBRARIES(${LIB_NAME} 
base.lib
base_gfx.lib
breakpad_handler.lib
googleurl.lib
net.lib
skia.lib
gtest.lib
libbzip2.lib
icui18n.lib
icuuc.lib
libjpeg.lib
libpng.lib
libxml2.lib
libxslt.lib
modp_b64.lib
zlib.lib
pcre.lib
activex_shim.lib
WTF.lib
v8_snapshot.lib
v8_base.lib
WebCore.lib
default_plugin.lib
Glue.lib
sdch.lib
sqlite3.lib
comctl32.lib
rpcrt4.lib
shlwapi.lib
winmm.lib
Usp10.lib
Psapi.lib
msimg32.lib
version.lib
Wininet.lib
WebKit.lib
urlmon.lib
DbgHelp.lib
Gdi32.lib
avutil-50.lib
avcodec-52.lib
avformat-52.lib
media.lib
)

ORZ_POST_BUILD_EVENT()