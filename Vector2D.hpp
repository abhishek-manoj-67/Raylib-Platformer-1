#pragma once

#include <iostream>

class Vec2 {
public:
    // methods
    Vec2() : x(0), y(0) {};
    Vec2(double x_, double y_) : x(x_), y(y_) {};

    // unary
    double magnitude() const;
    double magnitudeSquared() const;
    double angle() const;

    Vec2 normalize() const;
    Vec2 perp() const;

    Vec2& zero();

    Vec2 operator-() const;

    // binary
    double dot(const Vec2& other) const;
    double cross(const Vec2& other) const;

    Vec2& operator+=(const Vec2& other);
    Vec2& operator-=(const Vec2& other);
    Vec2& operator*=(const double scalar);
    Vec2& operator/=(const double scalar);

    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;
    Vec2 operator*(const double scalar) const;
    Vec2 operator/(const double scalar) const;

    // attrs
    double x, y;

protected:


private:

};

inline Vec2 operator*(double scalar, const Vec2& vector) {

    return vector * scalar;

}

std::ostream& operator<<(std::ostream& os, const Vec2& vec);

const extern Vec2 ZERO_VECTOR;
