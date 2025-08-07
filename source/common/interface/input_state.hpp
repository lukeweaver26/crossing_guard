#ifndef INPUT_STATE_HPP
#define INPUT_STATE_HPP

#include <iostream>

struct InputState {
	bool spawnVehicle;

	bool turnClockwise;
	bool turnCounterClockwise;

	float simSpeed;
	float worldViewportSize = 50;
};

#endif