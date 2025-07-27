#include <iostream>
#include <traffic_engine.hpp>
#include <graphics_engine.hpp>

int main ()
{
	std::cout << "Crossing Guard!" << std::endl;

	GraphicsEngine graphics;
	TrafficEngine engine;
	graphics.start();
	engine.loop();


}
