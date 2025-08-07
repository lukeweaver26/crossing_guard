#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <math.h>

class Vector2 {
  public:
	float x;
	float y;

	Vector2(float x = 0.0, float y = 0.0) : x(x), y(y){};

	// Scalar Operations
	Vector2 operator+(const float scalar) const;
	Vector2 operator*(const float scalar) const;

	// Vector Operations
	Vector2 operator+(const Vector2 &other) const;
	Vector2 operator*(const Vector2 &other) const;
	float dot(const Vector2 &other);

	Vector2 &operator+=(const Vector2 &other);
	Vector2 &operator*=(float scalar);

	float magnitude() const;
	Vector2 normal() const;
};

#endif