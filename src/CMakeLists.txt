add_library(dunenpc dunenpc.cpp)
target_link_libraries(dunenpc PUBLIC curl ${npc_lib})

if (UNIX AND NOT APPLE)
    target_link_libraries(dunenpc PUBLIC curl ${npc_lib} stdc++fs)
endif (UNIX AND NOT APPLE)

target_include_directories(dunenpc
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${npc_include})

install(TARGETS dunenpc DESTINATION lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include)
