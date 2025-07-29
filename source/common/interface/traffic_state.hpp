#ifndef TRAFFIC_STATE_HPP
#define TRAFFIC_STATE_HPP

#include <vector2.hpp>
#include <vector>

struct Object {
  Vector2 position;
  float angle;

  Object(Vector2 vec = {0, 0}) : position(vec), angle(0){};
};

struct TrafficState {
  std::vector<Object> objects;
};

#endif