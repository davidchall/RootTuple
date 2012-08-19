# Require CMake-2.8.6 for FortranCInterface module
cmake_minimum_required (VERSION 2.8.6)

# Set project name and language dependencies
project (RootTuple CXX C Fortran)

# Create source archives using make dist
set (CPACK_PACKAGE_VERSION_MAJOR 0)
set (CPACK_PACKAGE_VERSION_MINOR 1)
set (CPACK_PACKAGE_VERSION_PATCH 0)
set (CPACK_SOURCE_GENERATOR "TGZ")
set (CPACK_SOURCE_PACKAGE_FILE_NAME
  "${CMAKE_PROJECT_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
set (CPACK_SOURCE_IGNORE_FILES
  "${CPACK_SOURCE_IGNORE_FILES}" .git)
include (CPack)
add_custom_target (dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source)


add_subdirectory (src)
