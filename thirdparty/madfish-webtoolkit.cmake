
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

copy_headers(madfish-webtoolkit CoreToolkit CORETOOLKIT_HEADERS)
copy_headers(madfish-webtoolkit WebToolkit WEBTOOLKIT_HEADERS)

set_static_library_name(LIB_CoreToolkit_FILE CoreToolkit)
set_static_library_name(LIB_WebToolkit_FILE WebToolkit)

copy_library(madfish-webtoolkit CoreToolkit ${LIB_CoreToolkit_FILE})
copy_library(madfish-webtoolkit WebToolkit ${LIB_WebToolkit_FILE})

copy_license( madfish-webtoolkit License.txt )

ADD_DEPENDENCIES(
    madfish-webtoolkit
        THIRDPARTY_INCLUDES
        SPARROW_LIBRARIES
)


