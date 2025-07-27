#include <chrono>
#include <iostream>
#include <thread>

#include <hardbody.hpp>
#include <simulation_clock.hpp>
#include <traffic_engine.hpp>
#include <traffic_state.hpp>

TrafficEngine::TrafficEngine() : hardbodies() {}

void TrafficEngine::initialize() {
  Hardbody car({-1.0, 0.0}, {.1, 0}, {0, -.1});
  hardbodies.push_back(car);
}

TrafficState TrafficEngine::step() {

  TrafficState state;

  int hardbodies_size = static_cast<int>(hardbodies.size());
  for (int i = 0; i < hardbodies_size; i++) {
    hardbodies[i].step();
    state.objects.push_back(hardbodies[i].position);
  }
  return state;
}
