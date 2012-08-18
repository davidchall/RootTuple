set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/Modules/)

find_package (ROOT REQUIRED)

include_directories (${ROOT_INCLUDE_DIRS})

add_library (${CMAKE_PROJECT_NAME} SHARED RootTuple.cxx)
target_link_libraries (${CMAKE_PROJECT_NAME} ${ROOT_LIBRARIES})

install (TARGETS ${CMAKE_PROJECT_NAME} DESTINATION lib)
install (FILES RootTuple.h DESTINATION include)
