cmake_minimum_required(VERSION 3.24)
project(file-encoder)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(reverse)
add_subdirectory(inverse)
add_subdirectory(topng)

install(
	TARGETS reverse inverse topng
	CONFIGURATIONS Release
	RUNTIME DESTINATION bin
)
