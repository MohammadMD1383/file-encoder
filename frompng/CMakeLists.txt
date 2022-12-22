project(frompng)
include_directories(../core)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} png)
