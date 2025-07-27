#ifndef GRAPHICS_ENGINE_HPP
#define GRAPHICS_ENGINE_HPP

#include <traffic_state.hpp>
#include <GLFW/glfw3.h>

class GraphicsEngine {
    public:
        int initialize();
        int running();
        int step(const TrafficState& state);
        int shutdown();
        

    private:
        GLFWwindow* window = nullptr;

};

#endif