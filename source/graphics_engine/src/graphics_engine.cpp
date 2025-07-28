#include <GLFW/glfw3.h>
#include <graphics_engine.hpp>
#include <stdio.h>
#include <traffic_state.hpp>
#include <vector2.hpp>
#include <object_drawer.hpp>
#include <window_manager.hpp>

int GraphicsEngine::initialize() {
  GLFWwindow* window = WindowManager::getInstance().getWindow();

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;

  ImGui::StyleColorsDark();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  this->window = window;
  return 0;
}

int GraphicsEngine::step(const TrafficState &state) {
  WindowManager::getInstance().pollEvents();

  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  for (size_t i = 0; i < state.objects.size(); i++)
  {
    drawer.draw(state.objects[i]);
  }
  
  render();
  
  return 0;
}

int GraphicsEngine::shutdown() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  return 0;
}

void GraphicsEngine::render() {
  ImGui::Render();
  int display_w, display_h;
  glfwGetFramebufferSize(window, &display_w, &display_h);
  glViewport(0, 0, display_w, display_h);
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  glfwSwapBuffers(window);
}