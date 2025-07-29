#ifndef INPUT_STATE_HPP
#define INPUT_STATE_HPP

#include <iostream>

struct InputState {
    bool spawn_vehicle;
    float sim_speed;

    void print() {
        std::cout << "Spawn Vehicle: " << spawn_vehicle << std::endl;
    }
};

#endif