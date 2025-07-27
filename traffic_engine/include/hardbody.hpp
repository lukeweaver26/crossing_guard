#ifndef HARDBODY_HPP
#define HARDBODY_HPP

#include <vector2.hpp>

class Hardbody {
    public:
        Vector2 position;
        Vector2 velocity;
        Vector2 acceleration;

        void step();
        void print();

        Hardbody();
        Hardbody(
            std::pair<double, double> position, 
            std::pair<double, double> velocity, 
            std::pair<double, double> acceleration
        );
};

#endif