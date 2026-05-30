#pragma once

#include <iostream>
#include <cmath>
#include <vector>

#include "Vector2D.hpp"

// github repo test

class Polygon {
public:
    // Constructor
    Polygon() {};
    Polygon(std::initializer_list<Vec2> vertices_) : vertices(vertices_), angle(0) {}

    
    // methods
    std::vector<Vec2> edges() const;
    std::vector<Vec2> axes() const;
    std::pair<double, double> project(const Vec2& axis) const;
    bool overlap(double minA, double maxA, double minB, double maxB) const;
    bool collide(const Polygon& other) const;

    void moveTo(const Vec2& point);
    void moveBy(const Vec2& direction);

    Vec2 centroid();

    // attrs
    std::vector<Vec2> vertices;
    double angle;

protected:

private:
    bool collidePolygon(const Polygon& other) const;

};