
include_directories(${CMAKE_SOURCE_DIR}/include)

SET(SPARROW_LIB libsparrow)

SET(SPARROW_SRCS
    sparrow/tap_suite.cpp
    sparrow/test_run.cpp
)

add_library( ${SPARROW_LIB} ${LIB_MODE} ${SPARROW_SRCS} )