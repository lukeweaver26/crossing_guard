#ifndef TRAFFIC_ENGINE_HPP
#define TRAFFIC_ENGINE_HPP

#include <hardbody.hpp>
#include <traffic_state.hpp>
#include <vector>
#include <input_state.hpp>

class TrafficEngine {
public:
  void initialize();
  void step();
  void handleInput(const InputState& input_state);

  TrafficState getState();

  TrafficEngine();

private:
  std::vector<Hardbody> hardbodies;
  TrafficState state;
};

#endif