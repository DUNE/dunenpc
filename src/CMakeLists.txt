add_library(dunenpc dunenpc.cpp)
target_link_libraries(dunenpc PUBLIC curl ${nopayloadclient})

if (UNIX AND NOT APPLE)
    target_link_libraries(dunenpc PUBLIC curl ${nopayloadclient} stdc++fs)
endif (UNIX AND NOT APPLE)

target_include_directories(dunenpc
    INTERFACE
    $<INSTALL_INTERFACE:include>
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/contrib
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    /usr/local/include)

message(STATUS "INTERFACE: [${INTERFACE}]")
message(STATUS "CMAKE_SOURCE_DIR: [${CMAKE_SOURCE_DIR}]")

install(TARGETS dunenpc DESTINATION lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include)
