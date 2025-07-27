cmake_minimum_required(VERSION 3.15...4.0)
project(CrossingGuard VERSION 0.1.0
		      DESCRIPTION "Autonomous Traffic Simulation"
		      LANGUAGES CXX)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Don't use Wayland" FORCE)

add_subdirectory(dependencies/glfw)

add_subdirectory(traffic_engine)
add_subdirectory(graphics_engine)
add_subdirectory(dependencies)


add_executable(crossing-guard main.cpp)

find_package(OpenGL REQUIRED)

target_link_libraries(crossing-guard PUBLIC 
	traffic-engine
	graphics-engine
	imgui
	glfw
	OpenGL::GL
)
 
