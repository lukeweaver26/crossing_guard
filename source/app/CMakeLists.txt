add_executable(crossing-guard src/main.cpp)

set_target_properties(crossing-guard PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_include_directories(crossing-guard PUBLIC interface)

target_link_libraries(crossing-guard PUBLIC 
	traffic-engine
	graphics-engine
	input-manager
	window-manager
	common
	imgui
	glfw
	OpenGL::GL
)
