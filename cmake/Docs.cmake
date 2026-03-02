cmake_minimum_required(VERSION 3.23)

find_package(Doxygen)
if(Doxygen_FOUND)
  message(STATUS "Found Doxygen Version "
    "${DOXYGEN_VERSION} at ${DOXYGEN_EXECUTABLE}")

  doxygen_add_docs(docs 
    ${PROJECT_SOURCE_DIR}/greeter/include 
    COMMENT "Generating docs with Doxygen..."
  ) 
endif()