project (triangle)

cmake_minimum_required(VERSION 3.2)

add_definitions(-DNO_TIMER -DANSI_DECLARATORS -DSINGLE -DREDUCED)

set (SRCS triangle.c triangle.h triexit.cpp)
SET_SOURCE_FILES_PROPERTIES(${SRCS} PROPERTIES LANGUAGE CXX )

add_library(triangle STATIC ${SRCS})
set_target_properties (
    triangle
    PROPERTIES
    COMPILE_FLAGS -DTRILIBRARY -DNO_TIMER -DANSI_DECLARATORS -DSINGLE -DREDUCED
    POSITION_INDEPENDENT_CODE  TRUE
)

if (NOT BUILDING_PACKAGE)
        set(TRI_LIBS_INSTALL_DIR lib/${OUTPUT_DIR})
else()
        set(TRI_LIBS_INSTALL_DIR lib)
endif()


install (
        TARGETS triangle
        ARCHIVE DESTINATION ${TRI_LIBS_INSTALL_DIR}
        COMPONENT devel
)


  install(FILES
    ${CMAKE_SOURCE_DIR}/triangle.h
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  )

