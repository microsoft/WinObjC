cmake_minimum_required (VERSION 2.6) 
project (VSImporter)

add_subdirectory(third-party/PlistCpp)

set(VERSION_FILE ${CMAKE_SOURCE_DIR}/include/version.h)
if(MSVC)
  set(PLATFORM windows)
  include_directories(include/windows)
else()
  set(PLATFORM dummy)
  set(POSIX_ESCAPE \\)
endif()

file(GLOB platform_SRC "src/${PLATFORM}/*.cpp" "src/${PLATFORM}/*.c")
file(GLOB utils_SRC "src/utils/*.cpp")
file(GLOB vswriter_SRC "src/vswriter/*.cpp")
file(GLOB pbx_SRC "src/PBX/*.cpp")
file(GLOB Xib2Nib_SRC "xib2nib/*.cpp")
file(GLOB WBITelemetry_SRC "WBITelemetry/*.cpp")

FIND_PROGRAM(GIT_EXEC "git")
if(GIT_EXEC)
  add_custom_target(genVersionFile ALL echo ${POSIX_ESCAPE}\#define VERSION_SHA ${POSIX_ESCAPE}\\>"${VERSION_FILE}"&&"${GIT_EXEC}" rev-parse --short HEAD >> "${VERSION_FILE}")
else()
  add_custom_target(genVersionFile ALL echo ${POSIX_ESCAPE}\#define VERSION_SHA unknown > "${VERSION_FILE}")
endif()

add_executable(vsimporter
  src/vsimporter.cpp
  third-party/sole/sole.cpp
  src/query.cpp
  src/SBWorkspace.cpp
  src/SBProject.cpp
  src/SBTarget.cpp
  src/SBNativeTarget.cpp
  src/SBAggregateTarget.cpp
  src/SBBuildPhase.cpp
  src/SBResourcesBuildPhase.cpp
  src/SBFrameworksBuildPhase.cpp
  src/SBSourcesBuildPhase.cpp
  src/SBLog.cpp
  src/xcconfigparser.cpp
  src/settingmodifiers.cpp
  src/XCVariableExpander.cpp
  src/VariableCollectionManager.cpp
  src/VariableCollection.cpp
  src/VariableCollectionHierarchy.cpp
  src/SimpleVariableCollection.cpp
  src/EnvironmentVariableCollection.cpp
  src/BuildSettings.cpp
  src/BuildSettingsInfo.cpp
  ${platform_SRC}
  ${utils_SRC}
  ${vswriter_SRC}
  ${pbx_SRC}
)
add_dependencies(vsimporter genVersionFile)

add_executable(sb-expandvars
  src/starexpand.cpp
  src/SBLog.cpp
  src/utils/wildcardmatch.cpp
  src/utils/tokenizer.cpp
  src/utils/sbassert.cpp
  src/utils/fileutils.cpp
  src/utils/stringutils.cpp
  src/utils/miscutils.cpp
  src/xcconfigparser.cpp
  src/XCVariableExpander.cpp
  src/settingmodifiers.cpp
  src/VariableCollection.cpp
  src/SimpleVariableCollection.cpp
  src/EnvironmentVariableCollection.cpp
  src/VariableCollectionHierarchy.cpp
  ${platform_SRC}
)
add_dependencies(sb-expandvars genVersionFile)

add_executable(hmapmaker
  src/sb-hmapmaker.cpp
  src/utils/sbassert.cpp
  src/utils/hmapmaker.cpp
  src/utils/wildcardmatch.cpp
  src/utils/tokenizer.cpp
  src/utils/fileutils.cpp
  src/utils/stringutils.cpp
  src/utils/miscutils.cpp
  src/SBLog.cpp
  ${platform_SRC}
)

add_executable(Xib2Nib
  ${Xib2Nib_SRC}
)

add_library(WBITelemetry
  ${WBITelemetry_SRC}
)


include_directories(${CMAKE_SOURCE_DIR} include include/utils include/vswriter include/PBX third-party third-party/PlistCpp/src third-party/PlistCpp/third-party third-party/PlistCpp/third-party/pugixml/src)
target_link_libraries(vsimporter PlistCpp pugixml NSPlist)
target_link_libraries(sb-expandvars PlistCpp pugixml NSPlist)
target_link_libraries(Xib2Nib PlistCpp pugixml NSPlist WinHttp WBITelemetry ..\\..\\..\\Frameworks\\AppInsights\\Projects\\AppInsights_Win32\\Debug\\AppInsights_Win32.lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_CXX_FLAGS} -std=c++11")
