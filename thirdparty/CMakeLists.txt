
INCLUDE(ExternalProject)

SET(THIRDPARTY_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
ADD_CUSTOM_TARGET(
  THIRDPARTY_INCLUDES
  COMMAND ${CMAKE_COMMAND} -E make_directory ${THIRDPARTY_INCLUDES}
)

ExternalProject_Add(
  madfish-webtoolkit
  PREFIX webtoolkit
  SVN_REPOSITORY http://madfish-webtoolkit.googlecode.com/svn/trunk
  INSTALL_COMMAND ""
)

SET( CORETOOLKIT_HEADERS
    File.h
    FileUtils.h
    Logger.h
    OSUtils.h
    Socket.h
    Stream.h
    Thread.h
    Util.h
)

SET( WEBTOOLKIT_HEADERS
    Client.h
    Http.h
    HttpHelpers.h
    Server.h
    WebToolkit.h
)

ExternalProject_Get_Property(madfish-webtoolkit SOURCE_DIR)
ExternalProject_Get_Property(madfish-webtoolkit BINARY_DIR)

MACRO(copy_headers project directory listvar)
    ExternalProject_Add_Step(
        ${project} mkdir-${directory}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${THIRDPARTY_INCLUDES}/${directory}
        DEPENDEES install
    )
    FOREACH(header ${${listvar}}) 
        ExternalProject_Add_Step(
            ${project} copy-${directory}-${header}
            COMMAND ${CMAKE_COMMAND} -E copy
                ${SOURCE_DIR}/${directory}/${header}
                ${THIRDPARTY_INCLUDES}/${directory}/
            DEPENDEES mkdir-${directory}
        )
    ENDFOREACH()
ENDMACRO()

copy_headers(madfish-webtoolkit CoreToolkit CORETOOLKIT_HEADERS)
copy_headers(madfish-webtoolkit WebToolkit WEBTOOLKIT_HEADERS)

set_static_library_name(LIB_CoreToolkit_FILE CoreToolkit)
set_static_library_name(LIB_WebToolkit_FILE WebToolkit)

MACRO(copy_library project directory libname)
    ExternalProject_Add_Step(
        ${project} copy-${directory}-library
        COMMAND ${CMAKE_COMMAND} -E copy
                ${BINARY_DIR}/${directory}/${libname}
                ${SPARROW_LIBRARIES}
        DEPENDEES install
    )
ENDMACRO()

copy_library(madfish-webtoolkit CoreToolkit ${LIB_CoreToolkit_FILE})
copy_library(madfish-webtoolkit WebToolkit ${LIB_WebToolkit_FILE})

ADD_DEPENDENCIES(
    madfish-webtoolkit
        THIRDPARTY_INCLUDES
        SPARROW_LIBRARIES
)


