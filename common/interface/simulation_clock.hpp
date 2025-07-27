#ifndef SIMULATION_CLOCK_HPP
#define SIMULATION_CLOCK_HPP

#include <chrono>
#include <thread>

class SimulationClock {

    public:
        static SimulationClock& get() {
            static SimulationClock instance(0.05);
            return instance;
        }
        
        void wait_next();

        double get_timestep();

    private:
        std::chrono::time_point<std::chrono::steady_clock> next_tick;
        std::chrono::duration<double> timestep;

        SimulationClock(double timestep);

        SimulationClock(const SimulationClock&) = delete;
        void operator=(const SimulationClock&) = delete;
};

#endif