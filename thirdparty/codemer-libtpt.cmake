
ExternalProject_Add(
  libtpt
  PREFIX libtpt
  SVN_REPOSITORY https://svn.github.com/giftnuss/libtpt
  INSTALL_COMMAND ""
)

SET( LIBTPT_HEADERS
    buffer.h
    compat.h
    iparse.h
    object.h
    parse.h
    smartptr.h
    symbols.h
    token.h
    tpt.h
    tptexcept.h
    tpttypes.h
)

copy_headers(libtpt inc/libtpt LIBTPT_HEADERS)

set_static_library_name(LIB_libtpt_FILE tpt)

copy_library(libtpt src/lib ${LIB_libtpt_FILE})

copy_license( libtpt LICENSE )

ADD_DEPENDENCIES(
    libtpt
        THIRDPARTY_INCLUDES
        SPARROW_LIBRARIES
)
