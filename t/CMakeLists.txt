
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable( tap_test.t tap_test.cpp )
target_link_libraries( tap_test.t ${CMAKE_SOURCE_DIR}/src/libsparrow.a)