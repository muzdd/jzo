include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../common)

set(SRC print_link_head2tail.cpp ../../common/list.cpp)

add_library(plht STATIC ${SRC})


target_link_libraries(plht)

