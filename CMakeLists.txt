
project("sparrow" CXX)

cmake_minimum_required(VERSION 2.8)

SET(SPARROW_TAP_TEST sparrow_test)

SET(CMAKE_COLOR_MAKEFILE ON)

# Path to additional CMake modules
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# Loading my first cmake module
INCLUDE(candid)

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

SET(SPARROW_LIBRARIES ${CMAKE_SOURCE_DIR}/lib)
ADD_CUSTOM_TARGET(
    SPARROW_LIBRARIES
    COMMAND ${CMAKE_COMMAND} -E make_directory ${SPARROW_LIBRARIES}
)

MACRO(set_library_name name)
    set_static_library_name(LIB_${name}_FILE ${name})
    SET(LIB_${name}_FILENAME  ${SPARROW_LIBRARIES}/${LIB_${name}_FILE})
ENDMACRO()

MACRO(copy_sparrow_library name)
    set_library_name(${name})
    ADD_CUSTOM_TARGET(
        LIB_${name}
        COMMAND ${CMAKE_COMMAND} -E copy 
            ${CMAKE_BINARY_DIR}/src/${LIB_${name}_FILE}
            ${SPARROW_LIBRARIES}
        DEPENDS ${SPARROW_LIBRARIES} ${name}
    )
    ADD_DEPENDENCIES(
        LIB_${name} SPARROW_LIBRARIES
    )
ENDMACRO()

copy_sparrow_library(sparrow)
copy_sparrow_library(dbix)

ADD_SUBDIRECTORY(src)

# IF(WITH_TESTS)
    MESSAGE(STATUS "Enable sparrow tap tests to build - done")
    ENABLE_TESTING()
    
    ADD_SUBDIRECTORY(t)
# ENDIF()

ADD_SUBDIRECTORY(ex)

ADD_CUSTOM_TARGET(love
    COMMAND ${CMAKE_COMMAND} -E echo "not war!"
)

ADD_SUBDIRECTORY(thirdparty)
