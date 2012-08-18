# Package finder for ROOT
# Variables that must be set:
# - ROOT_FOUND
# - ROOT_INCLUDE_DIRS
# - ROOT_LIBRARIES
# - ROOT_DEFINITIONS

set (CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)
set (root_CONFIG_EXE root-config)

# Search PATH for root-config
execute_process (COMMAND which root-config
  OUTPUT_VARIABLE root_CONFIG
)

if (root_CONFIG)
  execute_process (COMMAND root-config --prefix
    OUTPUT_VARIABLE root_PREFIX
    )
  if (root_PREFIX)
    string (STRIP ${root_PREFIX} root_PREFIX)
    message (STATUS "Found root-config. ROOT location is ${root_PREFIX}")
  endif ()
  
  # Check ROOT version high enough
  #execute_process (COMMAND root-config --version
  #  OUTPUT_VARIABLE root_VERSION
  #  )
  #if (NOT root_VERSION VERSION_GREATER "5.28")
  #  message (STATUS "PSTree requires ROOT 5.28")
  #endif ()
  
  # Get library info from root-config
  execute_process (COMMAND root-config --libs --nonew --glibs
    OUTPUT_VARIABLE ROOTLIBS
    )
  string (STRIP "${ROOTLIBS}" ROOTLIBS)
  separate_arguments (ROOTLIBS)
  string (REGEX MATCHALL "-L[^;]+" root_LIBRARY_DIR "${ROOTLIBS}")
  string (REPLACE "-L" "" root_LIBRARY_DIR "${root_LIBRARY_DIR}")
  string (REGEX MATCHALL "-l[^;]+" root_LIBNAMES "${ROOTLIBS}")
  string (REPLACE "-l" "" root_LIBNAMES "${root_LIBNAMES}")
  
  # Get include info from root-config
  execute_process (COMMAND root-config --cflags
    OUTPUT_VARIABLE ROOTFLAGS
    )
  string (STRIP "${ROOTFLAGS}" ROOTFLAGS)
  separate_arguments (ROOTFLAGS)
  string (REGEX MATCHALL "-I[^;]+" root_INCLUDE_DIR "${ROOTFLAGS}")
  string (REPLACE "-I" "" root_INCLUDE_DIR "${root_INCLUDE_DIR}")
  string (REPLACE ";" " " root_INCLUDE_DIR "${root_INCLUDE_DIR}")

endif()

# Find an example header file
find_path (ROOT_INCLUDE_DIRS TTree.h ${root_INCLUDE_DIR})

# Find required libraries
foreach (libname ${root_LIBNAMES})
  unset (lib CACHE)
  find_library (lib ${libname} PATHS ${root_LIBRARY_DIR})
  if (lib)
    set (ROOT_LIBRARIES ${ROOT_LIBRARIES} ${lib})
  else()
    message (STATUS "Could NOT find library: ${libname}")
  endif()
endforeach()


# Return ROOT_FOUND=TRUE if everything OK
include (FindPackageHandleStandardArgs)
find_package_handle_standard_args (ROOT DEFAULT_MSG ROOT_LIBRARIES ROOT_INCLUDE_DIRS)
