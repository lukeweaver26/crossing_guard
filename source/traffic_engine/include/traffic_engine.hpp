#ifndef TRAFFIC_ENGINE_HPP
#define TRAFFIC_ENGINE_HPP

#include <box2d/box2d.h>
#include <input_state.hpp>
#include <traffic_state.hpp>
#include <vector>
#include <vehicle.hpp>

class TrafficEngine {
public:
  void initialize();
  void step();
  void handleInput(const InputState &input_state);

  TrafficState getState();

  TrafficEngine();

private:
  std::vector<VehicleInstance> cars;
  TrafficState state;
  Renderable ground;

  // Box2d
  b2WorldId worldId;
};

#endif