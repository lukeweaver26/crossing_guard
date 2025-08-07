#ifndef SIMULATION_CLOCK_HPP
#define SIMULATION_CLOCK_HPP

#include <chrono>
#include <thread>

class SimulationClock {
  public:
	static SimulationClock &get() {
		static SimulationClock instance(1.0f / 60.0f);
		return instance;
	}

	void wait_next();

	float get_timestep();

  private:
	std::chrono::time_point<std::chrono::steady_clock> next_tick;
	std::chrono::duration<float> timestep;

	SimulationClock(float timestep);

	SimulationClock(const SimulationClock &) = delete;
	void operator=(const SimulationClock &) = delete;
};

#endif