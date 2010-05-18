
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

ADD_DEPENDENCIES(
  madfish-webtoolkit THIRDPARTY_INCLUDES
)


