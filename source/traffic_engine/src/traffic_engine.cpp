#include <chrono>
#include <iostream>
#include <thread>

#include <hardbody.hpp>
#include <simulation_clock.hpp>
#include <traffic_engine.hpp>
#include <traffic_state.hpp>
#include <math.h>
#include <box2d/box2d.h>

TrafficEngine::TrafficEngine() {}

void TrafficEngine::initialize() {
  b2WorldDef worldDef = b2DefaultWorldDef();
  worldDef.gravity = (b2Vec2){0.0f, 0.0f};
  worldId = b2CreateWorld(&worldDef);

  b2BodyDef initialCarDef = b2DefaultBodyDef();
  initialCarDef.type = b2_dynamicBody;
  initialCarDef.position = (b2Vec2){0.0f, 0.0f};
  b2BodyId carId = b2CreateBody(worldId, &initialCarDef);
  b2Polygon carBox = b2MakeBox(1.0f, 2.5f);
  b2ShapeDef carShapeDef = b2DefaultShapeDef();
  carShapeDef.density = 1.0f;
  b2CreatePolygonShape(carId, &carShapeDef, &carBox);

  cars.push_back(carId);
}

void TrafficEngine::step() {

  state = TrafficState();

  float timestep = SimulationClock::get().get_timestep();
  int subStepCount = 4;
  b2World_Step(worldId, timestep, subStepCount);

  for (size_t i = 0; i < cars.size(); i++) {
    Object obj;

    b2Vec2 position = b2Body_GetPosition(cars[i]);
    float angle = b2Rot_GetAngle(b2Body_GetRotation(cars[i]));
    obj.position = Vector2(position.x, position.y);
    std::cout << obj.position.x << " " << obj.position.y << std::endl;
    obj.angle = angle;
    state.objects.push_back(obj);
  }
}

TrafficState TrafficEngine::getState() {return state;}

void TrafficEngine::handleInput(const InputState& input_state) {
  if (input_state.spawn_vehicle) {
    std::cout << "Spawn Vehicle" << std::endl;;
  }
}
  