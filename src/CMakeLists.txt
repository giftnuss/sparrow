
include_directories(${CMAKE_SOURCE_DIR}/include)

SET(SPARROW_LIB sparrow)

SET(SPARROW_SRCS
    sparrow/tap_suite.cpp
    sparrow/test_run.cpp
    sparrow/tap_base.cpp
    sparrow/tap_more_1.cpp
)

add_library( ${SPARROW_LIB} ${LIB_MODE} ${SPARROW_SRCS} )

SET(DBIX_LIB dbix)

SET(DBIX_SRCS
   dbix/column.cpp
   dbix/record.cpp
   dbix/table.cpp
   dbix/value.cpp
   dbix/types.cpp
   dbix/types/type.cpp
   dbix/types/text.cpp
)

add_library( ${DBIX_LIB} ${LIB_MODE} ${DBIX_SRCS} )

install(
   TARGETS ${SPARROW_LIB}
   DESTINATION lib
)