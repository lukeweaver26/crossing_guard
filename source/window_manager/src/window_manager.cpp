#include <stdexcept>
#include <window_manager.hpp>

WindowManager &WindowManager::getInstance() {
  static WindowManager instance;
  return instance;
}

void WindowManager::initialize(int width, int height, const char *title) {
  if (window)
    return; // already initialized
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  window = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if (!window)
    throw std::runtime_error("Failed to create GLFW window");
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // VSync
}

GLFWwindow *WindowManager::getWindow() const { return window; }

void WindowManager::pollEvents() { glfwPollEvents(); }

void WindowManager::swapBuffers() { glfwSwapBuffers(window); }

bool WindowManager::running() { return !glfwWindowShouldClose(window); }

void WindowManager::shutdown() {
  glfwDestroyWindow(window);
  glfwTerminate();
}