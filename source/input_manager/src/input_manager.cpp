#include <input_manager.hpp>
#include <input_state.hpp>

void InputManager::update() {
    state = {true};
}

InputState InputManager::getState() const { return state; }