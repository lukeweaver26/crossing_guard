#ifndef TRAFFIC_STATE_HPP
#define TRAFFIC_STATE_HPP

#include <vector2.hpp>
#include <vector>

const double DEFAULT_DIRECTION_X = 1;
const double DEFAULT_DIRECTION_Y = 0;

struct Object {
  Vector2 position;
  Vector2 direction;

  Object(Vector2 vec = {0, 0}) : position(vec), direction(DEFAULT_DIRECTION_X, DEFAULT_DIRECTION_Y){};
};

struct TrafficState {
  std::vector<Object> objects;
};

#endif