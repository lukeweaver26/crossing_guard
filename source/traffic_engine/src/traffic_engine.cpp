#include <chrono>
#include <iostream>
#include <thread>

#include <hardbody.hpp>
#include <simulation_clock.hpp>
#include <traffic_engine.hpp>
#include <traffic_state.hpp>
#include <math.h>

TrafficEngine::TrafficEngine() : hardbodies() {}

void TrafficEngine::initialize() {
  Hardbody car1({-1.0, 0.0}, {.5, .5}, {0, 0});
  Hardbody car2({-1.0, -1.0}, {.1, .5}, {0, 0});
  hardbodies.push_back(car1);
  hardbodies.push_back(car2);
}

void TrafficEngine::step() {

  state = TrafficState();

  int hardbodies_size = static_cast<int>(hardbodies.size());
  for (int i = 0; i < hardbodies_size; i++) {
    hardbodies[i].step();

    Object obj;
    obj.position = hardbodies[i].position;
    obj.direction = hardbodies[i].direction;
    state.objects.push_back(obj);
  }
}

TrafficState TrafficEngine::getState() {return state;}

void TrafficEngine::handleInput(const InputState& input_state) {
  static double angle = 0;
  
  if (input_state.spawn_vehicle) {
    double s = static_cast<double>(sinf(static_cast<float>(angle)));
    double c = static_cast<double>(cosf(static_cast<float>(angle)));
    std::pair<double, double> vel = std::pair<double, double>(1 * c - 0 * s, 1 * s + 0 * c);

    hardbodies.push_back(Hardbody({0, 0}, vel, {0, 0}));

    angle += M_PI / 6;
  }
}
  