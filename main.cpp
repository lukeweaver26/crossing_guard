#include <iostream>
#include <traffic_engine.hpp>

int main ()
{
	std::cout << "Crossing Guard!" << std::endl;

	TrafficEngine engine;
	engine.loop();
}
