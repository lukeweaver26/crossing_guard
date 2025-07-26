#ifndef HARDBODY_HPP
#define HARDBODY_HPP

#include <math.h>

class Vector2 {
    public:
        double x;
        double y;

        Vector2( double x = 0.0, double y = 0.0): x(x), y(y) {};

        // Scalar Operations
        Vector2 operator+(const double scalar) const {
            return Vector2(x + scalar, y + scalar);
        }

        Vector2 operator*(const double scalar) const {
            return Vector2(x * scalar, y * scalar);
        }

        // Vector Operations
        Vector2 operator+(const Vector2& other) const {
            return Vector2(x + other.x, y + other.y);
        }

        Vector2 operator*(const Vector2& other) const {
            return Vector2(x * other.x, y * other.y);
        }

        double dot(const Vector2& other) {
            return x * other.x + other.y * y;
        }

        Vector2& operator+=(const Vector2& other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        Vector2& operator*=(double scalar) {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        double magnitude() const {
            return std::sqrt(x * x + y * y);
        }
};

class Hardbody {
    public:
        Vector2 position;
        Vector2 velocity;
        Vector2 acceleration;

        void step();
        void print();

        Hardbody();
        Hardbody(
            std::pair<double, double> position, 
            std::pair<double, double> velocity, 
            std::pair<double, double> acceleration
        );
};

#endif