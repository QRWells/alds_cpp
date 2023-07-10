add_executable(alds_test test.cpp)

target_include_directories(alds_test PUBLIC ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(alds_test INTERFACE alds)

add_test(NAME alds_test COMMAND alds_test)