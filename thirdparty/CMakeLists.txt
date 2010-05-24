
INCLUDE(ExternalProject)

SET(THIRDPARTY_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
ADD_CUSTOM_TARGET(
  THIRDPARTY_INCLUDES
  COMMAND ${CMAKE_COMMAND} -E make_directory ${THIRDPARTY_INCLUDES}
)

SET(THIRDPARTY_ACKNOWLEDGEMENT ${CMAKE_CURRENT_SOURCE_DIR}/acknowledgement)
ADD_CUSTOM_TARGET(
  THIRDPARTY_ACKNOWLEDGEMENT
  COMMAND ${CMAKE_COMMAND} -E make_directory ${THIRDPARTY_ACKNOWLEDGEMENT}
)

MACRO(copy_headers project directory listvar)
    ExternalProject_Get_Property(
        ${project} SOURCE_DIR
    )
    ExternalProject_Add_Step(
        ${project} mkdir-${directory}
        COMMAND ${CMAKE_COMMAND} -E make_directory
            ${THIRDPARTY_INCLUDES}/${directory}
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

MACRO(copy_library project directory libname)
    ExternalProject_Get_Property(
        ${project} BINARY_DIR
    )
    ExternalProject_Add_Step(
        ${project} copy-${directory}-library
        COMMAND ${CMAKE_COMMAND} -E copy
                ${BINARY_DIR}/${directory}/${libname}
                ${SPARROW_LIBRARIES}
        DEPENDEES install
    )
ENDMACRO()

MACRO(copy_license project filename)
    STRING( REGEX REPLACE "\s+" "" cleanfilename ${filename} )
    STRING( REGEX REPLACE "/" "_" cleanfilename ${cleanfilename} )
    ExternalProject_Get_Property(
        ${project} SOURCE_DIR
    )
    ExternalProject_Add_Step(
        ${project} copy-${project}-license-${cleanfilename}
        COMMAND ${CMAKE_COMMAND} -E copy
                ${SOURCE_DIR}/${filename}
                ${THIRDPARTY_ACKNOWLEDGEMENT}/${project}-${cleanfilename}
    )
ENDMACRO()

FIND_LIBRARY( WEBTOOLKIT_LIB_FOUND WebToolkit )
FIND_FILE( WEBTOOLKIT_HEADER_FOUND WebToolkit/WebToolkit.h )

IF( NOT WEBTOOLKIT_LIB_FOUND OR NOT WEBTOOLKIT_HEADER_FOUND )
    INCLUDE( madfish-webtoolkit.cmake )
ENDIF()

FIND_LIBRARY( LIBTPT_LIB_FOUND tpt )
FIND_FILE( LIBTPT_HEADER_FOUND libtpt/tpt.h )

IF( NOT LIBTPT_LIB_FOUND OR NOT LIBTPT_HEADER_FOUND )
    INCLUDE( codemer-libtpt.cmake )
ENDIF()

