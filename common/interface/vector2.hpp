#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <math.h>

class Vector2 {
public:
  double x;
  double y;

  Vector2(double x = 0.0, double y = 0.0) : x(x), y(y){};

  // Scalar Operations
  Vector2 operator+(const double scalar) const;
  Vector2 operator*(const double scalar) const;

  // Vector Operations
  Vector2 operator+(const Vector2 &other) const;
  Vector2 operator*(const Vector2 &other) const;
  double dot(const Vector2 &other);

  Vector2 &operator+=(const Vector2 &other);
  Vector2 &operator*=(double scalar);

  double magnitude() const;
};

#endif