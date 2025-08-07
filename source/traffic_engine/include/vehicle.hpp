
#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <box2d/box2d.h>
#include <traffic_state.hpp>
#include <vector2.hpp>

class VehicleInstance {
  public:
	VehicleInstance(b2WorldId worldId, Vector2 position_m, Vector2 halfSize_m,
					float angle_rad);

	b2BodyId getId();
	Vector2 getPositionMeters();
	float getAngleRadians();

	Renderable getRenderable();

  private:
	b2BodyId bodyId;
};

#endif