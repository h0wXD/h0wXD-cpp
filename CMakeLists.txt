
CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)

PROJECT(h0wXD CXX)

OPTION(ENABLE_SSE "Allow SSE instructions (x86)" on)
SET(PATH_LEST "Lib/lest-1.22.0" CACHE STRING "Path to lest")

INCLUDE(CheckCXXCompilerFlag)

IF(CMAKE_COMPILER_IS_GNUCC)
    SET(COMPILER_GCC 1)
    SET(ENABLE_CXX14 "-std=c++14")
    SET(ENABLE_CXX11 "-std=c++11")
    CHECK_CXX_COMPILER_FLAG(ENABLE_CXX14 COMPILER_SUPPORTS_CXX14)
    CHECK_CXX_COMPILER_FLAG(ENABLE_CXX11 COMPILER_SUPPORTS_CXX11)
    IF(COMPILER_SUPPORTS_CXX14)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ENABLE_CXX14}")
    ELSEIF(COMPILER_SUPPORTS_CXX11)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ENABLE_CXX11}")
    ELSE()
        MESSAGE(STATUS "Could not find C++11 or higher support for compiler ${CMAKE_CXX_COMPILER}")
    ENDIF()
ENDIF(CMAKE_COMPILER_IS_GNUCC)

IF(MSVC)
    SET(COMPILER_MSVC 1)
    SET(EXECUTABLE_TYPE "WIN32")
ENDIF(MSVC)

IF(NOT CMAKE_SYSTEM_PROCESSOR AND CMAKE_SYSTEM_NAME STREQUAL "Windows")
    SET(CMAKE_SYSTEM_PROCESSOR "i686")
ENDIF()

IF(CMAKE_SYSTEM_PROCESSOR MATCHES "i.86" OR CMAKE_SYSTEM_PROCESSOR MATCHES "x86")
    SET(ARCH_X86 1)
ENDIF()

IF(ARCH_X86 AND ENABLE_SSE)
    IF(COMPILER_GCC)
        MESSAGE(STATUS "Enabling SSE instructions")
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -msse")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse")
    ENDIF(COMPILER_GCC)
    IF(COMPILER_MSVC)
        MESSAGE(STATUS "Allowing MSVC to use SSE instructions")
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /arch:SSE")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:SSE")
    ENDIF(COMPILER_MSVC)
ENDIF()

SET(BUILD_DIRECTORY "${CMAKE_SOURCE_DIR}/Build")
SET(OUTPUT_DIRECTORY "${BUILD_DIRECTORY}/Output")
SET(BINARY_DIRECTORY "${OUTPUT_DIRECTORY}/Bin")
SET(LIBRARY_DIRECTORY "${OUTPUT_DIRECTORY}/Lib")

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIRECTORY})
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIBRARY_DIRECTORY})

FOREACH(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    STRING(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BINARY_DIRECTORY})
    SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${LIBRARY_DIRECTORY})
    SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${LIBRARY_DIRECTORY})
ENDFOREACH(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)

SET(PROJECT_NAMES "h0wXD")

FOREACH(PROJECT_NAME ${PROJECT_NAMES})

    SET(OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/Output/${PROJECT_NAME}")
    ADD_SUBDIRECTORY("${CMAKE_SOURCE_DIR}/Source/${PROJECT_NAME}" ${OUTPUT_DIRECTORY})

ENDFOREACH(PROJECT_NAME ${PROJECT_NAMES})

SET(TEST_PROJECT_NAMES "h0wXD.Test")

FOREACH(PROJECT_NAME ${TEST_PROJECT_NAMES})

    SET(PATH_LEST_INCLUDE "${BUILD_DIRECTORY}/../${PATH_LEST}")
    SET(OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/Output/Test/${PROJECT_NAME}")
    ADD_SUBDIRECTORY("${CMAKE_SOURCE_DIR}/Test/${PROJECT_NAME}" ${OUTPUT_DIRECTORY})

ENDFOREACH(PROJECT_NAME ${TEST_PROJECT_NAMES})
