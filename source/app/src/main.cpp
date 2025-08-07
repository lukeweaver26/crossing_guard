#include <graphics_engine.hpp>
#include <input_manager.hpp>
#include <iostream>
#include <simulation_clock.hpp>
#include <simulation_state.hpp>
#include <traffic_engine.hpp>
#include <window_manager.hpp>

int main() {
  std::cout << "Crossing Guard" << std::endl;
  SimulationState simulation_state;
  simulation_state.worldViewportSize = Vector2(50, 50);

  WindowManager &window_manager = WindowManager::getInstance();
  window_manager.initialize(720, 720, "Crossing Guard");

  TrafficEngine traffic_engine;
  GraphicsEngine graphics_engine;
  InputManager input_manager;

  traffic_engine.initialize();
  graphics_engine.initialize();

  SimulationClock &clock = SimulationClock::get();

  while (window_manager.running()) {
    graphics_engine.startFrame();

    graphics_engine.step(simulation_state, traffic_engine.getState());

    input_manager.step();
    traffic_engine.handleInput(input_manager.getState());
    simulation_state.worldViewportSize.x =
        input_manager.getState().worldViewportSize;
    simulation_state.worldViewportSize.y =
        input_manager.getState().worldViewportSize;

    traffic_engine.step();

    graphics_engine.endFrame();

    clock.wait_next();
  }

  graphics_engine.shutdown();
  window_manager.shutdown();
}
