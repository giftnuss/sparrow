
INCLUDE_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable( ermsample 
    main.cpp 
    src/erm.cpp
)
target_link_libraries( ermsample 
    ${CMAKE_SOURCE_DIR}/src/libsparrow.a
    ${CMAKE_SOURCE_DIR}/src/libdbix.a
)
