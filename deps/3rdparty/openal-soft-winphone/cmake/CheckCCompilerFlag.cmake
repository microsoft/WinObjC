# - Check if the C source code provided in the SOURCE argument compiles.
# CHECK_C_SOURCE_COMPILES(SOURCE VAR)
#
#  FLAG   - compiler flag to check
#  VAR    - variable to store whether the source code compiled
#
# The following variables may be set before calling this macro to
# modify the way the check is run:
#
#  CMAKE_REQUIRED_FLAGS = string of compile command line flags
#  CMAKE_REQUIRED_DEFINITIONS = list of macros to define (-DFOO=bar)
#  CMAKE_REQUIRED_INCLUDES = list of include directories
#  CMAKE_REQUIRED_LIBRARIES = list of libraries to link

MACRO(CHECK_C_COMPILER_FLAG FLAG VAR)
  IF("${VAR}" MATCHES "^${VAR}$")
    SET(MACRO_CHECK_FUNCTION_DEFINITIONS
      "${FLAG} ${CMAKE_REQUIRED_FLAGS}")
    IF(CMAKE_REQUIRED_LIBRARIES)
      SET(CHECK_C_COMPILER_FLAG_ADD_LIBRARIES
        "-DLINK_LIBRARIES:STRING=${CMAKE_REQUIRED_LIBRARIES}")
    ELSE(CMAKE_REQUIRED_LIBRARIES)
      SET(CHECK_C_COMPILER_FLAG_ADD_LIBRARIES)
    ENDIF(CMAKE_REQUIRED_LIBRARIES)
    IF(CMAKE_REQUIRED_INCLUDES)
      SET(CHECK_C_COMPILER_FLAG_ADD_INCLUDES
        "-DINCLUDE_DIRECTORIES:STRING=${CMAKE_REQUIRED_INCLUDES}")
    ELSE(CMAKE_REQUIRED_INCLUDES)
      SET(CHECK_C_COMPILER_FLAG_ADD_INCLUDES)
    ENDIF(CMAKE_REQUIRED_INCLUDES)
    FILE(WRITE "${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/src.c"
      "int main() {return 0;}\n")

    MESSAGE(STATUS "Checking if C compiler supports ${FLAG}")
    TRY_COMPILE(${VAR}
      ${CMAKE_BINARY_DIR}
      ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/src.c
      COMPILE_DEFINITIONS ${CMAKE_REQUIRED_DEFINITIONS}
      CMAKE_FLAGS -DCOMPILE_DEFINITIONS:STRING=${MACRO_CHECK_FUNCTION_DEFINITIONS}
      "${CHECK_C_COMPILER_FLAG_ADD_LIBRARIES}"
      "${CHECK_C_COMPILER_FLAG_ADD_INCLUDES}"
      OUTPUT_VARIABLE OUTPUT)
    IF(${VAR})
      SET(${VAR} 1 CACHE INTERNAL "Test ${VAR}")
      MESSAGE(STATUS "Checking if C compiler supports ${FLAG} - Success")
      FILE(APPEND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeOutput.log
        "Performing C SOURCE FILE Test ${VAR} succeded with the following output:\n"
        "${OUTPUT}\n"
        "Source file was:\n${SOURCE}\n")
    ELSE(${VAR})
      MESSAGE(STATUS "Checking if C compiler supports ${FLAG} - Failed")
      SET(${VAR} "" CACHE INTERNAL "Test ${VAR}")
      FILE(APPEND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
        "Performing C SOURCE FILE Test ${VAR} failed with the following output:\n"
        "${OUTPUT}\n"
        "Source file was:\n${SOURCE}\n")
    ENDIF(${VAR})
  ENDIF("${VAR}" MATCHES "^${VAR}$")
ENDMACRO(CHECK_C_COMPILER_FLAG)
