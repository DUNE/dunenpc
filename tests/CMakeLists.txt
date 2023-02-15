add_executable(test_dunenpc test_dunenpc.cpp)

target_link_libraries(test_dunenpc dunenpc ${_std_cxx_filesystem_lib})

target_include_directories(test_dunenpc PRIVATE ${CMAKE_SOURCE_DIR}/include ${npc_include})

add_test(NAME test_dunenpc COMMAND ./test_dunenpc)
