#include <iostream>
#include <chrono>
#include <thread>

#include <traffic_engine.hpp>
#include <simulation_clock.hpp>
#include <hardbody.hpp>
#include <traffic_state.hpp>

TrafficEngine::TrafficEngine() : hardbodies() {}

void TrafficEngine::initialize() {
	Hardbody car ({-1.0, 0.0}, {.1, 0}, {0, -.01});
	hardbodies.push_back(car);
}

TrafficState TrafficEngine::step() {

	TrafficState state;
	for (int i = 0; i < hardbodies.size(); i++)
	{
		hardbodies[i].step();
		state.objects.push_back(hardbodies[i].position);
	}
	return state;
}
