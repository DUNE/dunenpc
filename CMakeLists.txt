cmake_minimum_required(VERSION 3.20)

project(dunenpc VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set installation destinations typical for *nix systems
include(GNUInstallDirs)
message(STATUS "ENV{NPC_INSTALL_DIR}: [$ENV{NPC_INSTALL_DIR}]")
if (DEFINED ENV{NPC_INSTALL_DIR})
    message(STATUS "Detected user defined NPC_INSTALL_DIR...")
    set(CMAKE_INSTALL_PREFIX "$ENV{NPC_INSTALL_DIR}")
    set(CMAKE_PREFIX_PATH "$ENV{NPC_INSTALL_DIR}")
else()
    message(STATUS "NPC_INSTALL_DIR not set. Using default...")
endif()
message(STATUS "CMAKE_INSTALL_PREFIX: [${CMAKE_INSTALL_PREFIX}]")
message(STATUS "CMAKE_PREFIX_PATH: [${CMAKE_PREFIX_PATH}]")

# Set up external dependencies
find_package(CURL REQUIRED)
find_library(npc_lib NAMES nopayloadclient)
find_path(npc_include NAMES nopayloadclient)

add_subdirectory(src)
add_subdirectory(examples)

# Set up tests
option(BUILD_TESTING "" OFF)
include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
