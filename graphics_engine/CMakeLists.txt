add_library(graphics-engine STATIC
    src/graphics_engine.cpp
)

target_include_directories(graphics-engine PUBLIC interface)
target_link_libraries(graphics-engine PRIVATE imgui)
