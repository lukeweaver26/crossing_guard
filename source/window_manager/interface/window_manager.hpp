#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <GLFW/glfw3.h>

class WindowManager {
public:
  static WindowManager &getInstance();

  void initialize(int width, int height, const char *title);
  void shutdown();

  GLFWwindow *getWindow() const;

  void pollEvents();
  void swapBuffers();
  bool running();

  WindowManager(const WindowManager &) = delete;
  void operator=(const WindowManager &) = delete;

private:
  WindowManager() = default;
  GLFWwindow *window = nullptr;
};

#endif