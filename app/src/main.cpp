#include <iostream>
#include <traffic_engine.hpp>
#include <graphics_engine.hpp>
#include <traffic_state.hpp>
#include <simulation_clock.hpp>

int main ()
{
	std::cout << "Crossing Guard!" << std::endl;

	GraphicsEngine graphics;
	TrafficEngine engine;
	TrafficState state;

	SimulationClock& clock = SimulationClock::get();

	engine.initialize();
	graphics.initialize();

	int ret = 0;
	while (graphics.running())
	{
		state = engine.step();
		graphics.step(state);
		clock.wait_next();
	}

	graphics.shutdown();
	
}
