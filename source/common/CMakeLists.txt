add_library(common STATIC
    src/vector2.cpp
    src/simulation_clock.cpp
)

target_include_directories(common PUBLIC interface)