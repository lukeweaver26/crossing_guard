#include "imgui.h"
#include <input_manager.hpp>
#include <input_state.hpp>

void InputManager::step() {

	if (state.spawnVehicle == true) {
		state.spawnVehicle = false;
	};

	if (ImGui::Begin("Controls")) {
		if (ImGui::Button("Spawn Vehicle")) {
			state.spawnVehicle = true;
		}
		ImGui::SliderFloat("Viewport Size", &state.worldViewportSize, 1.0f,
						   100.0f);
	}
	ImGui::End();
}

InputState InputManager::getState() const { return state; }

bool InputManager::shouldCaptureInput() const {
	return !ImGui::GetIO().WantCaptureKeyboard;
}