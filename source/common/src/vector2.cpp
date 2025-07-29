#include <math.h>

#include <vector2.hpp>

// Scalar Operations
Vector2 Vector2::operator+(const float scalar) const {
  return Vector2(x + scalar, y + scalar);
}

Vector2 Vector2::operator*(const float scalar) const {
  return Vector2(x * scalar, y * scalar);
}

// Vector Operations
Vector2 Vector2::operator+(const Vector2 &other) const {
  return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator*(const Vector2 &other) const {
  return Vector2(x * other.x, y * other.y);
}

float Vector2::dot(const Vector2 &other) { return x * other.x + other.y * y; }

Vector2 &Vector2::operator+=(const Vector2 &other) {
  x += other.x;
  y += other.y;
  return *this;
}

Vector2 &Vector2::operator*=(float scalar) {
  x *= scalar;
  y *= scalar;
  return *this;
}

float Vector2::magnitude() const { return std::sqrt(x * x + y * y); }

Vector2 Vector2::normal() const {
  float length = sqrtf(x * x + y * y);
  return Vector2(x / length, y / length);
}
