
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable( tap_test.t tap_test.cpp )
target_link_libraries( tap_test.t ${CMAKE_SOURCE_DIR}/src/libsparrow.a)

add_executable( dbix_value_test.t dbix_value_test.cpp )
target_link_libraries( dbix_value_test.t 
    ${CMAKE_SOURCE_DIR}/src/libsparrow.a
    ${CMAKE_SOURCE_DIR}/src/libdbix.a
)

add_executable( dbix_dbx_db.t dbix_dbx_db.cpp )
target_link_libraries( dbix_dbx_db.t
    ${CMAKE_SOURCE_DIR}/src/libsparrow.a
    ${CMAKE_SOURCE_DIR}/src/libdbix.a
)

add_executable( dbix_types_test.t dbix_types_test.cpp )
target_link_libraries( dbix_types_test.t
    ${CMAKE_SOURCE_DIR}/src/libsparrow.a
    ${CMAKE_SOURCE_DIR}/src/libdbix.a
)

