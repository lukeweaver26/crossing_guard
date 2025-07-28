add_library(window-manager STATIC src/window_manager.cpp)

target_link_libraries(window-manager PRIVATE glfw)
target_include_directories(window-manager PUBLIC interface)