include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/../src)

add_executable(test main.cpp)
target_link_libraries(test assp)

add_executable(test1 main1.cpp)
target_link_libraries(test1 assp)
