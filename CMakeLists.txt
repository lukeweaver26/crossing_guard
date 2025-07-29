cmake_minimum_required(VERSION 3.15...4.0)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(CrossingGuard VERSION 0.1.0
		      DESCRIPTION "Autonomous Traffic Simulation"
		      LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/graphics.cmake)
add_subdirectory(dependencies/box2d)

add_subdirectory(source)


set(COMPILE_WARNING_TARGETS  
	crossing-guard
	traffic-engine 
	graphics-engine
	window-manager
	input-manager
	app
)

set(COMPILER_OPTIONS 
	-Wall
	-Wextra
	-Werror
	-Wconversion
	# -pedantic
)

foreach(target IN LISTS COMPILE_WARNING_TARGETS)
	if (TARGET ${target})
		target_compile_options(${target} PRIVATE ${COMPILER_OPTIONS})
	else()
		message(WARNING "Target '${target}' not found.")
	endif()
endforeach()


