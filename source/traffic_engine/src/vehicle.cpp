
#include <algorithm>
#include <vehicle.hpp>

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
	b2BodyDef carDef = b2DefaultBodyDef();
	carDef.type = b2_dynamicBody;
	carDef.position = (b2Vec2){position.x, position.y};
	carDef.rotation = b2MakeRot(angle_rad);
	carDef.angularDamping = 3.0f;

	bodyId = b2CreateBody(worldId, &carDef);
	b2Polygon carBox = b2MakeBox(halfSize.x, halfSize.y);
	b2ShapeDef carShapeDef = b2DefaultShapeDef();
	carShapeDef.density = 1.0f;
	carShapeDef.material.friction = 0.0f;
	b2CreatePolygonShape(bodyId, &carShapeDef, &carBox);
}

void VehicleInstance::updateVehiclePhysics(float throttleInput,
										   float steeringInput) {
	const float maxSpeedMps = 20.0f;
	const float accelerationForceMpss = 100.0f;
	const float maxSteeringAngle = 0.04f; // radians/frame
	const float drag = .8f;

	// Kill lateral velocity
	b2Vec2 rightNormal = b2Body_GetWorldVector(bodyId, (b2Vec2){1.0f, 0.0f});
	float lateralVelocity =
		b2Dot(rightNormal, b2Body_GetLinearVelocity(bodyId));
	b2Vec2 lateralImpulse =
		-lateralVelocity * rightNormal * b2Body_GetMass(bodyId);
	b2Body_ApplyLinearImpulse(bodyId, lateralImpulse,
							  b2Body_GetWorldCenterOfMass(bodyId), true);

	// Simulate forward accleration
	b2Vec2 forwardNormal = b2Body_GetWorldVector(bodyId, (b2Vec2){0.0f, 1.0f});
	float currentSpeed = b2Dot(b2Body_GetLinearVelocity(bodyId), forwardNormal);
	float desiredSpeedMps = throttleInput * maxSpeedMps;

	float speedDiff = desiredSpeedMps - currentSpeed;
	float forceMag = std::clamp(speedDiff * accelerationForceMpss,
								-accelerationForceMpss, accelerationForceMpss);
	b2Body_ApplyForceToCenter(bodyId, forwardNormal * forceMag, true);

	float angularVel = b2Body_GetAngularVelocity(bodyId);
	float desiredTurn = steeringInput * maxSteeringAngle;
	b2Body_SetAngularVelocity(
		bodyId, std::clamp(angularVel + desiredTurn, -1.5f, 1.5f));

	// Apply drag to slow car down
	b2Vec2 velocity = b2Body_GetLinearVelocity(bodyId);
	b2Body_ApplyForceToCenter(bodyId, -drag * velocity, true);
}