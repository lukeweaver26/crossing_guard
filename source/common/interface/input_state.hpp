#ifndef INPUT_STATE_HPP
#define INPUT_STATE_HPP

#include <iostream>

struct InputState {
	bool spawnVehicle;

	float steeringFactor = 0;
	float throttle = 0;

	float simSpeed;
	float worldViewportSize = 50;
};

#endif