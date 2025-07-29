#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <input_state.hpp>
#include <GLFW/glfw3.h>

class InputManager {
    public:
        void step();
        InputState getState() const;

        bool shouldCaptureInput() const;

    private:
        InputState state;
};

#endif