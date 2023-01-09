cmake_minimum_required(VERSION 3.24)
project(file-encoder)

set(CMAKE_CXX_STANDARD 20)

# for CI/CD
if (DEFINED BOOST_ROOT)
	include_directories(${BOOST_ROOT})
endif ()

if (DEFINED WINDOWS)
	set(CMAKE_EXECUTABLE_SUFFIX .exe)
	
	include_directories("/fakepath/cpp-tools/boost.win.include")
	include_directories(/fakepath/cpp-tools/libpng/libpng-1.6.39/build/include)
	link_directories("/fakepath/cpp-tools/boost.win/stage/lib")
	link_directories(/fakepath/cpp-tools/libpng/libpng-1.6.39/build/lib)
	
	set(CMAKE_INSTALL_PREFIX build.win)
endif()

file(GLOB dirs LIST_DIRECTORIES true RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/*)
foreach (subdir ${dirs})
	if (IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${subdir} AND EXISTS ${PROJECT_SOURCE_DIR}/${subdir}/CMakeLists.txt)
		add_subdirectory(${subdir})
		list(APPEND targets ${subdir})
	endif ()
endforeach ()

if (DEFINED ENV{RUNNER_OS})
	foreach (target ${targets})
		set_target_properties(
			${target}
			PROPERTIES OUTPUT_NAME "$ENV{RUNNER_OS}-${target}"
		)
	endforeach ()
endif ()

install(
	TARGETS ${targets}
	CONFIGURATIONS Release
	RUNTIME DESTINATION bin
)
