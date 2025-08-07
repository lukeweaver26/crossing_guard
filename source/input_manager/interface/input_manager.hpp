#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <GLFW/glfw3.h>
#include <input_state.hpp>

class InputManager {
  public:
	void step();
	InputState getState() const;

	bool shouldCaptureInput() const;

  private:
	InputState state;
};

#endif