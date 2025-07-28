#include <chrono>
#include <iostream>
#include <thread>

#include <hardbody.hpp>
#include <simulation_clock.hpp>
#include <traffic_engine.hpp>
#include <traffic_state.hpp>

TrafficEngine::TrafficEngine() : hardbodies() {}

void TrafficEngine::initialize() {
  Hardbody car1({-1.0, 0.0}, {.5, .5}, {0, 0});
  Hardbody car2({-1.0, -1.0}, {.1, .5}, {0, 0});
  hardbodies.push_back(car1);
  hardbodies.push_back(car2);
}

TrafficState TrafficEngine::step() {

  TrafficState state;

  int hardbodies_size = static_cast<int>(hardbodies.size());
  for (int i = 0; i < hardbodies_size; i++) {
    hardbodies[i].step();

    Object obj;
    obj.position = hardbodies[i].position;
    obj.direction = hardbodies[i].direction;
    state.objects.push_back(obj);
  }
  return state;
}
