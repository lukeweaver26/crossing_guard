#ifndef TRAFFIC_ENGINE_HPP
#define TRAFFIC_ENGINE_HPP

#include <hardbody.hpp>
#include <traffic_state.hpp>
#include <vector>

class TrafficEngine {
public:
  TrafficState step();
  void initialize();

  TrafficEngine();

private:
  std::vector<Hardbody> hardbodies;
};

#endif