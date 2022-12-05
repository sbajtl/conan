cmake_minimum_required(VERSION 3.2)

project (glyphy)

set (CMAKE_DEBUG_POSTFIX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

find_package(Freetype REQUIRED)
message("FREETYPE_INCLUDE_DIRS" ${FREETYPE_INCLUDE_DIRS})

set (SRCS
  glyphy-arc.cc
  glyphy-arcs.cc
  glyphy-blob.cc
  glyphy-extents.cc
  glyphy-outline.cc
  glyphy-sdf.cc
  glyphy-shaders.cc
)

set (HDRS
  glyphy.h
  glyphy-arc-bezier.hh
  glyphy-arcs-bezier.hh
  glyphy-common-glsl.h
  glyphy-common.hh
  glyphy-freetype.h
  glyphy-geometry.hh
  glyphy-sdf-glsl.h
)

INCLUDE_DIRECTORIES(
   ${FREETYPE_INCLUDE_DIRS}
   ${CMAKE_SOURCE_DIR}
)

ADD_DEFINITIONS(-DPKGDATADIR="Shaders")

add_library(glyphy STATIC ${SRCS} ${HDRS})

set_target_properties (
    glyphy
    PROPERTIES
    POSITION_INDEPENDENT_CODE TRUE
)

set(GLIPHY_LIBS_INSTALL_DIR lib)

install (
    TARGETS glyphy
    ARCHIVE DESTINATION ${GLIPHY_LIBS_INSTALL_DIR}
    COMPONENT devel
)


install(FILES
    ${CMAKE_SOURCE_DIR}/glyphy.h
    ${CMAKE_SOURCE_DIR}/glyphy-freetype.h
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)

