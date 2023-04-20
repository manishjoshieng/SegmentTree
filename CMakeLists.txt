cmake_minimum_required(VERSION 3.22.1)

project(SegmentTree)

set(CMAKE_CXX_STANDARD 17)

# Set variables for the directories containing header files and source files
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# Add the source files to the build
add_executable(SegmentTree 
    main.cpp
)

include(CPack)
include(CTest)
enable_testing()





