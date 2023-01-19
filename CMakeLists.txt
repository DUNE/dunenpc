cmake_minimum_required(VERSION 3.20)

project(dunenpc VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set installation destinations typical for *nix systems
include(GNUInstallDirs)

# Set up external dependencies
find_package(CURL REQUIRED)
find_library(nopayloadclient NAMES nopayloadclient)

add_subdirectory(src)
add_subdirectory(examples)

# Set up tests
option(BUILD_TESTING "" OFF)
include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
