#include <chrono>
#include <simulation_clock.hpp>
#include <thread>

SimulationClock::SimulationClock(double timestep) {
  using namespace std::chrono;

  this->timestep = duration<double>(timestep);
  this->next_tick = steady_clock::now();
}

void SimulationClock::wait_next() {
  using namespace std::chrono;
  next_tick += duration_cast<steady_clock::duration>(timestep);
  std::this_thread::sleep_until(next_tick);
}

double SimulationClock::get_timestep() { return timestep.count(); }
