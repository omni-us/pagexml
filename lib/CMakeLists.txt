cmake_minimum_required( VERSION 2.8.4 )
project( PageXML )
set( lib_NAME PageXML )
#list( APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules" )
#include( FindPackageHandleStandardArgs )
#find_package( Ghostscript )
find_package( PkgConfig )
pkg_check_modules( opencv REQUIRED opencv>=2.4.9 )
pkg_check_modules( libxslt REQUIRED libxslt )
pkg_check_modules( gdal REQUIRED gdal )
pkg_check_modules( Magick REQUIRED Magick++>=6.8 )

add_definitions( -D__PAGEXML_OGR__ )
add_definitions( -D__PAGEXML_MAGICK__ )
add_definitions( -D__PAGEXML_IMG_CV__ )
#add_definitions( -D__PAGEXML_IMG_MAGICK__ )
#add_definitions( -D__PAGEXML_GS__ )

#set( CMAKE_REQUIRED_INCLUDES "${CMAKE_REQUIRED_INCLUDES};${GHOSTSCRIPT_INCLUDES};${opencv_INCLUDE_DIRS}" )

file( GLOB lib_SRC "*.cc" )
add_library( ${lib_NAME} SHARED ${lib_SRC} )
set_property( TARGET ${lib_NAME} PROPERTY CXX_STANDARD 11 )

string( REPLACE ";" " " CFLAGS_STR "-Wall -W ${gdal_CFLAGS} ${opencv_CFLAGS} ${libxslt_CFLAGS} ${Magick_CFLAGS}" )
set_target_properties( ${lib_NAME} PROPERTIES COMPILE_FLAGS "${CFLAGS_STR}" )

include_directories( SYSTEM ${Magick_INCLUDEDIR} ) # To suppress system header warnings

target_link_libraries( ${lib_NAME} ${gdal_LDFLAGS} ${GHOSTSCRIPT_LIBRARIES} ${opencv_LDFLAGS} ${libxslt_LDFLAGS} ${Magick_LDFLAGS} )

install( TARGETS ${lib_NAME} DESTINATION lib )
