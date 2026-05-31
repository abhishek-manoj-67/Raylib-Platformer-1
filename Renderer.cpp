#include <iostream>
#include <vector>
#include <cmath>
#include <raylib.h>

#include "Polygon.hpp"
#include "Vector2D.hpp"
#include "Renderer.hpp"

void Renderer::draw(const Polygon& poly, const Color& color, bool hollow) {

    if (!poly.vertices.empty()) {

        for (std::size_t i = 0; i < (poly.vertices.size()); i++) {

            const Vec2& end = poly.vertices[(i + 1) % poly.vertices.size()];
            const Vec2& start = poly.vertices[i];

            draw(end, color, start);

        }

    }

}

void Renderer::draw(const Vec2& end, const Color& color, const Vec2& start) {

    Vector2 end_ = {(float)end.x, (float)end.y};
    Vector2 start_ = {(float)start.x, (float)start.y};

    DrawLineV(start_, end_, color);
    
}
