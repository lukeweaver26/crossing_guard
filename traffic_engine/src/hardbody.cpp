#include <iostream>

#include <hardbody.hpp>
#include <simulation_clock.hpp>

Hardbody::Hardbody() : position(0, 0), velocity(0, 0), acceleration(0, 0) {}

Hardbody::Hardbody(std::pair<double, double> pos, std::pair<double, double> vel,
                   std::pair<double, double> acl)
    : position(pos.first, pos.second), velocity(vel.first, vel.second),
      acceleration(acl.first, acl.second) {}

void Hardbody::step() {
  double dt = SimulationClock::get().get_timestep();
  velocity += acceleration * dt;
  position += velocity * dt;
}

void Hardbody::print() {
  std::cout << "pos: " << position.x << " " << position.y << std::endl;
  std::cout << "vel: " << velocity.x << " " << velocity.y << std::endl;
  std::cout << "acl: " << acceleration.x << " " << acceleration.y << std::endl
            << std::endl;
}
