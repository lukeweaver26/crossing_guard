#ifndef GRAPHICS_ENGINE_HPP
#define GRAPHICS_ENGINE_HPP

#include <GLFW/glfw3.h>
#include <traffic_state.hpp>

class GraphicsEngine {
public:
  int initialize();
  int running();
  int step(const TrafficState &state);
  int shutdown();

private:
  GLFWwindow *window = nullptr;
};

#endif