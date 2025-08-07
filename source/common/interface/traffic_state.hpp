#ifndef TRAFFIC_STATE_HPP
#define TRAFFIC_STATE_HPP

#include <vector2.hpp>
#include <vector>

struct Renderable {
  Vector2 position_m;
  Vector2 halfSize_m;
  float angle_rad;

  Renderable(Vector2 position = {0.0f, 0.0f}, Vector2 halfSize = {1.25, .5f})
      : position_m(position), halfSize_m(halfSize), angle_rad(0){};
};

struct TrafficState {
  std::vector<Renderable> renderables;
};

#endif