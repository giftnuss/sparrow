
INCLUDE_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable( ermsample 
    main.cpp 
    src/erm.cpp
)
add_dependencies( ermsample LIB_dbix )
   
target_link_libraries( ermsample 
    ${LIB_dbix_FILENAME}
)
