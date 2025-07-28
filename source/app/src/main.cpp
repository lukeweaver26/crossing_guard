#include <graphics_engine.hpp>
#include <iostream>
#include <simulation_clock.hpp>
#include <traffic_engine.hpp>
#include <traffic_state.hpp>
#include <input_manager.hpp>
#include <window_manager.hpp>
#include <GLFW/glfw3.h>

int main() {
  std::cout << "Crossing Guard!" << std::endl;

  WindowManager& window_manager = WindowManager::getInstance();
  window_manager.initialize(720, 720, "Crossing Guard");

  TrafficEngine traffic_engine;
  GraphicsEngine graphics_engine;
  InputManager input_manager;

  traffic_engine.initialize();
  graphics_engine.initialize();
  
  TrafficState traffic_state;
  InputState input_state;

  SimulationClock &clock = SimulationClock::get();

  while (window_manager.running()) {
    traffic_state = traffic_engine.step();
    graphics_engine.step(traffic_state);
    clock.wait_next();
  }

  graphics_engine.shutdown();
  window_manager.shutdown();
}
