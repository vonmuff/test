cmake_minimum_required(VERSION 3.23)

find_package(spdlog REQUIRED)

add_library(GreeterAppLogic)
target_sources(GreeterAppLogic
    PRIVATE
    source/run.cpp
    PUBLIC
    FILE_SET app_public_headers
    TYPE HEADERS
    BASE_DIRS "include/"
    FILES "include/app/run.hpp"
)

add_executable(GreeterApp source/main.cpp)
target_compile_features(GreeterApp PRIVATE cxx_std_20)

target_link_libraries(GreeterAppLogic
    PRIVATE GreeterLib
    PRIVATE spdlog::spdlog
)
target_link_libraries(GreeterApp GreeterAppLogic)

include(GNUInstallDirs)
install(
    TARGETS GreeterApp
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT Application
)
