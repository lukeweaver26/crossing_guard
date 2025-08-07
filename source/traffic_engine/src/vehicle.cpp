
#include <vehicle.hpp>

b2BodyId VehicleInstance::getId() { return bodyId; }

Vector2 VehicleInstance::getPositionMeters() {
	b2Vec2 position = b2Body_GetPosition(bodyId);
	return Vector2(position.x, position.y);
}

float VehicleInstance::getAngleRadians() {
	return b2Rot_GetAngle(b2Body_GetRotation(bodyId));
}

Renderable VehicleInstance::getRenderable() {
	Renderable newRenderable;
	newRenderable.position_m = getPositionMeters();
	newRenderable.angle_rad = getAngleRadians();
	return newRenderable;
}

VehicleInstance::VehicleInstance(b2WorldId worldId, Vector2 position,
								 Vector2 halfSize, float angle_rad) {
	b2BodyDef initialCarDef = b2DefaultBodyDef();
	initialCarDef.type = b2_dynamicBody;
	initialCarDef.position = (b2Vec2){position.x, position.y};
	initialCarDef.rotation = b2MakeRot(angle_rad);

	bodyId = b2CreateBody(worldId, &initialCarDef);
	b2Polygon carBox = b2MakeBox(halfSize.x, halfSize.y);
	b2ShapeDef carShapeDef = b2DefaultShapeDef();
	carShapeDef.density = 10.0f;
	carShapeDef.material.friction = 0.9f;
	b2CreatePolygonShape(bodyId, &carShapeDef, &carBox);
}
