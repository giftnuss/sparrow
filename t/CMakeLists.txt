
include_directories(${CMAKE_SOURCE_DIR}/include)

SET(TEST_FILES
  tap_test.t
  dbix_value_test.t
  dbix_types_test.t
  dbix_table_test.t
)

add_executable( tap_test.t tap_test.cpp )
target_link_libraries( tap_test.t 
    ${LIB_sparrow_FILENAME}
)

macro(add_dbix_test filename)
    add_executable( ${filename}.t ${filename}.cpp )
    add_dependencies( ${filename}.t LIB_sparrow LIB_dbix )
    target_link_libraries( ${filename}.t
        ${LIB_sparrow_FILENAME}
        ${LIB_dbix_FILENAME}
    )
endmacro()

add_dbix_test(dbix_value_test)
add_dbix_test(dbix_types_test)
add_dbix_test(dbix_table_test)

#add_executable( dbix_dbx_db.t dbix_dbx_db.cpp )
#target_link_libraries( dbix_dbx_db.t
#    ${CMAKE_SOURCE_DIR}/src/libsparrow.a
#    ${CMAKE_SOURCE_DIR}/src/libdbix.a
#)

FOREACH(testcase ${TEST_FILES})
    ADD_TEST(${testcase} ${testcase})
ENDFOREACH(testcase)