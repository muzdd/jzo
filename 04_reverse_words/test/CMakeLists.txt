include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/../src)

add_executable(reverse_w main.cpp)
target_link_libraries(reverse_w rw)

