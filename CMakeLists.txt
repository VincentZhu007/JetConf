cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(JetConf LANGUAGES CXX)

set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

# Disable CMAKE_MACOSX_RPATH explicitly in new version cmake
# to avoid cmake warnings on Mac OS.
set(CMAKE_MACOSX_RPATH OFF)

# third_party
add_subdirectory(third_party)

# experiments
option(JET_CONF_WITH_EXPERIMENTS "build experiments?" ON)
message(STATUS "build experiments? " ${JET_CONF_WITH_EXPERIMENTS})

if(JET_CONF_WITH_EXPERIMENTS)
    add_subdirectory(experiments)
endif()

# source
add_subdirectory(src)

# tests
option(JET_CONF_WITH_TESTS "build tests?" ON)
message(STATUS "build tests? " ${JET_CONF_WITH_TESTS})

if(JET_CONF_WITH_TESTS)
    include(CTest)
    add_subdirectory(tests)
endif()