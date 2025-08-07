#include <chrono>
#include <iostream>
#include <thread>

#include <box2d/box2d.h>
#include <math.h>
#include <simulation_clock.hpp>
#include <traffic_engine.hpp>
#include <traffic_state.hpp>
#include <vehicle.hpp>

TrafficEngine::TrafficEngine() {}

void TrafficEngine::initialize() {
	b2WorldDef worldDef = b2DefaultWorldDef();
	worldDef.gravity = (b2Vec2){0.0f, 0.0f};
	worldId = b2CreateWorld(&worldDef);

	b2BodyDef groundBodyDef = b2DefaultBodyDef();
	groundBodyDef.position = {0.0f, -20.0f};
	b2BodyId groundId = b2CreateBody(worldId, &groundBodyDef);
	b2Polygon groundBox = b2MakeBox(50.0f, 10.0f);
	b2ShapeDef groundShapeDef = b2DefaultShapeDef();
	b2CreatePolygonShape(groundId, &groundShapeDef, &groundBox);

	ground.position_m = {0.0f, -20.0f};
	ground.halfSize_m = {50.0f, 10.0f};
}

void TrafficEngine::step() {

	state = TrafficState();

	float timestep = SimulationClock::get().get_timestep();
	int subStepCount = 4;
	b2World_Step(worldId, timestep, subStepCount);

	state.renderables.push_back(ground);
	for (size_t i = 0; i < cars.size(); i++) {
		state.renderables.push_back(cars[i].getRenderable());
	}
}

TrafficState TrafficEngine::getState() { return state; }

void TrafficEngine::handleInput(const InputState &input_state) {
	if (input_state.spawnVehicle) {
		VehicleInstance car(worldId, Vector2(0, 0), Vector2(1.25, .5), 0);
		cars.push_back(car);
	}
}
