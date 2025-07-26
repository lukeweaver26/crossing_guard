#include <iostream>
#include <sim.hpp>

int main ()
{
	std::cout << "Crossing Guard!" << std::endl;

	TrafficSimulation::Engine engine;
	engine.loop();
}
