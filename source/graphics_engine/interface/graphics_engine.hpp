#ifndef GRAPHICS_ENGINE_HPP
#define GRAPHICS_ENGINE_HPP

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <traffic_state.hpp>
#include <vector2.hpp>
#include <object_drawer.hpp>

class GraphicsEngine {
public:
  int initialize();
  int step(const TrafficState &state);
  int shutdown();

private:
  GLFWwindow *window;
  ObjectDrawer drawer;

  void render();
 
};

#endif