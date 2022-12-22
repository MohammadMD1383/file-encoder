project(topng)
include_directories(../core)

find_package(Boost 1.81.0)
if (DEFINED Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
else ()
	# for CI/CD
	include_directories(${BOOST_ROOT}/libs/gil/include)
endif ()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} png)
