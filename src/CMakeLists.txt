# Find ROOT
find_package (ROOT REQUIRED)
include_directories (${ROOT_INCLUDE_DIR})

# Test FORTRAN/C interface abilities and produce name mangling macros
include (FortranCInterface)
FortranCInterface_VERIFY(CXX)
FortranCInterface_HEADER(FC_namemangling.h)

# Include binary tree in include path (to find name mangling macros)
include_directories (${CMAKE_BINARY_DIR}/src)



set (RootTuple_SOURCES RootTuple.cxx interface.cxx)
set (RootTuple_HEADERS RootTuple.h interface.h ${CMAKE_BINARY_DIR}/src/FC_namemangling.h)

# Create library
add_library (RootTuple SHARED ${RootTuple_SOURCES})
target_link_libraries (RootTuple ${ROOT_LIBRARIES})

install (TARGETS RootTuple DESTINATION lib)
install (FILES ${RootTuple_HEADERS} DESTINATION include)
