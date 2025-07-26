#include <iostream>
#include <chrono>
#include <thread>

#include <traffic_engine.hpp>
#include <simulation_clock.hpp>
#include <hardbody.hpp>

void TrafficEngine::loop() {
	using namespace std::chrono;

	Hardbody car ({-1.0, 0.0}, {.1, 0}, {0, -.01});
	SimulationClock& clock = SimulationClock::get();
	while(true) {
		car.step();
		car.print();
		clock.wait_next();
	}
}
