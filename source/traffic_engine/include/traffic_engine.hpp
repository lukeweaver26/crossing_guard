#ifndef TRAFFIC_ENGINE_HPP
#define TRAFFIC_ENGINE_HPP

#include <traffic_state.hpp>
#include <vector>
#include <input_state.hpp>
#include <box2d/box2d.h>

class TrafficEngine {
public:
  void initialize();
  void step();
  void handleInput(const InputState& input_state);

  TrafficState getState();

  TrafficEngine();

private:
  std::vector<b2BodyId> cars;
  TrafficState state;

  // Box2d
  b2WorldId worldId;
};

#endif