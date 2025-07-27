#ifndef TRAFFIC_STATE_HPP
#define TRAFFIC_STATE_HPP

#include <vector2.hpp>
#include <vector>

struct Object {
    Vector2 position;

    Object(Vector2 vec) : position(vec) {};
};

struct TrafficState
{
    std::vector<Object> objects;
};

#endif