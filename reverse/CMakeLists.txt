project(reverse)

find_package(Boost 1.81.0 COMPONENTS filesystem REQUIRED)

include_directories(../core)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
