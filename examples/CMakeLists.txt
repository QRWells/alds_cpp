add_executable(doubly_linked_list doubly_linked_list.cpp)
target_include_directories(alds_bench PUBLIC ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(alds_bench INTERFACE alds)