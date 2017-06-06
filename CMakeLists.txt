cmake_minimum_required (VERSION 3.0)
project (Breakthrough)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -DBUILD_DOCUMENTATION=ON" )

find_package( PkgConfig REQUIRED)
pkg_check_modules ( PKG REQUIRED libglog cpputest)
include_directories ( ${PKG_INCLUDE_DIRS} )

#build doxygen documentation
find_package(Doxygen)
if(DOXYGEN_FOUND)
 configure_file(Doxyfile ${CMAKE_BINARY_DIR}/Doxyfile)
 add_custom_target(doc ALL
 ${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/Doxyfile
 WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
 COMMENT "Generating API" VERBATIM)
install(DIRECTORY ${CMAKE_BINARY_DIR}/doc/html
DESTINATION share/doc/${CMAKE_PROJECT_NAME})
endif()



add_executable(main_console.out src/main_console.cpp src/Plateau.cpp src/Humain.cpp src/Ia.cpp    )
target_link_libraries( main_console.out ${PKG_LIBRARIES} )
