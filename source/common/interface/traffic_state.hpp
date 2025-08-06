#ifndef TRAFFIC_STATE_HPP
#define TRAFFIC_STATE_HPP

#include <vector2.hpp>
#include <vector>

struct Object {
  Vector2 position_m;
  Vector2 size_m;
  float angle_rad;

  Object(Vector2 position = {0.0f, 0.0f}, Vector2 size = {2.5f, 1.0f}) : position_m(position), size_m(size), angle_rad(.5f * static_cast<float>(M_PI)){};
};

struct TrafficState {
  std::vector<Object> objects;
};

#endif