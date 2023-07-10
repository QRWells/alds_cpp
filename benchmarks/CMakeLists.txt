add_executable(alds_bench bench.cpp)

target_include_directories(alds_bench PUBLIC ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(alds_bench INTERFACE alds)

target_link_libraries(alds_bench PRIVATE benchmark::benchmark)