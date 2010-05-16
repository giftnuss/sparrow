
INCLUDE(ExternalProject)

ExternalProject_Add(
  madfish-webtoolkit
  PREFIX webtoolkit
  SVN_REPOSITORY http://madfish-webtoolkit.googlecode.com/svn/trunk
  INSTALL_COMMAND ""
#  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

