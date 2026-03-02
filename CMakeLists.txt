cmake_minimum_required(VERSION 3.23)
project(Greeter)

# set(COVERAGE_CONDITION
#   "$<AND:$<CONFIG:Coverage>,$<CXX_COMPILER_ID:GNU,Clang>>"
# )
# set(COVERAGE_FLAGS "$<${COVERAGE_CONDITION}:--coverage>")
# add_compile_options(${COVERAGE_FLAGS})
# add_link_options(${COVERAGE_FLAGS})

set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)

set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Greeter Library")

add_subdirectory(app)
add_subdirectory(lib)


enable_testing()
add_subdirectory(test)

add_subdirectory(benchmark)



include(CPack)
cpack_add_component(Development
  DISPLAY_NAME "The Greeter Library"
  DESCRIPTION "Compiled Library, Header Files, and CMake Configuration Files"
)

cpack_add_component(Application
  DISPLAY_NAME "The Greeter Application"
  DESCRIPTION "An application that says hello to the user"
)
