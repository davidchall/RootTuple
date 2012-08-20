# Require CMake-2.8.6 for FortranCInterface module
set (CMAKE_MINIMUM_VERSION_REQUIRED 2.8.6)
cmake_minimum_required (VERSION ${CMAKE_MINIMUM_VERSION_REQUIRED})

# Set project name and language dependencies
project (RootTuple CXX C Fortran)

# Create source archives using make dist
set (CPACK_PACKAGE_VERSION_MAJOR 0)
set (CPACK_PACKAGE_VERSION_MINOR 2)
set (CPACK_PACKAGE_VERSION_PATCH 0)
set (CPACK_SOURCE_GENERATOR "TGZ")
set (CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
set (CPACK_SOURCE_PACKAGE_FILE_NAME
  "${CMAKE_PROJECT_NAME}-${CPACK_PACKAGE_VERSION}")
set (CPACK_SOURCE_IGNORE_FILES
  "${CPACK_SOURCE_IGNORE_FILES}" .git README.md)
include (CPack)
add_custom_target (dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source)

# Tell CMake where to find additional modules
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/Modules/)

add_subdirectory (src)
add_subdirectory (docs)
