set(SRC AssignmentOperator.cpp valid.cpp)

add_library(assp STATIC ${SRC})

target_link_libraries(assp)

