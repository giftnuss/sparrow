
MACRO( set_static_library_name var name )
    IF(MSVC)
        SET(${var} ${name}.lib)
    ELSE()
        SET(${var} lib${name}.a)
    ENDIF()
ENDMACRO()