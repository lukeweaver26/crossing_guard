#include <GLFW/glfw3.h>
#include <graphics_engine.hpp>
#include <stdio.h>
#include <traffic_state.hpp>
#include <vector2.hpp>

ImVec2 GraphicsEngine::translate_coords(const Vector2 &traffic_plane) {
  ImVec2 graphics_coords;
  graphics_coords.x =
      static_cast<float>(traffic_plane.x + 1) * (static_cast<float>(width) / 2);
  graphics_coords.y = static_cast<float>(traffic_plane.y + 1) *
                      (static_cast<float>(height) / 2);
  return graphics_coords;
}

int GraphicsEngine::initialize() {
  // Init GLFW
  if (!glfwInit())
    return -1;
  window = glfwCreateWindow(width, height, "Crossing Guard", NULL, NULL);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable vsync

  // Setup ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;

  ImGui::StyleColorsDark();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  return 0;
}

int GraphicsEngine::running() { return !glfwWindowShouldClose(window); }

int GraphicsEngine::step(const TrafficState &state) {
  glfwPollEvents();

  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  // Get Object
  Object car = state.objects[0];

  // UI
  ImDrawList *bg = ImGui::GetBackgroundDrawList();

  ImVec2 pos = translate_coords(car.position);
  ImVec2 size(60, 30);
  bg->AddRectFilled(pos, ImVec2(pos.x + size.x, pos.y + size.y),
                    IM_COL32(255, 0, 0, 255));

  // Render
  ImGui::Render();
  int display_w, display_h;
  glfwGetFramebufferSize(window, &display_w, &display_h);
  glViewport(0, 0, display_w, display_h);
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  glfwSwapBuffers(window);
  return 0;
}

int GraphicsEngine::shutdown() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}