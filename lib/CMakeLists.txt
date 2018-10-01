cmake_minimum_required( VERSION 2.8.4 )
project( PageXML )
set( lib_NAME PageXML )
find_package( PkgConfig )
pkg_check_modules( opencv REQUIRED opencv>=2.4.9 )
pkg_check_modules( libxslt REQUIRED libxslt )
pkg_check_modules( gdal REQUIRED gdal )

add_definitions( -D__PAGEXML_CVIMG__ )
add_definitions( -D__PAGEXML_OGR__ )

file( GLOB lib_SRC "*.cc" )
add_library( ${lib_NAME} SHARED ${lib_NAME} )
set_property( TARGET ${lib_NAME} PROPERTY CXX_STANDARD 11 )

string( REPLACE ";" " " CFLAGS_STR "-Wall -W ${gdal_CFLAGS} ${opencv_CFLAGS} ${libxslt_CFLAGS}" )
set_target_properties( ${lib_NAME} PROPERTIES COMPILE_FLAGS "${CFLAGS_STR}" )

target_link_libraries( ${lib_NAME} ${gdal_LDFLAGS} ${opencv_LDFLAGS} ${libxslt_LDFLAGS} )

install( TARGETS ${lib_NAME} DESTINATION lib )
