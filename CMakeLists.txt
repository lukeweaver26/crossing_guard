cmake_minimum_required(VERSION 3.15...4.0)
project(CrossingGuard VERSION 0.1.0
		      DESCRIPTION "Autonomous Traffic Simulation"
		      LANGUAGES CXX)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Don't use Wayland" FORCE)

add_subdirectory(dependencies/glfw)

add_subdirectory(app)
add_subdirectory(common)
add_subdirectory(traffic_engine)
add_subdirectory(graphics_engine)
add_subdirectory(dependencies)
 
