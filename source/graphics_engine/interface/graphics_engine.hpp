#ifndef GRAPHICS_ENGINE_HPP
#define GRAPHICS_ENGINE_HPP

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <simulation_state.hpp>
#include <traffic_state.hpp>
#include <vector2.hpp>

class GraphicsEngine {
public:
  int initialize();
  int step(const SimulationState &sim_state, const TrafficState &state);

  void startFrame();
  void endFrame();

  int shutdown();

private:
  GLFWwindow *window;
  Vector2 worldViewportSize;

  ImVec2 translateCoordinatesToWindow(const ImVec2 &traffic_coordinates);
  ImVec2 scaleToWindow(const Vector2 &size_m);
  void draw(const Renderable &obj, ImU32 color);
};

#endif