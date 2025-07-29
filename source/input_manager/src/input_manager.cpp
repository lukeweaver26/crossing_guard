#include <input_manager.hpp>
#include <input_state.hpp>
#include "imgui.h"



void InputManager::step() {
    static int i = 0;
    state = InputState();
    i++;
    if (ImGui::Begin("Controls")) {
        if (ImGui::Button("Spawn Vehicle")) {
            state.spawn_vehicle = true;
        }
        ImGui::SliderFloat("Sim Speed", &state.sim_speed, 0.1f, 5.0f);
    }
    ImGui::End();
}

InputState InputManager::getState() const { return state; }

bool InputManager::shouldCaptureInput() const {
    return !ImGui::GetIO().WantCaptureKeyboard;
}