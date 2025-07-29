add_library(input-manager 
    STATIC 
        src/input_manager.cpp
)

target_link_libraries(input-manager PUBLIC common imgui)
target_include_directories(input-manager PUBLIC interface)