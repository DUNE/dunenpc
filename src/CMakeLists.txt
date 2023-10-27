option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_library(dunenpc dunenpc.cpp)
target_link_libraries(dunenpc PUBLIC curl ${npc_lib})

if (UNIX AND NOT APPLE)
    target_link_libraries(dunenpc PUBLIC curl ${npc_lib} stdc++fs)
endif (UNIX AND NOT APPLE)

set(INCLUDE_DIR_NLOHMANN_JSON "${CMAKE_SOURCE_DIR}/contrib" CACHE STRING "Description of MY_VAR")
message(STATUS "INCLUDE_DIR_NLOHMANN_JSON: [${INCLUDE_DIR_NLOHMANN_JSON}]")

target_include_directories(dunenpc
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${INCLUDE_DIR_NLOHMANN_JSON}
    ${npc_include})

install(TARGETS dunenpc DESTINATION lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include)

add_executable(cli_dunenpc cli.cpp)
target_link_libraries(cli_dunenpc PUBLIC dunenpc ${npc_lib} curl ${_std_cxx_filesystem_lib})
target_include_directories(cli_dunenpc PRIVATE ${CMAKE_SOURCE_DIR}/include ${npc_include} ${INCLUDE_DIR_NLOHMANN_JSON})
install(TARGETS cli_dunenpc DESTINATION bin)
