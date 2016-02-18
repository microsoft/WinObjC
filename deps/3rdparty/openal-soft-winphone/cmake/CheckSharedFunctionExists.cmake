# - Check if a symbol exists as a function, variable, or macro
# CHECK_SYMBOL_EXISTS(<symbol> <files> <variable>)
#
# Check that the <symbol> is available after including given header
# <files> and store the result in a <variable>.  Specify the list
# of files in one argument as a semicolon-separated list.
#
# If the header files define the symbol as a macro it is considered
# available and assumed to work.  If the header files declare the
# symbol as a function or variable then the symbol must also be
# available for linking.  If the symbol is a type or enum value
# it will not be recognized (consider using CheckTypeSize or
# CheckCSourceCompiles).
#
# The following variables may be set before calling this macro to
# modify the way the check is run:
#
#  CMAKE_REQUIRED_FLAGS = string of compile command line flags
#  CMAKE_REQUIRED_DEFINITIONS = list of macros to define (-DFOO=bar)
#  CMAKE_REQUIRED_INCLUDES = list of include directories
#  CMAKE_REQUIRED_LIBRARIES = list of libraries to link

#=============================================================================
# Copyright 2003-2011 Kitware, Inc.
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)

MACRO(CHECK_SHARED_FUNCTION_EXISTS SYMBOL FILES LIBRARY LOCATION VARIABLE)
  IF("${VARIABLE}" MATCHES "^${VARIABLE}$")
    SET(CMAKE_CONFIGURABLE_FILE_CONTENT "/* */\n")
    SET(MACRO_CHECK_SYMBOL_EXISTS_FLAGS ${CMAKE_REQUIRED_FLAGS})
    IF(CMAKE_REQUIRED_LIBRARIES)
      SET(CHECK_SYMBOL_EXISTS_LIBS 
        "-DLINK_LIBRARIES:STRING=${CMAKE_REQUIRED_LIBRARIES};${LIBRARY}")
    ELSE(CMAKE_REQUIRED_LIBRARIES)
      SET(CHECK_SYMBOL_EXISTS_LIBS
        "-DLINK_LIBRARIES:STRING=${LIBRARY}")
    ENDIF(CMAKE_REQUIRED_LIBRARIES)
    IF(CMAKE_REQUIRED_INCLUDES)
      SET(CMAKE_SYMBOL_EXISTS_INCLUDES
        "-DINCLUDE_DIRECTORIES:STRING=${CMAKE_REQUIRED_INCLUDES}")
    ELSE(CMAKE_REQUIRED_INCLUDES)
      SET(CMAKE_SYMBOL_EXISTS_INCLUDES)
    ENDIF(CMAKE_REQUIRED_INCLUDES)
    FOREACH(FILE ${FILES})
      SET(CMAKE_CONFIGURABLE_FILE_CONTENT
        "${CMAKE_CONFIGURABLE_FILE_CONTENT}#include <${FILE}>\n")
    ENDFOREACH(FILE)
    SET(CMAKE_CONFIGURABLE_FILE_CONTENT
      "${CMAKE_CONFIGURABLE_FILE_CONTENT}\nvoid cmakeRequireSymbol(int dummy,...){(void)dummy;}\nint main()\n{\n  cmakeRequireSymbol(0,&${SYMBOL});\n  return 0;\n}\n")

    CONFIGURE_FILE("${CMAKE_ROOT}/Modules/CMakeConfigurableFile.in"
      "${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/CheckSymbolExists.c" @ONLY)

    MESSAGE(STATUS "Looking for ${SYMBOL} in ${LIBRARY}")
    TRY_COMPILE(${VARIABLE}
      ${CMAKE_BINARY_DIR}
      ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/CheckSymbolExists.c
      COMPILE_DEFINITIONS ${CMAKE_REQUIRED_DEFINITIONS}
      CMAKE_FLAGS 
      -DCOMPILE_DEFINITIONS:STRING=${MACRO_CHECK_SYMBOL_EXISTS_FLAGS}
      -DLINK_DIRECTORIES:STRING=${LOCATION}
      "${CHECK_SYMBOL_EXISTS_LIBS}"
      "${CMAKE_SYMBOL_EXISTS_INCLUDES}"
      OUTPUT_VARIABLE OUTPUT)
    IF(${VARIABLE})
      MESSAGE(STATUS "Looking for ${SYMBOL} in ${LIBRARY} - found")
      SET(${VARIABLE} 1 CACHE INTERNAL "Have symbol ${SYMBOL} in ${LIBRARY}")
      FILE(APPEND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeOutput.log 
        "Determining if the ${SYMBOL} "
        "exist in ${LIBRARY} passed with the following output:\n"
        "${OUTPUT}\nFile ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/CheckSymbolExists.c:\n"
        "${CMAKE_CONFIGURABLE_FILE_CONTENT}\n")
    ELSE(${VARIABLE})
      MESSAGE(STATUS "Looking for ${SYMBOL} in ${LIBRARY} - not found.")
      SET(${VARIABLE} "" CACHE INTERNAL "Have symbol ${SYMBOL} in ${LIBRARY}")
      FILE(APPEND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log 
        "Determining if the ${SYMBOL} "
        "exist in ${LIBRARY} failed with the following output:\n"
        "${OUTPUT}\nFile ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/CheckSymbolExists.c:\n"
        "${CMAKE_CONFIGURABLE_FILE_CONTENT}\n")
    ENDIF(${VARIABLE})
  ENDIF("${VARIABLE}" MATCHES "^${VARIABLE}$")
ENDMACRO(CHECK_SHARED_FUNCTION_EXISTS)
