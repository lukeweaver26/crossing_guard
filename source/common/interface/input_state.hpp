#ifndef INPUT_STATE_HPP
#define INPUT_STATE_HPP

#include <iostream>

struct InputState {
    bool spawnVehicle;

    float simSpeed;
    float worldViewportSize = 10;
};

#endif