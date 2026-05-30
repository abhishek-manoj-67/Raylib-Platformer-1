#include <iostream>
#include <cmath>
#include <vector>

#include "Polygon.hpp"
#include "Vector2D.hpp"

std::vector<Vec2> Polygon::edges() const {

    std::vector<Vec2> edges;
    for (int i = 0; i < static_cast<int>(vertices.size()); i++) {

        Vec2 edge = vertices[(i + 1) % vertices.size()] - vertices[i];
        edges.push_back(edge);

    }

    return edges;

}

std::vector<Vec2> Polygon::axes() const {

    std::vector<Vec2> axes;
    for (const Vec2& edge : edges()) {

        Vec2 axis = edge.perp().normalize();
        axes.push_back(axis);

    }

    return axes;

}

std::pair<double, double> Polygon::project(const Vec2& axis) const {

    double min = vertices[0].dot(axis);
    double max = vertices[0].dot(axis);

    for (const Vec2& vertex: vertices) {

        double dot = vertex.dot(axis);

        if (dot < min) {
            min = dot;
        } else if (dot > max) {
            max = dot;
        }

    }

    std::pair<double, double> minmax;

    minmax.first = min;
    minmax.second = max;

    return minmax;

}

bool Polygon::overlap(double minA, double maxA, double minB, double maxB) const {

    return !(maxA < minB || maxB < minA);

}

bool Polygon::collide(const Polygon& other) const {

    return collidePolygon(other);

}

bool Polygon::collidePolygon(const Polygon& other) const {

    std::vector<Vec2> axes = this->axes(); 

    for (Vec2 axis: other.axes()) {
        axes.push_back(axis);
    }

    for (Vec2 axis : axes) {

        std::pair<double, double> minmaxa = project(axis);
        std::pair<double, double> minmaxb = other.project(axis);

        if (!(overlap(minmaxa.first, minmaxa.second, minmaxb.first, minmaxb.second))) {

            return false;

        }

    }

    return true;

}

void Polygon::moveTo(const Vec2& point) {

    Vec2 centroid;

    

    for (Vec2& vertex: vertices) {

        centroid += vertex;

    }

    centroid /= static_cast<double>(vertices.size());

    Vec2 offset = point - centroid;

    for (Vec2& vertex: vertices) {

        vertex += offset;

    }

}

void Polygon::moveBy(const Vec2& direction) {

    for (Vec2& vertex : vertices) { 

        vertex += direction;

    }

}

Vec2 Polygon::centroid() {

    Vec2 centr;

    for (Vec2 vertex: vertices) {
        centr += vertex;
    }

    centr /= static_cast<double>(vertices.size());

    return centr;

}
