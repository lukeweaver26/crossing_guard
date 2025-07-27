#ifndef GRAPHICS_ENGINE_HPP
#define GRAPHICS_ENGINE_HPP

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <traffic_state.hpp>
#include <vector2.hpp>

class GraphicsEngine {
public:
  int initialize();
  int running();
  int step(const TrafficState &state);
  int shutdown();

  GraphicsEngine(int width = 1280, int height = 720)
      : width(width), height(height){};

private:
  int width;
  int height;

  GLFWwindow *window = nullptr;
  ImVec2 translate_coords(const Vector2 &coords);
};

#endif