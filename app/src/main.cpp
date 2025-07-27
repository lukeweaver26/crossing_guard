#include <graphics_engine.hpp>
#include <iostream>
#include <simulation_clock.hpp>
#include <traffic_engine.hpp>
#include <traffic_state.hpp>

int main() {
  std::cout << "Crossing Guard!" << std::endl;

  GraphicsEngine graphics(1280, 720);
  TrafficEngine engine;
  TrafficState state;

  SimulationClock &clock = SimulationClock::get();

  engine.initialize();
  graphics.initialize();

  while (graphics.running()) {
    state = engine.step();
    graphics.step(state);
    clock.wait_next();
  }

  graphics.shutdown();
}
