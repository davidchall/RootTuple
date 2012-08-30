# Find ROOT
find_package (ROOT REQUIRED)
include_directories (${ROOT_INCLUDE_DIR})

# Test FORTRAN/C interface abilities and produce name mangling macros
include (FortranCInterface)
FortranCInterface_VERIFY(CXX)
FortranCInterface_HEADER(FC_namemangling.h)

# Include binary tree in include path (to find name mangling macros)
include_directories (${CMAKE_BINARY_DIR}/src)

# Create library
set (RootTuple_SOURCES RootTuple.cxx interface.cxx)
set (RootTuple_HEADERS RootTuple.h interface.h ${CMAKE_BINARY_DIR}/src/FC_namemangling.h)
add_library (RootTuple SHARED ${RootTuple_SOURCES})
target_link_libraries (RootTuple ${ROOT_LIBRARIES})

# Configure config script
configure_file ("${CMAKE_SOURCE_DIR}/src/RootTuple-config.in" "${CMAKE_BINARY_DIR}/src/RootTuple-config")

# Create install targets
install (TARGETS RootTuple DESTINATION lib)
install (FILES ${CMAKE_BINARY_DIR}/src/RootTuple-config DESTINATION bin 
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
