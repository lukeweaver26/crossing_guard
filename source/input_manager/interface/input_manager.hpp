#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <input_state.hpp>
#include <GLFW/glfw3.h>

class InputManager {
    public:
        void update();
        InputState getState() const;

    private:
        InputState state;
        GLFWwindow* window;
};

#endif