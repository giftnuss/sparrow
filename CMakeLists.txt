
project("sparrow" CXX)

cmake_minimum_required(VERSION 2.6)

SET(SPARROW_TAP_TEST sparrow_test)

SET(CMAKE_COLOR_MAKEFILE ON)

# Path to additional CMake modules
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

SET(BUILD_PEDANTIC TRUE CACHE BOOL
    "Choose compilation in pedantic or relaxed mode")

IF(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -Wno-long-long -ansi")
    IF(BUILD_PEDANTIC)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
    ENDIF()
    IF (CMAKE_COMPILER_IS_GNUCXX)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
    ENDIF()
ENDIF()

set( LIB_MODE STATIC )

ADD_SUBDIRECTORY(src)



IF(WITH_TESTS)
    MESSAGE(STATUS "Enable sparrow tap tests to build - done")
    ENABLE_TESTING()
    
    ADD_SUBDIRECTORY(t)
ENDIF()

