#include <iostream>
#include <chrono>
#include <sim.hpp>
#include <thread>

void TrafficSimulation::Engine::loop() {
	using namespace std::chrono;

	auto timestep = duration_cast<steady_clock::duration>(duration<double>(TIMESTEP_SEC));
	auto next_tick = steady_clock::now();

	while(true) {
		std::cout << "Tick at " << duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count() << " ms\n";

		next_tick += timestep;

		std::this_thread::sleep_until(next_tick);
	}
}
