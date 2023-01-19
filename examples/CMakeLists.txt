add_executable(cli_dunenpc cli_dunenpc.cpp)
target_link_libraries(cli_dunenpc dunenpc ${nopayloadclient} curl ${_std_cxx_filesystem_lib})
target_include_directories(cli_dunenpc PRIVATE ${CMAKE_SOURCE_DIR}/include)
install(TARGETS cli_dunenpc DESTINATION bin)
