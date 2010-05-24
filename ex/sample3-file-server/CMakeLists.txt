
include_directories(
    ${THIRDPARTY_INCLUDES}/WebToolkit
    ${THIRDPARTY_INCLUDES}/CoreToolkit
)

link_directories( 
    ${SPARROW_LIBRARIES}
)

file(GLOB SOURCES *.cpp *.h)

add_executable(FileServer ${SOURCES})

target_link_libraries(FileServer 
    WebToolkit
    CoreToolkit
    pthread
)

add_dependencies(FileServer
    madfish-webtoolkit
    libtpt
)

