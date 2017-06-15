cmake_minimum_required (VERSION 3.0)
project (Breakthrough)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -DBUILD_DOCUMENTATION=ON -ansi -pedantic -g -std=c++11 " )

find_package( PkgConfig REQUIRED)
pkg_check_modules ( PKG REQUIRED libglog cpputest)
include_directories ( ${PKG_INCLUDE_DIRS} )

find_package(SFML REQUIRED)

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



add_executable(main_test_fenetre.out src/main_test_fenetre.cpp src/Plateau.cpp src/Coups.cpp src/Humain.cpp src/Fenetre.cpp src/AlphaBeta.cpp src/Ia.cpp)
target_link_libraries( main_test_fenetre.out ${PKG_LIBRARIES} ${SFML_LIBRARY})
