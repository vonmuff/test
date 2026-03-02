# cmake_minimum_required(VERSION 3.23)

# add_library(GreeterLib)

# target_sources(GreeterLib
# PRIVATE
#     source/GreeterLib.cpp
# PUBLIC
#     FILE_SET public_headers
#     TYPE HEADERS
#     BASE_DIRS "include/"
#     FILES "include/GreeterLib/GreeterLib.hpp"
# )

# target_compile_features(GreeterLib PRIVATE cxx_std_20)

cmake_minimum_required(VERSION 3.23)
project(GreeterPack VERSION 1.0.0)

include(GNUInstallDirs)

add_library(GreeterLib source/GreeterLib.cpp)
add_library(Greeter::Lib ALIAS GreeterLib)

set_target_properties(GreeterLib PROPERTIES
  OUTPUT_NAME Greeter
  EXPORT_NAME Lib
)

target_sources(GreeterLib
  PUBLIC
  FILE_SET HEADERS
  BASE_DIRS "${PROJECT_SOURCE_DIR}/include"
  FILES
  "${PROJECT_SOURCE_DIR}/include/GreeterLib/GreeterLib.hpp"
)

install(
  TARGETS GreeterLib
  EXPORT GreeterLibTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  COMPONENT Development
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  COMPONENT Development
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  COMPONENT Development
  FILE_SET HEADERS DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}
  COMPONENT Development
)

install(EXPORT GreeterLibTargets
  FILE GreeterLibTargets.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/GreeterLib
  NAMESPACE Greeter::
  COMPONENT Development
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
  "cmake/GreeterLibConfig.cmake.in"
  "GreeterLibConfig.cmake"
  INSTALL_DESTINATION
  "${CMAKE_INSTALL_LIBDIR}/cmake/GreeterLib"
)

write_basic_package_version_file(
  "GreeterLibConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/GreeterLibConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/GreeterLibConfigVersion.cmake"
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/GreeterLib"
  COMPONENT Development
)


