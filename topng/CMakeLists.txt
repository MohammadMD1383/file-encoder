project(topng)
include_directories(../core)

if (DEFINED BOOST_ROOT)
	# for CI/CD
	include_directories(${BOOST_ROOT}/libs/gil/include)
else ()
	find_package(Boost 1.81.0 REQUIRED)
	include_directories(${Boost_INCLUDE_DIRS})
endif ()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} png)
